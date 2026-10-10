//! Rule interpreters: letter-to-sound rules (`206860` / `4062f0`), the
//! built-in exception dictionary (`207230` / `406cc0`), accent folding
//! (`2070b0`, `207180`) and the default stress rules (English `2077b0`,
//! Spanish `407240`).
//!
//! Rules are plain text in the DLLs: `left[match]right=PHONEMES` followed by
//! '\' (state bit 1) or '`' (state bit 2, letter-to-sound rules only).  The
//! contexts use metacharacters (class bit 0x400): ' ' word boundary, '#'
//! vowel, '+' front vowel, ':' any consonants, '^' consonant, '.' voiced
//! consonant, '&' sibilant, '@' T/S/... class, '%' suffix, '<' punctuation
//! or digit, '>' not punctuation, '?' digit, 'b' blanks.

use super::{Lang, T_CUR, T_FLAGS, T_OUT, T_ROOM, T_SRC, T_STATE, isspace, strlen, strncat};
use crate::mem::Mem;

/// `207180`: accented letters that rules spell out literally.
pub fn is_accented(c: u8) -> bool {
    matches!(c, 0xc1 | 0xc9 | 0xcd | 0xd1 | 0xd3 | 0xda | 0xe1 | 0xe9 | 0xed | 0xf1 | 0xf3 | 0xfa | 0xfc)
}

/// `2070b0`: fold an accented vowel to its base letter (only for chars
/// with the vowel class bit, so Ñ/ñ stay).
pub fn fold(m: &Mem, l: &Lang, c: u8) -> u8 {
    if l.cls(m, c) & 0x40 != 0 {
        match c {
            0xc1 | 0xe1 => b'A',
            0xc9 | 0xe9 => b'E',
            0xcd | 0xed => b'I',
            0xd1 | 0xf1 => b'N',
            0xd3 | 0xf3 => b'O',
            0xda | 0xfa | 0xfc => b'U',
            _ => c,
        }
    } else {
        c
    }
}

/// Compare a literal rule character with a text character.
#[inline]
fn lit_eq(m: &Mem, l: &Lang, rc: u8, tc: u8) -> bool {
    let tc = if is_accented(rc) { tc } else { fold(m, l, tc) };
    rc == tc
}

/// Length matched by the '%' suffix metacharacter at `t` (None: no suffix).
fn suffix(m: &Mem, t: u32) -> Option<u32> {
    let c0 = m.u8(t);
    if c0 == b'E' {
        let c1 = m.u8(t + 1);
        if c1 == b'R' {
            return Some(2 + (m.u8(t + 2) == b'S') as u32);
        }
        if c1 == b'L' && m.u8(t + 2) == b'Y' {
            return Some(3);
        }
        if c1 == b'S' || c1 == b'D' {
            return Some(2);
        }
        return Some(1);
    }
    if c0 == b'I' && m.u8(t + 1) == b'N' && m.u8(t + 2) == b'G' {
        return Some(3 + (m.u8(t + 3) == b'S') as u32);
    }
    None
}

#[inline]
fn step(p: u32, d: i32) -> u32 {
    p.wrapping_add(d as u32)
}

