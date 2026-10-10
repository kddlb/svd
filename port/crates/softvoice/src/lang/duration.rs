//! Segment duration rules (language slot [1]): TIENG32 `FUN_1c2010d0` and
//! TISPAN32 `FUN_1c4010d0`.  Klatt-style: a percentage built from context
//! rules scales the phoneme's inherent duration above its minimum.
//!
//! Both keep their working values in their DLL's `.bss`; they are written
//! at the same addresses (and widths) as the original so that the module
//! state stays identical to the DLL's.

use crate::mem::Mem;

/// Feature word of the phoneme in a record, via the record's language.
fn feat_at(m: &Mem, lang_ptr_at: u32, code: i16) -> u32 {
    m.u32(m.u32(m.u32(lang_ptr_at) + 0x1c).wrapping_add((code as i32 * 4) as u32))
}

/// Context gathered from the five records around the current one, stored
/// in the language module's globals.
struct Ctx {
    prev2_feat: u32,
    prev_code: i16,
    prev_feat: u32,
    prev_stress: i16,
    code: i16,
    feat: u32,
    flags: u32,
    stress: u16,
    next_code: i16,
    next_feat: u32,
    next_stress: i16,
    next_flags: u32,
    next2_feat: u32,
    fixed: i32,
    scale: i32,
}

/// Addresses of one module's globals (English / Spanish).
struct Globals {
    prev2_code: u32,
    prev2_feat: u32,
    prev2_flags: u32,
    prev2_stress: u32,
    prev_code: u32,
    prev_feat: u32,
    prev_flags: u32,
    prev_stress: u32,
    code: u32,
    feat: u32,
    flags: u32,
    stress: u32,
    next_code: u32,
    next_feat: u32,
    next2_code: u32,
    next2_feat: u32,
    next_stress: u32,
    next2_stress: u32,
    next_flags: u32,
    next2_flags: u32,
    fixed: u32,
    scale: u32,
}

const EN: Globals = Globals {
    prev2_code: 0x1c255350,
    prev2_feat: 0x1c255308,
    prev2_flags: 0x1c255368,
    prev2_stress: 0x1c255314,
    prev_code: 0x1c25531c,
    prev_feat: 0x1c255334,
    prev_flags: 0x1c255328,
    prev_stress: 0x1c255344,
    code: 0x1c255330,
    feat: 0x1c255348,
    flags: 0x1c255338,
    stress: 0x1c255352,
    next_code: 0x1c255346,
    next_feat: 0x1c255364,
    next2_code: 0x1c255332,
    next2_feat: 0x1c25534c,
    next_stress: 0x1c255304,
    next2_stress: 0x1c255358,
    next_flags: 0x1c255354,
    next2_flags: 0x1c255340,
    fixed: 0x1c255360,
    scale: 0x1c25535c,
};

const ES: Globals = Globals {
    prev2_code: 0x1c416fa0,
    prev2_feat: 0x1c416f58,
    prev2_flags: 0x1c416fb8,
    prev2_stress: 0x1c416f64,
    prev_code: 0x1c416f6c,
    prev_feat: 0x1c416f84,
    prev_flags: 0x1c416f78,
    prev_stress: 0x1c416f94,
    code: 0x1c416f80,
    feat: 0x1c416f98,
    flags: 0x1c416f88,
    stress: 0x1c416fa2,
    next_code: 0x1c416f96,
    next_feat: 0x1c416fb4,
    next2_code: 0x1c416f82,
    next2_feat: 0x1c416f9c,
    next_stress: 0x1c416f54,
    next2_stress: 0x1c416fa8,
    next_flags: 0x1c416fa4,
    next2_flags: 0x1c416f90,
    fixed: 0x1c416fb0,
    scale: 0x1c416fac,
};

