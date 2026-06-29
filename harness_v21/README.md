# v21 — Struct Field Access Cross-Reference (historical)

> **⚠️ Historical. Superseded by v25 `fwstruct xref`.**
> The unified `fwstruct` tool (Go binary in `bin/fwstruct`, source in
> `cmd/fwstruct/`) now provides cross-reference as `fwstruct xref`
> (currently TODO — pipeline still works through v22's re_xref.py).
> See `harness_v25/README.md` for the current state.

## Goal

For each LLM-proposed struct, identify which named firmware functions
read or write each field. This is the "call graph" for data structures
in the firmware.

## Pipeline

```
v19 LLM-named functions (1,256 across 4 binaries)
  +
v20 access patterns (per-function load/store fingerprints)
  +
v20 clusters (group funcs by struct access fingerprint)
  +
v20 LLM struct proposals (8 named structs)
  |
  v
v21 cross_reference_v2.py
  - For each cluster, find ALL funcs matching its fingerprint
  - For each field in the cluster, list readers/writers
  - Attach LLM struct name by fingerprint match
  |
  v
v21/field_map/<img>_cluster_xref.json (per-binary reports)
  +
v21/SUMMARY.json (cross-binary aggregate)
```

## Results

**6 unique named structs across 18 cluster instances, 290 total funcs:**

| Struct | Cluster instances | Total funcs touching | All images |
|--------|------------------|---------------------|------------|
| `mmio_clock_gate` | 4 | 95 | yes (all 4) |
| `tx_pkt_buf` | 4 | 24 | yes (all 4) |
| `delay_timer` | 3 | 73 | yes (3/4) |
| `bt_hci_cmd` | 3 | 64 | yes (3/4) |
| `vif_set_state_req` | 3 | 30 | yes (3/4) |
| `vif_bssid_ref` | 1 | 4 | partial |

## Sample cross-reference (fmacfwbt `vif_set_state_req` cluster)

Field writers (functions that set fields on the struct):
- `sub_101874` — sets mac, bssid
- `sub_101878` — sets mac, bssid
- `fmacfwbt_init_or_handler` — sets all fields (init)
- `sub_10184C`, `sub_10186C` — set flags, bssid

Field readers (functions that consume the struct):
- `sysctl_chip_id_get` — reads +0 (idx?)
- `fmacfwbt_init_or_handler` — reads for further init
- `sub_10184C`, `sub_101874` — read during vif setup

## Why this is useful

Before v21, we had:
- v19 decompiled C (human-readable but no struct types)
- v20 struct definitions (offsets + names)
- v20 clusters (which funcs use which offsets)

After v21, we have the JOIN:
- **For each struct field, the actual firmware functions that touch it**
- This means a developer can read the v19 C, look up "what function sets vif_info.ssid?",
  and get a list of 3-5 named candidates

## Usage

```bash
# After v20 is built:
python3 harness_v21/scripts/cross_reference_v2.py
python3 harness_v21/scripts/attach_llm_names.py
cat harness_v21/SUMMARY.json
```

## Limitations

- v20's LLM proposed 8 names, only 6 made it into clusters (others were trivial or stack-local)
- Only 18/106 cross-binary clusters got LLM names (need to ask LLM for more)
- Per-field reader/writer lists are limited to 10 each (need full enumeration)
- Cross-reference is by LLM function name match, which is best-effort

## What's next: v22

- Ask LLM for more struct names (the remaining 88 unnamed clusters)
- Build per-field "read-write invariants" (e.g., "vif_info.ssid is only written before state=CONNECTED")
- Cross-link v21 with v17's call graph (v17 has 75 oracle reports)
