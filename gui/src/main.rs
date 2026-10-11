//! svgui - an egui front end for the SoftVoice engine from "Talk It!".
//! Runs on the Rust port; 32-bit builds can also drive the original DLLs
//! for side-by-side comparison, and it also runs in the browser (WebAssembly,
//! `trunk build --release`).
#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

mod backend;
#[cfg(all(windows, target_arch = "x86"))]
mod dll;
mod palette;
mod rust_backend;

use std::collections::VecDeque;
use std::time::Duration;

use backend::{Backend, Lang, Param, Sync, Voice};
use eframe::egui;
use egui::text::LayoutJob;
use egui::{Color32, FontId, RichText, TextFormat};

const GENDERS: &[&str] = &["Male", "Female", "Child", "Giant"];
const GLOTTAL: &[&str] = &["Default", "Male", "Female", "Child", "High", "Mellow", "Impulse", "Odd", "Colossus"];
const VOICING: &[&str] = &["Normal", "Breathy", "Whispered"];
const F0_STYLES: &[&str] = &["Natural", "Style 2", "Monotone", "Sing", "Random"];

const TEXT_ID: &str = "text_edit";
const PHON_ID: &str = "phon_edit";

/// Which editor the command palette inserts into.
#[derive(Clone, Copy, PartialEq)]
enum Target {
    Text,
    Phonemes,
}

struct App {
    backends: Vec<Box<dyn Backend>>,
    active: usize,

    text: String,
    phon_text: String,
    speak_phonemes: bool,

    palette: palette::Palette,
    show_palette: bool,
    target: Target,

    language: Lang,
    presets: Vec<String>,
    preset: u16,
    voice: Voice,

    speaking: bool,
    spoken_text: String,
    paused: bool,
    word: Option<(usize, usize)>,
    mouth: Option<u16>,
    log: VecDeque<String>,
    status: String,
}

impl App {
    fn new(_cc: &eframe::CreationContext<'_>) -> Self {
        #[allow(unused_mut)]
        let mut backends: Vec<Box<dyn Backend>> = vec![Box::new(rust_backend::RustBackend::new())];
        #[allow(unused_mut)]
        let mut status = "Ready".to_string();
        #[cfg(all(windows, target_arch = "x86"))]
        match dll::DllBackend::open(&_cc.egui_ctx) {
            Ok(b) => backends.push(Box::new(b)),
            Err(e) => status = format!("Original DLLs unavailable: {e}"),
        }
        let mut app = App {
            backends,
            active: 0,
            text: "Hello! I am a talking computer from 1996.".into(),
            phon_text: " @w0  /HEH5LOW! @w7  AY3 @w9  )AEM @w12  AX @w14  TAO4KIHNX @w22  KUMPYUW4TER @w31  FRUM @w36   NAY5NTIY1N NAY2NDIY SIH5KS .".into(),
            speak_phonemes: false,
            palette: palette::Palette::default(),
            show_palette: true,
            target: Target::Text,
            language: Lang::English,
            presets: Vec::new(),
            preset: 0,
            voice: Voice::default(),
            speaking: false,
            spoken_text: String::new(),
            paused: false,
            word: None,
            mouth: None,
            log: VecDeque::new(),
            status,
        };
        app.activate(0);
        app
    }

    fn backend(&mut self) -> &mut dyn Backend {
        self.backends[self.active].as_mut()
    }

    /// Switch engine, carrying over language and preset.
    fn activate(&mut self, i: usize) {
        if self.speaking {
            self.stop();
        }
        self.active = i;
        let lang = self.language;
        if let Err(e) = self.backend().set_language(lang) {
            self.status = e;
        }
        self.presets = self.backend().preset_names();
        self.select_preset(self.preset);
    }

    fn select_preset(&mut self, preset: u16) {
        match self.backend().select_preset(preset) {
            Ok(v) => {
                self.preset = preset;
                self.voice = v;
            }
            Err(e) => self.status = e,
        }
    }

    fn set(&mut self, p: Param, v: i32) {
        if let Err(e) = self.backend().set_param(p, v) {
            self.status = e;
        }
    }

    /// The phonemes to speak, converting the text unless speaking phonemes
    /// directly.  Also records the text the word events refer to.
    fn phonemes(&mut self) -> Option<String> {
        if self.speak_phonemes {
            self.spoken_text.clear();
            return Some(self.phon_text.clone());
        }
        let text = self.text.clone();
        match self.backend().text_to_phonemes(&text) {
            Ok(p) => {
                self.phon_text = p.clone();
                self.spoken_text = text;
                Some(p)
            }
            Err(e) => {
                self.status = e;
                None
            }
        }
    }

