//! Spanish frame generator (language slot [2]): TISPAN32 `FUN_1c404020` and
//! its helpers, transliterated onto `Mem` (every global at its original
//! address and width).
//!
//! The generator works on a window of five phoneme records (S+0x20..0x30:
//! two back, current, two ahead).  For the current phoneme it computes
//! 17 parameter tracks (formants, bandwidths, amplitudes, ...), each kept in
//! a 0x40-byte "track" structure in TISPAN's `.bss` (start/target values,
//! transition times, a per-frame buffer), and then writes one 32-byte frame
//! per 8 ms.  Pitch is set by `3440` (or `3c50` / `39c0` when singing).
//!
//! Uninitialised stack variables: the original keeps some formant and
//! bandwidth state in locals of `1c404020` that are read before being
//! written (they carry values across loop iterations *and* across calls,
//! because the driver `5840` always calls the generator at the same stack
//! depth).  They are modelled by [`Locals`], kept in a thread-local.

use crate::mem::Mem;

/// The generator's stack frame (only the slots that are read before written
/// on some path; see the module comment).
#[derive(Clone, Copy, Default)]
struct Locals {
    f1: i32,  // ebx
    f2: i32,  // edi
    f3: i32,  // [esp+0x18]
    t1c: i32, // [esp+0x1c]
    b1: i32,  // [esp+0x20]
    b2: i32,  // [esp+0x24]
    b3: i32,  // [esp+0x2c]
    l20: i32, // [esp+0x38]
    l1c: i32, // [esp+0x3c]
    l18: i32, // [esp+0x40]
    l14: i32, // [esp+0x44]
    l46: i16, // [esp+0x12]
    l47: u8,  // [esp+0x11]
}

/// Values of the uninitialised slots at the start of a phrase (left there
/// by the earlier pipeline stages).
const GARBAGE: Locals = Locals {
    f1: 0,
    f2: 0,
    f3: 0,
    t1c: 0,
    b1: 0,
    b2: 0,
    b3: 0,
    l20: 0,
    l1c: 0,
    l18: 0,
    l14: 0,
    l46: 0,
    l47: 0xa0,
};


// ---- globals --------------------------------------------------------------

/// First-call flag (set again when the generator sees the end record).
const FIRST_CALL: u32 = 0x1c40dc4c;
/// Output frame pointer.
const FRAME: u32 = 0x1c412aa8;

// Window records, as copied by the generator.
const P2_CODE: u32 = 0x1c416f51; // u8
const P2_FEAT: u32 = 0x1c412b2c;
const P2_STRESS: u32 = 0x1c412b30; // u8
const P2_CLASS: u32 = 0x1c412600; // u16

const PREV_CODE: u32 = 0x1c416f53; // u8
const PREV_FEAT: u32 = 0x1c412ab4;
const PREV_STRESS: u32 = 0x1c412ab8; // u8
const PREV_FLAGS: u32 = 0x1c416f40;
const PREV_CLASS: u32 = 0x1c412240; // u16

const CUR_CODE: u32 = 0x1c412ace; // u8
const CUR_FEAT: u32 = 0x1c412ac0;
const CUR_STRESS: u32 = 0x1c412ac4; // u8
const CUR_FLAGS: u32 = 0x1c412ac8;
const CUR_FRAMES: u32 = 0x1c4121b6; // u16
const CUR_CLASS: u32 = 0x1c4121b4; // u16

const NEXT_CODE: u32 = 0x1c412460; // u8
const NEXT_FEAT: u32 = 0x1c416f4c;
const NEXT_STRESS: u32 = 0x1c416f50; // u8
const NEXT_FLAGS: u32 = 0x1c4121a4;
const NEXT_FRAMES: u32 = 0x1c412ab0; // u16
const NEXT_CLASS: u32 = 0x1c412acc; // u16

const N2_CODE: u32 = 0x1c412604; // u8
const N2_FEAT: u32 = 0x1c412aac;

/// Table of the 17 track structures.
const TRACKS: u32 = 0x1c412ae0;

// Byte tables in `.text`.
const TBL_F: u32 = 0x1c405a84; // formant (x/16) -> byte
const TBL_A: u32 = 0x1c405b84; // amplitude (x/32) -> byte
const TBL_BW: u32 = 0x1c405c84; // bandwidth (x/8) -> nibble
const TBL_BW2: u32 = 0x1c405d84;
const TBL_DB: u32 = 0x1c40604e;

// ---- small helpers --------------------------------------------------------

#[inline]
fn r(m: &Mem, a: u32) -> i32 {
    m.i32(a)
}
#[inline]
fn w(m: &mut Mem, a: u32, v: i32) {
    m.set_i32(a, v)
}
#[inline]
fn ru(m: &Mem, a: u32) -> u32 {
    m.u32(a)
}
/// Sign-extended 16-bit read.
#[inline]
fn sx(m: &Mem, a: u32) -> i32 {
    m.i16(a) as i32
}
/// `add word ptr [a], d`
#[inline]
fn addw(m: &mut Mem, a: u32, d: i32) {
    let v = (m.i16(a) as i32).wrapping_add(d);
    m.set_i16(a, v as i16);
}
/// `add dword ptr [a], d`
#[inline]
fn addd(m: &mut Mem, a: u32, d: i32) {
    let v = m.i32(a).wrapping_add(d);
    m.set_i32(a, v);
}
/// C signed division (`idiv`).
#[inline]
fn div(a: i32, b: i32) -> i32 {
    a.wrapping_div(b)
}
/// Byte at `base + idx` (idx may be negative).
#[inline]
fn tb(m: &Mem, base: u32, idx: i32) -> u8 {
    m.u8(base.wrapping_add(idx as u32))
}
fn is_r(c: u8) -> bool {
    c == 0x36 || c == 0x6c
}

// ---- helpers --------------------------------------------------------------

/// `1c402c30`: advance a track structure to its next segment.
fn shift(m: &mut Mem, p: u32) {
    let v = r(m, p + 8);
    w(m, p + 0x10, v);
    let v = r(m, p + 0x18);
    w(m, p + 8, v);
    let v = r(m, p + 0xc);
    w(m, p + 0x14, v);
    let v = r(m, p + 0x1c);
    w(m, p + 0xc, v);
    let v = r(m, p + 0x24);
    w(m, p + 0x20, v);
}

/// `1c402c60`: broad phoneme class of a record.
fn class(m: &Mem, rec: u32) -> u16 {
    let code = m.u16(rec + 0xc);
    if code == 0xff {
        return 9;
    }
    let f = m.u32((code as u32 * 0x1a + 2).wrapping_add(m.u32(rec + 4)));
    if f & 0x10000000 != 0 {
        return 0;
    }
    if f & 0x2000 != 0 {
        return 1;
    }
    if f & 0x8000 != 0 {
        return 2;
    }
    if f & 0x40 != 0 {
        return if f & 0x8000000 == 0 { 5 } else { 3 };
    }
    if f & 0x40000 != 0 {
        return if f & 0x8000000 == 0 { 6 } else { 4 };
    }
    if f & 4 != 0 {
        return 7;
    }
    if f & 0x20000000 != 0 {
        return 9;
    }
    if f & 0x100 == 0 {
        9
    } else {
        8
    }
}

