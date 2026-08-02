# Full-Link (non-gc) Undefined-Symbol Analysis

**Date:** 2026-08-02
**Tool:** `tools/analyze_full_link_undefs.py` (reproducible)
**Decision:** **Keep `--gc-sections` reachability as the link gate.**

## Question

The unified pipeline compiles each image to one object and links reachable
code with `--gc-sections --entry=start` (4/4 ELFs, zero undefs). Without
gc-sections every function is kept, so the objects still reference symbols
with no definition in the image. Are those undefs phantom LLM names / real
missing code, and should the gate change?

## Method

1. `arm-none-eabi-nm -u <img>.o` -> undefined symbols per image.
2. `__aeabi_*` -> float helpers (need `-lgcc`), not missing code.
3. Remaining names are looked up in the LLM naming dataset
   (`harness_v17/names/*.json`). The dataset is normalized: image name
   stripped of `_bin`, and addresses converted from the mixed chip/v14
   space (`chip = v14 - 0x1100000`, choosing the candidate inside the
   image code range).
4. A name that resolves to an address *inside* a composed function
   (scan-table boundaries, `harness_v25/out/*_bin_funcs.jsonl`) is a
   **naming artifact**: the old v17 function boundaries named mid-function
   or data-tail addresses, and call sites kept those names while the
   composed definition lives under the real function name.

## Breakdown (421 undefs across 4 images)

| Category                     | Count |  %    | Meaning |
|------------------------------|------:|------:|---------|
| naming_artifact              |   243 | 57.7% | name points inside a composed function; code exists |
| no_mapping                   |    95 | 22.6% | no dataset entry; mix of data-symbol-as-function decompile artifacts and a handful of genuine calls |
| __aeabi_float                |    62 | 14.7% | float ops need `-lgcc` |
| cross_image                  |     7 |  1.7% | genuine calls into another firmware image |
| sub_star_gap                 |     6 |  1.4% | real unnamed functions referenced but not reconstructed (**actual gaps**) |
| artifact                     |     6 |  1.4% | `MEMORY`, `COERCE_UNSIGNED_INT`, `memmove` (decompiler/type noise) |
| rename_mismatch              |     2 |  0.5% | call-site name differs from the composed definition name |

Real missing code is **~8 (1.9%)** (the six `sub_*` gaps plus two rename
mismatches), with a further subset of `no_mapping` (e.g. `bt_chan_parse`,
`rf_bus_reset_helper`, `rf_cmd_send_2`) being genuine call sites — the rest
of `no_mapping` are `log_free_dispatch_*`/`message_dispatch_*` data symbols
the decompiler emitted as function references (used as `(void *)(name)` /
`*(uint32_t *)name`, not real calls).

## Why the gate stays

- The gc link already proves the reconstruction is internally consistent:
  every reachable call has a definition.
- The non-gc undefs are ~92% naming/address/decompiler artifacts plus
  libgcc float helpers — not missing code. A non-gc gate would require
  `-lgcc` and stub symbols for thousands of artifact names without adding
  correctness signal.
- The genuine gaps are small and are tracked as concrete work: the six
  `sub_*` functions, and the handful of real `no_mapping` call sites.
  These are naming/reconstruction bugs, not a reason to change the gate.

## Reproduce

```bash
make -C src check
python3 tools/analyze_full_link_undefs.py          # uses existing src/*.o
python3 tools/analyze_full_link_undefs.py --rebuild # recompile first
```

## Related

- Naming-duplicate cleanup (same root cause as most `naming_artifact`
  undefs): see AGENTS.md next-work item 3.
