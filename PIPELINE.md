# Firmware Extraction Pipeline (Go)

This repository now includes a first-pass extraction pipeline implemented in Go.

## What It Produces

Running the pipeline emits:

- `images.jsonl` - per-image metadata (hashes, size, vector words, string counts)
- `functions.jsonl` - canonical function records merged from symbol dump + RE notes
- `artifacts.jsonl` - deterministic artifacts (MMIO refs, patch tags, vector fields)
- `function_links.jsonl` - cross-image function alignment links with confidence
- `patch_entries.jsonl` - decoded patch table entries (section/tag + addr/value tuples)
- `call_edges.jsonl` - extracted call relationships from RE notes
- `message_schema.jsonl` - inferred message/handler schema map
- `message_routes.jsonl` - dispatcher contract routes (type guards -> handler actions)
- `state_machines.jsonl` - first-pass task/state guard extraction from RE notes
- `mining_queue.jsonl` - prioritized targets for next reverse-engineering passes
- `mining_queue_full.jsonl` - full prioritized frontier without truncation
- `mining_queue_top300.jsonl` - stable top-300 slice for focused/manual passes
- `mining_queue_delta.json` - diff vs previous frontier (added/removed targets)
- `summary.json` - run totals
- `stats_latest.json` - detailed aggregated statistics snapshot
- `stats_history.jsonl` - time-series progress history for dashboarding
- `generated_twin/` - generated firmware twin scaffold (headers, role stubs, plan)

All outputs use a normalized schema suitable for downstream indexing and large-scale enrichment.

## Run

```bash
go run ./cmd/fwextract -root . -out extraction_out
```

Optional flags:

- `-min-string-len` (default: `4`) controls ASCII string extraction threshold.
- `-embedding-model` (optional) points to a GGUF embedding model path used as a semantic-alignment hook.
  - Example: `-embedding-model /home/grec-alexander/Downloads/bge-code-v1-q8_0.gguf`
- `-queue-limit` (default: `1200`) controls mining frontier width (`0` = no limit).
- `-queue-min-score` (default: `0.8`) controls inclusion threshold for mining candidates.
- `-run-tag` (optional) writes to `<out>/runs/<tag>/` instead of clobbering root outputs.
  - Use `-run-tag auto` for timestamped runs.

## Sweep Mining (Multi-Threshold)

Run multiple score thresholds and generate a deduplicated frontier union:

```bash
go run ./cmd/fwsweep -root . -out extraction_out -thresholds "0.6,0.8,1.0,1.2" -queue-limit 0 -run-tag-prefix sweep
```

Sweep outputs:

- `extraction_out/runs/<tag>/...` per-threshold full pipeline artifacts
- `extraction_out/sweeps/<prefix>_<timestamp>_union.jsonl` union frontier with run coverage metadata
- `extraction_out/sweeps/<prefix>_<timestamp>_summary.json` sweep summary and per-run queue counts
- `extraction_out/sweeps/<prefix>_<timestamp>_high_impact.jsonl` high-impact cut (`impact-min-score` + `impact-min-seen`)
- `extraction_out/sweeps/<prefix>_<timestamp>_hotspots.json` role/reason/coverage hotspot analytics
- `extraction_out/sweeps/<prefix>_<timestamp>_top_actionable.jsonl` ranked top actionable targets
- `extraction_out/sweeps/<prefix>_<timestamp>_tier_core.jsonl` stable high-signal targets
- `extraction_out/sweeps/<prefix>_<timestamp>_tier_aggressive.jsonl` medium-confidence expansion set
- `extraction_out/sweeps/<prefix>_<timestamp>_tier_experimental.jsonl` speculative neighborhood set
- `extraction_out/sweeps/<prefix>_<timestamp>_recon_strict.jsonl` strict reconstruction lane (stable, non-neighborhood)
- `extraction_out/sweeps/<prefix>_<timestamp>_recon_aggressive.jsonl` aggressive reconstruction lane (stable + broader signal)
- `extraction_out/sweeps/<prefix>_<timestamp>_packs/manifest.json` shard manifest for parallel triage packs

High-power expansion knobs (runtime):

- `-neighbor-max` sets `FW_MINING_NEIGHBOR_MAX` for this sweep run.
- `-neighbor-step` sets `FW_MINING_NEIGHBOR_STEP` for this sweep run.

## Statistics Collector

Collect once:

```bash
go run ./cmd/fwstats -out extraction_out
```

Watch mode:

```bash
go run ./cmd/fwstats -out extraction_out -watch -interval 5s
```

## Live Progress Dashboard

Start dashboard server:

```bash
go run ./cmd/fwdashboard -out extraction_out -addr 127.0.0.1:8090 -interval 2s
```

Then open `http://127.0.0.1:8090`.

The dashboard auto-refreshes via server-sent events and shows detailed totals, coverage metrics, confidence distributions, role breakdowns, patch section analytics, image stats, and time-series progress.

## Current Data Sources

- `*.bin` in workspace root
- `extracted_kernel/function_names.json`
- `re_notes.md`

## Next Expansion Targets

1. Add direct disassembly/IDB ingestion to attach callers/callees, xrefs, and function sizes.
2. Expand queue/state-machine contract extraction (task states, event IDs, transition guards).
3. Recover protocol schemas from dispatcher/parser functions and emit message DSL.
4. Generate C headers/stubs from extracted contracts to bootstrap firmware twin implementation.
