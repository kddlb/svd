//! Syllable arrays and the F0 contour: `cc10` (allocation), `c8c0` (stress,
//! accents, pitch marks, sentence type) and `cdc0` (F0 targets per
//! intonational phrase).
//!
//! Eight parallel per-syllable byte arrays hang off S (pointers advance
//! phrase by phrase inside `cdc0` and are rewound at the end):
//!   S+0xc4 start F0, S+0xc8 peak F0, S+0xcc end F0, S+0xd0 rise,
//!   S+0xd4 fall, S+0xd8 pitch-level marks, S+0xdc stress/accent,
//!   S+0xe0 sentence type.  F0 values are in 2 Hz units (0x37 = 110 Hz).
//! Counters: S+0xbe syllables, S+0xe4 phrase number, S+0xe6 accents in the
//! phrase, S+0xe8 syllables in the phrase, S+0xec/0xee first/last accent,
//! S+0xf0 syllable-based top-line term, S+0xf2 phrase start record.

use crate::mem::Mem;

use super::parse::REC;
use super::records::features;

const C4: u32 = 0xc4;
const C8: u32 = 0xc8;
const CC: u32 = 0xcc;
const D0: u32 = 0xd0;
const D4: u32 = 0xd4;
const D8: u32 = 0xd8;
const DC: u32 = 0xdc;
const E0: u32 = 0xe0;

fn arr(m: &Mem, s: u32, which: u32) -> u32 {
    m.u32(s + which)
}

/// `p + k` for a pointer and a signed offset.
fn off(p: u32, k: i32) -> u32 {
    (p as i32).wrapping_add(k) as u32
}

fn b(m: &Mem, p: u32) -> u8 {
    m.u8(p)
}

fn set(m: &mut Mem, p: u32, v: u8) {
    m.set_u8(p, v);
}

fn or(m: &mut Mem, p: u32, v: u8) {
    m.set_u8(p, m.u8(p) | v);
}

/// C's `(char)(x / 100)` for an int `x`.
fn div100(x: i32) -> u8 {
    (x / 100) as u8
}

/// `cc10`: count syllables (records flagged 0x80) and allocate the eight
/// arrays, each `n + 3` bytes with 0xff at index n.  Returns 0 or -2.
pub fn alloc_syllables(m: &mut Mem, s: u32) -> i32 {
    let recs = m.u32(s + 0x1c);
    let mut n: i16 = 0;
    let mut rec = recs + 5 * REC;
    let mut code = m.i16(recs + 0x8e);
    while code != 0xff {
        if m.u32(rec + 0x16) & 0x80 != 0 {
            n += 1;
        }
        code = m.i16(rec + 0x26);
        rec += REC;
    }
    let k = (n as u16).wrapping_add(3) as u32;
    let block = m.alloc((k * 8) as usize);
    m.set_u32(s + 0xc0, block);
    m.set_u16(s + 0xbe, n as u16);
    let a1 = k + 2 + block;
    m.set_u32(s + C4, block + 2);
    m.set_u32(s + C8, a1);
    m.set_u32(s + CC, a1 + k);
    let mut a = a1 + 2 * k;
    m.set_u32(s + D0, a);
    a += k;
    m.set_u32(s + D4, a);
    a += k;
    m.set_u32(s + D8, a);
    a += k;
    m.set_u32(s + E0, a);
    m.set_u32(s + DC, a + k);
    for which in [C4, C8, CC, D0, D4, D8, E0, DC] {
        let p = arr(m, s, which);
        set(m, p + k - 3, 0xff);
    }
    m.set_u16(s + 0xe8, 0);
    m.set_u16(s + 0xe4, 0);
    m.set_u16(s + 0xf0, 0);
    m.set_u32(s + 0xf2, recs + 4 * REC);
    0
}

/// `c8c0`: fill the stress, pitch-mark and sentence-type arrays.
pub fn mark_syllables(m: &mut Mem, s: u32) {
    stress_c900(m, s);
    pitch_marks_c9b0(m, s);
    let n = m.u16(s + 0xbe) as u32;
    let e0 = arr(m, s, E0);
    for i in 0..n {
        or(m, e0 + i, 1);
    }
    sentence_type_caf0(m, s);
    accents_cb60(m, s);
}

