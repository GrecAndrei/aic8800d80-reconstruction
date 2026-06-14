# Rebuild Milestone (2026-06-14)

## What This Repo Delivers

This repository reconstructs readable, auditable firmware logic from
stripped **AIC8800D80 WiFi/BT firmware** blobs (Marvell 88W8800-derived).

The rebuild path is **evidence-driven**:

- IDA Pro 9.3 exports provide grounded structural facts (function
  boundaries, calls, MMIO accesses)
- IDA Hex-Rays produces human-readable pseudo-C
- 16 deterministic LLM tools apply semantic names (LLM never writes C
  bodies; it only calls tools that mechanically generate code)
- 4 progressively better reconstruction layers (v15–v19) serve
  different verification needs

## v19 Headline Result (latest release)

**4,675 of 4,723 firmware functions decompiled (98.9%)** using IDA's
Hex-Rays decompiler, producing real C with proper control flow,
parameters, and local variables.

| Binary | Total | Decompiled | LLM-named | Time |
|--------|-------|------------|-----------|------|
| fmacfw_8800d80_h_u02 | 1,285 | 1,272 (99.0%) | 2 | 51s |
| fmacfw_8800d80_u02 | 1,286 | 1,273 (99.0%) | **462** | 83s |
| fmacfwbt_8800d80_u02 | 1,286 | 1,274 (99.1%) | **468** | 77s |
| lmacfw_rf_8800d80_u02 | 866 | 856 (98.8%) | **324** | 36s |
| **Total** | **4,723** | **4,675 (98.9%)** | **1,256** | **~4 min** |

Plus **25,815 MMIO register addresses** named automatically
(`REG_4024_0148`, `REG_4032_2000`, ...).

## Four release layers (v15 → v19)

### v15 — Synthesis baseline
Curated 356 functions of compilable C, all passing 25/25 truth lane
tests (byte-for-byte match against original firmware).

### v17 — LLM tool-use pipeline
- 16 deterministic tools, LLM as naming oracle only
- 5,741 function names applied successfully
- 4,002 functions in the release, all compilable
- 5.7 MB tarball

### v18 — Byte-faithful inline-asm
- 18,841 functions, 0% LLM hallucination
- Original ARM Thumb bytes embedded as `.byte 0xXX` directives
- **89% at 100% byte-match in compile-oracle**, 94.1% average
- Trade-off: human-unreadable C
- 1.2 MB tarball

### v19 — Hex-Rays decompilation (latest)
- 4,675 functions decompiled to real pseudo-C
- 1,256 LLM-named functions
- 25,815 MMIO names
- ~30 seconds per binary
- 4.7 MB tarball with 5,945 per-function files

## Why four layers?

Each layer trades off different properties:

| Need | Best layer |
|------|-----------|
| Compilable C with semantic meaning | v15, v17 |
| Byte-faithful to original | v18 |
| Human-readable to study | **v19** |
| ML training data (10K+ records) | v17 dataset |
| Hardware test boot | v18 (with IVT fix) |

## Pipeline

```
IDA Pro 9.3
   |
   v
ELF wrapper (loads at 0x100000)
   |
   v
IDB setup (LOAD=RWX, BSS sparse, MMIO phantom)
   |
   v
Apply LLM names + MMIO names
   |
   v
Hex-Rays decompile
   |
   v
Per-function .c files
   |
   v
Composed .c per binary
   |
   v
Release tarball
```

## Critical infrastructure

- **v14 BASE = 0x1200000** (v14 address space)
- **chip runtime = v14 - 0x1100000**
- **chip runtime BASE = 0x100000** (where firmware loads)
- **v18 disasm** via `r2 -q -2 -c "e asm.arch=arm; e asm.bits=16; pd N @ ADDR"`
- **v19 ELF wrapper**: minimal ARM ELF with one LOAD segment at 0x100000
- **MMIO phantom segment**: 0x40000000-0x60000000, 25,815 register addresses
- **IDA Pro 9.3** at `$IDAT (or default $HOME/ida-pro-9.3/idat)`
- **Hex-Rays** decompiler plugin `hexarm.so`
- **LLM API**: 6 keys round-robin at `https://api.tokenrouter.com/v1`,
  model `MiniMax-M3`, 1M context

## What's NOT in this repo (gaps)

- ❌ Hardware verification (waiting for user to test on actual chip)
- ❌ Drive upload (gws token expired, manual login needed)
- ❌ Cross-binary function mapping (v17 dataset has it, not surfaced in v19)
- ❌ Per-function call graphs (v18 has them, not used in v19)
- ❌ Type library (struct definitions for vif_info, tx_queue, etc.
  — these are hardcoded in `harness_v17/tools.py` but not applied to IDA)

## How to extend to v20+

Potential improvements for the next iteration:
- Apply struct field annotations to improve type inference
- Cross-reference v18 (byte-faithful) and v19 (decompiled) per function
- Add static type analysis to fix Hex-Rays type bugs
- Use v17's behavioral traces to validate decompiled control flow
- Add hardware fuzzing harness for verification
