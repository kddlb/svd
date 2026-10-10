//! Number and format normalizer: the dispatcher (`208150` / `407e20`), the
//! pattern handlers (times, dates, phone numbers, years), cardinal numbers
//! (English `207890`, Spanish `4073d0`) and mixed tokens (`209580` /
//! `409400`).
//!
//! The dispatcher cuts the token at T+8 to its run of
//! "0123456789,.$%+-()/:", builds a pattern from it ('#' digit, 'L' other,
//! the punctuation itself) in a global and looks it up in a table of
//! {pattern, length, handler}.  Handlers append phonemes to a global output
//! string that starts as " " and return how far the token was consumed:
//! 1 the number, 2 also the next word ("5 million"), 3 up to a character
//! the mixed-token reader could not read, 0 not handled.

use super::{
    Lang, T_CUR, T_OUT, T_ROOM, T_SRC, T_STATE, isdigit, strcat, strchr, strcspn, strlen, strneq, strrchr,
    strspn, streq, toupper,
};
use crate::mem::Mem;

/// Word for a character code from a pointer table (`table[c]`).
#[inline]
fn word(m: &Mem, table: u32, i: i32) -> u32 {
    m.u32(table.wrapping_add((i as u32).wrapping_mul(4)))
}

#[inline]
fn digit(m: &Mem, p: u32) -> i32 {
    m.i8(p) as i32 - 0x30
}

/// `208150` / `407e20`.  Returns 1 if the output is full.
pub fn normalize(m: &mut Mem, l: &Lang, t: u32) -> i32 {
    let tok = m.u32(t + T_CUR);
    m.set_u32(l.g_tok, tok);
    let c0 = m.u8(tok);
    if c0 == 0 {
        return 0;
    }
    if !isdigit(c0) {
        let c1 = m.u8(tok + 1);
        match c0 {
            b'$' => {
                if !isdigit(c1) && c1 != b'.' {
                    return 0;
                }
            }
            b'(' | b'.' => {
                if !isdigit(c1) {
                    return 0;
                }
            }
            _ => return 0,
        }
    }
    m.set_u8(l.pat, 0);
    let n = strspn(m, tok, l.numchars);
    let mut next = tok + n;
    let b = m.u8(next - 1);
    if b == b',' || b == b'.' {
        next -= 1;
    }
    let save1 = m.u8(next);
    let end1 = next;
    m.set_u32(l.g_end1, end1);
    if save1 != 0 {
        m.set_u8(next, 0);
        next += 1;
        while m.u8(next) == b' ' {
            next += 1;
        }
    }
    m.set_u32(l.g_next, next);
    let mut end2 = strchr(m, next, b' ');
    if end2 == 0 {
        end2 = next + strlen(m, next);
    }
    let b = m.u8(end2 - 1);
    if b == b',' || b == b'.' {
        end2 -= 1;
    }
    m.set_u32(l.g_end2, end2);
    let save2 = m.u8(end2);
    m.set_u8(end2, 0);

    let mut len = strlen(m, tok) as i32;
    let mut plain = true;
    if len > 19 {
        len = 20;
    }
    let mut p = tok;
    while len != 0 {
        len -= 1;
        let c = m.u8(p);
        p += 1;
        let s = if super::ctype(c) & 0x103 != 0 {
            plain = false;
            l.p_letter
        } else if isdigit(c) {
            l.p_digit
        } else {
            match c {
                b'$' => l.p_dollar,
                b'%' => l.p_percent,
                b',' => l.p_comma,
                b'.' => l.p_dot,
                b'(' => {
                    plain = false;
                    l.p_lpar
                }
                b')' => {
                    plain = false;
                    l.p_rpar
                }
                b'-' => {
                    plain = false;
                    l.p_dash
                }
                b'/' => {
                    plain = false;
                    l.p_slash
                }
                b':' => {
                    plain = false;
                    l.p_colon
                }
                _ => {
                    plain = false;
                    l.p_letter
                }
            }
        };
        strcat(m, l.pat, s);
    }

    m.set_u8(l.out, 0);
    strcat(m, l.out, l.p_space);
    let mut r = 0;
    let mut e = l.patterns;
    while m.u32(e + 8) != 0 {
        if streq(m, m.u32(e), l.pat) {
            let tok = m.u32(l.g_tok);
            let next = m.u32(l.g_next);
            r = call_handler(m, l, m.u32(e + 8), tok, next, l.out);
            break;
        }
        e += 12;
    }
    if r == 0 && plain {
        let (tok, next) = (m.u32(l.g_tok), m.u32(l.g_next));
        r = cardinal(m, l, tok, next, l.out);
    }
    if r == 0 {
        let tok = m.u32(l.g_tok);
        r = mixed(m, l, tok, l.g_next, l.out);
    }
    if r != 0 {
        let olen = strlen(m, l.out) as i32;
        let room = m.i32(t + T_ROOM) - olen;
        m.set_i32(t + T_ROOM, room);
        if room < 1 {
            r = -1;
        } else {
            let o = m.u32(t + T_OUT);
            strcat(m, o, l.out);
            m.set_u32(t + T_OUT, o.wrapping_add(olen as u32));
        }
    }
    let end1 = m.u32(l.g_end1);
    let end2 = m.u32(l.g_end2);
    m.set_u8(end1, save1);
    m.set_u8(end2, save2);
    let advance = |m: &mut Mem, to: u32, state: bool| {
        let src = to.wrapping_add(m.u32(t + T_SRC).wrapping_sub(m.u32(t + T_CUR)));
        m.set_u32(t + T_SRC, src);
        if state {
            m.set_u32(t + T_STATE, 4);
        }
        m.set_u32(t + T_CUR, to);
    };
    match r {
        0 => 0,
        1 => {
            advance(m, end1, true);
            0
        }
        2 => {
            advance(m, end2, true);
            0
        }
        3 => {
            let next = m.u32(l.g_next);
            advance(m, next, true);
            0
        }
        -1 => 1,
        _ => {
            advance(m, end1, false);
            0
        }
    }
}

