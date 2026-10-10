//! Text to phonemes (M5): TIBASE32 `_SVTextToPhon@24` (`fc50`) with its
//! embedded-command pass-through (`100d0`), and the language modules'
//! text-to-phoneme driver (`LoadLanguage` slot [3]: TIENG32 `FUN_1c2067c0`,
//! TISPAN32 `FUN_1c406250`) with everything it calls.
//!
//! The two language modules are compiled from the same source; their code
//! differs only in addresses, except for the cardinal-number reader, the
//! three-digit/year readers and the default-stress rule, which are separate
//! functions here (`numbers.rs`, `rules.rs`).  All rule and dictionary text
//! is read in place from the DLL images in [`Mem`], and every global is kept
//! at its original address and width (the normalizer's scratch strings, the
//! word-marker buffer, the shared conversion state at `0x1c0141e0`).
//!
//! The conversion state shared by TIBASE and the language driver (`T`,
//! `DAT_1c0141e0`, passed to the driver as its second argument):
//!   +0x00 u32  position in the caller's text (only kept up to date)
//!   +0x04 u32  end of the phoneme output (points at its NUL)
//!   +0x08 u32  current position in the cleaned copy of the text
//!   +0x0c u32  cleaned copy (calloc'ed; [0] is a space)
//!   +0x10 u32  start of the current word
//!   +0x14 i32  room left in the output buffer
//!   +0x18 u32  SVTextToPhon flags
//!   +0x1c u32  state of the last rule: 1 '\'-terminated rule, 2 '`'-terminated
//!              rule or dictionary word, 4 "more to do in this word" (set by
//!              each rule, the normalizer and `{{...}}`), 8 output had '.'/'?'
//!
//! Flags (`dwFlags`): 0x02 always apply the default stress rule (and allow
//! IX/AX as stressable vowels), 0x04 spell mode (letters are read one by
//! one; ']' is kept instead of becoming a space), 0x08 insert " @w<offset> "
//! before each word, 0x10 also mark words starting with "{{" and do not pass
//! "{{...}}" through, 0x40 do not force '?' to "?".

pub mod numbers;
pub mod rules;

use crate::lang::{CURRENT_LANG, ENGLISH, LangDef, SPANISH};
use crate::mem::Mem;

/// The conversion state (`DAT_1c0141e0`); see the module docs.
pub const T: u32 = 0x1c0141e0;
pub const T_SRC: u32 = 0x00;
pub const T_OUT: u32 = 0x04;
pub const T_CUR: u32 = 0x08;
pub const T_BASE: u32 = 0x0c;
pub const T_WORD: u32 = 0x10;
pub const T_ROOM: u32 = 0x14;
pub const T_FLAGS: u32 = 0x18;
pub const T_STATE: u32 = 0x1c;

/// "@w<offset>" word-marker buffer and the copy pointer `fc50` walks over it.
const MARKER: u32 = 0x1c014210;
const MARKER_PTR: u32 = 0x1c014200;

/// `SVTextToPhon` errors.
pub const ERR_HANDLE: i32 = 0x1b61;
pub const ERR_NULL: i32 = 0x1b70;

/// Context offsets used here: language structure, user-dictionary entry count.
pub const CTX_LANG: u32 = 0x4f8;
pub const CTX_DICT_COUNT: u32 = 0x28;

