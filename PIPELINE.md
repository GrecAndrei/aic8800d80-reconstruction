# Firmware Reconstruction Pipeline

This file describes the end-to-end pipeline used in this repository.

It covers three layers:

1. evidence extraction,
2. reconstruction and validation,
3. autonomous probe-and-rebuild cycling.

## Pipeline Layout

The repository is organized around three output classes:

- source and tooling: `cmd/`, `internal/`, `tools/`
- generated working state: `extraction_out/`, `analysis/`
- curated tracked releases: `artifacts/releases/`

The active working run root is currently `extraction_out/reconstruction/mega7/`.

## Stage 1: Evidence Extraction

Primary extraction command:

```bash
go run ./cmd/fwextract -root . -out extraction_out
```

This stage emits normalized evidence such as:

- `images.jsonl`
- `functions.jsonl`
- `artifacts.jsonl`
- `function_links.jsonl`
- `consensus_behavior.jsonl`
- `call_edges.jsonl`
- `message_schema.jsonl`
- `state_machines.jsonl`
- mining queue outputs and stats snapshots

Supporting commands:

- `go run ./cmd/fwsweep ...`: multi-threshold frontier generation
- `go run ./cmd/fwstats ...`: stats collection and watch mode
- `go run ./cmd/fwdashboard ...`: live progress dashboard

## Stage 2: IDA Exports And Semantic Inputs

The reconstruction path depends on grounded IDA exports plus embedder outputs.

Key sources:

- `tools/refresh_ida_exports.py`
- `tools/export_ida_cfg.py`
- `tools/export_ida_pseudocode.py`
- `tools/select_pseudocode_targets.py`
- `tools/embedder.py`

Important generated inputs:

- `extraction_out/ida_export_cfg/cfg_hints.jsonl`
- `extraction_out/ida_export_pseudo/pseudocode_hints.jsonl`
- `extraction_out/reconstruction/mega7/embedder_cache.json`
- `extraction_out/reconstruction/mega7/function_links.jsonl`
- `extraction_out/reconstruction/mega7/consensus_behavior.jsonl`

## Stage 3: Reconstruction Build Path

The real rebuild path is:

```bash
RUN_ROOT=extraction_out/reconstruction/mega7

go run ./cmd/fwcompose
go run ./cmd/fwdescriptors -run-root "$RUN_ROOT"
go run ./cmd/fwimplqueue -max-tasks 128
go run ./cmd/fwimplsynth -max-tasks 128
go run ./cmd/fwapplysynth
go run ./cmd/fwfinalize
go run ./cmd/fwvalidatecalls
go run ./cmd/fwharden
```

What each stage does:

- `fwcompose`: constructs composed reconstruction units from lifted work
- `fwdescriptors`: builds per-function descriptors, motif memory, transfer clusters, and descriptor summaries
- `fwimplqueue`: ranks implementation tasks using urgency, motif, phenotype, and transfer evidence
- `fwimplsynth`: synthesizes function bodies using observed evidence, motif memory, embedder neighbors, and transfer clusters
- `fwapplysynth`: merges synthesized bodies into the composed outputs
- `fwfinalize`: normalizes, scores, and publishes final reconstructed sources and quality reports
- `fwvalidatecalls`: checks emitted call behavior against evidence
- `fwharden`: enforces hard fail gates over quality and conformance outputs

## Stage 4: Autonomous Cycle

Autonomous loop entry point:

```bash
go run ./cmd/fwcycle -run-root extraction_out/reconstruction/mega7 -tag cycle_demo
```

Supporting tools:

- `tools/recon_cycle.py`: quiet controller and probe loop
- `tools/smoke_learn_loop.py`: batch smoke learning
- `tools/unicorn_smoke.py`: per-function bounded smoke harness
- `cmd/fwcycletrend`: trend summaries and gating
- `cmd/fwcycleauto`: detached multi-cycle supervisor

Cycle outputs are written under:

- `extraction_out/reconstruction/mega7/runs/<tag>/`
- `extraction_out/reconstruction/mega7/cycle_history.jsonl`
- `extraction_out/reconstruction/mega7/controller_state.json`
- `extraction_out/reconstruction/mega7/controller_experience.jsonl`

## Stage 5: Published Release Snapshot

Only curated release outputs belong in git:

- `artifacts/releases/aic8800d80-rebuild-v1/final/`
- `artifacts/releases/aic8800d80-rebuild-v1/meta/`
- `artifacts/releases/aic8800d80-rebuild-v1/README.md`

The release bundle should contain:

- finalized reconstructed sources
- manifests and checksums
- call conformance and quality reports
- release-level metadata describing what was published

## Operational Rules

- Treat `extraction_out/` as generated working state
- Treat `analysis/` as local scratch
- Prefer descriptor/motif/transfer changes over direct edits to generated outputs
- Use IDA exports and embedder outputs together; do not degrade to name-only heuristics when stronger evidence is available
- Publish only curated release artifacts under `artifacts/releases/`

## Related Docs

- `README.md`
- `docs/README.md`
- `docs/RUNBOOK.md`
- `docs/REPO_LAYOUT.md`
- `plan.md`