/// Dispatch a pattern handler by its original address.
fn call_handler(m: &mut Mem, l: &Lang, f: u32, s: u32, next: u32, out: u32) -> i32 {
    match f {
        0x1c209120 | 0x1c408df0 => phone11(m, l, s, next, out),
        0x1c2091f0 | 0x1c408ec0 => phone10(m, l, s, next, out),
        0x1c208ff0 | 0x1c408cc0 => phone7(m, l, s, next, out),
        0x1c209580 | 0x1c409400 => mixed_local(m, l, s, next, out),
        0x1c209380 | 0x1c4090f0 => year(m, l, s, next, out),
        0x1c208c90 | 0x1c408960 => time_hms(m, l, s, next, out),
        0x1c208850 | 0x1c408520 => time_hm(m, l, s, next, out),
        0x1c208f20 | 0x1c408bf0 => area_code(m, l, s, next, out),
        0x1c208a80 | 0x1c408750 => date(m, l, s, next, out),
        _ => panic!("unknown normalizer handler {f:#x}"),
    }
}

/// The mixed reader called with a pointer to the caller's own copy of
/// `next` (the pattern table and the year readers do this), so a return of
/// 3 does not move the dispatcher's position.
fn mixed_local(m: &mut Mem, l: &Lang, s: u32, next: u32, out: u32) -> i32 {
    let cell = m.alloc(4);
    m.set_u32(cell, next);
    let r = mixed(m, l, s, cell, out);
    m.free(cell);
    r
}

fn cardinal(m: &mut Mem, l: &Lang, s: u32, next: u32, out: u32) -> i32 {
    if l.is_english() { cardinal_en(m, l, s, next, out) } else { cardinal_es(m, l, s, next, out) }
}

fn three(m: &mut Mem, l: &Lang, s: u32, out: u32) {
    if l.is_english() { three_en(m, l, s, out) } else { three_es(m, l, s, out) }
}

// English cardinal strings.
const EN_HUNDRED: u32 = 0x1c24c9f0; // "/HUN5DRIHD "
const EN_TENS: u32 = 0x1c24d018; // "OW5 ", "TEH5N ", "TWEH5NIY "...
const EN_SCALE: u32 = 0x1c24cf68; // "/HUN5DRIHD ", "THAW5ZIND ", "MIH5LYIN "...
const EN_ZERO: u32 = 0x1c24c9e4; // "ZIH5ROW "
const EN_DOLLAR: u32 = 0x1c24c9d4; // "DAA5LER "
const EN_DOLLARS: u32 = 0x1c24c9c8; // "DAA5LERZ "
const EN_AND: u32 = 0x1c24c9c0; // "AEND "
const EN_CENT: u32 = 0x1c24c9b8; // "SEH5NT "
const EN_CENTS: u32 = 0x1c24c9ac; // "SEH5NTS "
const EN_POINT: u32 = 0x1c24c9a4; // "POY5NT "
const EN_PERCENT: u32 = 0x1c24c964; // "PERSEH5NT "
const EN_DOTS: u32 = 0x1c24c9fc; // ",."

