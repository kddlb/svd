//! M5 gate: `SVTextToPhon` must reproduce the oracle's phoneme strings and
//! return values for every case of every `ttp*` golden file.

use softvoice::lang::{self, ENGLISH, SPANISH};
use softvoice::mem::Mem;
use softvoice::ttp;

/// The oracle's default output buffer (`static char phon[1 << 18]`).
const DEFAULT_BUF: i32 = 1 << 18;

/// UTF-8 to Latin-1 as the oracle's `ToLatin1` does (other chars become '?').
fn latin1(s: &str) -> Vec<u8> {
    s.chars().take(8191).map(|c| if (c as u32) < 256 { c as u32 as u8 } else { b'?' }).collect()
}

struct Job {
    file: String,
    id: String,
    text: String,
    lang: String,
    flags: u32,
    buf: i32,
    want: Vec<u8>,
    want_r: i32,
}

fn run(job: &Job) -> Result<(), String> {
    let mut m = Mem::new();
    lang::install(&mut m);
    let def = if job.lang == "es" { &SPANISH } else { &ENGLISH };
    let ctx = ttp::context(&mut m, def);
    let text = latin1(&job.text);
    let (r, got) = ttp::text_to_phon(&mut m, ctx, &text, job.buf, job.flags);
    if r != job.want_r || got != job.want {
        return Err(format!(
            "{} case {} [{} ttp={:#x} buf={}] {:?}\n   got  {} {:?}\n   want {} {:?}",
            job.file,
            job.id,
            job.lang,
            job.flags,
            job.buf,
            job.text,
            r,
            String::from_utf8_lossy(&got),
            job.want_r,
            String::from_utf8_lossy(&job.want)
        ));
    }
    Ok(())
}

#[test]
fn text_to_phon() {
    if golden::missing(|n| n.starts_with("ttp")) {
        return;
    }
    let mut jobs = Vec::new();
    for path in golden::files() {
        let name = path.file_name().unwrap().to_string_lossy().to_string();
        if !name.starts_with("ttp") {
            continue;
        }
        for case in golden::read(&path).unwrap() {
            if case.meta.get("mode").map(String::as_str) != Some("text") {
                continue;
            }
            let flags = u32::from_str_radix(case.meta["ttp"].trim_start_matches("0x"), 16).unwrap();
            let buf = case.meta.get("ttpbuf").map(|v| v.parse().unwrap()).unwrap_or(DEFAULT_BUF);
            jobs.push(Job {
                file: name.clone(),
                id: case.id().to_string(),
                text: case.text().to_string(),
                lang: case.meta["lang"].clone(),
                flags,
                buf,
                want: case.phonemes.clone(),
                want_r: case.ttp_result.expect("no TTPR chunk"),
            });
        }
    }
    assert!(!jobs.is_empty(), "no ttp* golden files");
    // WebAssembly (wasm32-wasip1) has no threads, and panics abort.
    let threads = if cfg!(target_family = "wasm") {
        1
    } else {
        std::thread::available_parallelism().map(|n| n.get()).unwrap_or(4)
    };
    let chunk = jobs.len().div_ceil(threads);
    let mut failures: Vec<String> = if threads == 1 {
        jobs.iter().filter_map(|j| run(j).err()).collect()
    } else {
        std::thread::scope(|sc| {
        let hs: Vec<_> = jobs
            .chunks(chunk)
            .map(|part| {
                sc.spawn(move || {
                    part.iter()
                        .filter_map(|j| match std::panic::catch_unwind(|| run(j)) {
                            Ok(Ok(())) => None,
                            Ok(Err(e)) => Some(e),
                            Err(_) => Some(format!("{} case {} {:?}: panicked", j.file, j.id, j.text)),
                        })
                        .collect::<Vec<_>>()
                })
            })
            .collect();
        hs.into_iter().flat_map(|h| h.join().unwrap()).collect()
        })
    };
    failures.sort();
    let shown: Vec<_> = failures.iter().take(30).cloned().collect();
    assert!(failures.is_empty(), "{} of {} cases differ:\n{}", failures.len(), jobs.len(), shown.join("\n"));
    eprintln!("{} cases match", jobs.len());
}
