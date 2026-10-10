//! English frame generator (language slot [2]): TIENG32 `FUN_1c204690` and
//! its helpers.
//!
//! The generator keeps 17 parameter "tracks" in TIENG32's `.bss` (formant
//! frequencies and bandwidths, amplitudes, ...).  Each track is a 0x40-byte
//! structure:
//!   +0x00 u32  pointer (from the table at 0x1c24c158)
//!   +0x04 u32  per-frame output buffer (i16 x frames)
//!   +0x08 i32  target of the current phoneme      +0x18 i32  new target
//!   +0x0c i32  second target                     +0x1c i32  new second target
//!   +0x10/0x14 previous targets, +0x20/0x24 boundary values
//!   +0x28 i32  boundary percentage, +0x2c/0x30 i32 transition speeds,
//!   +0x34 i32  speed row, +0x38/0x3c i32 transition start/end (% of phoneme)
//! Every global is read and written at its original address and width so
//! the module state stays byte-identical to the DLL's.
//!
//! The helpers live in `frames_en_targets.rs` (per-phoneme targets) and
//! `frames_en_f0.rs` (F0 commands and accents).


use crate::mem::Mem;

/// Base of the generator's globals (most are within 0x1c250000..0x1c251000).
const B: u32 = 0x1c250000;

/// i32 global at B + offset.
macro_rules! g {
    ($m:expr, $o:expr) => {
        $m.i32(B + $o)
    };
}
/// Store an i32 global at B + offset.
macro_rules! s {
    ($m:expr, $o:expr, $v:expr) => {{
        let v: i32 = $v;
        $m.set_i32(B + $o, v);
    }};
}

#[path = "frames_en_f0.rs"]
mod f0;
#[path = "frames_en_targets.rs"]
mod targets;

// Context of the five records in the window (S+0x20..0x30), copied by the
// generator into its globals.  Codes are bytes, features/flags u32, the
// "stressed" flags bytes (flags & 0x10), frame counts and classes u16.
const P2_CODE: u32 = 0x1c255301;
const P2_FEAT: u32 = 0x1c250ed8;
const P2_STRF: u32 = 0x1c250edc;
const P2_STRESS: u32 = 0x1c250550;
const P2_FLAGS: u32 = 0x1c2552f8;
const P2_NFR: u32 = 0x1c2509b2;
const P2_CLASS: u32 = 0x1c2509b0;

const P_CODE: u32 = 0x1c255303;
const P_FEAT: u32 = 0x1c250e64;
const P_STRF: u32 = 0x1c250e68;
const P_STRESS: u32 = 0x1c255302;
const P_FLAGS: u32 = 0x1c2552f0;
const P_NFR: u32 = 0x1c250558;
const P_CLASS: u32 = 0x1c2505f0;

const C_CODE: u32 = 0x1c250e7e;
const C_FEAT: u32 = 0x1c250e70;
const C_STRF: u32 = 0x1c250e74;
const C_STRESS: u32 = 0x1c250ed4;
const C_FLAGS: u32 = 0x1c250e78;
const NFR: u32 = 0x1c250566;
const C_CLASS: u32 = 0x1c250564;

const N_CODE: u32 = 0x1c250810;
const N_FEAT: u32 = 0x1c2552fc;
const N_STRF: u32 = 0x1c255300;
const N_STRESS: u32 = 0x1c25055e;
const N_FLAGS: u32 = 0x1c250554;
const N_NFR: u32 = 0x1c250e60;
const N_CLASS: u32 = 0x1c250e7c;

const N2_CODE: u32 = 0x1c2509b4;
const N2_FEAT: u32 = 0x1c250e5c;
const N2_STRF: u32 = 0x1c250e62;
const N2_STRESS: u32 = 0x1c250e6c;
const N2_FLAGS: u32 = 0x1c250e54;
const N2_NFR: u32 = 0x1c250146;
const N2_CLASS: u32 = 0x1c250860;

/// First-call flag (set again by the terminating call).
const FIRST: u32 = 0x1c24c154;
/// Output frame pointer.
const OUT: u32 = 0x1c250e58;
/// Track pointer table (17 entries).
const TRACKS: u32 = 0x1c250e90;
const NTRACKS: u32 = 17;
/// Voicing source byte of the current phoneme / of the previous call.
const SOURCE: u32 = 0x1c250e69;
const SOURCE_PREV: u32 = 0x1c250e63;

/// Byte tables in TIENG32's `.rdata`, indexed by quantised values.
const TAB_FREQ: u32 = 0x1c205ff4;
const TAB_GAIN: u32 = 0x1c2060f4;
const TAB_BW: u32 = 0x1c2061f4;
const TAB_TILT: u32 = 0x1c2062f4;
const TAB_AMP: u32 = 0x1c20660e;
/// Voice presets (LangDef table [3]), 0x4a bytes each.
const PRESETS: u32 = 0x1c24b318;

