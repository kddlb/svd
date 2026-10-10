//! Bit-exact Rust port of the SoftVoice text-to-speech engine shipped with
//! Microsoft Plus! for Kids "Talk It!" (TIBASE32/TIENG32/TISPAN32 1.0.0.1117).
//!
//! Function names in comments (e.g. `402c`) refer to `FUN_1c00402c` in
//! TIBASE32.DLL; see `port/re/` for the decompilations and disassembly.

pub mod engine;
pub mod front;
pub mod image;
pub mod lang;
pub mod mem;
pub mod synth;
pub mod ttp;
