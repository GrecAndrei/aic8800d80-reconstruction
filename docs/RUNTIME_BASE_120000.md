# Runtime base is 0x120000 (not 0x100000)

**Finding date:** 2026-08-02

The AIC8800D80 SoC loads each WFFW firmware image at **0x120000**, not
0x100000. The whole reconstruction pipeline (naming dataset, composed `src/`,
`full_link.py`, the `verify` target keys) uses a self-consistent *analysis
space* of `file_offset + 0x100000`, which is **not** the hardware base. The
two are related by a constant: `hardware = analysis + 0x20000`.

## Why this was missed

The 0x100000 assumption predates this project's emulator work. Three symptoms
were attributed to "stale" pointers in the binaries; all three are explained
by the wrong base:

1. **IVT reset vector 0x1201a9** — called "stale / mid-function". In fact
   `0x1201a9 = 0x1201a8 | 1` and file 0x1a8 is the CPUID-check `start`
   (`movw r2,#0xc241`). The reset vector is *correct* at base 0x120000.
   `resolve_boot_entry()` was a workaround for the wrong base.
2. **Switch jump tables that Hex-Rays cannot decompile** — 6 functions
   (`sub_135528`, `sub_13C344`, `sub_13D950` in fmacfw_h_u02;
   `sub_13C484` in fmacfw_u02; `sub_13C520` in fmacfwbt_u02;
   `sub_11EBB4` in lmacfw_rf_u02) all fail with `switch analysis failed:
   switch information is incomplete or incorrect`. Their jump-table entries
   are exactly +0x20000 past the in-function targets in 0x100000-space,
   i.e. **in-function at 0x120000**. Example: `sub_13C520` (0x13c520–0x13c5b2
   analysis space) has table entries `0x15c54b`/`0x15c547` →
   `0x15c54a`/`0x15c546`, both inside 0x15c520–0x15c5b2 at base 0x120000.
3. **Boot behavior** — at base 0x100000, fmacfwbt "booted" only 125 insns
   (55 MMIO writes, then returned); the other three faulted at ~44 insns on
   a null-pointer write. At base 0x120000, **all four images boot from the
   reset vector to 8000+ insns with ~2660 MMIO writes and no fault**, then
   zero a ~97KB data region at 0x182000–0x199b00 and touch NVIC/peripherals
   (`0xe000e400`, `0x40509000`) — a real deep init.

## Verification

- Reset vector `0x1201a9` == CPUID `start` at file 0x1a8 for all 4 images.
- Jump-table targets in-function at base 0x120000 (checked directly).
- Literal pools at boot are absolute hardware addresses (`0xe000ed00` CPUID,
  `0x40506000` peripheral) — base-independent, so the early boot "worked"
  even at the wrong base.
- Emulator boot at 0x120000: identical deep behavior across all 4 images
  (same reset stub shared by the WFFW images).

## What stays where

| Artifact | Space | Note |
|---|---|---|
| Original binary emulation | 0x120000 | emulator `CHIP_BASE`; boot from IVT reset |
| Reconstruction `src/`, dataset, full link | 0x100000 | analysis convention, kept for consistency |
| `verify` compare key | 0x100000 | matches `truth_lane_smoke.py` recon rows |
| New decompiles of the 6 switch functions | 0x120000 then −0x20000 | decompile at hardware base, shift to analysis space |

## Consequence for the 6 stubs

The 6 `no-dataset-entry` stubs in `build/full_link/report.json` are functions
IDA *has* (names + sizes in the v19 decompile log) but could not decompile:
every one is a `decompile_none` with `switch analysis failed`. Decompiling
them requires IDA at base 0x120000 (jump tables then resolve). The resulting
C is shifted −0x20000 into analysis space before composing.
