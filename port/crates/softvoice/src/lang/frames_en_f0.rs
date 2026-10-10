//! F0 of the English generator's frames: TIENG32 `FUN_1c203ab0` (accent
//! targets for speech), `FUN_1c2042c0` (sung notes, S+0x4c == 3),
//! `FUN_1c204030` (held pitch, S+0x4c == 4) and the setters `FUN_1c204500`,
//! `FUN_1c204550`, `FUN_1c2045b0`, `FUN_1c204610`.

use super::*;

/// Note frequencies (i16), indexed by semitone.
const NOTES: u32 = 0x1c24c028;
/// Small per-phoneme pitch offsets for held pitch (i16 x 8).
const JITTER: u32 = 0x1c24c1a0;

const A00: u32 = B + 0xa00;
const E80: u32 = B + 0xe80;
const E84: u32 = B + 0xe84;
const E6A: u32 = B + 0xe6a;
const PENDING: u32 = B + 0x148;
const HOLD: u32 = 0x1c2552f4;
const F0: u32 = B + 0x560;

/// F0 value (Hz) for an accent level: levels above 0x6e are scaled by the
/// pitch range (S+0x60), then everything by the base pitch (S+0x46).
fn level(m: &Mem, s: u32, mut p: i32) -> u16 {
    if p > 0x6e {
        p = (m.u16(s + 0x60) as i32).wrapping_mul(p - 0x6e) / 100 + 0x6e;
    }
    ((m.u16(s + 0x46) as i32).wrapping_mul(p) / 0x6e) as u16
}

/// `FUN_1c204500`: F0 at the first frame.
fn at_start(m: &mut Mem, s: u32, fr: u32, p: i32) {
    let v = level(m, s, p);
    m.set_u16(fr + 0x18, v);
}

/// `FUN_1c204550`: F0 at the middle frame.
fn at_mid(m: &mut Mem, s: u32, fr: u32, p: i32) {
    let v = level(m, s, p);
    m.set_u16((m.u16(NFR) as u32 & !1).wrapping_mul(0x10).wrapping_add(0x18).wrapping_add(fr), v);
}

/// `FUN_1c2045b0`: F0 at the last frame.
fn at_end(m: &mut Mem, s: u32, fr: u32, p: i32) {
    let v = level(m, s, p);
    m.set_u16((m.u16(NFR) as u32 * 0x20).wrapping_add(fr).wrapping_sub(8), v);
}

/// `FUN_1c204610`: F0 in the middle of the next phoneme.
fn at_next(m: &mut Mem, s: u32, fr: u32, p: i32) {
    let v = level(m, s, p);
    let o = (m.u16(N_NFR) as u32 & !1) * 0x10 + m.u16(NFR) as u32 * 0x20;
    m.set_u16(o.wrapping_add(fr).wrapping_add(0x18), v);
}

/// The note of a `{f0 ...}` command with a non-positive argument (minus
/// the semitone), relative to the key (S+0xac octave, S+0xae note) and
/// folded into the table's range.
fn note(m: &Mem, s: u32, arg: i16) -> u16 {
    let mut c = m.i16(s + 0xac).wrapping_mul(12).wrapping_add(m.i16(s + 0xae)).wrapping_sub(arg);
    if c >= 0x55 {
        let q = (c.wrapping_sub(0x49) as u16) / 12;
        c = c.wrapping_sub((q.wrapping_mul(12)) as i16);
    }
    if c < 0 {
        let q = ((0xb_i16).wrapping_sub(c) as u16) / 12;
        c = c.wrapping_add((q.wrapping_mul(12)) as i16);
    }
    m.u16((NOTES as i32 + c as i32 * 2) as u32)
}

/// Store a frame's F0 word, unless it falls outside the frame buffer
/// (S+0xf6, S+0x102 bytes).  Held pitch writes into the frames after the
/// phoneme; near the end of a phrase the original runs past the buffer and
/// scribbles on heap memory that is not part of the engine's state.
fn store_f0(m: &mut Mem, s: u32, a: u32, v: u16) {
    let base = m.u32(s + 0xf6);
    if a.wrapping_sub(base) < m.u32(s + 0x102) {
        m.set_u16(a, v);
    }
}

/// Fill frames +0x18 from the command's position for the phoneme's length
/// (`fr` is the end of the phoneme's frames for held pitch).
fn fill(m: &mut Mem, s: u32, fr: u32, pos: u16, v: u16) {
    let mut dx = pos;
    let mut p = (fr as i32).wrapping_add((dx as i16 as i32) << 5) as u32;
    while m.u16(NFR) > dx {
        store_f0(m, s, p.wrapping_add(0x18), v);
        p = p.wrapping_add(0x20);
        dx = dx.wrapping_add(1);
    }
}

