# osal_int_exit ram_differ forensics (2026-08 — deepest single-function investigation)

## Verdict chain established with execution traces

`osal_int_exit @ 0x1149fc` (lmacfw_rf) differs only at RAM 0x180564 — the interrupt
nesting counter. End values: **orig=0, recon=1** — the decrement never executes in
the reconstruction, yet the run terminates "returned".

Traced mechanism:
1. `++counter` writes 1 in both (recon pc 0x806436, orig analysis 0x114a1c)
2. `blx` to the callback (data-stored pointer 0x1583dd, correctly relocated by
   full_link into the recon link at 0x8000a0 = `sub_1383DC`)
3. The callback executes its body, passes its interrupt-controller poll loops,
   reaches the correct epilogue `mov r0,r3; pop {r4,r5,r6,pc}` at 0x80020c/0x80020e
4. **Control never arrives back at 0x80643a** — the trace shows pc jumping
   0x80020c → 0x800212 (the literal pool!) without the pop instruction ever
   appearing in the pc trace, then executing pool words as code and falling into
   `crc32.part.0` at 0x80022c, where execution dies in a byte-scan loop and the
   run terminates without the osal_int_exit epilogue ever running

## Decisive isolation result

Calling `sub_1383DC` DIRECTLY with identical bootstate/args: **returns cleanly**
(r0=0). The defect manifests only in the nested context (called from osal_int_exit).
So the compiled callback is correct in isolation; something about the nested
stack/memory context corrupts the return — prime suspects:

- stack-slot corruption of the pushed lr by the callback's memory writes
  (the write `*(ctrl) = 53` targets memory derived from relocatable data pointers —
  in the nested case osal_int_exit has already run `__disable_irq`+flag write, and
  both the flag at 0x185afc and counter at 0x180564 are live)
- AAPCS/unicorn pop-{pc} behavior on the nested frame (alignment ruled out:
  all pushes are 4-word even counts)
- the unicorn code-hook trace itself may hide the pop — but the END STATE
  (counter 1, decrement never written) is hook-independent ground truth

## PRIMASK improvement (committed alongside)

Investigation exposed that `mrs r3, PRIMASK` at 0x114a04 was decompiled as
`__get_CPSR()` and the intrinsics were stateless stubs. types.h now implements a
per-image PRIMASK shadow (`__aic8800d80_primask_state`) mutated by
__disable_irq/__enable_irq — hardware-faithful interrupt nesting semantics.
This did NOT resolve the ram_differ (single non-nested call path executes the
same either way), but it is correct independent of the remaining defect.

## Next attack vector

Diff the callback's memory WRITE targets between direct-call and nested contexts —
the corruption vector is one of those writes hitting the nested lr stack slot.


## Byte-level endgame evidence (final state)

sp/lr instrumented at the epilogue: at pc 0x80020c (mov r0,r3) sp=0x19ffe0
(correct pre-pop value) — and sp NEVER advances, meaning the pop at 0x80020e
never executes. Execution appears next at 0x800212 (the literal pool). The
emitted bytes are verified correct (4618 mov; bd70 pop; pool after), the
beq.w at 0x8000ec correctly targets 0x80020c, and the pushed lr 0x80643b sits
untouched in the correct stack slot (0x19ffec). The transition 0x80020c ->
0x800212 with unchanged sp is impossible in correct ARM execution; remaining
suspects are (a) unicorn IT-state corruption across the blx boundary making
the pop conditionally skipped, or (b) a unicorn code-hook artifact masking the
true transition. The next attack requires single-stepping with uc_emu_start
instruction-level control rather than hooks, or rebasing the experiment onto
the alternative emulator harness (tools/test_boot_rom_contract.py path).


## Resolution attempt: single-stepping (final negative result)

True single-stepping was attempted two ways: (a) hook+emu_stop at the epilogue
then count=1 stepping — the platform's run wrapper re-entered after the stop
and pc ended at the sentinel; (b) fully manual emu_start drive — the platform's
exception/spin-breaker machinery is required for correct execution of this
corpus, and raw stepping hits UC_ERR_EXCEPTION with corrupt state. Hook-level
evidence remains the ground truth: the pop at 0x80020e never fires as a TB
entry, sp never advances past it, yet execution continues in the literal pool.
Note UC_HOOK_CODE in unicorn fires per translation-block entry, not per
instruction — so "the pop never appears in the trace" is consistent with the
pop executing inside the same TB as the preceding mov; but the sp evidence
(constant 0x19ffe0 across all subsequent hooked blocks) still contradicts a
successful pop. The anomaly is therefore one of: (a) unicorn mis-executes the
mov+pop TB in this precise register/memory state, (b) the sp hook reads are
themselves distorted by TB-boundary timing, or (c) a deeper corruption in how
the linked reconstruction's memory layout interacts with unicorn's Thumb
translation at this exact site. Root-causing requires unicorn-internals work
(gdb-server attach or qemu trace comparison) or an alternative execution
harness — beyond the scope of this investigation.

## Status

NOT FIXED — but the defect is localized to a single anomalous TB execution in
nested context. Everything else about the function is behaviorally exact
(MMIO footprint, return value, counter increment). The PRIMASK shadow work
landed independently. Recommend: revisit when an independent ARM Thumb
emulator backend is available for cross-validation, since unicorn-specific
artifacts cannot be ruled out without one.
