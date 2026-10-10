//! Language modules (TIENG32 / TISPAN32): the `LoadLanguage` structures,
//! the globals TIBASE keeps for them, and the ported module functions.

pub mod duration;
pub mod frames_en;
pub mod frames_es;

use crate::mem::Mem;

/// TIBASE globals holding each language's structure (0 if not loaded).
pub const TIBASE_LANG_EN: u32 = 0x1c012038;
pub const TIBASE_LANG_ES: u32 = 0x1c01203c;
pub const TIBASE_LANG_DE: u32 = 0x1c012040;
/// TIBASE global: language structure in effect while parsing (`DAT_1c014598`).
pub const CURRENT_LANG: u32 = 0x1c014598;

/// The `LoadLanguage` structure: 0xa0 bytes in the DLL's `.bss`.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct LangDef {
    /// Where the DLL's `DllMain` puts the structure.
    pub addr: u32,
    /// Slots [0]..[3]: frame-buffer init, durations, frame generator,
    /// text-to-phoneme driver (addresses of the original functions).
    pub funcs: [u32; 4],
    /// Slot [4]: language id.
    pub id: u32,
    /// Slots [5]..[9]: male and female phoneme tables, feature bits,
    /// voice presets, allophone rules.
    pub tables: [u32; 5],
}

pub const ENGLISH: LangDef = LangDef {
    addr: 0x1c255370,
    funcs: [0x1c206780, 0x1c2010d0, 0x1c204690, 0x1c2067c0],
    id: 1,
    tables: [0x1c24d720, 0x1c24e250, 0x1c24b010, 0x1c24b318, 0x1c24bd28],
};

pub const SPANISH: LangDef = LangDef {
    addr: 0x1c416fc0,
    funcs: [0x1c406210, 0x1c4010d0, 0x1c404020, 0x1c406250],
    id: 2,
    tables: [0x1c40f368, 0x1c40fe98, 0x1c40d010, 0x1c40d318, 0x1c40da50],
};

impl LangDef {
    /// Fill the structure as `LoadLanguage` does.
    pub fn load(&self, m: &mut Mem) {
        for (i, f) in self.funcs.iter().enumerate() {
            m.set_u32(self.addr + 4 * i as u32, *f);
        }
        m.set_u32(self.addr + 0x10, self.id);
        for (i, t) in self.tables.iter().enumerate() {
            m.set_u32(self.addr + 0x14 + 4 * i as u32, *t);
        }
        for o in (0x28..0xa0).step_by(4) {
            m.set_u32(self.addr + o, 0);
        }
    }

    pub fn by_addr(addr: u32) -> Option<&'static LangDef> {
        [&ENGLISH, &SPANISH].into_iter().find(|l| l.addr == addr)
    }
}

/// What loading each language DLL leaves in its `.data` (`DllMain`):
/// process-attach count, OS-version flag, module handle, structure pointer.
fn dll_main(m: &mut Mem, attach_count: u32, version_flag: u32, module_ptr: u32, struct_ptr: u32, def: &LangDef, base: u32) {
    m.set_u32(attach_count, 1);
    m.set_u32(version_flag, 0xffff_ffff);
    m.set_u32(module_ptr, base);
    m.set_u32(struct_ptr, def.addr);
}

/// What `SVOpenSpeech` does for English and Spanish: load both modules and
/// record them in TIBASE's globals.
pub fn install(m: &mut Mem) {
    dll_main(m, 0x1c24ed7c, 0x1c24ed80, 0x1c255438, 0x1c25543c, &ENGLISH, 0x1c200000);
    dll_main(m, 0x1c4109c4, 0x1c4109c8, 0x1c41708c, 0x1c417088, &SPANISH, 0x1c400000);
    ENGLISH.load(m);
    SPANISH.load(m);
    m.set_u32(TIBASE_LANG_EN, ENGLISH.addr);
    m.set_u32(TIBASE_LANG_ES, SPANISH.addr);
    m.set_u32(TIBASE_LANG_DE, 0);
}

/// Call a language module's duration rule (slot [1]) by its original address.
pub fn call_duration(m: &mut Mem, s: u32, func: u32) {
    match func {
        f if f == ENGLISH.funcs[1] => duration::english(m, s),
        f if f == SPANISH.funcs[1] => duration::spanish(m, s),
        _ => panic!("unknown duration rule {func:#x}"),
    }
}

/// Call a language module's frame generator (slot [2]) by its original address.
pub fn call_frames(m: &mut Mem, s: u32, func: u32) {
    match func {
        f if f == ENGLISH.funcs[2] => frames_en::generate(m, s),
        f if f == SPANISH.funcs[2] => frames_es::generate(m, s),
        _ => panic!("unknown frame generator {func:#x}"),
    }
}