/// `2080d0`: is the next word MILLION, BILLION, TRILLION or QUADRILLION?
fn is_big_en(m: &Mem, next: u32) -> bool {
    next != 0
        && (strneq(m, next, 0x1c24ca24, 7)
            || strneq(m, next, 0x1c24ca1c, 7)
            || strneq(m, next, 0x1c24ca10, 8)
            || strneq(m, next, 0x1c24ca04, 11))
}

/// `407da0`: MILLON, BILLON, TRILLON, QUADRILLON.
fn is_big_es(m: &Mem, next: u32) -> bool {
    next != 0
        && (strneq(m, next, 0x1c40e568, 6)
            || strneq(m, next, 0x1c40e560, 6)
            || strneq(m, next, 0x1c40e558, 7)
            || strneq(m, next, 0x1c40e54c, 10))
}

/// What the cardinal readers share up to the digit groups.
struct Num {
    s: u32,
    last: u32,
    pct: bool,
    dollar: bool,
    ip: i32,
    frac: i32,
    big: bool,
    one: bool,
    cents: bool,
}

/// The common head of `207890` / `4073d0`: strip '$' and '%', check that
/// the integer part is digits in groups of three.  None: not a number.
fn number_head(m: &mut Mem, l: &Lang, mut s: u32, next: u32, dot: u32, big: fn(&Mem, u32) -> bool) -> Option<Num> {
    let mut len = strlen(m, s) as i32;
    let dollar = m.u8(s) == b'$';
    if dollar {
        s += 1;
        len -= 1;
    }
    let last = s.wrapping_add((len - 1) as u32);
    let pct = m.u8(last) == b'%';
    if pct {
        len -= 1;
        m.set_u8(last, 0);
    }
    let ip = strcspn(m, s, dot) as i32;
    if ip > 0x52 {
        if pct {
            m.set_u8(last, b'%');
        }
        return None;
    }
    let mut frac = len - ip - 1;
    if frac < 1 {
        frac = 0;
    }
    let big = big(m, next);
    let one = dollar && ip == 1 && m.u8(s) == b'1';
    let cents = dollar && (frac == 2 || frac == 0) && !big;
    let mut ok = true;
    let mut cnt = 0;
    let mut q = l.pat.wrapping_add((ip - !dollar as i32) as u32);
    for _ in 0..ip {
        let c = m.u8(q);
        q = q.wrapping_sub(1);
        if c == b'#' {
            cnt += 1;
        } else if c == b',' && cnt == 3 {
            cnt = 0;
        } else {
            ok = false;
        }
    }
    if cnt > 3 {
        ok = false;
    }
    if frac != 0 && strchr(m, s + ip as u32 + 1, b'.') != 0 {
        ok = false;
    }
    if !ok {
        if pct {
            m.set_u8(last, b'%');
        }
        return None;
    }
    Some(Num { s, last, pct, dollar, ip, frac, big, one, cents })
}

/// Read three digits of a group: (hundreds, tens, ones), advancing `s`.
fn group(m: &Mem, s: &mut u32, g: u32) -> (i32, i32, i32) {
    let (mut h, mut tn, mut o) = (0, 0, 0);
    if g == 3 {
        h = digit(m, *s);
        *s += 1;
    }
    if g >= 2 && g <= 3 {
        tn = digit(m, *s);
        *s += 1;
    }
    if g >= 1 && g <= 3 {
        o = digit(m, *s);
        *s += 1;
    }
    (h, tn, o)
}