/// `1c4019c0`: formant (F1..F3) and amplitude targets and transition
/// times for the current phoneme.  `rec` is the current record.
fn formants(m: &mut Mem, rec: u32) {
    let cf = ru(m, CUR_FEAT);
    let nf = ru(m, NEXT_FEAT);
    let pf = ru(m, PREV_FEAT);
    let n2f = ru(m, N2_FEAT);
    let ccode = m.u8(CUR_CODE);
    let ncode = m.u8(NEXT_CODE);
    let n2code = m.u8(N2_CODE);
    let pcode = m.u8(PREV_CODE);
    let tbl = ru(m, rec + 4);

    if cf & 0x10002000 != 0 && cf & 0x10 == 0 {
        for a in [0x1c412238, 0x1c412358, 0x1c412288, 0x1c4123d8, 0x1c4122c8, 0x1c412418] {
            w(m, a, 0);
        }
        for a in [0x1c41223c, 0x1c41235c, 0x1c41228c, 0x1c4123dc, 0x1c4122cc, 0x1c41241c] {
            w(m, a, 100);
        }
    }
    for p in [0x1c412320, 0x1c412200, 0x1c4123a0, 0x1c412250, 0x1c4123e0, 0x1c412290] {
        shift(m, p);
    }
    let b1 = if ncode != 0x4b && ncode != 0x4c { ncode } else { n2code };
    let e = (b1 as i32 * 0x1a) as u32 + tbl;
    w(m, 0x1c412338, sx(m, e + 6));
    w(m, 0x1c412218, sx(m, e + 0xc));
    w(m, 0x1c4123b8, sx(m, e + 8));
    w(m, 0x1c412268, sx(m, e + 0xe));
    w(m, 0x1c4123f8, sx(m, e + 10));
    w(m, 0x1c4122a8, sx(m, e + 0x10));
    let v = r(m, 0x1c412218);
    w(m, 0x1c41221c, v);
    let v = r(m, 0x1c412268);
    w(m, 0x1c41226c, v);
    let v = r(m, 0x1c4122a8);
    w(m, 0x1c4122ac, v);
    let v = r(m, 0x1c412338);
    w(m, 0x1c41233c, v);
    let v = r(m, 0x1c4123b8);
    w(m, 0x1c4123bc, v);
    let v = r(m, 0x1c4123f8);
    w(m, 0x1c4123fc, v);
    if nf & 0x10 != 0 {
        w(m, 0x1c41233c, sx(m, e + 0x20));
        w(m, 0x1c41221c, sx(m, e + 0x26));
        w(m, 0x1c4123bc, sx(m, e + 0x22));
        w(m, 0x1c41226c, sx(m, e + 0x28));
        w(m, 0x1c4123fc, sx(m, e + 0x24));
        w(m, 0x1c4122ac, sx(m, e + 0x2a));
    }
    if ncode == 0x4b || ncode == 0x4c {
        w(m, 0x1c412218, sx(m, e + 0xc) + 200);
        let mut v = sx(m, e + 0xe) + 0x28;
        if v < 0xc9 {
            v = 200;
        }
        w(m, 0x1c412268, v);
        let mut v = sx(m, e + 0x10) + 0x3c;
        if v < 0x12d {
            v = 300;
        }
        w(m, 0x1c4122a8, v);
        let v = r(m, 0x1c412218);
        w(m, 0x1c41221c, v);
        let v = r(m, 0x1c412268);
        w(m, 0x1c41226c, v);
        let v = r(m, 0x1c4122a8);
        w(m, 0x1c4122ac, v);
        if cf & 0x20000000 == 0 {
            let v = r(m, 0x1c41233c).wrapping_add(r(m, 0x1c41232c)) >> 1;
            w(m, 0x1c412338, v);
            let v = r(m, 0x1c4123ac).wrapping_add(r(m, 0x1c4123bc)) >> 1;
            w(m, 0x1c4123b8, v);
            let v = r(m, 0x1c4123fc).wrapping_add(r(m, 0x1c4123ec)) >> 1;
            w(m, 0x1c4123f8, v);
        }
    }
    if nf & 0x20000000 != 0 {
        for (d, s) in [
            (0x1c412338, 0x1c41232c),
            (0x1c412218, 0x1c41220c),
            (0x1c4123b8, 0x1c4123ac),
            (0x1c412268, 0x1c41225c),
            (0x1c4123f8, 0x1c4123ec),
            (0x1c4122a8, 0x1c41229c),
        ] {
            let v = r(m, s);
            w(m, d, v);
        }
    }
    if cf & 0x20000000 != 0 {
        for (d, s) in [
            (0x1c41232c, 0x1c412338),
            (0x1c41220c, 0x1c41221c),
            (0x1c4123ac, 0x1c4123b8),
            (0x1c41225c, 0x1c41226c),
            (0x1c4123ec, 0x1c4123f8),
            (0x1c41229c, 0x1c4122ac),
        ] {
            let v = r(m, s);
            w(m, d, v);
        }
    }
    if nf & 0x10000000 == 0 {
        if nf & 0x40 != 0 && nf & 0x10000 != 0 && n2f & 0x10000000 != 0 && n2f & 0x200000 != 0 {
            addd(m, 0x1c4123b8, -0x32);
            addd(m, 0x1c4123f8, -200);
            let v = r(m, 0x1c4123b8);
            w(m, 0x1c4123bc, v);
            let v = r(m, 0x1c4123f8);
            w(m, 0x1c4123fc, v);
        }
    } else {
        if nf & 0x80 != 0 && nf & 0x1000 != 0 && n2f & 0x4000000 != 0 {
            let v = r(m, 0x1c4123b8);
            w(m, 0x1c4123bc, v);
        }
        if nf & 0x40000080 != 0 && n2f & 0x800 != 0 {
            addd(m, 0x1c4123bc, -300);
        }
        if nf & 0x40000000 != 0 && n2f & 2 != 0 {
            addd(m, 0x1c4123bc, -0x96);
        }
        if is_r(ccode) {
            let x = sx(m, tbl + 0x586);
            if cf & 0x200000 == 0 {
                let v = x.wrapping_add(r(m, 0x1c4123f8)) >> 1;
                w(m, 0x1c4123f8, v);
            } else {
                w(m, 0x1c4123f8, x);
            }
        }
        if ncode == 0x11 && m.u8(NEXT_STRESS) == 0 {
            w(m, 0x1c412338, 0x294);
            w(m, 0x1c41233c, 0x294);
            w(m, 0x1c4123b8, 0x514);
            w(m, 0x1c4123bc, 0x514);
            w(m, 0x1c4123f8, 0x960);
            w(m, 0x1c4123fc, 0x960);
        }
    }
    let set23 = |m: &mut Mem, f2: i32, f3: i32| {
        w(m, 0x1c4123bc, f2);
        w(m, 0x1c4123b8, f2);
        w(m, 0x1c4123fc, f3);
        w(m, 0x1c4123f8, f3);
    };
    if nf & 2 != 0 && cf & 0x180000 != 0 {
        set23(m, 0x73a, 0x898);
    }
    if nf & 0x4000000 != 0 && cf & 0x180000 != 0 {
        set23(m, 0x6a4, 0x76c);
    }
    if nf & 0x4000000 != 0 && cf & 0x80000000 != 0 {
        set23(m, 900, 0x9c4);
    }
    if ncode == 0x37 {
        if n2f & 0x800000 != 0 && n2f & 0x8000 == 0 {
            let x = sx(m, (n2code as u32 * 0x1a + 8).wrapping_add(tbl));
            let v = div(x.wrapping_add(r(m, 0x1c4123b8).wrapping_mul(9)), 10);
            w(m, 0x1c4123b8, v);
            w(m, 0x1c4123bc, v);
        }
        if n2f & 0x800000 == 0 || n2f & 0x8000 != 0 {
            let v = div(r(m, 0x1c4123b8).wrapping_mul(9).wrapping_add(0x91), 10);
            w(m, 0x1c4123b8, v);
            w(m, 0x1c4123bc, v);
        }
    }
    if ncode == 0x37 && n2f & 0x200000 != 0 {
        addd(m, 0x1c41233c, -100);
        addd(m, 0x1c4123bc, -100);
    }
    if is_r(ncode) {
        if cf & 0x200000 == 0 {
            let v = r(m, 0x1c4123e8);
            w(m, 0x1c4123f8, v);
        }
        if n2f & 0x200000 == 0 {
            w(m, 0x1c4123fc, sx(m, (n2code as u32 * 0x1a + 10).wrapping_add(tbl)));
        }
    }
    if ncode == 0x40 {
        let e2 = (n2code as u32 * 0x1a).wrapping_add(tbl);
        let v = sx(m, e2 + 6).wrapping_add(r(m, 0x1c41232c)) >> 1;
        w(m, 0x1c412338, v);
        let v = sx(m, e2 + 8).wrapping_add(r(m, 0x1c4123ac)) >> 1;
        w(m, 0x1c4123b8, v);
        let v = sx(m, e2 + 10).wrapping_add(r(m, 0x1c4123ec)) >> 1;
        w(m, 0x1c4123f8, v);
        let v = r(m, 0x1c412338);
        w(m, 0x1c41233c, v);
        let v = r(m, 0x1c4123b8);
        w(m, 0x1c4123bc, v);
        let v = r(m, 0x1c4123f8);
        w(m, 0x1c4123fc, v);
    }
    if ncode == 0x3e && cf & 0x40000080 != 0 {
        let v = r(m, 0x1c4123b8);
        w(m, 0x1c4123bc, v);
        let v = r(m, 0x1c4123f8);
        w(m, 0x1c4123fc, v);
        addd(m, 0x1c412338, -100);
        let v = r(m, 0x1c412338);
        w(m, 0x1c41233c, v);
    }
    if r(m, 0x1c4123f8).wrapping_sub(r(m, 0x1c4123b8)) < 0xfa {
        let v = r(m, 0x1c4123f8) - 0xfa;
        w(m, 0x1c4123b8, v);
    }
    if r(m, 0x1c4123fc).wrapping_sub(r(m, 0x1c4123bc)) < 0xfa {
        let v = r(m, 0x1c4123fc) - 0xfa;
        w(m, 0x1c4123bc, v);
    }
    if r(m, 0x1c4123b8).wrapping_sub(r(m, 0x1c412338)) < 200 {
        let v = r(m, 0x1c4123b8) - 200;
        w(m, 0x1c412338, v);
    }
    if r(m, 0x1c4123bc).wrapping_sub(r(m, 0x1c41233c)) < 200 {
        let v = r(m, 0x1c4123bc) - 200;
        w(m, 0x1c41233c, v);
    }
    aspiration(m);
    let old_aa = m.i16(0x1c4121aa);
    if nf & 0x10002000 != 0 {
        if n2f & 0x8000 != 0 {
            addd(m, 0x1c41221c, 100);
            addd(m, 0x1c41226c, 0x32);
            addd(m, 0x1c4122ac, 0x32);
            let v = r(m, 0x1c41233c).wrapping_add(500) >> 1;
            w(m, 0x1c41233c, v);
        }
        if cf & 0x8000 != 0 {
            addd(m, 0x1c412218, 100);
            addd(m, 0x1c412268, 0x32);
            addd(m, 0x1c4122a8, 0x32);
            let v = r(m, 0x1c412338).wrapping_add(500) >> 1;
            w(m, 0x1c412338, v);
        }
    }
    let v = m.u16(0x1c4121aa);
    m.set_u16(0x1c4121b2, v);
    let u6 = nf & 0x10000000;
    let aa: i16 = if u6 == 0 {
        if nf & 0x1000000 == 0 {
            if nf & 0x40 == 0 {
                3
            } else {
                2
            }
        } else {
            1
        }
    } else {
        0
    };
    m.set_i16(0x1c4121aa, aa);
    let mut t408 = tb(m, 0x1c40dee8, old_aa as i32 * 4 + aa as i32) as i32;
    if ccode == 0x37 {
        t408 = 0x14;
    }
    let u7 = cf & 0x10000000;
    if u7 != 0 && nf & 0x800 != 0 {
        t408 = 0x14;
    }
    w(m, 0x1c412408, t408);
    w(m, 0x1c412228, t408);
    w(m, 0x1c4122b8, t408);
    w(m, 0x1c412348, t408);
    w(m, 0x1c4123c8, t408);
    if u7 != 0 {
        if nf & 0x1000000 != 0 {
            w(m, 0x1c412348, 0x41);
            w(m, 0x1c412408, 0x32);
        }
        let v = r(m, 0x1c412348);
        w(m, 0x1c412228, v);
        let v = r(m, 0x1c412408);
        w(m, 0x1c4122b8, v);
        w(m, 0x1c4123c8, v);
        if is_r(ncode) {
            w(m, 0x1c412348, if cf & 0x80 == 0 { 0x1e } else { 100 });
            w(m, 0x1c4123c8, 0x50);
            w(m, 0x1c412408, 0x32);
            w(m, 0x1c4122b8, 0x14);
            w(m, 0x1c412228, 0x14);
        }
    }
    if is_r(ccode) {
        w(m, 0x1c412348, if pf & 0x80 == 0 { 0x46 } else { 0 });
        w(m, 0x1c412408, 0x32);
        w(m, 0x1c4123c8, 0x14);
        w(m, 0x1c4122b8, 0x14);
        w(m, 0x1c412228, 0x14);
    }
    let u3 = cf & 0x800000;
    if u3 == 0 || nf & 0x40 == 0 {
        if cf & 0x40 != 0 && nf & 0x800000 != 0 {
            w(m, 0x1c412228, 10);
            w(m, 0x1c412348, 10);
        }
    } else {
        w(m, 0x1c412228, 0x5a);
        w(m, 0x1c412348, 0x5a);
    }
    if nf & 0x20000000 != 0 {
        w(m, 0x1c412408, 0);
        w(m, 0x1c4123c8, 0);
        w(m, 0x1c412348, 0);
        w(m, 0x1c4122b8, 0x32);
        w(m, 0x1c412228, 0x32);
    }
    if cf & 0x20000000 != 0 {
        w(m, 0x1c412408, 100);
        w(m, 0x1c4123c8, 100);
        w(m, 0x1c412348, 100);
    }
    if u7 == 0 || nf & 0x4000000 == 0 {
        if cf & 0x4000000 != 0 && u6 != 0 {
            w(m, 0x1c4123c8, 0x1e);
        }
    } else {
        w(m, 0x1c4123c8, 0x50);
    }
    let all5 = |m: &mut Mem, v: i32| {
        for a in [0x1c412228, 0x1c412348, 0x1c4123c8, 0x1c4122b8, 0x1c412408] {
            w(m, a, v);
        }
    };
    if u3 != 0 && ncode == 0x1e {
        all5(m, 0x5a);
    }
    if cf & 0x80000 == 0 || nf & 0x8000 == 0 {
        if cf & 0x8000 != 0 && nf & 0x80000 != 0 {
            w(m, 0x1c4122b8, 0x5a);
            w(m, 0x1c4123c8, 0x5a);
            w(m, 0x1c412408, 0x5a);
        }
    } else {
        w(m, 0x1c4122b8, 10);
        w(m, 0x1c4123c8, 10);
        w(m, 0x1c412408, 10);
    }
    if cf & 0xc0100000 != 0 && nf & 0x2000 != 0 {
        all5(m, 0x14);
    }
    let interp = |m: &mut Mem, dst: u32, from: u32, to: u32, pct: u32| {
        let a = r(m, from);
        let v = a.wrapping_add(div(r(m, to).wrapping_sub(a).wrapping_mul(r(m, pct)), 100));
        w(m, dst, v);
    };
    interp(m, 0x1c412344, 0x1c41232c, 0x1c412338, 0x1c412348);
    interp(m, 0x1c4123c4, 0x1c4123ac, 0x1c4123b8, 0x1c4123c8);
    interp(m, 0x1c412404, 0x1c4123ec, 0x1c4123f8, 0x1c412408);
    interp(m, 0x1c412224, 0x1c41220c, 0x1c412218, 0x1c412228);
    interp(m, 0x1c412274, 0x1c41225c, 0x1c412268, 0x1c4122b8);
    interp(m, 0x1c4122b4, 0x1c41229c, 0x1c4122a8, 0x1c4122b8);
    if pf & 2 != 0 && u3 != 0 {
        w(m, 0x1c4123c0, 0x640);
        w(m, 0x1c412400, if cf & 0x80000 == 0 { 0xa28 } else { 0x8fc });
    }
    if cf & 2 != 0 && nf & 0x800000 != 0 {
        w(m, 0x1c412404, 0x8fc);
        if nf & 0x80000 == 0 {
            w(m, 0x1c412404, 0xa3c);
        }
    }
    if cf & 0x10002000 != 0 && nf & 0x4000000 != 0 {
        addd(m, 0x1c412224, 100);
        let s = r(m, 0x1c4123ec).wrapping_add(r(m, 0x1c4123b8)).wrapping_add(r(m, 0x1c4123ac));
        w(m, 0x1c4123c4, div(s, 3) - 400);
    }
    if nf & 0x4000000 != 0 && cf & 0x40000080 != 0 {
        addd(m, 0x1c4123c4, 100);
    }
    let u5 = cf & 0x4000000;
    if u5 != 0 && nf & 0x40000080 != 0 {
        addd(m, 0x1c4123c4, 100);
    }
    if u5 != 0 {
        let v = r(m, 0x1c4123c4) + if nf & 0x400 == 0 { 400 } else { 800 };
        w(m, 0x1c412404, v);
    }
    if nf & 0x4000000 != 0 {
        let v = r(m, 0x1c4123c4) + if cf & 0x400 == 0 { 600 } else { 800 };
        w(m, 0x1c412404, v);
    }
    if cf & 0x800 == 0 || u6 == 0 {
        if u7 != 0 && pf & 0x800 != 0 {
            addd(m, 0x1c412340, 100);
            addd(m, 0x1c4123c0, 100);
        }
    } else {
        addd(m, 0x1c412344, -0x3c);
        addd(m, 0x1c4123c4, -0x32);
    }
    if cf & 0x20000100 != 0 && ccode != 0x40 {
        let v = r(m, 0x1c412328);
        w(m, 0x1c412340, v);
        let v = r(m, 0x1c4123a8);
        w(m, 0x1c4123c0, v);
        let v = r(m, 0x1c4123e8);
        w(m, 0x1c412400, v);
    }
    if u5 != 0 && nf & 0x10002000 != 0 {
        let pair = match ncode {
            9 => Some((0x8de, 0xc1c)),
            0xd => Some((0x834, 0xa14)),
            0x11 => Some((0x76c, 0x97e)),
            0x1f => Some((0x866, 0xa41)),
            0x21 => Some((0x7e4, 0x92e)),
            0x23 => Some((0x4b0, 0x960)),
            0x27 | 0x5c => Some((1000, 0x9f6)),
            0x29 | 0x38 => Some((0x5dc, 0x76c)),
            0x36 | 0x6c => Some((0x78a, 0x9a6)),
            0x37 => Some((0x410, 0x8ca)),
            _ => None,
        };
        if let Some((a, b)) = pair {
            w(m, 0x1c4123c4, a);
            w(m, 0x1c412404, b);
        }
    }
    // Transition times: group A (+0x2c of each formant track), group B (+0x30).
    const GA: [u32; 6] = [0x1c41222c, 0x1c41234c, 0x1c41227c, 0x1c4123cc, 0x1c4122bc, 0x1c41240c];
    const GB: [u32; 6] = [0x1c412230, 0x1c412350, 0x1c412280, 0x1c4123d0, 0x1c4122c0, 0x1c412410];
    let set = |m: &mut Mem, g: &[u32], v: i32| {
        for &a in g {
            w(m, a, v);
        }
    };
    set(m, &GA, 10);
    set(m, &GB, 0xc);
    if cf & 0x1000000 != 0 {
        set(m, &GB, 5);
    }
    if u3 != 0 && nf & 0x1000000 != 0 {
        w(m, 0x1c412230, 6);
        w(m, 0x1c412350, 6);
        w(m, 0x1c412280, 8);
        w(m, 0x1c4123d0, 8);
        w(m, 0x1c4122c0, 8);
        w(m, 0x1c412410, 8);
    }
    if ccode == 0x39 {
        let v = if nf & 0x1000000 == 0 { 5 } else { 3 };
        w(m, 0x1c412280, v);
        w(m, 0x1c4122c0, v);
        w(m, 0x1c4123d0, v);
        w(m, 0x1c412410, v);
    }
    if is_r(ccode) {
        w(m, 0x1c412350, 4);
        w(m, 0x1c41234c, 4);
        w(m, 0x1c4123d0, 4);
        w(m, 0x1c4123cc, 4);
        w(m, 0x1c412410, 5);
        w(m, 0x1c41240c, 5);
        w(m, 0x1c412230, 2);
        w(m, 0x1c41222c, 2);
        w(m, 0x1c412280, 2);
        w(m, 0x1c41227c, 2);
        w(m, 0x1c4122c0, 2);
        w(m, 0x1c4122bc, 2);
    }
    if pf & 0x2000 != 0 && pcode != 0x36 && u7 != 0 {
        set(m, &GA, 7);
    }
    // LAB_1c402964
    if u7 != 0
        && m.u8(CUR_STRESS) != 0
        && m.u8(P2_STRESS) != 0
        && pf & 0x2000 != 0
        && ru(m, P2_FEAT) & 0x40000 != 0
    {
        set(m, &GA, 5);
    }
    let mut skip = false;
    if m.i16(PREV_CLASS) == 3 {
        if u3 != 0 {
            w(m, 0x1c41222c, 5);
            w(m, 0x1c41234c, 5);
            w(m, 0x1c41227c, 7);
            w(m, 0x1c4123cc, 7);
            w(m, 0x1c4122bc, 7);
            w(m, 0x1c41240c, 7);
            skip = true;
        }
    } else if u3 != 0 && m.i16(NEXT_CLASS) == 3 {
        w(m, 0x1c412230, 5);
        w(m, 0x1c412350, 5);
        w(m, 0x1c412280, 7);
        w(m, 0x1c4123d0, 7);
        w(m, 0x1c4122c0, 7);
        w(m, 0x1c412410, 7);
        skip = true;
    }
    if !skip && m.i16(CUR_CLASS) == 3 {
        w(m, 0x1c412280, 3);
        w(m, 0x1c412230, 2);
        w(m, 0x1c41222c, 2);
        w(m, 0x1c412350, 2);
        w(m, 0x1c41234c, 2);
        w(m, 0x1c41227c, 3);
        w(m, 0x1c4123d0, 3);
        w(m, 0x1c4123cc, 3);
        w(m, 0x1c4122c0, 3);
        w(m, 0x1c4122bc, 3);
        w(m, 0x1c412410, 3);
        w(m, 0x1c41240c, 3);
    }
    // LAB_1c402a6b
    if ccode == 0x37 {
        set(m, &GB, 3);
    }
    if u7 != 0 && nf & 0x800 != 0 {
        set(m, &GB, 5);
    }
    if cf & 0x10002000 != 0 {
        if pf & 0x1000040 != 0 {
            w(m, 0x1c4122bc, 5);
            w(m, 0x1c41227c, 5);
            w(m, 0x1c41222c, 5);
        }
        if nf & 0x1000040 != 0 {
            w(m, 0x1c4122c0, 5);
            w(m, 0x1c412280, 5);
            w(m, 0x1c412230, 5);
        }
    }
    w(m, 0x1c412b28, is_r(ccode) as i32);
    if is_r(ncode) {
        w(m, 0x1c412274, 0xfa);
        w(m, 0x1c412280, 2);
    }
    if is_r(pcode) {
        w(m, 0x1c412270, 0xfa);
        w(m, 0x1c41227c, 2);
    }
    let v = r(m, 0x1c4122b8);
    w(m, 0x1c412278, v);
}

