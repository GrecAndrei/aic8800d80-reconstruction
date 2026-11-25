# Width-aware arity analysis (2026-11-25)

## Method
`tools/arity_scan.py` compares machine-proven input registers (conservative
prologue scan in `tools/prototype_infer.py`) against the register-carrying
capacity of each composed prototype (64-bit types occupy pairs).

## Artifact classes eliminated with machine validation
1. `push.w {r3, ...}` wide-encoding register saves read r3 without semantic
   input meaning (fixed in prototype_infer).
2. `pop {r3}` return-address stack tricks DEFINE r3; treating pops as pure
   skips fabricated input evidence (fixed — pop write-effects recorded).
3. Register-pair artifact: 64-bit arguments occupy r0:r1, so call sites pass
   fewer C arguments than registers; the scan must compare against capacity,
   not parameter count.
4. Dead copies: `ble_ll_conn_get`/`rf_config_chan_table` copy r2 to r8 at the
   entry but never consume r8 anywhere in the body — real input evidence but
   semantically dead register allocation, not a prototype defect.
5. Boundary garbage: `bt_get_conn_entry` is a mid-function fallthrough
   continuation (no prologue), `bt_reg_write` a data table misidentified as
   code — separate boundary-integrity class, not arity defects.

## Result
203 raw candidates collapsed to a handful of genuine-looking cases
(hci_tx_alloc stages `movs r1, r3` as a callee argument — a probable real
passthrough input). Each genuine case requires per-function manual
reconstruction: the decompiled bodies were emitted against the wrong
prototype, so repairing the prototype alone does not express the missing
dataflow. Low blast radius; deferred behind corpus-level defects.

## Raw data
`metadata/arity_defects.json` (width-adjusted), `metadata/under_arity_sites.jsonl`.
