//! Sample generator: port of the hand-written assembly routine `402c`
//! (TIBASE32 0x1c00402c..0x1c00498e, disassembly in port/re/gen_402c.asm).
//!
//! A cascade formant synthesizer: a two-table crossfaded glottal source,
//! differentiated and shaped by a "tilt" resonator, plus aspiration noise,
//! through R5 -> R1 -> R3 -> R4 -> R2, plus a parallel frication branch,
//! companded to 8-bit unsigned PCM through a lookup table.
//!
//! All arithmetic mirrors the 16-bit x86 code: wrapping 16-bit adds,
//! 16x16->32 `imul`, and `shld` extraction of 16 bits from the product.
//! Field comments give the offset in the original state block
//! (S = context + 0x13a).

use crate::image::TIBASE;

/// Soft-clip / companding curve, indexed by sample -200..=200 (bytes).
const OUT_LUT: u32 = 0x1c0011c6;
/// dB -> linear amplitude, u16, indexed by *byte* offset (frame amplitudes).
const AMP_TABLE: u32 = 0x1c001308;
/// 1023 (aspiration, frication) i16 pairs.
const NOISE_TABLE: u32 = 0x1c001570;
const NOISE_LEN: u16 = 0x3ff;
/// R1-R3 coefficient `a` [freq code][bandwidth code], i16.
const RES_A: u32 = 0x1c002570;
/// R1-R3 coefficient `b` by bandwidth code, i16.
const RES_B: u32 = 0x1c003070;
/// R4/R5/frication coefficient `a` [freq code][bandwidth code], u16.
const RES_A_HI: u32 = 0x1c003090;
/// R4/R5/frication coefficient `b` by bandwidth code, u16.
const RES_B_HI: u32 = 0x1c003690;
/// Glottal tilt filter `a` / `b` by tilt code, i16.
const TILT_A: u32 = 0x1c0036b0;
const TILT_B: u32 = 0x1c0036d0;
/// 12 pointers to glottal waveform tables (1024 x i16 each).
const GLOTTAL_PTRS: u32 = 0x1c013bd0;
/// Frame-length scale: samples/frame = rate * 150 / 60 / (2 * frame[0xa]) / 2.
const SPF_MUL: u32 = 0x1c0120e8;
const SPF_DIV: u32 = 0x1c0120ea;

/// Frame field offsets (32-byte records).
mod f {
    pub const F1: usize = 0x00;
    pub const F2: usize = 0x01;
    pub const F3: usize = 0x02;
    pub const F4: usize = 0x03;
    pub const F5: usize = 0x04;
    pub const B1B2: usize = 0x06;
    pub const B3_TILT: usize = 0x07;
    pub const B4B5: usize = 0x08;
    pub const FRIC_F: usize = 0x09;
    pub const RATE: usize = 0x0a;
    pub const PHONEME: usize = 0x0b;
    pub const GLOT_A: usize = 0x0d;
    pub const GLOT_B: usize = 0x0e;
    pub const GLOT_MIX: usize = 0x0f;
    pub const AV: usize = 0x10;
    pub const AH: usize = 0x11;
    pub const AF: usize = 0x12;
    pub const BYPASS: usize = 0x13;
    pub const FRIC_BW: usize = 0x14;
    pub const SYNC: usize = 0x17;
    pub const F0: usize = 0x18;
    pub const MOUTH: usize = 0x1a;
    pub const INDEX: usize = 0x1b;
    pub const WORD: usize = 0x1c;
}

/// A sync event queued by the generator (`498f`).
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct RawEvent {
    pub code: u16,
    /// Milliseconds since the start of the phrase (S+0xfe >> 6).
    pub time: u32,
    pub value: u16,
    pub dvalue: u32,
}

/// Two-pole resonator state: low word = y[n-1], high word = y[n-2].
#[inline]
fn resonate(state: &mut u32, x: i16, a: i16, b: i16) -> i16 {
    let y1 = *state as u16 as i16;
    let y2 = (*state >> 16) as u16 as i16;
    let t1 = ((y1.wrapping_sub(x) as i32 * a as i32) >> 14) as i16; // shld dx,ax,2
    let t2 = ((y2.wrapping_sub(x) as i32 * b as i32) >> 15) as i16; // shld dx,ax,1
    let y = x.wrapping_sub(t2).wrapping_add(t1);
    *state = (y as u16 as u32) | ((y1 as u16 as u32) << 16);
    y
}

