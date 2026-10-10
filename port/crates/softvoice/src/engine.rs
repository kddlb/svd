//! The public engine: a port of TIBASE32's exported API (`SVOpenSpeech`,
//! `SVSetPersonality`, the `SVSet*` setters, `SVNarrate`) and of the
//! narrate driver (`3870`) and window-procedure loop that chain phrases
//! into one PCM stream.  Instead of playing through waveOut, `narrate`
//! returns the samples and the sync events with their sample positions.

use crate::front::{self, parse, prosody, records, timing};
use crate::lang::{self, LangDef};
use crate::mem::Mem;
use crate::synth::{post, Generator, RawEvent, SAMPLE_RATE};

/// Error codes (see sdk/softvoice.h).
pub const ERR_PHONEME: u32 = 7001;
pub const ERR_NO_MEMORY: u32 = 7002;
pub const ERR_PARAM_RANGE: u32 = 7010;
pub const ERR_EMBEDDED_COMMAND: u32 = 7015;
pub const ERR_LANGUAGE: u32 = 7022;

/// Sync message codes (`wParam` of "SVSyncMessages").
pub const SYNC_START: u16 = 1000;
pub const SYNC_DONE: u16 = 1001;
pub const SYNC_PLAYING: u16 = 1002;
pub const SYNC_WORD: u16 = 1003;
pub const SYNC_PHONEME: u16 = 1006;
pub const SYNC_INDEX: u16 = 1007;
pub const SYNC_MOUTH: u16 = 1008;

/// Voice presets in TIBASE (0x4a bytes each).
const PRESETS: u32 = 0x1c013600;
/// Size of the engine context.
const CTX_SIZE: usize = 0x5a8;
/// Offset of the synthesis state block S within the context.
const S: u32 = 0x13a;

/// Language selector for `set_language`.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Language {
    English = 1,
    Spanish = 2,
}

/// A sync event at a position in the output.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct Event {
    pub code: u16,
    pub value: u16,
    /// Sample index in `Utterance::pcm` at which the event is due.
    pub sample: usize,
}

/// The result of speaking a phoneme string.
#[derive(Clone, Debug, Default)]
pub struct Utterance {
    /// 8-bit unsigned mono PCM at 11025 Hz.
    pub pcm: Vec<u8>,
    pub events: Vec<Event>,
    /// Error reported by the end-of-speech message (0 = success).
    pub done_error: u16,
    /// With `Engine::hifi`: the same audio as 16-bit samples at 11025 Hz,
    /// without the original's 8-bit truncation (an extension, not bit-exact
    /// with anything in the original).
    pub pcm16: Option<Vec<i16>>,
}

impl Utterance {
    /// 16-bit samples at `rate` Hz: the hi-fi stream if present, otherwise
    /// the 8-bit stream widened, resampled from 11025 Hz.
    pub fn pcm16_at(&self, rate: u32) -> Vec<i16> {
        let base: Vec<i16> = match &self.pcm16 {
            Some(p) => p.clone(),
            None => self.pcm.iter().map(|&b| ((b as i16) - 0x80) << 8).collect(),
        };
        crate::synth::resample::resample(&base, SAMPLE_RATE, rate)
    }
}

pub struct Engine {
    pub mem: Mem,
    /// Address of the engine context in `mem`.
    pub ctx: u32,
    generator: Generator,
    /// Also produce `Utterance::pcm16` (see there).  Off by default.
    pub hifi: bool,
}

impl Default for Engine {
    fn default() -> Self {
        Self::new()
    }
}

impl Engine {
    /// `SVOpenSpeech(.., SV_LANG_ENGLISH | SV_LANG_SPANISH, ..)`.
    pub fn new() -> Self {
        Self::with_memory(Mem::new())
    }

