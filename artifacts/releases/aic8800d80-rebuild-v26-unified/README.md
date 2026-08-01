# v26 Unified — AIC8800D80 firmware reconstruction

One pipeline output: `src/` (4 images, real Hex-Rays bodies + materialized
data segment) + the LLM naming dataset (`names/`, 23,498 entries, 0 unnamed).

## Contents
- `src/<image>/main.c` — composed firmware C, one real body per function
- `src/<image>/functions/` — 5,623 per-function sources
- `src/<image>/data.c` — materialized data segment (flt/dbl via static union)
- `src/include/` — shared headers (aic8800d80_types.h, mmio, structs)
- `names/` — {fn}__{img}.json naming records (DeepSeek V4 Flash, status=ok)

## Verification
- `make -C src check`: all 4 images compile clean (arm-none-eabi-gcc,
  cortex-m4, -fsyntax-only)
- `tools/truth_lane_smoke.py --src`: behavioral gate 25/25 PASS
  (bodies compile, run under unicorn, natural return, MMIO traffic)
