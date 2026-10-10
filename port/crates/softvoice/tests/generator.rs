//! M2 gate: frames (as captured right before generation) -> PCM, bit-exact.

use softvoice::synth::Generator;

/// Run one phrase the way the narrate driver does: 0x2000 samples first,
/// then 0x1000 per returned buffer until the generator stops.
fn run_phrase(g: &mut Generator, frames: &[u8]) -> Vec<u8> {
    let mut out = Vec::new();
    g.generate(frames, &mut out, 0x2000);
    while g.running != 0 {
        g.generate(frames, &mut out, 0x1000);
    }
    out
}

fn first_diff(a: &[u8], b: &[u8]) -> Option<usize> {
    a.iter().zip(b).position(|(x, y)| x != y).or(if a.len() != b.len() { Some(a.len().min(b.len())) } else { None })
}

#[test]
fn pcm_matches_oracle() {
    if golden::missing(|_| true) {
        return;
    }
    let files = golden::files();
    assert!(!files.is_empty(), "no golden files in {}", golden::dir().display());
    let (mut cases, mut phrases, mut failures) = (0, 0, Vec::new());
    for file in &files {
        for case in golden::read(file).unwrap() {
            if case.phrases.is_empty() {
                continue;
            }
            cases += 1;
            let mut pcm = Vec::new();
            for snap in &case.phrases {
                phrases += 1;
                let mut g = Generator::from_context(&snap.ctx.data);
                pcm.extend(run_phrase(&mut g, &snap.frames.data));
            }
            if let Some(at) = first_diff(&pcm, &case.pcm) {
                failures.push(format!(
                    "{} case {} {:?}: first difference at sample {at} (len {} vs {})",
                    file.file_name().unwrap().to_string_lossy(),
                    case.id(),
                    case.text(),
                    pcm.len(),
                    case.pcm.len()
                ));
            }
        }
    }
    println!("{cases} cases, {phrases} phrases");
    assert!(failures.is_empty(), "{} mismatches:\n{}", failures.len(), failures.join("\n"));
}

/// Same, but starting from a zeroed engine and carrying generator state from
/// phrase to phrase, as the real engine does.
#[test]
fn pcm_matches_oracle_with_carried_state() {
    if golden::missing(|_| true) {
        return;
    }
    let mut failures = Vec::new();
    // Each case starts from a zeroed generator, so skip the corpus where one
    // engine speaks many utterances (covered by tests/e2e.rs).
    for file in golden::files().into_iter().filter(|f| !f.ends_with("persist.svg")) {
        for case in golden::read(&file).unwrap() {
            if case.phrases.is_empty() {
                continue;
            }
            let mut g = Generator::default();
            let mut pcm = Vec::new();
            for snap in &case.phrases {
                let flags = u32::from_le_bytes(snap.ctx.data[0x188..0x18c].try_into().unwrap());
                g.start_phrase(11025, flags);
                pcm.extend(run_phrase(&mut g, &snap.frames.data));
            }
            if let Some(at) = first_diff(&pcm, &case.pcm) {
                failures.push(format!("case {} {:?}: first difference at {at}", case.id(), case.text()));
            }
        }
    }
    assert!(failures.is_empty(), "{}", failures.join("\n"));
}