/// Letter-to-sound context match (`206978`): from rule position `rp` and
/// text position `tp` in direction `d`.  Ok(position of the '\', '`' or
/// '=' that ended it), Err(position of the rule char that failed).
fn lts_context(m: &Mem, l: &Lang, mut rp: u32, mut tp: u32, d: i32) -> Result<u32, u32> {
    loop {
        let rc = m.u8(rp);
        if rc == b'\\' || rc == b'`' || rc == b'=' {
            return Ok(rp);
        }
        let tc = m.u8(tp);
        if l.cls(m, rc) & 0x400 == 0 {
            if !lit_eq(m, l, rc, tc) {
                return Err(rp);
            }
            tp = step(tp, d);
        } else {
            match rc {
                b' ' => {
                    if l.cls(m, tc) & 0x80 != 0 {
                        return Err(rp);
                    }
                    loop {
                        tp = step(tp, d);
                        if !isspace(m.u8(tp)) {
                            break;
                        }
                    }
                }
                b'#' => {
                    if l.cls(m, tc) & 0x40 == 0 {
                        return Err(rp);
                    }
                    tp = step(tp, d);
                }
                b'%' => {
                    let Some(k) = suffix(m, tp) else { return Err(rp) };
                    tp = tp.wrapping_add(k);
                    if l.cls(m, m.u8(tp)) & 0x80 != 0 {
                        return Err(rp);
                    }
                }
                b'&' => {
                    if tc == b'H' {
                        let p = m.u8(tp.wrapping_sub(1));
                        if p != b'C' && p != b'S' {
                            return Err(rp);
                        }
                        tp = step(tp, 2 * d);
                    } else {
                        if l.cls(m, tc) & 0x10 == 0 {
                            return Err(rp);
                        }
                        tp = step(tp, d);
                    }
                }
                b'+' => {
                    if l.cls(m, tc) & 0x100 == 0 {
                        return Err(rp);
                    }
                    tp = step(tp, d);
                }
                b'.' => {
                    if l.cls(m, tc) & 0x28 != 0x28 {
                        return Err(rp);
                    }
                    tp = step(tp, d);
                }
                b':' => {
                    while l.cls(m, m.u8(tp)) & 0x20 != 0 {
                        tp = step(tp, d);
                    }
                }
                b'<' => {
                    if isspace(tc) || l.cls(m, tc) & 3 == 0 {
                        return Err(rp);
                    }
                    tp = step(tp, d);
                }
                b'>' => {
                    if l.cls(m, tc) & 1 != 0 {
                        return Err(rp);
                    }
                    tp = step(tp, d);
                }
                b'?' => {
                    if l.cls(m, tc) & 2 == 0 {
                        return Err(rp);
                    }
                    tp = step(tp, d);
                }
                b'@' => {
                    if tc == b'H' {
                        let p = m.u8(tp.wrapping_sub(1));
                        if p != b'T' && p != b'C' && p != b'S' {
                            return Err(rp);
                        }
                        tp = step(tp, 2 * d);
                    } else {
                        if l.cls(m, tc) & 4 == 0 {
                            return Err(rp);
                        }
                        tp = step(tp, d);
                    }
                }
                b'^' => {
                    if l.cls(m, tc) & 0x20 == 0 {
                        return Err(rp);
                    }
                    tp = step(tp, d);
                }
                b'b' => {
                    if !isspace(tc) {
                        return Err(rp);
                    }
                    loop {
                        tp = step(tp, d);
                        if !isspace(m.u8(tp)) {
                            break;
                        }
                    }
                }
                _ => return Err(rp),
            }
        }
        rp = step(rp, d);
    }
}

/// `206860` / `4062f0`: letter-to-sound rules for the word at T+8, up to
/// the next space or digit; a character that is not an ASCII letter (or
/// Ä/Ö/Ü/ß) is converted with the "other" rules and ends the call.
/// Returns 1 if the output is full (state cleared).
pub fn letters(m: &mut Mem, l: &Lang, t: u32) -> i32 {
    let mut dest = m.u32(t + T_OUT);
    let mut other = false;
    let mut st = m.u32(t + T_STATE);
    let mut w = m.u32(t + T_CUR);
    loop {
        let c = m.u8(w);
        if c == b' ' || c == 0 {
            break;
        }
        let cls = l.cls(m, c);
        if cls & 2 != 0 || other {
            break;
        }
        let mut rule = if cls & 0x80 == 0 {
            other = true;
            m.u32(l.lts_other)
        } else {
            match c {
                0xc4 => m.u32(l.lts_c4),
                0xd6 => m.u32(l.lts_d6),
                0xdc => m.u32(l.lts_dc),
                0xdf => m.u32(l.lts_df),
                _ if c < 0x7b => m.u32(l.lts + 4 * c as u32),
                _ => {
                    other = true;
                    m.u32(l.lts_other)
                }
            }
        };
        // Find the first rule that matches (`206915`).
        let (eq, next) = loop {
            let mut lb = rule;
            while m.u8(lb) != b'[' {
                lb += 1;
            }
            let mut r = lb + 1;
            let mut tp = w;
            let matched = loop {
                let rc = m.u8(r);
                if rc == b']' {
                    break true;
                }
                let tc = m.u8(tp);
                tp += 1;
                r += 1;
                if !lit_eq(m, l, rc, tc) {
                    break false;
                }
            };
            if !matched {
                rule = r;
                continue;
            }
            if m.u8(r - 1) == b'[' {
                tp += 1;
            }
            let fail = match lts_context(m, l, lb.wrapping_sub(1), w.wrapping_sub(1), -1) {
                Err(f) => Some(f),
                Ok(_) => match lts_context(m, l, r + 1, tp, 1) {
                    Err(f) => Some(f),
                    Ok(eq) => break (eq, tp),
                },
            };
            // Skip to the end of this rule.
            let mut p = fail.unwrap().wrapping_add(1);
            while m.u8(p) != b'\\' && m.u8(p) != b'`' {
                p += 1;
            }
            rule = p;
        };
        // Phonemes up to the terminator.
        let start = eq + 1;
        let mut n: i32 = 0;
        let mut fl = 4;
        let mut q = start;
        loop {
            let b = m.u8(q);
            q += 1;
            if b == b'\\' {
                fl |= 1;
                break;
            }
            if b == b'`' {
                fl |= 2;
                break;
            }
            n += 1;
            if b == b'.' || b == b'?' {
                fl |= 8;
            }
        }
        if m.i32(t + T_ROOM) < n {
            m.set_u32(t + T_STATE, 0);
            return 1;
        }
        if m.u8(t + T_FLAGS) & 0x40 == 0 && m.u8(w) == b'?' && n == 1 {
            strncat(m, dest, l.qmark, 1);
        } else {
            strncat(m, dest, start, n as i16 as i32);
        }
        m.set_i32(t + T_ROOM, m.i32(t + T_ROOM) - n);
        dest += strlen(m, dest);
        m.set_u32(t + T_OUT, dest);
        st = fl;
        m.set_u32(t + T_STATE, st);
        let src = w.wrapping_add(m.u32(t + T_SRC).wrapping_sub(m.u32(t + T_CUR)));
        m.set_u32(t + T_SRC, src);
        m.set_u32(t + T_CUR, w);
        w = next;
    }
    m.set_u8(dest, 0);
    m.set_u32(t + T_OUT, dest);
    m.set_u32(t + T_STATE, st);
    let src = w.wrapping_add(m.u32(t + T_SRC).wrapping_sub(m.u32(t + T_CUR)));
    m.set_u32(t + T_SRC, src);
    m.set_u32(t + T_CUR, w);
    0
}