/// Common prologue of both rules: read the context around the record at
/// S+0x28 into the globals and apply duration commands.
fn gather(m: &mut Mem, s: u32, g: &Globals) -> (u32, Ctx) {
    let r = m.u32(s + 0x28);
    let p2 = r.wrapping_sub(0x34);
    let p1 = r.wrapping_sub(0x1a);

    let prev2_code = m.i16(p2 + 0xc);
    m.set_i16(g.prev2_code, prev2_code);
    let prev2_feat = feat_at(m, p2 + 8, prev2_code);
    m.set_u32(g.prev2_feat, prev2_feat);
    m.set_u32(g.prev2_flags, m.u32(p2 + 0x16));
    m.set_u16(g.prev2_stress, m.u16(p2 + 0x10));
    let prev_code = m.i16(p1 + 0xc);
    m.set_i16(g.prev_code, prev_code);
    let prev_feat = feat_at(m, p1 + 8, prev_code);
    m.set_u32(g.prev_feat, prev_feat);
    m.set_u32(g.prev_flags, m.u32(p1 + 0x16));
    let prev_stress = m.i16(p1 + 0x10);
    m.set_i16(g.prev_stress, prev_stress);
    let code = m.i16(r + 0xc);
    m.set_i16(g.code, code);
    let feat = feat_at(m, r + 8, code);
    m.set_u32(g.feat, feat);
    let flags = m.u32(r + 0x16);
    m.set_u32(g.flags, flags);
    let stress = m.u16(r + 0x10);
    m.set_u16(g.stress, stress);

    let mut next_code = m.i16(r + 0x26);
    let (next_feat, next_stress, next_flags, next2_feat);
    if next_code == 0xff {
        next_code = 0;
        next_feat = 0x100000;
        next2_feat = 0x100000;
        next_stress = 0;
        next_flags = 0;
        m.set_i16(g.next_code, 0);
        m.set_u32(g.next_feat, next_feat);
        m.set_i16(g.next2_code, 0);
        m.set_u32(g.next2_feat, next2_feat);
        m.set_i16(g.next_stress, 0);
        m.set_u16(g.next2_stress, 0);
        m.set_u32(g.next_flags, 0);
        m.set_u32(g.next2_flags, 0);
    } else {
        m.set_i16(g.next_code, next_code);
        next_feat = feat_at(m, r + 0x22, next_code);
        m.set_u32(g.next_feat, next_feat);
        next_flags = m.u32(r + 0x30);
        m.set_u32(g.next_flags, next_flags);
        next_stress = m.i16(r + 0x2a);
        m.set_i16(g.next_stress, next_stress);
        let next2_code = m.i16(r + 0x40);
        m.set_i16(g.next2_code, next2_code);
        if next2_code == 0xff {
            next2_feat = 0x100000;
            m.set_u32(g.next2_feat, next2_feat);
            m.set_i16(g.next2_code, 0);
            m.set_u32(g.next2_flags, 0);
            m.set_u16(g.next2_stress, 0);
        } else {
            next2_feat = feat_at(m, r + 0x3c, next2_code);
            m.set_u32(g.next2_feat, next2_feat);
            m.set_u32(g.next2_flags, m.u32(r + 0x4a));
            m.set_u16(g.next2_stress, m.u16(r + 0x44));
        }
    }

    let mut fixed: i32 = 0;
    let mut scale: i32 = 100;
    m.set_i32(g.fixed, fixed);
    m.set_i32(g.scale, scale);
    let mut cmd = m.u32(r);
    if cmd != 0 {
        while m.i16(cmd) != 0x1e {
            let arg = m.i16(cmd + 2);
            match m.i16(cmd) as i32 {
                0x32 => {
                    let presets = m.u32(m.u32(r + 8) + 0x20);
                    let v = m.i16((presets as i32 + 0x24 + arg as i32 * 0x4a) as u32);
                    m.set_i32(s + 0x56, v as i32);
                }
                0x28 | 0x50 => {
                    if arg < 0 {
                        scale = (arg as i32).wrapping_mul(scale) / -100;
                        m.set_i32(g.scale, scale);
                    } else {
                        fixed = fixed.wrapping_add(arg as i32);
                        m.set_i32(g.fixed, fixed);
                    }
                }
                0x5a => m.set_i16(s + 0xb2, arg),
                0x64 => m.set_i16(s + 0xb0, arg),
                0x6e => m.set_i16(s + 0xb4, arg),
                0x136 => m.set_i32(s + 0x56, arg as i32),
                _ => {}
            }
            cmd += 6;
        }
    }
    (
        r,
        Ctx {
            prev2_feat,
            prev_code,
            prev_feat,
            prev_stress,
            code,
            feat,
            flags,
            stress,
            next_code,
            next_feat,
            next_stress,
            next_flags,
            next2_feat,
            fixed,
            scale,
        },
    )
}

