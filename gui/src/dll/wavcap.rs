//! Captures the engine's audio by patching TIBASE32's import of waveOutWrite.
//! Every buffer still goes to the sound card; while recording, a copy is kept.

use std::sync::atomic::{AtomicUsize, Ordering};
use std::sync::Mutex;

use windows_sys::Win32::Foundation::HMODULE;
use windows_sys::Win32::Media::Audio::{HWAVEOUT, WAVEHDR};
use windows_sys::Win32::System::Memory::{VirtualProtect, PAGE_READWRITE};

type WaveOutWrite = unsafe extern "system" fn(HWAVEOUT, *mut WAVEHDR, u32) -> u32;

static REAL: AtomicUsize = AtomicUsize::new(0);
static RECORDING: Mutex<Option<Vec<u8>>> = Mutex::new(None);

pub const SAMPLE_RATE: u32 = 11025;

unsafe extern "system" fn hook(hwo: HWAVEOUT, hdr: *mut WAVEHDR, cb: u32) -> u32 {
    if let Some(buf) = RECORDING.lock().unwrap().as_mut() {
        let h = unsafe { &*hdr };
        if !h.lpData.is_null() {
            buf.extend_from_slice(unsafe { std::slice::from_raw_parts(h.lpData as *const u8, h.dwBufferLength as usize) });
        }
    }
    let real: WaveOutWrite = unsafe { std::mem::transmute(REAL.load(Ordering::Relaxed)) };
    unsafe { real(hwo, hdr, cb) }
}

/// Patch the IAT of `module` (TIBASE32.DLL).  Returns false if not found.
pub fn install(module: HMODULE) -> bool {
    if REAL.load(Ordering::Relaxed) != 0 {
        return true;
    }
    unsafe {
        let base = module as *const u8;
        let rd = |off: usize| (base.add(off) as *const u32).read_unaligned() as usize;
        let nt = rd(0x3C);
        // PE32 optional header starts at nt+24; import directory is entry 1 at +104.
        let imports = rd(nt + 24 + 104);
        let mut desc = imports;
        while rd(desc + 12) != 0 {
            let dll = std::ffi::CStr::from_ptr(base.add(rd(desc + 12)).cast());
            if dll.to_bytes().eq_ignore_ascii_case(b"WINMM.dll") {
                let (mut names, mut iat) = (rd(desc), rd(desc + 16));
                while rd(names) != 0 {
                    let entry = rd(names);
                    if entry & 0x8000_0000 == 0 {
                        let name = std::ffi::CStr::from_ptr(base.add(entry + 2).cast());
                        if name.to_bytes() == b"waveOutWrite" {
                            let slot = base.add(iat) as *mut usize;
                            let mut old = 0;
                            VirtualProtect(slot.cast(), 4, PAGE_READWRITE, &mut old);
                            REAL.store(*slot, Ordering::Relaxed);
                            *slot = hook as WaveOutWrite as usize;
                            VirtualProtect(slot.cast(), 4, old, &mut old);
                            return true;
                        }
                    }
                    names += 4;
                    iat += 4;
                }
            }
            desc += 20;
        }
    }
    false
}

pub fn installed() -> bool {
    REAL.load(Ordering::Relaxed) != 0
}

pub fn start() {
    *RECORDING.lock().unwrap() = Some(Vec::new());
}

pub fn stop() -> Option<Vec<u8>> {
    RECORDING.lock().unwrap().take()
}

/// 8-bit unsigned mono PCM at 11025 Hz.
pub fn write_wav(path: &std::path::Path, data: &[u8]) -> std::io::Result<()> {
    let mut out = Vec::with_capacity(44 + data.len());
    let len = data.len() as u32;
    out.extend_from_slice(b"RIFF");
    out.extend_from_slice(&(36 + len).to_le_bytes());
    out.extend_from_slice(b"WAVEfmt ");
    out.extend_from_slice(&16u32.to_le_bytes());
    out.extend_from_slice(&1u16.to_le_bytes()); // PCM
    out.extend_from_slice(&1u16.to_le_bytes()); // mono
    out.extend_from_slice(&SAMPLE_RATE.to_le_bytes());
    out.extend_from_slice(&SAMPLE_RATE.to_le_bytes()); // bytes/s
    out.extend_from_slice(&1u16.to_le_bytes()); // block align
    out.extend_from_slice(&8u16.to_le_bytes()); // bits
    out.extend_from_slice(b"data");
    out.extend_from_slice(&len.to_le_bytes());
    out.extend_from_slice(data);
    std::fs::write(path, out)
}