fn clamp_f0(a: i16) -> i16 {
    if a >= 2000 {
        2000
    } else if a <= 10 {
        10
    } else {
        a
    }
}

/// `FUN_1c203ab0`: pitch commands of the phoneme, then the accent targets
/// (from the syllable arrays at S+0xc4/0xc8/0xcc/0xd8) for speech.
pub(super) fn accents(m: &mut Mem, s: u32, fr: u32, rec: u32) {
    let mut cmd = m.u32(rec);
    if cmd != 0 {
        while m.i16(cmd) != 0x1e {
            let arg = m.i16(cmd + 2);
            match m.i16(cmd) {
                0x8c => m.set_i16(s + 0xae, arg),
                0xb4 => {
                    // Notes (arg <= 0) are computed and dropped here.
                    if arg > 0 {
                        m.set_i16(s + 0x46, clamp_f0(arg));
                    }
                }
                0xf0 => m.set_i16(s + 0x4c, arg),
                0xfa => m.set_i16(s + 0x60, arg),
                _ => {}
            }
            cmd += 6;
        }
    }
    let e70 = m.u32(C_FEAT);
    let e64 = m.u32(P_FEAT);
    let fc = m.u32(N_FEAT);
    let e5c = m.u32(N2_FEAT);
    let e78 = m.u32(C_FLAGS);
    let ebx = (e78 & 4) >> 2;
    let ebp = !(fc & 0x20000000 == 0 && fc & 0x8000000 != 0 && (fc & 0x1000000 == 0 || fc & 0x8000 != 0));
    if e78 & 0x80 != 0 {
        if e64 & 0x100 != 0 && e70 & 0x8000000 != 0 {
            m.set_i32(A00, 100);
        } else {
            m.set_i32(A00, m.u8(m.u32(s + 0xc4)) as i32 * 2);
        }
        m.set_u32(s + 0xc4, m.u32(s + 0xc4).wrapping_add(1));
        m.set_i32(E80, m.u8(m.u32(s + 0xc8)) as i32 * 2);
        m.set_u32(s + 0xc8, m.u32(s + 0xc8).wrapping_add(1));
        m.set_i32(E84, m.u8(m.u32(s + 0xcc)) as i32 * 2);
        m.set_u32(s + 0xcc, m.u32(s + 0xcc).wrapping_add(1));
        m.set_u16(E6A, ((m.u8(m.u32(s + 0xd8)) & 0x70) >> 1) as u16);
        m.set_u32(s + 0xd8, m.u32(s + 0xd8).wrapping_add(1));
        m.set_u32(PENDING, 1);
        m.set_u32(HOLD, 0);
        let x = if e70 & 0x2000000 != 0 {
            e70
        } else if fc & 0x2000000 != 0 {
            fc
        } else if e5c & 0x2000000 != 0 {
            e5c
        } else {
            0
        };
        if x & 0x400000 == 0 {
            let d = if x & 0x200 != 0 {
                Some((4, 7, 4))
            } else if x & 0x4000 != 0 {
                Some((-4, -7, -4))
            } else {
                None
            };
            if let Some((a, b, c)) = d {
                m.set_i32(A00, m.i32(A00).wrapping_add(a));
                m.set_i32(E80, m.i32(E80).wrapping_add(b));
                m.set_i32(E84, m.i32(E84).wrapping_add(c));
            }
        }
    }
    if m.i16(s + 0x4c) != 0 {
        return;
    }
    if e70 & 0x2000 != 0 && e64 & 0x800000 != 0 && fc & 0x10000000 != 0 && m.u8(N_STRF) != 0 {
        at_mid(m, s, fr, m.i32(A00) - 10);
    }
    let e6a = || m.i16(E6A) as i32;
    if m.u32(HOLD) != 0 {
        let x = e6a();
        let p = if x != 0 { x.wrapping_add(m.i32(E84)) } else { m.i32(E84) };
        at_end(m, s, fr, p);
        return;
    }
    if m.u32(PENDING) != 0 {
        m.set_u32(HOLD, 0);
        if e70 & 0x8000000 != 0 {
            m.set_u32(PENDING, 0);
            let a00 = m.i32(A00);
            if e70 & 0x2000000 != 0 {
                at_start(m, s, fr, a00);
            } else if e64 & 0x100 != 0 {
                at_start(m, s, fr, a00);
                at_mid(m, s, fr, (m.i32(E80).wrapping_add(a00)) >> 1);
            } else if ebx != 0 && fc & 0x2000000 != 0 {
                at_mid(m, s, fr, a00);
            } else {
                at_end(m, s, fr, a00);
            }
        }
    }
    let mut to_ec4 = false;
    if e70 & 0x2000000 != 0 {
        let e80 = m.i32(E80);
        if e64 & 0x40000 != 0 && e64 & 0x8000000 == 0 {
            at_start(m, s, fr, e80 + 8);
        } else if m.u8(C_STRF) != 0 {
            if ebx != 0 {
                at_start(m, s, fr, e80);
            } else if m.u8(N_FLAGS) & 0x80 != 0 {
                at_mid(m, s, fr, e80);
            } else if fc & 0x10002000 != 0 {
                at_next(m, s, fr, e80);
            } else {
                at_end(m, s, fr, e80);
            }
        } else if ebx != 0 {
            at_start(m, s, fr, e80);
        } else {
            at_mid(m, s, fr, e80);
        }
        if ebx != 0 {
            to_ec4 = true;
        } else if m.i16(E6A) == 0 {
            let e84 = m.i32(E84);
            if m.u8(N_FLAGS) & 0x80 != 0 {
                at_end(m, s, fr, e84);
            } else {
                at_next(m, s, fr, e84);
            }
        }
    }
    if !to_ec4 && ebx == 0 {
        return;
    }
    if ebp && m.i16(E6A) == 0 {
        at_end(m, s, fr, m.i32(E84));
        m.set_u32(HOLD, 1);
        return;
    }
    if ebx != 0 && m.i16(E6A) != 0 {
        if e70 & 0x2000000 != 0 {
            at_mid(m, s, fr, m.i32(E84));
        }
        if ebp {
            at_end(m, s, fr, (m.i16(E6A) as i32).wrapping_add(m.i32(E84)));
            m.set_u32(HOLD, 1);
        }
    }
}

