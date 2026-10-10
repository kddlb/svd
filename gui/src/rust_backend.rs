//! Backend on the Rust port of the engine, playing through cpal (WebAudio
//! in the browser).

use std::path::Path;
use std::sync::atomic::{AtomicBool, AtomicUsize, Ordering};
use std::sync::Arc;

use cpal::traits::{DeviceTrait, HostTrait, StreamTrait};
use softvoice::engine::{self, Engine, Language};

use crate::backend::{wav_bytes, write_wav, Backend, Lang, Param, Sync, Voice};

const RATE: u32 = 11025;
/// Narrate flags: mouth-shape events (word events are always on).
const FLAGS: u32 = 0x08;

struct Shared {
    samples: Vec<f32>,
    pos: AtomicUsize,
    paused: AtomicBool,
}

struct Playback {
    stream: cpal::Stream,
    shared: Arc<Shared>,
    device_rate: u32,
    /// Pending events, in order, with their 11025 Hz sample positions.
    events: std::collections::VecDeque<engine::Event>,
    done_error: u16,
}

pub struct RustBackend {
    engine: Engine,
    playback: Option<Playback>,
}

impl RustBackend {
    pub fn new() -> Self {
        let mut engine = Engine::new();
        // Playback uses the 16-bit stream; saved WAVs stay faithful 8-bit.
        engine.hifi = true;
        RustBackend { engine, playback: None }
    }

    fn synthesize(&mut self, phonemes: &str) -> Result<engine::Utterance, String> {
        let bytes: Vec<u8> = phonemes.chars().map(|c| if (c as u32) < 256 { c as u8 } else { b'?' }).collect();
        self.engine.narrate(&bytes, FLAGS).map_err(|e| format!("SVNarrate: error {e}"))
    }
}

fn log_error(msg: &str) {
    #[cfg(target_arch = "wasm32")]
    web_sys::console::error_1(&format!("audio error: {msg}").into());
    #[cfg(not(target_arch = "wasm32"))]
    eprintln!("audio error: {msg}");
}

/// Play an utterance: the hi-fi 16-bit stream, resampled to the device.
fn open_stream(utt: &engine::Utterance) -> Result<(cpal::Stream, Arc<Shared>, u32), String> {
    let host = cpal::default_host();
    let device = host.default_output_device().ok_or("no audio output device")?;
    let supported = device.default_output_config().map_err(|e| e.to_string())?;
    let config: cpal::StreamConfig = supported.config();
    let rate = config.sample_rate;
    let channels = config.channels as usize;
    let samples = utt.pcm16_at(rate).iter().map(|&v| v as f32 / 32768.0).collect();
    let shared = Arc::new(Shared { samples, pos: AtomicUsize::new(0), paused: AtomicBool::new(false) });
    let s2 = shared.clone();
    let fill = move |frame: &mut dyn FnMut(f32)| {
        if s2.paused.load(Ordering::Relaxed) {
            frame(0.0);
        } else {
            let i = s2.pos.fetch_add(1, Ordering::Relaxed);
            frame(s2.samples.get(i).copied().unwrap_or(0.0));
        }
    };
    let stream = match supported.sample_format() {
        cpal::SampleFormat::F32 => {
            let fill = fill;
            device.build_output_stream(
                config,
                move |out: &mut [f32], _| {
                    for f in out.chunks_mut(channels) {
                        fill(&mut |v| f.fill(v));
                    }
                },
                |e| log_error(&e.to_string()),
                None,
            )
        }
        cpal::SampleFormat::I16 => {
            let fill = fill;
            device.build_output_stream(
                config,
                move |out: &mut [i16], _| {
                    for f in out.chunks_mut(channels) {
                        fill(&mut |v| f.fill((v * 32767.0) as i16));
                    }
                },
                |e| log_error(&e.to_string()),
                None,
            )
        }
        f => return Err(format!("unsupported sample format {f:?}")),
    }
    .map_err(|e| e.to_string())?;
    stream.play().map_err(|e| e.to_string())?;
    Ok((stream, shared, rate))
}