/// Duration of a pause phoneme: '-' uses S+0xb0, others S+0xb2 (comma) or
/// S+0xb4 (sentence end, feature bit 1).
fn pause(m: &Mem, s: u32, c: &Ctx) -> u32 {
    if c.code == 4 {
        m.u16(s + 0xb0) as u32
    } else if c.feat & 1 == 0 {
        m.u16(s + 0xb2) as u32
    } else {
        m.u16(s + 0xb4) as u32
    }
}

/// `x * pct / 100` rounded, as the original's `(x * pct + 50) / 100`.
fn pct(x: u32, p: u32) -> u32 {
    x.wrapping_mul(p).wrapping_add(0x32) / 100
}

/// `(dur * vfactor) / 100` with the original's 32-bit truncation.
fn vowel_factor(m: &Mem, s: u32, dur: u32) -> u32 {
    let p = (m.i32(s + 0x56) as i64).wrapping_mul(dur as i32 as i64) as u64 & 0xffff_ffff;
    (p / 100) as u32
}

/// TIENG32 `FUN_1c2010d0`.
pub fn english(m: &mut Mem, s: u32) {
    let g = &EN;
    let (r, mut c) = gather(m, s, g);
    let saved_prev_feat = c.prev_feat;
    let saved_next_feat = c.next_feat;
    let cur_table = m.u32(m.u32(r + 8) + 0x1c);

    if c.feat & 0x100000 != 0 {
        return;
    }
    let mut dur: u32;
    if c.feat & 0x200_0000 != 0 && c.code != 0x1b {
        dur = pause(m, s, &c);
        m.set_u32(0x1c255318, dur);
    } else {
        let final_ = c.flags & 4;
        let mut p: u32 = if final_ != 0 { 0x82 } else { 100 };
        m.set_u32(0x1c255324, p);
        if c.feat & 0x18000 != 0 && final_ != 0 {
            p = pct(p, 0x8c);
        }
        let vowel = c.feat & 0x1000_0000;
        if vowel != 0 {
            if final_ == 0 {
                p = pct(p, 0x3c);
            }
            if c.flags & 8 == 0 {
                p = pct(p, 0x55);
            }
            if c.flags & 0x40 != 0 {
                p = pct(p, 0x50);
            }
            if c.stress < 3 {
                p = pct(p, 0x3c);
            }
            let by_stress: u32 = match c.stress {
                0 => 100,
                1 => 0x5a,
                2 => 0x5d,
                3 => 0x60,
                4 | 5 => 100,
                6 => 0x6e,
                7 => 0x78,
                8 => 0x82,
                9 => 0x8c,
                _ => 100,
            };
            p = (by_stress.wrapping_mul(p).wrapping_add(0x32)) / 100;
            if c.code == 0x29 && c.prev_code == 0x39 {
                p = pct(p, 0x41);
            }
            let mut f: u32 = 100;
            if c.stress != 0 {
                let nf = c.next_feat;
                if nf & 0x2000_0000 == 0 && c.next_code != 0 {
                    if nf & 0x1000 == 0 || nf & 0x4000 != 0 || nf & 0x800_0000 == 0 {
                        if nf & 0x80_0000 == 0 {
                            if nf & 0x8000 == 0 || c.next_stress != 0 {
                                if nf & 0x100_0000 != 0 || c.next_code == 0x3f {
                                    f = if c.next_code == 0x54 || c.next_code == 0x55 { 0x37 } else { 0x46 };
                                }
                            } else {
                                let next2 = m.i16(g.next2_code) as i32;
                                f = if m.u8(cur_table.wrapping_add(3).wrapping_add((next2 * 4) as u32)) & 1 == 0 {
                                    0x55
                                } else {
                                    0x3c
                                };
                            }
                        } else {
                            f = 0x78;
                        }
                    } else {
                        f = 0x96;
                    }
                } else {
                    f = 0x82;
                }
            }
            if final_ == 0 {
                f = (f.wrapping_mul(0x1e).wrapping_add(0xf)) / 0x28 + 0x19;
            }
            m.set_u32(0x1c255310, f);
            p = (f.wrapping_mul(p).wrapping_add(0x32) as i32 / 100) as u32;
        }
        if c.feat & 2 != 0 {
            if c.prev_code > 8 {
                p = pct(p, 0x55);
            }
            if c.feat & 0x180_0000 != 0 && c.prev_code == 0x41 {
                p = pct(p, 0x3c);
            }
            if m.i16(g.prev2_code) == 0x41 && c.prev_feat & 0x180_0000 != 0 && c.feat & 0x30000 != 0 {
                p = ((p.wrapping_mul(5).wrapping_add(5)).wrapping_mul(10) as i32 / 100) as u32;
            }
            if c.prev_code == 0x41 && c.feat & 0x8000 != 0 {
                p = pct(p, 0x3c);
            }
            if c.feat & 0x1000 != 0 && c.feat & 0x800_0000 == 0 && final_ != 0 {
                p = pct(p, 0x96);
            }
            if c.stress < 3 {
                if c.feat & 0x30000 == 0 || c.next_feat & 0x1000_0000 == 0 {
                    p = pct(p, 0x46);
                } else {
                    p = pct(p, 0x14);
                }
            }
            if c.code == 0x39 && c.next_code == 0x29 {
                p = pct(p, 0x46);
            }
        }
        m.set_u32(0x1c25530c, c.prev_feat);
        m.set_u32(0x1c25533c, c.next_feat);
        if c.prev_code == 0 {
            c.prev_feat = c.prev2_feat;
            m.set_u32(g.prev_feat, c.prev_feat);
        }
        if c.next_code == 0 {
            c.next_feat = c.next2_feat;
            m.set_u32(g.next_feat, c.next_feat);
        }
        if vowel == 0 {
            if c.feat & 2 != 0 {
                let (a, b) = (c.prev_feat & 2 != 0, c.next_feat & 2 != 0);
                if a && b {
                    p = (p.wrapping_mul(5).wrapping_add(5)).wrapping_mul(10) / 100;
                } else if a || b {
                    p = p.wrapping_mul(0x46).wrapping_add(0x32) / 100;
                }
            }
        } else {
            if c.next_feat & 0x1000_0000 != 0 {
                p = pct(p, 0x78);
            }
            if c.prev_feat & 0x1000_0000 != 0 {
                p = p.wrapping_mul(0x46).wrapping_add(0x32) / 100;
            }
        }
        let table = m.u32(r + 4);
        let inh = m.i16((table as i32 + 0x14 + c.code as i32 * 0x1a) as u32) as i32;
        let mut min = m.i16((table as i32 + 0x12 + c.code as i32 * 0x1a) as u32) as i32;
        if c.stress == 0 {
            min = (min + 1) >> 1;
        }
        m.set_i32(0x1c255320, inh);
        m.set_i32(0x1c25532c, min);
        if p as i32 > 0xa9 {
            p = 0xaa;
        }
        m.set_u32(0x1c255324, p);
        dur = (min as u32).wrapping_add(((inh.wrapping_sub(min) as u32).wrapping_mul(p).wrapping_add(0x32) as i32 / 100) as u32);
        if c.stress != 0 && c.feat & 4 != 0 && saved_prev_feat & 0x100_0000 != 0 {
            dur = dur.wrapping_add(0x19);
        }
        if vowel != 0 && c.code != 0x17 && c.code != 0x18 {
            dur = vowel_factor(m, s, dur);
        }
    }
    let _ = c.next_flags;
    let _ = c.prev_stress;
    if c.fixed != 0 {
        dur = c.fixed as u32;
    }
    let mut d = (dur.wrapping_mul(c.scale as u32) as i32) / 100;
    if d > 3999 {
        d = 4000;
    }
    if d < 0x1a {
        d = 0x19;
    }
    m.set_u32(0x1c255318, d as u32);
    m.set_u32(g.prev_feat, saved_prev_feat);
    m.set_u32(g.next_feat, saved_next_feat);
    m.set_i16(r + 0xe, d as i16);
}