    /// Like `new`, on a prepared memory model (tests use allocation hints so
    /// that heap blocks land where the original's did).
    pub fn with_memory(mut mem: Mem) -> Self {
        lang::install(&mut mem);
        let ctx = mem.alloc(CTX_SIZE);
        mem.set_u32(ctx + 0x504, 3); // available languages
        mem.set_u32(ctx, 0); // notification window
        mem.set_u32(ctx + 0xc, u32::MAX); // WAVE_MAPPER
        mem.set_u32(ctx + 0x14, 0x20001);
        mem.set_u32(ctx + 0x18, 0x6a);
        let en = lang::ENGLISH.addr;
        mem.set_u32(ctx + 0x4f8, en);
        mem.set_u32(ctx + 0x4fc, en);
        copy_preset(&mut mem, ctx + 0xd0, 0, 0x6a);
        mem.set_u32(ctx + 0x500, mem.u32(en + 0x14));
        let ring = mem.alloc(0xce8);
        mem.set_u32(ctx + 0xa4, ring);
        Engine { mem, ctx, generator: Generator::default(), hifi: false }
    }

    fn c(&self, off: u32) -> u32 {
        self.ctx + off
    }

    /// `SVSetLanguage` (`f150`).
    pub fn set_language(&mut self, lang: Language) {
        let def: &LangDef = match lang {
            Language::English => &lang::ENGLISH,
            Language::Spanish => &lang::SPANISH,
        };
        let m = &mut self.mem;
        m.set_u32(self.ctx + 0x4f8, def.addr);
        m.set_u32(self.ctx + 0x4fc, def.addr);
        let table = if m.i16(self.ctx + 0xd8) != 1 { def.addr + 0x14 } else { def.addr + 0x18 };
        let t = m.u32(table);
        m.set_u32(self.ctx + 0x500, t);
    }

    /// `SVSetPersonality`: load preset 0..19.
    pub fn set_personality(&mut self, preset: u16) -> Result<(), u32> {
        if preset >= 0x14 {
            return Err(ERR_PARAM_RANGE);
        }
        copy_preset(&mut self.mem, self.ctx + 0xd0, preset as u32, 0x6a);
        let lang = self.mem.u32(self.ctx + 0x4fc);
        let table = match preset {
            1 | 5 | 0xd | 0xf => self.mem.u32(lang + 0x18),
            _ => self.mem.u32(lang + 0x14),
        };
        self.mem.set_u32(self.ctx + 0x500, table);
        Ok(())
    }

    fn set_checked(&mut self, off: u32, v: u16, ok: bool) -> Result<(), u32> {
        if !ok {
            return Err(ERR_PARAM_RANGE);
        }
        let a = self.c(off);
        self.mem.set_u16(a, v);
        Ok(())
    }

    pub fn set_pitch(&mut self, hz: u16) -> Result<(), u32> {
        self.set_checked(0xd4, hz, (10..=2000).contains(&hz))
    }
    pub fn set_rate(&mut self, wpm: u16) -> Result<(), u32> {
        self.set_checked(0xd6, wpm, (20..=500).contains(&wpm))
    }
    pub fn set_gender(&mut self, v: u16) -> Result<(), u32> {
        self.set_checked(0xd8, v, v < 4)
    }
    pub fn set_glottal_source(&mut self, v: u16) -> Result<(), u32> {
        self.set_checked(0xda, v, v < 9)
    }
    pub fn set_voicing_mode(&mut self, v: u16) -> Result<(), u32> {
        self.set_checked(0xdc, v, v < 3)
    }
    pub fn set_f0_style(&mut self, v: u16) -> Result<(), u32> {
        self.set_checked(0xe0, v, v < 5)
    }
    pub fn set_f0_range(&mut self, v: u16) -> Result<(), u32> {
        self.set_checked(0xe2, v, v < 0x1f5)
    }
    pub fn set_f0_perturb(&mut self, v: u16) -> Result<(), u32> {
        self.set_checked(0xe4, v, v < 0x1f5)
    }
    pub fn set_vowel_factor(&mut self, v: i16) {
        let a = self.c(0xf2);
        self.mem.set_i16(a, v);
    }
    pub fn set_av_bias(&mut self, v: i16) {
        let a = self.c(0xf8);
        self.mem.set_i16(a, v);
    }
    pub fn set_ah_bias(&mut self, v: i16) {
        let a = self.c(0xfa);
        self.mem.set_i16(a, v);
    }
    pub fn set_af_bias(&mut self, v: i16) {
        let a = self.c(0xfc);
        self.mem.set_i16(a, v);
    }
    /// `SVSetSpeakingMode`: bit 2 sets the "spell" narrate flag.
    pub fn set_speaking_mode(&mut self, mode: u16) -> Result<(), u32> {
        if mode & 7 == 0 {
            return Err(ERR_PARAM_RANGE);
        }
        let a = self.c(0xcc);
        let f = self.mem.u32(a);
        self.mem.set_u32(a, if mode & 2 != 0 { f | 0x10 } else { f & !0x10 });
        Ok(())
    }

