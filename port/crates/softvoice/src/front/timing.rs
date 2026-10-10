//! Durations and frames: the drivers `c3e0` (per-phoneme durations, via the
//! language module) and `5840` (frame generation, via the language module),
//! plus `f7c0` (`{tempo}` and `*` beat retiming) and `c420` (drop silent
//! phonemes and allocate the frame buffer).

use crate::lang;
use crate::mem::Mem;

use super::parse::REC;
use super::records::features;

/// `c3e0`: call the language's duration rule (slot [1]) for every phoneme
/// from record 2 on, with S+0x28 pointing at it.
pub fn durations(m: &mut Mem, s: u32) {
    let mut rec = m.u32(s + 0x1c) + 2 * REC;
    let mut code = m.i16(rec + 0xc);
    while code != 0xff {
        m.set_u32(s + 0x28, rec);
        let func = m.u32(m.u32(rec + 8) + 4);
        lang::call_duration(m, s, func);
        code = m.i16(rec + 0x26);
        rec += REC;
    }
}

/// `f7c0`: convert command positions (ms within the phoneme) to frame
/// offsets, and stretch the phonemes between beats (`*`, command 700) to
/// the `{tempo}` (command 0x2c6, beats per minute).
pub fn tempo(m: &mut Mem, s: u32) {
    let mut total: u32 = 0; // uVar9
    let mut beat_start = m.u32(s + 0x1c); // puVar8
    let mut beats: i32 = 0; // local_8
    let mut count: i32 = 0; // local_4
    let mut rec = beat_start;
    let mut code = m.i16(rec + 0xc);
    loop {
        if code == 0xff {
            return;
        }
        let mut cmd = m.u32(rec);
        if cmd != 0 {
            while m.i16(cmd) != 0x1e {
                if m.i16(cmd) == 0x2c6 {
                    let mut bpm = m.u16(cmd + 2);
                    if (bpm as i16) < 0x15 {
                        bpm = 0x14;
                    }
                    m.set_u16(s + 0xa8, bpm);
                    m.set_u16(s + 0xaa, (60000u64 / bpm as u64) as u16);
                    break;
                }
                let pos = m.i16(cmd + 4);
                if pos != 0 {
                    let dur = m.u16(rec + 0xe) as u32;
                    let v = if pos < 0 {
                        ((8u32.wrapping_sub(dur).wrapping_mul(pos as i32 as u32)) as i32 / 100) >> 3
                    } else {
                        let lim = dur as i16 as i32 - 8;
                        (if pos as i32 <= lim { pos as i32 } else { lim }) >> 3
                    };
                    m.set_i16(cmd + 4, v as i16);
                }
                cmd += 6;
            }
        }
        if m.u8(rec + 0x17) & 4 != 0 {
            beats = (m.u16(s + 0xaa) as u32).wrapping_mul(beats as u32) as i32;
            if beats != 0 {
                while count != 0 {
                    let mut d = (m.u16(beat_start + 0xe) as u32).wrapping_mul(beats as u32) / total;
                    if d > 3999 {
                        d = 4000;
                    }
                    if d < 0x1a {
                        d = 0x19;
                    }
                    m.set_u16(beat_start + 0xe, d as u16);
                    let mut c = m.u32(beat_start);
                    if c != 0 {
                        while m.i16(c) != 0x1e {
                            let pos = m.i16(c + 4);
                            if pos != 0 {
                                let mut v = ((pos as i32).wrapping_mul(beats) as u32) / total;
                                let lim = (m.u16(rec + 0xe) as i32 - 1) as u32;
                                if lim <= v {
                                    v = lim;
                                }
                                m.set_i16(c + 4, v as i16);
                            }
                            c += 6;
                        }
                    }
                    beat_start += REC;
                    count -= 1;
                }
            }
            total = 0;
            count = 0;
            beats = 0;
            let mut c = m.u32(rec);
            beat_start = rec;
            while m.i16(c) != 0x1e {
                if m.i16(c) == 700 {
                    beats = m.i16(c + 2) as i32;
                    break;
                }
                c += 6;
            }
        }
        count += 1;
        total = total.wrapping_add(m.u16(rec + 0xe) as u32);
        code = m.i16(rec + 0x26);
        rec += REC;
    }
}

/// `c420`: drop phonemes with feature bit 0x100000 (no acoustic
/// realisation), then allocate the frame buffer: 4 + sum((dur + 4) >> 3)
/// frames of 32 bytes.  Returns 0 (or 0x1b5b if out of memory).
pub fn alloc_frames(m: &mut Mem, s: u32) -> i32 {
    let mut count: u32 = 4;
    let mut dst = m.u32(s + 0x1c);
    let mut rec = dst;
    let mut code = m.i16(rec + 0xc);
    while code != 0xff {
        if (features(m, rec) >> 16) & 0x10 == 0 {
            if dst != rec {
                let r = m.bytes(rec, REC as usize).to_vec();
                m.bytes_mut(dst, REC as usize).copy_from_slice(&r);
            }
            dst += REC;
            count = count.wrapping_add(((m.u16(rec + 0xe) as i32 + 4) >> 3) as u32);
        }
        code = m.i16(rec + 0x26);
        rec += REC;
    }
    m.set_u16(dst + 0xc, 0xff);
    m.set_u32(s + 0x102, count << 5);
    let frames = m.alloc((count * 0x20) as usize);
    m.set_u32(s + 0xf6, frames);
    for o in [0xfa, 0x31e, 0x322, 0x326, 0x32a] {
        m.set_u32(s + o, frames);
    }
    m.set_u32(s + 0x32e, s);
    0
}

/// `5840`: slide a five-record window (S+0x20..0x30) over the phonemes and
/// call the language's frame generator (slot [2]) for each, then terminate
/// the frame buffer.
pub fn frames(m: &mut Mem, s: u32) {
    m.set_u32(s + 0xfa, m.u32(s + 0xf6));
    let mut rec = m.u32(s + 0x1c);
    m.set_u32(s + 0x20, rec);
    m.set_u32(s + 0x24, rec);
    m.set_u32(s + 0x28, rec + REC);
    m.set_u32(s + 0x2c, rec + 2 * REC);
    m.set_u32(s + 0x30, rec + 3 * REC);
    let mut code = m.i16(rec + 0x26);
    while code != 0xff {
        let func = m.u32(m.u32(rec + 0x22) + 8);
        lang::call_frames(m, s, func);
        m.set_u32(s + 0x20, m.u32(s + 0x24));
        m.set_u32(s + 0x24, m.u32(s + 0x28));
        let last = m.u32(s + 0x30);
        m.set_u32(s + 0x28, m.u32(s + 0x2c));
        m.set_u32(s + 0x2c, last);
        if m.i16(last + 0xc) != 0xff {
            m.set_u32(s + 0x30, last + REC);
        }
        code = m.i16(rec + 0x40);
        rec += REC;
    }
    let func = m.u32(m.u32(rec + 0x22) + 8);
    lang::call_frames(m, s, func);
    let p = m.u32(s + 0xfa);
    m.set_u8(p, 0xff);
    m.set_u8(p + 1, 0xff);
    m.set_u8(p + 2, 0xff);
    m.set_u8(p + 0x10, 0xff);
    m.set_u16(p + 0x18, 0xffff);
    if m.i16(s + 0x4c) == 3 {
        let k = -4 - m.u16(m.u32(s + 0x24) + 0xe) as i32;
        let back = (k + ((k >> 31) & 7)) >> 3;
        let v = m.u16((p as i32 + back * 0x20 - 8) as u32);
        m.set_u16(p - 8, v);
    }
}
