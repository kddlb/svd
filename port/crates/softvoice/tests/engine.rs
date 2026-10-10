//! M6: a fresh `Engine`, configured like the oracle's case (language,
//! preset, setters), must reach the same state as the original.

mod common;

use golden::Case;
use softvoice::engine::Engine;
use softvoice::front::{self, parse, prosody, records, timing};
use softvoice::mem::Mem;

fn u32_at(d: &[u8], o: usize) -> u32 {
    u32::from_le_bytes(d[o..o + 4].try_into().unwrap())
}

/// Engine whose heap blocks land at the oracle's addresses for the first
/// phrase of `case`.
fn engine_for(case: &Case, ph: &[&golden::Snapshot]) -> (Engine, u32) {
    let st0 = ph[0];
    let mut mem = Mem::new();
    mem.alloc_hints.extend([st0.ctx.addr, u32_at(&st0.ctx.data, 0xa4)]);
    let mut e = Engine::with_memory(mem);
    common::configure(&mut e, case);
    if case.meta.get("mode").map(String::as_str) == Some("text") {
        // SVTextToPhon ran first in the oracle and leaves state behind.
        let ttp = case.meta.get("ttp").map(|v| u32::from_str_radix(v.trim_start_matches("0x"), 16).unwrap()).unwrap_or(8);
        let (_, p) = e.text_to_phonemes_raw(&common::latin1(case.text()), ttp, 1 << 18);
        assert_eq!(p, case.phonemes, "case {}: text-to-phonemes", case.id());
    }
    let phon_addr = u32_at(&st0.ctx.data, 0xc8);
    assert!(e.begin(&case.phonemes, common::narrate_flags(case), Some(phon_addr)));
    (e, st0.ctx.addr + 0x13a)
}

/// Context fields that hold OS handles or times in the original (window
/// handles, waveOut handle and device, message id, start time).
const OS_FIELDS: &[(usize, usize)] = &[(0x0, 0x10), (0x20, 0x28), (0x13e, 0x142)];

/// Heap pointers in the language DLLs' .data whose values depend on where
/// the process's allocator put things: the CRT's at-exit tables, and the
/// text-to-phoneme scanner's pointers into the copied input text (same
/// offset within the text in the port and the original).
const CRT_FIELDS: &[(u32, u32)] = &[
    (0x1c250128, 0x1c25012c),
    (0x1c255444, 0x1c25544c),
    (0x1c417094, 0x1c41709c),
    (0x1c25011c, 0x1c250128),
    (0x1c411d6c, 0x1c411d7c),
];

/// Like `common::diff`, but ignoring OS-specific context fields; lists up to
/// eight differing context offsets.
fn diff_engine(m: &Mem, want: &golden::Snapshot) -> Option<String> {
    let got = m.block(want.ctx.addr)?;
    let mut bad = Vec::new();
    for (i, (a, b)) in got.iter().zip(&want.ctx.data).enumerate() {
        if a != b && !OS_FIELDS.iter().any(|&(lo, hi)| (lo..hi).contains(&i)) {
            bad.push(format!("+{i:#x} got {a:#04x} want {b:#04x}"));
        }
    }
    if !bad.is_empty() {
        bad.truncate(8);
        return Some(format!("ctx {}", bad.join(", ")));
    }
    let mut rest = want.clone();
    rest.ctx = golden::Block::default();
    common::diff(m, &rest)
}

/// Every differing 32-bit word of the language DLLs' .data (debug aid).
#[allow(dead_code)]
fn dll_word_diffs(m: &Mem, want: &golden::Snapshot) -> Vec<(u32, u32, u32)> {
    let mut v = Vec::new();
    for b in want.dll_data.iter().skip(1) {
        for o in (0..b.data.len() & !3).step_by(4) {
            let w = u32_at(&b.data, o);
            let g = m.u32(b.addr + o as u32);
            if g != w {
                v.push((b.addr + o as u32, g, w));
            }
        }
    }
    v
}

