# harness_v25 — Unified Structure Analysis (fwstruct)

The unified Go tool for analyzing AIC8800D80 firmware structure.
Builds on v19's decompiled C output to extract per-function structural
detail: callees, access patterns, numeric literals, struct candidates,
cross-binary diffs, and the boot init path.

This layer **supersedes the v20-v24 Python harnesses**. Those scripts
remain in the tree as historical reference and for cross-validation,
but new work should use `fwstruct`.

## Quick start

```bash
# 1. Make sure v19 decompilation has produced harness_v19/decompiled/<img>/*.c
ls harness_v19/decompiled/

# 2. Run the full analysis pipeline
bin/fwstruct scan       # parse v19 C → <out>/<img>_funcs.jsonl
bin/fwstruct structs    # cluster by access pattern → <out>/<img>_clusters.json
bin/fwstruct names      # LLM-name clusters (needs API keys)
bin/fwstruct callgraph  # build call graph → <out>/<img>_callgraph.json
bin/fwstruct magic      # classify numeric literals → <out>/<img>_magic.json
bin/fwstruct initpath   # extract boot path from start() → <out>/<img>_initpath.json
bin/fwstruct diff       # cross-binary diff → <out>/diff_<a>_vs_<b>.json
```

Default output dir is `harness_v25/out/`. Override with `--out <dir>`.

## Subcommands

| Command | Status | Purpose |
|---------|--------|---------|
| `scan`       | implemented | Parse v19 decompiled `.c` files into per-function JSONL |
| `structs`    | implemented | Cluster functions by access pattern (base+offset fingerprint) |
| `names`      | implemented | Send clusters to LLM for naming (`mmio_clock_gate`, `tx_pkt_buf`, ...) |
| `xref`       | TODO        | Cross-reference struct fields to named functions |
| `callgraph`  | implemented | Build call graph from C source |
| `magic`      | implemented | Classify numeric literals (bit_masks, timeouts, sizes, etc) |
| `initpath`   | implemented | Walk BFS from `start()` to enumerate the boot init chain |
| `diff`       | implemented | Compare same-address functions across the 4 binaries |
| `types`      | TODO        | Fix Hex-Rays type-inference bugs in v19 output |
| `ivt`        | TODO        | Rewrite IVT for v18 bootable WFFW |
| `annotate`   | TODO        | Emit annotated C with all known context (supersedes v23) |
| `report`     | TODO        | Aggregate summary across all subcommands |
| `all`        | TODO        | Run the full pipeline (scan..annotate) in one shot |

## Output schema

Each binary gets a set of JSON/JSONL files in `<out>/`:

```
<out>/
├── <image>_funcs.jsonl         # one JSON per function:
│                                 #   address, name, n_lines, n_gotos, n_returns,
│                                 #   callees[], accesses[{base,offset,size,direction}],
│                                 #   literals[]
├── <image>_clusters.json       # clustered by primary-arg access pattern
├── <image>_callgraph.json      # {func: [callees]}
├── <image>_magic.json          # numeric literal classification
├── <image>_initpath.json       # boot init chain from start()
├── diff_<a>_vs_<b>.json        # cross-binary diff (identical/modified/added/removed)
└── structs_summary.json        # aggregate cluster count across all binaries
```

## Inputs

`fwstruct scan` reads from `harness_v19/decompiled/<img>/<addr>_<name>.c`.
The filename format is what v19 emits — addr is the function address in
hex, name is either the LLM-applied name or `sub_<addr>`.

To re-scan a different decompiled dir, pass `--decompiled <dir>`.

## Build

```bash
go build -o bin/fwstruct ./cmd/fwstruct
```

Source is in `cmd/fwstruct/` (9 files, ~1,400 LoC) plus
`internal/decompile/`, `internal/llm/`, and `internal/structs/`.

## LLM calls

`fwstruct names` requires API keys. Place `*.key` files in a directory
and pass `--llm-key-dir <dir>`. Defaults to the `MiniMax-M3` model
with 4 concurrent calls. Same LLM provider stack as v17 (tokenrouter
endpoint, 1M context).

## Differences from v20-v24

The Python harnesses `harness_v20` through `harness_v24` produced
equivalent outputs in JSON via `radare2` disassembly. `fwstruct`
parses v19's Hex-Rays C directly (no r2 round-trip), runs in Go
(no Python startup cost), and unifies 12 analyses behind one CLI.

When both produce outputs, the Go version is faster and the schemas
are simpler. The Python outputs remain in git as historical artifacts.

## See also

- `harness_v19/README.md` — v19 decompilation pipeline (input to fwstruct)
- `harness_v17/README.md` — LLM tool-use pipeline (alternative naming path)
- `cmd/fwstruct/main.go` — subcommand dispatch table
- `internal/decompile/parser.go` — v19 C parser (Func struct, regex-based)