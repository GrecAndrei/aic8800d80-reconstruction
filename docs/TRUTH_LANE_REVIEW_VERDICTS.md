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

No defect in the reconstructed source was found for any of the 16; nothing under `src/` changed.

## Why the 7 REVIEW rows stay open

A single-function smoke with stubbed callees cannot see their peripheral writes,
and nothing in the body itself can be compared against the original. Deciding
them needs the reconstruction's callee chain executed for real: a linked,
non-stubbed run of `src/` under the same platform model as the original (no such
harness exists here), or a hardware trace. IDA is not required for that, and was
not available.

## Reproduce

```
python3 tools/aic8800d80_emulator.py verify --targets metadata/truth_lane_targets.json --out /tmp/orig
cp /tmp/orig/orig_depth0_baseline.json metadata/truth_lane_orig_depth0.json   # only when the emulator or targets change
python3 tools/truth_lane_smoke.py --src --out /tmp/tls
python3 tools/truth_lane_smoke.py --src --orig-baseline /nonexistent --out /tmp/tls_old_rule   # former rule: 9/16/0
python3 -m unittest tools/test_truth_lane.py
```