/// Addresses of one language module's text-to-phoneme data (English values
/// in comments; Spanish from aligning the identical code of both DLLs).
pub struct Lang {
    pub id: u32,
    /// u16 character classes (`DAT_1c209c20`): 0x01 punctuation, 0x02 digit,
    /// 0x04..0x20 consonant classes, 0x40 vowel, 0x80 letter, 0x100 front
    /// vowel, 0x400 rule metacharacter.
    pub class: u32,
    /// Letter-to-sound rule lists: per character (`c744`), Ä, Ö, ß, Ü and
    /// everything else (`c8c4`); the "?" string (`c8c8`).
    lts: u32,
    lts_c4: u32,
    lts_d6: u32,
    lts_df: u32,
    lts_dc: u32,
    lts_other: u32,
    qmark: u32,
    /// Exception dictionary: per letter (`c7cc`), digits (`c938`), other (`c93c`).
    dict: u32,
    dict_digit: u32,
    dict_other: u32,
    /// Spelling: {char *, len} per ASCII char (`d318`), ". " (`d260`),
    /// "DAA5T " (`d718`), "POY5NT " (`c9a4`).
    spell: u32,
    spell_stop: u32,
    spell_dot: u32,
    spell_point: u32,
    /// Normalizer globals: token, next word, token end, next-word end,
    /// pattern ("##:##"), output, scratch number.
    pub g_tok: u32,
    pub g_next: u32,
    pub g_end1: u32,
    pub g_end2: u32,
    pub pat: u32,
    pub out: u32,
    pub buf: u32,
    /// Pattern table: {char *pattern, int len, handler} ending with handler 0.
    patterns: u32,
    /// "0123456789,.$%+-()/:"
    numchars: u32,
    /// Pattern characters: ' ', 'L', '#', '$', '%', '(', ')', ',', '-', '/', ':', '.'.
    p_space: u32,
    p_letter: u32,
    p_digit: u32,
    p_dollar: u32,
    p_percent: u32,
    p_lpar: u32,
    p_rpar: u32,
    p_comma: u32,
    p_dash: u32,
    p_slash: u32,
    p_colon: u32,
    p_dot: u32,
    /// Word tables: by character code (`cf08`), 0..19 (`cfc8`), tens (`d040`).
    pub digits: u32,
    pub ones: u32,
    pub tens: u32,
    /// ", " (`c9e0`).
    pub comma_sp: u32,
    /// Times: "OWKLAA5K ", "OW4 ", "AW5ER", "MIH5NAXT", "SEH5KUND", "Z- ",
    /// "S- " (minutes), "- ".
    pub t_oclock: u32,
    pub t_oh: u32,
    pub t_hour: u32,
    pub t_minute: u32,
    pub t_second: u32,
    pub t_plural_h: u32,
    pub t_plural_m: u32,
    pub t_dash: u32,
    /// "EH5RIYAH2 KOW5D " (area code).
    pub area: u32,
    /// Mixed tokens: '$', '+', '-', '.', '/', ':' words.
    pub m_dollar: u32,
    pub m_plus: u32,
    pub m_dash: u32,
    pub m_point: u32,
    pub m_slash: u32,
    pub m_colon: u32,
}

pub const EN: Lang = Lang {
    id: 1,
    class: 0x1c209c20,
    lts: 0x1c24c744,
    lts_c4: 0x1c24c8b0,
    lts_d6: 0x1c24c8b4,
    lts_df: 0x1c24c8b8,
    lts_dc: 0x1c24c8bc,
    lts_other: 0x1c24c8c4,
    qmark: 0x1c24c8c8,
    dict: 0x1c24c7cc,
    dict_digit: 0x1c24c938,
    dict_other: 0x1c24c93c,
    spell: 0x1c24d318,
    spell_stop: 0x1c24d260,
    spell_dot: 0x1c24d718,
    spell_point: 0x1c24c9a4,
    g_tok: 0x1c250128,
    g_next: 0x1c25011c,
    g_end1: 0x1c250124,
    g_end2: 0x1c250120,
    pat: 0x1c250130,
    out: 0x1c24ed90,
    buf: 0x1c24ed88,
    patterns: 0x1c24cae8,
    numchars: 0x1c24cbec,
    p_space: 0x1c24cbc0,
    p_letter: 0x1c24cbe8,
    p_digit: 0x1c24cbe4,
    p_dollar: 0x1c24cbd0,
    p_percent: 0x1c24cbcc,
    p_lpar: 0x1c24cbe0,
    p_rpar: 0x1c24cbdc,
    p_comma: 0x1c24cbd4,
    p_dash: 0x1c24cbd8,
    p_slash: 0x1c24cbc8,
    p_colon: 0x1c24cbc4,
    p_dot: 0x1c24ca00,
    digits: 0x1c24cf08,
    ones: 0x1c24cfc8,
    tens: 0x1c24d040,
    comma_sp: 0x1c24c9e0,
    t_oclock: 0x1c24cc04,
    t_oh: 0x1c24cc10,
    t_hour: 0x1c24cc3c,
    t_minute: 0x1c24cc28,
    t_second: 0x1c24cc18,
    t_plural_h: 0x1c24cc34,
    t_plural_m: 0x1c24cc24,
    t_dash: 0x1c24cc38,
    area: 0x1c24cc44,
    m_dollar: 0x1c24c9d4,
    m_plus: 0x1c24cc80,
    m_dash: 0x1c24cc88,
    m_point: 0x1c24c9a4,
    m_slash: 0x1c24cc90,
    m_colon: 0x1c24cc74,
};

