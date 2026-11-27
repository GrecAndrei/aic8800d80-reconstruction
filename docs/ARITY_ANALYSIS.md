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

## Machine-validated repair pass (2026-11-27)

The syntactic under-arity scan is a triage signal, not a verdict: Hex-Rays both
invents unused parameters and drops real register forwarding. The correct
procedure is per-site machine evidence. Since the original note above, the
following classes were proven against the original binaries and repaired:

* zero-input fmac scheduler/dispatcher clones (`rf_is_idle`/`rf_calib_init` and
  `rf_get_flag`/`read_state_flag`/`bt_ctrl_main_task`);
* one-input list and packet-status helpers whose second Hex-Rays parameter is
  register scratch rather than an input;
* explicit first-argument forwarding in DMA completion callbacks;
* three-argument packet helper forwarding `(a1, v4, v6)` in TX completion/setup;
* frame-pair forwarding `(_frame.v2, _frame.v3, 0)` in event dispatchers;
* connection-table entry forwarding in message builders;
* configuration-halfword inputs to rate-code helpers;
* packet-object inputs to PHY/PLL status helpers;
* current-character inputs in packet scan loops;
* current-list-node forwarding `(v10)` / `(v17)` in the three scheduler loops;
* zero-input fault/NVIC status helpers and command-queue/ioctl event helpers whose
  machine bodies overwrite every argument register before use.

After those repairs the remaining syntactic census is fmacfw_h 13 functions /
15 call rows, fmacfw 14 / 16, fmacfwbt 13 / 15, and lmac 0 / 0. Remaining rows
are still unproven candidates. In particular `bt_conn_is_connected` and its
clones genuinely consume r1-r3, so their four-input prototypes must not be
"narrowed" merely because the scan is nonzero; their missing call-site argument
requires caller-level machine reconstruction. Conversely zero-machine-input
rows may be pass-through artifacts and require callee+caller analysis.
