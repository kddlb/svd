//! Bindings for TIBASE32.DLL (SoftVoice / Talk It!), loaded at runtime.
//! See ../sdk/softvoice.h for the reverse-engineered API notes.

use std::ffi::{c_char, c_void, CStr, CString, OsStr};
use std::os::windows::ffi::OsStrExt;
use std::path::{Path, PathBuf};
use std::ptr::null_mut;

use windows_sys::Win32::Foundation::{HMODULE, HWND};
use windows_sys::Win32::System::LibraryLoader::{GetProcAddress, LoadLibraryW, SetDllDirectoryW};

#[cfg(not(target_arch = "x86"))]
compile_error!("TIBASE32.DLL is 32-bit: build with --target i686-pc-windows-msvc");

pub type Hsv = *mut c_void;

pub const LANG_ENGLISH: u32 = 1;
pub const LANG_SPANISH: u32 = 2;

pub const ERR_LANGUAGE: u32 = 7022;

pub const TTP_WORD_MARKERS: u32 = 0x08;
pub const NARRATE_SYNC_MOUTH: u32 = 0x08;
pub const NARRATE_OVERRIDE: u32 = 0x20;

pub const SYNC_START: u32 = 1000;
pub const SYNC_DONE: u32 = 1001;
pub const SYNC_PLAYING: u32 = 1002;
pub const SYNC_WORD: u32 = 1003;
pub const SYNC_PHONEME: u32 = 1006;
pub const SYNC_INDEX: u32 = 1007;
pub const SYNC_MOUTH: u32 = 1008;

pub const VOICE_CURRENT: u16 = 0xFF;
pub const VOICE_COUNT: u16 = 20;

/// SVVOICEINFO, 0x6A bytes.
#[repr(C, packed(2))]
#[derive(Clone, Copy)]
pub struct VoiceInfo {
    pub name: *mut c_char,
    pub pitch: u16,
    pub rate: u16,
    pub gender: u16,
    pub glottal_source: u16,
    pub voicing_mode: u16,
    pub unknown_0e: i16,
    pub f0_style: u16,
    pub f0_range: u16,
    pub f0_perturb: u16,
    pub unknown_16: [u16; 6],
    pub vowel_factor: u16,
    pub unknown_24: [u16; 2],
    pub av_bias: i16,
    pub ah_bias: i16,
    pub af_bias: i16,
    pub speeds: [i16; 3],
    pub formant_scale: [u16; 6],
    pub f4: u16,
    pub b4: u16,
    pub f5: u16,
    pub b5: u16,
    pub unknown_48: i16,
    pub name_buf: [u8; 32],
}
const _: () = assert!(std::mem::size_of::<VoiceInfo>() == 0x6A);

impl VoiceInfo {
    pub fn zeroed() -> Self {
        // SAFETY: plain old data; a null name pointer is fine.
        unsafe { std::mem::zeroed() }
    }

    pub fn name(&self) -> String {
        let buf = self.name_buf;
        let len = buf.iter().position(|&b| b == 0).unwrap_or(buf.len());
        from_latin1(&buf[..len])
    }
}

/// SVSYNC, the lParam of the "SVSyncMessages" message.
#[repr(C)]
pub struct SyncInfo {
    pub hsv: Hsv,
    pub time: u32,
    pub code: u16,
    pub value: u16,
    pub dvalue: u32,
    pub phon: *const c_char,
    pub position: u32,
    pub reserved: [u32; 2],
}

#[repr(C)]
struct VersionInfo {
    version: u32,
    company: *const c_char,
    date: *const c_char,
    voice_info_size: u16,
}

type FnH = unsafe extern "stdcall" fn(Hsv) -> u32;
type FnHW = unsafe extern "stdcall" fn(Hsv, u16) -> u32;
type FnHS = unsafe extern "stdcall" fn(Hsv, i16) -> u32;