pub const ES: Lang = Lang {
    id: 2,
    class: 0x1c409aa0,
    lts: 0x1c40e23c,
    lts_c4: 0x1c40e3a8,
    lts_d6: 0x1c40e3ac,
    lts_df: 0x1c40e3b0,
    lts_dc: 0x1c40e3b4,
    lts_other: 0x1c40e3bc,
    qmark: 0x1c40e3c0,
    dict: 0x1c40e2c4,
    dict_digit: 0x1c40e430,
    dict_other: 0x1c40e434,
    spell: 0x1c40ef58,
    spell_stop: 0x1c40ee84,
    spell_dot: 0x1c40f358,
    spell_point: 0x1c40f360,
    g_tok: 0x1c411d78,
    g_next: 0x1c411d6c,
    g_end1: 0x1c411d74,
    g_end2: 0x1c411d70,
    pat: 0x1c411d80,
    out: 0x1c4109e0,
    buf: 0x1c4109d0,
    patterns: 0x1c40e628,
    numchars: 0x1c40e728,
    p_space: 0x1c40e4f4,
    p_letter: 0x1c40e724,
    p_digit: 0x1c40e720,
    p_dollar: 0x1c40e70c,
    p_percent: 0x1c40e708,
    p_lpar: 0x1c40e71c,
    p_rpar: 0x1c40e718,
    p_comma: 0x1c40e710,
    p_dash: 0x1c40e714,
    p_slash: 0x1c40e704,
    p_colon: 0x1c40e700,
    p_dot: 0x1c40e548,
    digits: 0x1c40ead8,
    ones: 0x1c40eb98,
    tens: 0x1c40ec10,
    comma_sp: 0x1c40e4e4,
    t_oclock: 0x1c40e4f4,
    t_oh: 0x1c40e740,
    t_hour: 0x1c40e76c,
    t_minute: 0x1c40e758,
    t_second: 0x1c40e748,
    t_plural_h: 0x1c40e764,
    t_plural_m: 0x1c40e754,
    t_dash: 0x1c40e768,
    area: 0x1c40e4f4,
    m_dollar: 0x1c40e4d8,
    m_plus: 0x1c40e7cc,
    m_dash: 0x1c40e7d4,
    m_point: 0x1c40e7ec,
    m_slash: 0x1c40e7e0,
    m_colon: 0x1c40e7b8,
};

impl Lang {
    #[inline]
    pub fn cls(&self, m: &Mem, c: u8) -> u16 {
        m.u16(self.class + 2 * c as u32)
    }
    pub fn is_english(&self) -> bool {
        self.id == 1
    }
}

// ---- MSVCRT40 in the "C" locale ------------------------------------------

/// `_pctype` of the "C" locale (MSVCRT): 0x01 upper, 0x02 lower, 0x04 digit,
/// 0x08 space, 0x10 punct, 0x20 control, 0x40 blank, 0x80 hex, 0x100 alpha.
/// Nothing above 0x7f is classified.
pub fn ctype(c: u8) -> u16 {
    match c {
        0x00..=0x08 => 0x20,
        0x09..=0x0d => 0x28,
        0x0e..=0x1f => 0x20,
        0x20 => 0x48,
        0x21..=0x2f => 0x10,
        b'0'..=b'9' => 0x84,
        0x3a..=0x40 => 0x10,
        b'A'..=b'F' => 0x181,
        b'G'..=b'Z' => 0x101,
        0x5b..=0x60 => 0x10,
        b'a'..=b'f' => 0x182,
        b'g'..=b'z' => 0x102,
        0x7b..=0x7e => 0x10,
        0x7f => 0x20,
        _ => 0,
    }
}
#[inline]
pub fn isdigit(c: u8) -> bool {
    ctype(c) & 4 != 0
}
#[inline]
pub fn isspace(c: u8) -> bool {
    ctype(c) & 8 != 0
}
#[inline]
pub fn toupper(c: u8) -> u8 {
    if c.is_ascii_lowercase() { c - 0x20 } else { c }
}
#[inline]
pub fn tolower(c: u8) -> u8 {
    if c.is_ascii_uppercase() { c + 0x20 } else { c }
}

