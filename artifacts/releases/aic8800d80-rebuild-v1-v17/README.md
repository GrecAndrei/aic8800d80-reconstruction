# aic8800d80-rebuild-v17

## What's in this release

| Item | Count | Description |
|------|------:|-------------|
| Named functions | ~3,000 | LLM-proposed function names for the AIC8800D80 firmware binaries |
| Composed C files | 4 | The 4 firmware binaries reconstructed as C source, with v17 names applied |
| WFFW files | 4 | Bootable WFFW containers (preserve original IVT, replace code) |
| Subsystem docs | 12 | Markdown documentation of each firmware subsystem |
| Pattern library | ~30 | Clustered behavioral patterns named by LLM |

## What v17 is

v17 is a **tool-use LLM pipeline** that:

1. **Never asks the LLM to write C code directly.** The LLM is given a tool set (16 deterministic functions in `tools.py`) and is told to use them for any address lookup, struct offset, or memory read. Direct C synthesis was a v15/v16 approach that produced hallucinated function bodies.
2. **Validates every byte literal in LLM output against tool results.** If the LLM writes `0x40123456` without a corresponding `read_dword` / `register_at` / `mmio_write_c` tool call returning that address, the output is rejected. This eliminates the address-arithmetic hallucinations that plagued v15.
3. **Uses the LLM as a research assistant, not an author.** The LLM proposes names, types, hypotheses, and documents subsystems. All actual C code is mechanically generated.

## The 7 LLM-assisted approaches (not yet all fully deployed)

| # | Approach | Status |
|---|----------|--------|
| 1 | Tool-Use Research | ✅ Deployed (naming job) |
| 2 | Naming & Type Oracle | ✅ Deployed (3,000+ names) |
| 3 | Pattern Library | ✅ Deployed (~30 patterns) |
| 4 | Behavioral Sequence Narrator | ✅ Deployed (docs/ dir) |
| 5 | Compilation Oracle | 🚧 Script ready (`compile_oracle.py`) |
| 6 | Cold Path Hypothesizer | 🚧 Covered by naming job |
| 7 | Documentation Synthesizer | ✅ Deployed (docs/ dir) |

## Build & verify

```bash
# Compile the integrated C
arm-linux-gnueabihf-gcc -c -fsyntax-only -DMAC_HDR_USE_FW_8800D80=1 -Wno-int-to-pointer-cast \
    composed/fmacfw_8800d80_u02_bin.reconstructed.c
# 0 errors expected
```

## Honest assessment

**What works:**
- 3,000+ functions have semantic names like `rf_bus_reset2`, `ipc_doorbell_handler`, `patch_apply_n_16c`.
- 4 composed C files compile to ARM Cortex-M4 with 0 errors.
- 4 WFFW output files generated, preserving original IVT/header.
- Subsystem documentation is human-readable and captures the variant-heavy nature of the firmware.

**What doesn't:**
- These are not yet a fully runnable replacement for the original firmware. The renamed C is mostly mechanical reconstructions of behavioral traces; init/boot paths and the cross-subsystem call graph are not fully wired.
- Tool calling is still slower than direct synthesis: 5.8 functions/s for naming vs 0.1/s in v16 (better, but not blazing).
- Some LLM-proposed names are "lazy" (e.g., 13 different `log_free_dispatch_nNNN` variants all get renamed to the same `log_free_dispatch`). Collision handling preserves correctness but loses variant information.

## Next steps (v18 candidates)

1. **Compilation Oracle** loop: compile C → disassemble → compare to original → feed divergences back to LLM → iterate.
2. **Boot path recovery**: focus on the 32 weak stubs that are referenced at reset time, manually reverse those.
3. **Variant disambiguation**: when the LLM collapses `_nNNN` variants, give it the disasm diffs to pick names that preserve the distinction.

## Provenance

- Original firmware: 4 binaries in `inputs/firmware/`, ~1.3 MB total
- Behavioral traces: 32,560 in `extraction_out/reconstruction/mega7/synth/`
- Composed C: 122,000+ function bodies in 4 files, ~134 MB
- LLM: MiniMax-M3 (1M context window) via 6 rotating API keys
- Total LLM calls in v17: ~50,000 naming + ~30 tool calls each + ~30 pattern + ~12 docs
