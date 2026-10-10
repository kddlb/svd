//! Sentence splitting (`c500`) and the phoneme-string parser (`4a10`) with
//! its embedded-command parser (`5180`, `5230`, `52d0`, `5310`, `56e0`,
//! `5700`, `5720`, `57e0`).
//!
//! Phoneme records are 26 bytes:
//!   +0x00 u32  command list (6-byte entries {code, arg, pos}, 0x1e ends)
//!   +0x04 u32  phoneme table (gender-specific)
//!   +0x08 u32  language structure
//!   +0x0c i16  phoneme code (0xff ends the array)
//!   +0x0e u16  duration (ms)
//!   +0x10 u16  stress
//!   +0x12 u32  phoneme features (from the table)
//!   +0x16 u32  runtime flags

use crate::lang::{CURRENT_LANG, TIBASE_LANG_DE, TIBASE_LANG_EN, TIBASE_LANG_ES};
use crate::mem::Mem;

pub const REC: u32 = 0x1a;

/// Per-character tables of {next char, code} pairs for chars 0x20..0x5b.
const CHAR_MAP: u32 = 0x1c012a68;
/// Embedded command keywords: 59 entries of {char *name, i16 code}.
const KEYWORDS: u32 = 0x1c0126b0;
const KEYWORDS_END: u32 = 0x1c012812;
const KEYWORD_COUNT: i32 = 0x3b;
/// Semitone offsets of the notes a..g.
const NOTES: u32 = 0x1c012b58;
/// Keyword argument lists (pointer arrays ending with "").
const LIST_VOICES: u32 = 0x1c012830;
const LIST_TRACT: u32 = 0x1c012888;
const LIST_GLOT: u32 = 0x1c0128a0;
const LIST_VOICING: u32 = 0x1c0128c8;
const LIST_F0STYLE: u32 = 0x1c0128d8;
const LIST_SPEAK: u32 = 0x1c0128f0;
const LIST_ONOFF: u32 = 0x1c012908;
const LIST_LANGUAGES: u32 = 0x1c012918;

/// Errors returned by `parse`.
pub const ERR_PHONEME: i32 = 0x1b59;
pub const ERR_COMMAND: i32 = 0x1b67;
/// `parse` result when the phrase was empty (only padding).
pub const EMPTY_PHRASE: i32 = 1000;

fn isdigit(c: u8) -> bool {
    c.is_ascii_digit()
}

fn strlen(m: &Mem, mut p: u32) -> u32 {
    let start = p;
    while m.u8(p) != 0 {
        p += 1;
    }
    p - start
}

/// `strncmp(a, b, n) == 0`
fn prefix_eq(m: &Mem, a: u32, b: u32, n: u32) -> bool {
    for k in 0..n {
        let (x, y) = (m.u8(a + k), m.u8(b + k));
        if x != y {
            return false;
        }
        if x == 0 {
            return true;
        }
    }
    true
}

/// `c500`: advance S+8 past the previous sentence and measure the next one
/// (up to and including '.' or '?').  S+0x14 = length, S+0x18 = number of
/// characters outside '@' tokens (sizes the record array).  Returns the
/// length; 0 means there are no more sentences.
pub fn split_sentence(m: &mut Mem, s: u32) -> i32 {
    let mut p = m.u32(s + 0x14).wrapping_add(m.u32(s + 8));
    m.set_u32(s + 8, p);
    let (mut len, mut count, mut counting) = (0i32, 0i32, true);
    loop {
        let c = m.u8(p);
        p += 1;
        if c == 0 {
            break;
        }
        len += 1;
        if c == b'@' {
            counting = false;
        }
        if c == b' ' {
            counting = true;
        }
        if counting {
            count += 1;
        }
        if c == b'.' || c == b'?' {
            break;
        }
    }
    m.set_i32(s + 0x14, len);
    m.set_i32(s + 0x18, count);
    len
}

/// `5720`: signed decimal terminated by ';', '}' or ' ' (a trailing '%'
/// returns the negated value, meaning "relative").  -0x8000 on error.
pub fn number(m: &Mem, mut p: u32) -> i16 {
    let c = m.u8(p);
    if c == 0 {
        return -0x8000;
    }
    let neg = c == b'-';
    if neg || c == b'+' {
        p += 1;
    }
    let mut v: i16 = 0;
    let mut c;
    loop {
        c = m.u8(p);
        p += 1;
        if !isdigit(c) {
            break;
        }
        v = v.wrapping_mul(10).wrapping_add(c as i8 as i16 - 0x30);
    }
    if neg {
        v = v.wrapping_neg();
    }
    if c != b';' && c != b'}' && c != b' ' {
        if c == b'%' && !neg {
            return v.wrapping_neg();
        }
        return -0x8000;
    }
    v
}

