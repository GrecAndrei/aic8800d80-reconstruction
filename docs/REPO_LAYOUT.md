# Repo Layout

This document describes what each top-level directory is for, and what
should or should not be committed.

## Top-level

| Dir | Purpose | Git? |
|-----|---------|------|
| `inputs/` | Source firmware blobs and related inputs (4 .bin files) | ✅ |
| `metadata/` | Stable per-image reconstruction descriptors | ✅ |
| `extracted_kernel/` | Historical kernel extraction notes | ✅ |
| `artifacts/` | Tracked published release snapshots | ✅ (curated) |
| `bin/` | Compiled Go binaries (built from `cmd/`) | ✅ |
| `extraction_out/` | Generated working outputs for current runs | ❌ (gitignored) |
| `analysis/` | Local scratch, wrapper state, ad hoc analysis | ❌ (gitignored) |
| `tmp/` | Per-session scratch space | ❌ (gitignored) |

## Harness directories

| Dir | Layer | Purpose | Git? |
|-----|-------|---------|------|
| `harness_v15/` | v15 | Synthesis baseline (Unicorn-driven body capture) | ✅ source only |
| `harness_v16/` | v16 | Failed LLM-C approach (kept for reference) | ✅ source, ❌ out/ (177MB reviews) |
| `harness_v17/` | v17 | LLM tool-use pipeline (16 tools, naming, integration) | ✅ source only |
| `harness_v19/` | v19 | Hex-Rays decompilation pipeline | ✅ source only |
| `harness_v20/` | v20 | Struct discovery (access patterns, Python/r2) | ✅ tracked outputs, **historical** |
| `harness_v21/` | v21 | Struct cross-reference | ✅ tracked outputs, **historical** |
| `harness_v22/` | v22 | Expanded struct names | ✅ tracked outputs, **historical** |
| `harness_v23/` | v23 | Annotated v19 C + field invariants | ✅ tracked outputs, **historical** |
| `harness_v24/` | v24 | Cross-binary function map | ✅ tracked outputs, **historical** |
| `harness_v25/` | v25 | Unified structure analysis (Go `fwstruct`) | ❌ out/ (gitignored) |

Within each harness:
- `scripts/`, `docs/`, `tools.py`, etc.: ✅ commit
- `idb/`, `log/`, `decompiled/`, `names/`, `out/`: ❌ gitignored (large)

## v20-v24: Historical Python struct recovery

These five harnesses form a single struct-recovery pipeline that
builds on v19's decompiled C output. Each one feeds the next:

```
v19 decompiled C
   ↓
v20  access patterns (r2 disasm) → structs → clusters
v21  cross-reference (which funcs touch which fields)
v22  expanded struct names (LLM proposes more)
v23  annotated C (prepend struct context to each function)
v24  cross-binary map (functions shared across the 4 binaries)
```

Unlike v15-v19, v20-v24's generated output dirs (`access_patterns/`,
`structs/`, `field_map/`, `annotated/`, `*.json`) are **committed**
to git — they are the canonical historical artifacts of each pipeline
stage and re-running the scripts reproduces them deterministically.

**Note:** The Go-based `fwstruct` tool (v25) supersedes v20-v24. New
analysis should use `bin/fwstruct` instead. The Python harnesses remain
in the tree for cross-validation and historical reference.

## Bin directory

Compiled Go binaries live in `bin/` (the Go idiom). They are built
from sources in `cmd/` and force-tracked with `git add -f`. The
following binaries are tracked:

- `fwapplysynth`, `fwcompact`, `fwcompose`, `fwcycle`, `fwfinalize`,
  `fwharden`, `fwimplsynth`, `fwstruct`

Tools that invoke binaries by path use `$REPO/bin/<binary>` (see
`tools/overnight_behavioral.sh` and `tools/score_truth_lane.py` for
examples).

## Historical workflow guide

The lowercase `agents.md` (smoke-cycle / `fwextract` era, v15-v18)
has been renamed to `docs/WORKFLOW_LEGACY.md`. AGENTS.md is the
current pipeline-oriented guide (v15-v25).

## Release artifacts

```
artifacts/releases/
├── README.md                                # artifact policy
├── aic8800d80-rebuild-v1/                   # v17 synthesized C working dir
├── aic8800d80-rebuild-v1-v15/               # v15 release
├── aic8800d80-rebuild-v1-v15.tar.gz         # 1.1 MB
├── aic8800d80-rebuild-v1-v17/               # v17 release
├── aic8800d80-rebuild-v1-v17.tar.gz         # 5.7 MB
├── aic8800d80-rebuild-v1-v18/               # v18 release
├── aic8800d80-rebuild-v1-v18.tar.gz         # 1.2 MB
├── aic8800d80-rebuild-v1-v19/               # v19 release ★
└── aic8800d80-rebuild-v1-v19.tar.gz         # 4.7 MB
```

Each release dir contains:
- `README.md`: layer-specific overview
- `composed_<version>/`: all functions concatenated per binary (.c)
- `decompiled/` (v19 only): per-function .c files + `_decompile_log.json`
- `docs/ORACLE_RESULTS.md`: quality report
- `named_samples/` (v19): curated LLM-named function samples
- `elf/` (v19): ARM Thumb ELF wrappers around raw .bin
- `wffw_*/` (v17, v18): Wearable Firmware Format binaries

## What NOT to commit

1. **IDA databases** (`*.i64`, `*.id0`, `*.id1`, etc.) — 2.1 GB each,
   reproducible from `.elf` + scripts
2. **Raw firmware** (`*.bin`) — 340 KB each, in `inputs/` but gitignored
   for release size
3. **Extraction outputs** (`extraction_out/`) — generated
4. **Logs** — `harness_v*/log/`, root `*.log`
5. **IDB files** — `harness_v*/idb/`
6. **Per-function decompiled .c** — too many small files
   (5,945 in v19/decompiled/, all in tarball)
7. **Python bytecode** — `__pycache__/`, `*.pyc`
8. **Editor state** — `*.swp`, `.DS_Store`
9. **Local tools state** — `.antigravitycli/`, `.commandcode/`
10. **tmp/ scratch space**

## What SHOULD be committed

1. **Source code** for all harnesses (`harness_v*/scripts/`, `*.py`, `*.sh`)
2. **Pipeline metadata** (`harness_v19/structs.json`,
   `mmio_registers.json`)
3. **Composed C source** (final outputs)
4. **Release directories** (curated)
5. **Release tarballs** (force-add with `git add -f *.tar.gz`)
6. **Documentation** (`*.md`)
7. **Tools** (Python helpers in `tools/`)
8. **Inputs metadata** (firmware descriptions, but not the .bin)

## IDB Database Convention

IDA Pro 9.3 databases are stored as a single `.i64` file. To save
disk space and avoid committing 2GB+ files:

- IDBs go in `harness_v*/idb/<image>.i64`
- IDBs are not committed (gitignored)
- IDBs are reproducible: rerun the setup script

For IDB-related scratch (auto-save, temp files):
- `*.id0`, `*.id1`, `*.id2`, `*.nam`, `*.til` are gitignored
