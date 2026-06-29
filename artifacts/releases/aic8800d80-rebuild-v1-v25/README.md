# aic8800d80-rebuild-v25

Unified structure analysis via `fwstruct` — Go-based parser of v19's
Hex-Rays decompiled C. Produces per-function metadata (callees, access
patterns, numeric literals, struct candidates, boot init path,
cross-binary diff) for all 4 firmware binaries.

## Status

Built by `cmd/fwstruct` running all 13 subcommands end-to-end.

| Item                 | Count |
|----------------------|------:|
| Functions analyzed   | 5,945 |
| Clusters identified  | 1,394 |
| LLM-named structs    | 0 (requires API keys, run `fwstruct names` separately) |
| Types rewritten      | 5,535 |
| Xref fields          | 12,821 |
| IVT handlers named   | ~20-80 per binary |
| Init-path max depth  | 0 (function-pointer indirection in the boot chain) |

## What's in here

- `out/<img>_funcs.jsonl` — per-function metadata
- `out/<img>_callgraph.json` — callees map per function
- `out/<img>_initpath.json` — boot init chain categorized by depth
- `out/<img>_clusters.json` — access-pattern clusters
- `out/<img>_magic.json` — numeric literal classification
- `out/<img>_xref.json` — struct field cross-reference (per cluster)
- `out/<img>_ivt.json` — IVT entries with handler names
- `out/<img>_types/` — per-func .c with MSVC types rewritten to C99
- `out/<img>_annotated/` — per-func .c with cluster context header
- `out/_report.json` — aggregate summary across all images

## Reproduction

```bash
# One command produces the entire dataset above
bin/fwstruct all

# Or run individual subcommands:
bin/fwstruct scan         # parse v19 decompiled C -> funcs.jsonl
bin/fwstruct callgraph    # build call graph
bin/fwstruct initpath     # walk boot init chain from start()
bin/fwstruct types        # rewrite MSVC types to C99
bin/fwstruct ivt          # parse Cortex-M IVT
bin/fwstruct xref         # struct field cross-reference
bin/fwstruct report       # aggregate summary
bin/fwstruct diff -a IMG1 -b IMG2   # cross-binary comparison
```

## v25 philosophy

`fwstruct` is a pure deterministic parser over v19's Hex-Rays output.
No LLM calls in the default pipeline (`names` is optional and separate).
All outputs are reproducible from the v19 decompiled C — re-running
`bin/fwstruct all` produces byte-identical results.

Unlike v15-v18 which produced C source, v25 produces machine-readable
metadata suitable for downstream analysis (call graph traversal, struct
typing, cross-binary diffing, init-path enumeration).

## Limitations

- `init_depth_max` is 0 for all binaries because the boot chain starts
  with `start()` calling `off_1001FC` (function pointer), which the BFS
  treats as no-depth indirection.
- LLM-named struct candidates require API keys and re-run
  (`bin/fwstruct names --llm-key-dir <dir>`).
- The `annotated` output only includes the cluster_id header; richer
  annotation (struct field types in the body) needs a downstream tool
  consuming the xref + types outputs together.

## See also

- `harness_v19/` — input to fwstruct (v19 decompiled C)
- `harness_v25/README.md` — full subcommand reference
- `PIPELINE.md` — how v25 fits into the overall pipeline