/// `207890`: English cardinal numbers, money ("$5.25", "$5 million") and
/// percentages.  Returns 0 (not a number), 1, or 2 (the next word was
/// MILLION etc. and is consumed).
pub fn cardinal_en(m: &mut Mem, l: &Lang, s: u32, next: u32, out: u32) -> i32 {
    let Some(n) = number_head(m, l, s, next, l.p_dot, is_big_en) else { return 0 };
    let mut s = n.s;
    let mut commas = 0;
    for k in 0..n.ip.max(0) as u32 {
        commas += (m.u8(s + k) == b',') as i32;
    }
    let mut rem = n.ip;
    let mut zero = false;
    while rem > 0 {
        let g = strcspn(m, s, EN_DOTS).min(3);
        let (h, tn, o) = group(m, &mut s, g);
        if h != 0 {
            strcat(m, out, word(m, l.ones, h));
            strcat(m, out, EN_HUNDRED);
        }
        if tn < 2 {
            let v = o + tn * 10;
            if v != 0 {
                strcat(m, out, word(m, l.ones, v));
            }
        } else {
            strcat(m, out, word(m, EN_TENS, tn));
            if o != 0 {
                strcat(m, out, word(m, l.ones, o));
            }
        }
        zero = h + tn + o == 0;
        if !zero {
            if commas != 0 {
                strcat(m, out, word(m, EN_SCALE, commas));
                commas -= 1;
                strcat(m, out, l.comma_sp);
            }
        } else {
            if rem < 4 {
                while rem != 0 {
                    rem -= 1;
                    strcat(m, out, EN_ZERO);
                }
                rem = -1;
            }
            commas -= 1;
        }
        s += 1;
        rem -= g as i32 + 1;
    }
    if zero {
        let c = strrchr(m, out, b',');
        if c != 0 {
            m.set_u8(c, 0);
        }
    }
    if n.ip == 0 {
        s += 1;
    }
    if n.dollar && n.cents {
        if n.one {
            strcat(m, out, EN_DOLLAR);
        } else if n.ip != 0 {
            strcat(m, out, EN_DOLLARS);
        }
        if n.frac == 2 {
            let tn = digit(m, s);
            let o = digit(m, s + 1);
            let v = o + tn * 10;
            if v != 0 {
                if n.ip != 0 {
                    strcat(m, out, EN_AND);
                }
                if tn < 2 {
                    strcat(m, out, word(m, l.ones, v));
                } else {
                    strcat(m, out, word(m, EN_TENS, tn));
                    if o != 0 {
                        strcat(m, out, word(m, l.ones, o));
                    }
                }
                strcat(m, out, if v == 1 { EN_CENT } else { EN_CENTS });
            }
        }
    } else if n.frac != 0 {
        strcat(m, out, EN_POINT);
        for _ in 0..n.frac {
            strcat(m, out, word(m, l.digits, m.i8(s) as i32));
            s += 1;
        }
    }
    let mut r = 1;
    if n.big {
        let w = match toupper(m.u8(next)) {
            b'B' => 0x1c24c98c, // "BIH5LYIN "
            b'M' => 0x1c24c998, // "MIH5LYIN "
            b'Q' => 0x1c24c970, // "KWAADRIH5LYIN "
            b'T' => 0x1c24c980, // "TRIH5LYIN "
            _ => 0,
        };
        if w != 0 {
            strcat(m, out, w);
        }
        r = 2;
    }
    if n.dollar && (n.big || !n.cents) {
        strcat(m, out, EN_DOLLARS);
    }
    if n.big && strchr(m, next, b')') != 0 {
        strcat(m, out, l.comma_sp);
    }
    if n.pct {
        strcat(m, out, EN_PERCENT);
        m.set_u8(n.last, b'%');
    }
    r
}

