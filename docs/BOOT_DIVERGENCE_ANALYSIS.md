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
