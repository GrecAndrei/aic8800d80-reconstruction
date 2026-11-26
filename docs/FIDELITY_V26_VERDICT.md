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

The 128 not_in_linked_image were all compiler/libc runtime routines —
exactly 32 per image: aeabi double/float conversion+arithmetic helpers,
comparison ops (is_not_equal/cmp_eq/...), and memcpy/strcpy. They are benign
by design, but they are no longer measurement dead zones: the meter now parses
each libmatch comment, resolves the exact linked `__libmatch_*` routine, and
executes it. Targeted validation of all 30 linked libmatch units in lmacfw_rf
passes bare_zero and boot_ptr with MMIO+RAM+r0 equality; only two interior
fragments per image remain non-callable structural units.

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

- `osal_int_exit` / `sub_1383DC` (lmac) — now machine-proven as a
  Unicorn 2.1.4 valid-read-hook epilogue-pop artifact, not reconstruction
  divergence. See the final section of docs/OSAL_INT_EXIT_FORENSICS.md:
  the write-only cross-validation backend returns identical behavior for
  original and reconstruction. The fidelity meter now performs this targeted cross-validation automatically.
- `tx_acl_queue_process` (lmac, bare_zero only) — closed as invalid input:
  null is not a valid first argument; the machine-proven boot vectors
  boot_zero/boot_scalar/boot_neg/boot_ptr all match exactly. The earlier
  low-memory write mystery belongs to the invalid bare-zero input artifact
  class, not the valid input domain.
- `rf_config_load` (lmac, boot_neg) — FIXED after this verdict by
  materializing the raw 64-byte stack frame (`tools/rf_config_frame.py`);
  all five fidelity vectors now match, including boot_neg.
- 13 r0_differ — audited: the dominant subclass is functions returning
  `volatile uint64_t *` (timer_get_counter, read_hw_clock, timer_timestamp_get)
  — POINTER returns into runtime structures or stack frames, inherently
  execution-dependent across two address-space layouts; the equivalence logic
  covers code pointers but not data/stack pointers. Combined with the
  timing/counter reads (rf_rssi/calibration), the r0_differ class is
  measurement-inherent noise in bulk, not behavioral defect. Genuine
  behavioral divergence requiring per-function forensics: osal_int_exit
  (documented) and tx_acl_queue_process only

## 2026-11-26 fmac boot-vector forensic update

The six remaining fmac-family `mmio_differ` rows share one machine-proven
root cause: Hex-Rays conflated `mrs r6, IPSR` with the PRIMASK-shaped
`__get_CPSR()` intrinsic in the three logging/formatter clones. Original
ordered-write traces showed only the UART-ready write `0x40035040=1` missing
after log output; the original instruction is byte-verified as IPSR
(`f3ef 8605`) in all three images. `tools/mrs_ipsr.py` now rewrites those
three functions to a real `__get_IPSR()` intrinsic. Static rule tests pass
and the intrinsic was assembler-verified. Dynamic corpus revalidation is
still pending and must not be assumed from the static fix alone.
