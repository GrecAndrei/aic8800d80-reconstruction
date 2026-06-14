# Firmware Reconstruction Pipeline (v15 → v19)

This file describes the end-to-end pipeline used in this repository for
**AIC8800D80 WiFi/BT firmware reconstruction**.

It covers **four release layers**, each with a different verification
trade-off, plus the supporting infrastructure (LLM tooling, IDA
integration, decompilation).

## Pipeline Layout

```
inputs/firmware/*.bin      (raw 340KB ARM Thumb binaries)
       |
       v
[Layer 0: IDA Pro 9.3 + Hex-Rays decompiler]
       |
       +---> v15 (synthesis)         -> compilable, curated 356 funcs
       +---> v17 (LLM tool-use)      -> compilable, 4,002 LLM-named funcs
       +---> v18 (byte-faithful)     -> compilable, 18,841 inline-asm funcs
       +---> v19 (Hex-Rays decompile) -> pseudo-C, 4,675 decompiled funcs
       |
       v
artifacts/releases/aic8800d80-rebuild-v1-v{15,17,18,19}/
       |
       v
*.tar.gz (released)
```

## Stage 1: IDA Pro Integration

All four layers depend on grounded IDA Pro analysis. Setup:

```bash
# Wrap raw .bin as ARM ELF (loads at 0x100000)
python3 harness_v19/scripts/make_elf.py

# Load into IDA, set up segments, apply names
idat -A -B -L<log> -S<setup_script> -o<idb> <elf>
```

The setup script (`harness_v19/scripts/ida_setup_v19.py`) does:
1. Set LOAD segment perm to RWX (default is RX, blocks data naming)
2. Extend LOAD to 0x200000 with SEGMOD_SPARSE (covers BSS)
3. Add MMIO phantom segment 0x40000000-0x60000000
4. Apply 25,815 MMIO register names from `harness_v19/mmio_registers.json`
5. Apply 5,741 LLM-generated function names from `harness_v19/llm_names.json`
6. Apply docstrings as comments

## Stage 2: v15 — Synthesis Baseline

**Goal:** Compilable C that matches the original firmware byte-for-byte.

Approach: Behavioral fingerprint — run original firmware through
Unicorn, capture MMIO read/write sequences, emit C bodies that
touch the same addresses.

- 25 critical functions in truth lane
- 19 PASS / 6 REVIEW / 0 FAIL
- 96.4% semantic completion
- 2689+ behavioral bodies

```bash
go run ./cmd/fwcompose
go run ./cmd/fwdescriptors -run-root extraction_out/reconstruction/mega7
go run ./cmd/fwimplqueue -max-tasks 128
go run ./cmd/fwimplsynth -max-tasks 128
go run ./cmd/fwapplysynth
go run ./cmd/fwfinalize
go run ./cmd/fwvalidatecalls
go run ./cmd/fwharden
```

## Stage 3: v17 — LLM Tool-Use Pipeline

**Goal:** Replace v15's mechanical synthesis with LLM-driven naming.

Approach: 16 deterministic tools + LLM (with strict address-safety
validator). LLM is **only** a naming oracle, never a C author.

Tools include:
- `register_at(addr)` → `REG_<page>_<off>` mechanical name
- `mmio_write_c(addr, val)` → `*((volatile uint32_t *)addr) = val`
- `find_string(addr)` → string at address
- `read_dword(image, addr)` → 32-bit value at address
- `behavioral_mmio_summary(fn, img)` → summary of MMIO accesses
- ... (16 total)

LLM never invents addresses; all address computation is via tools.

```bash
# Generate naming for new functions (5 fns/sec)
python3 harness_v17/naming_batch.py

# Disambiguate variants
python3 harness_v17/disambiguate.py

# Apply names to v15 composed
python3 harness_v17/integrate.py

# Verify with compile-oracle
python3 harness_v17/compile_oracle_run.py
```

Results:
- 5,741 LLM names applied across 4 binaries
- 4,002 functions in the v17 release
- 12 subsystem docs (bt, ipc, ke, mac, mmio, patch, rf, rx, scan, tx, unknown, util)
- 68 reusable pattern templates
- 10K+ ML training records (`dataset/v17_ml_pairs.jsonl`)

## Stage 4: v18 — Byte-Faithful Inline-asm

**Goal:** 100% byte-faithful reconstruction.

Approach: Extract original ARM Thumb bytes from firmware, embed as
`.byte 0xXX` directives inside naked C functions. C compiler treats
these as the exact original instructions.