    fn speak(&mut self) {
        let Some(phon) = self.phonemes() else { return };
        match self.backend().speak(&phon) {
            Ok(()) => {
                self.speaking = true;
                self.paused = false;
                self.word = None;
                self.mouth = None;
                self.log.clear();
                self.status = "Speaking...".into();
            }
            Err(e) => self.status = e,
        }
    }

    /// On the web: render and offer the WAV as a download.
    #[cfg(target_arch = "wasm32")]
    fn save_wav(&mut self) {
        let Some(phon) = self.phonemes() else { return };
        match self.backend().render_wav(&phon) {
            Some(Ok(wav)) => {
                let secs = (wav.len() - 44) as f32 / 11025.0;
                self.status = match web::download(&wav, "speech.wav", "audio/wav") {
                    Ok(()) => format!("Downloaded speech.wav ({secs:.2} s)"),
                    Err(e) => e,
                };
            }
            Some(Err(e)) => self.status = e,
            None => self.status = "This engine can't render WAV files".into(),
        }
    }

    #[cfg(not(target_arch = "wasm32"))]
    fn save_wav(&mut self) {
        let Some(path) = rfd::FileDialog::new().add_filter("WAV audio", &["wav"]).set_file_name("speech.wav").save_file() else {
            return;
        };
        let Some(phon) = self.phonemes() else { return };
        let plays = self.backend().save_plays_audio();
        match self.backend().save_wav(&phon, &path) {
            Ok(msg) => {
                self.status = msg;
                if plays {
                    self.speaking = true;
                    self.paused = false;
                    self.log.clear();
                }
            }
            Err(e) => self.status = e,
        }
    }

    fn stop(&mut self) {
        self.backend().stop();
        if self.speaking {
            self.status = "Stopped".into();
        }
        self.speaking = false;
        self.word = None;
        self.mouth = None;
        self.paused = false;
    }

    fn convert(&mut self) {
        let text = self.text.clone();
        match self.backend().text_to_phonemes(&text) {
            Ok(p) => {
                self.phon_text = p;
                self.status = "Converted".into();
            }
            Err(e) => self.status = e,
        }
    }

    fn handle_events(&mut self) {
        for ev in self.backend().poll() {
            if !self.speaking {
                continue;
            }
            match ev {
                Sync::Word(v) => {
                    self.word = word_range(&self.spoken_text, v as usize);
                    self.log.push_back(format!("word    offset={v}"));
                }
                Sync::Mouth(v) => {
                    self.mouth = Some(v);
                    self.log.push_back(format!("mouth   {v}"));
                }
                Sync::Other(code, v) => self.log.push_back(format!("sync {code} value={v}")),
                Sync::Done(err) => {
                    self.speaking = false;
                    self.word = None;
                    self.mouth = None;
                    self.paused = false;
                    self.status = if err == 0 { "Done".into() } else { format!("Speech ended with error {err}") };
                    self.log.push_back(format!("done    error={err}"));
                }
            }
            while self.log.len() > 500 {
                self.log.pop_front();
            }
        }
    }

    // ---- UI ---------------------------------------------------------------