/// `56e0`: required number (missing token = error).
fn number_req(m: &Mem, p: u32) -> i16 {
    if p == 0 { -0x8000 } else { number(m, p) }
}

/// `5700`: optional number (missing token = 0).
fn number_opt(m: &Mem, p: u32) -> i16 {
    if p == 0 { 0 } else { number(m, p) }
}

/// `57e0`: index of the first keyword in `list` that prefixes `p`.
fn keyword(m: &Mem, p: u32, mut list: u32) -> i16 {
    if p == 0 {
        return -0x8000;
    }
    let mut i: i16 = 0;
    loop {
        let name = m.u32(list);
        let n = strlen(m, name);
        if n == 0 {
            return -0x8000;
        }
        if prefix_eq(m, p, name, n) {
            return i;
        }
        list += 4;
        i += 1;
    }
}

/// `5230`: split one command into up to three space-separated tokens.
fn tokenize(m: &Mem, start: u32) -> [u32; 4] {
    let mut t = [start, 0, 0, 0];
    if start == 0 {
        return t;
    }
    let mut p = start;
    for k in 1..=3 {
        let mut c;
        loop {
            c = m.u8(p);
            if c != b' ' {
                break;
            }
            p += 1;
        }
        if c == b';' || c == b'}' || c == 0 {
            return t;
        }
        t[k] = p;
        if k == 3 {
            return t;
        }
        loop {
            c = m.u8(p);
            p += 1;
            if c == 0 || c == b';' || c == b'}' {
                return t;
            }
            if c == b' ' {
                break;
            }
        }
    }
    t
}

/// `52d0`: start of the next command: after ';', or after "} {" when
/// another brace group follows immediately; 0 otherwise.
fn next_command(m: &Mem, mut p: u32) -> u32 {
    if p == 0 {
        return 0;
    }
    loop {
        let c = m.u8(p);
        p += 1;
        if c == 0 {
            return 0;
        }
        if c == b';' {
            return p;
        }
        if c == b'}' {
            break;
        }
    }
    let mut c;
    loop {
        c = m.u8(p);
        p += 1;
        if c == 0 || c != b' ' {
            break;
        }
    }
    if c == b'{' { p } else { 0 }
}

/// `5310`: parse one command into the entry at `out`.  Returns 0x8000 on
/// error (for a bare number, the number itself).
fn parse_entry(m: &mut Mem, toks: [u32; 4], out: u32) -> u16 {
    let t1 = toks[1];
    if t1 == 0 {
        return 0x8000;
    }
    let c = m.u8(t1);
    if isdigit(c) {
        m.set_i16(out + 4, 0);
        m.set_i16(out, 0x28);
        let v = number_req(m, t1);
        m.set_i16(out + 2, v);
        return v as u16;
    }
    if (c as i8) > b'`' as i8 && (c as i8) < b'h' as i8 {
        let sharp = m.u8(t1 + 1) == b'#';
        let octave = number_req(m, t1 + sharp as u32 + 1);
        if (0..9).contains(&octave) {
            m.set_i16(out, 0xb4);
            let base = m.i16(NOTES + ((c as i8 as i32 - 0x61) * 2) as u32) as i32;
            m.set_i16(out + 2, (-(base + octave as i32 * 12 + sharp as i32)) as i16);
            let pos = number_opt(m, toks[2]);
            m.set_i16(out + 4, pos);
            return if pos == -0x8000 { 0x8000 } else { 0 };
        }
    }
    let mut toks = toks;
    if c == b'p' && isdigit(m.u8(t1 + 1)) {
        // "p150" means "p 150".
        toks[3] = toks[2];
        toks[2] = t1 + 1;
    }
    let mut i = 0;
    let mut entry = KEYWORDS;
    while entry < KEYWORDS_END {
        let name = m.u32(entry);
        if prefix_eq(m, t1, name, strlen(m, name)) {
            break;
        }
        entry += 6;
        i += 1;
    }
    if i == KEYWORD_COUNT {
        return 0x8000;
    }
    let code = m.i16(KEYWORDS + 4 + 6 * i as u32);
    m.set_i16(out, code);
    let (arg, pos) = (toks[2], toks[3]);
    let code = code as i32;
    let value = if code == 0x41 {
        let v = keyword(m, arg, LIST_LANGUAGES);
        m.set_i16(out + 2, v);
        m.set_i16(out + 4, number_opt(m, pos));
        let global = match v {
            0 => Some(TIBASE_LANG_EN),
            1 => Some(TIBASE_LANG_ES),
            2 => Some(TIBASE_LANG_DE),
            _ => None,
        };
        if let Some(g) = global {
            let lang = m.u32(g);
            m.set_u32(CURRENT_LANG, lang);
        }
        None
    } else if code == 0x32 {
        Some(keyword(m, arg, LIST_VOICES))
    } else if code < 0x6f {
        Some(number_req(m, arg))
    } else if code < 0xd3 {
        Some(match code {
            0xd2 => keyword(m, arg, LIST_GLOT),
            0xc8 => keyword(m, arg, LIST_TRACT),
            _ => number_req(m, arg),
        })
    } else if code > 0xf0 {
        Some(match code {
            0x320 | 0x32a | 0x33e | 0x348 | 0x35c => keyword(m, arg, LIST_ONOFF),
            0x212 => keyword(m, arg, LIST_SPEAK),
            _ => number_req(m, arg),
        })
    } else {
        Some(match code {
            0xf0 => keyword(m, arg, LIST_F0STYLE),
            0xdc => keyword(m, arg, LIST_VOICING),
            _ => number_req(m, arg),
        })
    };
    if let Some(v) = value {
        m.set_i16(out + 2, v);
        m.set_i16(out + 4, number_opt(m, pos));
    }
    if m.i16(out + 2) != -0x8000 && m.i16(out + 4) != -0x8000 { 0 } else { 0x8000 }
}

