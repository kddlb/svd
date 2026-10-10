//! Shared helpers for the golden-data tests.
#![allow(dead_code)]

use golden::{Case, Snapshot};
use softvoice::engine::{Engine, Language};
use softvoice::mem::Mem;

/// Context offset of the synthesis state block S.
pub const S_OFFSET: u32 = 0x13a;

/// Load a snapshot into a fresh memory model at its original addresses.
/// Returns (memory, S).
pub fn load(snap: &Snapshot) -> (Mem, u32) {
    load_case(snap, None)
}

/// Like `load`, also mapping the case's phoneme string where the context's
/// input pointer (ctx+0xc8) expects it.
pub fn load_case(snap: &Snapshot, case: Option<&Case>) -> (Mem, u32) {
    let mut m = Mem::new();
    if let Some(case) = case {
        let at = u32::from_le_bytes(snap.ctx.data[0xc8..0xcc].try_into().unwrap());
        let mut s = case.phonemes.clone();
        s.push(0);
        m.map(at, s);
    }
    for b in [&snap.ctx, &snap.records, &snap.syllables, &snap.frames, &snap.commands] {
        m.map(b.addr, b.data.clone());
    }
    (m, snap.ctx.addr + S_OFFSET)
}

/// Overwrite the DLLs' `.data` with the snapshot's copy (if it has one).
pub fn load_dll_data(m: &mut Mem, snap: &Snapshot) {
    for b in &snap.dll_data {
        if b.addr != 0 && !b.data.is_empty() {
            m.bytes_mut(b.addr, b.data.len()).copy_from_slice(&b.data);
        }
    }
}

/// Compare the DLLs' `.data` with the snapshot's copy.
pub fn diff_dll_data(m: &Mem, want: &Snapshot) -> Option<String> {
    const NAMES: [&str; 3] = ["tibase32", "tieng32", "tispan32"];
    for (name, b) in NAMES.iter().zip(&want.dll_data) {
        if b.addr == 0 || b.data.is_empty() {
            continue;
        }
        let got = m.bytes(b.addr, b.data.len());
        if let Some(i) = got.iter().zip(&b.data).position(|(x, y)| x != y) {
            return Some(format!("{name} .data {:#x}: got {:#04x} want {:#04x}", b.addr + i as u32, got[i], b.data[i]));
        }
    }
    None
}

/// Compare every captured block of `want` with the same addresses in `m`.
/// Returns a description of the first difference.
pub fn diff(m: &Mem, want: &Snapshot) -> Option<String> {
    let blocks = [
        ("ctx", &want.ctx),
        ("records", &want.records),
        ("syllables", &want.syllables),
        ("frames", &want.frames),
        ("commands", &want.commands),
    ];
    for (name, b) in blocks {
        if b.addr == 0 || b.data.is_empty() {
            continue;
        }
        let Some(got) = m.block(b.addr) else {
            return Some(format!("{name}: block at {:#x} missing", b.addr));
        };
        if got.len() != b.data.len() {
            return Some(format!("{name}: length {} vs {}", got.len(), b.data.len()));
        }
        if let Some(i) = got.iter().zip(&b.data).position(|(x, y)| x != y) {
            return Some(format!("{name} +{i:#x}: got {:#04x} want {:#04x}", got[i], b.data[i]));
        }
    }
    None
}

/// Number of stage snapshots per phrase (see the oracle's `g_stageSites`):
/// 0 sentence split (c500), 1 parse (4a10), 2 voice (3e40), 3 onsets (c550),
/// 4 allophones (5910), 5 syllables (c6d0), 6 boundaries (3de0),
/// 7 syllable arrays (cc10), 8 stress (c8c0), 9 F0 (cdc0), 10 durations
/// (c3e0), 11 tempo (f7c0), 12 frame alloc (c420), 13 frames (5840),
/// 14 F0 fill (cd40), 15/16 F0 smoothing (de60), 17 modulation (be40).
pub const STAGES: usize = 18;

/// Stage snapshots of a case grouped per phrase (STAGES per phrase).
pub fn phrases(case: &Case) -> Vec<Vec<&Snapshot>> {
    let mut out: Vec<Vec<&Snapshot>> = Vec::new();
    for s in &case.stages {
        if s.stage == Some(0) {
            out.push(Vec::new());
        }
        if let Some(p) = out.last_mut() {
            p.push(s);
        }
    }
    out
}

/// Run `f` for every (case, phrase stage list) of every golden file that has
/// stage snapshots.
pub fn for_each_phrase(mut f: impl FnMut(&Case, usize, &[&Snapshot])) -> usize {
    let mut n = 0;
    for file in golden::files() {
        for case in golden::read(&file).unwrap() {
            for (i, ph) in phrases(&case).iter().enumerate() {
                if ph.len() == STAGES {
                    f(&case, i, ph);
                    n += 1;
                }
            }
        }
    }
    n
}

/// Apply the case's settings in the oracle's order.
pub fn configure(e: &mut Engine, case: &Case) {
    let get = |k: &str| case.meta.get(k).and_then(|v| v.parse::<i32>().ok());
    e.set_language(if case.meta.get("lang").map(String::as_str) == Some("es") { Language::Spanish } else { Language::English });
    e.set_personality(get("voice").unwrap_or(0) as u16).unwrap();
    if let Some(p) = get("pitch").filter(|&p| p != 0) {
        let _ = e.set_pitch(p as u16);
    }
    if let Some(r) = get("rate").filter(|&r| r != 0) {
        let _ = e.set_rate(r as u16);
    }
    for key in ["gender", "glot", "voicing", "f0style", "f0range", "perturb", "vfactor", "avbias", "ahbias", "afbias", "speakmode"] {
        if let Some(v) = get(key) {
            let _ = match key {
                "gender" => e.set_gender(v as u16),
                "glot" => e.set_glottal_source(v as u16),
                "voicing" => e.set_voicing_mode(v as u16),
                "f0style" => e.set_f0_style(v as u16),
                "f0range" => e.set_f0_range(v as u16),
                "perturb" => e.set_f0_perturb(v as u16),
                "vfactor" => Ok(e.set_vowel_factor(v as i16)),
                "avbias" => Ok(e.set_av_bias(v as i16)),
                "ahbias" => Ok(e.set_ah_bias(v as i16)),
                "afbias" => Ok(e.set_af_bias(v as i16)),
                _ => e.set_speaking_mode(v as u16),
            };
        }
    }
}

pub fn narrate_flags(case: &Case) -> u32 {
    case.meta.get("nflags").and_then(|v| u32::from_str_radix(v.trim_start_matches("0x"), 16).ok()).unwrap_or(0x40)
}


/// UTF-8 text to Latin-1, as the oracle converts its corpus lines.
pub fn latin1(s: &str) -> Vec<u8> {
    s.chars().map(|c| if (c as u32) < 256 { c as u8 } else { b'?' }).collect()
}