/// `1c403100`: aspiration-amplitude targets from a per-phoneme table.
fn aspiration(m: &mut Mem) {
    let cf = ru(m, CUR_FEAT);
    if cf & 0x10 == 0 {
        return;
    }
    let ccode = m.u8(CUR_CODE);
    let mut i: i32 = 0;
    loop {
        if m.u8((0x1c40df18 + i * 3) as u32) == ccode {
            break;
        }
        i += 1;
        if i >= 0x15 {
            break;
        }
    }
    let b1 = m.u8((0x1c40df19 + i * 3) as u32);
    let b2 = m.u8((0x1c40df1a + i * 3) as u32);
    let mut u4 = b1 as u16;
    let mut u6 = b2 as u16;
    if cf & 0xc0000000 != 0 && ru(m, NEXT_FEAT) & 0x2000 != 0 {
        u4 = (b1 as u16).wrapping_sub(10);
        u6 = (b2 as u16).wrapping_sub(0xf);
    }
    if (u4 as i16) > 0x5e {
        u4 = 0x5f;
    }
    if (u4 as i16) < 1 {
        u4 = 0;
    }
    let a = u4 as i16 as i32;
    w(m, 0x1c412288, a);
    if (u6 as i16) > 99 {
        u6 = 100;
    }
    let mut b = u6 as i16 as i32;
    if b <= a + 5 {
        b = a + 5;
    }
    let b = b as i16 as i32;
    w(m, 0x1c41228c, b);
    for x in [0x1c412238, 0x1c4122c8, 0x1c412358, 0x1c4123d8, 0x1c412418] {
        w(m, x, a);
    }
    for x in [0x1c41223c, 0x1c4122cc, 0x1c41235c, 0x1c4123dc, 0x1c41241c] {
        w(m, x, b);
    }
    if ccode == 0x23 {
        w(m, 0x1c412238, 0x32);
        w(m, 0x1c412358, 0x32);
        w(m, 0x1c41223c, 0x5f);
        w(m, 0x1c41235c, 0x5f);
    }
}

/// `1c402d00`: voicing/frication amplitude and glottal targets.
fn amplitudes(m: &mut Mem, s: u32) {
    let cf = ru(m, CUR_FEAT);
    let nf = ru(m, NEXT_FEAT);
    let n2f = ru(m, N2_FEAT);
    let ccode = m.u8(CUR_CODE);
    let ncode = m.u8(NEXT_CODE);
    let pcode = m.u8(PREV_CODE);
    let nstress = m.u8(NEXT_STRESS);
    shift(m, 0x1c412500);
    shift(m, 0x1c412420);
    let i1 = ((m.u16(NEXT_CLASS) as i32) + m.u16(CUR_CLASS) as i32 * 10) * 10;
    w(m, 0x1c412528, tb(m, 0x1c40df58, i1) as i32);
    w(m, 0x1c412538, 0);
    let i2 = ((m.u16(CUR_CLASS) as i32) + m.u16(PREV_CLASS) as i32 * 10) * 10;
    w(m, 0x1c41253c, 0x4b);
    w(m, 0x1c41252c, tb(m, 0x1c40df5b, i2) as i32);
    w(m, 0x1c412530, tb(m, 0x1c40df5e, i1) as i32);
    w(m, 0x1c412448, tb(m, 0x1c40df59, i1) as i32);
    w(m, 0x1c41244c, tb(m, 0x1c40df5c, i2) as i32);
    w(m, 0x1c412450, tb(m, 0x1c40df5f, i1) as i32);
    if is_r(ccode) {
        w(m, 0x1c412530, 1);
        w(m, 0x1c41252c, 1);
    }
    if cf & 0x800000 != 0 {
        if is_r(ncode) {
            w(m, 0x1c412528, 0);
        }
        if is_r(pcode) {
            let v = r(m, 0x1c412508);
            w(m, 0x1c412520, v);
        }
    }
    let ntbl = ru(m, ru(m, s + 0x2c) + 4);
    let mut v518 = m.u8(ntbl.wrapping_add(0x16 + ncode as u32 * 0x1a)) as i32;
    if nf & 0x20000000 != 0 && cf & 0x8000000 == 0 {
        v518 = 0;
    }
    if cf & 0x10000000 != 0 && nf & 0x8000000 != 0 && nf & 0x40 != 0 && n2f & 0x10000000 != 0 {
        v518 += 6;
    }
    let mut v51c = v518;
    if nf & 0x8000000 != 0 && n2f & 0x8000000 == 0 {
        v51c = v518 - 3;
    }
    let v518 = tb(m, TBL_DB, v518) as i32;
    let v51c = tb(m, TBL_DB, v51c) as i32;
    w(m, 0x1c412518, v518);
    w(m, 0x1c41251c, v51c);
    let mut i438 = 0;
    if nf & 0x44 != 0 {
        match ncode {
            0x41 | 0x42 => i438 = 0x20,
            0x43 => i438 = 0x24,
            0x44 => i438 = 0x21,
            0x4b => i438 = 0x28,
            _ => {}
        }
    }
    let v438 = tb(m, 0x1c406058, i438) as i32;
    w(m, 0x1c412438, v438);
    let a = r(m, 0x1c41250c);
    let mut v524 = a.wrapping_add(div(v518.wrapping_sub(a).wrapping_mul(r(m, 0x1c412528)), 100));
    let a = r(m, 0x1c41242c);
    let v444 = a.wrapping_add(div(v438.wrapping_sub(a).wrapping_mul(r(m, 0x1c412448)), 100));
    w(m, 0x1c412444, v444);
    if v524 < 1 {
        v524 = 0;
    }
    w(m, 0x1c412524, v524);
    w(m, 0x1c41243c, v438);
    shift(m, 0x1c4124c0);
    shift(m, 0x1c412660);
    let mut v678: i32 = if nf & 0x8000000 == 0 { 8 } else { 0xc };
    if nstress != 0 {
        v678 += 2;
    }
    if ru(m, NEXT_FLAGS) & 4 != 0 && nstress == 0 {
        v678 -= 2;
    }
    if nf & 0x1000000 != 0 {
        v678 -= 5;
    }
    if ncode == 1 {
        addd(m, 0x1c41220c, 0x32);
    }
    let v678 = v678 * 0x100;
    w(m, 0x1c412678, v678);
    w(m, 0x1c412690, 3);
    w(m, 0x1c41268c, 3);
    w(m, 0x1c41267c, v678);
    let a = r(m, 0x1c4124cc);
    let v = a.wrapping_add(div(r(m, 0x1c4124d8).wrapping_sub(a).wrapping_mul(r(m, 0x1c4124e8)), 100));
    w(m, 0x1c4124e4, v);
    w(m, 0x1c412688, 0x32);
    let a = r(m, 0x1c41266c);
    let v = a.wrapping_add(div(v678.wrapping_sub(a).wrapping_mul(0x32), 100));
    w(m, 0x1c412684, v);
}