/// `imul` then `shld dx,ax,1`: bits 15..30 of the signed product.
#[inline]
fn mul15(a: i16, b: i16) -> i16 {
    ((a as i32 * b as i32) >> 15) as i16
}

#[inline]
fn shld16(dst: u16, src: u16, n: u32) -> u16 {
    (((dst as u32) << n) | ((src as u32) >> (16 - n))) as u16
}

/// The output curve at full precision: `sum / 32` through the 401-point
/// companding table, linearly interpolated, scaled to 16 bits.
fn smooth_sample(sum: i16) -> i16 {
    let x = sum as i32;
    let lo = x.div_euclid(32);
    let frac = x.rem_euclid(32);
    let at = |v: i32| TIBASE.u8((OUT_LUT as i32 + v.clamp(-200, 200)) as u32) as i8 as i32;
    let (a, b) = if lo >= 200 { (at(200), at(200)) } else if lo < -200 { (at(-200), at(-200)) } else { (at(lo), at(lo + 1)) };
    let y = (a * 32 + (b - a) * frac) * 8; // 8.5 fixed point -> 16 bits
    y.clamp(-32768, 32767) as i16
}

/// High word of a 16.16 accumulator.
#[inline]
fn hi(v: u32) -> i16 {
    (v >> 16) as u16 as i16
}

#[derive(Clone, Debug, Default)]
pub struct Generator {
    // --- per-utterance setup (copied in by the driver) ---
    /// S+0x48: sample rate (low word used).
    pub rate: u32,
    /// S+0x4e: narrate flags (sync enables, 0x40 = no sync events).
    pub flags: u32,

    // --- frame walk ---
    /// S+0xfa as a frame index (S+0xf6 is frame 0).
    pub frame: usize,
    /// S+0xfe: elapsed time in 1/64 ms.
    pub elapsed: u32,
    /// S+0x2bc: samples per frame.
    pub spf: u16,
    /// S+0x2fa: 0x10000 / spf, the interpolation step multiplier.
    pub step16: i16,
    /// S+0x30c: samples left in the current frame.
    pub frame_left: u16,
    /// S+0x30e: non-zero = (re)initialise on the next call.
    pub first: u16,
    /// S+0x314: non-zero while running; cleared at the end of the phrase.
    pub running: u16,
    /// S+0x312: last mouth shape sent.
    pub mouth: u8,

    // --- glottal source ---
    /// S+0x2fc: 26-bit phase accumulator.
    pub phase: u32,
    /// S+0x300: phase increment (F0 << 9).
    pub phase_inc: u32,
    /// S+0x2d8 / S+0x2dc: waveform table addresses.
    pub glot_a: u32,
    pub glot_b: u32,
    /// S+0x268 / S+0x270: crossfade weights.
    pub mix_a: i16,
    pub mix_b: i16,
    /// S+0x276 (16.16) / S+0x27a: voicing amplitude and its step.
    pub av: u32,
    pub av_step: u32,
    /// S+0x2aa: previous voiced sample << 16 (differentiator).
    pub diff_prev: u32,

    // --- noise gains (16.16, high word used) ---
    /// S+0x27e / S+0x286: current AH / AF as loaded per frame.
    pub ah: u32,
    pub af: u32,
    /// S+0x296 / S+0x29a: AH for negative / non-negative voiced sample.
    pub ah_neg: u32,
    pub ah_pos: u32,
    /// S+0x29e / S+0x2a2: AF for negative / non-negative voiced sample.
    pub af_neg: u32,
    pub af_pos: u32,
    /// S+0x280 / S+0x288: AH / AF picked for the current sample.
    pub cur_ah: i16,
    pub cur_af: i16,
    /// S+0x28e: frication bypass mix (high word).
    pub bypass: u32,
    /// S+0x2e4: noise table position (pairs); S+0x2ee: pairs left.
    pub noise_pos: u16,
    pub noise_left: u16,

