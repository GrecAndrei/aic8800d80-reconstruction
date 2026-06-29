# v22 — Expanded Struct Names (historical)

> **⚠️ Historical. Superseded by v25 `fwstruct names`.**
> The unified `fwstruct` tool (Go binary in `bin/fwstruct`, source in
> `cmd/fwstruct/`) now does struct naming via `fwstruct names` (LLM
> call against cluster access patterns). See `harness_v25/README.md`.

## Goal

Build on v20/v21 by asking the LLM for MORE struct names,
using the v21 cluster cross-reference as additional context.

## What v22 adds

v22 has 14 NEW struct names beyond v20's 8:
- v19: 6 known (vif_info, tx_queue, rx_desc, tx_desc, ke_env, scan_req)
- v20: 8 new (delay_timer, mmio_clock_gate, ke_dispatch_ctx, vif_bssid_ref,
        vif_set_state_req, bt_hci_cmd, mmio_reg_poll, tx_pkt_buf)
- v22: 14 new (irq_prio_set, bitmask_state, rf_state, ipc_shared_buf,
              rf_chan_cfg, log_state, phy_reg_param, rf_param_tbl,
              irq_status, rf_stream, rf_subsys, rf_calib_tbl)

**Total: 26 struct definitions, 106 cross-binary clusters, 52 named**

## Results

Cross-binary cluster naming status:

| Binary | Clusters | Named | % named |
|--------|----------|-------|---------|
| fmacfw_8800d80_h_u02 | 15 | 11 | 73% |
| fmacfw_8800d80_u02 | 32 | 14 | 44% |
| fmacfwbt_8800d80_u02 | 33 | 14 | 42% |
| lmacfw_rf_8800d80_u02 | 26 | 13 | 50% |
| **Total** | **106** | **52** | **49%** |

Top 10 named structs by total funcs:
- mmio_clock_gate: 5 instances, 105 funcs
- delay_timer: 4 instances, 92 funcs
- bt_hci_cmd: 3 instances, 64 funcs
- ke_dispatch_ctx: 6 instances, 46 funcs
- vif_set_state_req: 3 instances, 30 funcs
- tx_pkt_buf: 4 instances, 24 funcs
- phy_reg_param: 3 instances, 18 funcs
- ipc_shared_buf: 3 instances, 14 funcs
- rf_subsys: 1 instance, 12 funcs
- log_state: 2 instances, 8 funcs

## Pipeline

```
v20 access patterns + clusters (per-binary)
  +
v20 LLM proposals (8 names)
  +
v21 cluster xref (per-binary)
  |
  v
v22 llm_name_more.py - 2-turn LLM call for next 20 clusters
  - Turn 1: 1-line name per cluster
  - Turn 2: full struct with field names
  |
  v
v22/structs/named.json (14 unique new names)
  +
v22/structs/aic8800d80_v22_structs.json (26 combined)
  +
v22/structs/aic8800d80_v22.h (C header)
  |
  v
v22 re_xref.py - re-run cross-reference with all 26 names
  |
  v
v22/field_map/<img>_cluster_xref.json (52 named clusters)
  +
v22/SUMMARY.json (cross-binary aggregate)
```

## Usage

```bash
# After v20/v21 built:
python3 harness_v22/scripts/llm_name_more.py
python3 harness_v22/scripts/re_xref.py
cat harness_v22/SUMMARY.json

# Use the combined header:
cat harness_v22/structs/aic8800d80_v22.h
```

## Limitations

- Still 49% named (52/106). Unnamed are mostly minor variations or stack-locals
- LLM occasionally proposes duplicate struct names (e.g., mmio_clock_gate twice)
- v22 includes v20's old names but v20 didn't track which names came from v19 known

## What's next: v23

- LLM refinement of duplicate/conflicting names
- Use v22 named structs to actually annotate v19 decompiled C
  (e.g., replace `*(_DWORD *)(v5 + 0x8)` with `vif->mac_addr`)
- Identify "ghost" struct fields (offsets that LLM doesn't name but are touched)