/// Code of the record `count - 4` (the sentence-final punctuation).
fn final_code(m: &Mem, s: u32) -> i16 {
    let at = (m.u16(s + 0xe) as u32 * REC).wrapping_sub(0x5c).wrapping_add(m.u32(s + 0x1c));
    m.i16(at)
}

fn stress_c900(m: &mut Mem, s: u32) {
    let mut p = arr(m, s, DC);
    let mut rec = m.u32(s + 0x1c);
    let mut code = m.i16(rec + 0xc);
    while code != 0xff {
        let mut st = m.u16(rec + 0x10);
        let mut fl = m.u32(rec + 0x16);
        let mut next = rec + REC;
        if (features(m, rec) >> 24) & 4 == 0 {
            if fl & 0x80 != 0 {
                if fl & 0x20 != 0 {
                    let mut v = st as u8;
                    while st & 0xf == 0 {
                        st = m.u16(next + 0x10);
                        fl = m.u32(next + 0x16);
                        next += REC;
                        v = st as u8;
                    }
                    let mut v = (((v & 0xf) as u32 * 0xd) / 9) as u8;
                    if fl & 0x40 != 0 {
                        v = v.wrapping_add(2);
                    }
                    if v > 4 {
                        or(m, p, 0x20);
                    }
                    or(m, p, v);
                }
                p += 1;
            }
        } else {
            let prev = b(m, p - 1);
            set(m, p - 1, prev | 0x80);
            if (features(m, rec) >> 16) & 8 != 0 {
                set(m, p - 1, prev | 0xc0);
            }
        }
        rec = next;
        code = m.i16(rec + 0xc);
    }
}

fn pitch_marks_c9b0(m: &mut Mem, s: u32) {
    let mut marks = arr(m, s, D8).wrapping_sub(1);
    let mut stress = arr(m, s, DC).wrapping_sub(1);
    let mut in_paren = false;
    let mut rec = m.u32(s + 0x1c);
    let mut code = m.i16(rec + 0xc);
    while code != 0xff {
        let fl = m.u32(rec + 0x16);
        or(m, stress, if in_paren { 0x10 } else { 0 });
        if fl & 0x80 != 0 {
            marks += 1;
            stress += 1;
        }
        if code == 4 {
            or(m, marks, 0x90);
        }
        if fl & 0x800 == 0 {
            if fl & 0x1000 != 0 {
                in_paren = false;
                or(m, marks, 0xe);
            }
        } else {
            in_paren = true;
            or(m, marks, 2);
        }
        code = m.i16(rec + 0x26);
        rec += REC;
    }

    let mut pending: u8 = 0;
    let mut last_accent: u32 = 0;
    let mut n = m.u16(s + 0xbe) as u32;
    let mut st = arr(m, s, DC);
    let mut open = false;
    let mut p = arr(m, s, D8);
    while n != 0 {
        n -= 1;
        let v = b(m, p);
        let a = b(m, st);
        st += 1;
        if v & 0xf == 2 {
            set(m, p, b(m, p) & 0xf0);
            open = true;
            pending = 2;
        }
        if a & 0x20 != 0 {
            last_accent = p;
            if open {
                or(m, p, pending);
                pending = 0;
            }
        }
        if v & 0xf == 0xe {
            set(m, p, b(m, p) & 0xf0);
            pending = 0;
            open = false;
            if last_accent != 0 {
                or(m, last_accent, 0xe);
            }
            last_accent = 0;
        }
        p += 1;
    }
}

fn sentence_type_caf0(m: &mut Mem, s: u32) {
    let kind: u8 = match final_code(m, s) {
        1 => 4,
        2 => 8,
        _ => 0,
    };
    let mut n = m.u16(s + 0xbe) as u32;
    let mut p = arr(m, s, E0).wrapping_add(n).wrapping_sub(1);
    let mut st = arr(m, s, DC).wrapping_add(n).wrapping_sub(1);
    or(m, p, kind);
    loop {
        n = n.wrapping_sub(1);
        if n == 0 {
            break;
        }
        st = st.wrapping_sub(1);
        if b(m, st) & 0x80 != 0 {
            break;
        }
        or(m, p - 1, kind);
        p -= 1;
    }
}