/// Dictionary context match (`20733b`): like the letter-to-sound one, but
/// ' ' matches a single non-letter, '+' is the same as '#', and only '\'
/// and '=' end it.
fn dict_context(m: &Mem, l: &Lang, mut rp: u32, mut tp: u32, d: i32) -> Result<u32, u32> {
    loop {
        let rc = m.u8(rp);
        if rc == b'\\' || rc == b'=' {
            return Ok(rp);
        }
        let tc = m.u8(tp);
        if l.cls(m, rc) & 0x400 == 0 {
            if !lit_eq(m, l, rc, tc) {
                return Err(rp);
            }
            tp = step(tp, d);
        } else {
            match rc {
                b' ' => {
                    if l.cls(m, tc) & 0x80 != 0 {
                        return Err(rp);
                    }
                    tp = step(tp, d);
                }
                b'#' | b'+' => {
                    if l.cls(m, tc) & 0x40 == 0 {
                        return Err(rp);
                    }
                    tp = step(tp, d);
                }
                b'%' => {
                    let Some(k) = suffix(m, tp) else { return Err(rp) };
                    tp = tp.wrapping_add(k);
                    if l.cls(m, m.u8(tp)) & 0x80 != 0 {
                        return Err(rp);
                    }
                }
                b'&' => {
                    if tc == b'H' {
                        let p = m.u8(tp.wrapping_sub(1));
                        if p != b'C' && p != b'S' {
                            return Err(rp);
                        }
                        tp = step(tp, 2 * d);
                    } else {
                        if l.cls(m, tc) & 0x10 == 0 {
                            return Err(rp);
                        }
                        tp = step(tp, d);
                    }
                }
                b'.' => {
                    if l.cls(m, tc) & 0x28 != 0x28 {
                        return Err(rp);
                    }
                    tp = step(tp, d);
                }
                b':' => {
                    while l.cls(m, m.u8(tp)) & 0x20 != 0 {
                        tp = step(tp, d);
                    }
                }
                b'>' => {
                    if l.cls(m, tc) & 1 != 0 {
                        return Err(rp);
                    }
                    tp = step(tp, d);
                }
                b'?' => {
                    if l.cls(m, tc) & 2 == 0 {
                        return Err(rp);
                    }
                    tp = step(tp, d);
                }
                b'@' => {
                    if tc == b'H' {
                        let p = m.u8(tp.wrapping_sub(1));
                        if p != b'T' && p != b'C' && p != b'S' {
                            return Err(rp);
                        }
                        tp = step(tp, 2 * d);
                    } else {
                        if l.cls(m, tc) & 4 == 0 {
                            return Err(rp);
                        }
                        tp = step(tp, d);
                    }
                }
                b'^' => {
                    if l.cls(m, tc) & 0x20 == 0 {
                        return Err(rp);
                    }
                    tp = step(tp, d);
                }
                // The original loops forever on any other metacharacter.
                _ => panic!("dictionary metacharacter {rc:#x} at {rp:#x}"),
            }
        }
        rp = step(rp, d);
    }
}

