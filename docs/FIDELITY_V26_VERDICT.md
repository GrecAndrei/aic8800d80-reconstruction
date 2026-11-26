# Fidelity v26 — corrected corpus measurement (bare_zero, 4,718 functions)

## Final verdict

| verdict | count |
|---|---|
| full_match | 3,672 |
| asserted_match | 547 |
| reloc_ptr_match | 137 |
| original_did_not_return | 219 |
| not_in_linked_image | 128 |
| r0_differ | 13 |
| ram_differ | **2** |
| mmio_differ | **0** |

Genuine passing: 4,356 / 4,718 (92.3%). Measurement-limited: 347.
Genuinely divergent: **15** (2 ram + 13 r0).

## What the correction chain found

The path from v18's noisy measurement to v26 was almost entirely comparator
artifacts, not behavioral defects:

1. **Relocated data-stored function pointers** — the original stores
   runtime-space pointers, the reconstruction LINK_BASE-space pointers to the
   same functions. The pre-existing `is_equivalent_reloc_ptr` suppression
   silently failed because its original-side lookup was built from
   `lrr.marker_names` (composed-source markers), which was empty since
   de-monolithization (umbrella-include casualty, same root cause as the
   meter enumeration failure). Both fixed; equivalence is now primarily
   by analysis address — name-independent, since naming passes label the
   same unit differently across datasets.
2. **Reconstruction-owned emulation state** (`__aic8800d80_*` — the PRIMASK
   shadow etc.) — CPU-state models with no corresponding memory in the
   original, structurally incomparable. Neutralized in the ELF-region
   comparison. This single cluster accounted for 158 functions diffing at
   each of three addresses.
3. **Dedup-suffixed names** — compose emits base + `_N` for same-name units
   while the original function table keeps the shared base name.
4. **Stale objects** — `make check` does not reliably rebuild after compose
   regeneration rewrites main.c; links built on stale objects lost 123
   functions to gc-sections and diverged in peripheral write patterns
   (the v25 mmio_differ=21 class was entirely this artifact — v26 mmio=0).
   Correct chain: touch main.c, make check, then full_link.

## Remaining genuine divergence surface (15 functions)

- `osal_int_exit` (lmac) — the documented unicorn-level control-flow
  anomaly (docs/OSAL_INT_EXIT_FORENSICS.md), needs a second emulator
  backend to cross-validate
- `tx_acl_queue_process` (lmac, diff at 0x18) — low-address write
- 13 r0_differ — audited: the dominant subclass is functions returning
  `volatile uint64_t *` (timer_get_counter, read_hw_clock, timer_timestamp_get)
  — POINTER returns into runtime structures or stack frames, inherently
  execution-dependent across two address-space layouts; the equivalence logic
  covers code pointers but not data/stack pointers. Combined with the
  timing/counter reads (rf_rssi/calibration), the r0_differ class is
  measurement-inherent noise in bulk, not behavioral defect. Genuine
  behavioral divergence requiring per-function forensics: osal_int_exit
  (documented) and tx_acl_queue_process only
