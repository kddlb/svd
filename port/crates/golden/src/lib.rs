//! Reader for the golden files written by `port/oracle` (format "SVGOLD1").

use std::collections::HashMap;
use std::path::{Path, PathBuf};

/// A memory block captured from the original engine.
#[derive(Clone, Debug, Default)]
pub struct Block {
    /// Address in the original process (for resolving pointers).
    pub addr: u32,
    pub data: Vec<u8>,
}

/// Engine state at one point of the pipeline for one phrase.
#[derive(Clone, Debug, Default)]
pub struct Snapshot {
    /// Pipeline stage index (see the oracle's `g_stageSites`), or None for
    /// the snapshot taken right before the sample generator.
    pub stage: Option<u32>,
    pub ctx: Block,
    pub records: Block,
    pub syllables: Block,
    pub frames: Block,
    pub commands: Block,
    /// `.data` of tibase32, tieng32, tispan32 at this point (only for some
    /// stages; empty otherwise).
    pub dll_data: Vec<Block>,
}

#[derive(Clone, Debug, Default)]
pub struct Case {
    pub meta: HashMap<String, String>,
    /// Base addresses of tibase32, tieng32, tispan32.
    pub modules: [u32; 3],
    pub ttp_result: Option<i32>,
    pub phonemes: Vec<u8>,
    /// One per phrase, right before sample generation.
    pub phrases: Vec<Snapshot>,
    /// Per-stage snapshots (only with "#stages 1").
    pub stages: Vec<Snapshot>,
    pub pcm: Vec<u8>,
    /// (SVNarrate result, SV_SYNC_DONE error, phrase count)
    pub done: Option<[u32; 3]>,
}

impl Case {
    pub fn id(&self) -> &str {
        self.meta.get("id").map(String::as_str).unwrap_or("?")
    }
    pub fn text(&self) -> &str {
        self.meta.get("text").map(String::as_str).unwrap_or("")
    }
}

fn u32_at(d: &[u8], o: usize) -> u32 {
    u32::from_le_bytes(d[o..o + 4].try_into().unwrap())
}

fn parse_snapshot(body: &[u8], stage: Option<u32>) -> Snapshot {
    let mut o = if stage.is_some() { 4 } else { 0 };
    o += 4; // context address (repeated in the first block)
    let mut blocks = Vec::new();
    for _ in 0..5 {
        let addr = u32_at(body, o);
        let len = u32_at(body, o + 4) as usize;
        o += 8;
        blocks.push(Block { addr, data: body[o..o + len].to_vec() });
        o += len;
    }
    let mut it = blocks.into_iter();
    Snapshot {
        stage,
        ctx: it.next().unwrap(),
        records: it.next().unwrap(),
        syllables: it.next().unwrap(),
        frames: it.next().unwrap(),
        commands: it.next().unwrap(),
        dll_data: Vec::new(),
    }
}

pub fn read(path: &Path) -> std::io::Result<Vec<Case>> {
    let d = std::fs::read(path)?;
    assert!(d.starts_with(b"SVGOLD1\n"), "{}: not a golden file", path.display());
    let mut cases: Vec<Case> = Vec::new();
    let mut o = 8;
    while o < d.len() {
        if o + 8 > d.len() {
            break; // truncated (file still being written)
        }
        let tag = &d[o..o + 4];
        let len = u32_at(&d, o + 4) as usize;
        if o + 8 + len > d.len() {
            break;
        }
        let body = &d[o + 8..o + 8 + len];
        o += 8 + len;
        if tag == b"CASE" {
            let mut meta = HashMap::new();
            for line in String::from_utf8_lossy(body).split('\n') {
                if let Some((k, v)) = line.split_once('=') {
                    meta.insert(k.to_string(), v.to_string());
                }
            }
            cases.push(Case { meta, ..Default::default() });
            continue;
        }
        let case = cases.last_mut().expect("chunk before CASE");
        match tag {
            b"MODS" => case.modules = [u32_at(body, 0), u32_at(body, 4), u32_at(body, 8)],
            b"TTPR" => case.ttp_result = Some(u32_at(body, 0) as i32),
            b"PHON" => case.phonemes = body.to_vec(),
            b"SNAP" => case.phrases.push(parse_snapshot(body, None)),
            b"STAG" => case.stages.push(parse_snapshot(body, Some(u32_at(body, 0)))),
            b"LDAT" => {
                let stage = u32_at(body, 0);
                let mut o = 4;
                let mut blocks = Vec::new();
                for _ in 0..3 {
                    let addr = u32_at(body, o);
                    let len = u32_at(body, o + 4) as usize;
                    o += 8;
                    blocks.push(Block { addr, data: body[o..o + len].to_vec() });
                    o += len;
                }
                if let Some(snap) = case.stages.iter_mut().rev().find(|s| s.stage == Some(stage)) {
                    snap.dll_data = blocks;
                }
            }
            b"PCM_" => case.pcm = body.to_vec(),
            b"DONE" => case.done = Some([u32_at(body, 0), u32_at(body, 4), u32_at(body, 8)]),
            _ => panic!("unknown chunk {:?}", String::from_utf8_lossy(tag)),
        }
    }
    Ok(cases)
}

/// `port/golden`, relative to a crate manifest directory two levels down.
pub fn dir() -> PathBuf {
    PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("../../golden")
}

/// All golden files present (sorted), so tests run on whatever was generated.
pub fn files() -> Vec<PathBuf> {
    let mut v: Vec<_> = std::fs::read_dir(dir())
        .map(|rd| rd.filter_map(|e| e.ok().map(|e| e.path())).filter(|p| p.extension().is_some_and(|x| x == "svg")).collect())
        .unwrap_or_default();
    v.sort();
    v
}

/// True (after printing a note) when there is no golden file whose name
/// satisfies `pred`, so tests can skip instead of failing on a fresh clone.
/// The golden data is generated with the oracle; see the README.
pub fn missing(pred: impl Fn(&str) -> bool) -> bool {
    let found = files().iter().any(|p| pred(&p.file_name().unwrap().to_string_lossy()));
    if !found {
        eprintln!(
            "skipping: no golden data in {} (generate it with port/oracle, see README)",
            dir().display()
        );
    }
    !found
}
