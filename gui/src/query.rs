//! URL query parameters for the web build.  The page opens with the setup
//! they describe, and the address bar follows the UI, so the current text and
//! voice can be bookmarked or shared:
//!
//! ```text
//! ?text=Hola+amigos&lang=es&preset=3&pitch=180&gender=female&commands=0
//! ```
//!
//! | parameter   | value                                                 |
//! |-------------|-------------------------------------------------------|
//! | `text`      | text to speak                                         |
//! | `phonemes`  | phonemes, spoken as written (instead of `text`)       |
//! | `lang`      | `en` or `es`                                          |
//! | `preset`    | preset number (0-19) or name                          |
//! | `pitch`, `rate`, `f0range`, `f0perturb`, `vowel`, `av`, `ah`, `af` | number |
//! | `gender`, `glottal`, `voicing`, `f0style` | number or name (`female`, `breathy`, ...) |
//! | `commands`  | `0` hides the command palette, `1` shows it           |
//!
//! Voice parameters apply on top of the preset; the address bar only lists
//! the ones that differ from it.
#![cfg_attr(not(target_arch = "wasm32"), allow(dead_code))]

use std::ops::RangeInclusive;

use crate::backend::{Lang, Param};
use crate::{F0_STYLES, GENDERS, GLOTTAL, VOICING};

/// Voice parameters: query name, parameter, accepted range, value names.
pub const PARAMS: &[(&str, Param, RangeInclusive<i32>, &[&str])] = &[
    ("pitch", Param::Pitch, 10..=2000, &[]),
    ("rate", Param::Rate, 20..=500, &[]),
    ("f0style", Param::F0Style, 0..=4, F0_STYLES),
    ("f0range", Param::F0Range, 0..=500, &[]),
    ("f0perturb", Param::F0Perturb, 0..=500, &[]),
    ("vowel", Param::VowelFactor, 30..=300, &[]),
    ("gender", Param::Gender, 0..=3, GENDERS),
    ("glottal", Param::GlottalSource, 0..=8, GLOTTAL),
    ("voicing", Param::VoicingMode, 0..=2, VOICING),
    ("av", Param::AvBias, -30..=20, &[]),
    ("ah", Param::AhBias, -30..=20, &[]),
    ("af", Param::AfBias, -30..=20, &[]),
];

#[derive(Debug, Default, PartialEq)]
pub struct Query {
    pub text: Option<String>,
    pub phonemes: Option<String>,
    pub lang: Option<Lang>,
    /// Number or name; resolved against the preset list by `preset_index`.
    pub preset: Option<String>,
    pub params: Vec<(Param, i32)>,
    pub commands: Option<bool>,
    /// Parameters that were not understood, for the status bar.
    pub errors: Vec<String>,
}

/// Lowercase without spaces, so "Style 2" matches `style2`.
fn key(s: &str) -> String {
    s.chars().filter(|c| !c.is_whitespace()).flat_map(char::to_lowercase).collect()
}

pub fn parse(pairs: impl IntoIterator<Item = (String, String)>) -> Query {
    let mut q = Query::default();
    for (k, v) in pairs {
        match k.as_str() {
            "text" => q.text = Some(v),
            "phonemes" => q.phonemes = Some(v),
            "lang" => match key(&v).as_str() {
                "en" | "english" => q.lang = Some(Lang::English),
                "es" | "spanish" => q.lang = Some(Lang::Spanish),
                _ => q.errors.push(format!("lang={v}")),
            },
            "preset" => q.preset = Some(v),
            "commands" => match v.as_str() {
                "0" | "false" => q.commands = Some(false),
                "1" | "true" => q.commands = Some(true),
                _ => q.errors.push(format!("commands={v}")),
            },
            _ => match PARAMS.iter().find(|p| p.0 == k) {
                Some((_, p, range, names)) => {
                    let n = v.trim().parse().ok().or_else(|| names.iter().position(|n| key(n) == key(&v)).map(|i| i as i32));
                    match n {
                        Some(n) if range.contains(&n) => q.params.push((*p, n)),
                        _ => q.errors.push(format!("{k}={v}")),
                    }
                }
                None => q.errors.push(k),
            },
        }
    }
    q
}

/// A preset given by number or (case-insensitive) name.
pub fn preset_index(preset: &str, names: &[String]) -> Option<u16> {
    match preset.trim().parse::<usize>() {
        Ok(i) => (i < names.len()).then_some(i as u16),
        Err(_) => names.iter().position(|n| key(n) == key(preset)).map(|i| i as u16),
    }
}

