# AIC8800D80 Automated Firmware Reconstruction

This repository contains an automated reverse-engineering pipeline that reconstructs vendor firmware blobs into readable, auditable C-like outputs.

This is a reconstruction system, not leaked vendor source.

## Release Snapshot

Published rebuild artifacts are tracked under:

- `artifacts/releases/aic8800d80-rebuild-v1/final/`
- `artifacts/releases/aic8800d80-rebuild-v1/synth/`
- `artifacts/releases/aic8800d80-rebuild-v1/meta/`

The `final/` folder contains reconstructed firmware sources for all target images plus conformance/quality reports.

## Verified Results

Latest validated run:

- `function_count`: **356**
- `implemented_count`: **356**
- `strong_count`: **356**
- `fallback_count`: **0**
- `semantic_completion_pct`: **100.000**
- `avg_conformance_pct`: **100.000**
- `evaluable_count`: **356**
- `nonperfect_functions`: **0**
- `unevidenced_functions`: **0**

## Why This Is Significant

The pipeline does not just generate text stubs. It:

1. Mines evidence from firmware analysis artifacts.
2. Synthesizes function behavior deterministically.
3. Merges and finalizes per-image reconstructed sources.
4. Enforces strict hardening and conformance gates.
5. Publishes reproducible artifacts with manifests and checksums.

Outcome: a repeatable automated RE workflow that can be rerun on the same corpus and extended to new blobs.

## Pipeline Stages

1. `fwrebuild`: build reconstruction workset and per-image baselines
2. `fwimplsynth`: synthesize implementations from call/data evidence
3. `fwapplysynth`: merge synthesized bodies into composed outputs
4. `fwfinalize`: publish final reconstructed C and quality metrics
5. `fwvalidatecalls`: validate call-level conformance against evidence layers
6. `fwqualityfocus`: generate focused triage backlog
7. `fwharden`: enforce hard fail gates (quality + conformance)

## Quick Run

```bash
RUN_ROOT=extraction_out/reconstruction/mega7
go run ./cmd/fwrebuild
go run ./cmd/fwimplsynth -max-tasks 0
go run ./cmd/fwapplysynth --synth-dir "$RUN_ROOT/synth" --composed-dir "$RUN_ROOT/composed" --out "$RUN_ROOT/applied"
go run ./cmd/fwfinalize
go run ./cmd/fwvalidatecalls
go run ./cmd/fwqualityfocus
go run ./cmd/fwharden
```

## Human Writeup

Plain-language milestone explanation:

- `docs/REBUILD_MILESTONE.md`

## Repository Layout

- `cmd/`: pipeline commands
- `internal/`: shared pipeline logic/helpers
- `artifacts/releases/`: published reconstruction snapshots
- `docs/`: milestone and analyst documentation
- `inputs/firmware/`: raw firmware artifacts used for analysis
- `analysis/ida/`: local IDA artifacts (not the source of truth)