/// Stack slots of `FUN_1c204690` that are read before being written in a
/// call.  `5840` calls the generator in a loop at the same stack depth and
/// nothing else uses that stack in between, so they carry their values
/// from one call to the next (and from one frame to the next).
#[derive(Clone, Copy)]
struct Carry {
    /// [esp+0x11]: frame byte 0x1b (set by command 0x352).
    b11: u8,
    /// [esp+0x12]: frame word 0x1c (set by command 0x334).
    w12: i16,
    /// [esp+0x28]: the F2 bandwidth; not reloaded for the nasals (feature
    /// 0x8000), which reuse the previous frame's value.
    s28: i32,
    /// [esp+0x3c..0x48]: smoothed S+0x98, S+0x9c, S+0x9a, S+0x9e; only
    /// initialised by the first call of a phrase.
    s3c: i32,
    s40: i32,
    s44: i32,
    s48: i32,
}

/// What the oracle shows in those slots before the first call of every
/// phrase (byte 0x1b of the first frames is 0xa0, word 0x1c is 0).
const CARRY_INIT: Carry = Carry { b11: 0xa0, w12: 0, s28: 0, s3c: 0, s40: 0, s44: 0, s48: 0 };


#[inline]
fn add16(m: &mut Mem, a: u32, d: i32) {
    let v = (m.i16(a) as i32).wrapping_add(d);
    m.set_i16(a, v as i16);
}

#[inline]
fn track(m: &Mem, i: u32) -> u32 {
    m.u32(TRACKS + 4 * i)
}

/// `FUN_1c202fe0`: start a new phoneme on a track (current targets become
/// the previous ones, new targets become current).
fn shift(m: &mut Mem, t: u32) {
    m.set_u32(t + 0x10, m.u32(t + 8));
    m.set_u32(t + 8, m.u32(t + 0x18));
    m.set_u32(t + 0x14, m.u32(t + 0xc));
    m.set_u32(t + 0xc, m.u32(t + 0x1c));
    m.set_u32(t + 0x20, m.u32(t + 0x24));
}

/// `FUN_1c203010`: articulation class of a record's phoneme.
fn class(m: &Mem, rec: u32) -> u16 {
    let code = m.u16(rec + 0xc);
    if code == 0xff {
        return 9;
    }
    let f = m.u32((code as u32 * 0x1a + 2).wrapping_add(m.u32(rec + 4)));
    if f & 0x10000000 != 0 {
        0
    } else if f & 0x2000 != 0 {
        1
    } else if f & 0x8000 != 0 {
        2
    } else if f & 0x40 != 0 {
        if f & 0x8000000 != 0 { 3 } else { 5 }
    } else if f & 0x40000 != 0 {
        if f & 0x8000000 != 0 { 4 } else { 6 }
    } else if f & 4 != 0 {
        7
    } else if f & 0x20000000 != 0 {
        9
    } else if f & 0x100 != 0 {
        8
    } else {
        9
    }
}

/// `FUN_1c203870`: render a track's per-frame contour into its buffer: an
/// exponential approach from the boundary value to the target, crossfaded
/// (weights in 0x1c250a50, forward pass in 0x1c250150) with an approach
/// from the far boundary to the second target computed backwards.
fn contour(m: &mut Mem, t: u32) {
    const WEIGHT: u32 = 0x1c250a50;
    const FWD: u32 = 0x1c250150;
    const SPEEDS: u32 = 0x1c24c1b0;
    let n = m.u16(NFR) as i32;
    let start = (m.i32(t + 0x38).wrapping_mul(n)) / 100 + 1;
    let mut len = (m.i32(t + 0x3c).wrapping_mul(n).wrapping_add(0x32)) / 100 - start;
    if len <= 1 {
        len = 1;
    }
    let step = 0x8000 / len;
    let mut w = 0x8000 - step;
    let mut p = WEIGHT;
    if start > 0 {
        for k in 0..start as u32 {
            m.set_u16(WEIGHT + 2 * k, 0x100);
        }
        p = WEIGHT + (start as u32) * 2;
    }
    let mut k = start;
    while n > k {
        if w < 0 {
            w = 0;
        }
        m.set_u16(p, (w >> 7) as u16);
        p += 2;
        w -= step;
        k += 1;
    }
    m.set_u16((WEIGHT - 2).wrapping_add((n as u32) * 2), 0);
    let mut row = m.i32(t + 0x34);
    if row >= 8 {
        row = 8;
    }
    if row <= 0 {
        row = 0;
    }
    row <<= 4;
    let mut v = m.i32(t + 0x20);
    let target = m.i32(t + 8);
    let speed = m.i32((SPEEDS as i32 + (m.i32(t + 0x2c) + row) * 4) as u32);
    for i in 0..n as u32 {
        v = v.wrapping_add((target.wrapping_sub(v)).wrapping_mul(speed) >> 8);
        let wt = m.i16(WEIGHT + 2 * i) as i32;
        m.set_u16(FWD + 2 * i, (wt.wrapping_mul(v) >> 8) as u16);
    }
    let buf = m.u32(t + 4);
    let target2 = m.i32(t + 0xc);
    let mut v = m.i32(t + 0x24);
    let speed = m.i32((SPEEDS as i32 + (m.i32(t + 0x30) + row) * 4) as u32);
    for i in (0..n as u32).rev() {
        let wt = m.i16(WEIGHT + 2 * i) as i32;
        let x = ((0x100 - wt).wrapping_mul(v) >> 8) as u16;
        m.set_u16(buf.wrapping_add(2 * i), x.wrapping_add(m.u16(FWD + 2 * i)));
        v = v.wrapping_add((target2.wrapping_sub(v)).wrapping_mul(speed) >> 8);
    }
}