struct Api {
    open: unsafe extern "stdcall" fn(*mut Hsv, HWND, u32, u32, u32) -> u32,
    close: FnH,
    get_languages: unsafe extern "stdcall" fn(Hsv, *mut u32) -> u32,
    set_language: unsafe extern "stdcall" fn(Hsv, u32) -> u32,
    get_version: unsafe extern "stdcall" fn(*mut VersionInfo) -> u32,
    get_error_text: unsafe extern "stdcall" fn(u32, *mut c_char, u16) -> u32,
    text_to_phon: unsafe extern "stdcall" fn(Hsv, *const c_char, *mut c_char, i32, u32, u32) -> i32,
    narrate: unsafe extern "stdcall" fn(Hsv, *const c_char, HWND, u32, u32) -> u32,
    abort: FnH,
    pause: FnH,
    resume: FnH,
    get_voice_info: unsafe extern "stdcall" fn(Hsv, u16, *mut VoiceInfo, u16) -> u32,
    set_personality: FnHW,
    set_pitch: FnHW,
    set_rate: FnHW,
    set_gender: FnHW,
    set_glottal_source: FnHW,
    set_voicing_mode: FnHW,
    set_f0_style: FnHW,
    set_f0_range: FnHW,
    set_f0_perturb: FnHW,
    set_vowel_factor: FnHS,
    set_av_bias: FnHS,
    set_ah_bias: FnHS,
    set_af_bias: FnHS,
}

macro_rules! proc {
    ($module:expr, $name:literal) => {{
        let p = GetProcAddress($module, concat!($name, "\0").as_ptr())
            .ok_or_else(|| format!("TIBASE32.DLL has no export {}", $name))?;
        std::mem::transmute(p)
    }};
}

impl Api {
    unsafe fn load(m: HMODULE) -> Result<Self, String> {
        unsafe {
            Ok(Api {
                open: proc!(m, "_SVOpenSpeech@20"),
                close: proc!(m, "_SVCloseSpeech@4"),
                get_languages: proc!(m, "_SVGetAvailableLanguages@8"),
                set_language: proc!(m, "_SVSetLanguage@8"),
                get_version: proc!(m, "_SVGetVersionInfo@4"),
                get_error_text: proc!(m, "_SVGetErrorText@12"),
                text_to_phon: proc!(m, "_SVTextToPhon@24"),
                narrate: proc!(m, "_SVNarrate@20"),
                abort: proc!(m, "_SVAbort@4"),
                pause: proc!(m, "_SVPause@4"),
                resume: proc!(m, "_SVResume@4"),
                get_voice_info: proc!(m, "_SVGetVoiceInfo@16"),
                set_personality: proc!(m, "_SVSetPersonality@8"),
                set_pitch: proc!(m, "_SVSetPitch@8"),
                set_rate: proc!(m, "_SVSetRate@8"),
                set_gender: proc!(m, "_SVSetGender@8"),
                set_glottal_source: proc!(m, "_SVSetGlottalSource@8"),
                set_voicing_mode: proc!(m, "_SVSetVoicingMode@8"),
                set_f0_style: proc!(m, "_SVSetF0Style@8"),
                set_f0_range: proc!(m, "_SVSetF0Range@8"),
                set_f0_perturb: proc!(m, "_SVSetF0Perturb@8"),
                set_vowel_factor: proc!(m, "_SVSetVowelFactor@8"),
                set_av_bias: proc!(m, "_SVSetAVBias@8"),
                set_ah_bias: proc!(m, "_SVSetAHBias@8"),
                set_af_bias: proc!(m, "_SVSetAFBias@8"),
            })
        }
    }
}

/// An open engine instance.  Must be used from the thread that pumps
/// messages for the notification window (the UI thread).
pub struct Engine {
    api: Api,
    h: Hsv,
    pub dll_dir: PathBuf,
    pub languages: u32,
    pub version: String,
}

pub type SvResult<T = ()> = Result<T, String>;