/// `5180`: parse a `{...}` group (and any groups directly following it)
/// starting after the '{' at `*cur`, writing entries from `out`.  Returns
/// the next free entry, or 0 on error.
fn parse_commands(m: &mut Mem, cur: &mut u32, mut out: u32, ch: &mut u8, left: &mut i32) -> u32 {
    let first = *cur;
    if first == 0 {
        return 0;
    }
    let mut last = first;
    let mut p = first;
    while p != 0 {
        let toks = tokenize(m, p);
        if parse_entry(m, toks, out) == 0x8000 {
            m.set_i16(out, 0x46);
            *cur = p;
            return 0;
        }
        out += 6;
        last = p;
        p = next_command(m, p);
    }
    let mut consumed = last.wrapping_sub(*cur) as i32;
    *cur = last;
    loop {
        let c = m.u8(*cur);
        if c == 0 {
            break;
        }
        consumed += 1;
        *cur += 1;
        if c == b'}' {
            break;
        }
    }
    *ch = m.u8(*cur);
    *cur += 1;
    *left -= consumed + 1;
    out
}

/// Byte 3 of a phoneme's feature word, looked up through the language
/// structure recorded in a phoneme record.
fn rec_feature_hi(m: &Mem, rec: u32) -> u8 {
    let lang = m.u32(rec + 8);
    let code = m.i16(rec + 0xc) as i32;
    m.u8(m.u32(lang + 0x1c).wrapping_add(3).wrapping_add((code * 4) as u32))
}

fn or_flags(m: &mut Mem, rec: u32, bits: u32) {
    m.set_u32(rec + 0x16, m.u32(rec + 0x16) | bits);
}

