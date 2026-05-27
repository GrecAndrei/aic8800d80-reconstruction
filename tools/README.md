# Tools Catalog

This directory contains Python helpers used alongside the Go commands.

## IDA Export Helpers

- `refresh_ida_exports.py`
- `export_ida_cfg.py`
- `export_ida_edges.py`
- `export_ida_pseudocode.py`
- `select_pseudocode_targets.py`

## Autonomous Cycle And Learning

- `recon_cycle.py`: quiet controller and cycle summary logic
- `smoke_learn_loop.py`: batch smoke execution and learning feedback
- `update_smoke_checkpoints.py`: checkpoint promotion
- `prune_cycle_artifacts.py`: run-history housekeeping

## Analysis Helpers

- `embedder.py`: embedding and behavior classification support
- `unicorn_smoke.py`: bounded per-function smoke harness

These tools are part of the real rebuild loop; they are not just one-off scripts.
