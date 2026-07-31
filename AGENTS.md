# AGENTS.md — Quick Reference for AI Agents

## Project goal
Reconstruct human-readable C source from the AIC8800D80 WiFi/BT firmware
binaries (4 × ~340KB ARM Thumb images, Marvell 88W8800-derived, loaded at
0x100000), with byte-level ground truth always anchored to the binaries.

## Current series: Unified (replaces v15–v26)

The old "v-series" (v15, v17, v18, v19, v20–v25, v26) is legacy. Do not
build new layers on it. The unified series is ONE pipeline:

```
inputs/firmware/*.bin
   │  [deterministic] fwstruct extract + Hex-Rays decompile (v19 machinery)
   ▼
decompiled C per function
   │  [deterministic] fwstruct datasgen  → data segment materialized
   │  [deterministic] fwstruct compose   → src/<image>/main.c (real bodies only)
   │  [LLM oracle]    naming_src.py      → names for sub_* functions
   ▼
src/  (single output: per-function files + composed main.c + headers)
   │  [deterministic] emulation verify   → per-function behavioral gate
   ▼
release tarball
```

- **One tool**: `fwstruct` (Go, `cmd/fwstruct/`, build: `go build -o bin/fwstruct ./cmd/fwstruct`)
- **One output**: `src/` — 5,623 per-function files under `src/<image>/functions/`,
  composed `src/<image>/main.c`, shared headers in `src/include/`
- **One naming dataset**: `harness_v17/names/{fn}__{img}.json` (shared cache,
  skip-if-exists; legacy harness_v17 code is reused as a library, not extended)
- Legacy harness dirs (harness_v15 … v26) stay in the tree as frozen
  references; their outputs remain valid evidence.

## Current status (2026-07-31)

- **Naming revival**: pipeline now calls DeepSeek V4 Flash
  (`https://opencode.ai/zen/go/v1/chat/completions`, model `deepseek-v4-flash`,
  single key in `harness_v15/keys/keys.json` — untracked, do NOT commit).
  Naming run in progress for ~4,400 anonymous `sub_*` functions in `src/`.
- **In flight**: data segment materialization (`fwstruct datasgen`), real-body
  compose into `main.c` (`fwstruct compose`), removal of empty stubs.
- **Known gap (being fixed)**: `src/<image>/main.c` currently contains
  ~44K empty `void foo(void) { // TODO: integrate control/data flow. }` stubs;
  the real bodies live in `src/<image>/functions/`. Data globals are declared
  `extern` but never defined — nothing links until `datasgen` runs.

## Hard rules (do not violate)

1. **THINK IN TAGS, NOT BASH COMMANDS**: never use bash as scratch.
2. **LLM cost is NOT a constraint**: never halt execution early for token
   budget; never set max_tokens caps. Reasoning models need full output.
3. **Address-safety rule is absolute**: LLM may NOT compute any address,
   offset, pointer, or size in its head. Provide tools.
4. **LLM is NEVER a C author** — only tool user / naming oracle. All C is
   mechanically generated (v17+), decompiled (Hex-Rays), or emitted by
   fwstruct transforms.
5. **No artificial limits**: no max_tokens cap, no iteration cap, no
   batch-size capping for correctness.
6. **O(n) is mandatory**: never O(n*m) text splices in loops on multi-MB files.
7. **Long-running commands detached**: `setsid nohup ... > log 2>&1 &`,
   then poll the log in short sleeps. Never `wait` on a nohup'd process.
   Bash tool has 120s timeout.
8. **No synthetic/template bodies**; demand real semantic fidelity.
9. **Bugs are blocking**: fix integration bugs first, then continue.
10. **Frequent Commits**: commit after every meaningful change.
11. **Do not modify generated files manually**; fixes via real rebuild.
12. **Dual-track (A + B)**: hardware test path + cloud release path.
13. **Task Completion**: execute to full completion; verify mechanically.
14. **Use Hex-Rays decompiler** (`$IDAT` or `$HOME/ida-pro-9.3/idat`) for
    human-readable C. Hex-Rays output is cached — re-decompile or use
    `idaapi.decompile(ea, flags=idaapi.DECOMP_NO_CACHE)`.
15. **Use `bin/fwstruct`** for all structure/metadata work.
16. **Do not commit `harness_v15/keys/`** — API keys are untracked.

## LLM configuration (DeepSeek V4 Flash only)

- Provider: opencode.ai Zen gateway
- Endpoint: `https://opencode.ai/zen/go/v1/chat/completions`
- Model: `deepseek-v4-flash`
- Key: `harness_v15/keys/keys.json` → `providers[0].api_key` (untracked file)
- **REQUIRED header**: `User-Agent: opencode/1.0` — without it the gateway
  returns 403 (Cloudflare bot check). Both Python (oracle.py) and Go
  (internal/llm) clients already send it.
- `deepseek-v4-flash` is a reasoning model: it spends most output on
  reasoning tokens. NEVER set `max_tokens` (it starves the answer).
