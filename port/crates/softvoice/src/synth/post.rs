//! Frame post-processing between the language module's frame generator and
//! the sample generator: `cd40` (F0 gap fill), `de60` (F0 smoothing, run
//! twice) and `be40` (vibrato/tremolo/tone, jitter, F0 -> phase increment,
//! glottal waveform choice).  All take S (context + 0x13a).

use crate::mem::Mem;

/// Per-phrase F0 jitter sequence (i8).
const JITTER: u32 = 0x1c001470;
/// Sine table for vibrato / tremolo / tone modulation (i16).
const SINE: u32 = 0x1c013430;
/// F0 -> glottal waveform choice, 5 bytes per F0 value below 0x10e.
const GLOT_BY_F0: u32 = 0x1c012ee8;
/// Personality presets (0x4a bytes each): perturb at +0x16, glottal at +0x0c.
const PRESETS: u32 = 0x1c013600;

/// Frame buffer pointer, S+0xf6.
fn frames(m: &Mem, s: u32) -> u32 {
    m.u32(s + 0xf6)
}

/// `cd40`: frames carry F0 targets only at some points (0 elsewhere); fill
/// each run of zeros by linear interpolation in 8.8 fixed point.
pub fn fill_f0(m: &mut Mem, s: u32) {
    let mut p = frames(m, s);
    loop {
        let mut cur = p;
        let start = m.u16(cur + 0x18) as u32;
        let mut acc = (start * 0x100) as i32;
        let mut q = cur;
        let mut zeros = 0i32;
        let mut next = m.i16(q + 0x38);
        loop {
            p = q + 0x20;
            if next != 0 {
                break;
            }
            zeros += 1;
            next = m.i16(q + 0x58);
            q = p;
        }
        if m.u8(p) == 0xff {
            break;
        }
        if zeros > 0 {
            let end = m.u16(q + 0x38) as u32;
            let n = zeros + 1;
            let delta = (end.wrapping_mul(0x100).wrapping_sub(start.wrapping_mul(0x100))) as i32 / n;
            for _ in 0..zeros {
                acc = acc.wrapping_add(delta);
                m.set_u16(cur + 0x38, ((acc as u32) >> 8) as u16);
                cur += 0x20;
            }
        }
    }
}

/// `de60`: asymmetric one-pole smoothing of F0, forward then backward.
/// Rising and falling rates are S+0x66 and S+0x64 (out of 256).
pub fn smooth_f0(m: &mut Mem, s: u32) {
    let mut p = frames(m, s);
    let rise = m.u16(s + 0x66) as i32;
    let fall = m.u16(s + 0x64) as i32;
    let mut n = 0i32;
    let mut acc = (m.u16(p + 0x18) as i32) << 8;
    while m.u8(p) != 0xff {
        let f0 = m.u16(p + 0x18) as i32;
        let k = if f0 * 0x100 <= acc { rise } else { fall };
        n += 1;
        acc = acc.wrapping_add((f0 - (acc >> 8)).wrapping_mul(k));
        m.set_u16(p + 0x18, ((acc as u32) >> 8) as u16);
        p += 0x20;
    }
    n -= 1;
    while n > 0 {
        let f0 = m.u16(p - 8) as i32;
        let k = if f0 * 0x100 < acc { fall } else { rise };
        acc = acc.wrapping_add((f0 - (acc >> 8)).wrapping_mul(k));
        n -= 1;
        m.set_u16(p - 8, ((acc as u32) >> 8) as u16);
        p -= 0x20;
    }
}

