//! The embedded-command palette: every `{command}` the engine accepts
//! (docs/codes.md section 2), with an argument editor, inserted into the text
//! or phoneme editor at the cursor.

use std::collections::HashMap;

use eframe::egui;
use egui::RichText;

enum Arg {
    /// A number: default, range, unit, and whether `N%` (relative) is allowed.
    Num { default: i32, min: i32, max: i32, unit: &'static str, pct: bool },
    /// A keyword from a list.
    Choice(&'static [&'static str]),
    /// A musical note, `{c4}`, `{f#3}`.
    Note,
}

struct Cmd {
    name: &'static str,
    arg: Arg,
    /// Takes an optional position (ms into the following phoneme).
    pos: bool,
    help: &'static str,
}

const fn num(name: &'static str, default: i32, min: i32, max: i32, unit: &'static str, pos: bool, help: &'static str) -> Cmd {
    Cmd { name, arg: Arg::Num { default, min, max, unit, pct: false }, pos, help }
}

const fn choice(name: &'static str, list: &'static [&'static str], pos: bool, help: &'static str) -> Cmd {
    Cmd { name, arg: Arg::Choice(list), pos, help }
}

/// Inline `voice` names select presets 0-19 in this order; three of them
/// don't match the preset they select.
const VOICES: &[&str] = &[
    "male", "female", "largemale", "child", "giantmale", "mellowfemale", "mellowmale", "crispmale", "thefly", "robotoid",
    "martian", "colossus", "fastfred", "oldwoman", "munchkin", "troll", "nerd", "milktoast", "tipsy", "choirboy",
];
const NOTES: &[&str] = &["c", "d", "e", "f", "g", "a", "b"];

const GROUPS: &[(&str, &[Cmd])] = &[
    ("Voice and vocal tract", &[
        choice("voice", VOICES, true, "Switch preset mid-utterance. largemale = Fast Female, mellowmale = Choir Girl, crispmale = Amazon."),
        choice("tract", &["male", "female", "child", "giant"], true, "Vocal-tract size: scales the formants and the pitch range."),
        choice("glot", &["default", "male", "female", "child", "high", "mellow", "impulse", "odd", "colossus"], false, "Glottal source (voicing waveform)."),
        choice("voicing", &["normal", "breathy", "whispered"], true, "Voicing mode."),
        choice("language", &["english", "spanish"], false, "Phonemes from here on use that language's tables."),
    ]),
    ("Pitch and intonation", &[
        num("pitch", 120, 10, 2000, "Hz", true, "Base pitch from the next phoneme on. In sing and held-pitch modes, that note's pitch."),
        Cmd { name: "note", arg: Arg::Note, pos: false, help: "A musical note (A4 = 440 Hz). Only takes effect in f0style sing or random (held pitch)." },
        choice("f0style", &["natural", "style2", "monotone", "sing", "random"], false, "Intonation mode. sing: pitch follows notes and {pitch}. random: holds the last pitch."),
        num("f0range", 100, 0, 500, "", false, "Size of the intonation movements."),
        num("transpose", 0, -48, 48, "semitones", false, "Shifts the notes that follow it; put it before the note."),
        num("perturb", 0, 0, 500, "", false, "Pitch jitter."),
    ]),
    ("Timing", &[
        Cmd { name: "pause", arg: Arg::Num { default: 200, min: 0, max: 5000, unit: "ms", pct: true }, pos: false, help: "Duration of the next phoneme in ms, or N% of its rule duration. Same as a bare {N}." },
        num("rate", 170, 20, 500, "wpm", true, "Speaking rate from that point on."),
        num("vfactor", 100, 30, 300, "%", false, "Vowel duration factor (100 = normal)."),
        num("comma", 200, 0, 2000, "ms", false, "Length of , pauses (default 200)."),
        num("dash", 96, 0, 2000, "ms", false, "Length of - pauses (default 96)."),
        num("period", 140, 0, 2000, "ms", false, "Length of . and ? pauses (default 140)."),
        num("tempo", 80, 20, 400, "bpm", false, "Fits the phonemes between * beat marks to this tempo. No effect without * marks."),
    ]),
    ("Modulation", &[
        num("mod", 60, 0, 100, "%", false, "Overall modulation depth (default 0 = off). Nothing below is heard until this is set. Persists across utterances."),
        num("vibrato", 40, 0, 100, "", false, "Pitch modulation amount."),
        num("tremelo", 40, 0, 100, "", false, "Loudness modulation amount."),
        num("tonelo", 40, 0, 100, "", false, "Spectral-tilt (brightness) modulation amount."),
        num("modrate", 65, 0, 255, "", false, "Modulation (LFO) rate (default 65)."),
        num("modramp", 10, 0, 255, "", false, "How fast the depth moves towards mod (default 10)."),
    ]),
    ("Spectrum and amplitude", &[
        num("f1bias", 100, 25, 400, "%", false, "Scale F1 frequencies (100 = normal)."),
        num("f2bias", 100, 25, 400, "%", false, "Scale F2 frequencies (100 = normal)."),
        num("f3bias", 100, 25, 400, "%", false, "Scale F3 frequencies (100 = normal)."),
        num("b1bias", 100, 25, 400, "%", false, "Scale the B1 bandwidth (100 = normal)."),
        num("b2bias", 100, 25, 400, "%", false, "Scale the B2 bandwidth (100 = normal)."),
        num("b3bias", 100, 25, 400, "%", false, "Scale the B3 bandwidth (100 = normal)."),
        num("avbias", 0, -30, 20, "dB", true, "Voicing amplitude offset."),
        num("ahbias", 0, -30, 20, "dB", true, "Aspiration amplitude offset."),
        num("afbias", 0, -30, 20, "dB", true, "Frication amplitude offset."),
        num("avspeed", 0, 0, 5, "", false, "Smoothing of the voicing amplitude track."),
        num("ahspeed", 0, 0, 5, "", false, "Smoothing of the aspiration amplitude track."),
        num("afspeed", 0, 0, 5, "", false, "Smoothing of the frication amplitude track."),
        num("tone", 0, -8, 15, "", true, "Offset added to every frame's spectral-tilt index."),
        num("articeff", 0, -10, 30, "", true, "Articulation effort: negative slurs, positive exaggerates."),
        num("articspd", 0, 0, 5, "", true, "Smoothing of formant transitions."),
    ]),
    ("Sync events", &[
        num("usync", 0, 0, 255, "", true, "Posts an index sync event with this value when the next phoneme starts."),
        num("wordsync", 0, 0, 9999, "", true, "Posts a word sync event with this value (what @w<n> generates)."),
    ]),
];

/// Ready-made combinations.
const EXAMPLES: &[(&str, &str)] = &[
    ("Vibrato", "{mod 60; vibrato 40}"),
    ("Modulation off", "{mod 0}"),
    ("Whisper", "{voicing whispered}"),
    ("Robot", "{voice robotoid}"),
    ("Sing", "{f0style sing; c4}"),
    ("Monotone", "{f0style monotone}"),
    ("Slow", "{rate 90}"),
    ("Long pause", "{pause 600}"),
];

#[derive(Clone, Copy)]
struct ArgState {
    num: i32,
    pct: bool,
    choice: usize,
    letter: usize,
    sharp: bool,
    octave: i32,
}

#[derive(Default)]
pub struct Palette {
    args: HashMap<&'static str, ArgState>,
    use_pos: bool,
    pos: i32,
}

impl Palette {
    /// Draws the palette; returns the snippet to insert when a command is
    /// clicked.
    pub fn ui(&mut self, ui: &mut egui::Ui) -> Option<String> {
        let mut out = None;
        ui.horizontal(|ui| {
            ui.checkbox(&mut self.use_pos, "At")
                .on_hover_text("Add a position: the command takes effect this many ms into the following phoneme (only commands marked ⏱).");
            ui.add_enabled(self.use_pos, egui::DragValue::new(&mut self.pos).range(0..=5000).suffix(" ms"));
        });
        ui.add_space(4.0);

        egui::CollapsingHeader::new("Examples").default_open(true).show(ui, |ui| {
            ui.horizontal_wrapped(|ui| {
                for (label, snippet) in EXAMPLES {
                    if ui.button(*label).on_hover_text(RichText::new(*snippet).monospace()).clicked() {
                        out = Some(snippet.to_string());
                    }
                }
            });
        });

        for (title, cmds) in GROUPS {
            egui::CollapsingHeader::new(*title).default_open(true).show(ui, |ui| {
                egui::Grid::new(*title).num_columns(2).spacing([6.0, 4.0]).show(ui, |ui| {
                    for cmd in *cmds {
                        let st = self.args.entry(cmd.name).or_insert_with(|| initial(cmd));
                        let snippet = snippet(cmd, st, self.use_pos.then_some(self.pos));
                        let label = if cmd.pos { format!("{} ⏱", cmd.name) } else { cmd.name.to_string() };
                        let hover = format!("{}\n\nInserts {snippet}", cmd.help);
                        if ui.button(RichText::new(label).monospace()).on_hover_text(hover).clicked() {
                            out = Some(snippet);
                        }
                        ui.horizontal(|ui| arg_ui(ui, cmd, st));
                        ui.end_row();
                    }
                });
            });
        }
        out
    }
}

fn initial(cmd: &Cmd) -> ArgState {
    let num = match cmd.arg {
        Arg::Num { default, .. } => default,
        _ => 0,
    };
    ArgState { num, pct: false, choice: 0, letter: 0, sharp: false, octave: 4 }
}

fn arg_ui(ui: &mut egui::Ui, cmd: &Cmd, st: &mut ArgState) {
    match cmd.arg {
        Arg::Num { min, max, unit, pct, .. } => {
            let suffix = if pct && st.pct { "%".to_string() } else if unit.is_empty() { String::new() } else { format!(" {unit}") };
            ui.add(egui::DragValue::new(&mut st.num).range(min..=max).suffix(suffix));
            if pct {
                ui.checkbox(&mut st.pct, "%").on_hover_text("Relative to the rule duration");
            }
        }
        Arg::Choice(list) => {
            egui::ComboBox::from_id_salt(("palette", cmd.name))
                .selected_text(list[st.choice])
                .height(300.0)
                .show_ui(ui, |ui| {
                    for (i, name) in list.iter().enumerate() {
                        ui.selectable_value(&mut st.choice, i, *name);
                    }
                });
        }
        Arg::Note => {
            egui::ComboBox::from_id_salt(("palette", cmd.name)).width(40.0).selected_text(NOTES[st.letter]).show_ui(ui, |ui| {
                for (i, n) in NOTES.iter().enumerate() {
                    ui.selectable_value(&mut st.letter, i, *n);
                }
            });
            ui.checkbox(&mut st.sharp, "#");
            ui.add(egui::DragValue::new(&mut st.octave).range(0..=8).prefix("oct "));
        }
    }
}

fn snippet(cmd: &Cmd, st: &ArgState, pos: Option<i32>) -> String {
    let body = match cmd.arg {
        Arg::Num { pct, .. } => format!("{} {}{}", cmd.name, st.num, if pct && st.pct { "%" } else { "" }),
        Arg::Choice(list) => format!("{} {}", cmd.name, list[st.choice]),
        Arg::Note => format!("{}{}{}", NOTES[st.letter], if st.sharp { "#" } else { "" }, st.octave),
    };
    match pos {
        Some(p) if cmd.pos => format!("{{{body} {p}}}"),
        _ => format!("{{{body}}}"),
    }
}

/// Replaces the selection (or inserts at the cursor) of the `TextEdit` with
/// id `id`, leaving the cursor after the inserted text and focusing it.
/// With `pad`, adds spaces so the snippet isn't glued to a word: text to
/// phonemes reads a "{{command}}" with no space before it aloud, and drops the
/// word marker of a word right after it.  Returns what was inserted.
pub fn insert_at_cursor(ctx: &egui::Context, id: egui::Id, buf: &mut String, snippet: &str, pad: bool) -> String {
    use egui::text::{CCursor, CCursorRange};
    let mut state = egui::text_edit::TextEditState::load(ctx, id).unwrap_or_default();
    let n = buf.chars().count();
    let (a, b) = match state.cursor.char_range() {
        Some(r) => {
            let [x, y] = r.sorted_cursors();
            (x.index.0.min(n), y.index.0.min(n))
        }
        None => (n, n),
    };
    let byte = |c: usize| buf.char_indices().nth(c).map(|(i, _)| i).unwrap_or(buf.len());
    let (ba, bb) = (byte(a), byte(b));
    let mut snippet = snippet.to_string();
    if pad {
        if buf[..ba].chars().next_back().is_some_and(|c| !c.is_whitespace()) {
            snippet.insert(0, ' ');
        }
        if buf[bb..].chars().next().is_some_and(|c| !c.is_whitespace()) {
            snippet.push(' ');
        }
    }
    buf.replace_range(ba..bb, &snippet);
    let end = CCursor::new(a + snippet.chars().count());
    state.cursor.set_char_range(Some(CCursorRange::one(end)));
    state.store(ctx, id);
    ctx.memory_mut(|m| m.request_focus(id));
    snippet
}