impl Engine {
    pub fn open(notify: HWND) -> SvResult<Self> {
        let dir = find_dll_dir().ok_or_else(|| {
            "Could not find TIBASE32.DLL next to the program or in a TalkIt folder above it."
                .to_string()
        })?;
        let module = unsafe {
            // The engine LoadLibrary()s TIENG32/TISPAN32 by bare name.
            SetDllDirectoryW(wide(dir.as_os_str()).as_ptr());
            LoadLibraryW(wide(dir.join("tibase32.dll").as_os_str()).as_ptr())
        };
        if module.is_null() {
            return Err(format!("LoadLibrary failed for {}", dir.join("tibase32.dll").display()));
        }
        let api = unsafe { Api::load(module)? };
        super::wavcap::install(module);

        let mut h: Hsv = null_mut();
        let langs = LANG_ENGLISH | LANG_SPANISH;
        let err = unsafe { (api.open)(&mut h, notify, u32::MAX /* WAVE_MAPPER */, langs, 0) };
        let mut engine = Engine { api, h, dll_dir: dir, languages: 0, version: String::new() };
        if h.is_null() {
            return Err(format!("SVOpenSpeech: {}", engine.error_text(err)));
        }
        if err != 0 && err != ERR_LANGUAGE {
            return Err(format!("SVOpenSpeech: {}", engine.error_text(err)));
        }
        unsafe {
            (engine.api.get_languages)(h, &mut engine.languages);
            let mut v = VersionInfo { version: 0, company: std::ptr::null(), date: std::ptr::null(), voice_info_size: 0 };
            if (engine.api.get_version)(&mut v) == 0 {
                engine.version = format!(
                    "{} - {}",
                    CStr::from_ptr(v.company).to_string_lossy(),
                    CStr::from_ptr(v.date).to_string_lossy()
                );
            }
        }
        Ok(engine)
    }

    pub fn error_text(&self, err: u32) -> String {
        let mut buf = [0 as c_char; 128];
        unsafe { (self.api.get_error_text)(err, buf.as_mut_ptr(), buf.len() as u16) };
        let text = unsafe { CStr::from_ptr(buf.as_ptr()) }.to_string_lossy();
        format!("{text} ({err})")
    }

    fn check(&self, what: &str, err: u32) -> SvResult {
        if err == 0 { Ok(()) } else { Err(format!("{what}: {}", self.error_text(err))) }
    }

    pub fn set_language(&self, lang: u32) -> SvResult {
        self.check("SVSetLanguage", unsafe { (self.api.set_language)(self.h, lang) })
    }

    pub fn voice_info(&self, voice: u16) -> SvResult<VoiceInfo> {
        let mut vi = VoiceInfo::zeroed();
        let err = unsafe { (self.api.get_voice_info)(self.h, voice, &mut vi, 0x6A) };
        self.check("SVGetVoiceInfo", err).map(|_| vi)
    }

    pub fn set_personality(&self, voice: u16) -> SvResult {
        self.check("SVSetPersonality", unsafe { (self.api.set_personality)(self.h, voice) })
    }

    pub fn set_pitch(&self, v: u16) -> SvResult { self.check("SVSetPitch", unsafe { (self.api.set_pitch)(self.h, v) }) }
    pub fn set_rate(&self, v: u16) -> SvResult { self.check("SVSetRate", unsafe { (self.api.set_rate)(self.h, v) }) }
    pub fn set_gender(&self, v: u16) -> SvResult { self.check("SVSetGender", unsafe { (self.api.set_gender)(self.h, v) }) }
    pub fn set_glottal_source(&self, v: u16) -> SvResult { self.check("SVSetGlottalSource", unsafe { (self.api.set_glottal_source)(self.h, v) }) }
    pub fn set_voicing_mode(&self, v: u16) -> SvResult { self.check("SVSetVoicingMode", unsafe { (self.api.set_voicing_mode)(self.h, v) }) }
    pub fn set_f0_style(&self, v: u16) -> SvResult { self.check("SVSetF0Style", unsafe { (self.api.set_f0_style)(self.h, v) }) }
    pub fn set_f0_range(&self, v: u16) -> SvResult { self.check("SVSetF0Range", unsafe { (self.api.set_f0_range)(self.h, v) }) }
    pub fn set_f0_perturb(&self, v: u16) -> SvResult { self.check("SVSetF0Perturb", unsafe { (self.api.set_f0_perturb)(self.h, v) }) }
    pub fn set_vowel_factor(&self, v: i16) -> SvResult { self.check("SVSetVowelFactor", unsafe { (self.api.set_vowel_factor)(self.h, v) }) }
    pub fn set_av_bias(&self, v: i16) -> SvResult { self.check("SVSetAVBias", unsafe { (self.api.set_av_bias)(self.h, v) }) }
    pub fn set_ah_bias(&self, v: i16) -> SvResult { self.check("SVSetAHBias", unsafe { (self.api.set_ah_bias)(self.h, v) }) }
    pub fn set_af_bias(&self, v: i16) -> SvResult { self.check("SVSetAFBias", unsafe { (self.api.set_af_bias)(self.h, v) }) }