/// `207230` / `406cc0`: the exception dictionary.  Entries are sorted by
/// their second character; each list ends with "[*".  Matched words are
/// output (state 2) and matching continues after them.  Returns 1 if the
/// output is full.
pub fn exceptions(m: &mut Mem, l: &Lang, t: u32) -> i32 {
    let mut dest = m.u32(t + T_OUT);
    let mut unsorted = false;
    let mut w = m.u32(t + T_CUR);
    'word: loop {
        let c = m.u8(w);
        let cls = l.cls(m, c);
        let mut rules = if cls & 0x80 == 0 {
            unsorted = true;
            if cls & 2 != 0 { m.u32(l.dict_digit) } else { m.u32(l.dict_other) }
        } else if c < 0x7b {
            m.u32(l.dict + 4 * c as u32)
        } else {
            unsorted = true;
            m.u32(l.dict_other)
        };
        loop {
            let mut lb = rules;
            while m.u8(lb) != b'[' {
                lb += 1;
            }
            let mut r = lb + 1;
            if unsorted {
                if m.u8(r) == b'*' {
                    break 'word;
                }
            } else if (m.u8(w + 1) as i8) < (m.u8(lb + 2) as i8) || m.u8(r) == b'*' {
                break 'word;
            }
            let mut tp = w;
            let matched = loop {
                let rc = m.u8(r);
                if rc == b']' {
                    break true;
                }
                let tc = m.u8(tp);
                r += 1;
                tp += 1;
                if !lit_eq(m, l, rc, tc) {
                    break false;
                }
            };
            if !matched {
                rules = r;
                continue;
            }
            let fail = match dict_context(m, l, lb.wrapping_sub(1), w.wrapping_sub(1), -1) {
                Err(f) => Some(f),
                Ok(_) => match dict_context(m, l, r + 1, tp, 1) {
                    Err(f) => Some(f),
                    Ok(eq) => {
                        let start = eq + 1;
                        m.set_u32(t + T_STATE, 2);
                        let mut n: i32 = 0;
                        while m.u8(start + n as u32) != b'\\' {
                            n += 1;
                        }
                        if m.i32(t + T_ROOM) < n {
                            return 1;
                        }
                        strncat(m, dest, start, n as i16 as i32);
                        dest = dest.wrapping_add(n as u32);
                        m.set_i32(t + T_ROOM, m.i32(t + T_ROOM) - n);
                        let src = w.wrapping_add(m.u32(t + T_SRC).wrapping_sub(m.u32(t + T_CUR)));
                        m.set_u32(t + T_SRC, src);
                        m.set_u32(t + T_OUT, dest);
                        m.set_u32(t + T_CUR, w);
                        w = tp;
                        continue 'word;
                    }
                },
            };
            let mut p = fail.unwrap().wrapping_add(1);
            while m.u8(p) != b'\\' {
                p += 1;
            }
            rules = p;
        }
    }
    m.set_u8(dest, 0);
    m.set_u32(t + T_OUT, dest);
    let src = w.wrapping_add(m.u32(t + T_SRC).wrapping_sub(m.u32(t + T_CUR)));
    m.set_u32(t + T_SRC, src);
    m.set_u32(t + T_CUR, w);
    0
}

/// "IYIHEHAEAAAOUHAHEREYAYOYAWOWUWOHIXAX": stressable vowels (the last two
/// only with flag 0x02).
const EN_VOWELS: u32 = 0x1c24c940;

/// `2077b0`: if the word just output has no stress digit (other than 1/2),
/// put '5' after its first vowel.  Returns 1 if the output is full.
pub fn stress_en(m: &mut Mem, l: &Lang, t: u32) -> i32 {
    let mut p = m.u32(t + T_OUT);
    while m.u8(p) != b' ' {
        let c = m.u8(p);
        if l.cls(m, c) & 2 != 0 && c != b'1' && c != b'2' {
            return 0;
        }
        p = p.wrapping_sub(1);
    }
    p += 1;
    let n = if m.u32(t + T_FLAGS) & 2 == 0 { 0x10 } else { 0x12 };
    loop {
        if m.u8(p) == 0 {
            return 0;
        }
        for i in 0..n {
            let v = EN_VOWELS + 2 * i;
            if m.u8(v) == m.u8(p) && m.u8(p + 1) == m.u8(v + 1) {
                p += 2;
                if l.cls(m, m.u8(p)) & 2 != 0 {
                    return 0;
                }
                return insert_5(m, t, p);
            }
        }
        p += 1;
    }
}

