//! Maps the original SoftVoice DLLs into flat images (sections at their
//! virtual addresses, preferred base) so the engine can read its tables by
//! address, exactly like the original code.  Nothing from the DLLs is
//! committed to the source tree; they are read at build time from
//! $SOFTVOICE_DLL_DIR (default: ../../../TalkIt relative to this crate).

use std::env;
use std::fs;
use std::path::PathBuf;

/// (file name, expected PE TimeDateStamp) of the supported 1.0.0.1117 build.
const DLLS: &[(&str, u32)] = &[
    ("tibase32", 0x328f_eadb),
    ("tieng32", 0x328f_e9ef),
    ("tispan32", 0x328f_e94a),
];

fn rd16(d: &[u8], o: usize) -> u16 {
    u16::from_le_bytes([d[o], d[o + 1]])
}
fn rd32(d: &[u8], o: usize) -> u32 {
    u32::from_le_bytes([d[o], d[o + 1], d[o + 2], d[o + 3]])
}

fn main() {
    let manifest = PathBuf::from(env::var("CARGO_MANIFEST_DIR").unwrap());
    let dir = env::var_os("SOFTVOICE_DLL_DIR")
        .map(PathBuf::from)
        .unwrap_or_else(|| manifest.join("../../../TalkIt"));
    let out = PathBuf::from(env::var("OUT_DIR").unwrap());
    println!("cargo:rerun-if-env-changed=SOFTVOICE_DLL_DIR");

    let mut code = String::new();
    for &(name, stamp) in DLLS {
        let path = dir.join(format!("{name}.dll"));
        println!("cargo:rerun-if-changed={}", path.display());
        let d = fs::read(&path).unwrap_or_else(|e| {
            panic!("cannot read {} ({e}); set SOFTVOICE_DLL_DIR to the folder with the Talk It! DLLs", path.display())
        });
        let pe = rd32(&d, 0x3c) as usize;
        assert_eq!(&d[pe..pe + 4], b"PE\0\0", "{name}: not a PE file");
        let ts = rd32(&d, pe + 8);
        assert_eq!(ts, stamp, "{name}.dll is not the supported Talk It! 1.0.0.1117 build");
        let nsec = rd16(&d, pe + 6) as usize;
        let opt = pe + 24;
        let optsz = rd16(&d, pe + 20) as usize;
        let base = rd32(&d, opt + 28);
        let size_of_image = rd32(&d, opt + 56) as usize;
        let size_of_headers = rd32(&d, opt + 60) as usize;

        let mut img = vec![0u8; size_of_image];
        img[..size_of_headers].copy_from_slice(&d[..size_of_headers]);
        for i in 0..nsec {
            let s = opt + optsz + i * 40;
            let vsize = rd32(&d, s + 8) as usize;
            let va = rd32(&d, s + 12) as usize;
            let rsize = rd32(&d, s + 16) as usize;
            let raw = rd32(&d, s + 20) as usize;
            let n = rsize.min(vsize.max(rsize)).min(size_of_image - va);
            img[va..va + n].copy_from_slice(&d[raw..raw + n]);
        }
        fs::write(out.join(format!("{name}.img")), &img).unwrap();
        let upper = name.trim_end_matches("32").to_uppercase();
        code += &format!(
            "/// {name}.dll mapped at its preferred base.\npub static {upper}: Image = Image {{ base: {base:#x}, bytes: include_bytes!(concat!(env!(\"OUT_DIR\"), \"/{name}.img\")) }};\n"
        );
    }
    fs::write(out.join("images.rs"), code).unwrap();
}
