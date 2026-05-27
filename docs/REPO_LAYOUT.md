# Repo Layout

This repository is split into source, generated workspaces, and tracked releases.

## Top Level

- `cmd/`: executable Go commands
- `internal/`: shared Go packages used by commands
- `tools/`: Python helpers and export scripts
- `docs/`: operator and repository documentation
- `metadata/`: stable input metadata and per-image descriptors
- `inputs/`: firmware blobs and input assets
- `artifacts/`: tracked release snapshots only
- `extracted_kernel/`: historical kernel extraction notes
- `extraction_out/`: generated extraction and reconstruction outputs; ignored from git
- `analysis/`: local scratch and wrapper state; ignored from git
- `archives/`: archived bundles and imports

## Command Groups

Extraction and frontiering:

- `fwextract`
- `fwsweep`
- `fwstats`
- `fwdashboard`

Reconstruction path:

- `fwcompose`
- `fwdescriptors`
- `fwimplqueue`
- `fwimplsynth`
- `fwapplysynth`
- `fwfinalize`
- `fwvalidatecalls`
- `fwharden`

Autonomous orchestration:

- `fwcycle`
- `fwcycletrend`
- `fwcycleauto`

## Working State Rules

- `extraction_out/` is for generated state that can be regenerated
- `analysis/` is for local machine-specific wrapper output and scratch
- root-level built binaries must not be committed
- Python bytecode, Go caches, and local tool state must not be committed

## Tracked Artifact Rules

Track only curated release bundles under `artifacts/releases/<release>/`.

Each release should have:

- `README.md`
- `final/`
- `meta/`

`synth/` can be tracked only when intentionally publishing a synthesis corpus as part of the release.

## Canonical Active Workspace

The current active workspace is:

- `extraction_out/reconstruction/mega7/`

That run root contains composed outputs, synthesis outputs, final outputs, controller state, run history, and descriptor analysis.
