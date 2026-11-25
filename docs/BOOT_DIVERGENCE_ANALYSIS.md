# Boot divergence analysis (fmacfw_h / fmacfw_u02)

Evidence gathered 2026-11-25 during the post-repair corpus measurement
(70.76% exercised fidelity; boot regression isolated to the two fmacfw images).

## Symptom
- recon boot in fmacfw_h/fmacfw_u02 terminates at ~128k instructions after 277
  perfectly-matched peripheral writes; original caps at 500k with 2078+ writes.
- fmacfwbt / lmacfw_rf recon boot essentially correct (1953/2069, 2238/2251 prefix).
- Write 277 in the original is the first UART console byte of the `_cal` boot
  message at pc 0x12d70e/0x12d736 (hardware space).

## Established facts (machine-verified)
1. The recon boot does NOT fault: the `undefined_instruction_handler` at
   analysis 0x114a78 is an LLM misnomer. The function is a critical-section
   wrapper around the boot-ROM environment query (`mov.w r2,#0x1c8; ldr r3,[r2];
   blx r3`). `get_global_context` calling it is CORRECT binding; entering it
   during boot is normal control flow, not an exception.
2. `patch_apply` is a no-op in BOTH boots: the descriptor read through ROM
   vector 0x1d8 has magic "CALI" (correct, dword_114BF0 matches in original
   data and reconstruction) but a zero flag word, so `v6 = a1 & v9[1]` is 0
   and the function returns 1 without copying anything.
3. Original boot iterates the patch-check 3 times (3 identical 0x1d8 service
   calls, src 0x3ffe000 len 72); recon iterates once. The divergence is in the
   CALLER's loop control or downstream of the first iteration, not in
   patch_apply itself.
4. Low-memory ROM vector slots (0x100-0x210) are never written in either boot:
   the correct-memset-clobbers-vectors hypothesis is refuted.
5. The boot-ROM service copies byte-identical data in both boots.
6. The environment query returns 0 in both boots (contract model default), so
   context initialization is identical.

## Open question
Where exactly the caller of patch_apply diverges after the first iteration.
Candidate areas: the patch-table iteration logic in the boot chain
(data-driven loop bounds), or code between the last matched peripheral write
and the UART print path (`rf_config_read`/`crypto` tail events in original).

## Infrastructure notes
- The terminal-PC ring buffer is useless when a tight loop dominates; capture
  transition-triggered context instead (see scripts in session history).
- `fidelity_meter.py::measure_boot_parity` records first_diff in the JSON.

## Caller identified (2026-11-25, later pass)
`patch_apply` has no direct calls in the original text scan and no data
references because the boot-chain caller uses ordinary direct bl sites that
the quick hand-rolled thumb decoder missed. In the linked reconstruction the
callers are inside `read_global_signed_flag` (boot chain) and one deeper
consumer. The boot-chain loop control is data-driven: `read_global_signed_flag`
loads a global context pointer, reads a flag byte, and calls
`patch_apply(r0=1, a2, r2=4)` only while the flag byte is zero. The original
iterating 3 times vs the recon once means the flag/state memory the loop
reads differs after the first iteration — the divergence is in whatever
writes that global flag byte during the first pass, not in patch_apply.

## Formatter causal chain verified (2026-11-25, third pass)
The boot regression IS a genuine regression: the pre-repair measurement
(fidelity_postmem) shows recon boot capped at 500k instructions in all four
images (prefixes 1964/1960/1953/2238); post-repair the two fmacfw boots
return at ~128k after only 277/196 matched writes. The final matched write
in the original is the first UART console byte at pc 0x12d70e/0x12d736 —
the divergence is exactly at the first boot print.