- Python call path: `harness_v17/oracle.py::call_api` (reads key file,
  builds endpoint from `base_url` + `/chat/completions`).
- Go call path: `internal/llm.Client` (defaults match the same endpoint).
- Go keys: `AIC8800D80_LLM_KEY_<N>` env vars or `--llm-key-dir`.

## Pipeline commands

```bash
# Build the one tool
go build -o bin/fwstruct ./cmd/fwstruct

# Deterministic structure + metadata (no LLM)
bin/fwstruct scan | callgraph | structs | magic | initpath | diff | types | ivt | annotate | xref | report

# LLM naming (uses DeepSeek, keys from harness_v15/keys/keys.json)
python3 harness_v17/naming_src.py            # name anonymous sub_* funcs in src/
bin/fwstruct names                           # name struct clusters
python3 harness_v17/naming.py                # legacy full-function naming driver

# Decompile pipeline (Hex-Rays, per image)
harness_v19/scripts/run_v19.sh <image> both   # image names: fmacfw_8800d80_*_u02_bin etc.

# Truth-lane behavioral verification
python3 tools/truth_lane_smoke.py --final-dir extraction_out/reconstruction/mega7/final --out /tmp/opencode/truth_lane_smoke
```

## Address conversion cheat sheet

```
v14 BASE           = 0x1200000
chip runtime BASE  = 0x100000
file_offset = 0x100000 → chip addr 0x100000
chip addr = v14 addr - 0x1100000
```

## IDA Pro setup for AIC8800D80

The firmware loads as ARM Thumb at `0x100000`. To get IDA to recognize it:

1. Wrap the raw `.bin` as a minimal ARM ELF (one LOAD segment at 0x100000)
   - See `harness_v19/scripts/make_elf.py`
2. Load via `idat -A -B -L<log> -S<setup_script> -o<idb> <elf>`
3. Setup script must:
   - Set LOAD perm to RWX (default is RX, blocks data symbol naming)
   - Extend LOAD to 0x200000 with SEGMOD_SPARSE (BSS coverage)
   - Add MMIO phantom segment at 0x40000000-0x60000000
4. Apply LLM names via `ida_name.set_name(addr, name, ida_name.SN_FORCE)`
5. BSS addresses need `ida_bytes.create_data()` BEFORE `set_name()`
6. Decompile with `idaapi.decompile(ea)`

## r2 thumb disasm command

```bash
r2 -q -2 -c "e asm.arch=arm; e asm.bits=16; pd N @ ADDR" inputs/firmware/<file>.bin
```

DOES NOT work: `-a arm -b 16` (byte-granular), `-a thumb` (wrong at fn start),
`-m 0x100000` (offsets wrong on raw .bin).
Note: `harness_v17/tools.py::disasm_at` uses the `-a arm -b 16 -m 0x100000`
form; it is empirically working for the naming pipeline — do not "fix" it.

## AIC8800D80 firmware specs

- 4 binaries, ~340KB each; loads at 0x100000
- 4,723 total functions across 4 images (v19 boundaries)
- 5,945 function instances analyzed by v25 scan; 5,623 in src/ functions/
- 25,815 unique MMIO addresses; 1,042 distinct 64KB pages

## IDA quirks discovered

- `idc.get_db_name` doesn't exist in 9.x — use `idaapi.get_input_file_path()`
- `idc.SN_FORCE` is in `ida_name.SN_FORCE`
- `set_segm_attributes` is gone — use `seg.perm = ...` directly
- Hex-Rays output is **cached** — changes to symbols require re-decompile
  or `idaapi.decompile(ea, flags=idaapi.DECOMP_NO_CACHE)`
- Hex-Rays uses MSVC types (`__int64`, `_DWORD`, `_BYTE`), `_R0.._R15`
  registers, `_CF/_ZF/_NF/_OF` flags

## Disk space

- /tmp is 7.5GB tmpfs — keep IDB usage low
- IDBs are 2.1GB each (MMIO phantom segment) — store in `harness_v19/idb/`
  (gitignored), never in git
- Release tarballs < 10MB; safe for git

## Critical gitignore entries

- `*.i64`, `*.id0`, `*.id1`, `*.id2`, `*.nam`, `*.til` (IDA databases)
- `*.bin` (raw firmware), `*.o` (build artifacts — do not add back)
- `*.gz`, `*.tar.gz` (added with -f for releases)
- `harness_v15/keys/` (API keys — never commit)
- `harness_v19/decompiled/`, `harness_v19/idb/`, `harness_v19/log/`
- `extraction_out/`, `analysis/`

## Where to start

- Unified series status: this file; docs for the pipeline: `PIPELINE.md`
- fwstruct subcommands: `bin/fwstruct` (or `cmd/fwstruct/main.go`)
- src tree: `src/README.md`, `src/Makefile` (`make -C src check`)
- Legacy v19 machinery (still the decompile engine): `harness_v19/README.md`
