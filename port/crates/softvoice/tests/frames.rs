//! M4 gate (frame generation): stage 13 (`5840` + the language module's
//! frame generator) from the stage-12 snapshot, including the language
//! DLLs' `.data`, must reproduce the stage-13 snapshot exactly.
//!
//! Run one language with `cargo test --release --test frames english` or
//! `... spanish`.

mod common;

use softvoice::front;
use softvoice::lang;

fn check(lang_filter: &str) {
    let mut failures = Vec::new();
    let mut n = 0;
    common::for_each_phrase(|case, i, ph| {
        if case.meta.get("lang").map(String::as_str) != Some(lang_filter) {
            return;
        }
        // Phrases that switch language mid-way use both generators.
        if case.phonemes.windows(9).any(|w| w == b"{language") {
            return;
        }
        n += 1;
        let (mut m, s) = common::load(ph[12]);
        lang::install(&mut m);
        common::load_dll_data(&mut m, ph[12]);
        let result = std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| {
            front::timing::frames(&mut m, s);
        }));
        let d = match result {
            Err(e) => Some(format!(
                "panicked: {}",
                e.downcast_ref::<String>().cloned().or_else(|| e.downcast_ref::<&str>().map(|s| s.to_string())).unwrap_or_default()
            )),
            Ok(()) => common::diff(&m, ph[13]).or_else(|| common::diff_dll_data(&m, ph[13])),
        };
        if let Some(d) = d {
            failures.push(format!("case {} {:?} phrase {i}: {d}", case.id(), case.text()));
        }
    });
    assert!(n > 0, "no {lang_filter} phrases with stage snapshots");
    let shown: Vec<_> = failures.iter().take(15).cloned().collect();
    assert!(failures.is_empty(), "{} of {n} phrases differ:\n{}", failures.len(), shown.join("\n"));
}

#[test]
fn english() {
    check("en");
}

#[test]
fn spanish() {
    check("es");
}
