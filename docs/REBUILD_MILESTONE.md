# Rebuild Milestone: Human Summary

## What We Actually Did

We started from vendor firmware blobs (no original source code) and built an automated reverse-engineering pipeline that reconstructs readable C-like firmware logic.

The pipeline ingests mined evidence (addresses, names, call edges, message/state hints), synthesizes function bodies, merges them into per-image outputs, and validates the result with strict gates.

## What "Rebuilt Firmware" Means Here

This is a reconstructed firmware model, not leaked vendor source.

- It is behavior-oriented and evidence-driven.
- It is deterministic/reproducible with pipeline commands.
- It is validated by hardening and conformance gates.

## Final Verified Outcome

For the current release snapshot:

- `function_count`: `356`
- `implemented_count`: `356`
- `strong_count`: `356`
- `fallback_count`: `0`
- `semantic_completion_pct`: `100.000`
- `call_conformance avg`: `100.000`
- `evaluable_count`: `356`
- `nonperfect_functions`: `0`
- `unevidenced_functions`: `0`

## Where The Published Rebuilt Outputs Are

Tracked snapshot in git:

- `artifacts/releases/aic8800d80-rebuild-v1/final/`
- `artifacts/releases/aic8800d80-rebuild-v1/synth/`
- `artifacts/releases/aic8800d80-rebuild-v1/meta/`

Includes:

- Final reconstructed C files for all four images
- Final manifests and quality/conformance reports
- Synth evidence/manifest
- Rebuild/apply manifests
- SHA256 file list for final reconstructed sources

## Why This Matters

This is not one-off manual RE output. It is an automated RE system with measurable pass/fail quality gates that can be rerun and extended on new firmware inputs.
