//! Passes over the phoneme records after parsing: per-phoneme voice and
//! language (`3e40`), stressed-syllable onsets (`c550`), allophone rules
//! (`5910` and helpers), syllabification (`c6d0`) and post-boundary marks
//! (`3de0`).

use crate::lang::{TIBASE_LANG_DE, TIBASE_LANG_EN, TIBASE_LANG_ES};
use crate::mem::Mem;

use super::parse::REC;

/// Feature word of a record's phoneme, through its language structure.
pub fn features(m: &Mem, rec: u32) -> u32 {
    let lang = m.u32(rec + 8);
    let code = m.i16(rec + 0xc) as i32;
    m.u32(m.u32(lang + 0x1c).wrapping_add((code * 4) as u32))
}

fn flags(m: &Mem, rec: u32) -> u32 {
    m.u32(rec + 0x16)
}

fn or_flags(m: &mut Mem, rec: u32, bits: u32) {
    m.set_u32(rec + 0x16, m.u32(rec + 0x16) | bits);
}

/// Copy one 26-byte record.
fn copy_rec(m: &mut Mem, from: u32, to: u32) {
    let r = m.bytes(from, REC as usize).to_vec();
    m.bytes_mut(to, REC as usize).copy_from_slice(&r);
}

/// `3e40`: apply `{language}` and `{voice}` commands, stamping every record
/// with the language structure and phoneme table in effect at that point.
pub fn assign_voice(m: &mut Mem, s: u32) {
    let mut table = m.u32(s + 0x40);
    let mut lang = m.u32(s + 0x38);
    let mut rec = m.u32(s + 0x1c);
    let mut code = m.i16(rec + 0xc);
    loop {
        if code == 0xff {
            m.set_u32(rec + 8, lang);
            m.set_u32(rec + 4, table);
            return;
        }
        let mut cmd = m.u32(rec);
        if cmd != 0 {
            while m.i16(cmd) != 0x1e {
                if m.i16(cmd) == 0x41 {
                    let global = match m.i16(cmd + 2) {
                        0 => Some(TIBASE_LANG_EN),
                        1 => Some(TIBASE_LANG_ES),
                        2 => Some(TIBASE_LANG_DE),
                        _ => None,
                    };
                    if let Some(g) = global {
                        lang = m.u32(g);
                        m.set_u32(s + 0x3c, lang);
                        m.set_u32(s + 0x38, lang);
                    }
                }
                if m.i16(cmd) == 0x32 {
                    table = match m.i16(cmd + 2) {
                        1 | 3 | 5 | 0xd | 0xf => m.u32(lang + 0x18),
                        _ => m.u32(lang + 0x14),
                    };
                    m.set_u32(s + 0x40, table);
                }
                cmd += 6;
            }
        }
        m.set_u32(rec + 8, lang);
        m.set_u32(rec + 4, table);
        code = m.i16(rec + 0x26);
        rec += REC;
    }
}

/// `c550`: mark the consonants leading into each stressed vowel (flag 0x10).
pub fn mark_onsets(m: &mut Mem, s: u32) {
    let recs = m.u32(s + 0x1c);
    let mut prev = recs + 4 * REC;
    let mut rec = recs + 5 * REC;
    let mut code = m.i16(rec + 0xc);
    while code != 0xff {
        if m.i16(rec + 0x10) != 0 && features(m, prev) & 2 != 0 {
            or_flags(m, prev, 0x10);
            let f = features(m, prev);
            let mut q;
            if f & 0x8000 == 0 {
                q = prev;
                if f & 0x30000 != 0 {
                    q = prev - REC;
                }
                if features(m, q) & 0x180_0000 != 0 {
                    or_flags(m, q, 0x10);
                    q -= REC;
                }
            } else {
                q = prev - REC;
            }
            let f2 = features(m, q);
            if f2 & 0x4000 != 0 || (f2 & 0x1000 != 0 && f2 & 0x800_0000 == 0) {
                or_flags(m, q, 0x10);
            }
        }
        prev += REC;
        code = m.i16(rec + 0x26);
        rec += REC;
    }
}

/// `3de0`: flag 0x100 on the phoneme after the first boundary, up to the
/// first phoneme with feature bit 1.
pub fn mark_after_boundary(m: &mut Mem, s: u32) {
    let recs = m.u32(s + 0x1c);
    let mut f = features(m, recs + 4 * REC);
    let mut rec = recs + 5 * REC;
    let mut code = m.i16(rec + 0xc);
    loop {
        if code == 0xff {
            return;
        }
        let boundary = f & 0x400_0000;
        f = features(m, rec);
        if boundary != 0 {
            or_flags(m, rec, 0x100);
        }
        if f & 1 != 0 {
            return;
        }
        code = m.i16(rec + 0x26);
        rec += REC;
    }
}

/// Bit masks selected by the allophone rules' feature tests.
const RULE_MASKS: u32 = 0x1c0122a8;

