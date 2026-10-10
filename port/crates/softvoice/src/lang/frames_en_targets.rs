//! Per-phoneme targets of the English generator's tracks: TIENG32
//! `FUN_1c201b80` (formants), `FUN_1c203770` (transition timing of the
//! formants), `FUN_1c2030b0` (voicing/aspiration sources) and
//! `FUN_1c249310` (frication).  Ported from the disassembly (the Ghidra
//! output reorders some of the assignments).

use super::*;

/// Byte tables in TIENG32's `.data`.
const TAB_BOUNDARY: u32 = 0x1c24c3f0; // [old class * 4 + new class]
const TAB_TIMING: u32 = 0x1c24c420; // {code, start, end} x 0x15
const TAB_ASPIR: u32 = 0x1c24c400; // {code, frames} x 0xf
const TAB_PCT: u32 = 0x1c24c460; // [(class * 10 + class) * 10 + k]
const TAB_LEVEL: u32 = 0x1c2065be;
const TAB_LEVEL2: u32 = 0x1c2065c8;

#[inline]
fn entry(m: &Mem, rec: u32, code: u8) -> u32 {
    (code as u32 * 0x1a).wrapping_add(m.u32(rec + 4))
}

#[inline]
fn ph(m: &Mem, e: u32, off: u32) -> i32 {
    m.i16(e + off) as i32
}

/// `x0 + (x1 - x0) * pct / 100` for one of the interpolated track fields.
#[inline]
fn lerp(m: &mut Mem, dst: u32, x0: u32, x1: u32, pct: u32) {
    let a = g!(m, x0);
    let v = a.wrapping_add((g!(m, x1).wrapping_sub(a)).wrapping_mul(g!(m, pct)) / 100);
    s!(m, dst, v);
}