fn accents_cb60(m: &mut Mem, s: u32) {
    let mut n = m.u16(s + 0xbe) as u32;
    let mut mark: u32 = 0;
    let mut st = arr(m, s, DC);
    let mut p = arr(m, s, D8);
    let kind = b(m, arr(m, s, E0).wrapping_sub(1).wrapping_add(n)) & 0xc;
    let fc = final_code(m, s);
    if fc == 4 {
        let q = st.wrapping_add(n).wrapping_sub(1);
        or(m, q, 0x40);
    }
    while n != 0 {
        n -= 1;
        if b(m, st) & 0x20 != 0 {
            mark = p;
        }
        if b(m, st) & 0x40 != 0 {
            or(m, p, 0xb0);
            if mark != 0 {
                set(m, mark, (b(m, mark) & 0xf4) | 4);
                mark = 0;
            }
        }
        st += 1;
        p += 1;
    }
    if kind != 0 {
        set(m, p - 1, b(m, p - 1) & 0xf);
    }
    if kind == 4 {
        or(m, p - 1, 0x80);
    }
    if fc == 1 {
        set(m, p - 1, 0);
    }
}

/// `cdc0`: F0 targets for each intonational phrase.
pub fn f0_contour(m: &mut Mem, s: u32) {
    let mut more = next_phrase_ceb0(m, s);
    while more {
        if m.i16(s + 0xe6) != 0 {
            top_line_cfb0(m, s);
            declination_d010(m, s);
            rise_fall_d200(m, s);
            accent_shapes_d370(m, s);
        }
        marks_d6e0(m, s);
        interpolate_d780(m, s);
        segmental_dc80(m, s);
        let mut rec = m.u32(s + 0xf2);
        let mut code = m.i16(rec + 0xc);
        while code != 0xff && (features(m, rec) >> 16) & 8 == 0 {
            code = m.i16(rec + 0x26);
            rec += REC;
        }
        m.set_u32(s + 0xf2, rec + REC);
        more = next_phrase_ceb0(m, s);
    }
    let n = m.u16(s + 0xbe) as u32;
    for which in [C4, C8, CC, D0, D4, DC, D8, E0] {
        m.set_u32(s + which, arr(m, s, which).wrapping_sub(n));
    }
}

/// `ceb0`: advance the arrays to the next phrase and measure it.
fn next_phrase_ceb0(m: &mut Mem, s: u32) -> bool {
    let k = m.u16(s + 0xe8) as u32;
    for which in [C4, C8, CC, DC, D8, E0, D0, D4] {
        m.set_u32(s + which, arr(m, s, which).wrapping_add(k));
    }
    m.set_u16(s + 0xe8, 0);
    m.set_u16(s + 0xe6, 0);
    m.set_u16(s + 0xec, 0);
    m.set_u16(s + 0xe4, m.u16(s + 0xe4).wrapping_add(1));
    m.set_u16(s + 0xee, 0);
    m.set_u16(s + 0xf0, 0);
    let mut p = arr(m, s, DC);
    if b(m, p) == 0xff {
        return false;
    }
    let mut first = true;
    loop {
        let v = b(m, p);
        p += 1;
        if v & 0x80 != 0 {
            m.set_u16(s + 0xf0, m.u16(s + 0xf0).wrapping_add(1));
        }
        if v & 0x20 != 0 {
            m.set_u16(s + 0xe6, m.u16(s + 0xe6).wrapping_add(1));
            if first {
                first = false;
                m.set_u16(s + 0xec, m.u16(s + 0xe8));
            }
            m.set_u16(s + 0xee, m.u16(s + 0xe8));
        }
        m.set_u16(s + 0xe8, m.u16(s + 0xe8).wrapping_add(1));
        if v & 0x40 != 0 {
            break;
        }
    }
    m.set_u16(s + 0xf0, ((m.u16(s + 0xf0) as u32 + 4) / 3) as u16);
    true
}