    // --- filters: state, 16.16 coefficient accumulators, steps ---
    /// S+0x23e tilt filter; a at S+0x242/0x246, b at S+0x24a/0x24e.
    pub tilt: u32,
    pub tilt_a: u32,
    pub tilt_a_step: u32,
    pub tilt_b: u32,
    pub tilt_b_step: u32,
    /// S+0x1b2 R1; a S+0x1b6/0x1ba, b S+0x1be/0x1c2.
    pub r1: u32,
    pub r1_a: u32,
    pub r1_a_step: u32,
    pub r1_b: u32,
    pub r1_b_step: u32,
    /// S+0x1c6 R2; a S+0x1ca/0x1ce, b S+0x1d2/0x1d6.
    pub r2: u32,
    pub r2_a: u32,
    pub r2_a_step: u32,
    pub r2_b: u32,
    pub r2_b_step: u32,
    /// S+0x1da R3; a S+0x1de/0x1e2, b S+0x1e6/0x1ea.
    pub r3: u32,
    pub r3_a: u32,
    pub r3_a_step: u32,
    pub r3_b: u32,
    pub r3_b_step: u32,
    /// S+0x1ee R4; a S+0x1f2, b S+0x1fa (not interpolated).
    pub r4: u32,
    pub r4_a: u32,
    pub r4_b: u32,
    /// S+0x202 R5; a S+0x206, b S+0x20e.
    pub r5: u32,
    pub r5_a: u32,
    pub r5_b: u32,
    /// S+0x216 frication resonator; a S+0x21a, b S+0x222.
    pub fric: u32,
    pub fric_a: u32,
    pub fric_b: u32,

    /// Sync events produced while generating (only if flags & 0x40 == 0).
    pub events: Vec<RawEvent>,

    /// Optional 16-bit output (not in the original): the same companding
    /// curve, interpolated between its points instead of truncated to 8 bits.
    pub hifi: Option<Vec<i16>>,
}

impl Generator {
    /// Load the generator state from a raw context block (as captured by the
    /// oracle; `ctx` is the 0x5a8-byte engine context, S = ctx + 0x13a).
    pub fn from_context(ctx: &[u8]) -> Self {
        let s = 0x13a;
        let d = |o: usize| u32::from_le_bytes(ctx[s + o..s + o + 4].try_into().unwrap());
        let w = |o: usize| u16::from_le_bytes([ctx[s + o], ctx[s + o + 1]]);
        let frames = d(0xf6);
        Generator {
            rate: d(0x48),
            flags: d(0x4e),
            frame: (d(0xfa).wrapping_sub(frames) / 0x20) as usize,
            elapsed: d(0xfe),
            spf: w(0x2bc),
            step16: w(0x2fa) as i16,
            frame_left: w(0x30c),
            first: w(0x30e),
            running: w(0x314),
            mouth: ctx[s + 0x312],
            phase: d(0x2fc),
            phase_inc: d(0x300),
            glot_a: d(0x2d8),
            glot_b: d(0x2dc),
            mix_a: w(0x268) as i16,
            mix_b: w(0x270) as i16,
            av: d(0x276),
            av_step: d(0x27a),
            diff_prev: d(0x2aa),
            ah: d(0x27e),
            af: d(0x286),
            ah_neg: d(0x296),
            ah_pos: d(0x29a),
            af_neg: d(0x29e),
            af_pos: d(0x2a2),
            cur_ah: w(0x280) as i16,
            cur_af: w(0x288) as i16,
            bypass: d(0x28e),
            noise_pos: (d(0x2e4).wrapping_sub(NOISE_TABLE) / 4) as u16,
            noise_left: w(0x2ee),
            tilt: d(0x23e),
            tilt_a: d(0x242),
            tilt_a_step: d(0x246),
            tilt_b: d(0x24a),
            tilt_b_step: d(0x24e),
            r1: d(0x1b2),
            r1_a: d(0x1b6),
            r1_a_step: d(0x1ba),
            r1_b: d(0x1be),
            r1_b_step: d(0x1c2),
            r2: d(0x1c6),
            r2_a: d(0x1ca),
            r2_a_step: d(0x1ce),
            r2_b: d(0x1d2),
            r2_b_step: d(0x1d6),
            r3: d(0x1da),
            r3_a: d(0x1de),
            r3_a_step: d(0x1e2),
            r3_b: d(0x1e6),
            r3_b_step: d(0x1ea),
            r4: d(0x1ee),
            r4_a: d(0x1f2),
            r4_b: d(0x1fa),
            r5: d(0x202),
            r5_a: d(0x206),
            r5_b: d(0x20e),
            fric: d(0x216),
            fric_a: d(0x21a),
            fric_b: d(0x222),
            events: Vec::new(),
            hifi: None,
        }
    }

