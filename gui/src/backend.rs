//! What the UI needs from a speech engine.  Two implementations: the Rust
//! port (`rust_backend`) and, in 32-bit builds, the original DLLs (`dll`).

use std::path::Path;

/// Voice parameters shown in the UI (fields of SVVOICEINFO).
#[derive(Clone, Copy, Debug, Default, PartialEq)]
pub struct Voice {
    pub pitch: u16,
    pub rate: u16,
    pub gender: u16,
    pub glottal_source: u16,
    pub voicing_mode: u16,
    pub f0_style: u16,
    pub f0_range: u16,
    pub f0_perturb: u16,
    pub vowel_factor: u16,
    pub av_bias: i16,
    pub ah_bias: i16,
    pub af_bias: i16,
}

impl Voice {
    /// Decode a 0x6a-byte SVVOICEINFO.
    pub fn from_info(b: &[u8]) -> Voice {
        let u = |o: usize| u16::from_le_bytes([b[o], b[o + 1]]);
        Voice {
            pitch: u(0x04),
            rate: u(0x06),
            gender: u(0x08),
            glottal_source: u(0x0a),
            voicing_mode: u(0x0c),
            f0_style: u(0x10),
            f0_range: u(0x12),
            f0_perturb: u(0x14),
            vowel_factor: u(0x22),
            av_bias: u(0x28) as i16,
            ah_bias: u(0x2a) as i16,
            af_bias: u(0x2c) as i16,
        }
    }

    /// The preset name stored in an SVVOICEINFO.
    pub fn name_from_info(b: &[u8]) -> String {
        let n = &b[0x4a..0x6a];
        let len = n.iter().position(|&c| c == 0).unwrap_or(n.len());
        n[..len].iter().map(|&c| c as char).collect()
    }
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Param {
    Pitch,
    Rate,
    Gender,
    GlottalSource,
    VoicingMode,
    F0Style,
    F0Range,
    F0Perturb,
    VowelFactor,
    AvBias,
    AhBias,
    AfBias,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Lang {
    English,
    Spanish,
}

/// Events reported while speaking.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Sync {
    /// A word starts; character offset in the text given to text_to_phonemes.
    Word(u16),
    /// Mouth shape 1..9.
    Mouth(u16),
    /// Any other sync message (code, value), for the event log.
    Other(u16, u16),
    /// Speech ended (error code, 0 = ok).
    Done(u16),
}

pub trait Backend {
    /// Short name for the UI ("Rust port", "Original DLLs").
    fn name(&self) -> &'static str;
    /// Version / location line for the status bar.
    fn description(&self) -> String;
    fn languages(&self) -> Vec<Lang>;
    fn set_language(&mut self, lang: Lang) -> Result<(), String>;
    /// Names of the 20 presets.
    fn preset_names(&mut self) -> Vec<String>;
    /// Load a preset and return the resulting live voice.
    fn select_preset(&mut self, preset: u16) -> Result<Voice, String>;
    fn set_param(&mut self, p: Param, value: i32) -> Result<(), String>;
    /// Text (Latin-1 in a String, one char per byte) to a phoneme string
    /// with "@w" word markers.
    fn text_to_phonemes(&mut self, text: &str) -> Result<String, String>;
    /// Start speaking (asynchronous); events arrive through `poll`.
    fn speak(&mut self, phonemes: &str) -> Result<(), String>;
    /// Render to a WAV file.  Returns a status line.  (Native only.)
    #[cfg_attr(target_arch = "wasm32", allow(dead_code))]
    fn save_wav(&mut self, phonemes: &str, path: &Path) -> Result<String, String>;
    /// Render to WAV file bytes without playing (used on the web, where the
    /// file is offered as a download).  `None` if the backend can't.
    #[cfg_attr(not(target_arch = "wasm32"), allow(dead_code))]
    fn render_wav(&mut self, _phonemes: &str) -> Option<Result<Vec<u8>, String>> {
        None
    }
    /// Whether `save_wav` plays the audio while recording.
    fn save_plays_audio(&self) -> bool;
    fn stop(&mut self);
    fn pause(&mut self) -> Result<(), String>;
    fn resume(&mut self) -> Result<(), String>;
    /// Events since the last call.
    fn poll(&mut self) -> Vec<Sync>;
}

/// 8-bit unsigned mono PCM at 11025 Hz to a WAV file.
#[cfg_attr(target_arch = "wasm32", allow(dead_code))]
pub fn write_wav(path: &Path, pcm: &[u8]) -> std::io::Result<()> {
    std::fs::write(path, wav_bytes(pcm))
}

/// 8-bit unsigned mono PCM at 11025 Hz as WAV file bytes.
pub fn wav_bytes(pcm: &[u8]) -> Vec<u8> {
    let mut out = Vec::with_capacity(44 + pcm.len());
    let len = pcm.len() as u32;
    out.extend_from_slice(b"RIFF");
    out.extend_from_slice(&(36 + len).to_le_bytes());
    out.extend_from_slice(b"WAVEfmt ");
    out.extend_from_slice(&16u32.to_le_bytes());
    out.extend_from_slice(&1u16.to_le_bytes());
    out.extend_from_slice(&1u16.to_le_bytes());
    out.extend_from_slice(&11025u32.to_le_bytes());
    out.extend_from_slice(&11025u32.to_le_bytes());
    out.extend_from_slice(&1u16.to_le_bytes());
    out.extend_from_slice(&8u16.to_le_bytes());
    out.extend_from_slice(b"data");
    out.extend_from_slice(&len.to_le_bytes());
    out.extend_from_slice(pcm);
    out
}