/// `5a00`: left/target/right phoneme codes (0xff = any).
fn rule_codes_match(m: &Mem, rule: u32, rec: u32) -> bool {
    let target = m.u8(rule + 4);
    if target != 0xff && m.u16(rec + 0xc) != target as u16 {
        return false;
    }
    let left = m.u8(rule + 3);
    let right = m.u8(rule + 5);
    (left == 0xff || m.u16(rec - REC + 0xc) == left as u16) && (right == 0xff || m.u16(rec + 0x26) == right as u16)
}

/// `5a60`: up to five feature/stress tests walking forward from the
/// previous phoneme.
fn rule_features_match(m: &Mem, rule: u32, rec: u32, mode: u32) -> bool {
    let mut ok = true;
    let after = rec + REC;
    let mut p = rec;
    let mut fl = flags(m, rec - REC);
    let mut feat = features(m, rec - REC);
    for i in 0..5 {
        if !ok {
            break;
        }
        let t = m.u8(rule + 6 + i);
        if t != 0xff {
            let fails = match t & 0x60 {
                0x00 => fl & 0x10 != 0,
                0x20 => fl & 0x10 == 0,
                0x40 => m.u32(RULE_MASKS + (t as u32 & 0x1f) * 4) & feat != 0,
                _ => m.u32(RULE_MASKS + (t as u32 & 0x1f) * 4) & feat == 0,
            };
            if fails {
                ok = false;
            }
        }
        if t & 0x80 != 0 {
            feat = features(m, p);
            fl = flags(m, p);
            if after == p && m.u8(rule + 0xb) & 0x80 != 0 && m.i16(p + 0xc) == 0 {
                // Look across a word space.
                fl = m.u32(p + 0x30);
                feat = m.u32(m.u32(m.u32(p + 0x22) + 0x1c).wrapping_add((m.i16(p + 0x26) as i32 * 4) as u32));
                p += REC;
            }
            p += REC;
        }
    }
    let kind = m.u8(rule + 0xb);
    if kind & 0x10 != 0 {
        if kind & 0x1f != 0x11 {
            return false;
        }
        if mode == 0 {
            ok = false;
        }
    }
    ok
}

/// `5c00`: insert a phoneme before `rec`, shifting `n` records up.
fn rule_insert_before(m: &mut Mem, rule: u32, rec: u32, n: i32) -> bool {
    let code = m.u8(rule) as u16;
    if code == 0xff {
        return false;
    }
    let mut k = n;
    let mut from = (rec as i32 + (n - 1) * REC as i32) as u32;
    let mut to = (rec as i32 + n * REC as i32) as u32;
    while k != 0 {
        k -= 1;
        copy_rec(m, from, to);
        from = from.wrapping_sub(REC);
        to = to.wrapping_sub(REC);
    }
    m.set_u32(rec + 0x16, 0);
    m.set_u16(rec + 0x10, 0);
    m.set_u16(rec + 0xc, code);
    m.set_u32(rec + 8, m.u32(to + 8));
    let table = m.u32(to + 4);
    m.set_u32(rec + 4, table);
    m.set_u32(rec + 0x12, m.u32((code as i16 as i32 * REC as i32 + 2) as u32 + table));
    m.set_u32(rec, 0);
    true
}

/// `5cb0`: replace the phoneme.
fn rule_replace(m: &mut Mem, rule: u32, rec: u32) {
    let code = m.u8(rule + 1) as u16;
    if code == 0xff {
        return;
    }
    m.set_u16(rec + 0xc, code);
    let table = m.u32(rec + 4);
    m.set_u32(rec + 0x12, m.u32((code as i16 as i32 * REC as i32 + 2) as u32 + table));
}

/// `5d40`: insert a phoneme after `rec`.
fn rule_insert_after(m: &mut Mem, rule: u32, rec: u32, n: i32) -> bool {
    let code = m.u8(rule + 2) as u16;
    if code == 0xff {
        return false;
    }
    let mut k = n;
    let mut from = (rec as i32 + (n - 1) * REC as i32) as u32;
    let mut to = (rec as i32 + n * REC as i32) as u32;
    loop {
        k -= 1;
        if k == 0 {
            break;
        }
        copy_rec(m, from, to);
        from = from.wrapping_sub(REC);
        to = to.wrapping_sub(REC);
    }
    m.set_u16(rec + 0x26, code);
    m.set_u16(rec + 0x2a, 0);
    m.set_u32(rec + 0x30, 0);
    m.set_u32(rec + 0x22, m.u32(to + 8));
    let table = m.u32(to + 4);
    m.set_u32(rec + 0x1e, table);
    m.set_u32(rec + 0x2c, m.u32((code as i16 as i32 * REC as i32 + 2) as u32 + table));
    m.set_u32(rec + 0x1a, 0);
    true
}

/// `5cf0`: a rule with all three outputs 0xff deletes the phoneme.
fn rule_delete(m: &mut Mem, rule: u32, rec: u32, n: i32) -> bool {
    if m.u8(rule) != 0xff || m.u8(rule + 1) != 0xff || m.u8(rule + 2) != 0xff {
        return false;
    }
    let mut k = n;
    let mut to = rec;
    let mut from = rec;
    loop {
        k -= 1;
        if k == 0 {
            break;
        }
        copy_rec(m, from + REC, to);
        to += REC;
        from += REC;
    }
    true
}