impl crate::App {
    /// Apply a parsed query.  Called once at startup, after the first
    /// `activate`.
    pub fn apply_query(&mut self, mut q: Query) {
        if let Some(lang) = q.lang {
            match self.backend().set_language(lang) {
                Ok(()) => self.language = lang,
                Err(e) => q.errors.push(e),
            }
        }
        if let Some(p) = &q.preset {
            match preset_index(p, &self.presets) {
                Some(i) => self.select_preset(i),
                None => q.errors.push(format!("preset={p}")),
            }
        }
        for &(p, v) in &q.params {
            self.voice.set(p, v);
            self.set(p, v);
        }
        if let Some(text) = q.text {
            self.text = text;
        }
        if let Some(phon) = q.phonemes {
            self.phon_text = phon;
            self.speak_phonemes = true;
        }
        if let Some(c) = q.commands {
            self.show_palette = c;
        }
        if !q.errors.is_empty() {
            self.status = format!("Ignored URL parameters: {}", q.errors.join(", "));
        }
    }

    /// The current setup as query parameters, leaving out defaults.
    pub fn query_pairs(&self) -> Vec<(&'static str, String)> {
        let mut out = Vec::new();
        if self.speak_phonemes {
            out.push(("phonemes", self.phon_text.clone()));
        } else if self.text != crate::DEFAULT_TEXT {
            out.push(("text", self.text.clone()));
        }
        if self.language == Lang::Spanish {
            out.push(("lang", "es".into()));
        }
        if self.preset != 0 {
            out.push(("preset", self.preset.to_string()));
        }
        for (name, p, _, _) in PARAMS {
            let v = self.voice.get(*p);
            if v != self.preset_voice.get(*p) {
                out.push((name, v.to_string()));
            }
        }
        if !self.show_palette {
            out.push(("commands", "0".into()));
        }
        out
    }
}

#[cfg(target_arch = "wasm32")]
mod web {
    use wasm_bindgen::{JsCast, JsValue};
    use web_sys::UrlSearchParams;

    /// The page's query parameters.
    pub fn read() -> Vec<(String, String)> {
        let Some(search) = web_sys::window().and_then(|w| w.location().search().ok()) else { return Vec::new() };
        let Ok(params) = UrlSearchParams::new_with_str(&search) else { return Vec::new() };
        let Ok(Some(entries)) = js_sys::try_iter(&params) else { return Vec::new() };
        entries
            .flatten()
            .filter_map(|e| {
                let e: js_sys::Array = e.dyn_into().ok()?;
                Some((e.get(0).as_string()?, e.get(1).as_string()?))
            })
            .collect()
    }

    /// Replace the query in the address bar (no new history entry).
    pub fn write(pairs: &[(&str, String)]) {
        let Some(window) = web_sys::window() else { return };
        let Ok(params) = UrlSearchParams::new() else { return };
        for (k, v) in pairs {
            params.append(k, v);
        }
        let query = String::from(params.to_string());
        let url = if query.is_empty() { window.location().pathname().unwrap_or_default() } else { format!("?{query}") };
        if let Ok(history) = window.history() {
            let _ = history.replace_state_with_url(&JsValue::NULL, "", Some(&url));
        }
    }
}

#[cfg(target_arch = "wasm32")]
impl crate::App {
    pub fn apply_page_query(&mut self) {
        self.apply_query(parse(web::read()));
    }

    /// Update the address bar if the setup changed.
    pub fn sync_url(&mut self) {
        let pairs = self.query_pairs();
        if pairs != self.url_pairs {
            web::write(&pairs);
            self.url_pairs = pairs;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn q(s: &[(&str, &str)]) -> Query {
        parse(s.iter().map(|(k, v)| (k.to_string(), v.to_string())))
    }

    #[test]
    fn parses_values_and_names() {
        let r = q(&[("text", "Hi"), ("lang", "ES"), ("preset", "Fred"), ("pitch", "180"), ("gender", "female"), ("f0style", "Style 2"), ("af", "-5"), ("commands", "0")]);
        assert_eq!(r.text.as_deref(), Some("Hi"));
        assert_eq!(r.lang, Some(Lang::Spanish));
        assert_eq!(r.preset.as_deref(), Some("Fred"));
        assert_eq!(r.params, vec![(Param::Pitch, 180), (Param::Gender, 1), (Param::F0Style, 1), (Param::AfBias, -5)]);
        assert_eq!(r.commands, Some(false));
        assert!(r.errors.is_empty());
    }

    #[test]
    fn reports_bad_values() {
        let r = q(&[("pitch", "5"), ("gender", "robot"), ("lang", "fr"), ("volume", "3")]);
        assert!(r.params.is_empty());
        assert_eq!(r.errors, vec!["pitch=5", "gender=robot", "lang=fr", "volume"]);
    }

    #[test]
    fn resolves_presets() {
        let names: Vec<String> = ["Fred", "Big Bob"].iter().map(|s| s.to_string()).collect();
        assert_eq!(preset_index("1", &names), Some(1));
        assert_eq!(preset_index("bigbob", &names), Some(1));
        assert_eq!(preset_index("2", &names), None);
        assert_eq!(preset_index("Zed", &names), None);
    }
}
