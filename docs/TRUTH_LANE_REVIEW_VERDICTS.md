# Truth-lane smoke: verdicts for the 16 former REVIEW targets

`python3 tools/truth_lane_smoke.py --src` on the 25 targets in
`metadata/truth_lane_targets.json`, Clang 14, Unicorn 2.1.4, arm-none-eabi-gcc 10.3.1 (libgcc).

| | PASS | REVIEW | FAIL |
|---|---:|---:|---:|
| before | 9 | 16 | 0 |
| after | 18 | 7 | 0 |

## What was wrong with the check

1. **Unresolved float helper (the one capped target).** Clang lowers the
   `(int)COERCE_FLOAT(...)` in `rf_timer_toggle_update` to `__aeabi_f2iz`. The
   smoke link ignored unresolved symbols, so the call became `bl 0` and the run
   walked through unmapped memory to the 10,000-instruction cap. `unicorn_smoke.py`
   now links libgcc when `arm-none-eabi-gcc` is installed; the target returns in
   35 instructions. Without ARM GCC the old behavior (cap, REVIEW) remains.
2. **PASS required a peripheral write even where the original makes none.** The
   original-binary run (`aic8800d80_emulator.py verify`) shows that none of the 16
   targets writes a peripheral register from its own body (depth 0) on the
   exercised path. `verify` now also emits `orig_depth0_baseline.json` (tracked copy:
   `metadata/truth_lane_orig_depth0.json`), and a write-free return is a PASS only if
   the original returned, its body wrote no peripheral, **no callee wrote a
   peripheral**, and the reconstruction touched exactly the same peripheral
   addresses. Each row carries a `verdict_basis`. A write that the original body
   does not make is now REVIEW (no such row today).

## Limits of every verdict below

Both sides run one path from a default state; the reconstruction runs with all
callees stubbed to return 0 and usually takes a shorter path than the original.
A PASS means "returns and has the same depth-0 peripheral address footprint as
the original", not equal values, order, return value or behavior. For targets
with an empty footprint the match is that neither side touches a peripheral.

## Per target

Original columns: instructions executed, depth-0 peripheral reads/writes, whether callees wrote peripherals.

| target | image | orig | recon | verdict | reason |
|---|---|---|---|---|---|
| clock_calc @0x1031d8 | fmacfw_h | 29 insns, no callees, reads 0x40100024/0x40500010/0x40500020, 0 writes | returned, same 3 registers read, 0 writes | PASS | Read-only leaf in the original; footprint identical. |
| feature_guard_sdio @0x12eb90 | fmacfw_h | 12 insns, no peripheral traffic | returned, none | PASS | Original touches no peripheral. |
| log_system_init_mode2 @0x10f458 | fmacfw | 4570 insns, no peripheral traffic in body or callees | returned, none | PASS | Original touches no peripheral, callees included. |
| rf_reg_write_wait @0x10f010 | lmacfw_rf | 29 insns, no peripheral traffic | returned, none | PASS | Critical-section wrapper around boot-ROM slot 0x1b4; no peripheral in the original. |
| rf_reg_write_wait @0x10ec30 | fmacfwbt | 29 insns, no peripheral traffic | returned, none | PASS | Same as above. |
| rf_state_check @0x112030 | fmacfwbt | 11 insns, no peripheral traffic | returned, none | PASS | Original touches no peripheral. |
| rf_bus_write2 @0x111524 | lmacfw_rf | 8 insns, reads 0x40200900, 0 writes | returned, reads 0x40200900, 0 writes | PASS | Both take the early return after reading the bus register. The write branches of the body are not exercised by either side. |
| rf_bus_write2 @0x111a78 | fmacfwbt | same | same | PASS | Same as above. |
| rf_mem_read @0x11f594 | lmacfw_rf | 7 insns, no peripheral traffic | returned, none | PASS | Both return at the zero-length guard; the dump loop is not exercised. |
| rf_timer_toggle_update @0x130370 | fmacfw_h | 1670 insns, 0 depth-0 peripheral, callees write 99 registers | returned (was capped: check defect 1), none | REVIEW | Hardware effect is entirely in callees the smoke stubs. |
| rf_mem_write @0x12fd64 | fmacfwbt | 902 insns, 0 depth-0, callees write 0x40032000, 0x40035040 | returned, none | REVIEW | Same: callee-only writes. |
| rf_mem_write @0x12202c | lmacfw_rf | 875 insns, 0 depth-0, callees write 0x40032000 | returned, none | REVIEW | Same. |
| rf_level_apply @0x126dd8 | lmacfw_rf | 1730 insns, 0 depth-0, callees write 98 registers | returned, none | REVIEW | Same. |
| rf_level_apply @0x130514 | fmacfwbt | 685 insns, 0 depth-0, callees write 97 registers | returned, none | REVIEW | Same. |
| rf_cmd_dispatch @0x12fc7c | fmacfwbt | 866 insns, 0 depth-0, callees write 0x40032000, 0x40035040 | returned, none | REVIEW | Same. |
| rf_cmd_dispatch @0x121f44 | lmacfw_rf | 839 insns, 0 depth-0, callees write 0x40032000 | returned, none | REVIEW | Same. |

The smoke found no defect in the 16 target bodies. The linked run below finds defects in callees.