    fn voice_panel(&mut self, ui: &mut egui::Ui) {
        ui.heading("Voice");
        ui.add_space(4.0);
        let langs = self.backend().languages();
        egui::Grid::new("voice_grid").num_columns(2).spacing([8.0, 6.0]).show(ui, |ui| {
            if self.backends.len() > 1 {
                ui.label("Engine");
                let mut active = self.active;
                egui::ComboBox::from_id_salt("engine")
                    .selected_text(self.backends[active].name())
                    .show_ui(ui, |ui| {
                        for (i, b) in self.backends.iter().enumerate() {
                            ui.selectable_value(&mut active, i, b.name());
                        }
                    });
                if active != self.active {
                    self.activate(active);
                }
                ui.end_row();
            }

            ui.label("Language");
            let mut lang = self.language;
            egui::ComboBox::from_id_salt("lang")
                .selected_text(if lang == Lang::Spanish { "Spanish" } else { "English" })
                .show_ui(ui, |ui| {
                    if langs.contains(&Lang::English) {
                        ui.selectable_value(&mut lang, Lang::English, "English");
                    }
                    if langs.contains(&Lang::Spanish) {
                        ui.selectable_value(&mut lang, Lang::Spanish, "Spanish");
                    }
                });
            if lang != self.language {
                match self.backend().set_language(lang) {
                    Ok(()) => self.language = lang,
                    Err(e) => self.status = e,
                }
            }
            ui.end_row();

            ui.label("Preset");
            let mut preset = self.preset;
            egui::ComboBox::from_id_salt("preset")
                .selected_text(self.presets.get(preset as usize).cloned().unwrap_or_default())
                .height(400.0)
                .show_ui(ui, |ui| {
                    for (i, name) in self.presets.iter().enumerate() {
                        ui.selectable_value(&mut preset, i as u16, name);
                    }
                });
            if preset != self.preset {
                self.select_preset(preset);
            }
            ui.end_row();
        });
        if ui.button("Reset to preset").clicked() {
            self.select_preset(self.preset);
        }

        ui.separator();
        let mut v = self.voice;
        let mut changes: Vec<(Param, i32)> = Vec::new();
        ui.label(RichText::new("Prosody").strong());
        if slider_u16(ui, "Pitch (Hz)", &mut v.pitch, 10..=2000, true) { changes.push((Param::Pitch, v.pitch as i32)); }
        if slider_u16(ui, "Rate (wpm)", &mut v.rate, 20..=500, false) { changes.push((Param::Rate, v.rate as i32)); }
        if combo(ui, "F0 style", &mut v.f0_style, F0_STYLES) { changes.push((Param::F0Style, v.f0_style as i32)); }
        if slider_u16(ui, "F0 range", &mut v.f0_range, 0..=500, false) { changes.push((Param::F0Range, v.f0_range as i32)); }
        if slider_u16(ui, "F0 perturb", &mut v.f0_perturb, 0..=500, false) { changes.push((Param::F0Perturb, v.f0_perturb as i32)); }
        if slider_u16(ui, "Vowel length %", &mut v.vowel_factor, 30..=300, false) { changes.push((Param::VowelFactor, v.vowel_factor as i32)); }

        ui.add_space(6.0);
        ui.label(RichText::new("Voice quality").strong());
        if combo(ui, "Gender", &mut v.gender, GENDERS) { changes.push((Param::Gender, v.gender as i32)); }
        if combo(ui, "Glottal source", &mut v.glottal_source, GLOTTAL) { changes.push((Param::GlottalSource, v.glottal_source as i32)); }
        if combo(ui, "Voicing", &mut v.voicing_mode, VOICING) { changes.push((Param::VoicingMode, v.voicing_mode as i32)); }
        if slider_i16(ui, "Voicing (AV) bias", &mut v.av_bias, -30..=20) { changes.push((Param::AvBias, v.av_bias as i32)); }
        if slider_i16(ui, "Aspiration (AH) bias", &mut v.ah_bias, -30..=20) { changes.push((Param::AhBias, v.ah_bias as i32)); }
        if slider_i16(ui, "Frication (AF) bias", &mut v.af_bias, -30..=20) { changes.push((Param::AfBias, v.af_bias as i32)); }
        self.voice = v;
        for (p, x) in changes {
            self.set(p, x);
        }
        ui.add_space(6.0);
        ui.weak("Changes apply to the next utterance.");
    }

    fn palette_panel(&mut self, ui: &mut egui::Ui) {
        ui.heading("Commands");
        // The text editor is disabled while speaking phonemes as written.
        let target = if self.speak_phonemes { Target::Phonemes } else { self.target };
        ui.horizontal(|ui| {
            ui.label("Insert into");
            let mut t = target;
            ui.add_enabled_ui(!self.speak_phonemes, |ui| ui.selectable_value(&mut t, Target::Text, "Text"));
            ui.selectable_value(&mut t, Target::Phonemes, "Phonemes");
            self.target = t;
        });
        ui.weak("Click a command to insert it at the cursor. It applies from the next phoneme on. In text, commands are written {{...}}.");
        ui.add_space(4.0);
        if let Some(snippet) = self.palette.ui(ui) {
            let ctx = ui.ctx().clone();
            let snippet = match target {
                // Text to phonemes only passes "{{command}}" through (as
                // "{command}"); single braces are read aloud.
                Target::Text => palette::insert_at_cursor(&ctx, egui::Id::new(TEXT_ID), &mut self.text, &format!("{{{snippet}}}"), true),
                Target::Phonemes => palette::insert_at_cursor(&ctx, egui::Id::new(PHON_ID), &mut self.phon_text, &snippet, false),
            };
            self.target = target;
            self.status = format!("Inserted {snippet}");
        }
    }