/// `1c40a9e0`: frication/burst and nasal-zero targets; also the number of
/// frames (and level) of the closure at the end of stops.
fn bursts(m: &mut Mem, rec: u32) {
    let cf = ru(m, CUR_FEAT);
    let nf = ru(m, NEXT_FEAT);
    let pf = ru(m, PREV_FEAT);
    let n2f = ru(m, N2_FEAT);
    let ccode = m.u8(CUR_CODE);
    let ncode = m.u8(NEXT_CODE);
    let n2code = m.u8(N2_CODE);
    let pcode = m.u8(PREV_CODE);
    let nstress = m.u8(NEXT_STRESS);
    for p in [0x1c412540, 0x1c412580, 0x1c412360, 0x1c412470] {
        shift(m, p);
    }
    w(m, 0x1c41237c, 0);
    w(m, 0x1c412378, 0);
    let u3 = nf & 0x40;
    if u3 != 0 {
        let mut v: i32 = match ncode {
            b'A' => 0x2f,
            b'B' => 0x3d,
            b'C' => 0x37,
            b'D' => 0x31,
            b'E' => 0x2e,
            b'F' => 0x3c,
            b'G' => 0x38,
            b'H' => 0x35,
            _ => 0,
        };
        if cf & 0x10000 != 0 && nf & 0x80 == 0 {
            v += 3;
        }
        let i4 = v;
        if nstress == 0 {
            v -= 2;
            if nf & 2 != 0 {
                v = i4 - 4;
            }
        }
        w(m, 0x1c412378, v);
        w(m, 0x1c41237c, v);
    }
    let mut b2 = false;
    w(m, 0x1c412398, 0);
    w(m, 0x1c41239c, 0x4b);
    w(m, 0x1c412488, -10);
    w(m, 0x1c412558, 3000);
    w(m, 0x1c412598, 400);
    let v = tb(m, TBL_DB, r(m, 0x1c412378)) as i32;
    let v2 = tb(m, TBL_DB, r(m, 0x1c41237c)) as i32;
    w(m, 0x1c412378, v);
    w(m, 0x1c41237c, v2);
    if nf & 0x40040 != 0 {
        if n2code == 0x29 || n2code == 0x38 {
            b2 = true;
        }
        let tbl = ru(m, rec + 4);
        // (bp, ax, di) = (F, BW, A)
        let (bp, ax, di): (i16, i16, i16);
        if nf & 2 == 0 {
            if nf & 0x10000 == 0 {
                if nf & 0x4000000 == 0 {
                    if nf & 8 == 0 {
                        if nf & 0x400 != 0 {
                            bp = 0xe10;
                            ax = 1000;
                            di = -3;
                        } else {
                            // Unreachable with TISPAN's tables (the original
                            // reads an uninitialised local here).
                            bp = 0x19;
                            ax = 0x19;
                            di = 0x19;
                        }
                    } else {
                        bp = 0xe10;
                        ax = 1000;
                        di = -6;
                    }
                } else if n2f & 0x800000 == 0 {
                    bp = 0x834;
                    ax = 0xdc;
                    di = -0x12;
                } else {
                    let e = (n2code as u32 * 0x1a).wrapping_add(tbl);
                    bp = (sx(m, e + 8).wrapping_add(sx(m, e + 10)) >> 1) as i16;
                    ax = 0xfa;
                    di = -0x12;
                }
            } else if b2 {
                bp = 0x8fc;
                ax = 300;
                di = -0x12;
            } else {
                bp = 0x9c4;
                ax = 300;
                di = -0x12;
            }
        } else if nf & 0x40000 == 0 || !is_r(n2code) {
            bp = 4000;
            ax = 500;
            di = -0x12;
        } else {
            bp = 0xdac;
            ax = 0x1c2;
            di = -0x12;
        }
        w(m, 0x1c41255c, bp as i32);
        w(m, 0x1c412558, bp as i32);
        w(m, 0x1c41259c, ax as i32);
        w(m, 0x1c412598, ax as i32);
        w(m, 0x1c41248c, di as i32);
        w(m, 0x1c412488, di as i32);
        if nf & 2 != 0 {
            if b2 {
                addd(m, 0x1c41255c, -300);
            }
            if cf & 0x200000 != 0 {
                addd(m, 0x1c412558, -300);
            }
        }
        if nf & 0x10000 != 0 {
            if cf & 0x10002000 != 0 {
                let v = (r(m, 0x1c4123ec).wrapping_add(r(m, 0x1c4123ac)) >> 1) + 100;
                w(m, 0x1c412558, v);
                w(m, 0x1c412598, div(v, 6));
            }
            if n2f & 0x10002000 != 0 {
                let e = (n2code as u32 * 0x1a).wrapping_add(tbl);
                let v = (sx(m, e + 8) + sx(m, e + 10) >> 1) + 100;
                w(m, 0x1c41255c, v);
                w(m, 0x1c41259c, div(v, 6));
            }
        }
    }
    if u3 == 0 && cf & 0x40 != 0 {
        let v = r(m, 0x1c41254c);
        w(m, 0x1c412558, v);
        let v = r(m, 0x1c41258c);
        w(m, 0x1c412598, v);
        let v = r(m, 0x1c41247c);
        w(m, 0x1c412488, v);
    }
    if cf & 0x40 == 0 && cf & 0x40000 == 0 {
        if pf & 0x40 != 0 {
            let v = r(m, 0x1c412554);
            w(m, 0x1c412548, v);
            let v = r(m, 0x1c412594);
            w(m, 0x1c412588, v);
            let v = r(m, 0x1c412484);
            w(m, 0x1c412478, v);
        }
        if u3 != 0 {
            let v = r(m, 0x1c412558);
            w(m, 0x1c41254c, v);
            let v = r(m, 0x1c412598);
            w(m, 0x1c41258c, v);
            let v = r(m, 0x1c412488);
            w(m, 0x1c41247c, v);
        }
    }
    let u7 = cf & 0x4000000;
    if u7 != 0 && nf & 0x10002000 != 0 {
        let v = r(m, 0x1c4123c4) + 0x82;
        w(m, 0x1c41254c, v);
    }
    let i4 = ((m.u16(NEXT_CLASS) as i32) + m.u16(CUR_CLASS) as i32 * 10) * 10;
    let v388 = tb(m, 0x1c40df5a, i4) as i32;
    w(m, 0x1c412388, v388);
    w(m, 0x1c412568, 0x32);
    w(m, 0x1c4125a8, 0x32);
    w(m, 0x1c412498, 0x32);
    let i5 = ((m.u16(CUR_CLASS) as i32) + m.u16(PREV_CLASS) as i32 * 10) * 10;
    let v = tb(m, 0x1c40df5d, i5) as i32;
    w(m, 0x1c41238c, v);
    let v = tb(m, 0x1c40df60, i4) as i32;
    w(m, 0x1c412390, v);
    let v = if pf & 0x40 == 0 { 5 } else { 2 };
    w(m, 0x1c41249c, v);
    w(m, 0x1c4125ac, v);
    w(m, 0x1c41256c, v);
    let v = if u3 == 0 { 5 } else { 2 };
    w(m, 0x1c4124a0, v);
    w(m, 0x1c4125b0, v);
    w(m, 0x1c412570, v);
    let u3b = cf & 0x40000;
    if u3b != 0 {
        for a in [0x1c412498, 0x1c4125a8, 0x1c412568, 0x1c4124a0, 0x1c4125b0, 0x1c412570] {
            w(m, a, 0);
        }
    }
    if cf & 0x40 != 0 && pf & 0x40000 != 0 {
        w(m, 0x1c41249c, 0);
        w(m, 0x1c4125ac, 0);
        w(m, 0x1c41256c, 0);
    }
    let interp = |m: &mut Mem, dst: u32, from: u32, to: u32, pct: u32| {
        let a = r(m, from);
        let v = a.wrapping_add(div(r(m, to).wrapping_sub(a).wrapping_mul(r(m, pct)), 100));
        w(m, dst, v);
    };
    interp(m, 0x1c412384, 0x1c41236c, 0x1c412378, 0x1c412388);
    interp(m, 0x1c412564, 0x1c41254c, 0x1c412558, 0x1c412568);
    interp(m, 0x1c4125a4, 0x1c41258c, 0x1c412598, 0x1c4125a8);
    m.set_u16(0x1c4121dc, 0);
    interp(m, 0x1c412494, 0x1c41247c, 0x1c412488, 0x1c412498);
    m.set_u16(0x1c4121ac, 0);
    let u5 = cf & 1;
    if !(u5 != 0 || (u3b != 0 && (nf & 0x20000000 == 0 || nf & 0x8000 != 0))) {
        return;
    }
    let mut i: i32 = 0;
    loop {
        if m.u8((0x1c40def8 + i * 2) as u32) == ccode {
            break;
        }
        i += 1;
        if i >= 0xf {
            break;
        }
    }
    let mut dc = m.u8((0x1c40def9 + i * 2) as u32) as i16;
    if pcode != b'A' && ccode == b'R' && (ncode == b'l' || ncode == b'6') {
        dc = dc.wrapping_add(3);
    }
    if u5 != 0 && m.u8(CUR_STRESS) != 0 && ncode != b'l' {
        dc = dc.wrapping_add(2);
    }
    let pflags = ru(m, PREV_FLAGS);
    if pcode == b'A' && pflags & 0x80 != 0 {
        dc = 2;
    }
    let frames = m.i16(CUR_FRAMES);
    if dc >= frames {
        dc = frames;
    }
    m.set_i16(0x1c4121dc, dc);
    let mut ac: i16 = 0;
    if u3b != 0 {
        ac = match ccode {
            b'I' => 0x3b,
            b'J' => 0x3e,
            b'Q' => 0x32,
            b'R' => {
                if pcode != b'A' && ncode == b'l' {
                    0x2b
                } else {
                    0x25
                }
            }
            b'T' => 0x3a,
            _ => 0,
        };
    }
    let u3c = cf & 0x10000;
    if u3c != 0 && nf & 0x80 == 0 {
        ac = ac.wrapping_add(4);
    }
    let cstress = m.u8(CUR_STRESS);
    if pf & 0x8000 != 0 && cstress == 0 {
        ac = ac.wrapping_sub(6);
    } else if pf & 0x8000 == 0 && cstress == 0 {
        ac = ac.wrapping_sub(3);
    }
    if nf & 0x40040 != 0 {
        ac = ac.wrapping_sub(3);
    }
    if pcode == b'A' && pflags & 0x80 != 0 {
        ac = ac.wrapping_sub(3);
    }
    m.set_i16(0x1c4121ac, ac);
    if u5 != 0 {
        return;
    }
    if ncode == b'@' {
        m.set_i16(0x1c4121ac, 0);
    }
    if nf & 1 != 0 {
        return;
    }
    if nf & 0x40000 == 0 {
        if ncode == b'@' && n2f & 0x40000 != 0 {
            if (cf & 0x400 != 0 && n2f & 0x400 != 0)
                || (cf & 2 != 0 && n2f & 2 != 0)
                || (u7 != 0 && n2f & 0x4000000 != 0)
                || (u3c != 0 && n2f & 0x10000 != 0)
            {
                m.set_i16(0x1c4121ac, 0);
            }
        }
    } else if (cf & 0x400 != 0 && nf & 0x400 != 0)
        || (cf & 2 != 0 && nf & 2 != 0)
        || (u7 != 0 && nf & 0x4000000 != 0)
        || (u3c != 0 && nf & 0x10000 != 0)
    {
        m.set_i16(0x1c4121ac, 0);
    }
}

