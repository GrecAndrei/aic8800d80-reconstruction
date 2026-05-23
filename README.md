# AIC8800D80 Reconstruction

This repository contains the reconstruction pipeline for AIC8800D80 firmware analysis, focused on turning mined call/data evidence into readable, auditable reconstructed C outputs.

## Current Status

- Rebuild pipeline: **passing**
- Hardening gate: **passing**
- Final reconstruction metrics (latest run):
  - `function_count`: **356**
  - `implemented_count`: **356**
  - `strong_count`: **356**
  - `fallback_count`: **0**
  - `semantic_completion_pct`: **100.000**
- Quality focus backlog (latest run):
  - `focus_items`: **0**
  - `high risk`: **0**
  - `medium-risk sub_*`: **0**

Status artifacts (generated):
- `extraction_out/reconstruction/mega7/final/finalize_manifest.json`
- `extraction_out/reconstruction/mega7/final/finalize_quality.json`
- `extraction_out/reconstruction/mega7/final/quality_focus.json`
- `extraction_out/reconstruction/mega7/synth/implsynth_evidence.json`

## How It Works

The pipeline is staged and evidence-driven:

1. `fwrebuild`
- Builds mined reconstruction artifacts from the recon workset.
- Produces rebuilt manifests and per-image reconstructed stubs.

2. `fwimplsynth`
- Synthesizes implementation bodies from:
  - implementation queue
  - call-edge graph
  - composed hints
  - family/token/image heuristics
- Emits per-function synth outputs and `implsynth_evidence.json` (caller/callee evidence, inferred alias/calls).

3. `fwapplysynth`
- Merges synthesized bodies into composed reconstruction files.
- Uses body-strength precedence so stronger bodies win deterministically.

4. `fwfinalize`
- Publishes final reconstruction files and metrics.
- Produces `finalize_manifest.json` and per-function quality/risk analysis in `finalize_quality.json`.

5. `fwqualityfocus`
- Builds a prioritized triage list (`quality_focus.json`) for manual RE hardening.

6. `fwharden`
- Enforces fail-fast hardening gates:
  - no TODO residues
  - no isolated-leaf markers
  - no fallback functions
  - strong count equals function count
  - semantic completion at 100%

## Quick Start

Run full rebuild and hardening:

```bash
go run ./cmd/fwrebuild
go build -o /tmp/fwimplsynth ./cmd/fwimplsynth
/tmp/fwimplsynth -max-tasks 0
go run ./cmd/fwapplysynth --synth-dir extraction_out/reconstruction/mega7/synth --composed-dir extraction_out/reconstruction/mega7/composed --out extraction_out/reconstruction/mega7/applied
go run ./cmd/fwfinalize
go run ./cmd/fwqualityfocus
go run ./cmd/fwharden
```

## Repository Layout

- `cmd/`: pipeline commands (`fwrebuild`, `fwimplsynth`, `fwapplysynth`, `fwfinalize`, `fwqualityfocus`, `fwharden`, etc.)
- `internal/`: shared internals/helpers
- `PIPELINE.md`: pipeline-specific notes
- `docs/notes/`: analyst notes and reconstruction logs
- `metadata/`: recon metadata snapshots and user config files
- `tools/local-bin/`: local helper binaries (not required for source builds)

## Workspace Hygiene

- Large/generated artifacts remain outside git tracking via `.gitignore` (especially `extraction_out/` and firmware databases).
- Source-of-truth code and docs are kept in tracked top-level folders (`cmd`, `internal`, `docs`).

## Update Policy

This README status section is updated whenever pipeline quality/hardening state materially changes.