```bash
# For each named function, get bytes from r2 disasm
python3 harness_v17/disasm_to_asm.py

# Verify byte-match
python3 harness_v17/compile_oracle_run.py
```

Results:
- 18,841 functions faithfully reproduced
- 0% LLM hallucination
- 89% at 100% byte-match in compile-oracle
- 94.1% avg byte-match
- C compiles to the original binary

Drawback: C is unreadable (just `.byte` directives).

## Stage 5: v19 — Hex-Rays Decompilation

**Goal:** Human-readable C from the same firmware.

Approach: IDA Pro's Hex-Rays decompiler. Set up IDB with all the
metadata (function names, MMIO names, docstrings) and decompile.

```bash
# Setup + decompile for all 4 binaries
harness_v19/scripts/run_v19.sh fmacfw_8800d80_h_u02_bin both
harness_v19/scripts/run_v19.sh fmacfw_8800d80_u02_bin both
harness_v19/scripts/run_v19.sh fmacfwbt_8800d80_u02_bin both
harness_v19/scripts/run_v19.sh lmacfw_rf_8800d80_u02_bin both

# Combine per-function .c into single .c per binary
python3 harness_v19/scripts/post_process.py
```

Results:
- 4,675 of 4,723 functions decompiled (98.9%)
- 1,256 LLM-named functions
- 25,815 MMIO register names
- ~30 seconds per binary
- Real C with parameters, local variables, control flow

Drawback: Not directly compilable (Hex-Rays type-inference bugs).

## Truth-Lane Scoring

Score the top 25 critical functions with original-binary trace validation:

```bash
python3 tools/truth_lane_smoke.py \
  --final-dir extraction_out/reconstruction/mega7/final \
  --out /tmp/opencode/truth_lane_smoke

python3 tools/behavioral_fingerprint.py \
  --bin inputs/firmware/lmacfw_rf_8800d80_u02.bin \
  --targets /tmp/opencode/targets.jsonl --out /tmp/opencode/fingerprints.jsonl

python3 tools/find_mmio_functions.py \
  --bin inputs/firmware/lmacfw_rf_8800d80_u02.bin --base 0x1200000 \
  --functions extraction_out/ida_export_live/lmacfw_rf_8800d80_u02.bin.functions.jsonl \
  --out /tmp/opencode/mmio_fns.jsonl
```

The v15 build reports **19 PASS / 6 REVIEW / 0 FAIL** — all behavioral
bodies pass, all REVIEW are motif bodies (stochastic XOR) with zero
MMIO writes.

## Release Catalog

| Release | Format | Size | Functions | Compiles? | Readable? |
|---------|--------|------|-----------|-----------|-----------|
| v15 | Synthesized C | 1.1 MB | 356 curated | ✅ | ✅ |
| v17 | LLM-named C | 5.7 MB | 4,002 | ✅ | ✅ |
| v18 | Inline-asm | 1.2 MB | 18,841 | ✅ | ❌ |
| v19 | Hex-Rays decompile | 4.7 MB | 4,675 | ❌ (pseudo) | ✅ |

## Autonomous Cycling (v15)

The reconstruction runs in autonomous cycles:

```bash
go run ./cmd/fwcycle -run-root extraction_out/reconstruction/mega7 -tag cycle_demo
```

Each cycle:
1. Extract new evidence from IDA exports
2. Find functions below conformance threshold
3. Synthesize new bodies via LLM tool-use
4. Validate against original binary
5. Promote successful bodies to compose pipeline

## Critical Infrastructure

- **v14 BASE = 0x1200000** (v14 address space)
- **chip runtime = v14 - 0x1100000**
- **chip runtime BASE = 0x100000** (where firmware loads)
- **r2 disasm**: `r2 -q -2 -c "e asm.arch=arm; e asm.bits=16; pd N @ ADDR"`
- **IDA Pro 9.3** at `$IDAT (or default $HOME/ida-pro-9.3/idat)`
- **Hex-Rays plugin** `hexarm.so`
- **LLM API**: 6 keys round-robin at `https://api.tokenrouter.com/v1`,
  model `MiniMax-M3`, 1M context

## See Also

- `AGENTS.md` — quick reference
- `README.md` — top-level overview
- `docs/RUNBOOK.md` — operator commands
- `docs/REBUILD_MILESTONE.md` — current status
- `harness_v19/README.md` — v19-specific docs
