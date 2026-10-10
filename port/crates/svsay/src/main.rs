//! svsay - speak with the Rust port of the SoftVoice (Talk It!) engine.
//!
//!   svsay [options] text...
//!     -l en|es      language (default en)
//!     -v N          personality preset 0..19
//!     -r WPM        rate 20..500
//!     -p HZ         pitch 10..2000
//!     -f FLAGS      narrate flags (SV_NARRATE_*), e.g. 0x0f for all syncs
//!     -P            the text is a phoneme string
//!     -n            print the phonemes only, do not speak
//!     -w FILE       write a WAV file (11025 Hz, 8-bit mono) instead of playing
//!     -e            print sync events
//!     -H            16-bit "hi-fi" output (not bit-exact: the original's
//!                   output curve without 8-bit truncation)
//!     -R HZ         resample to HZ (implies -H), e.g. 22050 or 44100

use std::sync::atomic::{AtomicUsize, Ordering};
use std::sync::Arc;
use std::time::Duration;

use cpal::traits::{DeviceTrait, HostTrait, StreamTrait};
use softvoice::engine::{Engine, Event, Language};
use softvoice::synth::SAMPLE_RATE;

struct Options {
    lang: Language,
    voice: Option<u16>,
    rate: Option<u16>,
    pitch: Option<u16>,
    flags: u32,
    phonemes: bool,
    phon_only: bool,
    wav: Option<String>,
    events: bool,
    hifi: bool,
    out_rate: Option<u32>,
    text: String,
}

fn usage() -> ! {
    eprintln!("usage: svsay [-l en|es] [-v N] [-r WPM] [-p HZ] [-f FLAGS] [-P] [-n] [-w out.wav] [-e] [-H] [-R HZ] text...");
    std::process::exit(2);
}

fn parse_args() -> Options {
    let mut o = Options {
        lang: Language::English,
        voice: None,
        rate: None,
        pitch: None,
        flags: 0,
        phonemes: false,
        phon_only: false,
        wav: None,
        events: false,
        hifi: false,
        out_rate: None,
        text: String::new(),
    };
    let mut args = std::env::args().skip(1);
    let num = |v: Option<String>| -> u32 {
        let v = v.unwrap_or_else(|| usage());
        let r = match v.strip_prefix("0x") {
            Some(h) => u32::from_str_radix(h, 16),
            None => v.parse(),
        };
        r.unwrap_or_else(|_| usage())
    };
    while let Some(a) = args.next() {
        match a.as_str() {
            "-l" => o.lang = if args.next().as_deref() == Some("es") { Language::Spanish } else { Language::English },
            "-v" => o.voice = Some(num(args.next()) as u16),
            "-r" => o.rate = Some(num(args.next()) as u16),
            "-p" => o.pitch = Some(num(args.next()) as u16),
            "-f" => o.flags = num(args.next()),
            "-w" => o.wav = Some(args.next().unwrap_or_else(|| usage())),
            "-P" => o.phonemes = true,
            "-n" => o.phon_only = true,
            "-e" => o.events = true,
            "-H" => o.hifi = true,
            "-R" => {
                o.out_rate = Some(num(args.next()));
                o.hifi = true;
            }
            "-h" | "--help" => usage(),
            _ => {
                if !o.text.is_empty() {
                    o.text.push(' ');
                }
                o.text.push_str(&a);
            }
        }
    }
    if o.text.is_empty() {
        usage();
    }
    o
}

fn latin1(s: &str) -> Vec<u8> {
    s.chars().map(|c| if (c as u32) < 256 { c as u8 } else { b'?' }).collect()
}

/// Mono PCM WAV: `bits` 8 (unsigned) or 16 (signed little-endian).
fn write_wav(path: &str, data: &[u8], rate: u32, bits: u16) -> std::io::Result<()> {
    let mut out = Vec::with_capacity(44 + data.len());
    let len = data.len() as u32;
    let block = bits / 8;
    out.extend_from_slice(b"RIFF");
    out.extend_from_slice(&(36 + len).to_le_bytes());
    out.extend_from_slice(b"WAVEfmt ");
    out.extend_from_slice(&16u32.to_le_bytes());
    out.extend_from_slice(&1u16.to_le_bytes());
    out.extend_from_slice(&1u16.to_le_bytes());
    out.extend_from_slice(&rate.to_le_bytes());
    out.extend_from_slice(&(rate * block as u32).to_le_bytes());
    out.extend_from_slice(&block.to_le_bytes());
    out.extend_from_slice(&bits.to_le_bytes());
    out.extend_from_slice(b"data");
    out.extend_from_slice(&len.to_le_bytes());
    out.extend_from_slice(data);
    std::fs::write(path, out)
}