/// `1c403200`: fill a track's per-frame buffer: an S-shaped transition from
/// the start value (+0x20) towards the target (+8), then towards the end
/// value (+0x24 -> +0xc) over the second half.
fn track(m: &mut Mem, p: u32) {
    let n = m.u16(CUR_FRAMES) as i32;
    let start = div(r(m, p + 0x38).wrapping_mul(n), 100) + 1;
    let mut len = div(r(m, p + 0x3c).wrapping_mul(n).wrapping_add(0x32), 100) - start;
    if len < 2 {
        len = 1;
    }
    let step = div(0x8000, len);
    let mut acc = 0x8000 - step;
    let mut k = start;
    if start > 0 {
        for i in 0..start as u32 {
            m.set_u16(0x1c4126a0 + 2 * i, 0x100);
        }
    }
    while k < n {
        if acc < 0 {
            acc = 0;
        }
        m.set_i16(0x1c4126a0 + 2 * k as u32, (acc >> 7) as i16);
        acc -= step;
        k += 1;
    }
    m.set_u16((0x1c41269e + 2 * n) as u32, 0);
    let mut sm = r(m, p + 0x34);
    if sm >= 8 {
        sm = 8;
    }
    if sm < 1 {
        sm = 0;
    }
    let mut v = r(m, p + 0x20);
    let tgt = r(m, p + 8);
    let rate = r(m, (0x1c40dca8 + (r(m, p + 0x2c) + sm * 0x10) * 4) as u32);
    for i in 0..n as u32 {
        v = v.wrapping_add(tgt.wrapping_sub(v).wrapping_mul(rate) >> 8);
        let k = sx(m, 0x1c4126a0 + 2 * i);
        m.set_i16(0x1c411da0 + 2 * i, (k.wrapping_mul(v) >> 8) as i16);
    }
    let buf = ru(m, p + 4);
    let tgt = r(m, p + 0xc);
    let mut v = r(m, p + 0x24);
    let rate = r(m, (0x1c40dca8 + (r(m, p + 0x30) + sm * 0x10) * 4) as u32);
    for j in 0..n as u32 {
        let i = n as u32 - 1 - j;
        let k = sx(m, 0x1c4126a0 + 2 * i);
        let x = ((0x100 - k).wrapping_mul(v) >> 8) as i16;
        let y = m.i16(0x1c411da0 + 2 * i);
        m.set_i16(buf + 2 * i, x.wrapping_add(y));
        v = v.wrapping_add(tgt.wrapping_sub(v).wrapping_mul(rate) >> 8);
    }
}

/// `1c4033c0`: closure frames at the end of stops (amplitude track 0x360).
fn closure(m: &mut Mem) {
    let dc = m.i16(0x1c4121dc);
    let ac = m.i16(0x1c4121ac);
    if dc > 0 && ac > 0 {
        let n = m.u16(CUR_FRAMES) as u32;
        let mut p = ru(m, 0x1c412364) + 2 * n;
        let mut i: i16 = 0;
        while i < dc {
            p -= 2;
            i += 1;
            m.set_i16(p, ac);
        }
        if m.u8(CUR_FEAT) & 1 != 0 {
            addw(m, p, -8);
            addw(m, p + 2, -4);
            let q = ru(m, 0x1c412364) + 2 * n - 2;
            addw(m, q, -8);
            addw(m, q - 2, -4);
        }
    }
}

/// `1c403e90`/`3ee0`/`3f40`/`3fa0`: F0 target (in % of the base pitch)
/// to Hz, written to a frame's pitch word.
fn pitch_at(m: &mut Mem, s: u32, at: u32, mut pct: i32) {
    if pct > 0x6e {
        pct = div((m.u16(s + 0x60) as i32).wrapping_mul(pct - 0x6e), 100) + 0x6e;
    }
    let v = div((m.u16(s + 0x46) as i32).wrapping_mul(pct), 0x6e);
    m.set_i16(at, v as i16);
}
fn pitch_first(m: &mut Mem, s: u32, fr: u32, pct: i32) {
    pitch_at(m, s, fr + 0x18, pct)
}
fn pitch_mid(m: &mut Mem, s: u32, fr: u32, pct: i32) {
    let n = m.u16(CUR_FRAMES) as u32;
    pitch_at(m, s, (n & !1) * 0x10 + 0x18 + fr, pct)
}
fn pitch_last(m: &mut Mem, s: u32, fr: u32, pct: i32) {
    let n = m.u16(CUR_FRAMES) as u32;
    pitch_at(m, s, (n * 0x20).wrapping_sub(8).wrapping_add(fr), pct)
}
fn pitch_next_mid(m: &mut Mem, s: u32, fr: u32, pct: i32) {
    let n = m.u16(CUR_FRAMES) as u32;
    let nn = m.u16(NEXT_FRAMES) as u32;
    pitch_at(m, s, (nn & !1) * 0x10 + n * 0x20 + 0x18 + fr, pct)
}

/// `1c403440`: speech pitch contour for the phoneme (`fr` = its first frame).
fn pitch(m: &mut Mem, s: u32, fr: u32, rec: u32) {
    let mut c = ru(m, rec);
    if c != 0 {
        while m.i16(c) != 0x1e {
            match m.i16(c) {
                0x8c => {
                    let v = m.u16(c + 2);
                    m.set_u16(s + 0xae, v);
                }
                0xb4 => {
                    let mut v = m.i16(c + 2);
                    if v > 0 {
                        if v >= 2000 {
                            v = 2000;
                        }
                        if v < 0xb {
                            v = 10;
                        }
                        m.set_i16(s + 0x46, v);
                    }
                }
                0xf0 => {
                    let v = m.u16(c + 2);
                    m.set_u16(s + 0x4c, v);
                }
                0xfa => {
                    let v = m.u16(c + 2);
                    m.set_u16(s + 0x60, v);
                }
                _ => {}
            }
            c += 6;
        }
    }
    let cfl = ru(m, CUR_FLAGS);
    let cf = ru(m, CUR_FEAT);
    let nf = ru(m, NEXT_FEAT);
    let pf = ru(m, PREV_FEAT);
    let u4 = (cfl & 4) >> 2;
    let b1 = !(nf & 0x20000000 == 0 && nf & 0x8000000 != 0 && (nf & 0x1000000 == 0 || nf & 0x8000 != 0));
    if cfl & 0x80 != 0 {
        if pf & 0x100 == 0 || cf & 0x8000000 == 0 {
            let p = ru(m, s + 0xc4);
            w(m, 0x1c412650, m.u8(p) as i32 * 2);
        } else {
            w(m, 0x1c412650, 100);
        }
        addd(m, s + 0xc4, 1);
        let p = ru(m, s + 0xc8);
        w(m, 0x1c412ad0, m.u8(p) as i32 * 2);
        addd(m, s + 0xc8, 1);
        let p = ru(m, s + 0xcc);
        w(m, 0x1c412ad4, m.u8(p) as i32 * 2);
        addd(m, s + 0xcc, 1);
        let p = ru(m, s + 0xd8);
        m.set_u16(0x1c412aba, ((m.u8(p) & 0x70) >> 1) as u16);
        addd(m, s + 0xd8, 1);
        w(m, 0x1c411d98, 1);
        w(m, 0x1c416f44, 0);
        let n2f = ru(m, N2_FEAT);
        let u3 = if cf & 0x2000000 != 0 {
            cf
        } else if nf & 0x2000000 != 0 {
            nf
        } else if n2f & 0x2000000 != 0 {
            n2f
        } else {
            0
        };
        if u3 & 0x400000 == 0 {
            if u3 & 0x200 == 0 {
                if u3 & 0x4000 != 0 {
                    addd(m, 0x1c412650, -4);
                    addd(m, 0x1c412ad0, -7);
                    addd(m, 0x1c412ad4, -4);
                }
            } else {
                addd(m, 0x1c412650, 4);
                addd(m, 0x1c412ad0, 7);
                addd(m, 0x1c412ad4, 4);
            }
        }
    }
    if m.u16(s + 0x4c) != 0 {
        return;
    }
    let p650 = || 0x1c412650u32;
    if cf & 0x2000 != 0 && pf & 0x800000 != 0 && nf & 0x10000000 != 0 && m.u8(NEXT_STRESS) != 0 {
        let v = r(m, p650()) - 10;
        pitch_mid(m, s, fr, v);
    }
    let aba = m.i16(0x1c412aba) as i32;
    if r(m, 0x1c416f44) != 0 {
        let v = if aba != 0 { aba + r(m, 0x1c412ad4) } else { r(m, 0x1c412ad4) };
        pitch_last(m, s, fr, v);
        return;
    }
    if r(m, 0x1c411d98) != 0 {
        w(m, 0x1c416f44, 0);
        if cf & 0x8000000 != 0 {
            w(m, 0x1c411d98, 0);
            let v650 = r(m, 0x1c412650);
            if cf & 0x2000000 == 0 {
                if pf & 0x100 == 0 {
                    if u4 == 0 || nf & 0x2000000 == 0 {
                        pitch_last(m, s, fr, v650);
                    } else {
                        pitch_mid(m, s, fr, v650);
                    }
                } else {
                    pitch_first(m, s, fr, v650);
                    let v = r(m, 0x1c412ad0).wrapping_add(v650) >> 1;
                    pitch_mid(m, s, fr, v);
                }
            } else {
                pitch_first(m, s, fr, v650);
            }
        }
    }
    let ad0 = r(m, 0x1c412ad0);
    let ad4 = r(m, 0x1c412ad4);
    let nfl = ru(m, NEXT_FLAGS);
    if cf & 0x2000000 != 0 {
        if pf & 0x40000 == 0 || pf & 0x8000000 != 0 {
            if m.u8(CUR_STRESS) == 0 {
                if u4 == 0 {
                    pitch_mid(m, s, fr, ad0);
                } else {
                    pitch_first(m, s, fr, ad0);
                }
            } else if u4 == 0 {
                if nfl & 0x80 != 0 {
                    pitch_mid(m, s, fr, ad0);
                } else if nf & 0x10002000 == 0 {
                    pitch_last(m, s, fr, ad0);
                } else {
                    pitch_next_mid(m, s, fr, ad0);
                }
            } else {
                pitch_first(m, s, fr, ad0);
            }
        } else {
            pitch_first(m, s, fr, ad0 + 8);
        }
        if u4 == 0 && aba == 0 {
            if nfl & 0x80 == 0 {
                pitch_next_mid(m, s, fr, ad4);
            } else {
                pitch_last(m, s, fr, ad4);
            }
        }
    }
    if u4 == 0 {
        return;
    }
    // LAB_1c403854
    if b1 && aba == 0 {
        pitch_last(m, s, fr, ad4);
        w(m, 0x1c416f44, 1);
        return;
    }
    if aba != 0 {
        if cf & 0x2000000 != 0 {
            pitch_mid(m, s, fr, ad4);
        }
        if b1 {
            pitch_last(m, s, fr, aba + ad4);
            w(m, 0x1c416f44, 1);
        }
    }
}