Machine-verified causal chain: the original boot enters the formatter
(dbg_vsnprintf_offset family) 3 times in the first 300k instructions (first
at insn 71950) and continues deep; the recon boot enters it exactly twice
and unwinds at 128459 instructions. The formatter's digit-emission defect
(traced separately: middle digit positions of '%u' output leak stack
pointer bytes, e.g. 0x0019efcb into the output buffer) corrupts execution
during boot logging. The digit corruption itself is a frame-layout defect
in the decompiled backward-growing digit buffer exposed by the corrected
build (-ffreestanding codegen shift), not a wrong division constant —
dword_12EA04 = 0xcccccccd matches in original and reconstruction.

## RESOLVED (2026-11-25): formatter scratch-frame repair heals the boot
`tools/format_scratch_frame.py` merges the decompiled formatter's backward
digit-generation scratch into a single array object so all pointer arithmetic
stays in-object under correct compilation (commit ae94a120c). Post-repair
boot parity on freshly linked ELFs: fmacfw_h recon capped 500000i with
prefix 1964/2078, fmacfw_u02 capped 500000i with prefix 1960/2074 — exactly
the pre-regression deep-boot behavior (the residual 114/114-write tail
divergence matches the pre-existing baseline). The boot regression causal
chain is closed: decompile frame-model defect → formatter clobbered its own
frame during boot logging → boot derailed at the first print.

## Related analysis: memory-content loop sensitivity is not a decompile defect
Machine-level comparison of ble_get_rssi (fmacfw_h 0x11de3c) confirms the
decompiled `while(1)` linked-list walk faithfully matches the original machine
logic: the loop continues unconditionally while the signed global flag is
non-negative, and only applies the null-terminator check when the flag is
negative. Both sides can in principle loop forever when the walked list lacks
a flagged entry; standalone-emulation divergence in the `boot_ptr` vector
reflects memory-content sensitivity, not a reconstruction defect. Treat the
`recon_did_not_return` cluster in boot_ptr as sensitivity artifacts unless a
per-function machine comparison shows a real logic divergence.

## Truth-lane linked comparison: 7/7 PASS post-repair (2026-11-25)
`tools/linked_recon_run.py` against the dual-repaired full-link ELF (formatter
scratch-frame + rom_copy_frames): PASS=7 REVIEW=0 FAIL=0, every decisive
target reporting identical_peripheral_write_sequence. The former 1 PASS /
6 FAIL linked-run split — whose failures were callee decompile defects
including the formatter — is fully closed by the two frame-object repairs.

## Corpus-wide verification of the frame repairs (fidelity v4, 2026-11-25)
Fresh full-corpus measurement on dual-repaired sources (formatter scratch
frame + rom_copy_frames), all scoring improvements active:

- EXERCISED_ALL_MATCH: 3455/4720 = 73.20% true non-trivial fidelity
  (baseline v2: 3347 = 70.91%).
- Per-function delta vs v2: 115 improved, 0 regressed, 0 lateral
  (108 DIFFER->MATCH, 6 NOT_RUN->MATCH).
- Failing functions corpus-wide: 203 -> 94. Per image: fmacfw_h 73->31,
  fmacfw_u02 93->26, fmacfwbt 24, lmacfw_rf 13.
- Boot trace prefix parity: all four images now capped at 500000i with deep
  matched prefixes (1964/2078, 1960/2074, 1953/2069, 2238/2251) — the
  fmacfw boot regression is closed in the measurement itself, matching the
  pre-regression baseline exactly.

## Corpus noise decomposition (post-v4 triage, 2026-11-25)
The 94 failing functions in v4 decompose as: ~34 r0_differ caller-noise
(r0 residue with no consuming call site anywhere in the image — now excluded
from scoring by the caller-noise overlay); ~25 shared-state divergence at
SRAM byte 0x1922a7 concentrated in the timer/ll machinery (stable across
runs, under root-cause investigation); 15 r0_void_ub cases all in the
boot_neg vector in small accessors (input-residue noise); 5 exercised
mmio_differ (mostly boot_neg noise plus small hardware-init sequences);
remainder genuine but complex defects (mac_isr_handler, find_extension —
libc-binding/control-flow decompile defects) and boundary artifacts
(bt_reg_write data-as-code). The genuine-defect count is thus far smaller
than the raw failing count; the timer-state cluster is the single dominant
systematic target.