    /// Raw voice settings (the 0x6a-byte SVVOICEINFO at context + 0xd0).
    pub fn voice_info(&self) -> &[u8] {
        self.mem.bytes(self.ctx + 0xd0, 0x6a)
    }

    /// `SVGetVoiceInfo(preset)`: a preset's SVVOICEINFO (0x6a bytes; the
    /// name pointer at +0 is not meaningful outside the engine).
    pub fn preset_info(&mut self, preset: u16) -> Result<Vec<u8>, u32> {
        if preset >= 0x14 {
            return Err(ERR_PARAM_RANGE);
        }
        let tmp = self.mem.alloc(0x6a);
        copy_preset(&mut self.mem, tmp, preset as u32, 0x6a);
        let v = self.mem.bytes(tmp, 0x6a).to_vec();
        self.mem.free(tmp);
        Ok(v)
    }

    /// Number of built-in presets.
    pub const PRESETS: u16 = 20;

    /// `SVTextToPhon`: text (Latin-1) to a phoneme string in the current
    /// language.  `flags` are SV_TTP_* (0x08 inserts "@w<offset>" word
    /// markers); `cap` is the output buffer size.  Returns the original's
    /// result (0, an error code, or -(n + 1) when the buffer filled at input
    /// offset n) and the phonemes.  Like the original, input longer than
    /// 514 characters yields an empty string.
    pub fn text_to_phonemes_raw(&mut self, text: &[u8], flags: u32, cap: i32) -> (i32, Vec<u8>) {
        crate::ttp::text_to_phon(&mut self.mem, self.ctx, text, cap, flags)
    }

    /// Text to phonemes for any length of text (an extension): the text is
    /// converted in pieces of at most 500 characters, split after sentence
    /// ends or spaces, and "@w" offsets are rebased onto the whole text.
    /// For texts that fit in one piece this is exactly `SVTextToPhon` with
    /// a 0x2800-byte buffer, as Talk It! calls it.
    pub fn text_to_phonemes(&mut self, text: &[u8], flags: u32) -> Result<Vec<u8>, i32> {
        const PIECE: usize = 500;
        let mut out = Vec::new();
        let mut start = 0;
        while start < text.len() {
            let mut end = (start + PIECE).min(text.len());
            if end < text.len() {
                let piece = &text[start..end];
                let cut = piece
                    .iter()
                    .rposition(|&c| matches!(c, b'.' | b'?' | b'!'))
                    .or_else(|| piece.iter().rposition(|&c| c == b' '))
                    .map(|i| start + i + 1)
                    .filter(|&e| e > start);
                end = cut.unwrap_or(end);
            }
            let (r, p) = self.text_to_phonemes_raw(&text[start..end], flags, 0x2800);
            if r > 0 {
                return Err(r);
            }
            if !out.is_empty() {
                out.push(b' ');
            }
            out.extend(rebase_word_markers(&p, start));
            start = end;
        }
        Ok(out)
    }

    /// `SVNarrate`: speak a phoneme string (see sdk/softvoice.h for the
    /// format).  `flags` are SV_NARRATE_* flags.  Returns the PCM and sync
    /// events, or the error `SVNarrate` itself would return.
    pub fn narrate(&mut self, phonemes: &[u8], flags: u32) -> Result<Utterance, u32> {
        self.narrate_at(phonemes, flags, None)
    }