/// Note number (`{c4}` etc., command 0xb4 with a value <= 0) to Hz.
fn note(m: &Mem, s: u32, v: i16) -> i16 {
    let mut n = (m.i16(s + 0xac).wrapping_mul(0xc)).wrapping_add(m.i16(s + 0xae)).wrapping_sub(v);
    if n > 0x54 {
        let q = (n.wrapping_sub(0x49) as u16) / 0xc;
        n = n.wrapping_add((q as i16).wrapping_mul(-0xc));
    }
    if n < 0 {
        let q = (0xbu16.wrapping_sub(n as u16)) / 0xc;
        n = n.wrapping_add((q as i16).wrapping_mul(0xc));
    }
    m.i16((0x1c40db20i32 + n as i32 * 2) as u32)
}

/// `1c4039c0`: pitch for `{f0style 4}`-like mode 4 (`fr` = end of the
/// phoneme's frames).
fn pitch_mode4(m: &mut Mem, s: u32, fr: u32, rec: u32) {
    let mut c = ru(m, rec);
    if c != 0 {
        while m.i16(c) != 0x1e {
            match m.i16(c) {
                0x8c => {
                    let v = m.u16(c + 2);
                    m.set_u16(s + 0xae, v);
                }
                0xb4 => {
                    let mut v = m.i16(c + 2);
                    if v < 1 {
                        v = note(m, s, v);
                    } else {
                        if v >= 2000 {
                            v = 2000;
                        }
                        if v < 0xb {
                            v = 10;
                        }
                    }
                    let mut k = m.u16(c + 4);
                    let mut a = (k as i16 as i32 * 0x20) as u32;
                    a = a.wrapping_add(fr);
                    while k < m.u16(CUR_FRAMES) {
                        m.set_i16(a + 0x18, v);
                        a = a.wrapping_add(0x20);
                        k = k.wrapping_add(1);
                    }
                }
                0xf0 => {
                    let v = m.u16(c + 2);
                    m.set_u16(s + 0x4c, v);
                }
                0xfa => {
                    let v = m.u16(c + 2);
                    m.set_u16(s + 0x60, v);
                }
                _ => {}
            }
            c += 6;
        }
    }
    let cf = ru(m, CUR_FEAT);
    if ru(m, CUR_FLAGS) & 0x80 != 0 || cf & 0x20000000 != 0 {
        let mut v = m.u16(0x1c4121b0);
        let ccode = m.u8(CUR_CODE);
        if cf & 0x20000000 == 0 && ccode != 0x1c {
            let p = m.u16(s + 0x46) as i32;
            let k = sx(m, 0x1c40dc98 + ((ccode as i32 + p) & 7) as u32 * 2);
            v = div(k.wrapping_mul(p), 0x6e) as u16;
        }
        m.set_u16(fr + 0x18, v);
        let old = m.u16(0x1c4121b0);
        m.set_u16(fr.wrapping_sub(8), old);
        m.set_u16(0x1c4121b0, v);
    }
}

/// `1c403c50`: pitch for singing (`{f0style sing}`): hold the current note.
fn pitch_sing(m: &mut Mem, s: u32, fr: u32, rec: u32) {
    let hold = m.i16(0x1c4121b0);
    let n = m.u16(CUR_FRAMES);
    let mut a = fr;
    for _ in 0..n {
        m.set_i16(a + 0x18, hold);
        a += 0x20;
    }
    let mut c = ru(m, rec);
    if c != 0 {
        while m.i16(c) != 0x1e {
            match m.i16(c) {
                0x8c => {
                    let v = m.u16(c + 2);
                    m.set_u16(s + 0xae, v);
                }
                0xb4 => {
                    let mut v = m.i16(c + 2);
                    if v < 1 {
                        v = note(m, s, v);
                    } else {
                        if v >= 2000 {
                            v = 2000;
                        }
                        if v < 0xb {
                            v = 10;
                        }
                    }
                    let mut k = m.u16(c + 4);
                    let mut a = (k as i16 as i32 * 0x20) as u32;
                    a = a.wrapping_add(fr);
                    while k < m.u16(CUR_FRAMES) {
                        m.set_i16(a + 0x18, v);
                        a = a.wrapping_add(0x20);
                        k = k.wrapping_add(1);
                    }
                    m.set_i16(0x1c4121b0, v);
                }
                0xf0 => {
                    let v = m.u16(c + 2);
                    m.set_u16(s + 0x4c, v);
                }
                0xfa => {
                    let v = m.u16(c + 2);
                    m.set_u16(s + 0x60, v);
                }
                _ => {}
            }
            c += 6;
        }
    }
}

// ---- the generator ----------------------------------------------------------

/// Copy one window record's fields into the generator's globals.
struct Slot {
    code: u32,
    feat: u32,
    stress: u32,
    byte10: u32,
    flags: u32,
    frames: u32,
    class: u32,
}

fn load_slot(m: &mut Mem, rec: u32, sl: &Slot, ff_to_1b: bool) {
    let mut code = m.u8(rec + 0xc);
    m.set_u8(sl.code, code);
    if ff_to_1b && code == 0xff {
        code = 0x1b;
        m.set_u8(sl.code, code);
    }
    let v = m.u32(rec + 0x12);
    m.set_u32(sl.feat, v);
    let v = m.u8(rec + 0x16) & 0x10;
    m.set_u8(sl.stress, v);
    let v = m.u8(rec + 0x10);
    m.set_u8(sl.byte10, v);
    let v = m.u32(rec + 0x16);
    m.set_u32(sl.flags, v);
    let v = ((m.u16(rec + 0xe) as i32 + 4) >> 3) as u16;
    m.set_u16(sl.frames, v);
    let c = class(m, rec);
    m.set_u16(sl.class, c);
}

/// TISPAN32 `FUN_1c404020`: emit the frames for the phoneme at S+0x28.
pub fn generate(m: &mut Mem, s: u32) {
    let mut st = m.local("frames_es", GARBAGE);
    generate_with(m, s, &mut st);
    m.set_local("frames_es", st);
}

