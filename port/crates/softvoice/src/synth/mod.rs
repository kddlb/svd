//! Frames -> 8-bit PCM.

pub mod generator;
pub mod post;
pub mod resample;

pub use generator::{Generator, RawEvent};

/// Size of one synthesis frame record.
pub const FRAME_SIZE: usize = 0x20;
/// Output sample rate.
pub const SAMPLE_RATE: u32 = 11025;