/// `FUN_1c203a30`: aspiration ramp at the end of the phoneme (the last
/// 0x1c25058c frames of track 0x710 get 0x1c25055c).
fn aspiration_tail(m: &mut Mem) {
    let count = m.i16(B + 0x58c);
    let level = m.i16(B + 0x55c);
    if count <= 0 || level <= 0 {
        return;
    }
    let buf = m.u32(B + 0x714);
    let mut p = (m.u16(NFR) as u32 * 2).wrapping_add(buf);
    let mut i: i16 = 0;
    while count > i {
        p = p.wrapping_sub(2);
        i += 1;
        m.set_i16(p, level);
    }
    if m.u8(C_FEAT) & 1 != 0 {
        add16(m, p, -8);
        add16(m, p + 2, -4);
        let q = buf.wrapping_add(m.u16(NFR) as u32 * 2).wrapping_sub(2);
        add16(m, q, -8);
        add16(m, q.wrapping_sub(2), -4);
    }
}

/// Copy a record of the window into the generator's globals.
#[allow(clippy::too_many_arguments)]
fn load_record(
    m: &mut Mem,
    rec: u32,
    code: u32,
    feat: u32,
    strf: u32,
    stress: u32,
    flags: u32,
    nfr: u32,
    cls: u32,
    end_code: bool,
) {
    let c = m.u8(rec + 0xc);
    m.set_u8(code, if end_code && c == 0xff { 0x1b } else { c });
    m.set_u32(feat, m.u32(rec + 0x12));
    m.set_u8(strf, m.u8(rec + 0x16) & 0x10);
    m.set_u8(stress, m.u8(rec + 0x10));
    m.set_u32(flags, m.u32(rec + 0x16));
    m.set_u16(nfr, ((m.u16(rec + 0xe) as i32 + 4) >> 3) as u16);
    let k = class(m, rec);
    m.set_u16(cls, k);
}

/// Index of a quantisation table: (v + r/2) / r, low byte.
#[inline]
fn q(v: i32, half: i32, div: i32) -> u32 {
    ((v.wrapping_add(half) / div) & 0xff) as u32
}

