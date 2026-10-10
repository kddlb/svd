# SoftVoice (Talk It!) — reverse engineering and a bit-exact Rust port

*Microsoft Plus! for Kids* (1996) shipped **Talk It!**, a toy text-to-speech
program built on **SoftVoice**, a formant synthesizer by SoftVoice, Inc. It
speaks English and Spanish through three 32-bit DLLs: `TIBASE32.DLL` (the
engine), `TIENG32.DLL` and `TISPAN32.DLL` (the language modules).

This repository contains:

- **A documented API** for those DLLs (`sdk/softvoice.h`) and a small C
  program that drives them (`sdk/svsay.c`).
- **A Rust port of the engine** (`port/crates/softvoice`) that produces the
  same output as the original, **byte for byte**: text → phonemes → 8-bit
  11025 Hz PCM, English and Spanish, every voice preset and embedded
  command.
- **A CLI** (`port/crates/svsay`) and **a GUI** (`gui/`, egui) built on the
  port.
- **The test oracle** (`port/oracle`): a 32-bit Windows program that runs the
  original DLLs headless, with every audio call stubbed out, and records
  their behaviour as reference ("golden") data for the tests.
- **A reference** for the phoneme codes, `{embedded commands}`, error and
  sync codes, and flags: [`docs/codes.md`](docs/codes.md).

## ⚠️ You need the original DLLs

**The DLLs are not included and are not redistributable.** This repository
contains none of their bytes. To build anything, put `tibase32.dll`,
`tieng32.dll` and `tispan32.dll` (version 1.0.0.1117, from Talk It!) in
`TalkIt/`, or point `SOFTVOICE_DLL_DIR` at them.

- **Building the Rust port requires the DLLs.** `port/crates/softvoice/build.rs`
  reads them at build time and refuses any other build. The engine reads its
  data from them by address: glottal waveforms, filter tables, phoneme
  targets, voice presets, letter-to-sound rules and the English exception
  dictionary.
- **Running the built programs doesn't.** The build embeds the DLL images, so
  `svsay` and `svgui` run without the DLLs present.
- **Built binaries therefore contain Microsoft/SoftVoice code and data.** Use
  them yourself, but don't redistribute them, any more than you would the
  DLLs.

## Platforms

| Part | Windows | macOS / Linux |
|---|---|---|
| `softvoice` engine crate, `svsay` CLI, `svgui` (Rust backend) | ✅ built and tested | should work (pure Rust plus cpal/eframe), **untested**. Linux needs ALSA dev headers for cpal. |
| Test suite (`cargo test`) | ✅ | should work, given golden data copied from a Windows machine |
| Oracle, golden-data generation, `sdk/svsay.c`, GUI "Original DLLs" backend | ✅ (32-bit MSVC) | ❌ these load the original 32-bit Windows DLLs |

## Building

Rust (stable) and the DLLs in `TalkIt/` are required.

```sh
cd port
cargo build --release              # engine + svsay CLI
target/release/svsay "Hello, world."                   # speak
target/release/svsay -l es -v 3 "Hola, ¿cómo estás?"   # Spanish, "Child" voice
target/release/svsay -w hello.wav "Hello, world."      # write a WAV instead
target/release/svsay -P "{f0style sing; c4} LAA5 {e4} LAA5 {g4} LAA5."   # phonemes
target/release/svsay -H -R 44100 -w hifi.wav "Hello."  # 16-bit 44.1 kHz (extension)

cd ../gui
cargo run --release                # GUI on the Rust port
cargo run --release --target i686-pc-windows-msvc      # + "Original DLLs" backend for A/B
```

`svsay -h` lists all options. `-e` prints the sync events (word, mouth
shape, …).

## How exact is it?

The tests compare the port with the original DLLs on golden data that the
oracle records. They check every pipeline stage (memory snapshots of the
original's internal structures) and the end result:

- **Text → phonemes:** 33,262 cases (English dictionary, letter-to-sound
  rules, numbers, dates, times, money, Latin-1, flags, buffer overflow).
- **Phonemes → PCM:** ~3,000 utterances covering all 20 presets, every setter,
  embedded commands, singing, multi-sentence text, and **long-lived engines**:
  115 utterances spoken back to back on one engine, where state carried
  between utterances matters.

All of these are identical byte for byte. Some quirks of the original are
reproduced on purpose; see `docs/codes.md` and the module comments.

**Not ported or not covered:**

- User dictionaries (`SVLoadUserDictionary`). The file format was never
  documented, and there are no samples.
- The 8000 Hz output path. The engine always runs at 11025 Hz.
- A few paths where the original reads uninitialised stack memory, which no
  test input reaches. They're modelled with fixed values and documented in
  the code.
- Inputs that crash the original (e.g. Spanish `IL`/`IM`/`IN`, `1.5/2` in
  text) also panic in the port.

**Extensions** (not part of the original and not bit-exact by design):

- 16-bit output with interpolated companding (`Engine::hifi`, `svsay -H`).
- A windowed-sinc resampler (`svsay -R`).
- `Engine::text_to_phonemes`, which splits text longer than the original's
  514-character limit. `text_to_phonemes_raw` keeps the original behaviour.

## Regenerating the golden data

Building and running don't need golden data; only the comparison tests
do. Without it, `cargo test` still passes: each golden-data test prints
"skipping: no golden data" (visible with `-- --nocapture`) and returns.

The golden files (~800 MB) aren't in the repository. On Windows, with
MSVC Build Tools:

```bat
port\oracle\build.cmd
cd port\oracle\build
oracle.exe ..\..\corpus\smoke.txt ..\..\golden\smoke.svg
rem ...and likewise for each corpus/*.txt (generators in port/tools/)
cd ..\..\
cargo test -p softvoice --release
```

The oracle never plays audio: it replaces every `waveOut*` import of the
engine with a stub and refuses to run if any is left unhooked.

## Repository layout

```
docs/codes.md         phoneme codes, {commands}, error/sync codes, flags
sdk/                  softvoice.h (reconstructed API), svsay.c, build.cmd
port/crates/softvoice the engine (src/{front,lang,synth,ttp}, engine.rs)
port/crates/svsay     CLI
port/crates/golden    golden-file reader
port/oracle/          oracle.c: runs the original DLLs and records golden data
port/corpus/          test inputs (generated by port/tools/mkcorpus*.py)
port/re/              decompilations and disassembly used for the port
gui/                  egui GUI (Rust port; original DLLs in 32-bit builds)
```

## How the port works

The original is C (plus some hand-written x86 assembly) full of pointer
arithmetic over packed structures and DLL globals. To make byte-for-byte
comparison possible, the port runs on a small model of the original's
memory (`port/crates/softvoice/src/mem.rs`):

- the three DLL images mapped at their original addresses;
- heap blocks placed wherever they were allocated.

Each function is a faithful transliteration that names its original
(`FUN_1c00402c` → `synth/generator.rs`). Oracle snapshots load straight into
that model, so every stage can be tested in isolation. The code is
therefore literal rather than idiomatic; with the tests in place it can be
refactored safely.

## Legal

This is an independent research and preservation project, not affiliated
with Microsoft or SoftVoice, Inc. "Talk It!", "Microsoft Plus! for Kids" and
"SoftVoice" belong to their respective owners. The original software isn't
included, and the port is useless without it.
