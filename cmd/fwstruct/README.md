# fwstruct — Unified Firmware-Structure Analyzer

`fwstruct` is the Go-based replacement for the v20–v25 Python one-off scripts.
It is a single binary with subcommands, designed to be:

- **Stateless**: each subcommand reads prior outputs and writes new ones
- **Re-runnable**: skip already-done work; re-run only changed steps
- **Composable**: chain subcommands for full pipeline
- **Testable**: pure functions where possible; no global state

## Subcommands

| Command | What | Input | Output |
|---------|------|-------|--------|
| `scan` | Parse v19 C into per-func JSONL | `harness_v19/decompiled/<img>/*.c` | `<out>/<img>_funcs.jsonl` |
| `structs` | Cluster funcs by access pattern | funcs.jsonl | `<out>/<img>_clusters.json` |
| `names` | LLM-name clusters | clusters + LLM keys | `<out>/<img>_named.json`, `proposals.json` |
| `xref` | Per-field reader/writer counts | funcs + clusters | `<out>/<img>_xref.json` |
| `callgraph` | Per-image call graph | funcs.jsonl | `<out>/<img>_callgraph.json` |
| `magic` | Classify numeric literals | funcs.jsonl + mmio DB | `<out>/<img>_magic.json` |
| `initpath` | BFS from start() | callgraph | `<out>/<img>_initpath.json` |
| `diff` | Cross-binary version diff | funcs.jsonl × 2 | `<out>/diff_<a>_vs_<b>.json` |
| `types` | Fix Hex-Rays type bugs | decompiled C | `<out>/types_fixed/<img>/*.c` |
| `ivt` | Rewrite IVT for v18 bootable | original WFFW + v18 WFFW | `<out>/ivt/<img>_ivt_v18.bin` |
| `annotate` | Annotate C with struct types | decompiled C + clusters + named | `<out>/annotated/<img>/*.c` |
| `report` | Aggregate summary | all prior outputs | `<out>/report.json` |
| `all` | Run scan..annotate | — | — |

## Usage

```sh
# Build
go build -o /tmp/fwstruct ./cmd/fwstruct

# Run the full pipeline (no LLM)
fwstruct all --verbose

# Run with LLM naming
fwstruct scan --verbose
fwstruct structs --verbose
fwstruct names --llm-key-dir /etc/llm-keys --concurrency 8
fwstruct xref --verbose
fwstruct annotate --verbose

# Per-subcommand help
fwstruct scan --help
```

## Architecture

```
cmd/fwstruct/                 entry points
  main.go                     subcommand dispatcher
  common.go                   shared flags + helpers
  scan.go                     parse v19 C
  structs.go                  cluster by access pattern
  names.go                    LLM naming
  xref.go                     field cross-reference
  callgraph.go                call graph
  magic.go                    literal classification
  initpath.go                 boot path BFS
  diff.go                     version diff
  types.go                    Hex-Rays type fix
  ivt.go                      IVT rewrite
  annotate.go                 C annotation
  report.go                   aggregate report
  all.go                      chain all subcommands

internal/decompile/           v19 C parser
  parser.go                   regex-based line parser
  parser_test.go              unit test

internal/structs/             struct recovery
  structs.go                  cluster + field xref
  args.go                     arg-register helpers

internal/llm/                 LLM client
  client.go                   MiniMax-M3 client
  naming.go                   struct naming prompt + parser

internal/types/               type-inference fix
  fix.go                      array_index, func_ptr_call

internal/ivt/                 IVT rewrite
  ivt.go                      parse, rewrite, apply
```

## Why Go

The user requested no more one-off Python scripts. Go gives us:

- **Single static binary** — no Python interpreter, no venv
- **Type safety** — refactor with confidence
- **Fast** — 10x speedup on large inputs
- **Composability** — `fwstruct scan | fwstruct structs` is just chaining binaries
- **Same style as the rest of the repo** — `cmd/fwcycle`, `cmd/fwmega`, `cmd/fwrecon`, etc.

## Replaces

This binary replaces the following Python one-offs:

- `harness_v20/scripts/*.py` (struct recovery) → `structs` + `xref` + `names`
- `harness_v21/scripts/*.py` (field xref)        → `xref`
- `harness_v22/scripts/*.py` (more naming)      → `names`
- `harness_v23/scripts/*.py` (annotation)       → `annotate`
- `harness_v24/scripts/*.py` (cross-binary)     → `diff`
- `harness_v25/v25_1_magic/magic_decode.py`     → `magic`