/// `FUN_1c201b80`: formant targets (F1..F3 and bandwidths) of the phoneme,
/// looking at the next phonemes for coarticulation.  `rec` is S+0x28.
pub(super) fn formants(m: &mut Mem, rec: u32) {
    for t in [0x6d0, 0x5b0, 0x750, 0x600, 0x790, 0x640] {
        shift(m, B + t);
    }
    let n = m.u8(N_CODE);
    let n2 = m.u8(N2_CODE);
    let e70 = m.u32(C_FEAT);
    let e64 = m.u32(P_FEAT);
    let fc = m.u32(N_FEAT);
    let e5c = m.u32(N2_FEAT);
    let e7e = m.u8(C_CODE);
    let tab = m.u32(rec + 4);

    let e = entry(m, rec, if n != 0x4b && n != 0x4c { n } else { n2 });
    s!(m, 0x6e8, ph(m, e, 6));
    s!(m, 0x5c8, ph(m, e, 0xc));
    s!(m, 0x768, ph(m, e, 8));
    s!(m, 0x618, ph(m, e, 0xe));
    s!(m, 0x7a8, ph(m, e, 10));
    s!(m, 0x658, ph(m, e, 0x10));
    if fc & 0x10 != 0 {
        s!(m, 0x6ec, ph(m, e, 0x20));
        s!(m, 0x5cc, ph(m, e, 0x26));
        s!(m, 0x76c, ph(m, e, 0x22));
        s!(m, 0x61c, ph(m, e, 0x28));
        s!(m, 0x7ac, ph(m, e, 0x24));
        s!(m, 0x65c, ph(m, e, 0x2a));
    } else {
        s!(m, 0x6ec, g!(m, 0x6e8));
        s!(m, 0x5cc, g!(m, 0x5c8));
        s!(m, 0x76c, g!(m, 0x768));
        s!(m, 0x61c, g!(m, 0x618));
        s!(m, 0x7ac, g!(m, 0x7a8));
        s!(m, 0x65c, g!(m, 0x658));
    }
    if n == 0x4b || n == 0x4c {
        let v = ph(m, e, 0xc) + 200;
        s!(m, 0x5cc, v);
        s!(m, 0x5c8, v);
        let mut v = ph(m, e, 0xe) + 0x28;
        if v <= 200 {
            v = 200;
        }
        s!(m, 0x61c, v);
        s!(m, 0x618, v);
        let mut v = ph(m, e, 0x10) + 0x3c;
        if v <= 300 {
            v = 300;
        }
        s!(m, 0x65c, v);
        s!(m, 0x658, v);
        if e70 & 0x20000000 == 0 {
            s!(m, 0x6e8, (g!(m, 0x6ec).wrapping_add(g!(m, 0x6dc))) >> 1);
            s!(m, 0x768, (g!(m, 0x75c).wrapping_add(g!(m, 0x76c))) >> 1);
            s!(m, 0x7a8, (g!(m, 0x7ac).wrapping_add(g!(m, 0x79c))) >> 1);
        }
    }
    if fc & 0x20000000 != 0 {
        s!(m, 0x6e8, g!(m, 0x6dc));
        s!(m, 0x5c8, g!(m, 0x5bc));
        s!(m, 0x768, g!(m, 0x75c));
        s!(m, 0x618, g!(m, 0x60c));
        s!(m, 0x7a8, g!(m, 0x79c));
        s!(m, 0x658, g!(m, 0x64c));
    }
    if e70 & 0x20000000 != 0 {
        s!(m, 0x6dc, g!(m, 0x6e8));
        s!(m, 0x5bc, g!(m, 0x5cc));
        s!(m, 0x75c, g!(m, 0x768));
        s!(m, 0x60c, g!(m, 0x61c));
        s!(m, 0x79c, g!(m, 0x7a8));
        s!(m, 0x64c, g!(m, 0x65c));
    }
    let e2 = entry(m, rec, n2);
    if fc & 0x10000000 != 0 {
        if n == 0x1c && e64 & 0x800000 != 0 && e64 & 0x8000 == 0 {
            let v = (g!(m, 0x768).wrapping_add(g!(m, 0x760))) >> 1;
            s!(m, 0x76c, v);
            s!(m, 0x768, v);
        }
        if fc & 0x80 != 0 && fc & 0x1000 != 0 && e5c & 0x4000000 != 0 {
            s!(m, 0x76c, g!(m, 0x768));
        }
        if fc & 0x40000080 != 0 && e5c & 0x800 != 0 {
            s!(m, 0x76c, g!(m, 0x76c).wrapping_sub(300));
        }
        if fc & 0x40000000 != 0 && e5c & 2 != 0 {
            s!(m, 0x76c, g!(m, 0x76c).wrapping_sub(0x96));
        }
        if fc & 0x400000 != 0 {
            let v = (ph(m, e2, 10).wrapping_add(g!(m, 0x7a8)).wrapping_add(g!(m, 0x798))) / 3;
            s!(m, 0x7a8, v);
            s!(m, 0x7ac, v);
        }
    } else if fc & 0x40 != 0 && fc & 0x10000 != 0 && e5c & 0x10000000 != 0 && e5c & 0x200000 != 0 {
        s!(m, 0x768, g!(m, 0x768).wrapping_sub(0x32));
        s!(m, 0x7a8, g!(m, 0x7a8).wrapping_sub(200));
        s!(m, 0x76c, g!(m, 0x768));
        s!(m, 0x7ac, g!(m, 0x7a8));
    }
    let set23 = |m: &mut Mem, f2: i32, f3: i32| {
        s!(m, 0x76c, f2);
        s!(m, 0x768, f2);
        s!(m, 0x7ac, f3);
        s!(m, 0x7a8, f3);
    };
    if fc & 2 != 0 && e70 & 0x180000 != 0 {
        set23(m, 0x73a, 0x898);
    }
    if fc & 0x4000000 != 0 && e70 & 0x180000 != 0 {
        set23(m, 0x6a4, 0x76c);
    }
    if fc & 0x4000000 != 0 && e70 & 0x80000000 != 0 {
        set23(m, 900, 0x9c4);
    }
    if n == 0x37 {
        if e5c & 0x800000 != 0 && e5c & 0x8000 == 0 {
            let v = (ph(m, e2, 8).wrapping_add(g!(m, 0x768).wrapping_mul(9))) / 10;
            s!(m, 0x76c, v);
            s!(m, 0x768, v);
        }
        if e5c & 0x800000 == 0 || e5c & 0x8000 != 0 {
            let v = (g!(m, 0x768).wrapping_mul(9).wrapping_add(0x91)) / 10;
            s!(m, 0x76c, v);
            s!(m, 0x768, v);
        }
    }
    if n == 0x36 {
        s!(m, 0x768, (ph(m, e2, 8).wrapping_add(g!(m, 0x768).wrapping_mul(3))).wrapping_mul(25) / 100);
        s!(m, 0x76c, (ph(m, e2, 8).wrapping_add(g!(m, 0x768).wrapping_mul(2))) / 3);
        s!(m, 0x7a8, g!(m, 0x768).wrapping_add(0xfa));
        s!(m, 0x7ac, (ph(m, e2, 10).wrapping_add(g!(m, 0x7a8).wrapping_mul(2))) / 3);
    }
    if fc & 0x800 != 0 && n2 == 0x29 {
        s!(m, 0x6ec, g!(m, 0x6ec).wrapping_sub(0x50));
    }
    if n == 0x3f {
        let v = (ph(m, e2, 6).wrapping_add(g!(m, 0x6d8).wrapping_mul(2)).wrapping_add(g!(m, 0x6e8))) >> 2;
        s!(m, 0x6ec, v);
        s!(m, 0x6e8, v);
        let v = (ph(m, e2, 8).wrapping_add(g!(m, 0x768)).wrapping_add(g!(m, 0x758))) / 3;
        s!(m, 0x76c, v);
        s!(m, 0x768, v);
        let v = (ph(m, e2, 10).wrapping_add(g!(m, 0x7a8)).wrapping_add(g!(m, 0x798))) / 3;
        s!(m, 0x7ac, v);
        s!(m, 0x7a8, v);
    }
    if n == 0x40 {
        let v = (ph(m, e2, 6).wrapping_add(g!(m, 0x6dc))) >> 1;
        s!(m, 0x6ec, v);
        s!(m, 0x6e8, v);
        let v = (ph(m, e2, 8).wrapping_add(g!(m, 0x75c))) >> 1;
        s!(m, 0x76c, v);
        s!(m, 0x768, v);
        let v = (ph(m, e2, 10).wrapping_add(g!(m, 0x79c))) >> 1;
        s!(m, 0x7ac, v);
        s!(m, 0x7a8, v);
    }
    if n == 0x3e && e70 & 0x40000080 != 0 {
        s!(m, 0x6e8, g!(m, 0x6e8).wrapping_sub(100));
        s!(m, 0x768, g!(m, 0x768).wrapping_add(0x28a));
        s!(m, 0x6ec, g!(m, 0x6e8));
        s!(m, 0x76c, g!(m, 0x768));
        s!(m, 0x7a8, g!(m, 0x7a8).wrapping_add(0x2ee));
        s!(m, 0x7ac, g!(m, 0x7a8));
    }
    if e70 & 8 != 0 && n == 0x36 {
        s!(m, 0x6ec, g!(m, 0x6e8));
        s!(m, 0x76c, g!(m, 0x768));
        s!(m, 0x7ac, g!(m, 0x7a8));
        s!(m, 0x6e8, ph(m, tab, 0x276));
        s!(m, 0x768, ph(m, tab, 0x278));
        s!(m, 0x7a8, ph(m, tab, 0x27a));
        s!(m, 0x5c8, ph(m, tab, 0x27c));
        s!(m, 0x618, ph(m, tab, 0x27e));
        s!(m, 0x658, ph(m, tab, 0x280));
    }
    if n == 0x29 && e5c & 0x800 != 0 {
        for (o, po) in [(0x6ec, 0x312), (0x76c, 0x314), (0x7ac, 0x316), (0x5cc, 0x318), (0x61c, 0x31a), (0x65c, 0x31c)] {
            s!(m, o, (ph(m, tab, po).wrapping_add(g!(m, o))) >> 1);
        }
    }
    if g!(m, 0x7a8).wrapping_sub(g!(m, 0x768)) < 0xfa {
        s!(m, 0x768, g!(m, 0x7a8).wrapping_sub(0xfa));
    }
    if g!(m, 0x7ac).wrapping_sub(g!(m, 0x76c)) < 0xfa {
        s!(m, 0x76c, g!(m, 0x7ac).wrapping_sub(0xfa));
    }
    if g!(m, 0x768).wrapping_sub(g!(m, 0x6e8)) < 200 {
        s!(m, 0x6e8, g!(m, 0x768).wrapping_sub(200));
    }
    if g!(m, 0x76c).wrapping_sub(g!(m, 0x6ec)) < 200 {
        s!(m, 0x6ec, g!(m, 0x76c).wrapping_sub(200));
    }
    timing(m);

    let s10 = fc & 0x10002000;
    if s10 != 0 {
        if e5c & 0x8000 != 0 {
            s!(m, 0x5cc, g!(m, 0x5cc).wrapping_add(100));
            s!(m, 0x61c, g!(m, 0x61c).wrapping_add(0x32));
            s!(m, 0x65c, g!(m, 0x65c).wrapping_add(0x32));
            s!(m, 0x6ec, (g!(m, 0x6ec).wrapping_mul(2).wrapping_add(500)) / 3);
        }
        if e70 & 0x8000 != 0 {
            s!(m, 0x5c8, g!(m, 0x5c8).wrapping_add(100));
            s!(m, 0x618, g!(m, 0x618).wrapping_add(0x32));
            s!(m, 0x658, g!(m, 0x658).wrapping_add(0x32));
            s!(m, 0x6e8, (g!(m, 0x6e8).wrapping_mul(2).wrapping_add(500)) / 3);
        }
    }

    // Boundary percentages from the classes of the previous and next phoneme.
    let old = m.i16(B + 0x55a);
    m.set_i16(B + 0x562, old);
    let ebx = fc & 0x10000000;
    let new: i16 = if ebx != 0 {
        0
    } else if fc & 0x1000000 != 0 {
        1
    } else if fc & 0x40 != 0 {
        2
    } else {
        3
    };
    m.set_i16(B + 0x55a, new);
    const SIX: [u32; 6] = [0x7b8, 0x778, 0x6f8, 0x668, 0x628, 0x5d8];
    let set6 = |m: &mut Mem, v: i32| {
        for o in SIX {
            s!(m, o, v);
        }
    };
    let v = m.u8((TAB_BOUNDARY as i32 + old as i32 * 4 + new as i32) as u32) as i32;
    set6(m, v);
    if e7e == 0x37 {
        set6(m, 0x14);
    }
    let edi = e70 & 0x800000;
    if edi != 0 && fc & 0x40 != 0 {
        s!(m, 0x5d8, 0x5a);
        s!(m, 0x6f8, 0x5a);
    } else if e70 & 0x40 != 0 && fc & 0x800000 != 0 {
        s!(m, 0x5d8, 10);
        s!(m, 0x6f8, 10);
    }
    if e70 & 0x1000000 != 0 && fc & 0x800000 != 0 {
        s!(m, 0x6f8, if e70 & 0x4000000 != 0 { 0x14 } else { 0x28 });
        s!(m, 0x628, 0x46);
        s!(m, 0x5d8, 0x46);
    } else if edi != 0 && fc & 0x1000000 != 0 {
        s!(m, 0x6f8, 0x3c);
        s!(m, 0x628, 0x1e);
        s!(m, 0x5d8, 0x1e);
    } else if fc & 0x20000000 != 0 {
        s!(m, 0x7b8, 0);
        s!(m, 0x778, 0);
        s!(m, 0x6f8, 0);
        s!(m, 0x668, 0x32);
        s!(m, 0x628, 0x32);
        s!(m, 0x5d8, 0x32);
    }
    if e70 & 0x20000000 != 0 {
        s!(m, 0x7b8, 100);
        s!(m, 0x778, 100);
        s!(m, 0x6f8, 100);
    }
    let esi = e70 & 0x10000000;
    if esi != 0 && fc & 0x4000000 != 0 {
        s!(m, 0x778, 0x50);
    } else if e70 & 0x4000000 != 0 && ebx != 0 {
        s!(m, 0x778, 0x1e);
    }
    if edi != 0 && fc & 0x800 != 0 {
        set6(m, 0x5a);
    }
    let ecx = e70 & 0x80000;
    let set4 = |m: &mut Mem, v: i32| {
        for o in [0x7b8, 0x778, 0x668, 0x628] {
            s!(m, o, v);
        }
    };
    if ecx != 0 && fc & 0x8000 != 0 {
        set4(m, 10);
    } else if e70 & 0x8000 != 0 && fc & 0x80000 != 0 {
        set4(m, 0x5a);
    }
    if e70 & 0xc0100000 != 0 && fc & 0x2000 != 0 {
        set6(m, 0x14);
    }
    lerp(m, 0x6f4, 0x6dc, 0x6e8, 0x6f8);
    lerp(m, 0x774, 0x75c, 0x768, 0x778);
    lerp(m, 0x7b4, 0x79c, 0x7a8, 0x7b8);
    lerp(m, 0x5d4, 0x5bc, 0x5c8, 0x5d8);
    lerp(m, 0x624, 0x60c, 0x618, 0x628);
    lerp(m, 0x664, 0x64c, 0x658, 0x668);

    let p64_2 = e64 & 2;
    if p64_2 != 0 && m.u8(P_CODE) != 0x3f && edi != 0 {
        s!(m, 0x770, 0x640);
        s!(m, 0x7b0, 0x8fc);
        if ecx == 0 {
            s!(m, 0x7b0, 0xa28);
        }
    }
    if e70 & 2 != 0 && e7e != 0x3f && fc & 0x800000 != 0 {
        s!(m, 0x7b4, 0x8fc);
        if fc & 0x80000 == 0 {
            s!(m, 0x7b4, 0xa3c);
        }
    }
    if p64_2 != 0 && e7e == 0x29 {
        s!(m, 0x770, g!(m, 0x770).wrapping_add(300));
    }
    if e70 & 0x10002000 != 0 && fc & 0x4000000 != 0 {
        s!(m, 0x5d4, g!(m, 0x5d4).wrapping_add(100));
        let v = (g!(m, 0x79c).wrapping_add(g!(m, 0x768)).wrapping_add(g!(m, 0x75c))) / 3 - 400;
        s!(m, 0x774, v);
    }
    let fc_400 = fc & 0x4000000;
    if fc_400 != 0 && e70 & 0x40000080 != 0 {
        s!(m, 0x774, g!(m, 0x774).wrapping_add(100));
    }
    let edx = e70 & 0x4000000;
    if edx != 0 && fc & 0x40000080 != 0 {
        s!(m, 0x774, g!(m, 0x774).wrapping_add(100));
    }
    if edx != 0 {
        s!(m, 0x7b4, g!(m, 0x774).wrapping_add(if fc & 0x400 != 0 { 800 } else { 400 }));
    }
    if fc_400 != 0 {
        s!(m, 0x7b4, g!(m, 0x774).wrapping_add(if e70 & 0x400 != 0 { 800 } else { 600 }));
    }
    if e70 & 0x800 != 0 && ebx != 0 {
        s!(m, 0x6f4, g!(m, 0x6f4).wrapping_sub(0x3c));
        s!(m, 0x774, g!(m, 0x774).wrapping_sub(0x32));
    } else if esi != 0 && e64 & 0x800 != 0 {
        s!(m, 0x6f0, g!(m, 0x6f0).wrapping_add(100));
        s!(m, 0x770, g!(m, 0x770).wrapping_add(100));
    }
    if e70 & 0x20000100 != 0 && e7e != 0x40 {
        s!(m, 0x6f0, g!(m, 0x6d8));
        s!(m, 0x770, g!(m, 0x758));
        s!(m, 0x7b0, g!(m, 0x798));
    }
    if edx != 0 && s10 != 0 {
        let v = match n {
            9 => Some((0x8de, 0xc1c)),
            0xb | 0x18 => Some((0x866, 0xb54)),
            0xd => Some((0x834, 0xa14)),
            0xf => Some((0x898, 0xa00)),
            0x11 => Some((2000, 0x9c4)),
            0x12 | 0x17 => Some((2000, 0x8ca)),
            0x13 => Some((0x5dc, 0x898)),
            0x15 | 0x23 | 0x33 => Some((0x5dc, 2000)),
            0x19 => Some((0x6a4, 0x802)),
            0x1f => Some((0x866, 0xa41)),
            0x21 => Some((0x7e4, 0x92e)),
            0x25 => Some((0x80c, 0x8d4)),
            0x27 => Some((0x73a, 0x834)),
            0x29 => Some((2000, 0x8fc)),
            0x2b => Some((0x898, 0xaf0)),
            0x2d => Some((0x7f8, 0x9d8)),
            0x31 => Some((0x500, 2000)),
            0x36 => Some((0x47e, 0x776)),
            0x37 | 0x56 => Some((0x410, 0x8ca)),
            _ => None,
        };
        if let Some((a, b)) = v {
            s!(m, 0x774, a);
            s!(m, 0x7b4, b);
        }
    }

    // Transition speeds.
    const SPD_A: [u32; 6] = [0x5dc, 0x6fc, 0x62c, 0x77c, 0x66c, 0x7bc];
    const SPD_B: [u32; 6] = [0x5e0, 0x700, 0x630, 0x780, 0x670, 0x7c0];
    let set = |m: &mut Mem, os: &[u32], v: i32| {
        for &o in os {
            s!(m, o, v);
        }
    };
    set(m, &SPD_A, 10);
    set(m, &SPD_B, 10);
    if edi != 0 && fc & 0x1000000 != 0 {
        set(m, &[0x5e0, 0x700], 7);
        set(m, &[0x630, 0x780, 0x670, 0x7c0], 9);
    }
    if e7e == 0x39 {
        set(m, &[0x630, 0x780, 0x670, 0x7c0], if fc & 0x1000000 != 0 { 3 } else { 5 });
    }
    if e7e == 0x36 {
        set(m, &SPD_A, 6);
        set(m, &SPD_B, 6);
    }
    let p2000 = e64 & 0x2000;
    let mut to_cfb = true;
    if p2000 != 0 && m.u8(P_CODE) != 0x36 {
        if esi == 0 {
            to_cfb = false;
        } else {
            set(m, &SPD_A, 7);
        }
    }
    if to_cfb
        && esi != 0
        && m.u8(C_STRF) != 0
        && m.u8(P2_STRF) != 0
        && p2000 != 0
        && m.u32(P2_FEAT) & 0x40000 != 0
    {
        set(m, &SPD_A, 5);
    }
    if e64 & 0x1000000 != 0 && edi != 0 {
        set(m, &[0x5dc, 0x6fc], 7);
    }
    let mut skip = false;
    if m.i16(P_CLASS) == 3 {
        if edi != 0 {
            set(m, &[0x5dc, 0x6fc], 5);
            set(m, &[0x62c, 0x77c, 0x66c, 0x7bc], 7);
            skip = true;
        }
    } else if edi != 0 && m.i16(N_CLASS) == 3 {
        set(m, &[0x5e0, 0x700], 5);
        set(m, &[0x630, 0x780, 0x670, 0x7c0], 7);
        skip = true;
    }
    if !skip && m.i16(C_CLASS) == 3 {
        set(m, &[0x5e0, 0x5dc, 0x700, 0x6fc], 2);
        set(m, &[0x630, 0x62c, 0x780, 0x77c, 0x670, 0x66c, 0x7c0, 0x7bc], 3);
    }
    if n == 0x3f {
        s!(m, 0x6f8, 0x4b);
        set(m, &[0x5e0, 0x700], 6);
    }
    if e7e == 0x3f {
        s!(m, 0x6f8, 0x19);
        set(m, &[0x700, 0x6fc], 1);
    }
    if m.u8(P_CODE) == 0x3f {
        set(m, &[0x5dc, 0x6fc], 4);
    }
    if n == 0x1d {
        set(m, &SPD_B, 0xe);
    }
    if e7e == 0x37 {
        set(m, &SPD_B, 3);
    }
    if e70 & 0x10002000 != 0 {
        if e64 & 0x1000040 != 0 {
            set(m, &[0x66c, 0x62c, 0x5dc], 5);
        }
        if fc & 0x1000040 != 0 {
            set(m, &[0x670, 0x630, 0x5e0], 5);
        }
    }
}

