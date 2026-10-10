//! End to end: phonemes -> PCM through the public `Engine` must equal the
//! oracle's PCM byte for byte, for every case of every golden file.

mod common;

use softvoice::engine::Engine;

#[test]
fn narrate_matches_oracle_pcm() {
    if golden::missing(|_| true) {
        return;
    }
    let mut failures = Vec::new();
    let mut n = 0;
    for file in golden::files() {
        // Cases recorded with "#persist 1" share one engine per session,
        // as an application would; others get a fresh engine each.
        let mut engine: Option<(String, Engine)> = None;
        for case in golden::read(&file).unwrap() {
            let session = case.meta.get("session").cloned();
            let reuse = matches!((&engine, &session), (Some((a, _)), Some(b)) if a == b);
            if !reuse {
                engine = Some((session.unwrap_or_default(), Engine::new()));
            }
            let Some([narrate_err, done_err, _]) = case.done else { continue };
            n += 1;
            let e = &mut engine.as_mut().unwrap().1;
            if case.meta.get("session").is_none() {
                *e = Engine::new();
            }
            common::configure(e, &case);
            let flags = common::narrate_flags(&case);
            // Text-mode cases start from the text, as the oracle did.
            if case.meta.get("mode").map(String::as_str) == Some("text") {
                let text = common::latin1(case.text());
                let ttp = case.meta.get("ttp").map(|v| u32::from_str_radix(v.trim_start_matches("0x"), 16).unwrap()).unwrap_or(8);
                let cap = case.meta.get("ttpbuf").and_then(|v| v.parse().ok()).unwrap_or(1 << 18);
                let (r, p) = e.text_to_phonemes_raw(&text, ttp, cap);
                if Some(r) != case.ttp_result || p != case.phonemes {
                    failures.push(format!("{} case {} {:?}: text-to-phonemes differs", file.file_name().unwrap().to_string_lossy(), case.id(), case.text()));
                    continue;
                }
            }
            let result = std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| e.narrate(&case.phonemes, flags)));
            let problem = match result {
                Err(_) => Some("panicked".to_string()),
                Ok(Err(err)) if err == narrate_err => None,
                Ok(Err(err)) => Some(format!("narrate failed with {err}, oracle {narrate_err}")),
                Ok(Ok(_)) if narrate_err != 0 => Some(format!("narrate succeeded, oracle failed with {narrate_err}")),
                Ok(Ok(u)) => {
                    if u.done_error as u32 != done_err {
                        Some(format!("done error {} vs {done_err}", u.done_error))
                    } else if u.pcm != case.pcm {
                        let at = u.pcm.iter().zip(&case.pcm).position(|(a, b)| a != b).unwrap_or(u.pcm.len().min(case.pcm.len()));
                        Some(format!("PCM differs at sample {at} (len {} vs {})", u.pcm.len(), case.pcm.len()))
                    } else {
                        None
                    }
                }
            };
            if let Some(p) = problem {
                failures.push(format!("{} case {} {:?}: {p}", file.file_name().unwrap().to_string_lossy(), case.id(), case.text()));
            }
        }
    }
    println!("{n} cases compared");
    assert!(n > 0);
    let shown: Vec<_> = failures.iter().take(20).cloned().collect();
    assert!(failures.is_empty(), "{} of {n} cases differ:\n{}", failures.len(), shown.join("\n"));
}

/// The optional 16-bit stream must leave the faithful 8-bit output alone and
/// agree with it to within one 8-bit step.
#[test]
fn hifi_matches_8bit_stream() {
    if golden::missing(|_| true) {
        return;
    }
    let mut checked = 0;
    // Fresh engine per case, so skip the persistent-session corpus.
    for file in golden::files().into_iter().filter(|f| !f.ends_with("persist.svg")) {
        for case in golden::read(&file).unwrap().into_iter().filter(|c| c.done == Some([0, 0, c.done.map_or(0, |d| d[2])])).take(40) {
            let mut e = Engine::new();
            e.hifi = true;
            common::configure(&mut e, &case);
            let u = e.narrate(&case.phonemes, common::narrate_flags(&case)).unwrap();
            assert_eq!(u.pcm, case.pcm, "case {}: 8-bit output changed", case.id());
            let h = u.pcm16.expect("pcm16");
            assert_eq!(h.len(), u.pcm.len());
            for (i, (&a, &b)) in h.iter().zip(&u.pcm).enumerate() {
                let byte = (b as i32 - 0x80) * 256;
                assert!((a as i32 - byte).abs() <= 256, "case {} sample {i}: {a} vs {byte}", case.id());
            }
            checked += 1;
        }
    }
    assert!(checked > 0);
}

/// Sanity check for the persistence corpus: carried-over engine state must
/// actually change some utterances, or the session test proves nothing.
#[test]
fn persistent_state_matters() {
    let path = golden::dir().join("persist.svg");
    if !path.exists() {
        return;
    }
    let mut differ = 0;
    for case in golden::read(&path).unwrap() {
        let Some([0, _, _]) = case.done else { continue };
        let mut e = Engine::new();
        common::configure(&mut e, &case);
        if let Ok(u) = e.narrate(&case.phonemes, common::narrate_flags(&case)) {
            differ += (u.pcm != case.pcm) as usize;
        }
    }
    println!("{differ} persistent-session utterances differ from a fresh engine");
    assert!(differ > 0, "the persistence corpus does not exercise carried state");
}
