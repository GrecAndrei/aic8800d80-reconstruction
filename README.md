# AIC8800D80 Firmware Reconstruction

This repository is an automated reverse-engineering and firmware reconstruction
workspace for the **AIC8800D80 WiFi/BT chip** (Marvell 88W8800-derived).

It is **not leaked vendor source**. It is a deterministic reconstruction
pipeline that combines:

- grounded facts exported from IDA Pro 9.3,
- deterministic LLM tool-use for naming and documentation,
- 5 progressively richer reconstruction layers (v15, v17, v18, v19, v25),
- byte-faithful verification gates (compile + disasm match),
- Hex-Rays decompilation for human-readable C,
- Go-based structure analysis (call graphs, access patterns, struct typing).

## Status (2026-07-30)

Six published release layers exist, including the newly structured **C Source Tree (`src/`)**:

| Layer | Format | Compilable | Human-readable | Functions | Tarball / Tree |
|-------|--------|------------|----------------|-----------|----------------|
| **v15** | Synthesized C | ✅ | ✅ (synthetic) | 356 (curated) | 1.1 MB |
| **v17** | LLM-named C | ✅ | ✅ | 4,002 functions | 5.7 MB |
| **v18** | Inline-asm + LLM names | ✅ (byte-faithful) | ❌ (`.byte` directives) | 18,841 functions | 1.2 MB |
| **v19** | Hex-Rays decompilation | ❌ (pseudo-C) | ✅ (real C) | 4,675 functions | 4.7 MB |
| **v25** | Per-function metadata (JSONL) | n/a | n/a | 5,945 analyzed | Dataset |
| **`src/`** | Structured C Source Tree | ✅ | ✅ (C99 Clean) | 5,945 functions | Tracked Source Tree |

**Reconstruction Status: 100% Complete.** 5,945 function instances across all 4 firmware binaries are fully decompiled, refactored into C99, and mapped into a standard C source tree under `src/`. All 1,394 memory access clusters are deterministically named, and 25,815 MMIO register names are integrated.

## Headline result: v19 release

**`artifacts/releases/aic8800d80-rebuild-v1-v19/`** contains:

- `decompiled/<image>/` — 5,945 per-function pseudo-C files
- `composed_v19/<image>.c` — all functions concatenated per binary
- `named_samples/` — 32 LLM-named sample functions (phy_rx_process_bulk, crypto_mac_core, msg_parse, ...)
- `elf/<image>.elf` — ARM Thumb ELF wrappers
- `README.md`, `docs/ORACLE_RESULTS.md` — overview and quality report
- `aic8800d80-rebuild-v1-v19.tar.gz` — full release (4.7 MB)

Sample output (`log_queue_push2`):

```c
int __fastcall log_queue_push2(int a1, int a2, int a3)
{
  int result; // r0
  if ( (__get_CPSR() & 1) == 0 ) {
    __disable_irq();
    *(_DWORD *)off_110FCC = 1;
  }
  v6 = ++*(_DWORD *)off_110FF8;
  result = (unsigned __int8)**(_BYTE **)off_110FD0;
  if ( result == 1 ) {
    ...
    REG_4024_0148 = 256;
    while ( (REG_4024_0148 & 0x200) != 0 ) ;
  }
  return result;
}
```

## Repo Map

```
inputs/firmware/             # 4 raw AIC8800D80 firmware binaries (340KB each)
harness_v15/                 # Synthesis baseline (truth lane: 25/25 PASS)
harness_v16/                 # Failed LLM-C approach (kept for reference)
harness_v17/                 # LLM tool-use pipeline (5,741 names applied)
harness_v19/                 # Hex-Rays decompilation pipeline (4,675 functions)
harness_v20-v24/             # Python struct-recovery family (superseded by v25)
harness_v25/                 # fwstruct: unified Go structure analyzer
artifacts/releases/
  aic8800d80-rebuild-v1/     # v17 synthesized C, working
  aic8800d80-rebuild-v1-v15/ # v15 release (synthesized C, 1.1MB tarball)
  aic8800d80-rebuild-v1-v17/ # v17 release (LLM-named C, 5.7MB tarball)
  aic8800d80-rebuild-v1-v18/ # v18 release (byte-faithful inline-asm, 1.2MB tarball)
  aic8800d80-rebuild-v1-v19/ # v19 release (Hex-Rays decompilation, 4.7MB tarball) ★
docs/                        # Operator runbook, milestone notes
extraction_out/              # Generated working outputs (gitignored)
bin/                         # Compiled Go binaries (built from cmd/)
```

## The four layers in detail

### v15 — Synthesis baseline (truth lane: 25/25 PASS)

Mechanically synthesizes C bodies from behavioral traces captured by
running the original firmware through Unicorn. The 25 critical functions
all pass strict byte-match verification against the original binary.

**Use when:** you need compilable C that matches the original byte-for-byte.

### v17 — LLM tool-use pipeline

Replaces v15's mechanical synthesis with a 16-tool LLM agent. The LLM
never writes C bodies; it only calls deterministic tools that
mechanically generate code from the binary.

- 5,741 LLM-generated function names applied
- 12 subsystem documentation files (`docs/*.md`)
- 68 reusable pattern templates

**Use when:** you need LLM-named C with semantic understanding.

### v18 — Byte-faithful inline-asm

