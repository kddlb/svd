//! Backend on the original 32-bit DLLs (TIBASE32 etc.), for comparison.
//! Only built for i686 (`cargo run --target i686-pc-windows-msvc`).

#[allow(dead_code)]
mod notify;
#[allow(dead_code)]
mod sv;
mod wavcap;

use std::ffi::CString;
use std::path::{Path, PathBuf};

use windows_sys::Win32::Foundation::HWND;

use crate::backend::{Backend, Lang, Param, Sync, Voice};

/// The utterance being spoken; `phon` must outlive it.
struct Current {
    phon: CString,
    record: Option<PathBuf>,
}

pub struct DllBackend {
    engine: sv::Engine,
    hwnd: HWND,
    current: Option<Current>,
    /// Result of the last finished recording, for the status bar.
    pending: Vec<Sync>,
}

impl DllBackend {
    pub fn open(ctx: &eframe::egui::Context) -> Result<Self, String> {
        let hwnd = notify::create_window(ctx);
        let engine = sv::Engine::open(hwnd)?;
        Ok(DllBackend { engine, hwnd, current: None, pending: Vec::new() })
    }

    fn start(&mut self, phonemes: &str, record: Option<PathBuf>) -> Result<(), String> {
        let bytes = sv::to_latin1(phonemes);
        let phon = CString::new(bytes.into_iter().filter(|&b| b != 0).collect::<Vec<_>>()).unwrap();
        if record.is_some() {
            wavcap::start();
        }
        match self.engine.narrate(&phon, self.hwnd, sv::NARRATE_SYNC_MOUTH | sv::NARRATE_OVERRIDE) {
            Ok(()) => {
                self.current = Some(Current { phon, record });
                Ok(())
            }
            Err(e) => {
                wavcap::stop();
                Err(e)
            }
        }
    }
}

impl Backend for DllBackend {
    fn name(&self) -> &'static str {
        "Original DLLs"
    }

    fn description(&self) -> String {
        format!("{}  ·  {}", self.engine.version, self.engine.dll_dir.display())
    }

    fn languages(&self) -> Vec<Lang> {
        let mut v = Vec::new();
        if self.engine.languages & sv::LANG_ENGLISH != 0 {
            v.push(Lang::English);
        }
        if self.engine.languages & sv::LANG_SPANISH != 0 {
            v.push(Lang::Spanish);
        }
        v
    }

    fn set_language(&mut self, lang: Lang) -> Result<(), String> {
        self.engine.set_language(match lang {
            Lang::English => sv::LANG_ENGLISH,
            Lang::Spanish => sv::LANG_SPANISH,
        })
    }

    fn preset_names(&mut self) -> Vec<String> {
        (0..sv::VOICE_COUNT)
            .map(|i| self.engine.voice_info(i).map(|v| v.name()).unwrap_or_else(|_| format!("Voice {i}")))
            .collect()
    }

    fn select_preset(&mut self, preset: u16) -> Result<Voice, String> {
        self.engine.set_personality(preset)?;
        let vi = self.engine.voice_info(sv::VOICE_CURRENT)?;
        // SAFETY: SVVOICEINFO is plain data, 0x6a bytes.
        let bytes = unsafe { std::slice::from_raw_parts(&vi as *const sv::VoiceInfo as *const u8, 0x6a) };
        Ok(Voice::from_info(bytes))
    }

    fn set_param(&mut self, p: Param, v: i32) -> Result<(), String> {
        let e = &self.engine;
        match p {
            Param::Pitch => e.set_pitch(v as u16),
            Param::Rate => e.set_rate(v as u16),
            Param::Gender => e.set_gender(v as u16),
            Param::GlottalSource => e.set_glottal_source(v as u16),
            Param::VoicingMode => e.set_voicing_mode(v as u16),
            Param::F0Style => e.set_f0_style(v as u16),
            Param::F0Range => e.set_f0_range(v as u16),
            Param::F0Perturb => e.set_f0_perturb(v as u16),
            Param::VowelFactor => e.set_vowel_factor(v as i16),
            Param::AvBias => e.set_av_bias(v as i16),
            Param::AhBias => e.set_ah_bias(v as i16),
            Param::AfBias => e.set_af_bias(v as i16),
        }
    }

    fn text_to_phonemes(&mut self, text: &str) -> Result<String, String> {
        self.engine.text_to_phon(&sv::to_latin1(text)).map(|p| sv::from_latin1(&p))
    }

    fn speak(&mut self, phonemes: &str) -> Result<(), String> {
        self.start(phonemes, None)
    }

    fn save_wav(&mut self, phonemes: &str, path: &Path) -> Result<String, String> {
        if !wavcap::installed() {
            return Err("WAV capture is not available".into());
        }
        self.start(phonemes, Some(path.to_path_buf()))?;
        Ok("Speaking and recording...".into())
    }

    fn save_plays_audio(&self) -> bool {
        true
    }

    fn stop(&mut self) {
        if self.current.take().is_some() {
            self.engine.abort();
            wavcap::stop();
        }
    }

    fn pause(&mut self) -> Result<(), String> {
        self.engine.pause()
    }

    fn resume(&mut self) -> Result<(), String> {
        self.engine.resume()
    }

    fn poll(&mut self) -> Vec<Sync> {
        let mut out = std::mem::take(&mut self.pending);
        for ev in notify::drain() {
            let Some(cur) = &self.current else { continue };
            if ev.phon != cur.phon.as_ptr() as usize {
                continue; // late message from an aborted utterance
            }
            out.push(match ev.code {
                sv::SYNC_WORD => Sync::Word(ev.value),
                sv::SYNC_MOUTH => Sync::Mouth(ev.value),
                sv::SYNC_DONE => {
                    let cur = self.current.take().unwrap();
                    if let Some(path) = cur.record {
                        let data = wavcap::stop().unwrap_or_default();
                        if let Err(e) = wavcap::write_wav(&path, &data) {
                            eprintln!("{}: {e}", path.display());
                        }
                    }
                    Sync::Done(ev.value)
                }
                c => Sync::Other(c as u16, ev.value),
            });
        }
        out
    }
}