## The 7 REVIEW rows, decided by a linked run

The smoke cannot see callee writes, so `tools/linked_recon_run.py` runs each
target inside the fully linked reconstruction (`tools/full_link.py`, every
callee is the reconstructed body, zero stubs) on the same Unicorn platform and
MMIO model as the original, and compares the complete ordered peripheral
traffic, values included. The reconstructed data keeps the original's absolute
pointers into the image at 0x120000, so the code is linked at 0x800000 and the
original image stays mapped as data; any fetch inside the original image is
reported and makes the row REVIEW (none occurred).

Result for the 7, with the `-O2` build `make -C src check` produces: **1 PASS / 6 FAIL**.
The same 6 fail at `-O0` and `-O1`.

| target | image | original | linked reconstruction | verdict | reason |
|---|---|---|---|---|---|
| rf_level_apply @0x130514 | fmacfwbt | 98 writes | 98 writes | PASS | Identical ordered peripheral reads and writes, values included (0x40342248, then the 0x40342400.. table). |
| rf_level_apply @0x126dd8 | lmacfw_rf | 128 writes | 382 writes (`-O2`), 126 (`-O0`/`-O1`) | FAIL | The 98 RF register writes are identical, values included. The UART log (0x40032000) differs: the original emits `DEBUG: freq=%d, comp_bits=%x\r\n`; the reconstruction emits `D` repeated at `-O2` and the same line without the two `%` at `-O0`/`-O1`. The defect is in the reconstructed formatter path (`rf_parse_cal_cmd` @0x11ebb4, a vsnprintf), and its output depends on the optimization level. |
| rf_mem_write @0x12fd64 | fmacfwbt | 23 writes | does not return | FAIL | Spins in `memmove_5` @0x143f00 before any write. That function is newlib's ARMv7 `strlen` (`uadd8`/`sel`); the decompiled body lost the GE-flag logic and loops on `while ( !HIDWORD(0) )`, which GCC compiles to `b .`. |
| rf_cmd_dispatch @0x12fc7c | fmacfwbt | 23 writes | does not return | FAIL | Same `memmove_5` body. |
| rf_mem_write @0x12202c | lmacfw_rf | 21 writes | does not return | FAIL | Same `strlen` decompile, named `memset_ff` in this image. |
| rf_cmd_dispatch @0x121f44 | lmacfw_rf | 21 writes | does not return | FAIL | Same `memset_ff` body. |
| rf_timer_toggle_update @0x130370 | fmacfw_h | 100 writes | does not return | FAIL | Spins in `hw_poll_status` @0x10df08. Its `while ( *((uint32_t *)off_10DF68 + 7) != 1 )` polls register 0x4010d01c through a non-volatile pointer, so `-O2` reads it once and loops forever; the original reads it three times and goes on. At `-O0` the poll passes and the run then spins in `double_compare_ord`, whose body contains a Hex-Rays `JUMPOUT`. |

These are defects in reconstructed callee bodies, not in the 7 target bodies.
None is fixed here: the bodies are Hex-Rays output, a correct replacement needs
a re-decompile (IDA) or a pipeline rule, and hand-written C is not allowed.

### All 25 targets in the linked run

`--all` runs every target. It is a stricter comparison than the smoke (ordered
writes with values, callees included) and it shows a second, wider defect:

| build of `src/` | PASS | REVIEW | FAIL |
|---|---:|---:|---:|
| `-O2` (the `make -C src check` build) | 14 | 0 | 11 |
| `-O0` | 19 | 0 | 6 |

The 5 extra `-O2` failures are smoke PASS rows: `rf_hw_timer_init` ×2,
`crypto_hw_enable` ×2 and `crypto_key_load`. The source accesses registers
through plain pointers, so `-O2` merges and reorders writes to one register
(`crypto_hw_enable`: the original writes 0x40344094 four times, 0x0, 0x0, 0x40,
0x50; the `-O2` build writes 0x0, 0x50). At `-O0` all five match the original
write for write. The smoke PASS for them stands as defined (same addresses) and
is no evidence about values or order. At `-O0` `full_link.py` adds two return-0
stubs (`__pld`, `JUMPOUT`), so that build is a diagnostic, not a gate.

### Limits

One path from a default state (zeroed RAM, boot callbacks stubbed) per target.
A PASS is an identical peripheral sequence on that path, not behavioral
equivalence. The 52 to 173 `.bss` blobs `full_link.py` substitutes for
decompiler data symbols are link scaffolding, not original addresses.

## Reproduce

```
python3 tools/aic8800d80_emulator.py verify --targets metadata/truth_lane_targets.json --out /tmp/orig
cp /tmp/orig/orig_depth0_baseline.json metadata/truth_lane_orig_depth0.json   # only when the emulator or targets change
python3 tools/truth_lane_smoke.py --src --out /tmp/tls
python3 tools/truth_lane_smoke.py --src --orig-baseline /nonexistent --out /tmp/tls_old_rule   # former rule: 9/16/0
python3 -m unittest tools/test_truth_lane.py

make -C src check                      # add OPT=-O0 for the diagnostic build
python3 tools/full_link.py --text-base 0x800000 --out build/full_link_run
python3 tools/linked_recon_run.py --out /tmp/linked            # the 7; --all for all 25
```
