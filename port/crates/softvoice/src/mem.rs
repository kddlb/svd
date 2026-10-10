//! A small model of the original engine's memory.
//!
//! The C code this crate ports is full of pointer arithmetic over packed
//! structures (the engine context, 26-byte phoneme records, 32-byte frames,
//! 6-byte command entries) and over tables inside the DLLs.  Porting it on
//! top of this flat model keeps it bit-exact and makes every intermediate
//! state directly comparable with the oracle's snapshots, which load into a
//! `Mem` at their original addresses.
//!
//! Addresses are 32-bit: the three DLL images live at their preferred bases
//! (writable copies, since the language DLLs keep state in their `.data`),
//! and heap blocks live wherever they were allocated.

use crate::image::{TIBASE, TIENG, TISPAN};

struct Block {
    base: u32,
    data: Vec<u8>,
}

pub struct Mem {
    images: [(u32, Vec<u8>); 3],
    heap: Vec<Block>,
    next: u32,
    /// Addresses to hand out for the next allocations (tests use this to
    /// reproduce the oracle's heap layout so blocks compare byte for byte).
    pub alloc_hints: std::collections::VecDeque<u32>,
    /// Per-instance state the original kept in stack slots that survive
    /// between calls (see the frame generators), keyed by module.
    locals: std::collections::HashMap<&'static str, Box<dyn std::any::Any>>,
}

/// Fresh heap allocations start here (well away from the DLL images).
const HEAP_START: u32 = 0x4000_0000;

impl Default for Mem {
    fn default() -> Self {
        Self::new()
    }
}

impl Mem {
    pub fn new() -> Self {
        Mem {
            images: [
                (TIBASE.base, TIBASE.bytes.to_vec()),
                (TIENG.base, TIENG.bytes.to_vec()),
                (TISPAN.base, TISPAN.bytes.to_vec()),
            ],
            heap: Vec::new(),
            next: HEAP_START,
            alloc_hints: Default::default(),
            locals: Default::default(),
        }
    }

    /// Read a module's carried "stack" state (created with `init` on first use).
    pub fn local<T: Copy + 'static>(&mut self, key: &'static str, init: T) -> T {
        *self.locals.entry(key).or_insert_with(|| Box::new(init)).downcast_ref::<T>().expect("local type")
    }

    /// Store a module's carried "stack" state.
    pub fn set_local<T: Copy + 'static>(&mut self, key: &'static str, v: T) {
        self.locals.insert(key, Box::new(v));
    }

    /// Map a block at a fixed address (used to load oracle snapshots).
    pub fn map(&mut self, base: u32, data: Vec<u8>) {
        if base == 0 || data.is_empty() {
            return;
        }
        self.heap.retain(|b| b.base != base);
        self.heap.push(Block { base, data });
    }

    /// `calloc`: a zeroed block at a fresh address.
    pub fn alloc(&mut self, len: usize) -> u32 {
        if let Some(base) = self.alloc_hints.pop_front() {
            self.heap.retain(|b| b.base != base);
            self.heap.push(Block { base, data: vec![0; len.max(1)] });
            return base;
        }
        let base = self.next;
        self.next = self.next.wrapping_add((len as u32 + 0xfff) & !0xfff).wrapping_add(0x1000);
        self.heap.push(Block { base, data: vec![0; len.max(1)] });
        base
    }

    pub fn free(&mut self, addr: u32) {
        self.heap.retain(|b| b.base != addr);
    }

    /// The whole block starting at `addr` (for comparisons and dumps).
    pub fn block(&self, addr: u32) -> Option<&[u8]> {
        self.heap.iter().find(|b| b.base == addr).map(|b| b.data.as_slice())
    }

    #[inline]
    fn locate(&self, addr: u32, len: usize) -> (&[u8], usize) {
        for (base, img) in &self.images {
            if addr >= *base && ((addr - base) as usize) + len <= img.len() {
                return (img, (addr - base) as usize);
            }
        }
        for b in &self.heap {
            if addr >= b.base && ((addr - b.base) as usize) + len <= b.data.len() {
                return (&b.data, (addr - b.base) as usize);
            }
        }
        panic!("read of {len} bytes at unmapped address {addr:#010x}");
    }

    #[inline]
    fn locate_mut(&mut self, addr: u32, len: usize) -> (&mut [u8], usize) {
        for (base, img) in &mut self.images {
            if addr >= *base && ((addr - *base) as usize) + len <= img.len() {
                return (img, (addr - *base) as usize);
            }
        }
        for b in &mut self.heap {
            if addr >= b.base && ((addr - b.base) as usize) + len <= b.data.len() {
                return (&mut b.data, (addr - b.base) as usize);
            }
        }
        panic!("write of {len} bytes at unmapped address {addr:#010x}");
    }

    pub fn bytes(&self, addr: u32, len: usize) -> &[u8] {
        let (d, o) = self.locate(addr, len);
        &d[o..o + len]
    }
    pub fn bytes_mut(&mut self, addr: u32, len: usize) -> &mut [u8] {
        let (d, o) = self.locate_mut(addr, len);
        &mut d[o..o + len]
    }

    #[inline]
    pub fn u8(&self, a: u32) -> u8 {
        self.bytes(a, 1)[0]
    }
    #[inline]
    pub fn i8(&self, a: u32) -> i8 {
        self.u8(a) as i8
    }
    #[inline]
    pub fn u16(&self, a: u32) -> u16 {
        let b = self.bytes(a, 2);
        u16::from_le_bytes([b[0], b[1]])
    }
    #[inline]
    pub fn i16(&self, a: u32) -> i16 {
        self.u16(a) as i16
    }
    #[inline]
    pub fn u32(&self, a: u32) -> u32 {
        u32::from_le_bytes(self.bytes(a, 4).try_into().unwrap())
    }
    #[inline]
    pub fn i32(&self, a: u32) -> i32 {
        self.u32(a) as i32
    }
    #[inline]
    pub fn set_u8(&mut self, a: u32, v: u8) {
        self.bytes_mut(a, 1)[0] = v;
    }
    #[inline]
    pub fn set_u16(&mut self, a: u32, v: u16) {
        self.bytes_mut(a, 2).copy_from_slice(&v.to_le_bytes());
    }
    #[inline]
    pub fn set_i16(&mut self, a: u32, v: i16) {
        self.set_u16(a, v as u16);
    }
    #[inline]
    pub fn set_u32(&mut self, a: u32, v: u32) {
        self.bytes_mut(a, 4).copy_from_slice(&v.to_le_bytes());
    }
    #[inline]
    pub fn set_i32(&mut self, a: u32, v: i32) {
        self.set_u32(a, v as u32);
    }
}