    /// Text (Latin-1 bytes) to a phoneme string, with @w word markers.
    pub fn text_to_phon(&self, text: &[u8]) -> SvResult<Vec<u8>> {
        let input = CString::new(text.iter().copied().filter(|&b| b != 0).collect::<Vec<_>>()).unwrap();
        let mut size = text.len() * 8 + 4096;
        loop {
            let mut buf = vec![0u8; size];
            let r = unsafe {
                (self.api.text_to_phon)(self.h, input.as_ptr(), buf.as_mut_ptr().cast(), size as i32, TTP_WORD_MARKERS, 0)
            };
            if r == 0 {
                let len = buf.iter().position(|&b| b == 0).unwrap_or(size);
                buf.truncate(len);
                return Ok(buf);
            }
            if r > 0 {
                return Err(format!("SVTextToPhon: {}", self.error_text(r as u32)));
            }
            if size > 1 << 22 {
                return Err("SVTextToPhon: text too long".into());
            }
            size *= 2; // buffer filled up; retry with a larger one
        }
    }

    /// Start speaking.  `phon` must stay alive until SYNC_DONE arrives.
    pub fn narrate(&self, phon: &CStr, notify: HWND, flags: u32) -> SvResult {
        self.check("SVNarrate", unsafe { (self.api.narrate)(self.h, phon.as_ptr(), notify, flags, 0) })
    }

    pub fn abort(&self) { unsafe { (self.api.abort)(self.h) }; }
    pub fn pause(&self) -> SvResult { self.check("SVPause", unsafe { (self.api.pause)(self.h) }) }
    pub fn resume(&self) -> SvResult { self.check("SVResume", unsafe { (self.api.resume)(self.h) }) }
}

impl Drop for Engine {
    fn drop(&mut self) {
        unsafe {
            (self.api.abort)(self.h);
            (self.api.close)(self.h);
        }
    }
}

fn find_dll_dir() -> Option<PathBuf> {
    let has = |d: &Path| d.join("tibase32.dll").is_file();
    let exe = std::env::current_exe().ok()?;
    let mut candidates = Vec::new();
    for dir in exe.ancestors().skip(1).take(6) {
        candidates.push(dir.to_path_buf());
        candidates.push(dir.join("TalkIt"));
    }
    if let Ok(cwd) = std::env::current_dir() {
        candidates.push(cwd.join("TalkIt"));
        candidates.push(cwd);
    }
    candidates.into_iter().find(|d| has(d))
}

fn wide(s: &OsStr) -> Vec<u16> {
    s.encode_wide().chain(std::iter::once(0)).collect()
}

/// One byte per char, so character offsets survive the round trip.
pub fn to_latin1(s: &str) -> Vec<u8> {
    s.chars().map(|c| if (c as u32) < 256 && c != '\0' { c as u8 } else { b'?' }).collect()
}

pub fn from_latin1(b: &[u8]) -> String {
    b.iter().map(|&x| x as char).collect()
}