/// `FUN_1c203770`: start/end of the formant transitions of a phoneme with
/// feature 0x10 (from a {code, start, end} table).
fn timing(m: &mut Mem) {
    let e70 = m.u32(C_FEAT);
    if e70 & 0x10 == 0 {
        return;
    }
    let code = m.u8(C_CODE);
    let mut i: i16 = 0;
    loop {
        if m.u8((TAB_TIMING as i32 + i as i32 * 3) as u32) == code {
            break;
        }
        i += 1;
        if i >= 0x15 {
            break;
        }
    }
    let e = (TAB_TIMING as i32 + i as i32 * 3) as u32;
    let mut a = m.u8(e + 1) as i16;
    let mut b = m.u8(e + 2) as i16;
    if e70 & 0xc0000000 != 0 && m.u32(N_FEAT) & 0x2000 != 0 {
        a -= 10;
        b -= 0xf;
    }
    if a >= 0x5f {
        a = 0x5f;
    }
    if a <= 0 {
        a = 0;
    }
    let a = a as i32;
    if b >= 0x64 {
        b = 0x64;
    }
    let mut b = b as i32;
    if b <= a + 5 {
        b = a + 5;
    }
    let b = b as i16 as i32;
    for o in [0x5e8, 0x708, 0x638, 0x788, 0x678, 0x7c8] {
        s!(m, o, a);
    }
    for o in [0x5ec, 0x70c, 0x63c, 0x78c, 0x67c, 0x7cc] {
        s!(m, o, b);
    }
    if code == 0x23 {
        s!(m, 0x5e8, 0x32);
        s!(m, 0x708, 0x32);
        s!(m, 0x5ec, 0x5f);
        s!(m, 0x70c, 0x5f);
    }
}