fn top_line_cfb0(m: &mut Mem, s: u32) {
    let f0 = m.u16(s + 0xf0) as u32;
    let e4 = m.u16(s + 0xe4) as u32;
    let mut v = f0.wrapping_mul(6u32.wrapping_sub(e4)).wrapping_add(e4.wrapping_mul((-4i32) as u32)).wrapping_add(0x3d) as i32;
    if v < 0x3f {
        v = 0x3e;
    }
    if v > 0x47 {
        v = 0x48;
    }
    let at = arr(m, s, C8) + m.u16(s + 0xec) as u32;
    set(m, at, v as u8);
}

fn declination_d010(m: &mut Mem, s: u32) {
    let accents = m.u16(s + 0xe6) as u32;
    let e8 = m.u16(s + 0xe8) as i32;
    let ec = m.u16(s + 0xec) as u32;
    let base: i32 = if b(m, off(arr(m, s, E0), e8 - 1)) & 0xc == 8 { 0x3f } else { 0x37 };
    if accents > 1 {
        let mut p8 = arr(m, s, C8) + ec;
        let top = b(m, p8) as u32;
        let mut acc = (top * 4) as i32;
        p8 += 1;
        let mut step = ((top.wrapping_sub(base as u32)).wrapping_mul(4) as i32) / accents as i32;
        let mut k = accents as i32 - 1;
        let mut p5 = arr(m, s, DC) + 1 + ec;
        if k < 1 || k > 2 {
            k = (step * 0x73 + 0x32) / 100;
            step += ((step * -0x1e - 0x32) / 100) / (accents as i32 - 3);
            let mut v = b(m, p5);
            loop {
                p5 += 1;
                if v & 0x20 != 0 {
                    break;
                }
                p8 += 1;
                v = b(m, p5);
            }
            acc -= k;
            let mut left = accents as i32 - 4;
            set(m, p8, (acc >> 2) as u8);
            loop {
                p8 += 1;
                if left == 0 {
                    break;
                }
                let v = b(m, p5);
                p5 += 1;
                if v & 0x20 != 0 {
                    acc -= step;
                    left -= 1;
                    set(m, p8, (acc >> 2) as u8);
                }
            }
            let mut v = b(m, p5);
            while v & 0x20 == 0 {
                p5 += 1;
                p8 += 1;
                v = b(m, p5);
            }
            acc -= k;
            set(m, p8, (acc >> 2) as u8);
            let last = arr(m, s, C8) + m.u16(s + 0xee) as u32;
            set(m, last, ((acc - step) >> 2) as u8);
        } else {
            while k != 0 {
                if b(m, p5) & 0x20 != 0 {
                    acc -= step;
                    k -= 1;
                    set(m, p8, (acc >> 2) as u8);
                }
                p8 += 1;
                p5 += 1;
            }
        }
    }
    let mut n = accents;
    let mut p5 = arr(m, s, C8) + ec;
    let mut p8 = arr(m, s, DC) + ec;
    while n != 0 {
        let a = b(m, p8);
        if a & 0x20 != 0 {
            let v = b(m, p5) as u32;
            let t = (v.wrapping_sub(base as u32).wrapping_mul(5).wrapping_add(0x19).wrapping_mul(2)) as i32 / 100;
            let mut x = t.wrapping_mul((a & 0xf) as i32 - 8).wrapping_add(v as i32);
            if x < 0x1a {
                x = 0x19;
            }
            if x > 199 {
                x = 200;
            }
            n -= 1;
            set(m, p5, x as u8);
        }
        p5 += 1;
        p8 += 1;
    }
}

