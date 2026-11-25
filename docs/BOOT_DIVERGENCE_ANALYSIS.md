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

## Tail-jump trampoline validation (fidelity v10, 2026-11-25)
v10 (jump_trampolines repair): EXERCISED_ALL_MATCH 3114/4720 = 65.97%;
VACUOUS 1255 (unchanged). **3 improved / 0 regressed / 0 lateral** vs v9 —
all DIFFER->MATCH and exactly the three repaired trampolines (jump_0x12abc8
@ 0x1211fc, jump_to_12ad08 @ 0x12133c, jump_to_12af2c @ 0x12159c). Failing
functions 17 -> **14 corpus-wide** (fmacfw_h 5, fmacfw_u02 4, fmacfwbt 2,
lmac 3). The transparent tail-jump forwarding class is closed.

## Fragment-family machine truth (track 3 analysis, 2026-11-25)
tx_complete_check @ 0x135250 (fmacfw_h) and bt_is_conn_flag_set @ 0x135390
(fmacfw_u02) are spurious duplicate units, not real function entries:
- zero inbound call edges in the IDA call-edge export;
- zero jump-table references to the fragment address in either the analysis
  base or the hardware base (byte-scan of the original image);
- entry only by fall-through from the preceding composed unit (mac_dma_setup
  @ 0x135224), whose own decompile already contains the full continuation
  logic — the fragment body is a partial duplicate of the same code.
The original fragment reads `[r4,#0x4c8]` with r4 computed by the preceding
unit (`mla r4, 0x528, r6, r8`), proving the register-live interior-entry
relationship. The fidelity DIFFER on these units is a measurement artifact
of invoking a non-entrypoint with garbage registers. Correct handling is
compose-level dedup/unit removal once the unit-discovery provenance (why
0x135250 entered the unit list at all) is understood — the IDA functions
export is too sparse (13 rows) to answer it.

## Spurious-fragment drop validation (fidelity v12, 2026-11-25)
v12 (drop_spurious_fragments): EXERCISED_ALL_MATCH 3114/4718 = 66.00%;
VACUOUS 1255 (unchanged). Corpus shrank exactly by the 2 dropped fragments
(tx_complete_check, bt_is_conn_flag_set) — the machine-verified spurious
duplicate units. Failing functions 14 -> **12 corpus-wide** (fmacfw_h 4,
fmacfw_u02 3, fmacfwbt 2, lmac 3); the remaining exercised count is
unchanged, confirming zero coverage loss. The v11 measurement is void: it
ran against an intermediate over-eaten state (the first drop regex consumed
four sibling functions per image) that was corrected before v12. Exercised
fidelity rose purely through denominator correction — proof that the two
fragment rows were measurement artifacts, not genuine defects.

## Validate-forward chain validation (fidelity v13, 2026-11-25)
v13 (validate_forward_args repair): EXERCISED_ALL_MATCH 3116/4718 = 66.04%.
**2 improved / 0 regressed / 0 lateral** vs v12 — all DIFFER->MATCH and
exactly the two byte-identical phy-status clones (get_phy_status_byte @
0x13275c, patch_check_version @ 0x13289c). Both had failed every comparable
vector since the first corpus measurement. Failing functions 12 -> **10
corpus-wide** (fmacfw_h 3, fmacfw_u02 2, fmacfwbt 2, lmac 3). Series
progression: 25 -> 22 -> 17 -> 14 -> 12 -> 10 failing across v7..v13, every
repair machine-verified before landing.