/// `FUN_1c2030b0`: voicing and aspiration source targets.
pub(super) fn sources(m: &mut Mem, s: u32) {
    shift(m, B + 0x8b0);
    shift(m, B + 0x7d0);
    let e70 = m.u32(C_FEAT);
    let e64 = m.u32(P_FEAT);
    let fc = m.u32(N_FEAT);
    let e5c = m.u32(N2_FEAT);
    let e7e = m.u8(C_CODE);
    let n = m.u8(N_CODE);
    let c564 = m.u16(C_CLASS) as u32;
    let row1 = (m.u16(N_CLASS) as u32 + c564 * 10) * 10;
    let row2 = (c564 + m.u16(P_CLASS) as u32 * 10) * 10;
    s!(m, 0x8d8, m.u8(TAB_PCT + row1) as i32);
    s!(m, 0x8dc, m.u8(TAB_PCT + 3 + row2) as i32);
    s!(m, 0x8e0, m.u8(TAB_PCT + 6 + row1) as i32);
    if m.u8(P_CODE) == 0x3f {
        s!(m, 0x8dc, 1);
    }
    if e7e == 0x3f {
        s!(m, 0x8e0, 1);
        s!(m, 0x8dc, 1);
    }
    if n == 0x3f {
        s!(m, 0x8e0, 1);
    }
    s!(m, 0x8e8, 0);
    s!(m, 0x8ec, 0x4b);
    s!(m, 0x7f8, m.u8(TAB_PCT + 1 + row1) as i32);
    s!(m, 0x7fc, m.u8(TAB_PCT + 4 + row2) as i32);
    s!(m, 0x800, m.u8(TAB_PCT + 7 + row1) as i32);
    let ntab = m.u32(m.u32(s + 0x2c) + 4);
    s!(m, 0x8c8, m.u8(ntab.wrapping_add(n as u32 * 0x1a + 0x16)) as i32);
    if (n == 0x1c || n == 0x1b) && e70 & 0x8000000 == 0 {
        s!(m, 0x8c8, 0);
    }
    let edi = e70 & 0x10000000;
    if edi != 0 && fc & 0x8000000 != 0 && fc & 0x40 != 0 && e5c & 0x10000000 != 0 {
        s!(m, 0x8c8, g!(m, 0x8c8).wrapping_add(6));
    }
    s!(m, 0x8cc, g!(m, 0x8c8));
    if fc & 0x8000000 != 0 && e5c & 0x8000000 == 0 {
        s!(m, 0x8cc, g!(m, 0x8c8).wrapping_sub(3));
    }
    s!(m, 0x7e8, 0);
    s!(m, 0x8c8, m.u8(TAB_LEVEL.wrapping_add(g!(m, 0x8c8) as u32)) as i32);
    s!(m, 0x8cc, m.u8(TAB_LEVEL.wrapping_add(g!(m, 0x8cc) as u32)) as i32);
    if fc & 0x44 != 0 {
        let v = match n {
            0x35 => 0x2f,
            0x41 | 0x44 => 0x21,
            0x42 => 0x20,
            0x43 => 0x24,
            0x4b | 0x4c => 0x2b,
            _ => 0,
        };
        s!(m, 0x7e8, v);
    }
    let v = m.u8(TAB_LEVEL2.wrapping_add(g!(m, 0x7e8) as u32)) as i32;
    s!(m, 0x7e8, v);
    s!(m, 0x7ec, v);

    if e64 & 0x8000000 == 0 && e64 & 0x40040 != 0 && (e70 & 0x10002000 != 0 || e7e == 0x1c) {
        const E6E: u32 = B + 0xe6e;
        const E52: u32 = B + 0xe52;
        let ebx = e70 & 0x10002000;
        m.set_i16(E6E, 5);
        m.set_i16(E52, 0x2e);
        if m.u8(P_STRF) == 0 {
            m.set_i16(E6E, 2);
            m.set_i16(E52, 0x28);
        }
        if edi == 0 {
            m.set_i16(E6E, if e70 & 0x800 != 0 || e64 & 0x400 != 0 { 6 } else { 7 });
        }
        if m.u32(P2_FEAT) & 0x8000000 != 0 && m.u8(C_STRF) == 0 {
            add16(m, E6E, -1);
        }
        if e64 & 1 != 0 {
            add16(m, E6E, -3);
        }
        if e7e == 0x1c || e7e == 0x1b {
            m.set_i16(E6E, 8);
            add16(m, E52, -3);
        }
        let esi = e64 & 0x40000;
        if esi != 0 && m.u8(P2_CODE) == 0x41 && m.u8(P_FLAGS) & 0x80 == 0 {
            m.set_i16(E6E, 0);
        } else if e64 & 0x40 != 0 {
            if edi != 0 {
                m.set_i16(E6E, 1);
            } else {
                m.set_u16(E6E, m.u16(NFR) >> 1);
            }
        }
        let cx = m.i16(NFR);
        let di = m.i16(E6E);
        m.set_i16(E6E, if cx < di { cx } else { di });
        if e70 & 0x80000 != 0 && e64 & 2 != 0 {
            add16(m, E52, if e7e == 0x36 { 6 } else { 1 });
        }
        let a52 = m.i16(s + 0x52);
        if (a52 == 0 || a52 == 3) && e64 & 0x400 == 0 && ebx != 0 {
            add16(m, E6E, 2);
            if m.u8(C_STRF) != 0 || m.u8(C_FLAGS) & 4 != 0 {
                add16(m, E6E, 2);
            }
        }
        if m.i16(s + 0x4c) == 3 {
            m.set_i16(E6E, m.i16(E6E) >> 1);
        }
        let e6e = m.i16(E6E);
        if e6e > 0 {
            s!(m, 0x7d8, m.u8((TAB_LEVEL2 as i32 + m.i16(E52) as i32) as u32) as i32);
            if e64 & 0x40 != 0 {
                s!(m, 0x7d8, g!(m, 0x7e4));
            }
            s!(m, 0x7fc, 2);
            s!(m, 0x7dc, 0);
            s!(m, 0x808, 0);
            let mut v = ((e6e as i32 * 100 + 0x32) as u32) / (m.u16(NFR) as u32);
            if v >= 100 {
                v = 100;
            }
            s!(m, 0x608, g!(m, 0x608).wrapping_add(100));
            s!(m, 0x80c, v as i32);
            if esi != 0 {
                if e64 & 0x4000000 != 0 {
                    s!(m, 0x660, g!(m, 0x660).wrapping_add(0x96));
                }
                for o in [0x7fc, 0x8b8, 0x62c, 0x5dc, 0x8dc] {
                    s!(m, o, 0);
                }
                let mut c = g!(m, 0x80c).wrapping_add(-400 / (cx as i32));
                if c <= 0 {
                    c = 0;
                }
                let v = g!(m, 0x80c);
                for o in [0x638, 0x5e8, 0x8e8] {
                    s!(m, o, c);
                }
                for o in [0x63c, 0x5ec, 0x8ec] {
                    s!(m, o, v);
                }
            }
        }
    }
    lerp(m, 0x8d4, 0x8bc, 0x8c8, 0x8d8);
    lerp(m, 0x7f4, 0x7dc, 0x7e8, 0x7f8);
    for o in [0x8c8, 0x8cc, 0x8d4] {
        if g!(m, o) <= 0 {
            s!(m, o, 0);
        }
    }
    shift(m, B + 0x870);
    shift(m, B + 0xa10);
    let mut a28: i32 = 0xc;
    if fc & 0x8000000 == 0 {
        a28 = 8;
    }
    if m.u8(N_STRF) != 0 {
        a28 += 2;
    }
    if m.u8(N_FLAGS) & 4 != 0 && m.u8(N_STRF) == 0 {
        a28 -= 2;
    }
    if fc & 0x1000000 != 0 {
        a28 -= 5;
    }
    if n == 1 {
        s!(m, 0x5bc, g!(m, 0x5bc).wrapping_add(0x32));
    }
    s!(m, 0xa40, 3);
    s!(m, 0xa3c, 3);
    let v = a28 << 8;
    s!(m, 0xa28, v);
    s!(m, 0xa2c, v);
    lerp(m, 0x894, 0x87c, 0x888, 0x898);
    s!(m, 0xa38, 0x32);
    let a = g!(m, 0xa1c);
    s!(m, 0xa34, a.wrapping_add((v.wrapping_sub(a)).wrapping_mul(0x32) / 100));
}