fn rise_fall_d200(m: &mut Mem, s: u32) {
    let ec = m.u16(s + 0xec) as u32;
    let mut n = m.u16(s + 0xe6) as u32;
    let mut peak = arr(m, s, C8) + ec;
    let mut rise = arr(m, s, D0) + ec;
    let mut fall = arr(m, s, D4) + ec;
    let mut st = arr(m, s, DC) + ec;
    let mut marks = arr(m, s, D8) + ec;
    while n != 0 {
        if b(m, st) & 0x20 != 0 {
            let pk = b(m, peak) as i32;
            let mut lvl = (b(m, marks) & 0xf) as u32;
            if b(m, marks) & 0xf > 6 {
                lvl = lvl.wrapping_sub(0x10);
            }
            let k = (lvl.wrapping_mul(0x14).wrapping_add(0x32) as i32) / 100 + 1;
            set(m, rise, (k.wrapping_mul(pk - 0x37).wrapping_mul(0x28).wrapping_add(0x32) / 100) as u8);
            let mut f = (1u32.wrapping_sub(lvl).wrapping_mul((pk - 0x37) as u32).wrapping_mul(0x14).wrapping_add((-0x32i32) as u32) as i32) / 100;
            if f < 1 {
                f = 0;
            }
            set(m, fall, f as u8);
            if b(m, st) & 0x10 != 0 && lvl == 0 {
                let r = b(m, rise);
                set(m, rise, r.wrapping_add(div100((r as u32).wrapping_mul((-0x1ei32) as u32).wrapping_add((-0x32i32) as u32) as i32)));
                let f = b(m, fall);
                set(m, fall, f.wrapping_add(div100((f as u32).wrapping_mul((-0x1ei32) as u32).wrapping_add((-0x32i32) as u32) as i32)));
            }
            n -= 1;
        }
        st += 1;
        rise += 1;
        fall += 1;
        peak += 1;
        marks += 1;
    }
    let v = b(m, arr(m, s, C8) + ec).wrapping_sub(0x37);
    set(m, arr(m, s, D0) + ec, v);
}

fn accent_shapes_d370(m: &mut Mem, s: u32) {
    // (The original also checks the year here; it can never trigger.)
    if m.u16(s + 0xe6) >= 2 {
        let ec = m.u16(s + 0xec) as u32;
        let mut p8 = arr(m, s, C8) + ec;
        let mut p9 = arr(m, s, D0) + ec;
        let mut l20 = arr(m, s, D4) + ec;
        let mut gap: i32 = 0;
        let mut left = m.u16(s + 0xe6) as i32 - 1;
        let mut p11 = p8;
        let mut p3 = p9;
        let mut p4 = l20;
        let mut p5 = arr(m, s, DC) + 1 + ec;
        while left != 0 {
            l20 += 1;
            p8 += 1;
            p9 += 1;
            if b(m, p5) & 0x20 == 0 {
                gap += 1;
                p5 += 1;
                continue;
            }
            let (a, k14, k10) = match gap {
                0 => (-0x28, -0x14, 0x14),
                1 => (0, 0, 0),
                2 => (0xf, 10, -0xf),
                3 => (0x19, 0xf, -0x19),
                _ => (0x1e, 0xf, -0x19),
            };
            let pct = |v: u8, k: i32| div100((v as u32).wrapping_mul(k as u32).wrapping_add(0x32) as i32);
            let v3 = b(m, p3);
            set(m, p3, pct(v3, a).wrapping_add(v3));
            let v9 = b(m, p9);
            set(m, p9, v9.wrapping_add(pct(v9, a)));
            let v11 = b(m, p11);
            set(m, p11, div100((v11 as i32 - 0x37) * k14 + 0x32).wrapping_add(v11));
            let v8 = b(m, p8);
            let nv = div100((v8 as i32 - 0x37) * k10 + 0x32).wrapping_add(v8);
            set(m, p8, nv);
            if gap > 2 && b(m, p5) & 0x10 == 0 {
                set(m, p9, nv.wrapping_sub(0x34));
            }
            if gap == 0 {
                let t = (b(m, p9) as u32)
                    .wrapping_add((b(m, p11) as u32).wrapping_sub(b(m, p8) as u32).wrapping_sub(b(m, p4) as u32))
                    as i32;
                let c = t as u8;
                if t < 1 {
                    set(m, p9, b(m, p9).wrapping_sub(c));
                } else {
                    set(m, p4, c.wrapping_add(b(m, p4)));
                }
                if b(m, p5 - 2) & 0x20 != 0 {
                    let x = b(m, p3);
                    set(m, p3, b(m, p4));
                    set(m, p4, x);
                }
            }
            gap = 0;
            p11 = p8;
            p3 = p9;
            p4 = l20;
            p5 += 1;
            left -= 1;
        }
    }

    let n = m.u16(s + 0xe6) as u32;
    if n != 0 {
        let ec = m.u16(s + 0xec) as u32;
        let mut k = n;
        let mut p = arr(m, s, C8) + ec;
        let mut st = arr(m, s, DC) + ec;
        let mut top: u32 = 0;
        loop {
            if b(m, st) & 0x20 != 0 {
                top = top.max(b(m, p) as u32);
                k -= 1;
            }
            p += 1;
            st += 1;
            if k == 0 {
                break;
            }
        }
        let ee = m.u16(s + 0xee) as u32;
        let mut kind_p = arr(m, s, E0) + ee;
        let mut st = arr(m, s, DC) + ee;
        let mut peak = arr(m, s, C8) + ee;
        let mut rise = arr(m, s, D0) + ee;
        let mut fall = arr(m, s, D4) + ee;
        let mut kind = b(m, kind_p) & 0xc;
        while kind != 0 {
            if b(m, st) & 0x20 != 0 {
                if kind == 8 {
                    let c = (((b(m, fall) as u32) * 0x50 + 0x32) / 100) as u8;
                    set(m, rise, b(m, rise).wrapping_add(c));
                    set(m, fall, b(m, fall).wrapping_sub(c));
                }
                if b(m, st) & 0x80 != 0 {
                    let gender = m.i16(s + 0x52);
                    let c = if gender == 1 || gender == 2 { b'*' } else { b'%' };
                    if kind == 4 {
                        set(m, fall, b(m, peak).wrapping_sub(c));
                    } else {
                        set(m, fall, b(m, peak).wrapping_add(div100(top.wrapping_mul((-0x78i32) as u32).wrapping_add((-0x32i32) as u32) as i32)));
                    }
                }
            }
            fall -= 1;
            kind_p -= 1;
            rise -= 1;
            st -= 1;
            peak -= 1;
            kind = b(m, kind_p) & 0xc;
        }
    }
}