    /// Prepare for a new phrase, as the narrate driver does (`df20` sets the
    /// rate and flags, `3870` sets S+0x30e = 0xff and S+0x314 = 1).  All other
    /// state carries over from the previous phrase, as in the original.
    pub fn start_phrase(&mut self, rate: u32, flags: u32) {
        self.rate = rate;
        self.flags = flags;
        self.first = 0xff;
        self.running = 1;
        self.events.clear();
    }

    /// One call of `402c(S, count)`: append `count` samples to `out`.
    /// `frames` is the whole frame buffer (terminated by a frame whose first
    /// byte is 0xff).  After the phrase ends the rest of the call is filled
    /// with silence (0x80) and `running` is cleared.
    pub fn generate(&mut self, frames: &[u8], out: &mut Vec<u8>, count: u16) {
        let mut left = count; // S+0x2f4
        // A fresh phrase starts by loading a frame; a continuing call resumes
        // at the per-sample bookkeeping (0x1c0044a0) after the last sample.
        let mut resume = self.first == 0;
        if !resume {
            self.first = 0;
            self.r1 = 0;
            self.r2 = 0;
            self.r3 = 0;
            self.r4 = 0;
            self.r5 = 0;
            self.fric = 0;
            self.tilt = 0;
            self.diff_prev = 0;
            self.phase = 0;
            self.noise_left = NOISE_LEN;
            self.phase_inc = 0x20000;
            self.frame = 4;
            self.elapsed = 0x40;
            self.noise_pos = 0;
        }
        loop {
            let mut need_frame = true;
            if resume {
                self.noise_left = self.noise_left.wrapping_sub(1);
                if self.noise_left == 0 {
                    self.noise_left = NOISE_LEN;
                    self.noise_pos = 0;
                }
                self.frame_left = self.frame_left.wrapping_sub(1);
                need_frame = self.frame_left == 0;
            }
            if need_frame && !self.next_frame(frames) {
                out.extend(std::iter::repeat_n(0x80u8, left as usize));
                if let Some(h) = &mut self.hifi {
                    h.extend(std::iter::repeat_n(0i16, left as usize));
                }
                self.running = 0;
                return;
            }
            if !self.sample(out, &mut left) {
                return;
            }
            resume = true;
        }
    }

    /// Produce one sample (0x1c004120..0x1c00449a).  Returns false when the
    /// call's sample budget is exhausted.
    #[inline]
    fn sample(&mut self, out: &mut Vec<u8>, left: &mut u16) -> bool {
        // Glottal source: two waveforms at the same phase, crossfaded.
        self.phase = self.phase.wrapping_add(self.phase_inc) & 0x3ff_ffff;
        let idx = (self.phase >> 16) * 2;
        let s1 = mul15(TIBASE.i16(self.glot_a + idx), self.mix_a);
        let s2 = mul15(TIBASE.i16(self.glot_b + idx), self.mix_b);
        let voiced = mul15(s1.wrapping_add(s2), hi(self.av));
        self.av = self.av.wrapping_add(self.av_step);

        // Pitch-synchronous noise gains.
        if voiced < 0 {
            self.cur_ah = hi(self.ah_neg);
            self.cur_af = hi(self.af_neg);
        } else {
            self.cur_ah = hi(self.ah_pos);
            self.cur_af = hi(self.af_pos);
        }

        // Differentiate: x = (voiced - previous) * 2, 16-bit wrap.
        let cur = (voiced as u16 as u32) << 16;
        let prev = std::mem::replace(&mut self.diff_prev, cur);
        let mut x = ((cur.wrapping_sub(prev) << 1) >> 16) as u16 as i16;

        // Spectral tilt.
        x = resonate(&mut self.tilt, x, hi(self.tilt_a), hi(self.tilt_b));
        self.tilt_a = self.tilt_a.wrapping_add(self.tilt_a_step);
        self.tilt_b = self.tilt_b.wrapping_add(self.tilt_b_step);

        // Aspiration.
        let np = NOISE_TABLE + self.noise_pos as u32 * 4;
        x = x.wrapping_add(mul15(TIBASE.i16(np), self.cur_ah));

        // Cascade R5, R1, R3, R4, R2.
        x = resonate(&mut self.r5, x, hi(self.r5_a), hi(self.r5_b));
        x = resonate(&mut self.r1, x, hi(self.r1_a), hi(self.r1_b));
        self.r1_a = self.r1_a.wrapping_add(self.r1_a_step);
        self.r1_b = self.r1_b.wrapping_add(self.r1_b_step);
        x = resonate(&mut self.r3, x, hi(self.r3_a), hi(self.r3_b));
        self.r3_a = self.r3_a.wrapping_add(self.r3_a_step);
        self.r3_b = self.r3_b.wrapping_add(self.r3_b_step);
        x = resonate(&mut self.r4, x, hi(self.r4_a), hi(self.r4_b));
        x = resonate(&mut self.r2, x, hi(self.r2_a), hi(self.r2_b));
        self.r2_a = self.r2_a.wrapping_add(self.r2_a_step);
        self.r2_b = self.r2_b.wrapping_add(self.r2_b_step);
        let cascade = x;

        // Frication branch.
        let n1 = TIBASE.i16(np + 2) >> 2;
        self.noise_pos += 1;
        let y = resonate(&mut self.fric, n1, hi(self.fric_a), hi(self.fric_b));
        let w = mul15(y, hi(self.bypass)).wrapping_sub(n1 >> 5);
        let p = w as i32 * self.cur_af as i32;
        let (hi16, lo16) = ((p >> 16) as u16, p as u16);
        let fric = shld16(shld16(hi16, lo16, 1), lo16, 3) as i16;

        // Output: scale, clamp, compand to unsigned 8-bit.
        let sum = cascade.wrapping_add(fric);
        let v = (sum >> 5).clamp(-200, 200);
        let byte = TIBASE.u8((OUT_LUT as i32 + v as i32) as u32);
        out.push(byte.wrapping_add(0x80));
        if let Some(h) = &mut self.hifi {
            h.push(smooth_sample(sum));
        }

        *left -= 1;
        *left != 0
    }

