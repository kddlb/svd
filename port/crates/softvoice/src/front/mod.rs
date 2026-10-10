//! Phoneme string -> phoneme records -> prosody (language-independent part
//! of TIBASE).  Functions take S (engine context + 0x13a).

pub mod parse;
pub mod prosody;
pub mod records;
pub mod timing;

use crate::mem::Mem;

/// What the narrate driver (`3870`) does between `split_sentence` and
/// `parse`: mark the phrase active and (re)allocate the record array,
/// sized from the sentence (S+0x18 * 2 + 10 records).
pub fn alloc_records(m: &mut Mem, s: u32) {
    m.set_u8(s + 0x31d, 1);
    m.set_u8(s + 0x31c, 2);
    let old = m.u32(s + 0x1c);
    if old != 0 {
        m.free(old);
    }
    let count = (m.u32(s + 0x18).wrapping_mul(2).wrapping_add(10)) as u16;
    m.set_u16(s + 0xc, count);
    let recs = m.alloc(count as usize * parse::REC as usize);
    m.set_u32(s + 0x1c, recs);
}