pub fn strlen(m: &Mem, s: u32) -> u32 {
    let mut p = s;
    while m.u8(p) != 0 {
        p += 1;
    }
    p - s
}

/// `strcat`: append `src` (with its NUL) at the end of `dst`.
pub fn strcat(m: &mut Mem, dst: u32, src: u32) {
    let mut d = dst + strlen(m, dst);
    let mut s = src;
    loop {
        let c = m.u8(s);
        m.set_u8(d, c);
        if c == 0 {
            break;
        }
        s += 1;
        d += 1;
    }
}

/// `strncat`: append at most `n` chars of `src` and a NUL (nothing for n <= 0).
pub fn strncat(m: &mut Mem, dst: u32, src: u32, n: i32) {
    let mut d = dst + strlen(m, dst);
    let mut s = src;
    let mut k = n.max(0) as u32;
    while k > 0 {
        let c = m.u8(s);
        if c == 0 {
            break;
        }
        m.set_u8(d, c);
        d += 1;
        s += 1;
        k -= 1;
    }
    m.set_u8(d, 0);
}

fn in_set(m: &Mem, set: u32, c: u8) -> bool {
    let mut p = set;
    loop {
        let x = m.u8(p);
        if x == 0 {
            return false;
        }
        if x == c {
            return true;
        }
        p += 1;
    }
}

pub fn strcspn(m: &Mem, s: u32, set: u32) -> u32 {
    let mut p = s;
    loop {
        let c = m.u8(p);
        if c == 0 || in_set(m, set, c) {
            return p - s;
        }
        p += 1;
    }
}

pub fn strspn(m: &Mem, s: u32, set: u32) -> u32 {
    let mut p = s;
    loop {
        let c = m.u8(p);
        if c == 0 || !in_set(m, set, c) {
            return p - s;
        }
        p += 1;
    }
}

/// `strchr` (0 if not found; finds the NUL for c == 0).
pub fn strchr(m: &Mem, s: u32, c: u8) -> u32 {
    let mut p = s;
    loop {
        let x = m.u8(p);
        if x == c {
            return p;
        }
        if x == 0 {
            return 0;
        }
        p += 1;
    }
}

pub fn strrchr(m: &Mem, s: u32, c: u8) -> u32 {
    let mut p = s;
    let mut found = 0;
    loop {
        let x = m.u8(p);
        if x == c {
            found = p;
        }
        if x == 0 {
            return found;
        }
        p += 1;
    }
}