/// `5910`: apply the language's allophone rules (16 bytes each:
/// insert-before, replace, insert-after, left, target, right, five
/// feature tests, flags) to every phoneme.
pub fn apply_allophones(m: &mut Mem, s: u32) {
    let mode = m.u32(s + 0x4e) & 0x10;
    let mut n = m.u16(s + 0xe) as i32 - 5;
    let mut rec = m.u32(s + 0x1c) + 5 * REC;
    let mut code = m.i16(rec + 0xc);
    while code != 0xff {
        let mut rule = m.u32(m.u32(rec + 8) + 0x24);
        loop {
            let mut last = m.u8(rule + 0xb) & 0x20 != 0;
            if rule_codes_match(m, rule, rec)
                && m.u8(rule + 0xb) & 0x12 == 0
                && rule_features_match(m, rule, rec, mode)
            {
                if rule_insert_before(m, rule, rec, n) {
                    n += 1;
                    m.set_u16(s + 0xe, m.u16(s + 0xe).wrapping_add(1));
                }
                rule_replace(m, rule, rec);
                if rule_insert_after(m, rule, rec, n) {
                    rec += REC;
                    m.set_u16(s + 0xe, m.u16(s + 0xe).wrapping_add(1));
                }
                if rule_delete(m, rule, rec, n) {
                    rec -= REC;
                    m.set_u16(s + 0xe, m.u16(s + 0xe).wrapping_sub(1));
                }
                if m.u8(rule + 0xb) & 0x40 == 0 {
                    last = true;
                }
            }
            rule += 0x10;
            if last {
                break;
            }
        }
        n -= 1;
        code = m.i16(rec + 0x26);
        rec += REC;
    }
}

/// `c6d0`: syllabification.  Sets per-record flags: 0x80 syllable nucleus
/// start, 0x40/0x20 syllable membership, 8 word end, 4 phrase-final domain.
pub fn syllabify(m: &mut Mem, s: u32) {
    let recs = m.u32(s + 0x1c);
    let mut start = recs + 5 * REC; // iVar12
    let mut acc: u32 = 0; // uVar8
    let mut split: i32 = -1; // iVar10
    let mut p1 = recs + 6 * REC; // iVar1: one past the current record
    let mut seen_vowel = false; // bVar5
    let mut code = m.i16(recs + 5 * REC + 0xc); // sVar3
    let mut q = start; // iVar13
    let mut count: i32 = 0; // iVar11
    let at = |base: u32, k: i32| (base as i32 + k * REC as i32) as u32;
    while code != 0xff {
        let mut i9 = count + 1;
        let kind = features(m, p1 - REC) & 0x1400_0000;
        if kind == 0x400_0000 {
            let c4 = m.i16(at(p1, -i9) + 0xc);
            if c4 == 0x1e || c4 == 0x1d {
                split -= 1;
                q += REC;
                let carry = flags(m, start - REC) & 0x60;
                or_flags(m, start, carry);
                start += REC;
                i9 = count;
            }
            if split > 0 {
                q = at(q, split);
            }
            let mut n = (i9 - 1) - split;
            or_flags(m, q, 8);
            let mut i7;
            let mark = if code != 0 {
                true
            } else {
                i7 = at(q, n);
                m.u8(i7 - 3) & 0x10 != 0
            };
            if mark {
                i7 = q;
                while n > 0 {
                    or_flags(m, i7, 4);
                    q = i7 + REC;
                    n -= 1;
                    i7 = q;
                }
            } else {
                i7 = at(q, n);
            }
            or_flags(m, start, 0x80);
            let mut k = i9 - 1;
            while k != 0 {
                or_flags(m, start, acc);
                start += REC;
                k -= 1;
            }
            acc = 0;
            i9 = 0;
            start += REC;
            q = i7 + REC;
            seen_vowel = false;
        } else if kind == 0x1000_0000 && code != 0x1e && code != 0x1d {
            if seen_vowel {
                let c = m.i16(at(p1, -i9) + 0xc);
                if c == 0x1e || c == 0x1d {
                    split -= 1;
                    q += REC;
                    let carry = flags(m, start - REC) & 0x60;
                    or_flags(m, start, carry);
                    start += REC;
                    i9 = count;
                }
                or_flags(m, start, 0x80);
                split = (split + i9) >> 1;
                i9 -= split;
                q = at(q, split);
                while split != 0 {
                    or_flags(m, start, acc | 0x40);
                    start += REC;
                    split -= 1;
                }
                acc = 0x40;
            } else {
                seen_vowel = true;
            }
            split = i9 - 1;
            acc |= flags(m, at(start, split)) & 0x20;
        }
        code = m.i16(p1 + 0xc);
        p1 += REC;
        count = i9;
    }
}
