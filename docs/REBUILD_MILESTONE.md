# Rebuild Milestone

## What This Repo Delivers

This repository reconstructs readable, auditable firmware logic from stripped AIC8800D80 firmware blobs.

The rebuild path is evidence-driven:

- IDA exports provide grounded structural facts
- embedder outputs provide retrieval and transfer priors
- descriptors unify those signals per function
- compose, synth, finalize, validate, and harden stages turn those signals into tracked release outputs

## Current Published Snapshot

Current curated release:

- `artifacts/releases/aic8800d80-rebuild-v1/`

Published metrics recorded in that release:

- `function_count`: `356`
- `implemented_count`: `356`
- `strong_count`: `356`
- `fallback_count`: `0`
- `semantic_completion_pct`: `100.000`
- `evaluable_count`: `352`
- `avg_conformance_pct`: `100.000`

## Active Working Snapshot

Live autonomous work happens under:

- `extraction_out/reconstruction/mega7/`

This workspace includes:

- run-tagged cycle outputs
- controller state and experience logs
- descriptor, motif, and transfer analysis
- compose, synth, applied, and final generated outputs

## Why The Current Milestone Matters

The project is no longer just generating placeholders from names. The current path now pushes richer semantic evidence through the rebuild pipeline:

- descriptors and motif memory
- embedder-neighbor retrieval
- transfer clusters and preferred emitters
- finalize and hardening stages that see the same evidence

That means the pipeline is improving actual rebuild behavior rather than only improving isolated tools.

## Constraint To Keep In Mind

Even with strong internal scores, this is still reconstructed firmware behavior from stripped blobs, not original vendor source. The goal is the strongest reproducible, evidence-backed reconstruction we can build from the available artifacts.