#[test]
#[ignore]
fn list_dll_word_diffs() {
    let mut all = std::collections::BTreeMap::<u32, usize>::new();
    for file in golden::files() {
        for case in golden::read(&file).unwrap() {
            let phrases = common::phrases(&case);
            let Some(ph) = phrases.first() else { continue };
            if ph.len() != common::STAGES || case.meta.get("mode").map(String::as_str) != Some("text") {
                continue;
            }
            let (mut e, s) = engine_for(&case, ph);
            let m = &mut e.mem;
            parse::split_sentence(m, s);
            m.alloc_hints.extend([ph[1].records.addr, ph[1].commands.addr, ph[7].syllables.addr, ph[12].frames.addr]);
            front::alloc_records(m, s);
            parse::parse(m, s);
            records::assign_voice(m, s);
            records::mark_onsets(m, s);
            records::apply_allophones(m, s);
            records::syllabify(m, s);
            records::mark_after_boundary(m, s);
            prosody::alloc_syllables(m, s);
            prosody::mark_syllables(m, s);
            prosody::f0_contour(m, s);
            timing::durations(m, s);
            timing::tempo(m, s);
            timing::alloc_frames(m, s);
            for (a, g, w) in dll_word_diffs(m, ph[12]) {
                if !(0x1c250128..0x1c25012c).contains(&a) && !(0x1c255444..0x1c25544c).contains(&a) && !(0x1c417094..0x1c41709c).contains(&a) {
                    *all.entry(a).or_default() += 1;
                    if all[&a] == 1 { println!("{a:#x}: got {g:#x} want {w:#x}  ({})", case.text()); }
                }
            }
        }
    }
    println!("{all:x?}");
}

#[test]
fn prologue_and_front_end_match() {
    if golden::missing(|_| true) {
        return;
    }
    let mut failures = Vec::new();
    let mut n = 0;
    for file in golden::files() {
        for case in golden::read(&file).unwrap() {
            let phrases = common::phrases(&case);
            let Some(ph) = phrases.first() else { continue };
            if ph.len() != common::STAGES {
                continue;
            }
            n += 1;
            let (mut e, s) = engine_for(&case, ph);
            let m = &mut e.mem;
            parse::split_sentence(m, s);
            let mut fail = diff_engine(m, ph[0]).map(|d| format!("stage 0: {d}"));
            if fail.is_none() {
                m.alloc_hints.extend([ph[1].records.addr, ph[1].commands.addr, ph[7].syllables.addr, ph[12].frames.addr]);
                front::alloc_records(m, s);
                parse::parse(m, s);
                records::assign_voice(m, s);
                records::mark_onsets(m, s);
                records::apply_allophones(m, s);
                records::syllabify(m, s);
                records::mark_after_boundary(m, s);
                prosody::alloc_syllables(m, s);
                prosody::mark_syllables(m, s);
                prosody::f0_contour(m, s);
                timing::durations(m, s);
                timing::tempo(m, s);
                timing::alloc_frames(m, s);
                // tibase32's .data holds OS bookkeeping (class atom, message
                // id, instance, timers); compare the language modules only.
                let mut lang_only = ph[12].clone();
                if let Some(b) = lang_only.dll_data.first_mut() {
                    *b = golden::Block::default();
                }
                // The CRT's at-exit table pointers (heap addresses) differ.
                for b in lang_only.dll_data.iter_mut().skip(1) {
                    for &(lo, hi) in CRT_FIELDS {
                        if b.addr <= lo && hi <= b.addr + b.data.len() as u32 {
                            let at = (lo - b.addr) as usize;
                            let cur = m.bytes(lo, (hi - lo) as usize).to_vec();
                            b.data[at..at + cur.len()].copy_from_slice(&cur);
                        }
                    }
                }
                fail = diff_engine(m, ph[12]).or_else(|| common::diff_dll_data(m, &lang_only))
                    .map(|d| format!("stage 12: {d}"));
            }
            if let Some(d) = fail {
                failures.push(format!("{} case {} {:?}: {d}", file.file_name().unwrap().to_string_lossy(), case.id(), case.text()));
            }
        }
    }
    assert!(n > 0);
    let shown: Vec<_> = failures.iter().take(20).cloned().collect();
    assert!(failures.is_empty(), "{} of {n} cases differ:\n{}", failures.len(), shown.join("\n"));
}
