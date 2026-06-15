# v25: Unified Firmware Structure Analysis

`v25` is the analysis layer of the project. It builds on v19 (Hex-Rays
decompiled C) and v22 (named structs) to produce structured deliverables.

The analysis is driven by `fwstruct` (in `cmd/fwstruct/`), a Go binary
with 13 subcommands. This replaces the v20-v24 Python one-off scripts.

## Quick start

```sh
# Build
go build -o /tmp/fwstruct ./cmd/fwstruct

# Run the full pipeline
fwstruct all --verbose

# Or run individual subcommands
fwstruct scan
fwstruct structs
fwstruct callgraph
fwstruct magic
fwstruct initpath
fwstruct diff --a=fmacfw_8800d80_h_u02_bin --b=fmacfw_8800d80_u02_bin
fwstruct types
fwstruct ivt
fwstruct annotate
fwstruct report
```

## What v25 produces

Located in `harness_v25/out/`:

- `<img>_funcs.jsonl` — per-function metadata (callees, accesses, literals)
- `<img>_clusters.json` — funcs grouped by struct access fingerprint
- `<img>_callgraph.json` — caller/callee map + top hubs
- `<img>_magic.json` — classified numeric literals
- `<img>_initpath.json` — BFS depth from start() + categories
- `<img>_xref.json` — per-field reader/writer counts
- `diff_<a>_vs_<b>.json` — version diff
- `types_summary.json` — type-fix stats
- `report.json` — aggregate summary
- `annotated/<img>/*.c` — annotated C files (cluster + struct)
- `types_fixed/<img>/*.c` — type-inference-fixed C files
- `ivt/<img>_ivt_v18.bin` — v18 WFFW with rewritten IVT

## Stats from latest run

| Metric | Value |
|--------|-------|
| Total funcs | 5,945 |
| Total clusters | 1,394 |
| Clustered funcs | 1,525 (26%) |
| Total literals | 6,029 |
| Type fixes | 17,291 (array_index) |
| IVT images patched | 4 |
| Images | fmacfw_h, fmacfw_u02, fmacfwbt, lmacfw_rf |

## Subcommand details

See `cmd/fwstruct/README.md` for the full subcommand table and
architecture diagram.