/// TIENG32 `FUN_1c204690`: emit the frames for the phoneme at S+0x28.
pub fn generate(m: &mut Mem, s: u32) {
    let rec28 = m.u32(s + 0x28);
    if m.i16(rec28 + 0xc) == 0xff {
        m.set_u32(FIRST, 1);
        return;
    }
    let mut counter: u8 = 0;
    m.set_u32(OUT, m.u32(s + 0xfa));
    let mut st = m.local("frames_en", CARRY_INIT);
    if m.u32(FIRST) != 0 {
        st = CARRY_INIT;
        first_call(m, s, rec28, &mut st);
    }

    let rec20 = m.u32(s + 0x20);
    load_record(m, rec20, P2_CODE, P2_FEAT, P2_STRF, P2_STRESS, P2_FLAGS, P2_NFR, P2_CLASS, false);
    let rec24 = m.u32(s + 0x24);
    load_record(m, rec24, P_CODE, P_FEAT, P_STRF, P_STRESS, P_FLAGS, P_NFR, P_CLASS, false);
    load_record(m, rec28, C_CODE, C_FEAT, C_STRF, C_STRESS, C_FLAGS, NFR, C_CLASS, false);
    let rec2c = m.u32(s + 0x2c);
    load_record(m, rec2c, N_CODE, N_FEAT, N_STRF, N_STRESS, N_FLAGS, N_NFR, N_CLASS, true);
    let rec30 = m.u32(s + 0x30);
    load_record(m, rec30, N2_CODE, N2_FEAT, N2_STRF, N2_STRESS, N2_FLAGS, N2_NFR, N2_CLASS, true);
    m.set_u8(SOURCE_PREV, m.u8(SOURCE));

    for i in 0..NTRACKS {
        let t = track(m, i);
        m.set_i32(t + 0x28, 0x32);
        m.set_i32(t + 0x38, 0x19);
        m.set_i32(t + 0x3c, 0x4b);
        m.set_i32(t + 0x2c, 7);
        m.set_i32(t + 0x30, 7);
        m.set_i32(t + 0x34, 3);
    }
    m.set_u16(B + 0xe88, m.u16(B + 0x58c));
    targets::formants(m, rec28);
    targets::sources(m, s);
    targets::frication(m, rec28);

    let v = m.i16(s + 0x5e).wrapping_add(3) as i32;
    for o in [0x7c4, 0x784, 0x704, 0x674, 0x634, 0x5e4, 0x964, 0x924] {
        s!(m, o, v);
    }
    s!(m, 0x8e4, m.i16(s + 0x7e) as i32 + 3);
    s!(m, 0x804, m.i16(s + 0x80) as i32 + 3);
    let v = m.i16(s + 0x82) as i32 + 3;
    s!(m, 0x854, v);
    s!(m, 0x744, v);
    for i in 0..NTRACKS {
        let t = track(m, i);
        contour(m, t);
    }

    let n = m.u16(NFR);
    {
        let (mut a, mut b, mut c) = (m.u32(B + 0x8b4), m.u32(B + 0x7d4), m.u32(B + 0x714));
        let mut k: u16 = 0;
        while n > k {
            let amp = |m: &Mem, p: u32| {
                let v = m.i16(p);
                m.u8(TAB_AMP.wrapping_add(if v > 0 { v as u32 } else { 0 })) as i16
            };
            let v = amp(m, a);
            m.set_i16(a, v);
            let v = amp(m, b) - 10;
            m.set_i16(b, v);
            let v = amp(m, c);
            m.set_i16(c, v);
            a += 2;
            b += 2;
            c += 2;
            k += 1;
        }
    }
    aspiration_tail(m);

    let e70 = m.u32(C_FEAT);
    let e64 = m.u32(P_FEAT);
    if e70 & 0x40000 != 0 && e70 & 0x8000000 != 0 {
        let d: i16 =
            if e64 & 0x8000000 != 0 && e64 & 0x800000 != 0 && m.i16(s + 0x2f2) != 2 { 5 } else { 0x3c };
        let (mut p8b4, mut p7d4, mut p6d4, mut p5b4, mut p604) =
            (m.u32(B + 0x8b4), m.u32(B + 0x7d4), m.u32(B + 0x6d4), m.u32(B + 0x5b4), m.u32(B + 0x604));
        let mut k: u16 = 0;
        while n > k {
            add16(m, p8b4, -(d as i32));
            m.set_i16(p7d4, 0);
            m.set_i16(p6d4, if m.i16(s + 0x52) == 1 { 0xfa } else { 0x78 });
            add16(m, p5b4, 0x28);
            add16(m, p604, 0xfa);
            p8b4 += 2;
            p7d4 += 2;
            p6d4 += 2;
            p5b4 += 2;
            p604 += 2;
            k += 1;
        }
    }

    let nasal = e70 & 0x8000 != 0;
    let mut flags: u32 = if nasal { 0x10 } else { 0 };
    // Per-frame read pointers into the track buffers.
    for (dst, src) in [
        (0x574, 0x694),
        (0x57c, 0x6d4),
        (0x580, 0x754),
        (0x588, 0x794),
        (0x568, 0x5b4),
        (0x56c, 0x604),
        (0x570, 0x644),
        (0x59c, 0x8f4),
        (0x5a0, 0x934),
        (0x598, 0x8b4),
        (0x584, 0x7d4),
        (0x578, 0x714),
        (0x590, 0x824),
        (0x594, 0x874),
        (0x864, 0xa14),
        (0x680, 0x9c4),
        (0x5a4, 0x974),
    ] {
        m.set_u32(B + dst, m.u32(B + src));
    }

    let e7e = m.u8(C_CODE);
    // Loop-carried registers and stack slots.
    let (mut f1, mut f2, mut f3) = (0i32, 0i32, 0i32); // [esp+0x18], ecx, ebx
    let (mut b1, mut b3) = (0i32, 0i32); // edi, [esp+0x24]
    let mut k: u16 = 0;
    while n > k {
        let mut cmd = m.u32(rec28);
        if cmd != 0 && m.i16(cmd) != 0x1e {
            loop {
                if m.i16(cmd + 4) as i32 == k as i32 {
                    let arg = m.i16(cmd + 2);
                    match m.i16(cmd) {
                        0xbe => m.set_i16(s + 0x44, arg),
                        0x32 => voice_preset(m, s, arg),
                        0xc8 => m.set_i16(s + 0x52, arg),
                        0xdc => m.set_i16(s + 0x2f2, arg),
                        0xe6 => m.set_i16(s + 0x8a, arg),
                        0xf0 => m.set_i16(s + 0x4c, arg),
                        0x140 => m.set_i16(s + 0x5c, arg),
                        0x14a => m.set_i16(s + 0x5e, arg),
                        0x154 => m.set_i16(s + 0x7e, arg),
                        0x15e => m.set_i16(s + 0x80, arg),
                        0x168 => m.set_i16(s + 0x82, arg),
                        0x172 => m.set_i16(s + 0x84, arg),
                        0x17c => m.set_i16(s + 0x86, arg),
                        0x186 => m.set_i16(s + 0x88, arg),
                        0x1f4 => m.set_i16(s + 0x92, arg),
                        0x1fe => m.set_i16(s + 0x94, arg),
                        0x208 => m.set_i16(s + 0x96, arg),
                        0x226 => m.set_i16(s + 0x8c, arg),
                        0x230 => m.set_i16(s + 0x8e, arg),
                        0x23a => m.set_i16(s + 0x90, arg),
                        0x334 => {
                            flags |= 0x20;
                            st.w12 = arg;
                        }
                        0x352 => {
                            flags |= 8;
                            st.b11 = arg as u8;
                        }
                        _ => {}
                    }
                }
                cmd += 6;
                if m.i16(cmd) == 0x1e {
                    break;
                }
            }
        }

        let p598 = m.u32(B + 0x598);
        let p584 = m.u32(B + 0x584);
        let p578 = m.u32(B + 0x578);
        let p59c = m.u32(B + 0x59c);
        let mut voice: i16 = m.i16(m.u32(B + 0x864)) >> 8; // [esp+0x14]
        if !nasal {
            f1 = m.i16(m.u32(B + 0x57c)) as i32;
            f2 = m.i16(m.u32(B + 0x580)) as i32;
            f3 = m.i16(m.u32(B + 0x588)) as i32;
            b1 = m.i16(m.u32(B + 0x568)) as i32;
            st.s28 = m.i16(m.u32(B + 0x56c)) as i32;
            b3 = m.i16(m.u32(B + 0x570)) as i32;
        } else {
            let fixed = match e7e {
                0x3c | 0x57 => Some((0x4a1, 0x898, 0x14a)),
                0x3d | 0x58 => Some((0x640, 0x8fc, 0x109)),
                0x3e => Some((0x6d6, 0x8ca, 0xfa)),
                _ => None,
            };
            if let Some((a, b, c)) = fixed {
                f2 = a;
                f3 = b;
                f1 = c;
                b3 = 0x3c;
                b1 = 500;
            }
        }
        let mut b2 = st.s28;

        let a2f2 = m.i16(s + 0x2f2);
        let max_into_584 = |m: &mut Mem, d: i32| {
            let x = m.i16(p598) as i32 - d;
            let y = m.i16(p584) as i32;
            m.set_i16(p584, if x > y { x } else { y } as i16);
        };
        if a2f2 == 1 {
            if m.i16(s + 0x52) == 0 {
                b1 += 0x3c;
            }
            max_into_584(m, 7);
            let ax = m.i16(p598);
            if ax > 0x14 {
                m.set_i16(p598, ax.wrapping_add(4));
            }
            voice = voice.wrapping_sub(4);
        } else if a2f2 == 2 {
            max_into_584(m, 3);
            b1 = 200;
            m.set_i16(p598, 0);
        } else if !nasal {
            max_into_584(m, 0x14);
        } else {
            m.set_i16(p584, 0);
        }
        if nasal {
            add16(m, p584, -7);
        }

        let scale = m.i16(s + 0x5c) as i32 + 10; // ebp
        let a52 = m.i16(s + 0x52);
        if a52 == 1 {
            voice = voice.wrapping_sub(5);
            add16(m, p598, -10);
            add16(m, p584, -0x14);
            add16(m, p578, -6);
            add16(m, p59c, 0x96);
        } else if a52 == 2 {
            voice = voice.wrapping_sub(1);
            add16(m, p598, -0xd);
            let f2_0 = f2;
            f3 = f3.wrapping_add(0x429);
            add16(m, p584, -0x16);
            let f1_0 = f1;
            add16(m, p578, -7);
            f1 = (f1.wrapping_sub(0x1c2).wrapping_mul(scale).wrapping_mul(0x91)) / 1000 + 0x2e4;
            f2 = (f2.wrapping_sub(0x5aa).wrapping_mul(scale).wrapping_mul(0x91)) / 1000 + 0x834;
            if f3.wrapping_sub(f2) < 0x15e {
                f3 = f2 + 0x15e;
            }
            b1 = f1.wrapping_mul(b1) / f1_0 + 0x96;
            b2 = f2.wrapping_mul(b2) / f2_0 + 0x32;
            if b1 >= 300 {
                b1 = 300;
            }
            if b1 <= 100 {
                b1 = 100;
            }
            add16(m, p59c, 0xfa);
        } else {
            let f2_0 = f2;
            let f1_0 = f1;
            let f3_0 = f3;
            let (x1, x2, x3) = (f1.wrapping_sub(0x1c2), f2.wrapping_sub(0x5aa), f3.wrapping_sub(0x9a1));
            if a52 == 3 {
                f1 = (x1.wrapping_mul(scale).wrapping_mul(0x5c)) / 1000 + 400;
                f2 = (x2.wrapping_mul(scale).wrapping_mul(0x5c)) / 1000 + 0x564;
                f3 = (x3.wrapping_mul(scale).wrapping_mul(0x5c)) / 1000 + 0x92e;
                if f3.wrapping_sub(f2) < 0xfa {
                    f3 = f2 + 0xfa;
                }
                add16(m, p59c, -100);
            } else {
                f1 = (x1.wrapping_mul(scale).wrapping_mul(100)) / 1000 + 0x1c2;
                f2 = (x2.wrapping_mul(scale).wrapping_mul(100)) / 1000 + 0x5aa;
                f3 = (x3.wrapping_mul(scale).wrapping_mul(100)) / 1000 + 0x9a1;
            }
            b1 = f1.wrapping_mul(b1) / f1_0;
            b2 = f2.wrapping_mul(b2) / f2_0;
            b3 = f3.wrapping_mul(b3) / f3_0;
            if b1 >= 300 {
                b1 = 300;
            }
            if b1 <= 0x28 {
                b1 = 0x28;
            }
            let mut d = m.i16(s + 0x46) as i32 - 0x6e;
            if d <= 0 {
                d = 0;
            }
            d /= 0xe;
            if d >= 0x14 {
                d = 0x14;
            }
            add16(m, p598, -d);
            add16(m, p584, -0xd);
            add16(m, p578, -2);
            f1 = f1.wrapping_mul(0x22) / 0x21;
        }

        add16(m, p598, m.i16(s + 0x84) as i32);
        add16(m, p584, m.i16(s + 0x86) as i32);
        add16(m, p578, m.i16(s + 0x88) as i32);
        let clampf = |v: i32| if v <= 100 { 100 } else if v >= 0xff0 { 0xff0 } else { v };
        f1 = clampf((m.i16(s + 0x92) as i32).wrapping_mul(f1) / 100);
        f2 = clampf((m.i16(s + 0x94) as i32).wrapping_mul(f2) / 100);
        f3 = clampf((m.i16(s + 0x96) as i32).wrapping_mul(f3) / 100);
        let clampb = |v: i32| if v <= 0x28 { 0x28 } else if v >= 500 { 500 } else { v };
        b1 = clampb((m.i16(s + 0x8c) as i32).wrapping_mul(b1) / 100);
        b2 = clampb((m.i16(s + 0x8e) as i32).wrapping_mul(b2) / 100);
        b3 = clampb((m.i16(s + 0x90) as i32).wrapping_mul(b3) / 100);
        let smooth = |cur: i32, target: i16| cur.wrapping_add(((target as i32).wrapping_sub(cur)).wrapping_mul(5000) >> 16);
        st.s3c = smooth(st.s3c, m.i16(s + 0x98));
        st.s40 = smooth(st.s40, m.i16(s + 0x9c));
        st.s44 = smooth(st.s44, m.i16(s + 0x9a));
        st.s48 = smooth(st.s48, m.i16(s + 0x9e));
        voice = voice.wrapping_add(m.i16(s + 0x8a));
        if voice >= 0xf {
            voice = 0xf;
        }
        if voice <= 0 {
            voice = 0;
        }
        let mut s38 = m.i16(p59c) as i32;
        let mut s30 = m.i16(m.u32(B + 0x5a0)) as i32;
        if m.i16(s + 0x48) == 8000 {
            let k11 = |v: i32| v.wrapping_mul(11) >> 3;
            f1 = k11(f1);
            b1 = k11(b1);
            f2 = k11(f2);
            b2 = k11(b2);
            f3 = k11(f3);
            b3 = k11(b3);
            st.s3c = k11(st.s3c);
            st.s44 = k11(st.s44);
            st.s40 = k11(st.s40);
            st.s48 = k11(st.s48);
            s38 = k11(s38);
            s30 = k11(s30);
        }
        st.s28 = b2;

        let tab30 = m.u32(rec30 + 4);
        let entry = (e7e as u32 * 0x1a).wrapping_add(tab30);
        let late = e70 & 0xc0100000 != 0 && (n >> 1) < k;
        let mut src = m.u8(entry + if late { 0x31 } else { 0x17 });
        m.set_u8(SOURCE, src);
        if src == 0 {
            src = m.u8(SOURCE_PREV);
            m.set_u8(SOURCE, src);
        }
        let fr = m.u32(OUT);
        m.set_u8(fr + 0x1a, src);
        m.set_u8(fr, m.u8(TAB_FREQ + q(f1, 8, 16)));
        m.set_u8(fr + 1, m.u8(TAB_FREQ + q(f2, 8, 16)));
        m.set_u8(fr + 2, m.u8(TAB_FREQ + q(f3, 8, 16)));
        m.set_u8(fr + 3, m.u8(TAB_GAIN + q(st.s3c, 0x10, 32)));
        m.set_u8(fr + 4, m.u8(TAB_GAIN + q(st.s40, 0x10, 32)));
        m.set_u8(fr + 5, 0);
        let hi = m.u8(TAB_BW + q(b1, 4, 8)) << 4;
        m.set_u8(fr + 6, hi.wrapping_add(m.u8(TAB_BW + q(b2, 4, 8))));
        let hi = m.u8(TAB_BW + q(b3, 4, 8)) << 4;
        m.set_u8(fr + 7, hi.wrapping_add(voice as u8));
        let hi = m.u8(TAB_TILT + q(st.s44, 4, 8)) << 4;
        m.set_u8(fr + 8, hi.wrapping_add(m.u8(TAB_TILT + q(st.s48, 4, 8))));
        m.set_u8(fr + 9, m.u8(TAB_GAIN + q(s38, 0x10, 32)));
        m.set_u8(fr + 0xb, e7e);
        let mut ax = m.u16(s + 0x44) >> 1;
        if ax <= 1 {
            ax = 1;
        }
        m.set_u8(fr + 0xa, ax as u8);
        let clamp_av = |v: i32| if v >= 0x80 { 0x80 } else if v <= 0 { 0 } else { v };
        m.set_u8(fr + 0x10, clamp_av(m.i16(p598) as i32 * 2) as u8);
        m.set_u8(fr + 0x11, clamp_av(m.i16(p584) as i32 * 2) as u8);
        m.set_u8(fr + 0x12, clamp_av(m.i16(p578) as i32 * 2) as u8);
        let v = m.i16(m.u32(B + 0x590)) as i32 * 2 + 0x5c;
        m.set_u8(fr + 0x13, if v <= 0 { 0 } else { v as u8 });
        m.set_u8(fr + 0x14, m.u8(TAB_TILT + q(s30, 4, 8)) << 4);
        m.set_u8(fr + 0x1b, st.b11);
        m.set_i16(fr + 0x1c, st.w12);
        m.set_u8(fr + 0x17, flags as u8);
        m.set_u8(fr + 0x1f, counter);
        counter = counter.wrapping_add(1);
        match m.u16(s + 0x4c) {
            2 => m.set_u16(fr + 0x18, m.u16(s + 0x46)),
            4 => {}
            _ => m.set_u16(fr + 0x18, 0),
        }
        m.set_u32(OUT, fr + 0x20);
        flags &= !0x28;
        for o in [0x57c, 0x580, 0x588, 0x568, 0x56c, 0x570, 0x59c, 0x5a0, 0x864, 0x594, 0x598, 0x584, 0x578, 0x590, 0x574] {
            m.set_u32(B + o, m.u32(B + o).wrapping_add(2));
        }
        k += 1;
    }

    m.set_u16(m.u32(s + 0xf6) + 0x18, m.u16(s + 0x46));
    let span = m.u16(NFR) as u32 * 0x20;
    let out = m.u32(OUT);
    f0::accents(m, s, out.wrapping_sub(span), rec28);
    match m.u16(s + 0x4c) {
        3 => f0::sung(m, s, out.wrapping_sub(m.u16(NFR) as u32 * 0x20), rec28),
        4 => f0::held(m, s, out, rec28),
        _ => {}
    }
    let rf = m.u32(rec28 + 0x16);
    let mut cl: u8 = if rf & 0x100 != 0 { 3 } else { 1 };
    if rf & 0x80 != 0 {
        cl |= 4;
    }
    let first = m.u32(OUT).wrapping_sub(m.u16(NFR) as u32 * 0x20);
    m.set_u8(first + 0x17, m.u8(first + 0x17) | cl);
    m.set_u32(s + 0xfa, m.u32(OUT));
    m.set_u16(s + 0xa0, m.u8(TAB_GAIN + q(m.i16(s + 0x98) as i32, 0x10, 32)) as u16);
    m.set_u16(s + 0xa4, m.u8(TAB_GAIN + q(m.i16(s + 0x9c) as i32, 0x10, 32)) as u16);
    m.set_u16(s + 0xa2, m.u8(TAB_TILT + q(m.i16(s + 0x9a) as i32, 4, 8)) as u16);
    m.set_u16(s + 0xa6, m.u8(TAB_TILT + q(m.i16(s + 0x9e) as i32, 4, 8)) as u16);
    m.set_local("frames_en", st);
}