/// `strncmp(a, b, n) == 0`
pub fn strneq(m: &Mem, a: u32, b: u32, n: u32) -> bool {
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

/// `strcmp(a, b) == 0`
pub fn streq(m: &Mem, a: u32, b: u32) -> bool {
    let mut k = 0;
    loop {
        let (x, y) = (m.u8(a + k), m.u8(b + k));
        if x != y {
            return false;
        }
        if x == 0 {
            return true;
        }
        k += 1;
    }
}

// ---- TIBASE32 ------------------------------------------------------------

/// Allocate an engine context good enough for text-to-phonemes: the
/// language structure at +0x4f8 and no user dictionary (+0x28 = 0).
pub fn context(m: &mut Mem, lang: &LangDef) -> u32 {
    let ctx = m.alloc(0x5a8);
    m.set_u32(ctx + CTX_LANG, lang.addr);
    ctx
}

/// Convert `text` (Latin-1, no NUL) to phonemes as `SVTextToPhon(ctx, text,
/// buf, out_cap, flags)` does, with `text` and the output buffer placed in
/// fresh heap blocks.  Returns the API result (0, an error code, or
/// -(n + 1) when the buffer filled up at input offset n) and the output
/// string (without its NUL).
///
/// `ctx` must be a context from [`context`] (or a snapshot) whose language
/// structure has been loaded (`lang::install`); `out_cap` must be > 0.
pub fn text_to_phon(m: &mut Mem, ctx: u32, text: &[u8], out_cap: i32, flags: u32) -> (i32, Vec<u8>) {
    let src = m.alloc(text.len() + 1);
    m.bytes_mut(src, text.len()).copy_from_slice(text);
    let cap = out_cap.max(1) as usize;
    let out = m.alloc(cap);
    let r = sv_text_to_phon(m, ctx, src, out, out_cap, flags);
    let mut s = Vec::new();
    for k in 0..cap as u32 {
        let c = m.u8(out + k);
        if c == 0 {
            break;
        }
        s.push(c);
    }
    m.free(src);
    m.free(out);
    (r, s)
}

/// What `fc50` writes to the cleaned copy for input character `c`: lower
/// case letters are upper-cased, a few Latin-1 symbols and letters are kept
/// (ä/ö/ü become Ä/Ö/Ü), ']' becomes a space unless flag 0x04, other
/// characters are kept if printable or blank in the "C" locale and become a
/// space otherwise (so all of 0x80..0xff not listed, and control chars).
pub fn clean_char(c: u8, flags: u32) -> u8 {
    if ctype(c) & 2 != 0 {
        return toupper(c);
    }
    match c {
        0xa2 | 0xa3 | 0xa5 | 0xa9 | 0xae | 0xb0 | 0xb1 | 0xbc | 0xbd | 0xbe | 0xc1 | 0xc4 | 0xc9 | 0xcd
        | 0xd1 | 0xd3 | 0xd6 | 0xd7 | 0xda | 0xdc | 0xdf | 0xe1 | 0xe9 | 0xed | 0xf1 | 0xf3 | 0xf7 | 0xfa => c,
        0xe4 => 0xc4,
        0xf6 => 0xd6,
        0xfc => 0xdc,
        b']' if flags & 4 == 0 => b' ',
        _ if ctype(c) & 0x157 != 0 => c,
        _ => b' ',
    }
}

/// Bytes kept around the calloc'ed copy: the rules may look a few bytes
/// past either end (left context of the first word, suffix checks).
const GUARD: u32 = 16;

/// `fc50` (`_SVTextToPhon@24`) on buffers already in memory.
pub fn sv_text_to_phon(m: &mut Mem, ctx: u32, text: u32, out: u32, cap: i32, flags: u32) -> i32 {
    if ctx == 0 {
        return ERR_HANDLE;
    }
    if text == 0 || out == 0 {
        return ERR_NULL;
    }
    m.set_u8(MARKER, b'@');
    m.set_u8(MARKER + 1, b'w');
    m.set_u8(MARKER + 2, 0);
    let len = strlen(m, text);
    // calloc((short)(strlen + 3))
    let size = (len as u16).wrapping_add(3) as i16 as i32;
    let block = m.alloc(size.max(0) as usize + 2 * GUARD as usize);
    // Not a space or a letter: what the heap header before the block is in
    // practice for the one rule that can look there.
    m.set_u8(block + GUARD - 1, 0x01);
    let buf = block + GUARD;
    m.set_u32(T + T_SRC, text);
    m.set_u32(T + T_OUT, out);
    m.set_u32(T + T_CUR, buf);
    m.set_u32(T + T_BASE, buf);
    m.set_i32(T + T_ROOM, cap);
    m.set_u32(T + T_FLAGS, flags);
    m.set_u32(T + T_STATE, 0);
    m.set_u8(buf, b' ');
    let mut d = buf + 1;
    if len > 0x202 {
        // Texts longer than 514 characters leave an empty string in front.
        m.set_u8(d, 0);
        d += 1;
    }
    let mut s = text;
    while m.u8(s) != 0 {
        let c = m.u8(s);
        s += 1;
        m.set_u8(d, clean_char(c, flags));
        d += 1;
    }
    m.set_u8(d, 0);
    m.set_u32(T + T_CUR, buf + 1);
    m.set_u8(out, 0);
    m.set_i32(T + T_ROOM, cap - 1);
    let mut w = buf + 1;
    while m.u8(w) == b' ' {
        w += 1;
    }
    let lang = m.u32(ctx + CTX_LANG);
    m.set_u32(CURRENT_LANG, lang);

    // `ebp`: where the output is cut on overflow; `esi`: offset of the word.
    let mut cut: Option<u32> = None;
    let mut off: i32 = 0;
    let mut eax = 0;
    if m.u8(w) != 0 {
        loop {
            off = (w.wrapping_sub(buf) as i32) - 1;
            if flags & 8 != 0 && ((m.u8(w) != b'{' && m.u8(w + 1) != b'{') || flags & 0x10 != 0) {
                ltoa(m, off, MARKER + 2);
                m.set_u32(MARKER_PTR, MARKER);
                let mlen = strlen(m, MARKER) as u16 as i16 as i32;
                if mlen + 2 >= m.i32(T + T_ROOM) {
                    eax = 1;
                    break;
                }
                m.set_i32(T + T_ROOM, m.i32(T + T_ROOM) - (mlen + 2));
                let mut o = m.u32(T + T_OUT);
                m.set_u8(o, b' ');
                o += 1;
                for _ in 0..mlen {
                    let p = m.u32(MARKER_PTR);
                    m.set_u8(o, m.u8(p));
                    m.set_u32(MARKER_PTR, p + 1);
                    o += 1;
                }
                cut = Some(o - 1);
                m.set_u8(o, b' ');
                o += 1;
                m.set_u8(o, 0);
                m.set_u32(T + T_OUT, o);
            }
            m.set_u32(T + T_WORD, w);
            let moved = w.wrapping_sub(m.u32(T + T_CUR));
            m.set_u32(T + T_SRC, m.u32(T + T_SRC).wrapping_add(moved));
            m.set_u32(T + T_CUR, w);
            if m.i32(T + T_ROOM) <= 1 {
                eax = 1;
                break;
            }
            let o = m.u32(T + T_OUT);
            cut = Some(o);
            m.set_u8(o, b' ');
            m.set_u8(o + 1, 0);
            m.set_u32(T + T_OUT, o + 1);
            m.set_i32(T + T_ROOM, m.i32(T + T_ROOM) - 1);
            eax = embedded_command(m, T);
            if eax != 0 {
                break;
            }
            eax = call_driver(m, lang, ctx, T);
            if eax != 0 {
                break;
            }
            w = m.u32(T + T_CUR);
            while m.u8(w) == b' ' {
                w += 1;
            }
            if m.u8(w) == 0 {
                break;
            }
        }
    }
    let mut r = 0;
    if eax == 1 {
        // The original writes through an uninitialized pointer if the very
        // first word does not fit; nothing sensible to model there.
        if let Some(c) = cut {
            m.set_u8(c, 0);
        }
        r = -1 - off;
    }
    m.free(block);
    r
}

/// `_ltoa(v, dst, 10)`.
fn ltoa(m: &mut Mem, v: i32, dst: u32) {
    let s = v.to_string();
    for (i, b) in s.bytes().enumerate() {
        m.set_u8(dst + i as u32, b);
    }
    m.set_u8(dst + s.len() as u32, 0);
}

/// `100d0`: copy an embedded "{{command}}" to the output as "{command}"
/// (lower-cased).  Returns 1 if it does not fit.
pub fn embedded_command(m: &mut Mem, t: u32) -> i32 {
    let dest = m.u32(t + T_OUT);
    let s = m.u32(t + T_CUR);
    m.set_u32(t + T_STATE, m.u32(t + T_STATE) & !4);
    if m.u8(t + T_FLAGS) & 0x10 != 0 {
        return 0;
    }
    if m.u8(s) != b'{' || m.u8(s + 1) != b'{' {
        return 0;
    }
    let mut c = m.u8(s + 2);
    let mut n: i32 = 0;
    let mut q = s + 3;
    let closed = loop {
        if c == 0 {
            break false;
        }
        if c == b'}' && m.u8(q) == b'}' {
            break true;
        }
        c = m.u8(q);
        n += 1;
        q += 1;
    };
    if !closed {
        return 0;
    }
    let count = n + 2;
    if count > m.i32(t + T_ROOM) {
        return 1;
    }
    strncat(m, dest, s + 1, count);
    m.set_i32(t + T_ROOM, m.i32(t + T_ROOM) - count);
    m.set_u32(t + T_OUT, m.u32(t + T_OUT).wrapping_add(count as u32));
    m.set_u32(t + T_CUR, q + 1);
    let mut d = dest;
    for _ in 0..n {
        d += 1;
        m.set_u8(d, tolower(m.u8(d)));
    }
    let o = m.u32(t + T_OUT);
    m.set_u8(o, 0);
    m.set_u32(t + T_STATE, m.u32(t + T_STATE) | 4);
    0
}

/// Call the language structure's slot [3] by its original address.
pub fn call_driver(m: &mut Mem, lang: u32, ctx: u32, t: u32) -> i32 {
    let f = m.u32(lang + 0xc);
    if f == ENGLISH.funcs[3] {
        driver(m, &EN, ctx, t)
    } else if f == SPANISH.funcs[3] {
        driver(m, &ES, ctx, t)
    } else {
        panic!("unknown text-to-phoneme driver {f:#x}")
    }
}

/// `2067c0` / `406250`: convert the word at T+8 (and whatever the
/// normalizer and rules leave in it).  Returns 1 when the output is full.
pub fn driver(m: &mut Mem, l: &Lang, ctx: u32, t: u32) -> i32 {
    let flags = m.u32(t + T_FLAGS);
    if flags & 4 != 0 {
        let r = spell(m, l, t);
        if r != 0 {
            return r;
        }
        m.set_u32(t + T_STATE, m.u32(t + T_STATE) & !4);
        return 0;
    }
    loop {
        m.set_u32(t + T_STATE, m.u32(t + T_STATE) & !4);
        let r = user_dictionary(m, ctx, t);
        if r != 0 {
            return r;
        }
        let r = rules::exceptions(m, l, t);
        if r != 0 {
            return r;
        }
        let r = numbers::normalize(m, l, t);
        if r != 0 {
            return r;
        }
        if m.u32(t + T_STATE) & 4 != 0 {
            continue;
        }
        let r = rules::letters(m, l, t);
        if r != 0 {
            return r;
        }
        let st = m.u32(t + T_STATE);
        if st & 4 != 0 {
            continue;
        }
        if flags & 2 != 0 || st & 1 != 0 {
            return if l.is_english() { rules::stress_en(m, l, t) } else { rules::stress_es(m, l, t) };
        }
        return 0;
    }
}

/// `2097a0` / `409620`: the user dictionary.  Only the "no dictionary
/// loaded" case (context +0x28 = 0 entries) is ported.
pub fn user_dictionary(m: &mut Mem, ctx: u32, _t: u32) -> i32 {
    if ctx == 0 || m.u32(ctx + CTX_DICT_COUNT) == 0 {
        return 0;
    }
    panic!("user dictionaries are not ported");
}

/// `209a00` / `409880`: spell mode.  Reads the word character by character
/// from the per-character table; '.' is "point" before a digit and "dot"
/// before another character, '?' at the end of a word is ". ".  A word that
/// ends at a space gets ", " (the last space of the output becomes ',').
pub fn spell(m: &mut Mem, l: &Lang, t: u32) -> i32 {
    let st = m.u32(t + T_STATE);
    let mut o = m.u32(t + T_OUT);
    let mut s = m.u32(t + T_CUR);
    let mut c;
    loop {
        c = m.u8(s);
        if c == 0 || c > 0x7f {
            break;
        }
        let mut w = m.u32(l.spell + 8 * c as u32);
        let c1 = m.u8(s + 1);
        if c == b'.' {
            if !isdigit(c1) {
                if !isspace(c1) && c1 != 0 {
                    w = l.spell_dot;
                }
            } else {
                w = l.spell_point;
            }
        } else if c == b'?' && (isspace(c1) || c1 == 0) {
            w = l.spell_stop;
        }
        let n = strlen(m, w) as i32;
        if m.i32(t + T_ROOM) < n {
            m.set_u32(t + T_STATE, 0);
            return 1;
        }
        m.set_i32(t + T_ROOM, m.i32(t + T_ROOM) - n);
        for k in 0..n as u32 {
            m.set_u8(o, m.u8(w + k));
            o += 1;
        }
        m.set_u8(o, 0);
        m.set_u32(t + T_SRC, m.u32(t + T_SRC).wrapping_add(1));
        m.set_u32(t + T_CUR, m.u32(t + T_CUR).wrapping_add(1));
        m.set_u32(t + T_OUT, o);
        m.set_u32(t + T_STATE, st | 6);
        s += 1;
        if isspace(c) {
            break;
        }
    }
    if c != 0 {
        if m.i32(t + T_ROOM) == 0 {
            m.set_u32(t + T_STATE, 0);
            return 1;
        }
        m.set_i32(t + T_ROOM, m.i32(t + T_ROOM) - 1);
        m.set_u8(o - 1, b',');
        m.set_u8(o, b' ');
        m.set_u8(o + 1, 0);
        m.set_u32(t + T_OUT, o + 1);
        m.set_u32(t + T_STATE, st | 6);
    }
    0
}
