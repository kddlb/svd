//! M3 gate: each tibase front-end stage, run on the oracle's snapshot from
//! before it, must reproduce the snapshot after it exactly.

mod common;

use softvoice::front;
use softvoice::lang;

#[test]
fn parse_4a10() {
    if golden::missing(|_| true) {
        return;
    }
    let mut failures = Vec::new();
    let n = common::for_each_phrase(|case, i, ph| {
        let (before, after) = (ph[0], ph[1]);
        let (mut m, s) = common::load_case(before, Some(case));
        lang::install(&mut m);
        m.alloc_hints.extend([after.records.addr, after.commands.addr]);
        front::alloc_records(&mut m, s);
        let r = front::parse::parse(&mut m, s);
        if let Some(d) = common::diff(&m, after) {
            failures.push(format!("case {} {:?} phrase {i} (parse returned {r:#x}): {d}", case.id(), case.text()));
        }
    });
    assert!(n > 0);
    assert!(failures.is_empty(), "{} of {n} phrases differ:\n{}", failures.len(), failures.join("\n"));
}

/// Run `run` on each phrase's snapshot `stage - 1` and compare with `stage`.
fn check(stage: usize, run: fn(&mut softvoice::mem::Mem, u32)) {
    let mut failures = Vec::new();
    let n = common::for_each_phrase(|case, i, ph| {
        let (mut m, s) = common::load(ph[stage - 1]);
        lang::install(&mut m);
        // Blocks the stage allocates get the oracle's addresses.
        match stage {
            7 => m.alloc_hints.push_back(ph[stage].syllables.addr),
            12 => m.alloc_hints.push_back(ph[stage].frames.addr),
            _ => {}
        }
        run(&mut m, s);
        if let Some(d) = common::diff(&m, ph[stage]) {
            failures.push(format!("case {} {:?} phrase {i}: {d}", case.id(), case.text()));
        }
    });
    assert!(n > 0);
    let shown: Vec<_> = failures.iter().take(15).cloned().collect();
    assert!(failures.is_empty(), "{} of {n} phrases differ:\n{}", failures.len(), shown.join("\n"));
}

#[test]
fn voice_3e40() {
    if golden::missing(|_| true) {
        return;
    }
    check(2, front::records::assign_voice);
}

#[test]
fn onsets_c550() {
    if golden::missing(|_| true) {
        return;
    }
    check(3, front::records::mark_onsets);
}

#[test]
fn allophones_5910() {
    if golden::missing(|_| true) {
        return;
    }
    check(4, front::records::apply_allophones);
}

#[test]
fn syllables_c6d0() {
    if golden::missing(|_| true) {
        return;
    }
    check(5, front::records::syllabify);
}

#[test]
fn boundaries_3de0() {
    if golden::missing(|_| true) {
        return;
    }
    check(6, front::records::mark_after_boundary);
}

#[test]
fn syllable_arrays_cc10() {
    if golden::missing(|_| true) {
        return;
    }
    check(7, |m, s| {
        front::prosody::alloc_syllables(m, s);
    });
}

#[test]
fn stress_c8c0() {
    if golden::missing(|_| true) {
        return;
    }
    check(8, front::prosody::mark_syllables);
}

#[test]
fn f0_contour_cdc0() {
    if golden::missing(|_| true) {
        return;
    }
    check(9, front::prosody::f0_contour);
}

#[test]
fn tempo_f7c0() {
    if golden::missing(|_| true) {
        return;
    }
    check(11, front::timing::tempo);
}

#[test]
fn frame_alloc_c420() {
    if golden::missing(|_| true) {
        return;
    }
    check(12, |m, s| {
        front::timing::alloc_frames(m, s);
    });
}

#[test]
fn durations_c3e0() {
    if golden::missing(|_| true) {
        return;
    }
    let mut failures = Vec::new();
    let n = common::for_each_phrase(|case, i, ph| {
        let (mut m, s) = common::load(ph[9]);
        lang::install(&mut m);
        common::load_dll_data(&mut m, ph[9]);
        front::timing::durations(&mut m, s);
        let d = common::diff(&m, ph[10]).or_else(|| common::diff_dll_data(&m, ph[10]));
        if let Some(d) = d {
            failures.push(format!("case {} {:?} phrase {i}: {d}", case.id(), case.text()));
        }
    });
    assert!(n > 0);
    let shown: Vec<_> = failures.iter().take(15).cloned().collect();
    assert!(failures.is_empty(), "{} of {n} phrases differ:\n{}", failures.len(), shown.join("\n"));
}