/// Insert '5' at `p` in the output and move T+4 to the new end.
fn insert_5(m: &mut Mem, t: u32, mut p: u32) -> i32 {
    if m.i32(t + T_ROOM) < 1 {
        return 1;
    }
    m.set_i32(t + T_ROOM, m.i32(t + T_ROOM) - 1);
    let mut carry = b'5';
    while m.u8(p) != 0 {
        let c = m.u8(p);
        m.set_u8(p, carry);
        p += 1;
        carry = c;
    }
    m.set_u8(p, carry);
    p += 1;
    m.set_u8(p, 0);
    m.set_u32(t + T_OUT, p);
    0
}

/// "IYEHAAEYAYOYOHUW": Spanish vowels (pairs at +0..+0x10).
const ES_VOWELS: u32 = 0x1c40e438;

/// `407240`: Spanish default stress.  If the word just output has no
/// stress digit (other than 1/2), find its last letter: after N, S or a
/// vowel other than AY/OY the second-to-last vowel gets '5' (an IY right
/// before the last vowel is skipped; with no earlier vowel the last one
/// found gets it), otherwise the last vowel.  A word with no letter of its own continues the
/// search into the previous words' output.  Transliterated from the assembly.
pub fn stress_es(m: &mut Mem, l: &Lang, t: u32) -> i32 {
    let v = ES_VOWELS + 1;
    let vend = ES_VOWELS + 0x11;
    let is_pair = |m: &Mem, e: u32, s: u32| m.u8(e) == m.u8(s) && m.u8(e - 1) == m.u8(s.wrapping_sub(1));
    let out = m.u32(t + T_OUT);
    let mut edi = out;
    let mut esi = out;
    let mut ecx = 0;
    let dl = m.u8(edi);
    if dl != b' ' {
        loop {
            let al = m.u8(edi);
            if l.cls(m, al) & 2 != 0 && al != b'1' && al != b'2' {
                return 0;
            }
            edi = edi.wrapping_sub(1);
            if m.u8(edi) == b' ' {
                break;
            }
        }
    }
    if l.cls(m, dl) & 0x80 == 0 {
        loop {
            esi = esi.wrapping_sub(1);
            if l.cls(m, m.u8(esi)) & 0x80 != 0 {
                break;
            }
        }
    }
    let al = m.u8(esi);
    let mut penult = al == b'N' || al == b'S';
    if !penult {
        let mut e = v;
        while e < vend {
            if m.u8(e) == al
                && m.u8(esi.wrapping_sub(1)) == m.u8(e - 1)
                && e != ES_VOWELS + 0xb
                && e != ES_VOWELS + 9
            {
                penult = true;
                break;
            }
            e += 2;
        }
    }
    if !penult {
        if al == b' ' {
            return 0;
        }
        // Stress the last vowel.
        'found: loop {
            let mut e = v;
            while e < vend {
                if is_pair(m, e, esi) {
                    ecx = 1;
                    break 'found;
                }
                e += 2;
            }
            esi = esi.wrapping_sub(1);
            if m.u8(esi) == b' ' {
                return 0;
            }
        }
    } else {
        // Second-to-last vowel (`407316`).
        let mut last = 0u32; // edi: where the scan ends up (garbage at first)
        let mut prev = 0u32; // ebx
        let mut done = false;
        'scan: loop {
            let mut e = v;
            while e < vend {
                if is_pair(m, e, esi) {
                    last = esi;
                    ecx += 1;
                    if ecx >= 2 && (e != v || ecx != 2 || prev.wrapping_sub(esi) != 2) {
                        done = true;
                        break 'scan;
                    }
                    prev = esi;
                    esi = esi.wrapping_sub(1);
                }
                e += 2;
            }
            esi = esi.wrapping_sub(1);
            if m.u8(esi) == b' ' {
                break;
            }
        }
        if !done {
            esi = last;
        }
    }
    if ecx == 0 {
        return 0;
    }
    esi += 1;
    if l.cls(m, m.u8(esi)) & 2 != 0 {
        return 0;
    }
    insert_5(m, t, esi)
}
