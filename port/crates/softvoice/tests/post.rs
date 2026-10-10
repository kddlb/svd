//! M2 gate (frame post-processing): each stage from the previous stage's
//! snapshot must reproduce the next snapshot exactly.

mod common;

use softvoice::mem::Mem;
use softvoice::synth::post;

fn check(stage: usize, run: fn(&mut Mem, u32)) {
    let mut failures = Vec::new();
    let n = common::for_each_phrase(|case, i, ph| {
        let (mut m, s) = common::load(ph[stage - 1]);
        run(&mut m, s);
        if let Some(d) = common::diff(&m, ph[stage]) {
            failures.push(format!("case {} {:?} phrase {i}: {d}", case.id(), case.text()));
        }
    });
    assert!(n > 0, "no stage snapshots (generate a corpus with #stages 1)");
    assert!(failures.is_empty(), "{} of {n} phrases differ:\n{}", failures.len(), failures.join("\n"));
}

#[test]
fn f0_fill_cd40() {
    if golden::missing(|_| true) {
        return;
    }
    check(14, post::fill_f0);
}

#[test]
fn f0_smooth_de60_first() {
    if golden::missing(|_| true) {
        return;
    }
    check(15, post::smooth_f0);
}

#[test]
fn f0_smooth_de60_second() {
    if golden::missing(|_| true) {
        return;
    }
    check(16, post::smooth_f0);
}

#[test]
fn modulate_be40() {
    if golden::missing(|_| true) {
        return;
    }
    check(17, post::modulate);
}
