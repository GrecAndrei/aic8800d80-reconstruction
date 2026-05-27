# Artifact Policy

This repository separates tracked release artifacts from generated working state.

## Tracked

Track only curated release bundles under:

- `artifacts/releases/`

Each release should be self-describing and should include release-level docs and metadata.

## Not Tracked

Do not commit these as routine working output:

- `extraction_out/`
- `analysis/`
- local caches and wrapper state
- root-level built binaries

## Current Release Catalog

See `artifacts/releases/README.md` for the list of tracked releases.