// Spanish cardinal strings.
const ES_TENS: u32 = 0x1c40ebe8; // "VEY5NTEY " (tens alone)
const ES_TENS_Y: u32 = 0x1c40ec10; // "VEY5NTEHIY " (tens followed by ones)
const ES_SCALE: u32 = 0x1c40eb38; // "SIYEH5NTOH ", "MIY5L ", "MIYYOH5N "...
const ES_ZERO: u32 = 0x1c40e4e8; // "SEH5ROH "
const ES_UNO: u32 = 0x1c40e53c; // "UW4NOH "
const ES_CIEN: u32 = 0x1c40e534; // "SIYEH4N"
const ES_QUIN: u32 = 0x1c40e528; // "KIYNIYEH4N"
const ES_SETE: u32 = 0x1c40e518; // "SEH3TEHSIYEH4N"
const ES_NOVE: u32 = 0x1c40e508; // "NOH3VEHSIYEH4N"
const ES_SP: u32 = 0x1c40e4f4; // " "
const ES_TO: u32 = 0x1c40e4f8; // "TOH "
const ES_TOS: u32 = 0x1c40e500; // "TOHS "
const ES_DOLLAR: u32 = 0x1c40e4d8; // "DOH5LAAR "
const ES_DOLLARS: u32 = 0x1c40e4c8; // "DOH5LAAREHS "
const ES_CENT: u32 = 0x1c40e4b8; // "SEHNTAA5VOH "
const ES_CENTS: u32 = 0x1c40e4a8; // "SEHNTAA5VOHS "
const ES_Y: u32 = 0x1c40e4a4; // "IY "
const ES_DECIMAL: u32 = 0x1c40e494; // "DEH5SIYMAAL "
const ES_PERCENT: u32 = 0x1c40e448; // "POHR SIYEH5NTOH "
const ES_DOTS: u32 = 0x1c40e544; // ",."

/// Spanish hundreds ("SIYEH4N" + " "/"TOH "/"TOHS " etc.), shared by the
/// cardinal and year readers.
fn hundreds_es(m: &mut Mem, l: &Lang, h: i32, rest: i32, out: u32, quin: u32, sete: u32, nove: u32) {
    match h {
        2 | 3 | 4 | 6 | 8 => {
            strcat(m, out, word(m, l.ones, h));
            strcat(m, out, ES_CIEN);
        }
        1 => strcat(m, out, ES_CIEN),
        5 => strcat(m, out, quin),
        7 => strcat(m, out, sete),
        9 => strcat(m, out, nove),
        _ => {}
    }
    if h < 2 {
        strcat(m, out, if rest == 0 { ES_SP } else { ES_TO });
    } else {
        strcat(m, out, ES_TOS);
    }
}

/// `4073d0`: Spanish cardinal numbers, money and percentages.
pub fn cardinal_es(m: &mut Mem, l: &Lang, s: u32, next: u32, out: u32) -> i32 {
    let Some(n) = number_head(m, l, s, next, l.p_dot, is_big_es) else { return 0 };
    let mut s = n.s;
    let mut commas = 0;
    for k in 0..n.ip.max(0) as u32 {
        commas += (m.u8(s + k) == b',') as i32;
    }
    let mut rem = n.ip;
    let mut zero = false;
    while rem > 0 {
        let g = strcspn(m, s, ES_DOTS).min(3);
        let (h, tn, o) = group(m, &mut s, g);
        if h + tn == 0 && o == 1 {
            if commas == 0 {
                strcat(m, out, ES_UNO);
            }
        } else {
            if h != 0 {
                hundreds_es(m, l, h, o + tn, out, ES_QUIN, ES_SETE, ES_NOVE);
            }
            if tn < 2 {
                let v = o + tn * 10;
                if v != 0 {
                    strcat(m, out, word(m, l.ones, v));
                }
            } else {
                strcat(m, out, word(m, if o == 0 { ES_TENS } else { ES_TENS_Y }, tn));
                if o != 0 {
                    strcat(m, out, word(m, l.ones, o));
                }
            }
        }
        zero = o + h + tn == 0;
        if !zero {
            if commas != 0 {
                strcat(m, out, word(m, ES_SCALE, commas));
                commas -= 1;
                strcat(m, out, l.comma_sp);
            }
        } else {
            if rem < 4 {
                while rem != 0 {
                    rem -= 1;
                    strcat(m, out, ES_ZERO);
                }
                rem = -1;
            }
            commas -= 1;
        }
        s += 1;
        rem -= g as i32 + 1;
    }
    if zero {
        let c = strrchr(m, out, b',');
        if c != 0 {
            m.set_u8(c, 0);
        }
    }
    if n.ip == 0 {
        s += 1;
    }
    if n.dollar && n.cents {
        if n.one {
            strcat(m, out, ES_DOLLAR);
        } else if n.ip != 0 {
            strcat(m, out, ES_DOLLARS);
        }
        if n.frac == 2 {
            let tn = digit(m, s);
            let o = digit(m, s + 1);
            let v = o + tn * 10;
            if v != 0 {
                if tn < 2 {
                    strcat(m, out, word(m, l.ones, v));
                } else {
                    strcat(m, out, word(m, ES_TENS, tn));
                    if o != 0 {
                        strcat(m, out, word(m, l.ones, o));
                    }
                }
                strcat(m, out, if v == 1 { ES_CENT } else { ES_CENTS });
            }
        }
    } else if n.frac != 0 {
        strcat(m, out, ES_Y);
        for _ in 0..n.frac {
            strcat(m, out, word(m, l.digits, m.i8(s) as i32));
            s += 1;
        }
        strcat(m, out, ES_DECIMAL);
    }
    let mut r = 1;
    if n.big {
        let w = match toupper(m.u8(next)) {
            b'B' => 0x1c40e478, // "MIY3L MIYYOH5N "
            b'M' => 0x1c40e488, // "MIYYOH5N "
            b'Q' => 0x1c40e45c, // "KWAADRIYYOH5N "
            b'T' => 0x1c40e46c, // "TRIYYOH5N "
            _ => 0,
        };
        if w != 0 {
            strcat(m, out, w);
        }
        r = 2;
    }
    if n.dollar && (n.big || !n.cents) {
        strcat(m, out, ES_DOLLARS);
    }
    if n.big && strchr(m, next, b')') != 0 {
        strcat(m, out, l.comma_sp);
    }
    if n.pct {
        strcat(m, out, ES_PERCENT);
        m.set_u8(n.last, b'%');
    }
    r
}

