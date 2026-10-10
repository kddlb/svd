//! Hidden message-only window that receives the engine's "SVSyncMessages".
//! It lives on the UI thread; winit's message loop dispatches to it.

use std::collections::VecDeque;
use std::sync::atomic::{AtomicU32, Ordering};
use std::sync::{Mutex, OnceLock};

use windows_sys::Win32::Foundation::{HWND, LPARAM, LRESULT, WPARAM};
use windows_sys::Win32::System::LibraryLoader::GetModuleHandleW;
use windows_sys::Win32::UI::WindowsAndMessaging::{
    CreateWindowExW, DefWindowProcW, RegisterClassW, RegisterWindowMessageW, HWND_MESSAGE, WNDCLASSW,
};

use eframe::egui;

use super::sv::SyncInfo;

#[derive(Clone, Copy, Debug)]
pub struct SyncEvent {
    pub code: u32,
    pub value: u16,
    pub time: u32,
    /// Phoneme string the event belongs to; identifies the utterance.
    pub phon: usize,
}

static SYNC_MSG: AtomicU32 = AtomicU32::new(0);
static QUEUE: Mutex<VecDeque<SyncEvent>> = Mutex::new(VecDeque::new());
static REPAINT: OnceLock<egui::Context> = OnceLock::new();

fn w(s: &str) -> Vec<u16> {
    s.encode_utf16().chain(std::iter::once(0)).collect()
}

pub fn create_window(ctx: &egui::Context) -> HWND {
    let _ = REPAINT.set(ctx.clone());
    unsafe {
        SYNC_MSG.store(RegisterWindowMessageW(w("SVSyncMessages").as_ptr()), Ordering::Relaxed);
        let class = w("svguiNotify");
        let wc = WNDCLASSW {
            lpfnWndProc: Some(wndproc),
            hInstance: GetModuleHandleW(std::ptr::null()),
            lpszClassName: class.as_ptr(),
            ..std::mem::zeroed()
        };
        RegisterClassW(&wc);
        CreateWindowExW(
            0,
            class.as_ptr(),
            class.as_ptr(),
            0,
            0,
            0,
            0,
            0,
            HWND_MESSAGE,
            std::ptr::null_mut(),
            wc.hInstance,
            std::ptr::null(),
        )
    }
}

unsafe extern "system" fn wndproc(hwnd: HWND, msg: u32, wp: WPARAM, lp: LPARAM) -> LRESULT {
    let sync = SYNC_MSG.load(Ordering::Relaxed);
    if sync != 0 && msg == sync && lp != 0 {
        // The engine reuses the struct, so copy it out right away.
        let s = unsafe { &*(lp as *const SyncInfo) };
        QUEUE.lock().unwrap().push_back(SyncEvent {
            code: wp as u32,
            value: s.value,
            time: s.time,
            phon: s.phon as usize,
        });
        if let Some(ctx) = REPAINT.get() {
            ctx.request_repaint();
        }
        return 0;
    }
    unsafe { DefWindowProcW(hwnd, msg, wp, lp) }
}

pub fn drain() -> Vec<SyncEvent> {
    QUEUE.lock().unwrap().drain(..).collect()
}