    /// `narrate` with the phoneme string placed at a fixed address (tests
    /// reproduce the oracle's buffer address).
    pub fn narrate_at(&mut self, phonemes: &[u8], flags: u32, string_addr: Option<u32>) -> Result<Utterance, u32> {
        let mut out = Utterance::default();
        if !self.begin(phonemes, flags, string_addr) {
            out.events.push(Event { code: SYNC_START, value: 0, sample: 0 });
            out.events.push(Event { code: SYNC_DONE, value: 0, sample: 0 });
            return Ok(out);
        }
        let s = self.ctx + S;
        let mut first = true;
        loop {
            let phrase_start = out.pcm.len();
            match self.phrase(s) {
                Phrase::Started => {
                    let m = &mut self.mem;
                    let flags = m.u32(s + 0x4e);
                    if flags & 0x8000_0000 != 0 {
                        out.events.push(Event { code: SYNC_START, value: 0, sample: phrase_start });
                        m.set_u32(s + 0x4e, flags ^ 0x8000_0000);
                    }
                    out.events.push(Event { code: SYNC_PLAYING, value: 0, sample: phrase_start });
                    let g = &mut self.generator;
                    let frames_addr = self.mem.u32(s + 0xf6);
                    let frames = self.mem.block(frames_addr).expect("frame buffer").to_vec();
                    g.start_phrase(self.mem.u32(s + 0x48), self.mem.u32(s + 0x4e));
                    g.hifi = self.hifi.then(Vec::new);
                    g.generate(&frames, &mut out.pcm, 0x2000);
                    while g.running != 0 {
                        g.generate(&frames, &mut out.pcm, 0x1000);
                    }
                    for e in g.events.drain(..) {
                        out.events.push(raw_event(e, phrase_start));
                    }
                    if let Some(h) = g.hifi.take() {
                        out.pcm16.get_or_insert_with(Vec::new).extend(h);
                    }
                    // c3da0: the phrase's frames are released.
                    self.mem.free(frames_addr);
                    self.mem.set_u32(s + 0xf6, 0);
                }
                Phrase::Finished => break,
                Phrase::Failed(err) => {
                    if first {
                        return Err(err as u32);
                    }
                    out.done_error = err as u16;
                    out.events.push(Event { code: SYNC_DONE, value: err as u16, sample: out.pcm.len() });
                    return Ok(out);
                }
                Phrase::Empty => {
                    out.events.push(Event { code: SYNC_DONE, value: 0, sample: out.pcm.len() });
                    return Ok(out);
                }
            }
            first = false;
        }
        out.events.push(Event { code: SYNC_DONE, value: 0, sample: out.pcm.len() });
        Ok(out)
    }

    /// `SVNarrate`'s set-up before the first phrase.  Returns false for an
    /// empty string (which only produces START and DONE).
    pub fn begin(&mut self, phonemes: &[u8], flags: u32, string_addr: Option<u32>) -> bool {
        let ctx = self.ctx;
        let mut text = phonemes.iter().copied().take_while(|&b| b != 0).collect::<Vec<u8>>();
        if text.is_empty() {
            return false;
        }
        text.push(0);
        let addr = match string_addr {
            Some(a) => {
                self.mem.map(a, text);
                a
            }
            None => {
                let a = self.mem.alloc(text.len());
                self.mem.bytes_mut(a, text.len()).copy_from_slice(&text);
                a
            }
        };
        let m = &mut self.mem;
        m.set_u32(ctx + 0x1c, 2);
        let ring = m.u32(ctx + 0xa4);
        m.set_u16(ring, 0);
        m.set_u16(ring + 2, 0);
        m.set_u32(ctx + 0xc8, addr);
        copy_voice_to_synth(m, ctx);
        m.set_u32(ctx + 0x176, m.u32(ctx + 0x4f8));
        m.set_u32(ctx + 0x172, m.u32(ctx + 0x4fc));
        m.set_u32(ctx + 0x17a, m.u32(ctx + 0x500));
        let mut f = m.u32(ctx + 0x188) | flags | 0x8000_0000;
        if f & 0x4000_0000 == 0 {
            f |= 0xa000_0000;
        }
        m.set_u32(ctx + 0x188, f);
        m.set_u32(ctx + 0x156, 0);
        true
    }

