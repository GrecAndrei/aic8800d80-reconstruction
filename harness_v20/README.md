# v20 — Struct Recovery from Access Patterns (historical)

> **⚠️ Historical. Superseded by v25 `fwstruct`.**
> The unified `fwstruct` tool (Go binary in `bin/fwstruct`, source in
> `cmd/fwstruct/`) now does struct discovery in one step:
>
> ```bash
> bin/fwstruct scan       # per-func metadata
> bin/fwstruct structs    # access-pattern clusters
> bin/fwstruct names      # LLM-named struct candidates
> ```
>
> See `harness_v25/README.md` for the current pipeline. The Python
> scripts in this directory remain for cross-validation against the
> r2-based access-pattern extraction (different parser, same idea).

## Goal

Reverse-engineer the AIC8800D80 firmware's internal struct types
**mechanically** from disassembly, without guessing addresses by hand.

The previous layers (v15, v17, v18, v19) all produced decompiled C
without knowing what the structs look like. v20 fills that gap by:

1. Disassembling every function in v19 with r2
2. Extracting every load/store pattern (`ldr r0, [r4, #0xc]`, `strb r1, [r0]`, ...)
3. Grouping accesses by base register + offset
4. Clustering functions with similar access patterns
5. Asking the LLM to propose struct field names from the clusters
6. Cross-referencing with v19's known struct definitions

## Pipeline

```
v19 decompiled names (4,675 funcs)
       |
       v
extract_access_patterns.py (r2 per func, 4 workers parallel)
       |
       v
access_patterns/<img>_patterns.json (1,290-1,741 funcs, 18-31K accesses)
       |
       v
group_structs.py (group by base+offset, count occurrences)
       |
       v
structs/<img>_structs.json (40-45 struct candidates per binary)
       |
       v
cluster_structs.py (cluster funcs by primary-arg fingerprint)
       |
       v
structs/<img>_clusters.json (15-33 significant struct groups)
       |
       v
llm_propose_structs.py (LLM proposes struct names from 20 top patterns)
       |
       v
structs/proposals_v4.json (8 LLM-named structs)
       |
       v
aic8800d80_v20.h (combined v19 + v20 struct definitions)
       |
       v
SUMMARY.json (cross-binary results)
```

## Results (4 binaries)

| Binary | Functions | Accesses | Struct candidates | Significant clusters |
|--------|-----------|----------|-------------------|---------------------|
| fmacfw_8800d80_h_u02 | 1,290 | 22,383 | 44 | 15 |
| fmacfw_8800d80_u02 | 1,735 | 30,472 | 45 | 32 |
| fmacfwbt_8800d80_u02 | 1,741 | 30,668 | 44 | 33 |
| lmacfw_rf_8800d80_u02 | 1,179 | 17,940 | 40 | 24 |

**Total**: 5,945 functions, 101,463 load/store accesses analyzed,
4 binaries, ~40-45 struct candidates each.

## LLM-proposed struct names (8)

From the most-frequent cross-binary access fingerprints:

| Struct | Fields | Functions (sum across 4 binaries) |
|--------|--------|-----------------------------------|
| `delay_timer` | us, ticks | 198 |
| `mmio_clock_gate` | bit, addr | 117 |
| `ke_dispatch_ctx` | handler, arg, next, state | 83 |
| `vif_bssid_ref` | vif, bssid | 43 |
| `vif_set_state_req` | vif_idx, flags, mac, bssid, op, state | 40 |
| `bt_hci_cmd` | ogf, ocf | 38 |
| `mmio_reg_poll` | addr, mask, val, expected, ret | 33 |
| `tx_pkt_buf` | addr, len, ctrl, bssid, payload_end | 30 |

These supplement the v19 known structs:
`vif_info`, `tx_queue`, `rx_desc`, `tx_desc`, `ke_env`, `scan_req`.

## Cross-binary consistency

The same 4-5 most-frequent struct fingerprints appear in ALL 4 binaries:

```
[(+0, 4), (+4, 4)]                -> stack frame pair       (198 funcs total)
[(+0, 1), (+0, 4)]                -> overlapping byte+word  (117 funcs)
[(+0,4), (+4,4), (+8,4), (+c,4)]  -> 4-pointer struct       (83 funcs)
[(-8, 4), (+0, 4)]                -> prev+next linked list  (23 funcs)
[(+0,4), (+4,4), (+8,4), (+e,4), (+320,4)] -> large struct (30 funcs)
```

This confirms the firmware shares code paths across the 4 binaries
(WiFi host, WiFi upper, Bluetooth, RF) and uses common internal types.

## Usage

```bash
# Step 1: extract all access patterns (~3 min total, 4 workers)
python3 harness_v20/scripts/extract_all.py

# Step 2: group by base register + offset
python3 harness_v20/scripts/group_structs.py

# Step 2.5: cluster functions by primary-arg fingerprint
python3 harness_v20/scripts/cluster_structs.py

# Step 3: LLM proposes struct names (~$0.05)
python3 harness_v20/scripts/llm_propose_structs_v4.py

# Step 4: generate combined struct header
python3 harness_v20/scripts/annotate_v19.py  # produces SUMMARY.json
```

## How to use the struct header

The file `structs/aic8800d80_v20.h` has 14 struct definitions
(6 v19 known + 8 v20 new). Use it to interpret the v19 decompiled C:

```c
// From v19 decompiled:
int v6 = *(_DWORD *)(v5 + 4);  // flags?
*(_DWORD *)(v5 + 8) = v6;      // mac_addr?

// With v20 header:
struct vif_info *vif = (struct vif_info *)v5;
vif->flags = vif->mac_addr;
```

The struct header is **not** directly compilable; it's a documentation
artifact for human reading. To make v19 decompilations compile with
the structs, you'd need to also re-run v19 Hex-Rays with the structs
applied in IDA (this is in v20/ida_setup_v20.py but currently brittle).

## Limitations

- Stack locals (sp-arg) dominate the top patterns - they aren't real structs
- Some structs span 800+ bytes (vif_info) - probably sub-structs
- LLM proposed 8 new names but ~30 more significant clusters remain unnamed
- Struct injection in IDA is brittle (parse_decl API quirk)
- Access patterns only cover ldr/str with #imm - not ldr r0, [r0, r1] indexed

## What's next: v21

- Use [r-base+indexed-offset] patterns for array elements
- Identify struct inheritance (overlapping structs at same base)
- Cross-link struct field access with LLM-named functions
- Add stack-var recovery (v20 currently only handles args)
