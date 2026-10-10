//! Read-only access to the original DLL images by virtual address.

pub struct Image {
    pub base: u32,
    pub bytes: &'static [u8],
}

impl Image {
    #[inline]
    fn off(&self, va: u32) -> usize {
        (va - self.base) as usize
    }
    #[inline]
    pub fn u8(&self, va: u32) -> u8 {
        self.bytes[self.off(va)]
    }
    #[inline]
    pub fn u16(&self, va: u32) -> u16 {
        let o = self.off(va);
        u16::from_le_bytes([self.bytes[o], self.bytes[o + 1]])
    }
    #[inline]
    pub fn i16(&self, va: u32) -> i16 {
        self.u16(va) as i16
    }
    #[inline]
    pub fn u32(&self, va: u32) -> u32 {
        let o = self.off(va);
        u32::from_le_bytes(self.bytes[o..o + 4].try_into().unwrap())
    }
    pub fn slice(&self, va: u32, len: usize) -> &'static [u8] {
        let o = self.off(va);
        &self.bytes[o..o + len]
    }
    pub fn contains(&self, va: u32) -> bool {
        va >= self.base && ((va - self.base) as usize) < self.bytes.len()
    }
}

include!(concat!(env!("OUT_DIR"), "/images.rs"));
