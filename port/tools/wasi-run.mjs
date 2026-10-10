// Cargo test runner for wasm32-wasip1: runs a test .wasm under Node's WASI
// with port/golden preopened as /golden.
//   CARGO_TARGET_WASM32_WASIP1_RUNNER="node tools/wasi-run.mjs" \
//     cargo test -p softvoice --release --target wasm32-wasip1
// $SOFTVOICE_GOLDEN_ONLY (comma-separated name substrings) limits the files,
// since the larger ones don't fit in 32-bit wasm memory at once.
import { readFile, readdir } from 'node:fs/promises';
import { WASI } from 'node:wasi';
import { argv, env, exit } from 'node:process';
import { fileURLToPath } from 'node:url';
import path from 'node:path';

const here = path.dirname(fileURLToPath(import.meta.url));
const golden = env.SOFTVOICE_GOLDEN_HOST || path.join(here, '..', 'golden');
const [wasmPath, ...args] = argv.slice(2);
const wasi = new WASI({
  version: 'preview1',
  args: [wasmPath, ...args],
  env: {
    SOFTVOICE_GOLDEN_DIR: '/golden',
    // Node's WASI can't list directories on Windows, so pass the names.
    SOFTVOICE_GOLDEN_FILES: (await readdir(golden).catch(() => [])).join(','),
    ...(env.SOFTVOICE_GOLDEN_ONLY ? { SOFTVOICE_GOLDEN_ONLY: env.SOFTVOICE_GOLDEN_ONLY } : {}),
    RUST_TEST_THREADS: '1',
  },
  preopens: { '/golden': golden },
  returnOnExit: true,
});
const module = await WebAssembly.compile(await readFile(wasmPath));
const instance = await WebAssembly.instantiate(module, wasi.getImportObject());
exit(wasi.start(instance));