impl Backend for RustBackend {
    fn name(&self) -> &'static str {
        "Rust port"
    }

    fn description(&self) -> String {
        "SoftVoice engine, Rust port (bit-exact with TIBASE32 1.0.0.1117)".into()
    }

    fn languages(&self) -> Vec<Lang> {
        vec![Lang::English, Lang::Spanish]
    }

    fn set_language(&mut self, lang: Lang) -> Result<(), String> {
        self.engine.set_language(match lang {
            Lang::English => Language::English,
            Lang::Spanish => Language::Spanish,
        });
        Ok(())
    }

    fn preset_names(&mut self) -> Vec<String> {
        (0..Engine::PRESETS)
            .map(|i| self.engine.preset_info(i).map(|b| Voice::name_from_info(&b)).unwrap_or_default())
            .collect()
    }

    fn select_preset(&mut self, preset: u16) -> Result<Voice, String> {
        self.engine.set_personality(preset).map_err(|e| format!("SVSetPersonality: error {e}"))?;
        Ok(Voice::from_info(self.engine.voice_info()))
    }

    fn set_param(&mut self, p: Param, v: i32) -> Result<(), String> {
        let e = &mut self.engine;
        let r = match p {
            Param::Pitch => e.set_pitch(v as u16),
            Param::Rate => e.set_rate(v as u16),
            Param::Gender => e.set_gender(v as u16),
            Param::GlottalSource => e.set_glottal_source(v as u16),
            Param::VoicingMode => e.set_voicing_mode(v as u16),
            Param::F0Style => e.set_f0_style(v as u16),
            Param::F0Range => e.set_f0_range(v as u16),
            Param::F0Perturb => e.set_f0_perturb(v as u16),
            Param::VowelFactor => Ok(e.set_vowel_factor(v as i16)),
            Param::AvBias => Ok(e.set_av_bias(v as i16)),
            Param::AhBias => Ok(e.set_ah_bias(v as i16)),
            Param::AfBias => Ok(e.set_af_bias(v as i16)),
        };
        r.map_err(|e| format!("{p:?}: error {e}"))
    }

    fn text_to_phonemes(&mut self, text: &str) -> Result<String, String> {
        let bytes: Vec<u8> = text.chars().map(|c| if (c as u32) < 256 { c as u8 } else { b'?' }).collect();
        self.engine
            .text_to_phonemes(&bytes, 0x08)
            .map(|p| p.iter().map(|&b| b as char).collect())
            .map_err(|e| format!("SVTextToPhon: error {e}"))
    }

    fn speak(&mut self, phonemes: &str) -> Result<(), String> {
        self.stop();
        let utt = self.synthesize(phonemes)?;
        let (stream, shared, device_rate) = open_stream(&utt)?;
        self.playback = Some(Playback {
            stream,
            shared,
            device_rate,
            events: utt.events.into_iter().collect(),
            done_error: utt.done_error,
        });
        Ok(())
    }

    fn save_wav(&mut self, phonemes: &str, path: &Path) -> Result<String, String> {
        let utt = self.synthesize(phonemes)?;
        write_wav(path, &utt.pcm).map_err(|e| format!("{}: {e}", path.display()))?;
        Ok(format!("Saved {} ({:.2} s)", path.display(), utt.pcm.len() as f32 / RATE as f32))
    }

    fn render_wav(&mut self, phonemes: &str) -> Option<Result<Vec<u8>, String>> {
        Some(self.synthesize(phonemes).map(|utt| wav_bytes(&utt.pcm)))
    }

    fn save_plays_audio(&self) -> bool {
        false
    }

    fn stop(&mut self) {
        self.playback = None;
    }

    fn pause(&mut self) -> Result<(), String> {
        if let Some(p) = &self.playback {
            p.shared.paused.store(true, Ordering::Relaxed);
            let _ = p.stream.pause();
        }
        Ok(())
    }

    fn resume(&mut self) -> Result<(), String> {
        if let Some(p) = &self.playback {
            p.shared.paused.store(false, Ordering::Relaxed);
            p.stream.play().map_err(|e| e.to_string())?;
        }
        Ok(())
    }

    fn poll(&mut self) -> Vec<Sync> {
        let mut out = Vec::new();
        let Some(p) = &mut self.playback else { return out };
        let played = p.shared.pos.load(Ordering::Relaxed).min(p.shared.samples.len());
        let at = (played as u64 * RATE as u64 / p.device_rate as u64) as usize;
        let finished = played >= p.shared.samples.len();
        while let Some(e) = p.events.front() {
            if e.sample > at && !finished {
                break;
            }
            let e = p.events.pop_front().unwrap();
            out.push(match e.code {
                engine::SYNC_WORD => Sync::Word(e.value),
                engine::SYNC_MOUTH => Sync::Mouth(e.value),
                engine::SYNC_DONE => Sync::Done(p.done_error),
                c => Sync::Other(c, e.value),
            });
        }
        if finished && p.events.is_empty() {
            self.playback = None;
        }
        out
    }
}