    fn main_panel(&mut self, ui: &mut egui::Ui) {
        let ctrl_enter = ui.input_mut(|i| i.consume_key(egui::Modifiers::CTRL, egui::Key::Enter));

        ui.heading("Text");
        let edit = egui::TextEdit::multiline(&mut self.text)
            .font(FontId::proportional(18.0))
            .desired_rows(5)
            .desired_width(f32::INFINITY)
            .hint_text("Type something to say...");
        let edit = edit.id(egui::Id::new(TEXT_ID));
        if ui.add_enabled(!self.speak_phonemes, edit).has_focus() {
            self.target = Target::Text;
        }

        let speaking = self.speaking;
        ui.horizontal(|ui| {
            if ui.button(RichText::new("▶ Speak").size(16.0)).on_hover_text("Ctrl+Enter").clicked() || ctrl_enter {
                self.speak();
            }
            if ui.add_enabled(speaking, egui::Button::new(RichText::new("⏹ Stop").size(16.0))).clicked() {
                self.stop();
            }
            let label = if self.paused { "▶ Resume" } else { "⏸ Pause" };
            if ui.add_enabled(speaking, egui::Button::new(RichText::new(label).size(16.0))).clicked() {
                let r = if self.paused { self.backend().resume() } else { self.backend().pause() };
                match r {
                    Ok(()) => self.paused = !self.paused,
                    Err(e) => self.status = e,
                }
            }
            let hint = if self.backends[self.active].save_plays_audio() {
                "Speak and record the audio to an 11025 Hz 8-bit WAV file"
            } else {
                "Render to an 11025 Hz 8-bit WAV file (silently)"
            };
            if ui.button(RichText::new("💾 Save WAV…").size(16.0)).on_hover_text(hint).clicked() {
                self.save_wav();
            }
            ui.separator();
            ui.checkbox(&mut self.speak_phonemes, "Speak phonemes as written");
            ui.toggle_value(&mut self.show_palette, "{ } Commands").on_hover_text("Show the embedded-command palette");
        });

        ui.add_space(8.0);
        egui::Frame::group(ui.style()).show(ui, |ui| {
            ui.set_min_height(60.0);
            ui.set_width(ui.available_width());
            if self.speaking && !self.spoken_text.is_empty() {
                ui.label(highlighted(ui, &self.spoken_text, self.word));
            } else if self.speaking {
                ui.weak("Speaking phonemes...");
            } else {
                ui.weak("The word being spoken is highlighted here.");
            }
            ui.add_space(4.0);
            ui.horizontal(|ui| {
                ui.weak("Mouth shape");
                for id in 1..=9u16 {
                    let text = RichText::new(format!(" {id} ")).monospace();
                    ui.label(if self.mouth == Some(id) {
                        text.background_color(ui.visuals().selection.bg_fill).color(Color32::WHITE)
                    } else {
                        text.weak()
                    });
                }
            });
        });

        ui.add_space(8.0);
        egui::CollapsingHeader::new("Phonemes").default_open(true).show(ui, |ui| {
            ui.horizontal(|ui| {
                if ui.button("Convert text").clicked() {
                    self.convert();
                }
                ui.weak("ARPAbet-style codes, stress 1-9 after vowels, {commands} allowed");
            });
            egui::ScrollArea::vertical().id_salt("phon").max_height(140.0).show(ui, |ui| {
                let edit = egui::TextEdit::multiline(&mut self.phon_text).id(egui::Id::new(PHON_ID)).code_editor().desired_rows(4).desired_width(f32::INFINITY);
                if ui.add(edit).has_focus() {
                    self.target = Target::Phonemes;
                }
            });
        });

        egui::CollapsingHeader::new(format!("Sync events ({})", self.log.len())).show(ui, |ui| {
            egui::ScrollArea::vertical().id_salt("log").max_height(180.0).stick_to_bottom(true).show(ui, |ui| {
                for line in &self.log {
                    ui.monospace(line);
                }
            });
        });
    }
}

impl eframe::App for App {
    fn ui(&mut self, ui: &mut egui::Ui, _frame: &mut eframe::Frame) {
        self.handle_events();
        if self.speaking {
            ui.ctx().request_repaint_after(Duration::from_millis(15));
        }
        let description = self.backends[self.active].description();
        egui::Panel::bottom("status").show(ui, |ui| {
            ui.horizontal(|ui| {
                ui.label(&self.status);
                ui.with_layout(egui::Layout::right_to_left(egui::Align::Center), |ui| {
                    ui.weak(description);
                });
            });
        });
        egui::Panel::left("voice").resizable(false).default_size(280.0).show(ui, |ui| {
            egui::ScrollArea::vertical().show(ui, |ui| self.voice_panel(ui));
        });
        if self.show_palette {
            egui::Panel::right("palette").resizable(true).default_size(300.0).show(ui, |ui| {
                egui::ScrollArea::vertical().show(ui, |ui| self.palette_panel(ui));
            });
        }
        egui::CentralPanel::default().show(ui, |ui| self.main_panel(ui));
    }
}