/// `be40`: per-frame modulation, jitter, F0 -> phase increment and glottal
/// waveform selection, applying `{voice}`, `{vibrato}`, `{mod...}`, `{glot}`
/// and `{perturb}` commands at the phonemes where they occur.
pub fn modulate(m: &mut Mem, s: u32) {
    let mut jit = JITTER;
    let mut jit_count: u16 = 0;
    let mut phase: u16 = 0; // local_1e
    let mut fr = frames(m, s);
    let mod_rate = |m: &Mem| ((((m.i16(s + 0x68) as i32) * 0x340) as u32 as u64) / 0x7f) as u16;
    let mut step = mod_rate(m); // local_22
    let mut target = (m.i16(s + 0x6a) as i32) << 8; // local_1c
    let mut ramp = (0x10000i64 / m.i16(s + 0x6c) as i64) as i32; // local_8

    let mut rec = m.u32(s + 0x1c);
    let mut code = m.i16(rec + 0x26);
    loop {
        if code == 0xff {
            return;
        }
        let next = rec + 0x1a;
        let mut cmd = m.u32(next);
        if cmd != 0 {
            while m.i16(cmd) != 0x1e {
                let arg = m.i16(cmd + 2);
                match m.i16(cmd) {
                    0x32 => {
                        let preset = PRESETS + (arg as i32 * 0x4a) as u32;
                        m.set_u16(s + 0x62, m.u16(preset + 0x16));
                        m.set_u16(s + 0x5a, m.u16(preset + 0x0c));
                    }
                    0xa0 => m.set_i16(s + 0x78, arg),
                    0xa2 => m.set_i16(s + 0x7a, arg),
                    0xa4 => m.set_i16(s + 0x7c, arg),
                    0xaa => {
                        m.set_i16(s + 0x68, arg);
                        step = mod_rate(m);
                    }
                    0xac => {
                        let depth = (((arg as i32) << 8) / 100) as i16;
                        m.set_i16(s + 0x6a, depth);
                        target = (depth as i32) << 8;
                        let old = m.i16(s + 0x72);
                        m.set_i16(s + 0x72, depth);
                        m.set_u32(s + 0x6e, (old < depth) as u32);
                    }
                    0xae => {
                        m.set_i16(s + 0x6c, arg);
                        ramp = (0x10000i64 / arg as i64) as i32;
                    }
                    0xd2 => m.set_i16(s + 0x5a, arg),
                    0x104 => m.set_i16(s + 0x62, arg),
                    _ => {}
                }
                cmd += 6;
            }
        }

        let nframes = ((m.u16(rec + 0x28) as i32 + 4) >> 3) as i16;
        for _ in 0..nframes.max(0) {
            let f0 = m.u16(fr + 0x18);
            let f0w = f0 as u32;
            let rate = m.u16(s + 0x48) as u32;
            m.set_u16(fr + 0x18, ((f0w << 17) / rate) as u16);
            phase = step.wrapping_add(phase) & 0x1fff;
            let mut modulated = false;
            let sine = m.i16(SINE + ((phase as u32 >> 5) & 0xfffe)) as i32;

            // Modulation depth ramps toward the target.
            if m.i32(s + 0x6e) == 1 {
                let v = ramp.wrapping_add(m.i32(s + 0x74));
                m.set_i32(s + 0x74, v);
                if target < v {
                    m.set_i32(s + 0x74, target);
                }
            } else {
                let v = m.i32(s + 0x74).wrapping_sub(0x1999);
                m.set_i32(s + 0x74, v);
                if v < target {
                    m.set_i32(s + 0x74, target);
                }
            }
            let depth = m.i32(s + 0x74) >> 8;

            let vibrato = m.i16(s + 0x78) as i32;
            if vibrato != 0 && depth != 0 {
                modulated = true;
                let cur = m.u16(fr + 0x18);
                let d = (((((cur as u32).wrapping_mul(sine as u32) as i32 >> 15).wrapping_mul(depth)) >> 8).wrapping_mul(vibrato)) >> 10;
                m.set_u16(fr + 0x18, (d as i16 as u16).wrapping_add(cur));
            }
            let tremolo = m.i16(s + 0x7a) as i32;
            if tremolo != 0 && depth != 0 {
                modulated = true;
                let t = ((((sine - 0x7ff8).wrapping_mul(tremolo) >> 16).wrapping_mul(depth)) >> 8).wrapping_mul(2);
                let clamp = |v: i32| if v < 1 { 0 } else if v > 0x7f { 0x80 } else { v };
                let ah = clamp(m.u8(fr + 0x11) as i32 + t);
                let av = clamp(m.u8(fr + 0x10) as i32 + t);
                m.set_u8(fr + 0x10, av as u8);
                m.set_u8(fr + 0x11, ah as u8);
            }
            let tone = m.i16(s + 0x7c) as i32;
            if tone != 0 && depth != 0 {
                modulated = true;
                let b7 = m.u8(fr + 7);
                let mut t = (((tone.wrapping_mul(sine) >> 15).wrapping_mul(depth)) >> 8).wrapping_add((b7 & 0xf) as i32);
                if t > 0xe {
                    t = 0xf;
                }
                if t < 1 {
                    t = 0;
                }
                m.set_u8(fr + 7, (t as u8).wrapping_add(b7 & 0xf0));
            }
            if !modulated {
                phase = 0;
            }

            // Jitter.
            let perturb = m.u16(s + 0x62) as u32;
            if perturb != 0 {
                let j = (m.i8(jit) as i32 as u32).wrapping_mul(perturb).wrapping_mul(f0w) as i32 >> 13;
                m.set_u16(fr + 0x18, m.u16(fr + 0x18).wrapping_add(j as i16 as u16));
            }
            jit_count += 1;
            if jit_count > 0xff {
                jit = JITTER;
                jit_count = 0;
            }

            // Glottal waveform pair and crossfade.
            m.set_u8(fr + 0xf, 0xff);
            let (a, b, mix) = match m.u16(s + 0x5a) {
                0 if m.i16(s + 0x52) != 0 => (None, None, None),
                0 | 1 => {
                    if f0 < 0x10e {
                        let mut k = 0u32;
                        let mut c = 0u8;
                        while k < 5 {
                            c = m.u8(GLOT_BY_F0 + f0w * 5 + k);
                            if c != 0 {
                                break;
                            }
                            k += 1;
                        }
                        let second = if k != 4 { (k + 1) as u8 } else { k as u8 };
                        (Some(k as u8), Some(second), Some(c))
                    } else {
                        (Some(4), Some(4), None)
                    }
                }
                2 => (Some(5), Some(5), None),
                3 => (Some(6), Some(6), None),
                4 => (Some(7), Some(7), None),
                5 => (Some(10), Some(10), None),
                6 => (Some(8), Some(8), None),
                7 => (Some(9), Some(9), None),
                8 => (Some(11), Some(11), None),
                _ => (Some(0), Some(0), None),
            };
            if let Some(a) = a {
                m.set_u8(fr + 0xd, a);
            }
            if let Some(b) = b {
                m.set_u8(fr + 0xe, b);
            }
            if let Some(mix) = mix {
                m.set_u8(fr + 0xf, mix);
            }

            fr += 0x20;
            jit += 1;
        }
        code = m.i16(rec + 0x40);
        rec = next;
    }
}
