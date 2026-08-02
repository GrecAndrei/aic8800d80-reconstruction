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

## Full-System Emulator

- `aic8800d80_emulator.py`: full-system Unicorn platform for the raw
  firmware images (chip base 0x100000, Cortex-M3 CPU model for M-profile
  `MSR MSP`, MMIO device model from `src/include/aic8800d80_mmio.h`).
  - `header <image>` — IVT / boot header info
  - `boot <image>` — boot from the resolved `start` entry, log ordered
    MMIO traffic with register names
  - `trace <image> <addr>` — run one function in the ORIGINAL binary
  - `verify` — fingerprint every truth-lane target in the original binary
    (ground-truth behavioral evidence)
  - `compare` — pair original fingerprints with the reconstructed-side
    `truth_lane_smoke.py` outcomes and score peripheral-register overlap

These tools are part of the real rebuild loop; they are not just one-off scripts.
