//! Sample-rate conversion for the optional 16-bit output (not part of the
//! original engine): a windowed-sinc (Lanczos, a = 8) resampler.

use std::f64::consts::PI;

const A: i64 = 8;

fn sinc(x: f64) -> f64 {
    if x.abs() < 1e-9 { 1.0 } else { (PI * x).sin() / (PI * x) }
}

/// Resample `input` from `from` Hz to `to` Hz.  When downsampling the
/// kernel is widened to act as the anti-aliasing filter.
pub fn resample(input: &[i16], from: u32, to: u32) -> Vec<i16> {
    if from == to || input.is_empty() {
        return input.to_vec();
    }
    let ratio = to as f64 / from as f64;
    let scale = ratio.min(1.0); // cutoff relative to the input Nyquist
    let n = (input.len() as f64 * ratio).round() as usize;
    let width = (A as f64 / scale).ceil() as i64;
    (0..n)
        .map(|i| {
            let t = i as f64 / ratio;
            let c = t.floor() as i64;
            let (mut acc, mut norm) = (0.0, 0.0);
            for k in (c - width + 1)..=(c + width) {
                let d = (t - k as f64) * scale;
                if d.abs() >= A as f64 {
                    continue;
                }
                let w = sinc(d) * sinc(d / A as f64);
                norm += w;
                if k >= 0 && (k as usize) < input.len() {
                    acc += w * input[k as usize] as f64;
                }
            }
            let v = if norm != 0.0 { acc / norm } else { 0.0 };
            v.round().clamp(-32768.0, 32767.0) as i16
        })
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn identity_and_length() {
        let x: Vec<i16> = (0..1000).map(|i| ((i as f64 * 0.05).sin() * 10000.0) as i16).collect();
        assert_eq!(resample(&x, 11025, 11025), x);
        assert_eq!(resample(&x, 11025, 44100).len(), 4000);
        assert_eq!(resample(&x, 11025, 22050).len(), 2000);
    }

    #[test]
    fn low_frequency_sine_survives() {
        // 200 Hz at 11025 Hz, upsampled to 44100 Hz: compare with the exact sine.
        let f = 200.0;
        let x: Vec<i16> = (0..2205).map(|i| ((2.0 * PI * f * i as f64 / 11025.0).sin() * 10000.0) as i16).collect();
        let y = resample(&x, 11025, 44100);
        for (i, v) in y.iter().enumerate().skip(200).take(8000) {
            let want = (2.0 * PI * f * i as f64 / 44100.0).sin() * 10000.0;
            assert!((*v as f64 - want).abs() < 60.0, "sample {i}: {v} vs {want}");
        }
    }
}