/// Play 16-bit PCM at `src_rate` on the default output device and wait.
fn play(pcm: &[i16], src_rate: u32) -> Result<(), String> {
    let host = cpal::default_host();
    let device = host.default_output_device().ok_or("no audio output device")?;
    let supported = device.default_output_config().map_err(|e| e.to_string())?;
    let config: cpal::StreamConfig = supported.config();
    let rate = config.sample_rate;
    let channels = config.channels as usize;

    // Linear resampling to the device rate.
    let resampled = softvoice::synth::resample::resample(pcm, src_rate, rate);
    let samples: Arc<Vec<f32>> = Arc::new(resampled.iter().map(|&v| v as f32 / 32768.0).collect());
    let pos = Arc::new(AtomicUsize::new(0));
    let (s2, p2) = (samples.clone(), pos.clone());
    let stream = match supported.sample_format() {
        cpal::SampleFormat::F32 => device.build_output_stream(
            config,
            move |out: &mut [f32], _| {
                for frame in out.chunks_mut(channels) {
                    let i = p2.fetch_add(1, Ordering::Relaxed);
                    let v = s2.get(i).copied().unwrap_or(0.0);
                    frame.fill(v);
                }
            },
            |e| eprintln!("audio error: {e}"),
            None,
        ),
        cpal::SampleFormat::I16 => device.build_output_stream(
            config,
            move |out: &mut [i16], _| {
                for frame in out.chunks_mut(channels) {
                    let i = p2.fetch_add(1, Ordering::Relaxed);
                    let v = s2.get(i).copied().unwrap_or(0.0);
                    frame.fill((v * 32767.0) as i16);
                }
            },
            |e| eprintln!("audio error: {e}"),
            None,
        ),
        f => return Err(format!("unsupported sample format {f:?}")),
    }
    .map_err(|e| e.to_string())?;
    stream.play().map_err(|e| e.to_string())?;
    while pos.load(Ordering::Relaxed) < samples.len() {
        std::thread::sleep(Duration::from_millis(20));
    }
    std::thread::sleep(Duration::from_millis(100));
    Ok(())
}

fn event_name(code: u16) -> &'static str {
    match code {
        1000 => "START",
        1001 => "DONE",
        1002 => "PLAYING",
        1003 => "WORD",
        1004 => "1004",
        1005 => "1005",
        1006 => "PHONEME",
        1007 => "INDEX",
        1008 => "MOUTH",
        _ => "?",
    }
}

fn main() {
    let o = parse_args();
    let mut engine = Engine::new();
    engine.set_language(o.lang);
    let check = |what: &str, r: Result<(), u32>| {
        if let Err(e) = r {
            eprintln!("{what}: error {e}");
            std::process::exit(1);
        }
    };
    if let Some(v) = o.voice {
        check("voice", engine.set_personality(v));
    }
    if let Some(r) = o.rate {
        check("rate", engine.set_rate(r));
    }
    if let Some(p) = o.pitch {
        check("pitch", engine.set_pitch(p));
    }

    let phonemes = if o.phonemes {
        latin1(&o.text)
    } else {
        // SV_TTP_WORD_MARKERS, so word sync events refer to the text.
        match engine.text_to_phonemes(&latin1(&o.text), 0x08) {
            Ok(p) => p,
            Err(e) => {
                eprintln!("text to phonemes: error {e}");
                std::process::exit(1);
            }
        }
    };
    if o.phon_only {
        println!("{}", phonemes.iter().map(|&b| b as char).collect::<String>());
        return;
    }

    engine.hifi = o.hifi;
    let utt = match engine.narrate(&phonemes, o.flags) {
        Ok(u) => u,
        Err(e) => {
            eprintln!("narrate: error {e}");
            std::process::exit(1);
        }
    };
    if o.events {
        for Event { code, value, sample } in &utt.events {
            println!("{:>8.3}s  {:<7} ({code}) value={value}", *sample as f64 / SAMPLE_RATE as f64, event_name(*code));
        }
    }
    if utt.done_error != 0 {
        eprintln!("speech ended with error {}", utt.done_error);
    }
    let out_rate = o.out_rate.unwrap_or(SAMPLE_RATE);
    match &o.wav {
        Some(path) => {
            let (data, bits) = if o.hifi {
                let s = utt.pcm16_at(out_rate);
                (s.iter().flat_map(|v| v.to_le_bytes()).collect::<Vec<u8>>(), 16)
            } else {
                (utt.pcm.clone(), 8)
            };
            if let Err(e) = write_wav(path, &data, out_rate, bits) {
                eprintln!("{path}: {e}");
                std::process::exit(1);
            }
            let secs = utt.pcm.len() as f64 / SAMPLE_RATE as f64;
            println!("wrote {path}: {out_rate} Hz {bits}-bit, {secs:.2} s");
        }
        None => {
            if let Err(e) = play(&utt.pcm16_at(SAMPLE_RATE), SAMPLE_RATE) {
                eprintln!("playback: {e}");
                std::process::exit(1);
            }
        }
    }
}