/// `209580` / `409400`: a token that is not a plain number: an optional
/// "(...)" around it becomes ", ...," and the rest is read as a cardinal
/// or, failing that, character by character.  Returns 3 (and stores the
/// position in `*next_at`) at the first character it cannot read.
pub fn mixed(m: &mut Mem, l: &Lang, mut s: u32, next_at: u32, out: u32) -> i32 {
    let size = strlen(m, s) + 1;
    let n = size as i32 - 1;
    let last = s.wrapping_add(size).wrapping_sub(2);
    let b = m.u8(last);
    if b == b')' {
        m.set_u8(last, 0);
        m.set_u8(l.pat.wrapping_add(size).wrapping_sub(2), 0);
    }
    if m.u8(s) == b'(' {
        s += 1;
        let mut i = 0;
        while i < n {
            m.set_u8(l.pat + i as u32, m.u8(l.pat + i as u32 + 1));
            i += 1;
        }
        strcat(m, out, l.comma_sp);
    }
    let r = cardinal(m, l, s, 0, out);
    m.set_u8(last, b);
    if r == 0 {
        let mut k = n;
        loop {
            if k == 0 {
                return 1;
            }
            let c = m.u8(s);
            let w = if isdigit(c) {
                word(m, l.digits, c as i32)
            } else {
                match c {
                    b'$' => l.m_dollar,
                    b'+' => l.m_plus,
                    b',' => l.t_dash,
                    b'-' => l.m_dash,
                    b'.' => l.m_point,
                    b'/' => l.m_slash,
                    b':' => l.m_colon,
                    _ => {
                        m.set_u32(next_at, s);
                        return 3;
                    }
                }
            };
            strcat(m, out, w);
            k -= 1;
            s += 1;
        }
    }
    if b == b')' {
        strcat(m, out, l.comma_sp);
    }
    r
}

/// `209290`: English "###" (phone groups): digit by digit, or "N hundred".
fn three_en(m: &mut Mem, l: &Lang, s: u32, out: u32) {
    let (a, b, c) = (digit(m, s), digit(m, s + 1), digit(m, s + 2));
    strcat(m, out, word(m, l.ones, a));
    let w = if a == 0 || b != 0 || c != 0 {
        strcat(m, out, word(m, l.ones, b));
        word(m, l.ones, c)
    } else {
        0x1c24cc58 // "/HAH5NDRIHD "
    };
    strcat(m, out, w);
}

/// `408f60`: Spanish "###": digit by digit, or "N cientos" / "cien".
fn three_es(m: &mut Mem, l: &Lang, s: u32, out: u32) {
    let (a, b, c) = (digit(m, s), digit(m, s + 1), digit(m, s + 2));
    if a == 0 || b != 0 || c != 0 {
        strcat(m, out, word(m, l.ones, a));
        strcat(m, out, word(m, l.ones, b));
        strcat(m, out, word(m, l.ones, c));
    } else if a != 1 {
        strcat(m, out, word(m, l.ones, a));
        strcat(m, out, 0x1c40e774); // "SIYEH4NTOHS "
    } else {
        strcat(m, out, 0x1c40e784); // "SIYEH5N "
    }
}