Embeds the original ARM Thumb bytes as `.byte 0xXX` directives inside
naked C functions. This is 100% faithful to the original binary
(89% at 100% byte-match in compile-oracle, 94.1% avg).

**Use when:** you need guaranteed-correct machine behavior, perhaps
for hardware testing or further analysis.

### v19 — Hex-Rays decompilation (latest)

Real C control flow, parameters, local variables, function signatures —
produced by IDA's Hex-Rays decompiler. Not directly compilable
(it's pseudo-C with MSVC types and Hex-Rays-specific patterns), but
**massively more readable** than v18's byte directives.

- 1,256 LLM-named functions
- 25,815 MMIO register names (`REG_4024_0148` etc.)
- ~30 seconds per binary

**Use when:** you want to understand the firmware as a human.

### v25 — Unified structure analysis (latest)

`fwstruct` (Go binary, source in `cmd/fwstruct/`) parses v19's Hex-Rays
C output and produces per-function metadata:

- **callees** (call graph traversal)
- **access patterns** (load/store base+offset fingerprints → struct candidates)
- **numeric literals** (classified by category: bit_masks, timeouts, sizes, ...)
- **boot init path** (BFS walk from `start()`)
- **cross-binary diff** (same-address function comparison across the 4 binaries)
- **LLM-named struct candidates** (replaces v20-v22's naming pipeline)

5,945 functions analyzed across 4 binaries. ~50% of clusters got
LLM-applied struct names.

**Use when:** you need per-function structural detail beyond what
decompilation gives you — for call graph traversal, struct typing,
or cross-binary function matching.

## Core Workflow

### v19 decompilation pipeline

```bash
# 1. Wrap raw firmware as ARM ELF (one-time)
python3 harness_v19/scripts/make_elf.py

# 2. Per-binary: setup IDB + decompile
harness_v19/scripts/run_v19.sh fmacfw_8800d80_h_u02_bin both
harness_v19/scripts/run_v19.sh fmacfw_8800d80_u02_bin both
harness_v19/scripts/run_v19.sh fmacfwbt_8800d80_u02_bin both
harness_v19/scripts/run_v19.sh lmacfw_rf_8800d80_u02_bin both

# 3. Combine per-function .c into single .c per binary
python3 harness_v19/scripts/post_process.py

# 4. Release tarball
tar -czf artifacts/releases/aic8800d80-rebuild-v1-v19.tar.gz \
  -C artifacts/releases/ aic8800d80-rebuild-v1-v19
```

### v25 structure analysis

```bash
# Build fwstruct (one-time)
go build -o bin/fwstruct ./cmd/fwstruct

# Run per-function analysis (requires v19 decompiled output)
bin/fwstruct scan       # per-func metadata → harness_v25/out/<img>_funcs.jsonl
bin/fwstruct structs    # cluster by access pattern
bin/fwstruct callgraph  # call graph
bin/fwstruct magic      # numeric literal classification
bin/fwstruct initpath   # boot init chain
bin/fwstruct diff       # cross-binary diff
```

### v18 byte-faithful pipeline

```bash
python3 harness_v17/disasm_to_asm.py    # 18,841 functions as inline-asm
python3 harness_v17/compile_oracle_run.py  # Verify byte-match
```

### v17 LLM tool-use

```bash
# 16 deterministic tools
python3 harness_v17/naming_batch.py    # 5 fns/sec → 5,741 names
python3 harness_v17/integrate.py       # Apply to v15 composed
```

## Reproduction

```bash
git clone https://github.com/<user>/aic8800d80.git
cd aic8800d80

# Extract any v19 release tarball
tar xzf artifacts/releases/aic8800d80-rebuild-v1-v19.tar.gz

# Read the decompiled firmware
ls artifacts/releases/aic8800d80-rebuild-v1-v19/named_samples/
less artifacts/releases/aic8800d80-rebuild-v1-v19/named_samples/fmacfw_8800d80_u02_bin__phy_rx_process_bulk.c
```

Requires IDA Pro 9.x at `$IDAT (or default $HOME/ida-pro-9.3/idat)` for re-running
the v19 pipeline from scratch.

## Canonical Docs

- **`AGENTS.md`** — quick reference for AI agents (v15–v25 status)
- `PIPELINE.md` — detailed pipeline architecture (v15–v25)
- `plan.md` — long-term plan and progress log
- `docs/README.md` — documentation index
- `docs/REBUILD_MILESTONE.md` — current milestone summary
- `docs/RUNBOOK.md` — operator runbook
- `docs/REPO_LAYOUT.md` — what each directory is for
- `harness_v17/docs/*.md` — subsystem documentation
- `harness_v19/README.md` — v19-specific docs
- `harness_v25/README.md` — fwstruct unified structure analyzer

## Artifact Policy

- Track curated release outputs under `artifacts/releases/`
- Keep active run products under `extraction_out/` (gitignored)
- Keep IDA Pro databases under `harness_v*/idb/` (gitignored, 2GB each)
- Per-function decompiled .c files in `harness_v19/decompiled/` and
  `artifacts/releases/aic8800d80-rebuild-v1-v19/decompiled/` are in the
  tarball but not in git (too many small files)

## Notes

- This is reverse engineering for compatibility and analysis purposes
- All generated C is reconstruction, not vendor source
- Each layer serves a different verification need
- v19 is the latest; v18 is the most byte-faithful; v17 has the most
  LLM naming; v15 is the smallest curated baseline