fn marks_d6e0(m: &mut Mem, s: u32) {
    let mut marks = arr(m, s, D8);
    let mut n = m.u16(s + 0xe8) as u32;
    let mut st = arr(m, s, DC);
    let mut seen = false;
    let mut fall = arr(m, s, D4);
    while n != 0 {
        n -= 1;
        if b(m, st) & 0x20 != 0 {
            seen = true;
        }
        if b(m, marks) & 0xf0 != 0 && seen {
            let v = b(m, fall);
            let x = if b(m, marks) & 0x80 == 0 {
                (v as u32).wrapping_mul((-0x50i32) as u32).wrapping_add((-0x32i32) as u32) as i32
            } else {
                (v as u32 * 0x1e + 0x32) as i32
            };
            set(m, fall, v.wrapping_add(div100(x)));
        }
        if b(m, st) & 0x80 != 0 {
            seen = false;
        }
        st += 1;
        fall += 1;
        marks += 1;
    }
}

fn interpolate_d780(m: &mut Mem, s: u32) {
    let mut st = arr(m, s, DC);
    let mut start = arr(m, s, C4);
    let lead = if m.i16(s + 0xe6) == 0 { m.u16(s + 0xe8) } else { m.u16(s + 0xec) };
    let mut end = arr(m, s, CC);
    let mut peak = arr(m, s, C8);
    for _ in 0..lead {
        set(m, start, 0x37);
        start += 1;
        let v = b(m, st);
        st += 1;
        set(m, peak, (v & 0xf).wrapping_mul(2).wrapping_add(b'7'));
        set(m, end, 0x37);
        end += 1;
        peak += 1;
    }

    let ec = m.u16(s + 0xec) as u32;
    let mut l14 = arr(m, s, DC) + ec;
    let mut l18 = arr(m, s, C4) + ec;
    let mut l10 = arr(m, s, C8) + ec;
    let mut lc = arr(m, s, CC) + ec;
    let mut l4 = arr(m, s, D0) + ec;
    let mut l1c = arr(m, s, D4) + ec;
    let mut left = m.u16(s + 0xe6) as i32 - 1;
    set(m, l18, b(m, l10).wrapping_sub(b(m, l4)));
    set(m, lc, b(m, l10).wrapping_sub(b(m, l1c)));
    if left < 1 {
        left = 0;
    }
    let mut gap: i32 = 0;
    let mut p8 = l14;
    let mut p17 = l18;
    let mut p9 = l10;
    let mut p16 = lc;
    while left != 0 {
        l4 += 1;
        lc += 1;
        l10 += 1;
        l14 += 1;
        l18 += 1;
        l1c += 1;
        if b(m, l14) & 0x20 == 0 {
            gap += 1;
            continue;
        }
        set(m, l18, b(m, l10).wrapping_sub(b(m, l4)));
        set(m, lc, b(m, l10).wrapping_sub(b(m, l1c)));
        if gap != 0 {
            let d = b(m, p16) as i32 - b(m, l18) as i32;
            let mut l24 = d;
            if d < 0 {
                l24 = 0;
                let c = (d / 2) as u8;
                set(m, p16, b(m, p16).wrapping_sub(c));
                set(m, l18, b(m, l18).wrapping_add(c));
            }
            if b(m, l14) & 0x10 == 0 {
                if gap == 1 {
                    let v = b(m, p16);
                    set(m, p17 + 1, v);
                    set(m, p9 + 1, v.wrapping_sub((l24 / 2) as u8));
                    set(m, p16 + 1, b(m, p17 + 1).wrapping_sub(l24 as u8));
                } else if gap == 2 {
                    let v = b(m, p16);
                    set(m, p17 + 1, v);
                    set(m, p9 + 1, v.wrapping_add(div100(l24 * -0x1e - 0x32)));
                    let v = div100(l24 * -0x3c - 0x32).wrapping_add(b(m, p17 + 1));
                    set(m, p16 + 1, v);
                    set(m, p17 + 2, v);
                    set(m, p9 + 2, v.wrapping_add(div100(l24 * -0x14 - 0x32)));
                    set(m, p16 + 2, b(m, p17 + 2).wrapping_add(div100(l24 * -0x28 - 0x32)));
                } else {
                    let v = b(m, p16);
                    let d = v as i32 - 0x34;
                    set(m, p17 + 1, v);
                    set(m, p9 + 1, v.wrapping_add(div100(d * -0x16 - 0x32)));
                    let v = div100(d * -0x2d - 0x32).wrapping_add(b(m, p17 + 1));
                    set(m, p16 + 1, v);
                    set(m, p17 + 2, v);
                    set(m, p9 + 2, v.wrapping_add(div100(d * -0x12 - 0x32)));
                    let v = div100(d * -0x23 - 0x32).wrapping_add(b(m, p17 + 2));
                    set(m, p16 + 2, v);
                    set(m, p17 + 3, v);
                    p17 += 3;
                    p9 += 3;
                    p16 += 3;
                    set(m, p9, v.wrapping_add(div100((-5 - d) * 10)));
                    p8 += 3;
                    set(m, p16, b(m, p17).wrapping_add(div100(d * -0x14 - 0x32)));
                    let mut k = gap - 4;
                    if gap != 3 {
                        loop {
                            let v = b(m, p16);
                            p17 += 1;
                            p9 += 1;
                            set(m, p17, v);
                            set(m, p16 + 1, v);
                            let nb = p8 + 1;
                            p16 += 1;
                            p8 += 1;
                            set(m, p9, v.wrapping_add((b(m, nb) & 0xf).wrapping_mul(2)));
                            let more = k != 0;
                            k -= 1;
                            if !more {
                                break;
                            }
                        }
                    }
                }
            } else {
                l24 /= gap;
                loop {
                    gap -= 1;
                    let v = b(m, p16);
                    p17 += 1;
                    p9 += 1;
                    p16 += 1;
                    set(m, p17, v);
                    set(m, p9, v.wrapping_sub((l24 / 2) as u8));
                    set(m, p16, b(m, p17).wrapping_sub(l24 as u8));
                    if gap == 0 {
                        break;
                    }
                }
            }
        }
        gap = 0;
        left -= 1;
        p8 = l14;
        p17 = l18;
        p9 = l10;
        p16 = lc;
    }

    let n = m.u16(s + 0xe8) as u32;
    if b(m, off(arr(m, s, DC), n as i32 - 1)) & 0x20 == 0 {
        let ee = m.u16(s + 0xee) as u32;
        let mut k = n;
        if m.i16(s + 0xe6) != 0 {
            k = n.wrapping_sub(ee).wrapping_sub(1);
        }
        let mut start = arr(m, s, C4) + ee;
        let mut peak = arr(m, s, C8) + ee;
        let mut end = ee + arr(m, s, CC);
        let kind = b(m, off(arr(m, s, E0), n as i32 - 1)) & 0xc;
        let mut slope = if kind == 4 { b(m, end) as i32 - 0x25 } else { b(m, end) as i32 - 0x37 };
        slope /= k as i32;
        while k != 0 {
            let v = b(m, end);
            start += 1;
            end += 1;
            peak += 1;
            set(m, start, v);
            let v = v.wrapping_sub(slope as u8);
            set(m, end, v);
            set(m, peak, v.wrapping_add(2));
            k -= 1;
        }
        if kind == 8 {
            let mut p = arr(m, s, C8);
            let mut top: u32 = 0;
            for _ in 0..n {
                top = top.max(b(m, p) as u32);
                p += 1;
            }
            let at = off(arr(m, s, CC), m.u16(s + 0xe8) as i32 - 1);
            set(m, at, ((top * 0x78 + 0x32) / 100) as u8);
        }
    }
}