/// TISPAN32 `FUN_1c4010d0`.
pub fn spanish(m: &mut Mem, s: u32) {
    let g = &ES;
    let (r, c) = gather(m, s, g);
    if c.feat & 0x100000 != 0 {
        return;
    }
    let mut dur: u32;
    if c.feat & 0x200_0000 != 0 && c.code != 0x1b {
        dur = pause(m, s, &c);
    } else {
        let mut p: u32 = if c.flags & 4 != 0 { 0x82 } else { 100 };
        if c.feat & 0x18000 != 0 && c.flags & 4 != 0 {
            p = pct(p, 0x8c);
        }
        if c.feat & 0x1000_0000 != 0 {
            match c.stress {
                6 => p = pct(p, 0x6e),
                7 => p = pct(p, 0x78),
                8 => p = pct(p, 0x82),
                9 => p = pct(p, 0x8c),
                _ => {}
            }
            if c.flags & 0x40 != 0 {
                p = pct(p, 0x50);
                if c.stress == 0 {
                    p = pct(p, 0x50);
                }
            }
            if c.prev_code < 9 {
                p = pct(p, 0x78);
            }
            let mut f: u32 = 100;
            if c.flags & 8 != 0 && (c.stress != 0 || c.flags & 0x40 != 0) {
                f = 0x78;
            }
            if c.next_feat & 0x100_0000 != 0 {
                f = 0x55;
            }
            if c.next_feat & 0x1000 != 0 && c.next_feat & 0x800_0000 != 0 {
                f = 0x82;
            }
            m.set_u32(0x1c416f60, f);
            p = (f.wrapping_mul(p).wrapping_add(0x32)) / 100;
            if c.stress != 0 && c.next_feat & 2 != 0 && c.next_flags & 0x80 == 0 {
                p = pct(p, 0x46);
            }
            if c.next_code == 0x1e || c.next_code == 0x36 || c.next_code == 0x6c {
                p = (p.wrapping_mul(0x4b).wrapping_add(0x32) as i32 / 100) as u32;
            }
            if c.stress == 0 {
                if c.next_stress != 0 && c.next_feat & 0x1000_0000 != 0 {
                    p = (p.wrapping_mul(0x96).wrapping_add(0x32) as i32 / 100) as u32;
                } else if c.prev_stress != 0 && c.prev_feat & 0x1000_0000 != 0 {
                    p = (p.wrapping_mul(0x82).wrapping_add(0x32) as i32 / 100) as u32;
                }
            }
        }
        let cons = c.feat & 2;
        if cons != 0 {
            if c.feat & 0x40_0000 != 0 {
                p = pct(p, 0x4b);
            }
            if c.prev_code < 9 {
                if c.feat & 0x30000 != 0 {
                    p = if c.stress == 0 { pct(p, 0x8c) } else { pct(p, 200) };
                }
            } else {
                p = pct(p, 0x55);
            }
            if c.prev_feat & 0x1000_0000 != 0 && c.next_feat & 2 != 0 {
                p = if c.prev_stress == 0 {
                    pct(p, 0x82)
                } else if c.next_feat & 0x800_0000 == 0 {
                    pct(p, 0xa0)
                } else {
                    pct(p, 200)
                };
            } else if c.prev_feat & 0x1000_0000 != 0 {
                p = pct(p, 0x82);
            }
            if (c.code == 0x52 && c.prev_code == 0x3d)
                || (c.code == 0x51 && c.prev_code == 0x3c)
                || (c.code == 0x54 && c.prev_code == 0x3e)
            {
                p = pct(p, 0x96);
            }
        }
        m.set_u32(0x1c416f74, p);
        m.set_u32(0x1c416f5c, c.prev_feat);
        m.set_u32(0x1c416f8c, c.next_feat);
        let table = m.u32(r + 4);
        let inh = m.i16((table as i32 + 0x14 + c.code as i32 * 0x1a) as u32) as i32;
        let min = m.i16((table as i32 + 0x12 + c.code as i32 * 0x1a) as u32) as i32;
        m.set_i32(0x1c416f70, inh);
        m.set_i32(0x1c416f7c, min);
        let base = if c.stress == 0 { min } else { inh };
        let pc = if p as i32 > 299 { 300 } else { p };
        dur = (pc.wrapping_mul(base as u32) as i32 / 100) as u32;
        if c.feat & 0x1000_0000 != 0 {
            dur = vowel_factor(m, s, dur);
        }
    }
    let _ = c.prev2_feat;
    let _ = c.next2_feat;
    if c.fixed != 0 {
        dur = c.fixed as u32;
    }
    let mut d = ((dur.wrapping_mul(c.scale as u32) as i32 / 100) * 0xf) / 0xd;
    if d > 3999 {
        d = 4000;
    }
    if d < 0x1a {
        d = 0x19;
    }
    m.set_u32(0x1c416f68, d as u32);
    m.set_i16(r + 0xe, d as i16);
}