    /// Advance to the next frame and load its parameters (0x1c0044cb).
    /// Returns false at the end of the phrase.
    fn next_frame(&mut self, frames: &[u8]) -> bool {
        let i = self.frame + 1;
        let fr = &frames[i * 0x20..i * 0x20 + 0x20];
        if fr[0] == 0xff {
            return false;
        }
        // The frame two back ended a sentence ('.' = 1, '?' = 2).
        let back2 = frames[i * 0x20 - 0x35];
        if back2 == 1 || back2 == 2 {
            return false;
        }
        self.frame = i;
        let prev = &frames[(i - 1) * 0x20..i * 0x20];

        let rate = self.rate as u16 as u32;
        let q = (rate * TIBASE.u16(SPF_MUL) as u32 / TIBASE.u16(SPF_DIV) as u32) as u16;
        self.spf = (q / (fr[f::RATE] as u16 * 2)) >> 1;
        self.step16 = (0x10000i32 / self.spf as i16 as i32) as i16;

        if self.flags & 0x40 == 0 {
            self.queue_events(fr);
        }
        let dt = ((64000u32 * self.spf as u32) / rate) as u16 as i16 as i32 as u32;
        self.elapsed = self.elapsed.wrapping_add(dt);

        let step = |target: i16, cur: u32| ((target.wrapping_sub(hi(cur)) as i32) * self.step16 as i32) as u32;

        let t = (fr[f::B3_TILT] & 0xf) as u32 * 2;
        self.tilt_a_step = step(TIBASE.i16(TILT_A + t), self.tilt_a);
        self.tilt_b_step = step(TIBASE.i16(TILT_B + t), self.tilt_b);

        self.phase_inc = (u16::from_le_bytes([fr[f::F0], fr[f::F0 + 1]]) as u32) << 9;

        // R1..R3: interpolated coefficients.
        let (b1, b2, b3) = (fr[f::B1B2] >> 4, fr[f::B1B2] & 0xf, fr[f::B3_TILT] >> 4);
        let a_idx = |freq: u8, bw: u8| ((freq as u32) << 5) | (bw as u32 * 2);
        self.r1_b_step = step(TIBASE.i16(RES_B + b1 as u32 * 2), self.r1_b);
        self.r1_a_step = step(TIBASE.i16(RES_A + a_idx(fr[f::F1], b1)), self.r1_a);
        self.r2_b_step = step(TIBASE.i16(RES_B + b2 as u32 * 2), self.r2_b);
        self.r2_a_step = step(TIBASE.i16(RES_A + a_idx(fr[f::F2], b2)), self.r2_a);
        self.r3_b_step = step(TIBASE.i16(RES_B + b3 as u32 * 2), self.r3_b);
        self.r3_a_step = step(TIBASE.i16(RES_A + a_idx(fr[f::F3], b3)), self.r3_a);

        // R4, R5, frication: set once per frame.
        let (b4, b5, bf) = (fr[f::B4B5] >> 4, fr[f::B4B5] & 0xf, fr[f::FRIC_BW] >> 4);
        let coef = |va: u32| (TIBASE.u16(va) as u32) << 16;
        self.r4_b = coef(RES_B_HI + b4 as u32 * 2);
        self.r4_a = coef(RES_A_HI + a_idx(fr[f::F4], b4));
        self.r5_b = coef(RES_B_HI + b5 as u32 * 2);
        self.r5_a = coef(RES_A_HI + a_idx(fr[f::F5], b5));
        self.fric_b = coef(RES_B_HI + bf as u32 * 2);
        self.fric_a = coef(RES_A_HI + a_idx(fr[f::FRIC_F], bf));

        // Glottal crossfade and amplitudes.
        self.mix_a = ((fr[f::GLOT_MIX] as u16) << 7) as i16;
        self.mix_b = 0x7f80u16.wrapping_sub(self.mix_a as u16) as i16;
        let amp = |code: u8| TIBASE.u16(AMP_TABLE + code as u32);
        self.av_step = step(amp(fr[f::AV]) as i16, self.av);
        self.ah = (amp(fr[f::AH]) as u32) << 16;
        self.ah_neg = self.ah;
        self.ah_pos = self.ah;
        self.af = (amp(fr[f::AF]) as u32) << 16;
        self.af_neg = self.af;
        self.af_pos = self.af;
        self.bypass = (0x101du16.wrapping_sub(amp(fr[f::BYPASS])) as u32) << 16;
        if fr[f::AV] >= 0x3c {
            self.ah_pos = self.ah_neg >> 3;
            self.af_pos = self.af_neg >> 4;
        }

        // Silence: reset the cascade and tilt filter states.
        if fr[f::AV] <= 0xe && fr[f::AH] <= 0xe && prev[f::AV] <= 0xe && prev[f::AH] <= 0xe {
            self.r1 = 0;
            self.r2 = 0;
            self.r3 = 0;
            self.r4 = 0;
            self.tilt = 0;
        }

        self.glot_a = TIBASE.u32(GLOTTAL_PTRS + fr[f::GLOT_A] as u32 * 4);
        self.glot_b = TIBASE.u32(GLOTTAL_PTRS + fr[f::GLOT_B] as u32 * 4);
        self.frame_left = self.spf;
        true
    }