/// `208ff0` / `408cc0`: "###-####".
fn phone7(m: &mut Mem, l: &Lang, s: u32, _next: u32, out: u32) -> i32 {
    for k in 0..3 {
        strcat(m, out, word(m, l.digits, m.i8(s + k) as i32));
    }
    strcat(m, out, l.comma_sp);
    strcat(m, out, word(m, l.digits, m.i8(s + 4) as i32));
    three(m, l, s + 5, out);
    1
}

/// `2091f0` / `408ec0`: "###-###-####", "###/###-####".
fn phone10(m: &mut Mem, l: &Lang, s: u32, next: u32, out: u32) -> i32 {
    strcat(m, out, l.area);
    three(m, l, s, out);
    strcat(m, out, l.p_comma);
    phone7(m, l, s + 4, next, out);
    1
}

/// `209120` / `408df0`: "#-###-###-####".
fn phone11(m: &mut Mem, l: &Lang, s: u32, next: u32, out: u32) -> i32 {
    strcat(m, out, word(m, l.digits, m.i8(s) as i32));
    strcat(m, out, l.p_comma);
    three(m, l, s + 2, out);
    strcat(m, out, l.p_comma);
    phone7(m, l, s + 6, next, out);
    1
}

/// `208f20` / `408bf0`: "(###)" followed by a number: an area code.
fn area_code(m: &mut Mem, l: &Lang, s: u32, next: u32, out: u32) -> i32 {
    if next != 0 && isdigit(m.u8(next)) {
        strcat(m, out, l.area);
        three(m, l, s + 1, out);
        strcat(m, out, l.p_comma);
        return 1;
    }
    0
}

/// Append a number below 100 for the date reader: 0..19 as one word,
/// otherwise tens + ones (also "zero" ones).
fn date_part(m: &mut Mem, l: &Lang, v: i32, out: u32) {
    let w = if v < 20 {
        word(m, l.ones, v)
    } else {
        strcat(m, out, word(m, l.tens, v / 10));
        word(m, l.ones, v % 10)
    };
    strcat(m, out, w);
}

/// `208a80` / `408750`: "#/#/##" .. "##/##/##" (no validation).
fn date(m: &mut Mem, l: &Lang, mut s: u32, _next: u32, out: u32) -> i32 {
    let mut a = 0;
    while m.u8(s) != b'/' {
        a = digit(m, s) + a * 10;
        s += 1;
    }
    let mut b = 0;
    let mut p = s + 1;
    while m.u8(p) != b'/' {
        b = digit(m, p) + b * 10;
        p += 1;
    }
    let c = digit(m, p + 2) + (m.i8(p + 1) as i32 * 5 - 0xf0) * 2;
    date_part(m, l, a, out);
    date_part(m, l, b, out);
    date_part(m, l, c, out);
    1
}

/// `208850` / `408520`: "#:##", "##:##" (hours 1..12, minutes 0..59).
fn time_hm(m: &mut Mem, l: &Lang, s: u32, _next: u32, out: u32) -> i32 {
    let (hi, lo, p);
    if m.u8(s + 1) == b':' {
        hi = 0;
        lo = digit(m, s);
        p = s + 1;
    } else {
        lo = digit(m, s + 1);
        hi = digit(m, s);
        p = s + 2;
    }
    let h = lo + hi * 10;
    let m1 = digit(m, p + 1);
    let m2 = digit(m, p + 2);
    let mm = m2 + m1 * 10;
    if h < 1 || h > 12 || mm > 59 {
        return 0;
    }
    strcat(m, out, word(m, l.ones, h));
    if mm == 0 {
        strcat(m, out, l.t_oclock);
    } else if m1 == 0 {
        strcat(m, out, l.t_oh);
        strcat(m, out, word(m, l.ones, m2));
    } else if m1 == 1 {
        strcat(m, out, word(m, l.ones, mm));
    } else {
        strcat(m, out, word(m, l.tens, m1));
        if m2 != 0 {
            strcat(m, out, word(m, l.ones, m2));
        }
    }
    1
}