fn segmental_dc80(m: &mut Mem, s: u32) {
    let mut rec = m.u32(s + 0xf2);
    let mut st = arr(m, s, DC);
    let mut start = arr(m, s, C4);
    let mut peak = arr(m, s, C8);
    let mut n = m.u16(s + 0xe8) as u32;
    let mut end = arr(m, s, CC);
    while n != 0 {
        n -= 1;
        if m.u8(rec + 0x16) & 0x80 == 0 {
            loop {
                let q = rec;
                rec = q + REC;
                if m.u32(q + 0x30) & 0x80 != 0 {
                    break;
                }
            }
        }
        let f = features(m, rec);
        let voiced_cons = f & 2 != 0 && f & 0x800_0000 != 0;
        let unvoiced_cons = f & 2 != 0 && f & 0x800_0000 == 0;
        let base;
        let x;
        if b(m, st) & 0x20 == 0 {
            base = b(m, end);
            x = (((b(m, peak) as u32).wrapping_sub(base as u32)).wrapping_mul(5).wrapping_add(5).wrapping_mul(10)) as i32;
        } else {
            if unvoiced_cons {
                let v = b(m, peak);
                set(m, peak, v.wrapping_add(div100((v as u32 * 0x14).wrapping_sub(0x41a) as i32)));
            }
            let mut k: u32 = if voiced_cons { 0x14 } else { 0 };
            if unvoiced_cons {
                k = 0x50;
            }
            let pv = b(m, peak) as u32;
            let sv = b(m, start);
            set(m, start, sv.wrapping_add(div100((pv.wrapping_sub(sv as u32)).wrapping_mul(k).wrapping_add(0x32) as i32)));
            let mut any_unvoiced = false;
            let mut all_voiced = true;
            let mut stop = b(m, st + 1) & 0x20;
            let mut q = rec;
            while stop == 0 {
                let lang = m.u32(q + 0x22);
                let code = m.i16(q + 0x26) as i32;
                let f = m.u32(m.u32(lang + 0x1c).wrapping_add((code * 4) as u32));
                any_unvoiced = any_unvoiced || (f & 2 != 0 && f & 0x800_0000 == 0);
                all_voiced = all_voiced && f & 2 != 0 && f & 0x800_0000 != 0;
                stop = m.u8(q + 0x30) & 0x88;
                q += REC;
            }
            let k: u32 = if any_unvoiced {
                0x42
            } else if all_voiced {
                0x14
            } else {
                0x32
            };
            base = b(m, end);
            x = ((b(m, peak) as u32).wrapping_sub(base as u32)).wrapping_mul(k).wrapping_add(0x32) as i32;
        }
        st += 1;
        start += 1;
        peak += 1;
        set(m, end, base.wrapping_add(div100(x)));
        end += 1;
    }
}