## Timer-repair corpus validation (fidelity v5, 2026-11-25)
Fresh measurement on timer_signed_diffs-repaired sources with the caller-noise
overlay active: EXERCISED_ALL_MATCH 3475/4720 = 73.62% (v4: 73.20%). Per-
function delta vs v4: 20 improved / 0 regressed / 0 lateral (all DIFFER->MATCH).
Failing functions 94 -> 74 corpus-wide (fmacfw_h 31->25, fmacfw_u02 26->20,
fmacfwbt 24->18, lmacfw_rf 13->11). The dominant 0x1922a7 shared-state cluster
is closed in the measurement itself.

## Signed-comparison + heap-boundary validation (fidelity v6, 2026-11-25)
v6 (tick_signed_cmps repaired): EXERCISED_ALL_MATCH 3475/4720 = 73.62%,
3 improved / 0 regressed / 0 lateral vs v5 (all DIFFER->MATCH); failing
functions 74 -> 71 corpus-wide. The tick-delta repair class is closed.

## Caller-noise fusion + heap-boundary validation (fidelity v7, 2026-11-25)
v7 (caller-use fusion wired into scan_image + heap_boundary_literal repair):
EXERCISED_ALL_MATCH 3103/4720 = 65.74% true non-trivial fidelity; VACUOUS 1255.
**46 improved / 0 regressed / 0 lateral** vs v6 — all DIFFER->MATCH.
Failing functions collapsed 71 -> **25 corpus-wide** (fmacfw_h 8, fmacfw_u02 8,
fmacfwbt 6, lmac 3). patch_alignment @ 0x12c954 DIFFER->MATCH — the heap
free-list boundary repair is validated. The exercised/vacuous rebalancing
(3475->3103 exercised, 837->1255 vacuous) is the caller-noise exclusion
working as intended: r0 differences with no consuming caller no longer count
as observable traffic, so noise-only functions move to vacuous-match. The
65.74% figure is a cleaner measure of true behavioral fidelity.

## Tailcall-args + strncasecmp-binding validation (fidelity v8, 2026-11-25)
v8 (patch_tailcall_args + find_ext_strncasecmp repairs, post-chain-order fix):
EXERCISED_ALL_MATCH 3106/4720 = 65.81%; VACUOUS 1255 (unchanged).
**3 improved / 0 regressed / 0 lateral** vs v7 — all DIFFER->MATCH:
patch_handle_data @ 0x13376c (the tailcall-argument repair), find_extension
@ 0x12f9a4 (the strncasecmp-binding repair), and one sibling improvement at
fmacfw_u02 0x116174. Failing functions 25 -> **22 corpus-wide** (fmacfw_h 8,
fmacfw_u02 6, fmacfwbt 5, lmac 3); exercised matches rose exactly by the 3
improvements. The chain-order repair (find_ext_strncasecmp after libc_names)
held the reproduce fixed-point for the entire run.

## Mix-clone tailcall + parse_ipv4_dot validation (fidelity v9, 2026-11-25)
v9 (generalized patch_tailcall_args + ipv4_dot_libc repairs):
EXERCISED_ALL_MATCH 3111/4720 = 65.91%; VACUOUS 1255 (unchanged).
**5 improved / 0 regressed / 0 lateral** vs v8 — all DIFFER->MATCH:
ble_state_check_13362c @ 0x13362c and bt_process_rx_data @ 0x133988 (the
register-preserving mix/hash tailcall clones), parse_ipv4_dot @ 0x12f788
(the strchr/strncasecmp libc bindings), and two sibling improvements at
fmacfw_h 0x116034 and fmacfwbt 0x1165b4. Failing functions 22 -> **17
corpus-wide** (fmacfw_h 6, fmacfw_u02 5, fmacfwbt 3, lmac 3); exercised
matches rose exactly by the 5 improvements.
