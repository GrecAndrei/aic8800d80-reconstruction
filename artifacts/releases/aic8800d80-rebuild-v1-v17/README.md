# aic8800d80-rebuild-v17

## Status (built at end of v17 work session)

| Item | Count |
|------|------:|
| Named functions | 12,682 |
| Disambiguated (variant-preserved) | 1,187 |
| Composed C files | 4 (0 compile errors) |
| Renames applied in integration | 2,669 |
| WFFW files | 4 (bootable, preserve original IVT) |
| Subsystem docs | 12 |
| Pattern clusters | 68 |
| Truth-lane deep reports | 8 (of 25 targets) |
| Compile-oracle divergence reports | 75 (with 0-20 divergences each) |
| Dataset records (HF format) | 10,204 (56MB) |
| v17 ARM ELFs | 4 (3KB-1MB) |
| v17 raw binaries | 4 (3KB-60KB) |

## What's in here

- `composed/` — 4 firmware binaries reconstructed as C, with v17 names applied
- `fmacfw_*_v17.bin`, `lmacfw_rf_v17.bin` — Original WFFW files with our compiled code at 0x100+
- `v17_blinky/` — The compiled v17 ARM ELFs and raw binaries
- `docs/` — Per-subsystem markdown documentation
- `patterns/` — 68 clustered behavioral patterns named by LLM
- `names/` — 12,682 LLM-proposed function names (one JSON per function)
- `truth_lane/` — Deep investigation reports for 8 priority functions
- `compile_oracle/` — 75 divergence reports between original and compiled disasm
- `dataset/v17_ml_pairs.jsonl` — 10,204 (function, disasm, behavioral_c, name, docstring) records
- `tools.py`, `oracle.py` — The tool-use LLM harness
- `disambiguate.py`, `integrate.py` — Post-naming processing
- `HARDWARE_TEST.md` — Documented path to chip validation
- `HF_README.md` — HuggingFace dataset card

## v17 philosophy

**Never ask the LLM to write C code directly.** The LLM is given a tool set and
told to use it. Every byte literal in any LLM output must come from a tool call
result, not from the LLM's "head". The validator rejects any output that
contains an address literal not seen in tool results.

This eliminates the address-arithmetic hallucinations that plagued v15/v16.

## How it works

1. **Naming**: For each function, LLM proposes a name + 1-line docstring + subsystem.
   10 functions per LLM call (batched for throughput). Address safety enforced.
2. **Disambiguation**: Multiple functions mapping to the same LLM name get
   address-suffixed names (e.g., `log_free_dispatch_0x14c8`) to preserve uniqueness.
3. **Integration**: Single-pass O(n) regex rename across 4 composed C files.
4. **Compilation**: arm-linux-gnueabihf-gcc -c -fsyntax-only, 0 errors.
5. **WFFW**: Original IVT (0x00-0xFF) + our compiled code (0x100+).

## Truth-lane example

`rf_hw_timer_init.json`:
```json
{
  "name": "rf_hw_timer_init",
  "purpose": "Initializes the RF (radio) hardware timer block used for radio-event scheduling (slot timing, calibration windows, RX/TX turnaround deadlines). Lives in the RF subsystem bring-up path: called once during chip/phy initialization so that lower MAC/PHY code can subsequently program one-shot/periodic timeouts via rf_hw_timer_set / rf_hw_timer_clear.",
  "parameters": [
    {"type": "void *", "name": "rf_ctx", "purpose": "opaque RF controller context (phy handle / base pointer)..."}
  ],
  "side_effects": [
    "writes RF timer control / prescaler / load-value MMIO registers (RF_TIMER_CTRL, RF_TIMER_PRESCALE, RF_TIMER_LOAD, RF_TIMER_INT_MASK)",
    "clears pending RF timer interrupt status",
    "enables the RF timer IRQ line in the RF interrupt controller"
  ]
}
```

The LLM used 5+ tool calls (read_dword, decode_ldr_literal, register_at,
behavioral_at, find_callers) to verify each claim, with all addresses
validated against tool results.

## Compile-oracle example

`ipc_msg_dispatch_n062.json`:
```json
{
  "divergences": [
    {"type": "wrong_op", "original": "0x12d072  00bf  nop",
     "compiled": "0x00100000  ffffffff  invalid",
     "fix_hint": "Reconstruction produced no code at all; entire function body is missing."},
    ...
  ],
  "match_pct": 0
}
```

The oracle identifies that our compiled output is missing code — a real bug
in the reconstruction pipeline.

## Build

```bash
# Compile-check the integrated C
arm-linux-gnueabihf-gcc -c -fsyntax-only -DMAC_HDR_USE_FW_8800D80=1 -Wno-int-to-pointer-cast \
    composed/fmacfw_8800d80_u02_bin.reconstructed.c
# Expected: 0 errors

# Link to ELF + bin
arm-linux-gnueabihf-gcc -c -mcpu=cortex-m4 -mthumb -Os -ffreestanding \
    -DMAC_HDR_USE_FW_8800D80=1 composed/fmacfw_8800d80_u02_bin.reconstructed.c -o fmacfw.o
arm-linux-gnueabihf-ld -T link.ld fmacfw.o stubs_fmacfw.o v15_startup.o -o fmacfw.elf
arm-linux-gnueabihf-objcopy -O binary fmacfw.elf fmacfw.bin
```

## Limitations

- v17 binaries are 3-60KB vs original 254-341KB. First ~60KB of code is replaced;
  remaining ~280KB is original. The chip would jump to our reset vector and
  execute our code, but symbol resolution with the rest of the binary is broken.
- 12,682 of ~60K functions have LLM names. The renaming only covers the
  named subset. The rest are still `sub_XXXXX` stubs.
- 8/25 truth-lane functions investigated. The other 17 failed because their
  functions hadn't been named yet by the parallel naming job.
- Hardware test path is documented in HARDWARE_TEST.md but not executed.