    /// One call of the narrate driver `3870`: build the next phrase's
    /// frames.
    fn phrase(&mut self, s: u32) -> Phrase {
        let m = &mut self.mem;
        let ctx = s - S;
        m.set_u32(0x1c0145ac, 0);
        m.set_u32(0x1c0145a8, 0);
        m.set_u32(0x1c0145a4, 0);
        m.set_u32(ctx + 0x230, 0);
        m.set_u32(ctx + 0x1fa, 0);
        m.set_u8(ctx + 0x457, 0);
        if parse::split_sentence(m, s) == 0 {
            m.set_u8(ctx + 0x457, 0);
            release_phrase(m, s);
            return Phrase::Finished;
        }
        front::alloc_records(m, s);
        let r = parse::parse(m, s);
        if r != 0 {
            release_phrase(m, s);
            return if r == parse::EMPTY_PHRASE { Phrase::Empty } else { Phrase::Failed(r) };
        }
        records::assign_voice(m, s);
        records::mark_onsets(m, s);
        records::apply_allophones(m, s);
        records::syllabify(m, s);
        records::mark_after_boundary(m, s);
        if prosody::alloc_syllables(m, s) != 0 {
            release_phrase(m, s);
            return Phrase::Failed(ERR_NO_MEMORY as i32);
        }
        prosody::mark_syllables(m, s);
        prosody::f0_contour(m, s);
        timing::durations(m, s);
        timing::tempo(m, s);
        let r = timing::alloc_frames(m, s);
        if r != 0 {
            release_phrase(m, s);
            return Phrase::Failed(r);
        }
        timing::frames(m, s);
        post::fill_f0(m, s);
        post::smooth_f0(m, s);
        post::smooth_f0(m, s);
        post::modulate(m, s);
        m.set_u16(ctx + 0x448, 0xff);
        let running = (m.i16(ctx + 0x44a) != 0x65) as u16;
        m.set_u16(ctx + 0x44e, running);
        release_phrase(m, s);
        Phrase::Started
    }
}

enum Phrase {
    /// Frames are ready (at S+0xf6).
    Started,
    /// No more sentences.
    Finished,
    /// The phrase was empty: speech ends.
    Empty,
    Failed(i32),
}

/// `3f50(ctx, 0)`: release the phrase's records, commands and syllables.
fn release_phrase(m: &mut Mem, s: u32) {
    let ctx = s - S;
    for off in [0x156, 0x16e, 0x1fa] {
        let p = m.u32(ctx + off);
        if p != 0 {
            m.free(p);
        }
        m.set_u32(ctx + off, 0);
    }
}

fn raw_event(e: RawEvent, phrase_start: usize) -> Event {
    let code = match e.code {
        0x3eb => SYNC_WORD,
        0x3ee => SYNC_PHONEME,
        0x3ef => SYNC_INDEX,
        0x3f0 => SYNC_MOUTH,
        c => c,
    };
    Event { code, value: e.value, sample: phrase_start + (e.time as usize * SAMPLE_RATE as usize) / 1000 }
}

/// `e120`: copy voice preset `idx` into the SVVOICEINFO at `dst`.  With
/// `size == 0x6a` the name is copied too.
pub fn copy_preset(m: &mut Mem, dst: u32, idx: u32, size: u16) {
    let p = PRESETS + idx * 0x4a;
    if size == 0x6a {
        let name = m.u32(p);
        let mut buf = [0u8; 0x20];
        let mut i = 0;
        while i < 0x20 {
            let c = m.u8(name + i as u32);
            if c == 0 {
                break;
            }
            buf[i] = c;
            i += 1;
        }
        m.bytes_mut(dst + 0x4a, 0x20).copy_from_slice(&buf);
        m.set_u32(dst, dst + 0x4a);
        m.set_u8(dst + 0x69, 0);
    }
    // (destination offset, preset offset) for each 16-bit field.
    const MAP: [(u32, u32); 35] = [
        (0x04, 0x04), (0x06, 0x08), (0x08, 0x0a), (0x0a, 0x0c), (0x0c, 0x0e), (0x0e, 0x10),
        (0x10, 0x12), (0x12, 0x14), (0x14, 0x16), (0x16, 0x18), (0x18, 0x1a), (0x1a, 0x1c),
        (0x1c, 0x1e), (0x1e, 0x20), (0x20, 0x22), (0x22, 0x24), (0x24, 0x26), (0x26, 0x28),
        (0x2e, 0x2a), (0x30, 0x2c), (0x32, 0x2e), (0x28, 0x30), (0x2a, 0x32), (0x2c, 0x34),
        (0x34, 0x36), (0x36, 0x38), (0x38, 0x3a), (0x3a, 0x3c), (0x3c, 0x3e), (0x3e, 0x40),
        (0x40, 0x42), (0x42, 0x44), (0x44, 0x46), (0x46, 0x48), (0x48, 0x06),
    ];
    for (d, s) in MAP {
        let v = m.u16(p + s);
        m.set_u16(dst + d, v);
    }
}

