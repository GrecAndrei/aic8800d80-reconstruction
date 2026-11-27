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

## 2026-11-27 authoritative eight-vector corpus evidence

This section supersedes the older five-vector numbers above. The authoritative
artifact is `metadata/fidelity_meter.json`, generated by a complete remote
eight-vector run over all 4,718 composed functions. The vectors are
`bare_zero`, `boot_zero`, `boot_scalar`, `boot_neg`, `boot_ptr`, `boot_ptr4`,
`boot_double`, and `boot_double_nan`. `boot_ptr4` seeds four valid SRAM struct
pointers; `boot_double_nan` passes a quiet-NaN first double operand
(`r1=0x7ff80000`) and finite second operand so the softfp parent entries
exercise their special-case dispatch.

| metric | result |
|---|---:|
| static defect functions | **0** |
| failing any vector | **0** |
| exercised all-match | **4,554 / 4,718 (96.52%)** |
| vacuous all-match | **0** |
| never-comparable | **0** |
| nonreturning-prefix rows | **156** (118 exercised, 38 vacuous) |
| interior libmatch fragments | **8** |
| machine-proven nullsub/tail-alias exclusions | **36** |
| truth lane | **25/25 bare_zero and 25/25 all vectors** |

Every vector has zero DIFFER rows. Per-vector MATCH/PREFIX/NOT_RUN/INVALID
counts are: bare_zero 4,511/143/8/56; boot_zero 4,532/143/8/35;
boot_scalar 4,521/141/8/48; boot_neg 4,504/147/8/59;
boot_ptr 4,156/262/8/292; boot_ptr4 4,131/364/8/215;
boot_double 4,316/158/8/236; boot_double_nan 4,316/158/8/236.

The 156 nonreturning rows are explicitly classified, not silently upgraded:
95 rows have exact complete write sequences through the cap, 38 have no
observable writes on either side, 20 have a strict write prefix, and 3 have an
original-nonreturn write prefix. Vector-level occurrences are 688, 222, 160,
and 24 respectively. These are cap-bounded partial evidence: both sides failed
to return, and all observed ordered events agree, but future writes after the
instruction cap are unproven. They are excluded from `EXERCISED_ALL_MATCH`
rather than counted as full equivalence. Strictly proven silent terminal
closed loops remain eligible for full match because the meter proves a
memory-invariant, peripheral-read-free closed loop.

The 8 interior fragments are not independent callable functions. They are
byte-contained inside the linked compiler-runtime `__aeabi_dmul` and
`__aeabi_ddiv` parents at offsets 0x1dc or 0x16e. Address-based parent lookup
finds all 8 parents, and every parent is MATCH on all eight vectors including
`boot_double_nan`; coverage is therefore structural byte-containment plus
parent-entry behavioral evidence, not fabricated standalone-entry evidence.

Boot traces are exact ordered peripheral-write prefixes through the
4096-write cap in all four images. Both original and reconstruction hit the
write cap, so this is exact capped-prefix evidence, not proof of complete
boot. There is no first ordinal write mismatch.

The remote dynamic corpus intentionally used `--no-build-check`; its report
therefore leaves `post_compose_clean` and `src_reproduce_clean` null. Build
validation is a documented split gate run locally on the same byte-identical
linked ELFs: all four images compile with `make -C src check`,
`tools/mix_state_chain.py --check` is clean, `tools/full_link.py` relinks all
four images with zero missing stubs and zero residual undefined symbols, and
the post-compose rule suite is clean. `make -C src reproduce` is the
post-commit fixed-point gate because it intentionally compares regenerated
source with git HEAD.

This establishes zero known static defects and zero measured behavioral
divergences on every comparable probe in the finite corpus. It does not
mathematically prove unprobed inputs, events after an instruction/write cap,
or asynchronous host/interrupt interleavings; those boundaries are explicit
measurement limits, not hidden failures.