    /// Sync events for a new frame (0x1c004543..0x1c004605).  ECX carries
    /// over between events, as in the original.
    fn queue_events(&mut self, fr: &[u8]) {
        let time = self.elapsed >> 6;
        let mut ecx: u32 = 0;
        let push = |events: &mut Vec<RawEvent>, code: u16, ecx: u32| {
            events.push(RawEvent { code, time, value: ecx as u16, dvalue: ecx });
        };
        if self.flags & 8 != 0 && fr[f::MOUTH] != self.mouth {
            ecx = fr[f::MOUTH] as u32;
            self.mouth = fr[f::MOUTH];
            push(&mut self.events, 0x3f0, ecx);
        }
        if self.flags & 4 != 0 && fr[f::SYNC] & 1 != 0 {
            ecx = (ecx & 0xffff_0000) | fr[f::PHONEME] as u32;
            push(&mut self.events, 0x3ee, ecx);
        }
        if self.flags & 2 != 0 && fr[f::SYNC] & 4 != 0 {
            push(&mut self.events, 0x3ed, ecx);
        }
        if self.flags & 1 != 0 && fr[f::SYNC] & 2 != 0 {
            push(&mut self.events, 0x3ec, ecx);
        }
        if fr[f::SYNC] & 8 != 0 {
            ecx = (ecx & 0xffff_0000) | fr[f::INDEX] as u32;
            push(&mut self.events, 0x3ef, ecx);
        }
        if fr[f::SYNC] & 0x20 != 0 {
            ecx = (ecx & 0xffff_0000) | u16::from_le_bytes([fr[f::WORD], fr[f::WORD + 1]]) as u32;
            push(&mut self.events, 0x3eb, ecx);
        }
    }
}