/// `df20`: copy the voice settings (context + 0xd0..) into the synthesis
/// state and reset per-utterance synthesis parameters.
fn copy_voice_to_synth(m: &mut Mem, ctx: u32) {
    let w = |m: &mut Mem, to: u32, from: u32| {
        let v = m.u16(ctx + from);
        m.set_u16(ctx + to, v);
    };
    m.set_u32(ctx + 0x13a, ctx);
    m.set_u32(ctx + 0x188, m.u32(ctx + 0xcc));
    m.set_u32(ctx + 0x142, m.u32(ctx + 0xc8));
    w(m, 0x17e, 0xd6);
    w(m, 0x180, 0xd4);
    w(m, 0x3f2, 0xd4);
    m.set_u16(ctx + 0x182, SAMPLE_RATE as u16);
    w(m, 0x186, 0xe0);
    w(m, 0x19a, 0xe2);
    w(m, 0x19c, 0xe4);
    w(m, 0x19e, 0xe8);
    w(m, 0x1a0, 0xea);
    w(m, 0x18c, 0xd8);
    w(m, 0x42c, 0xdc);
    w(m, 0x1c4, 0xde);
    w(m, 0x196, 0xf4);
    w(m, 0x198, 0xf6);
    m.set_u32(ctx + 0x190, m.u16(ctx + 0xf2) as u32);
    w(m, 0x194, 0xda);
    m.set_u32(ctx + 0x14e, 0);
    w(m, 0x1be, 0xf8);
    w(m, 0x1c0, 0xfa);
    w(m, 0x1c2, 0xfc);
    w(m, 0x1b8, 0xfe);
    w(m, 0x1ba, 0x100);
    w(m, 0x1bc, 0x102);
    w(m, 0x1c6, 0x10a);
    w(m, 0x1c8, 0x10c);
    w(m, 0x1ca, 0x10e);
    w(m, 0x1cc, 0x104);
    w(m, 0x1ce, 0x106);
    w(m, 0x1d0, 0x108);
    w(m, 0x1d2, 0x110);
    w(m, 0x1d6, 0x114);
    w(m, 0x1d4, 0x112);
    w(m, 0x1d8, 0x116);
    w(m, 0x1e6, 0x118);
    m.set_u16(ctx + 0x1e8, 0);
    m.set_u16(ctx + 0x1e2, 0x50);
    m.set_u16(ctx + 0x1e4, 0x2ee);
    m.set_u32(ctx + 0x1a8, 0);
    m.set_u16(ctx + 0x1ac, 0);
    m.set_u32(ctx + 0x1ae, 0);
    m.set_u16(ctx + 0x1a2, 0x41);
    m.set_u16(ctx + 0x1a6, 10);
    m.set_u16(ctx + 0x1ea, 0x60);
    m.set_u16(ctx + 0x1ee, 0x8c);
    m.set_u16(ctx + 0x1ec, 200);
    m.set_u32(ctx + 0x452, 0);
    m.set_u16(ctx + 0x44c, 0xff);
}

/// Add `offset` to every "@w<n>" marker in a phoneme string.
fn rebase_word_markers(p: &[u8], offset: usize) -> Vec<u8> {
    if offset == 0 {
        return p.to_vec();
    }
    let mut out = Vec::with_capacity(p.len() + 16);
    let mut i = 0;
    while i < p.len() {
        if p[i] == b'@' && p.get(i + 1) == Some(&b'w') && p.get(i + 2).is_some_and(u8::is_ascii_digit) {
            let mut j = i + 2;
            let mut n = 0usize;
            while j < p.len() && p[j].is_ascii_digit() {
                n = n * 10 + (p[j] - b'0') as usize;
                j += 1;
            }
            out.extend_from_slice(format!("@w{}", n + offset).as_bytes());
            i = j;
        } else {
            out.push(p[i]);
            i += 1;
        }
    }
    out
}