fn generate_with(m: &mut Mem, s: u32, st: &mut Locals) {
    let mut cv3: u8 = 0;
    if m.i16(ru(m, s + 0x28) + 0xc) == 0xff {
        w(m, FIRST_CALL, 1);
        return;
    }
    let v = ru(m, s + 0xfa);
    m.set_u32(FRAME, v);
    if r(m, FIRST_CALL) != 0 {
        const T: [(u32, u32); 17] = [
            (0x1c4122e0, 0x1c412b40),
            (0x1c412320, 0x1c412f40),
            (0x1c4123a0, 0x1c413340),
            (0x1c4123e0, 0x1c413740),
            (0x1c412200, 0x1c413b40),
            (0x1c412250, 0x1c413f40),
            (0x1c412290, 0x1c414340),
            (0x1c412500, 0x1c414740),
            (0x1c412360, 0x1c414b40),
            (0x1c412420, 0x1c414f40),
            (0x1c412470, 0x1c415340),
            (0x1c412540, 0x1c415740),
            (0x1c412580, 0x1c415b40),
            (0x1c412660, 0x1c415f40),
            (0x1c4124c0, 0x1c416340),
            (0x1c4125c0, 0x1c416740),
            (0x1c412610, 0x1c416b40),
        ];
        for (i, (t, _)) in T.iter().enumerate() {
            m.set_u32(TRACKS + 4 * i as u32, *t);
        }
        // Current-frame pointers into each track's buffer.
        for (cur, (t, buf)) in [
            (0x1c4121c4u32, T[0]),
            (0x1c4121cc, T[1]),
            (0x1c4121d0, T[2]),
            (0x1c4121d8, T[3]),
            (0x1c4121b8, T[4]),
            (0x1c4121bc, T[5]),
            (0x1c4121c0, T[6]),
            (0x1c4121e8, T[7]),
            (0x1c4121c8, T[8]),
            (0x1c4121d4, T[9]),
            (0x1c4121e0, T[10]),
            (0x1c4121ec, T[11]),
            (0x1c4121f0, T[12]),
            (0x1c4124b4, T[13]),
            (0x1c4121e4, T[14]),
            (0x1c4121f4, T[15]),
        ] {
            m.set_u32(cur, buf);
            m.set_u32(t + 4, buf);
        }
        m.set_u16(0x1c412aa0, 0);
        m.set_u16(0x1c412aba, 0);
        m.set_u32(0x1c4122d0, 0x1c416b40);
        m.set_u32(0x1c412614, 0x1c416b40);
        w(m, 0x1c411d98, 0);
        w(m, 0x1c416f44, 0);
        w(m, 0x1c412ad4, 0x6e);
        w(m, 0x1c412ad0, 0x6e);
        w(m, 0x1c412650, 0x6e);
        w(m, 0x1c412b34, 0);
        w(m, 0x1c4122e8, 100);
        w(m, 0x1c4124c8, 0);
        w(m, 0x1c412328, 400);
        w(m, 0x1c412208, 100);
        w(m, 0x1c412668, 0xf);
        w(m, 0x1c4123a8, 0x578);
        w(m, 0x1c412258, 100);
        w(m, 0x1c412588, 400);
        for a in [0x1c412508, 0x1c412428, 0x1c412368, 0x1c412478, 0x1c4125c8, 0x1c412618] {
            w(m, a, 0);
        }
        w(m, 0x1c4123e8, 0x960);
        w(m, 0x1c412298, 200);
        w(m, 0x1c412548, 3000);
        // A new phrase: the uninitialised slots hold what the earlier
        // pipeline stages left there.
        st.l46 = GARBAGE.l46;
        st.l47 = GARBAGE.l47;
        st.l20 = sx(m, s + 0x98);
        st.l1c = sx(m, s + 0x9c);
        st.l18 = sx(m, s + 0x9a);
        st.l14 = sx(m, s + 0x9e);
        let fr = ru(m, FRAME);
        let p = m.u16(s + 0x46);
        m.set_u16(fr + 0x18, p);
        let p = m.u16(fr + 0x18);
        m.set_u16(0x1c4121b0, p);
        let d = (m.u16(ru(m, s + 0x28) + 0xe) as i32 + 4) >> 3;
        m.set_u16((fr as i32 + d * 0x20 + 0x18) as u32, p);
        for i in 0..17u32 {
            let t = ru(m, TRACKS + 4 * i);
            let v = r(m, t + 8);
            for o in [0x14, 0x10, 0xc, 0x24, 0x20, 0x1c, 0x18] {
                w(m, t + o, v);
            }
            let v = ru(m, 0x1c40dc50 + 4 * i);
            m.set_u32(t, v);
        }
        m.set_u8(0x1c412ab9, 1);
        w(m, FIRST_CALL, 0);
    }
    let p2 = ru(m, s + 0x20);
    load_slot(
        m,
        p2,
        &Slot {
            code: P2_CODE,
            feat: P2_FEAT,
            stress: P2_STRESS,
            byte10: 0x1c4121a0,
            flags: 0x1c416f48,
            frames: 0x1c412602,
            class: P2_CLASS,
        },
        false,
    );
    let pr = ru(m, s + 0x24);
    load_slot(
        m,
        pr,
        &Slot {
            code: PREV_CODE,
            feat: PREV_FEAT,
            stress: PREV_STRESS,
            byte10: 0x1c416f52,
            flags: PREV_FLAGS,
            frames: 0x1c4121a8,
            class: PREV_CLASS,
        },
        false,
    );
    let rec = ru(m, s + 0x28);
    load_slot(
        m,
        rec,
        &Slot {
            code: CUR_CODE,
            feat: CUR_FEAT,
            stress: CUR_STRESS,
            byte10: 0x1c412b24,
            flags: CUR_FLAGS,
            frames: CUR_FRAMES,
            class: CUR_CLASS,
        },
        false,
    );
    let nx = ru(m, s + 0x2c);
    load_slot(
        m,
        nx,
        &Slot {
            code: NEXT_CODE,
            feat: NEXT_FEAT,
            stress: NEXT_STRESS,
            byte10: 0x1c4121ae,
            flags: NEXT_FLAGS,
            frames: NEXT_FRAMES,
            class: NEXT_CLASS,
        },
        true,
    );
    let n2 = ru(m, s + 0x30);
    load_slot(
        m,
        n2,
        &Slot {
            code: N2_CODE,
            feat: N2_FEAT,
            stress: 0x1c412ab2,
            byte10: 0x1c412abc,
            flags: 0x1c412aa4,
            frames: 0x1c411d96,
            class: 0x1c4124b0,
        },
        true,
    );
    let v = m.u8(0x1c412ab9);
    m.set_u8(0x1c412ab3, v);
    for i in 0..17u32 {
        let t = ru(m, TRACKS + 4 * i);
        w(m, t + 0x28, 0x32);
        w(m, t + 0x38, 0x19);
        w(m, t + 0x3c, 0x4b);
        w(m, t + 0x2c, 7);
        w(m, t + 0x30, 7);
        w(m, t + 0x34, 3);
    }
    let v = m.u16(0x1c4121dc);
    m.set_u16(0x1c412ad8, v);
    formants(m, rec);
    amplitudes(m, s);
    bursts(m, rec);
    for a in [0x1c412414, 0x1c4123d4, 0x1c412354, 0x1c4122c4, 0x1c412284, 0x1c412234] {
        w(m, a, 5);
    }
    let v = (m.i16(s + 0x5e).wrapping_add(3)) as i32;
    w(m, 0x1c4125b4, v);
    w(m, 0x1c412574, v);
    w(m, 0x1c412534, sx(m, s + 0x7e) + 3);
    w(m, 0x1c412454, sx(m, s + 0x80) + 3);
    let v = sx(m, s + 0x82) + 3;
    w(m, 0x1c4124a4, v);
    w(m, 0x1c412394, v);
    for i in 0..17u32 {
        let t = ru(m, TRACKS + 4 * i);
        track(m, t);
    }
    let n = m.u16(CUR_FRAMES) as u32;
    {
        let (a, b, c) = (ru(m, 0x1c412504), ru(m, 0x1c412424), ru(m, 0x1c412364));
        for i in 0..n {
            let mut v = m.i16(a + 2 * i);
            if v < 1 {
                v = 0;
            }
            let x = tb(m, 0x1c40609e, v as i32) as i16;
            m.set_i16(a + 2 * i, x);
            let mut v = m.i16(b + 2 * i);
            if v < 1 {
                v = 0;
            }
            let x = tb(m, 0x1c40609e, v as i32) as i16 - 10;
            m.set_i16(b + 2 * i, x);
            let mut v = m.i16(c + 2 * i);
            if v < 1 {
                v = 0;
            }
            let x = tb(m, 0x1c40609e, v as i32) as i16;
            m.set_i16(c + 2 * i, x);
        }
    }
    closure(m);
    let cf = ru(m, CUR_FEAT);
    let pf = ru(m, PREV_FEAT);
    if cf & 0x40000 != 0
        && cf & 0x8000000 != 0
        && m.u8(CUR_STRESS) != 0
        && (pf & 0x20000000 != 0 || ru(m, PREV_FLAGS) & 8 != 0 || m.u8(CUR_CODE) == 0x4f)
    {
        let d: i16 = if pf & 0x8000000 == 0 || pf & 0x800000 == 0 || m.i16(s + 0x2f2) == 2 {
            0x3c
        } else {
            5
        };
        st.t1c = (st.t1c as u32 & 0xffff0000 | d as u16 as u32) as i32;
        let (a, b, c, e, f) = (
            ru(m, 0x1c412504),
            ru(m, 0x1c412424),
            ru(m, 0x1c412324),
            ru(m, 0x1c412204),
            ru(m, 0x1c412254),
        );
        let v52 = m.i16(s + 0x52);
        for i in 0..n {
            addw(m, a + 2 * i, -(d as i32));
            m.set_i16(b + 2 * i, 0);
            m.set_i16(c + 2 * i, if v52 == 1 { 0xfa } else { 0x78 });
            addw(m, e + 2 * i, 0x28);
            addw(m, f + 2 * i, 0xfa);
        }
    }
    let nasal = cf & 0x8000 != 0;
    let mut bv13: u32 = if nasal { 0x10 } else { 0 };
    for (d, src) in [
        (0x1c4121c4u32, 0x1c4122e4u32),
        (0x1c4121cc, 0x1c412324),
        (0x1c4121d0, 0x1c4123a4),
        (0x1c4121d8, 0x1c4123e4),
        (0x1c4121b8, 0x1c412204),
        (0x1c4121bc, 0x1c412254),
        (0x1c4121c0, 0x1c412294),
        (0x1c4121ec, 0x1c412544),
        (0x1c4121f0, 0x1c412584),
        (0x1c4121e8, 0x1c412504),
        (0x1c4121d4, 0x1c412424),
        (0x1c4121c8, 0x1c412364),
        (0x1c4121e0, 0x1c412474),
        (0x1c4121e4, 0x1c4124c4),
        (0x1c4124b4, 0x1c412664),
        (0x1c4122d0, 0x1c412614),
        (0x1c4121f4, 0x1c4125c4),
    ] {
        let v = ru(m, src);
        m.set_u32(d, v);
    }
    let mut l42: u16 = 0;
    if m.u16(CUR_FRAMES) != 0 {
        st.f1 = st.t1c;
        st.f2 = st.t1c;
    }
    let n2rec = ru(m, s + 0x30);
    while l42 < m.u16(CUR_FRAMES) {
        let mut c = ru(m, rec);
        if c != 0 && m.i16(c) != 0x1e {
            loop {
                if sx(m, c + 4) == l42 as i32 {
                    let code = m.i16(c);
                    let arg = m.i16(c + 2);
                    match code {
                        0xbe => m.set_i16(s + 0x44, arg),
                        0x32 => {
                            let e = 0x1c40d318u32.wrapping_add((arg as i32 * 0x4a) as u32);
                            if m.i16(s + 0x4c) != 3 {
                                let v = m.u16(e + 0x12);
                                m.set_u16(s + 0x4c, v);
                                let v = m.u16(e + 8);
                                m.set_u16(s + 0x44, v);
                            }
                            for (so, eo) in [
                                (0x52u32, 0xau32),
                                (0x2f2, 0xe),
                                (0x46, 4),
                                (0xac, 6),
                                (0x60, 0x14),
                                (0x62, 0x16),
                                (0x64, 0x1a),
                                (0x66, 0x1c),
                                (0x8a, 0x10),
                                (0x98, 0x42),
                                (0x9a, 0x44),
                                (0x9c, 0x46),
                                (0x9e, 0x48),
                                (0x92, 0x36),
                                (0x94, 0x38),
                                (0x96, 0x3a),
                                (0x8c, 0x3c),
                                (0x8e, 0x3e),
                                (0x90, 0x40),
                                (0x84, 0x30),
                                (0x86, 0x32),
                                (0x88, 0x34),
                                (0x7e, 0x2a),
                                (0x80, 0x2c),
                                (0x82, 0x2e),
                                (0x5c, 0x26),
                                (0x5e, 0x28),
                            ] {
                                let v = m.u16(e + eo);
                                m.set_u16(s + so, v);
                            }
                        }
                        0xdc => m.set_i16(s + 0x2f2, arg),
                        200 => m.set_i16(s + 0x52, arg),
                        0xf0 => m.set_i16(s + 0x4c, arg),
                        0xe6 => m.set_i16(s + 0x8a, arg),
                        0x14a => m.set_i16(s + 0x5e, arg),
                        0x140 => m.set_i16(s + 0x5c, arg),
                        0x15e => m.set_i16(s + 0x80, arg),
                        0x154 => m.set_i16(s + 0x7e, arg),
                        0x172 => m.set_i16(s + 0x84, arg),
                        0x168 => m.set_i16(s + 0x82, arg),
                        0x186 => m.set_i16(s + 0x88, arg),
                        0x17c => m.set_i16(s + 0x86, arg),
                        0x1fe => m.set_i16(s + 0x94, arg),
                        500 => m.set_i16(s + 0x92, arg),
                        0x226 => m.set_i16(s + 0x8c, arg),
                        0x208 => m.set_i16(s + 0x96, arg),
                        0x23a => m.set_i16(s + 0x90, arg),
                        0x230 => m.set_i16(s + 0x8e, arg),
                        0x334 => {
                            st.l46 = arg;
                            bv13 |= 0x20;
                        }
                        0x352 => {
                            bv13 |= 8;
                            st.l47 = arg as u8;
                        }
                        _ => {}
                    }
                }
                c += 6;
                if m.i16(c) == 0x1e {
                    break;
                }
            }
        }
        let mut l44: i16 = m.i16(ru(m, 0x1c4124b4)) >> 8;
        if !nasal {
            st.f1 = sx(m, ru(m, 0x1c4121cc));
            st.f2 = sx(m, ru(m, 0x1c4121d0));
            st.f3 = sx(m, ru(m, 0x1c4121d8));
            st.b1 = sx(m, ru(m, 0x1c4121b8));
            st.b2 = sx(m, ru(m, 0x1c4121bc));
            st.b3 = sx(m, ru(m, 0x1c4121c0));
        } else {
            let set = match m.u8(CUR_CODE) {
                0x3c | 0x57 => Some((0x14a, 0x4a1, 0x898)),
                0x3d | 0x58 => Some((0x109, 0x640, 0x8fc)),
                0x3e => Some((0xfa, 0x6d6, 0x8ca)),
                _ => None,
            };
            if let Some((f1, f2, f3)) = set {
                st.f1 = f1;
                st.f2 = f2;
                st.f3 = f3;
                st.b1 = 500;
                st.b3 = 0x3c;
            }
        }
        let pe8 = ru(m, 0x1c4121e8);
        let pd4 = ru(m, 0x1c4121d4);
        let pc8 = ru(m, 0x1c4121c8);
        let s2f2 = m.i16(s + 0x2f2);
        if s2f2 == 1 {
            if m.i16(s + 0x52) == 0 {
                st.b1 += 0x3c;
            }
            let a = sx(m, pe8) - 7;
            let b = sx(m, pd4);
            m.set_i16(pd4, if a > b { a } else { b } as i16);
            let x = m.i16(pe8);
            if x > 0x14 {
                m.set_i16(pe8, x.wrapping_add(4));
            }
            l44 = l44.wrapping_sub(4);
        } else if s2f2 == 2 {
            let a = sx(m, pe8) - 3;
            let b = sx(m, pd4);
            st.b1 = 200;
            m.set_i16(pd4, if a > b { a } else { b } as i16);
            m.set_i16(pe8, 0);
        } else if nasal {
            m.set_i16(pd4, 0);
        } else {
            let a = sx(m, pe8) - 0x14;
            let b = sx(m, pd4);
            m.set_i16(pd4, if a > b { a } else { b } as i16);
        }
        if cf & 0x8000 != 0 {
            addw(m, pd4, -7);
        }
        if r(m, 0x1c412b28) != 0 {
            match l42 & 3 {
                0 | 2 => {
                    st.f1 -= 0x32;
                    st.f2 = st.f2.wrapping_mul(3).wrapping_add(0x4b0) >> 2;
                    st.b2 = st.b2.wrapping_add(200) >> 1;
                    st.b1 += 0x28;
                    addw(m, pe8, -3);
                    st.f3 = st.f3.wrapping_add(2000) >> 1;
                }
                1 => {
                    st.f1 -= 100;
                    st.f2 = st.f2.wrapping_add(0x4b0) >> 1;
                    st.b1 += 0x50;
                    addw(m, pe8, -6);
                    st.b2 = 200;
                    st.f3 = 2000;
                }
                _ => {}
            }
        }
        let k = sx(m, s + 0x5c) + 10;
        let v52 = m.i16(s + 0x52);
        let nf2: i32; // ebp: F2
        let mut bw1: i32; // ecx: B1
        if v52 == 1 {
            st.f3 = st.f3.wrapping_add(0x1d1);
            addw(m, pe8, -10);
            l44 = l44.wrapping_sub(5);
            addw(m, pd4, -0x14);
            addw(m, pc8, -6);
            st.t1c = div((st.f1 - 0x1c2).wrapping_mul(k).wrapping_mul(0x73), 1000) + 0x24a;
            nf2 = div((st.f2 - 0x5aa).wrapping_mul(k).wrapping_mul(0x87), 1000) + 0x6de;
            if st.f3.wrapping_sub(nf2) < 300 {
                st.f3 = nf2 + 300;
            }
            bw1 = div(st.t1c.wrapping_mul(st.b1), st.f1) + 0x32;
            st.b2 = div(nf2.wrapping_mul(st.b2), st.f2);
            if bw1 >= 0x15e {
                bw1 = 0x15e;
            }
            if bw1 <= 0x46 {
                bw1 = 0x46;
            }
            addw(m, ru(m, 0x1c4121ec), 0x96);
        } else if v52 == 2 {
            l44 = l44.wrapping_sub(1);
            addw(m, pe8, -0xd);
            addw(m, pd4, -0x16);
            st.f3 = st.f3.wrapping_add(0x429);
            addw(m, pc8, -7);
            st.t1c = div((st.f1 - 0x1c2).wrapping_mul(k).wrapping_mul(0x91), 1000) + 0x2e4;
            nf2 = div((st.f2 - 0x5aa).wrapping_mul(k).wrapping_mul(0x91), 1000) + 0x834;
            if st.f3.wrapping_sub(nf2) < 0x15e {
                st.f3 = nf2 + 0x15e;
            }
            bw1 = div(st.t1c.wrapping_mul(st.b1), st.f1) + 0x96;
            st.b2 = div(nf2.wrapping_mul(st.b2), st.f2) + 0x32;
            if bw1 >= 0x12c {
                bw1 = 0x12c;
            }
            if bw1 <= 100 {
                bw1 = 100;
            }
            addw(m, ru(m, 0x1c4121ec), 0xfa);
        } else {
            let (of1, of2, of3) = (st.f1, st.f2, st.f3);
            st.t1c = of1;
            let f3m = of3.wrapping_sub(0x9a1);
            st.f3 = f3m;
            let nf1;
            if v52 == 3 {
                nf1 = div((of1 - 0x1c2).wrapping_mul(k).wrapping_mul(0x5c), 1000) + 400;
                let tmp = div((of2 - 0x5aa).wrapping_mul(k).wrapping_mul(0x5c), 1000);
                nf2 = tmp + 0x564;
                st.f3 = div(k.wrapping_mul(f3m).wrapping_mul(0x5c), 1000) + 0x92e;
                if st.f3.wrapping_sub(nf2) < 0xfa {
                    st.f3 = nf2 + 0xfa;
                }
                addw(m, ru(m, 0x1c4121ec), -100);
            } else {
                nf1 = div((of1 - 0x1c2).wrapping_mul(k).wrapping_mul(100), 1000) + 0x1c2;
                nf2 = div((of2 - 0x5aa).wrapping_mul(k).wrapping_mul(100), 1000) + 0x5aa;
                st.f3 = div(k.wrapping_mul(f3m).wrapping_mul(100), 1000) + 0x9a1;
            }
            st.f1 = nf1;
            bw1 = div(nf1.wrapping_mul(st.b1), of1);
            st.b2 = div(nf2.wrapping_mul(st.b2), of2);
            st.b3 = div(st.b3.wrapping_mul(st.f3), of3);
            if bw1 >= 0x12c {
                bw1 = 0x12c;
            }
            if bw1 <= 0x28 {
                bw1 = 0x28;
            }
            let mut x = sx(m, s + 0x46) - 0x6e;
            if x <= 0 {
                x = 0;
            }
            x /= 0xe;
            if x >= 0x14 {
                x = 0x14;
            }
            addw(m, pe8, -x);
            addw(m, pd4, -0xd);
            addw(m, pc8, -2);
            st.t1c = div(nf1.wrapping_mul(34), 0x21);
        }
        // 1c405244
        addw(m, pe8, sx(m, s + 0x84));
        addw(m, pd4, sx(m, s + 0x86));
        addw(m, pc8, sx(m, s + 0x88));
        let clamp = |v: i32, lo: i32, hi: i32| {
            let v = if v >= hi { hi } else { v };
            if v <= lo {
                lo
            } else {
                v
            }
        };
        st.f1 = clamp(div(sx(m, s + 0x92).wrapping_mul(st.t1c), 100), 100, 0xff0);
        st.f2 = clamp(div(sx(m, s + 0x94).wrapping_mul(nf2), 100), 100, 0xff0);
        st.f3 = clamp(div(sx(m, s + 0x96).wrapping_mul(st.f3), 100), 100, 0xff0);
        let bb1 = div(sx(m, s + 0x8c).wrapping_mul(bw1), 100);
        let bb2 = div(sx(m, s + 0x8e).wrapping_mul(st.b2), 100);
        st.t1c = 100;
        let bb3 = div(sx(m, s + 0x90).wrapping_mul(st.b3), 100);
        st.b1 = clamp(bb1, 0x28, 0x1f4);
        st.b2 = clamp(bb2, 0x28, 0x1f4);
        st.b3 = clamp(bb3, 0x28, 0x1f4);
        let smooth = |cur: i32, tgt: i32| cur.wrapping_add(tgt.wrapping_sub(cur).wrapping_mul(5000) >> 16);
        st.l20 = smooth(st.l20, sx(m, s + 0x98));
        st.l1c = smooth(st.l1c, sx(m, s + 0x9c));
        st.l18 = smooth(st.l18, sx(m, s + 0x9a));
        st.l14 = smooth(st.l14, sx(m, s + 0x9e));
        l44 = l44.wrapping_add(m.i16(s + 0x8a));
        if l44 >= 0xf {
            l44 = 0xf;
        }
        if l44 <= 0 {
            l44 = 0;
        }
        let mut av = sx(m, ru(m, 0x1c4121ec)); // ebp
        st.t1c = sx(m, ru(m, 0x1c4121f0));
        if m.i16(s + 0x48) == 8000 {
            let k = |v: i32| v.wrapping_mul(11) >> 3;
            st.f1 = k(st.f1);
            st.b1 = k(st.b1);
            st.f2 = k(st.f2);
            st.b2 = k(st.b2);
            st.f3 = k(st.f3);
            st.b3 = k(st.b3);
            st.l20 = k(st.l20);
            st.l18 = k(st.l18);
            st.l1c = k(st.l1c);
            st.l14 = k(st.l14);
            av = k(av);
            st.t1c = k(st.t1c);
        }
        let ccode = m.u8(CUR_CODE);
        let off = if cf & 0xc0100000 == 0 || (m.u16(CUR_FRAMES) >> 1) >= l42 { 0x17 } else { 0x31 };
        let mut ab9 = m.u8((ccode as u32 * 0x1a + off).wrapping_add(ru(m, n2rec + 4)));
        if ab9 == 0 {
            ab9 = m.u8(0x1c412ab3);
        }
        m.set_u8(0x1c412ab9, ab9);
        let fr = ru(m, FRAME);
        m.set_u8(fr + 0x1a, ab9);
        let d16 = |v: i32| (v / 16) as u8 as i32;
        let d32 = |v: i32| (v / 32) as u8 as i32;
        let d8 = |v: i32| (v / 8) as u8 as i32;
        let v = tb(m, TBL_F, d16(st.f1 + 8));
        m.set_u8(fr, v);
        let v = tb(m, TBL_F, d16(st.f2 + 8));
        m.set_u8(fr + 1, v);
        let v = tb(m, TBL_F, d16(st.f3 + 8));
        m.set_u8(fr + 2, v);
        let v = tb(m, TBL_A, d32(st.l20 + 0x10));
        m.set_u8(fr + 3, v);
        let v = tb(m, TBL_A, d32(st.l1c + 0x10));
        m.set_u8(fr + 4, v);
        m.set_u8(fr + 5, 0);
        let v = (tb(m, TBL_BW, d8(st.b1 + 4)) << 4).wrapping_add(tb(m, TBL_BW, d8(st.b2 + 4)));
        m.set_u8(fr + 6, v);
        let v = (tb(m, TBL_BW, d8(st.b3 + 4)) << 4).wrapping_add(l44 as u8);
        m.set_u8(fr + 7, v);
        let v = (tb(m, TBL_BW2, d8(st.l18 + 4)) << 4).wrapping_add(tb(m, TBL_BW2, d8(st.l14 + 4)));
        m.set_u8(fr + 8, v);
        let v = tb(m, TBL_A, d32(av + 0x10));
        m.set_u8(fr + 9, v);
        m.set_u8(fr + 0xb, ccode);
        let mut x = m.u16(s + 0x44) >> 1;
        if x <= 1 {
            x = 1;
        }
        m.set_u8(fr + 10, x as u8);
        let c8 = |v: i32| {
            let v = if v >= 0x80 { 0x80 } else { v };
            if v <= 0 {
                0
            } else {
                v
            }
        };
        let v = c8(sx(m, ru(m, 0x1c4121e8)) * 2);
        m.set_u8(fr + 0x10, v as u8);
        let v = c8(sx(m, ru(m, 0x1c4121d4)) * 2);
        m.set_u8(fr + 0x11, v as u8);
        let v = c8(sx(m, ru(m, 0x1c4121c8)) * 2);
        m.set_u8(fr + 0x12, v as u8);
        let mut v = sx(m, ru(m, 0x1c4121e0)) * 2 + 0x5c;
        if v <= 0 {
            v = 0;
        }
        m.set_u8(fr + 0x13, v as u8);
        let v = tb(m, TBL_BW2, d8(st.t1c + 4)) << 4;
        m.set_u8(fr + 0x14, v);
        m.set_u8(fr + 0x1b, st.l47);
        m.set_i16(fr + 0x1c, st.l46);
        m.set_u8(fr + 0x17, bv13 as u8);
        m.set_u8(fr + 0x1f, cv3);
        cv3 = cv3.wrapping_add(1);
        let s4c = m.u16(s + 0x4c);
        if s4c == 2 {
            let v = m.u16(s + 0x46);
            m.set_u16(fr + 0x18, v);
        } else if s4c != 4 {
            m.set_u16(fr + 0x18, 0);
        }
        m.set_u32(FRAME, fr + 0x20);
        bv13 &= !0x28;
        for a in [
            0x1c4121cc, 0x1c4121d0, 0x1c4121d8, 0x1c4121b8, 0x1c4121bc, 0x1c4121c0, 0x1c4121ec, 0x1c4121f0,
            0x1c4124b4, 0x1c4121e4, 0x1c4121e8, 0x1c4121d4, 0x1c4121c8, 0x1c4121e0, 0x1c4121c4,
        ] {
            addd(m, a, 2);
        }
        l42 = l42.wrapping_add(1);
    }
    let v = m.u16(s + 0x46);
    let f0 = ru(m, s + 0xf6);
    m.set_u16(f0 + 0x18, v);
    let n = m.u16(CUR_FRAMES) as u32;
    let end = ru(m, FRAME);
    let first = end.wrapping_sub(n * 0x20);
    pitch(m, s, first, rec);
    match m.u16(s + 0x4c) {
        3 => pitch_sing(m, s, first, rec),
        4 => pitch_mode4(m, s, end, rec),
        _ => {}
    }
    let fl = ru(m, rec + 0x16);
    let mut b: u8 = if fl & 0x100 != 0 { 3 } else { 1 };
    if fl & 0x80 != 0 {
        b |= 4;
    }
    let end = ru(m, FRAME);
    let a = end.wrapping_sub(m.u16(CUR_FRAMES) as u32 * 0x20) + 0x17;
    let v = m.u8(a) | b;
    m.set_u8(a, v);
    m.set_u32(s + 0xfa, end);
    let v = tb(m, TBL_A, (sx(m, s + 0x98) + 0x10) / 32 & 0xff) as u16;
    m.set_u16(s + 0xa0, v);
    let v = tb(m, TBL_A, (sx(m, s + 0x9c) + 0x10) / 32 & 0xff) as u16;
    m.set_u16(s + 0xa4, v);
    let v = tb(m, TBL_BW2, (sx(m, s + 0x9a) + 4) / 8 & 0xff) as u16;
    m.set_u16(s + 0xa2, v);
    let v = tb(m, TBL_BW2, (sx(m, s + 0x9e) + 4) / 8 & 0xff) as u16;
    m.set_u16(s + 0xa6, v);
}