/// Command 0x32 inside a phoneme: load a voice preset into S.
fn voice_preset(m: &mut Mem, s: u32, arg: i16) {
    let p = (PRESETS as i32 + arg as i32 * 0x4a) as u32;
    if m.i16(s + 0x4c) != 3 {
        m.set_u16(s + 0x4c, m.u16(p + 0x12));
        m.set_u16(s + 0x44, m.u16(p + 8));
    }
    for (so, po) in [
        (0x52, 0xa),
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
        m.set_u16(s + so, m.u16(p + po));
    }
}

/// The first call of a phrase: set up the tracks and their buffers.
fn first_call(m: &mut Mem, s: u32, rec28: u32, st: &mut Carry) {
    for (i, t) in [
        0x690u32, 0x6d0, 0x750, 0x790, 0x5b0, 0x600, 0x640, 0x8b0, 0x710, 0x7d0, 0x820, 0x8f0, 0x930, 0xa10, 0x870,
        0x970, 0x9c0,
    ]
    .into_iter()
    .enumerate()
    {
        m.set_u32(TRACKS + 4 * i as u32, B + t);
    }
    // Track buffers (0x400 bytes each), and the frame read pointers.
    for (buf, a, b) in [
        (0x1c250ef0u32, 0x574u32, 0x694u32),
        (0x1c2512f0, 0x57c, 0x6d4),
        (0x1c2516f0, 0x580, 0x754),
        (0x1c251af0, 0x588, 0x794),
        (0x1c251ef0, 0x568, 0x5b4),
        (0x1c2522f0, 0x56c, 0x604),
        (0x1c2526f0, 0x570, 0x644),
        (0x1c252af0, 0x598, 0x8b4),
        (0x1c252ef0, 0x578, 0x714),
        (0x1c2532f0, 0x584, 0x7d4),
        (0x1c2536f0, 0x590, 0x824),
        (0x1c253af0, 0x59c, 0x8f4),
        (0x1c253ef0, 0x5a0, 0x934),
        (0x1c2542f0, 0x864, 0xa14),
        (0x1c2546f0, 0x594, 0x874),
        (0x1c254af0, 0x5a4, 0x974),
    ] {
        m.set_u32(B + a, buf);
        m.set_u32(B + b, buf);
    }
    m.set_u16(B + 0xe50, 0);
    m.set_u16(B + 0xe6a, 0);
    m.set_u32(B + 0x680, 0x1c254ef0);
    m.set_u32(B + 0x9c4, 0x1c254ef0);
    s!(m, 0x148, 0);
    m.set_u32(0x1c2552f4, 0);
    s!(m, 0xe84, 0x6e);
    s!(m, 0xe80, 0x6e);
    s!(m, 0xa00, 0x6e);
    s!(m, 0xee0, 0);
    s!(m, 0x698, 100);
    s!(m, 0x878, 0);
    s!(m, 0x6d8, 400);
    s!(m, 0x5b8, 100);
    s!(m, 0xa18, 0xf);
    s!(m, 0x758, 0x578);
    s!(m, 0x608, 100);
    s!(m, 0x938, 400);
    for o in [0x8b8, 0x7d8, 0x718, 0x828, 0x978, 0x9c8] {
        s!(m, o, 0);
    }
    s!(m, 0x798, 0x960);
    s!(m, 0x648, 200);
    s!(m, 0x8f8, 3000);
    st.s3c = m.i16(s + 0x98) as i32;
    st.s40 = m.i16(s + 0x9c) as i32;
    st.s44 = m.i16(s + 0x9a) as i32;
    st.s48 = m.i16(s + 0x9e) as i32;
    let out = m.u32(OUT);
    m.set_u16(out + 0x18, m.u16(s + 0x46));
    let f0 = m.u16(out + 0x18);
    m.set_u16(B + 0x560, f0);
    let idx = (m.u16(rec28 + 0xe) as i32 + 4) >> 3;
    m.set_u16((out as i32 + idx * 0x20 + 0x18) as u32, f0);
    for i in 0..NTRACKS {
        let t = track(m, i);
        let v = m.u32(t + 8);
        for o in [0x14, 0x10, 0xc, 0x24, 0x20, 0x1c, 0x18] {
            m.set_u32(t + o, v);
        }
        m.set_u32(t, m.u32(0x1c24c158 + 4 * i));
    }
    m.set_u8(SOURCE, 1);
    m.set_u32(FIRST, 0);
}