/// `4a10`: parse the sentence at S+8 (length S+0x14) into phoneme records
/// at S+0x1c and embedded commands into a new block at S+0x34.  Returns 0,
/// ERR_PHONEME, ERR_COMMAND or EMPTY_PHRASE.
pub fn parse(m: &mut Mem, s: u32) -> i32 {
    let start = m.u32(s + 8);
    let recs = m.u32(s + 0x1c);
    m.set_u32(CURRENT_LANG, m.u32(s + 0x38));

    // Size the command buffer.
    let mut n: i32 = 10;
    let mut cur = start;
    let mut ch = m.u8(cur);
    while ch != 0 {
        cur += 1;
        if ch == b';' {
            n += 1;
        }
        if ch == b'}' {
            n += 2;
        }
        if ch == b'*' {
            n += 2;
            loop {
                ch = m.u8(cur);
                if ch != b'*' {
                    break;
                }
                cur += 1;
            }
        }
        if ch == b'@' {
            n += 2;
        }
        ch = m.u8(cur);
    }
    let mut cw = m.alloc((n * 6) as usize);
    m.set_u32(s + 0x34, cw);

    // Five padding records.
    let tbl = m.u32(s + 0x40);
    let lang = m.u32(CURRENT_LANG);
    let pad = |m: &mut Mem, r: u32, code: u16, feat_off: u32, dur: Option<u16>| {
        m.set_u16(r + 0xc, code);
        m.set_u32(r + 0x12, m.u32(tbl + feat_off));
        if let Some(d) = dur {
            m.set_u16(r + 0xe, d);
        }
        m.set_u32(r + 8, lang);
        m.set_u32(r + 4, tbl);
    };
    pad(m, recs, 0, 2, None);
    pad(m, recs + REC, 0, 2, None);
    pad(m, recs + 2 * REC, 0x1b, 0x2c0, Some(0x50));
    pad(m, recs + 3 * REC, 0x1b, 0x2c0, Some(0x50));
    pad(m, recs + 4 * REC, 0, 2, None);
    let mut rec = recs + 5 * REC;
    m.set_u16(s + 0xe, 5);

    let mut err = 0i32;
    let mut cur = start;
    let mut ch = m.u8(cur);
    cur += 1;
    let mut cmd_start: u32 = 0;
    let mut beats: u16 = 0;
    let mut word: u16 = 0;
    let mut word_pending = false;
    let mut left = m.i32(s + 0x14);
    let mut code: u32 = 0;
    let flags80 = m.u32(s + 0x4e) & 0x80 != 0;

    'outer: while left > 0 {
        if ch == b'{' {
            if flags80 {
                // Commands disabled: skip the group.
                left -= 1;
                ch = b'{';
                loop {
                    if ch == b'}' {
                        break;
                    }
                    ch = m.u8(cur);
                    cur += 1;
                    left -= 1;
                    if ch == 0 {
                        break;
                    }
                }
                if left < 1 {
                    break 'outer;
                }
                ch = m.u8(cur);
                cur += 1;
                continue;
            }
            if cmd_start == 0 {
                cmd_start = cw;
            }
            cw = parse_commands(m, &mut cur, cw, &mut ch, &mut left);
            if cw == 0 {
                err = ERR_COMMAND;
                break 'outer;
            }
            if left == 0 {
                break 'outer;
            }
        }

        // Character (pair) -> phoneme code.
        let mut idx = ch as i8 as i32 - 0x20;
        if !(0..=0x3b).contains(&idx) {
            idx = 1;
        }
        let mut e = m.u32(CHAR_MAP + 4 * idx as u32);
        let next = m.u8(cur);
        let odd_h = if next == b'H' {
            let mut q = cur;
            let mut odd = false;
            loop {
                q += 1;
                odd = !odd;
                if m.u8(q) != b'H' {
                    break;
                }
            }
            odd
        } else {
            true
        };
        let mask = if odd_h { 0xff } else { 0 };
        let first = m.u8(e);
        let mut b3 = first;
        while (mask & next) != b3 && m.u8(e) != 0 {
            e += 2;
            b3 = m.u8(e);
        }
        code = m.u8(e + 1) as u32;
        if code == 0xff {
            if first != 0 {
                cur += 1;
            }
            err = ERR_PHONEME;
            left = 0;
            code = 8;
        } else {
            if m.u8(e) != 0 {
                cur += 1;
                left -= 1;
            }
            ch = m.u8(cur);
            cur += 1;
            left -= 1;
        }

        let mut append = true;
        let cur_lang = m.u32(CURRENT_LANG);
        let features = m.u32(m.u32(cur_lang + 0x1c) + code * 4);
        if features & 0x4000_0200 != 0 {
            let prev = rec - REC;
            if rec_feature_hi(m, prev) & 0x10 == 0 {
                append = false;
                cur -= 1;
                err = ERR_PHONEME;
                ch = 0;
            } else {
                let stress = match code {
                    0x68 => 5,
                    0x69 => 2,
                    _ => (code as u16).wrapping_sub(0x5e) & 0xff,
                };
                m.set_u16(prev + 0x10, stress);
                if m.i16(prev + 0x10) != 0 {
                    or_flags(m, prev, 0x30);
                }
                append = false;
            }
        }
        if code == 0x6a {
            if !flags80 {
                beats = beats.wrapping_add(1);
            }
            append = false;
        }
        if code == 0x6b {
            // "@w<offset>": word sync.  (The original's error check compares
            // a 16-bit value with 0xffff8000 and never fires.)
            word = number_req(m, cur - 1) as u16;
            loop {
                ch = m.u8(cur);
                cur += 1;
                if ch == 0 {
                    break;
                }
                left -= 1;
                if !isdigit(ch) {
                    break;
                }
            }
            word_pending = true;
            append = false;
        }
        if (features >> 24) & 4 != 0 {
            if m.i16(s + 0xe) == 4 {
                append = false;
            } else if rec_feature_hi(m, rec - REC) & 4 != 0 {
                if code == 0 {
                    append = false;
                } else {
                    // Replace the previous boundary.
                    m.set_u16(s + 0xe, m.u16(s + 0xe).wrapping_sub(1));
                    rec -= REC;
                    append = true;
                }
            }
        }
        if code == 5 {
            or_flags(m, rec, 0x800);
            append = false;
        } else if code == 6 {
            let prev = rec - REC;
            if rec_feature_hi(m, prev) & 4 == 0 {
                or_flags(m, prev, 0x1000);
            } else if m.i16(prev + 0xc) == 0 {
                or_flags(m, prev - REC, 0x1000);
            }
            append = false;
        }
        if m.u32(cur_lang + 0x10) == 1 && code == 0x36 && cmd_start == 0 && beats == 0 {
            // English: vowel + R becomes an r-coloured vowel.
            code = match m.u16(rec - REC + 0xc) {
                0x09 => 0x2b,
                0x0d => 0x2d,
                0x11 => 0x2f,
                0x27 => 0x31,
                0x29 => 0x33,
                _ => code,
            };
            if code != 0x36 {
                m.set_u16(s + 0xe, m.u16(s + 0xe).wrapping_sub(1));
                rec -= REC;
                let list = m.u32(rec);
                if list != 0 {
                    cw -= 6;
                    cmd_start = list;
                }
            }
        } else if code == 0x5c {
            code = 0x27;
        }

        if append {
            m.set_u16(s + 0xe, m.u16(s + 0xe).wrapping_add(1));
            m.set_u16(rec + 0xc, code as u16);
            let tbl = m.u32(s + 0x40);
            m.set_u32(rec + 0x12, m.u32((code * REC + 2).wrapping_add(tbl)));
            m.set_u32(rec + 8, m.u32(CURRENT_LANG));
            m.set_u32(rec + 4, tbl);
            if code != 0 {
                let mut p = cw;
                if beats != 0 {
                    if cmd_start == 0 {
                        cmd_start = cw;
                    }
                    if cw != 0 {
                        m.set_i16(cw, 700);
                        p = cw + 6;
                        m.set_u16(cw + 2, beats);
                        m.set_u16(cw + 4, 0);
                    }
                    or_flags(m, rec, 0x400);
                    beats = 0;
                }
                let mut q = p;
                if word_pending {
                    if cmd_start == 0 {
                        cmd_start = p;
                    }
                    if p != 0 {
                        m.set_i16(p, 0x334);
                        q = p + 6;
                        m.set_u16(p + 2, word);
                        m.set_u16(p + 4, 0);
                    }
                    word_pending = false;
                }
                let list = cmd_start;
                cw = q;
                if cmd_start != 0 && q != 0 {
                    m.set_i16(q, 0x1e);
                    cw = q + 6;
                    m.set_u16(q + 2, 0);
                    m.set_u16(q + 4, 0);
                }
                cmd_start = 0;
                m.set_u32(rec, list);
            }
            rec += REC;
        }
    }

    m.set_u32(s + 0x10, cur.wrapping_sub(1));
    if err == 0 && m.u16(s + 0xe) >= 5 {
        let mut end = rec;
        let tbl = m.u32(s + 0x40);
        if m.i16(rec - REC + 0xc) == 0 {
            m.set_u16(rec - REC + 0xc, 4);
        } else if rec_feature_hi(m, rec - REC) & 2 == 0 || code == 0x1b {
            m.set_u16(rec + 0xc, 4);
            end = rec + REC;
            m.set_u32(rec + 0x12, m.u32(tbl + 0x6a));
            m.set_u16(s + 0xe, m.u16(s + 0xe).wrapping_add(1));
        }
        if cmd_start != 0 {
            if cw != 0 {
                m.set_i16(cw, 0x1e);
                m.set_u16(cw + 2, 0);
                m.set_u16(cw + 4, 0);
            }
            m.set_u32(end - REC, cmd_start);
        }
        m.set_u16(end + 0xc, 0x1b);
        m.set_u32(end + 0x12, m.u32(tbl + 0x2c0));
        m.set_u16(end + 0x26, 0x1b);
        m.set_u32(end + 0x2c, m.u32(tbl + 0x2c0));
        m.set_u16(end + 0x40, 0xff);
        m.set_u16(end + 0x44, 0xff);
        m.set_u16(end + 0x42, 0xff);
        m.set_u32(end + 0x46, 0);
        m.set_u16(s + 0xe, m.u16(s + 0xe).wrapping_add(3));
    }
    if m.u16(s + 0xe) == 4 {
        err = EMPTY_PHRASE;
        m.set_u16(s + 0xe, 0);
    }
    err
}
