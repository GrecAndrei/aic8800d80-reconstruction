# AIC8800D80 Firmware Reconstruction

This repository is an automated reverse-engineering and firmware reconstruction workspace for the AIC8800D80 firmware family.

It is not leaked vendor source. It is a deterministic reconstruction pipeline that combines:

- grounded facts exported from IDA Pro,
- embedder-driven retrieval and clustering,
- staged body synthesis and merge/finalize passes,
- strict conformance and hardening gates,
- autonomous probe and rebuild cycles.

## Status

- Active reconstruction workspace: `extraction_out/reconstruction/mega7/`
- Published tracked release: `artifacts/releases/aic8800d80-rebuild-v1/`
- Canonical long-term plan: `plan.md`
- End-to-end pipeline reference: `PIPELINE.md`
- Repo navigation and operator docs: `docs/README.md`

The tracked release snapshot currently records:

- `function_count`: `356`
- `implemented_count`: `356`
- `strong_count`: `356`
- `fallback_count`: `0`
- `semantic_completion_pct`: `100.000`
- `evaluable_count`: `352`
- `avg_conformance_pct`: `100.000`

These values come from the curated release bundle under `artifacts/releases/aic8800d80-rebuild-v1/`. The live workspace under `extraction_out/` can be newer and noisier.

## Repo Map

- `cmd/`: Go entry points for extraction, reconstruction, validation, dashboards, and autonomous cycle control
- `internal/`: shared extraction, pipeline, reconstruction, file I/O, and stats packages
- `tools/`: Python helpers for IDA export, probing, smoke learning, autonomous cycles, and embedder integration
- `docs/`: repo map, runbook, milestone notes, and research notes
- `artifacts/`: tracked published release snapshots only
- `metadata/`: stable input metadata and per-image reconstruction descriptors
- `inputs/`: source firmware blobs and related inputs
- `extracted_kernel/`: historical kernel-focused extraction notes and slices
- `extraction_out/`: generated working outputs for current runs; ignored from git
- `analysis/`: local scratch, wrapper state, and ad hoc analysis output; ignored from git

Detailed layout rules live in `docs/REPO_LAYOUT.md`.

## Canonical Docs

- `docs/README.md`: documentation index
- `docs/RUNBOOK.md`: operator runbook and common commands
- `docs/REPO_LAYOUT.md`: what each top-level directory is for, and what should or should not be committed
- `docs/REBUILD_MILESTONE.md`: current high-level milestone summary
- `PIPELINE.md`: extraction + reconstruction + validation pipeline reference
- `plan.md`: long-term autonomous architecture and progress log

## Core Workflow

Typical rebuild path:

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

Autonomous cycle entry point:

```bash
go run ./cmd/fwcycle -run-root extraction_out/reconstruction/mega7 -tag cycle_demo
```

See `docs/RUNBOOK.md` and `PIPELINE.md` for the full staged workflow.

## Artifact Policy

- Track curated release outputs under `artifacts/releases/`
- Keep active run products under `extraction_out/`
- Keep local wrapper state and scratch under `analysis/`
- Do not commit local caches, root-level built binaries, or Python bytecode

This policy is enforced by `.gitignore` and documented in `artifacts/README.md`.

## Adaptation

To adapt this repository to another firmware family:

1. Place new blobs under `inputs/firmware/`
2. Re-run extraction into `extraction_out/`
3. Build a reconstruction baseline
4. Run descriptor, synthesis, finalize, and validation stages
5. Publish only curated release outputs under `artifacts/releases/<name>/`

## Notes

- The live workspace is intentionally richer than the published release snapshot.
- The repo is organized around a clean split between source, generated workspaces, and tracked release artifacts.
- When in doubt, start with `docs/README.md`.