/// `208c90` / `408960`: "#:##:##" .. "###:##:##" as hours, minutes, seconds.
fn time_hms(m: &mut Mem, l: &Lang, mut s: u32, _next: u32, out: u32) -> i32 {
    m.set_u8(l.pat, b'#');
    m.set_u8(l.pat + 1, b'#');
    m.set_u8(l.pat + 2, b'#');
    for (unit, plural) in [(l.t_hour, l.t_plural_h), (l.t_minute, l.t_plural_m)] {
        m.set_u32(l.buf, 0);
        let mut d = l.buf;
        let mut v = 0;
        loop {
            let c = m.u8(s);
            s += 1;
            if c == b':' {
                break;
            }
            m.set_u8(d, c);
            d += 1;
            v = c as i8 as i32 - 0x30 + v * 10;
        }
        cardinal(m, l, l.buf, 0, out);
        strcat(m, out, unit);
        strcat(m, out, if v == 1 { l.t_dash } else { plural });
    }
    // s is past the second ':'.
    m.set_u32(l.buf, 0);
    let b2 = m.u8(s);
    let mut d = l.buf;
    if b2 != b'0' {
        d = l.buf + 1;
        m.set_u32(l.buf, b2 as u32);
    }
    let b3 = m.u8(s + 1);
    m.set_u8(d, b3);
    m.set_u8(d + 1, 0);
    cardinal(m, l, l.buf, 0, out);
    strcat(m, out, l.t_second);
    let v = (b2 as i8 as i32 * 5 - 0xf0) * 2 - 0x30 + b3 as i8 as i32;
    strcat(m, out, if v != 1 { l.t_plural_h } else { l.t_dash });
    1
}

/// `209380`: English "####" as a year ("nineteen ninety six", "two
/// thousand five"); a leading 0 is read as a mixed token.
fn year_en(m: &mut Mem, l: &Lang, s: u32, next: u32, out: u32) -> i32 {
    if m.u8(s) == b'0' {
        mixed_local(m, l, s, next, out);
        return 1;
    }
    let a = digit(m, s);
    let b = digit(m, s + 1);
    let c = digit(m, s + 2);
    let d = digit(m, s + 3);
    if b * 10 + c == 0 {
        strcat(m, out, word(m, l.ones, a));
        strcat(m, out, 0x1c24cc68); // "THAW5ZIHND "
        if d == 0 {
            return 1;
        }
        strcat(m, out, word(m, l.ones, d));
        return 1;
    }
    if a == 1 {
        strcat(m, out, word(m, l.ones, m.i8(s + 1) as i32 - 0x26));
    } else {
        strcat(m, out, word(m, l.tens, a));
        if b != 0 {
            strcat(m, out, word(m, l.ones, b));
        }
    }
    let v = d + c * 10;
    let w = if v == 0 {
        0x1c24cc58 // "/HAH5NDRIHD "
    } else if c == 1 {
        word(m, l.ones, v)
    } else {
        strcat(m, out, word(m, l.tens, c));
        if d == 0 {
            return 1;
        }
        word(m, l.ones, d)
    };
    strcat(m, out, w);
    1
}

/// `4090f0`: Spanish "####" as a year ("mil novecientos noventa y seis").
fn year_es(m: &mut Mem, l: &Lang, s: u32, next: u32, out: u32) -> i32 {
    if m.u8(s) == b'0' {
        mixed_local(m, l, s, next, out);
        return 1;
    }
    let a = digit(m, s);
    let b = digit(m, s + 1);
    let c = digit(m, s + 2);
    let d = digit(m, s + 3);
    if a > 1 {
        strcat(m, out, word(m, l.ones, a));
    }
    strcat(m, out, 0x1c40e7b0); // "MIY5L "
    if b != 0 {
        hundreds_es(m, l, b, c + d, out, ES_QUIN, 0x1c40e7a0, 0x1c40e790);
    }
    let w = if c < 2 {
        let v = d + c * 10;
        if v == 0 {
            return 1;
        }
        word(m, l.ones, v)
    } else {
        strcat(m, out, word(m, if d == 0 { ES_TENS } else { ES_TENS_Y }, c));
        if d == 0 {
            return 1;
        }
        word(m, l.ones, d)
    };
    strcat(m, out, w);
    1
}

fn year(m: &mut Mem, l: &Lang, s: u32, next: u32, out: u32) -> i32 {
    if l.is_english() { year_en(m, l, s, next, out) } else { year_es(m, l, s, next, out) }
}