/// `FUN_1c249310`: frication and aspiration targets.
pub(super) fn frication(m: &mut Mem, rec: u32) {
    for t in [0x8f0, 0x930, 0x710, 0x820] {
        shift(m, B + t);
    }
    let e70 = m.u32(C_FEAT);
    let e64 = m.u32(P_FEAT);
    let fc = m.u32(N_FEAT);
    let e5c = m.u32(N2_FEAT);
    let e7e = m.u8(C_CODE);
    let n = m.u8(N_CODE);
    let n2 = m.u8(N2_CODE);
    let p_code = m.u8(P_CODE);

    s!(m, 0x72c, 0);
    s!(m, 0x728, 0);
    let ecx = fc & 0x40;
    if ecx != 0 {
        let v = match n {
            0x41 => 0x30,
            0x42 => 0x3d,
            0x43 => 0x37,
            0x44 => 0x31,
            0x45 => 0x2e,
            0x46 => 0x3c,
            0x47 => 0x38,
            0x48 => 0x35,
            _ => 0,
        };
        s!(m, 0x728, v);
        if e70 & 0x10000 != 0 && fc & 0x80 == 0 {
            s!(m, 0x728, g!(m, 0x728) + 3);
        }
        if m.u8(N_STRF) == 0 {
            s!(m, 0x728, g!(m, 0x728) - 2);
            if m.u8(N_FLAGS) & 4 != 0 {
                s!(m, 0x728, g!(m, 0x728) - 2);
            }
        }
        s!(m, 0x72c, g!(m, 0x728));
    }
    s!(m, 0x748, 0);
    s!(m, 0x74c, 0x4b);
    s!(m, 0x838, -10);
    s!(m, 0x908, 3000);
    s!(m, 0x948, 400);
    s!(m, 0x728, m.u8(TAB_LEVEL.wrapping_add(g!(m, 0x728) as u32)) as i32);
    s!(m, 0x72c, m.u8(TAB_LEVEL.wrapping_add(g!(m, 0x72c) as u32)) as i32);
    let ebx = fc & 0x40040;
    if ebx != 0 || n == 0x3f {
        let esi = n2 == 0x29 || n2 == 0x38 || n2 == 0x15;
        let edx = fc & 2;
        let (bp, ax, di): (i16, i16, i16) = if edx != 0 {
            if fc & 0x40000 != 0 && n2 == 0x36 { (0xa28, 400, -18) } else { (0x1194, 500, -18) }
        } else if fc & 0x10000 != 0 {
            if esi { (0x8fc, 300, -18) } else { (0x9c4, 300, -18) }
        } else if fc & 0x4000000 != 0 {
            if e5c & 0x800000 != 0 {
                let e = entry(m, rec, n2);
                (((ph(m, e, 8) + ph(m, e, 10)) >> 1) as i16, 0xfa, -18)
            } else {
                (0x834, 0xdc, -18)
            }
        } else if fc & 8 != 0 {
            (0xe10, 1000, -6)
        } else if fc & 0x400 != 0 {
            (0xe10, 1000, -3)
        } else {
            // Uninitialised local: the slot holds the EBX that FUN_1c2030b0
            // pushed just before, i.e. FUN_1c204690's constant 0x4b.
            (0x4b, 0x4b, 0x4b)
        };
        s!(m, 0x90c, bp as i32);
        s!(m, 0x908, bp as i32);
        s!(m, 0x94c, ax as i32);
        s!(m, 0x948, ax as i32);
        s!(m, 0x83c, di as i32);
        s!(m, 0x838, di as i32);
        if edx != 0 {
            if esi {
                s!(m, 0x90c, g!(m, 0x90c) - 300);
            }
            if e70 & 0x200000 != 0 {
                s!(m, 0x908, g!(m, 0x908) - 0x96);
            }
        }
        if fc & 0x10000 != 0 {
            if e70 & 0x10002000 != 0 {
                let v = ((g!(m, 0x79c).wrapping_add(g!(m, 0x75c))) >> 1) + 100;
                s!(m, 0x908, v);
                s!(m, 0x948, v / 6);
            }
            if e5c & 0x10002000 != 0 {
                let e = entry(m, rec, n2);
                let v = ((ph(m, e, 8) + ph(m, e, 10)) >> 1) + 100;
                s!(m, 0x90c, v);
                s!(m, 0x94c, v / 6);
            }
        }
    }
    if ecx == 0 && e70 & 0x40 != 0 {
        s!(m, 0x908, g!(m, 0x8fc));
        s!(m, 0x948, g!(m, 0x93c));
        s!(m, 0x838, g!(m, 0x82c));
    }
    let edi = e70 & 0x40;
    if edi == 0 && e70 & 0x40000 == 0 {
        if e64 & 0x40 != 0 {
            s!(m, 0x8f8, g!(m, 0x904));
            s!(m, 0x938, g!(m, 0x944));
            s!(m, 0x828, g!(m, 0x834));
        }
        if ecx != 0 {
            s!(m, 0x8fc, g!(m, 0x908));
            s!(m, 0x93c, g!(m, 0x948));
            s!(m, 0x82c, g!(m, 0x838));
        }
    }
    let esi = e70 & 0x4000000;
    if esi != 0 && fc & 0x10002000 != 0 {
        s!(m, 0x8fc, g!(m, 0x774) + 0x82);
    }
    let c564 = m.u16(C_CLASS) as u32;
    let row1 = (m.u16(N_CLASS) as u32 + c564 * 10) * 10;
    let row2 = (c564 + m.u16(P_CLASS) as u32 * 10) * 10;
    s!(m, 0x738, m.u8(TAB_PCT + 2 + row1) as i32);
    for o in [0x918, 0x958, 0x848] {
        s!(m, o, 0x32);
    }
    s!(m, 0x73c, m.u8(TAB_PCT + 5 + row2) as i32);
    s!(m, 0x740, m.u8(TAB_PCT + 8 + row1) as i32);
    let v = if e64 & 0x40 != 0 { 2 } else { 5 };
    for o in [0x84c, 0x95c, 0x91c] {
        s!(m, o, v);
    }
    let v = if ecx != 0 { 2 } else { 5 };
    for o in [0x850, 0x960, 0x920] {
        s!(m, o, v);
    }
    let ecx3 = e70 & 0x40000;
    if ecx3 != 0 {
        for o in [0x848, 0x958, 0x918, 0x850, 0x960, 0x920] {
            s!(m, o, 0);
        }
    }
    if edi != 0 && e64 & 0x40000 != 0 {
        for o in [0x84c, 0x95c, 0x91c] {
            s!(m, o, 0);
        }
    }
    lerp(m, 0x734, 0x71c, 0x728, 0x738);
    lerp(m, 0x914, 0x8fc, 0x908, 0x918);
    lerp(m, 0x954, 0x93c, 0x948, 0x958);
    lerp(m, 0x844, 0x82c, 0x838, 0x848);
    const N58C: u32 = B + 0x58c;
    const L55C: u32 = B + 0x55c;
    m.set_u16(N58C, 0);
    m.set_u16(L55C, 0);
    let edx = e70 & 1;
    if !(edx != 0 || e7e == 0x3f || (ecx3 != 0 && (fc & 0x20000000 == 0 || fc & 0x8000 != 0))) {
        return;
    }
    let mut i: i16 = 0;
    loop {
        if m.u8((TAB_ASPIR as i32 + i as i32 * 2) as u32) == e7e {
            break;
        }
        i += 1;
        if i >= 0xf {
            break;
        }
    }
    m.set_u16(N58C, m.u8((TAB_ASPIR as i32 + i as i32 * 2 + 1) as u32) as u16);
    if p_code != 0x41 && e7e == 0x52 && n == 0x36 {
        add16(m, N58C, 3);
    }
    if edx != 0 && m.u8(C_STRF) != 0 && n != 0x36 {
        add16(m, N58C, 2);
    }
    if p_code == 0x41 && m.u8(P_FLAGS) & 0x80 != 0 {
        m.set_u16(N58C, 2);
    }
    let ax = m.i16(N58C);
    let di = m.i16(NFR);
    m.set_i16(N58C, if ax < di { ax } else { di });
    if ecx3 != 0 || e7e == 0x3f {
        let v = match e7e {
            0x3f => 0x2a,
            0x49 => 0x3c,
            0x4a => 0x3e,
            0x4d => 0x32,
            0x4e => 0x2c,
            0x4f => 0x3a,
            0x50 | 0x51 => 0x38,
            0x52 => {
                if p_code != 0x41 && n == 0x36 {
                    0x34
                } else {
                    0x2e
                }
            }
            0x54 | 0x55 => 0x3b,
            _ => 0,
        };
        m.set_i16(L55C, v);
    }
    let ecx4 = e70 & 0x10000;
    if ecx4 != 0 && fc & 0x80 == 0 {
        add16(m, L55C, 4);
    }
    let p8000 = e64 & 0x8000;
    if p8000 != 0 && m.u8(C_STRF) == 0 {
        add16(m, L55C, -6);
    } else if p8000 == 0 && m.u8(C_STRF) == 0 {
        add16(m, L55C, -3);
    }
    if ebx != 0 {
        add16(m, L55C, -3);
    } else if n == 0x1c {
        add16(m, L55C, -5);
    }
    if p_code == 0x41 && m.u8(P_FLAGS) & 0x80 != 0 {
        add16(m, L55C, -3);
    }
    if esi != 0 && n == 0x36 {
        add16(m, L55C, 6);
    }
    if edx != 0 {
        return;
    }
    if n == 0x40 {
        m.set_u16(L55C, 0);
    }
    if fc & 1 != 0 {
        return;
    }
    let other = if fc & 0x40000 != 0 {
        fc
    } else if n == 0x40 && e5c & 0x40000 != 0 {
        e5c
    } else {
        return;
    };
    if (e70 & 0x400 != 0 && other & 0x400 != 0)
        || (e70 & 2 != 0 && other & 2 != 0)
        || (esi != 0 && other & 0x4000000 != 0)
        || (ecx4 != 0 && other & 0x10000 != 0)
    {
        m.set_u16(L55C, 0);
    }
}
