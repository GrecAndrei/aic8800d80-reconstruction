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

## Historical v26 divergence surface (15 functions; all now closed or reclassified)

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
and the intrinsic was assembler-verified. After rebuilding both object and
linked-run artifacts, targeted probes showed all six formerly failing rows
matching every vector, and the full four-image corpus meter now reports
**0 failing functions / 100% comparable-all-match** (4,718 functions,
3,181 exercised all-match, 1,320 vacuous all-match, 217 never-comparable).

## 2026-11-26 timer-forwarding validation

The three lmac task-queue handlers were machine-proven to load the timer object
pointer into r0 before `bl timer_is_past`; the zero-argument Hex-Rays cast was
therefore a real latent ABI defect even though prior vectors happened to match.
`tools/timer_target_forward.py` now forwards the argument explicitly. After
rebuild/relink, `task_queue_handler_a/b/c` each match all five fidelity
vectors (MMIO+RAM+r0), so the correction is both machine-motivated and
behavior-preserving.

## 2026-11-27 final corpus evidence

The under-arity/static-contract campaign is closed with machine evidence rather
than scan-count gaming: every one of the 34 original rows was either narrowed
because the original machine code overwrote the apparent input before use, or
repaired by forwarding the exact register value the original caller placed in
r0-r3. The final three frame-builder callbacks receive
`(_frame.v55, _frame.v60, 2)`; targeted linked probes match the callers on all
five vectors and dynamically exercise the callees on boot_neg, boot_ptr, and
boot_scalar.

Final four-image meter (`metadata/fidelity_meter.json`, 4,718 composed
functions, five probe vectors):

| metric | result |
|---|---:|
| static defect functions | **0** |
| syntactic under-arity rows | **0** |
| jumpout/memory-macro/missing-stub defects | **0 / 0 / 0** |
| failing any vector | **0** |
| exercised all-match | **3,181 (67.42%)** |
| vacuous all-match | **1,320** |
| never-comparable | **217** |
| comparable all-match | **100%** |
| truth lane | **25/25 bare_zero and 25/25 all vectors** |

Every probe vector has zero DIFFER rows. Per-vector MATCH/NOT_RUN counts are
bare_zero 4,490/227, boot_zero 3,569/1,149, boot_scalar 3,656/1,059,
boot_neg 3,579/1,135, and boot_ptr 3,423/1,289. `NOT_RUN` is neutral evidence:
the original did not return (or the unit is not callable in the linked image),
not a reconstruction failure.

The 217 never-comparable rows are measurement-limited, not hidden failures:
209 are originals that do not return on any standalone probe vector (boot/
interrupt/event-wait style control flow), and 8 are non-callable interior
libmatch fragments (`double_compare_nan`, `double_compare_ord`,
`double_multiply`, `double_divide`, `__aeabi_dmul_nan`, `__aeabi_ddiv_nan`,
`aeabi_dadd_internal`, `double_unordered` in their respective images). The
1,320 vacuous all-match rows are weaker evidence than exercised rows: original
and reconstruction match, but the probes observe no MMIO write, RAM difference,
or non-zero r0 result. They include small getters/polling wrappers, linked
libmatch routines, and 36 machine-proven nullsub/tail-alias structural units.
They are reported separately precisely so they cannot inflate the exercised
fidelity claim.

Boot traces are exact ordered-write prefixes at the 500k-instruction cap:
reconstruction/original writes are fmacfw_h 1,964/2,078, fmacfw 1,960/2,074,
fmacfwbt 1,953/2,069, and lmacfw_rf 2,236/2,251. In every image each
reconstruction write equals the original write at the same ordinal position;
the first difference is an additional original write after the reconstruction
reached the same instruction cap. Because the reconstruction is independently
compiled C rather than the original instruction stream, instruction-count
timing is not bit-identical; this is a coverage caveat, not a demonstrated
sequence/value divergence.

Build/reproducibility evidence in the same report: all four full links succeed
with zero residual undefined symbols and zero missing stubs,
`post_compose_clean=true`, and `make -C src reproduce` confirms that a fresh
compose is byte-identical to the tracked `src/` and `metadata/libmatch.json`.

This establishes zero known static defects and zero measured behavioral
divergences on every comparable probe. It does not mathematically prove all
unprobed inputs or asynchronous host/interrupt interleavings; those are
outside the finite machine-evidence corpus and are intentionally not claimed.