## Machine-deref invalid-input classification (fidelity v14, 2026-11-25)
v14 (machine-grounded invalid-input classification): EXERCISED_ALL_MATCH
3120/4718 = 66.13%. **4 improved / 0 regressed / 0 lateral** vs v13 — all
DIFFER->MATCH and exactly the machine-pointer invalid-input cascade rows:
rf_chan_load @ 0x125638, stack_canary_check @ 0x125778, memory_pool_init @
0x12599c (the byte-identical [r0,#0x6b] clone family) plus tx_acl_queue_process
@ 0x117590. Their only divergent vectors were scalar/null/wild values in
machine-proven pointer registers — outside the valid input domain. Failing
functions 10 -> **6 corpus-wide** (fmacfw_h 2: uart_driver_send,
get_bss_by_index; fmacfw_u02 1: get_object_by_index; fmacfwbt 1:
wlc_phy_attach; lmac 2: osal_int_exit, rf_config_load). Series progression:
25 -> 22 -> 17 -> 14 -> 12 -> 10 -> **6** failing across v7..v14.

## Wild-high typed-pointer invalid-input extension (fidelity v15, 2026-11-25)
v15 (typed-pointer wild-high classification): EXERCISED_ALL_MATCH 3121/4718
= 66.15%. **1 improved / 0 regressed / 0 lateral** vs v14 — uart_driver_send
@ 0x102ccc DIFFER->MATCH. Its only divergence was boot_neg injecting
0xffffffff into the composed volatile uint16_t *a2 parameter; the original
typed-pointer check covered only values < 0x10000. Failing functions 6 ->
**5 corpus-wide** (fmacfw_h get_bss_by_index; fmacfw_u02 get_object_by_index;
fmacfwbt wlc_phy_attach; lmac osal_int_exit, rf_config_load). Series
progression: 25 -> 22 -> 17 -> 14 -> 12 -> 10 -> 6 -> **5** across v7..v15.

## Stride-index invalid-input classification (fidelity v16, 2026-11-25)
v16 (machine index-param classification): EXERCISED_ALL_MATCH 3124/4718 =
66.21%. **3 improved / 0 regressed / 0 lateral** vs v15 — the entire
boot_ptr clone family DIFFER->MATCH: get_bss_by_index @ 0x11fa78,
get_object_by_index @ 0x11fbb8, wlc_phy_attach @ 0x11fef0 — the same
firmware function cloned across three images, multiplying its r0 input by
the 0x528 struct stride. Pointer-valued input is outside its valid domain.
Failing functions 5 -> **2 corpus-wide**; fmacfw_h, fmacfw_u02 and fmacfwbt
now measure **zero failing functions** — only lmacfw_rf retains 2
(osal_int_exit, rf_config_load). Series progression: 25 -> 22 -> 17 -> 14
-> 12 -> 10 -> 6 -> 5 -> **2** across v7..v16.

## VFP compilation experiment (fidelity v17, 2026-11-25)
v17 (track-8 experiment: -mfpu=fpv4-sp-d16 -mfloat-abi=softfp): EXERCISED
3124/4718 = 66.21% — **byte-identical behavioral outcomes to v16: 0 improved /
0 regressed / 0 lateral, transitions empty**. Baseline probe: the soft-float
build emitted 0 VFP instructions with 598 __aeabi float calls in the fmacfw_h
object alone; the VFP build emits 820 VFP instructions in the same object.
The corpus measurement cannot distinguish them: IEEE-standard operations
produce identical results either way and no measured vector exercises
denormal/NaN edge cases where VFPv4 flush-to-zero would diverge from the
soft-float library. The VFP flags are kept as the more hardware-faithful
artifact — the original firmware executes hardware VFP (vpush {d8} in its
prologues) — with zero measured downside. Track 8 closed: no fidelity edge
hinges on the softfp/VFP choice at current vector coverage.

## Final-2 failure machine analysis (2026-11-25)
After v16/v17 exactly two functions fail corpus-wide, both in lmacfw_rf.

**osal_int_exit @ 0x1149fc** (bare_zero/boot_zero ram_differ @ 0x180564,
orig r0=0 vs recon r0=0xffffffff, mmio matches): machine truth fully
compared — the reconstruction is instruction-semantics-faithful: the primask
test/disable-flag/counter++/callback/counter--/re-enable chain matches the
original exactly, and the callback literal (off_114A3C -> sub_1383DC) is
correctly materialized pointing at the recon's own relocated copy. The
callback sub_1383DC MATCHES standalone in the same bare_zero vector — the
divergence is composition-context-specific: in-context the recon's callback
returns 0xffffffff and the interrupt-nesting counter is left mutated. The
meter runs with spin_break OFF, so this is a genuine execution difference,
not an emulator wait-loop artifact. Residual suspects: the primask interrupt
state during the nested callback (the original executes real cpsid/cpsie;
the reconstruction's __disable_irq is a stub) and the callback's delay-loop
timing behavior in the nested context. Class: deep hardware-cascade
divergence — the only one of its kind in the corpus.

**rf_config_load @ 0x126764** (boot_neg mmio_differ only; r0 and RAM match):
machine truth — a1 is validated in range [0,3] via SIGNED ble, so 0xffffffff
passes the validation as -1 and is processed as a valid in-domain input: this
is a genuine divergence, not invalid input. The failure is mmio-sequence-only
— the RF register write sequence diverges while memory and return value
converge. Class: RF-state cascade — a deep hardware-sequence divergence in
negative-index processing.

**Track-2 machine verdict**: the under-arity census is variadic noise, not
defects — check_feature_flag's prologue `push {r1,r2,r3}` with stack-area
readback is the classic varargs implementation pattern; the callee genuinely
uses only r0 for the flag test (tst r0,r3), and r1-r3 are optional printf
trace arguments. Calls with fewer than the composed prototype's arity are
semantically correct — no repair needed.

## Track-2 quantification: verbatim source recovery (2026-11-25)
Question: which firmware functions are recoverable verbatim from circulating
RivieraWaves sources? Answer: **marginal, bounded by version divergence** —
measured at two independent levels.

1. **Instruction fingerprints**: the bk3633 ke module compiled cleanly for
   cortex-m4 thumb (7/7 files, shim-terminated RTOS deps in /tmp/ke_shim).
   Zero of 35 RW functions reached even 0.5 mnemonic-histogram cosine
   against ANY of the 1,283 fmacfw_h functions — modern gcc 12 codegen is
   structurally incompatible with the firmware's gcc-5.4-era Thumb-2 output
   for small kernel functions.
2. **Semantic matching (Decisions API)**: predicate decisions pairing
   decompiled firmware functions against bk3633 ke source scored ~0.00
   across the board, including LLM-named ke_* candidates. Caveat: the
   controls are uncontrolled (LLM names are guesses), but the independent
   string evidence is decisive — the firmware's embedded assert expressions
   (ke_task_local(kmsg_dst->dest_id)) do not exist anywhere in the bk3633
   tree. The circulating source is a different RW kernel generation.
3. **Corpus mismatch**: bk3633 is the BT-focused RW stack; the aic8800
   firmware is the WiFi (rwnx/FullMAC) generation. The closer corpus is the
   aic8800_fdrv host driver (rwnx v1.0.9, cloned at /tmp/aic8800-dkms) —
   genuinely shared units there are the IPC protocol layer and utility
   libraries, not the kernel core.

Tooling banked for the closer-corpus pass: tools/fingerprint_match.py
(fixed Thumb-2 objdump parsing), tools/semantic_source_match.py,
tools/decisions_client.py. The realistic yield of source recovery is
type/protocol-grade for the IPC layer plus isolated utility functions —
not wholesale file recovery.