fn slider_u16(ui: &mut egui::Ui, label: &str, v: &mut u16, range: std::ops::RangeInclusive<u16>, log: bool) -> bool {
    ui.add(egui::Slider::new(v, range).text(label).logarithmic(log)).changed()
}

fn slider_i16(ui: &mut egui::Ui, label: &str, v: &mut i16, range: std::ops::RangeInclusive<i16>) -> bool {
    ui.add(egui::Slider::new(v, range).text(label)).changed()
}

fn combo(ui: &mut egui::Ui, label: &str, v: &mut u16, names: &[&str]) -> bool {
    let before = *v;
    ui.horizontal(|ui| {
        egui::ComboBox::from_id_salt(label).selected_text(names.get(*v as usize).copied().unwrap_or("?")).show_ui(ui, |ui| {
            for (i, n) in names.iter().enumerate() {
                ui.selectable_value(v, i as u16, *n);
            }
        });
        ui.label(label);
    });
    *v != before
}

/// Byte range of the word starting at character `start`.
fn word_range(text: &str, start: usize) -> Option<(usize, usize)> {
    let mut chars = text.char_indices().skip(start).peekable();
    let &(b0, _) = chars.peek()?;
    let b1 = chars.find(|(_, c)| c.is_whitespace()).map(|(b, _)| b).unwrap_or(text.len());
    Some((b0, b1))
}

fn highlighted(ui: &egui::Ui, text: &str, word: Option<(usize, usize)>) -> LayoutJob {
    let normal = TextFormat { font_id: FontId::proportional(20.0), color: ui.visuals().text_color(), ..Default::default() };
    let strong = TextFormat { background: ui.visuals().selection.bg_fill, color: Color32::WHITE, ..normal.clone() };
    let mut job = LayoutJob::default();
    job.wrap.max_width = ui.available_width();
    match word {
        Some((a, b)) => {
            job.append(&text[..a], 0.0, normal.clone());
            job.append(&text[a..b], 0.0, strong);
            job.append(&text[b..], 0.0, normal);
        }
        None => job.append(text, 0.0, normal),
    }
    job
}

#[cfg(target_arch = "wasm32")]
mod web {
    use wasm_bindgen::JsCast;

    /// Offer `data` as a file download.
    pub fn download(data: &[u8], name: &str, mime: &str) -> Result<(), String> {
        let err = |e: wasm_bindgen::JsValue| format!("download failed: {e:?}");
        let parts = js_sys::Array::of1(&js_sys::Uint8Array::from(data));
        let opts = web_sys::BlobPropertyBag::new();
        opts.set_type(mime);
        let blob = web_sys::Blob::new_with_u8_array_sequence_and_options(&parts, &opts).map_err(err)?;
        let url = web_sys::Url::create_object_url_with_blob(&blob).map_err(err)?;
        let doc = web_sys::window().and_then(|w| w.document()).ok_or("no document")?;
        let a: web_sys::HtmlAnchorElement = doc.create_element("a").map_err(err)?.unchecked_into();
        a.set_href(&url);
        a.set_download(name);
        a.click();
        web_sys::Url::revoke_object_url(&url).map_err(err)?;
        Ok(())
    }
}

#[cfg(target_arch = "wasm32")]
fn main() {
    use wasm_bindgen::JsCast;
    wasm_bindgen_futures::spawn_local(async {
        let doc = web_sys::window().and_then(|w| w.document()).expect("no document");
        let canvas = doc
            .get_element_by_id("svgui")
            .expect("no #svgui canvas")
            .dyn_into::<web_sys::HtmlCanvasElement>()
            .expect("#svgui is not a canvas");
        let start = eframe::WebRunner::new()
            .start(canvas, eframe::WebOptions::default(), Box::new(|cc| Ok(Box::new(App::new(cc)))))
            .await;
        if let Err(e) = start {
            web_sys::console::error_1(&e);
        }
    });
}

#[cfg(not(target_arch = "wasm32"))]
fn main() -> eframe::Result {
    let options = eframe::NativeOptions {
        viewport: egui::ViewportBuilder::default()
            .with_title("SoftVoice — Talk It! engine")
            .with_inner_size([1260.0, 720.0])
            .with_min_inner_size([700.0, 480.0]),
        ..Default::default()
    };
    eframe::run_native("svgui", options, Box::new(|cc| Ok(Box::new(App::new(cc)))))
}