/// `FUN_1c2042c0`: sung notes: the frames keep the current note until a
/// pitch command changes it.
pub(super) fn sung(m: &mut Mem, s: u32, fr: u32, rec: u32) {
    let cur = m.u16(F0);
    let mut k: u16 = 0;
    let mut p = fr;
    while k < m.u16(NFR) {
        m.set_u16(p + 0x18, cur);
        p = p.wrapping_add(0x20);
        k += 1;
    }
    let mut cmd = m.u32(rec);
    if cmd == 0 {
        return;
    }
    while m.i16(cmd) != 0x1e {
        let arg = m.i16(cmd + 2);
        match m.i16(cmd) {
            0x8c => m.set_i16(s + 0xae, arg),
            0xb4 => {
                let v = if arg <= 0 { note(m, s, arg) } else { clamp_f0(arg) as u16 };
                fill(m, s, fr, m.u16(cmd + 4), v);
                m.set_u16(F0, v);
            }
            0xf0 => m.set_i16(s + 0x4c, arg),
            0xfa => m.set_i16(s + 0x60, arg),
            _ => {}
        }
        cmd += 6;
    }
}

/// `FUN_1c204030`: held pitch.  `fr` is the end of the phoneme's frames, so
/// pitch commands write into the following frames.
pub(super) fn held(m: &mut Mem, s: u32, fr: u32, rec: u32) {
    let mut cmd = m.u32(rec);
    if cmd != 0 {
        while m.i16(cmd) != 0x1e {
            let arg = m.i16(cmd + 2);
            match m.i16(cmd) {
                0x8c => m.set_i16(s + 0xae, arg),
                0xb4 => {
                    let v = if arg <= 0 { note(m, s, arg) } else { clamp_f0(arg) as u16 };
                    fill(m, s, fr, m.u16(cmd + 4), v);
                }
                0xf0 => m.set_i16(s + 0x4c, arg),
                0xfa => m.set_i16(s + 0x60, arg),
                _ => {}
            }
            cmd += 6;
        }
    }
    let e70 = m.u32(C_FEAT);
    if m.u8(C_FLAGS) & 0x80 != 0 || e70 & 0x20000000 != 0 {
        let e7e = m.u8(C_CODE);
        let v = if e70 & 0x20000000 == 0 && e7e != 0x1c {
            let c46 = m.u16(s + 0x46) as u32;
            let idx = (e7e as u32 + c46) & 7;
            ((m.i16(JITTER + idx * 2) as i32).wrapping_mul(c46 as i32) / 0x6e) as u16
        } else {
            m.u16(F0)
        };
        m.set_u16(fr.wrapping_sub(8), m.u16(F0));
        store_f0(m, s, fr + 0x18, v);
        m.set_u16(F0, v);
    }
}
