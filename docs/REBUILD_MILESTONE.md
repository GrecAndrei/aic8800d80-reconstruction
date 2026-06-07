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

## Current Live Build — v12 Real-Pseudocode Reconstruction

The active workspace (`extraction_out/reconstruction/mega7/`) is on the v12
build path. It is significantly larger than the curated v1 release and uses
a real-pseudocode transpiler for fidelity-first reconstruction of
truth-lane targets.

Build metrics (v12):

- `fmacfw_h`: 906 functions, 0 compile errors
- `fmacfw`: 74441 functions, 0 compile errors
- `fmacfwbt`: 52052 functions, 0 compile errors
- `lmacfw_rf`: 57378 functions, 0 compile errors
- `applysynth`: 17365 bodies applied, 15133 unique
- `implemented_count`: 17504
- `completion_pct`: 28.429
- `fallback_count`: 0
- Truth Lane Scorecard: **25 PASS / 0 REVIEW / 0 FAIL** on the 25 critical targets
- Truth Lane Unicorn Smoke: **17 PASS / 8 REVIEW / 0 FAIL** — all 17 real-pseudo
  bodies execute end-to-end in the Unicorn ARMv7-M emulator
- Cloud evidence: `mega7_v12_clean.tar.gz` uploaded to Drive
  (`1o2qy21F9EbMpPk4B9WqIEMHfWrL3BW4y`)

What changed in v12:

- New `cmd/fwimplsynth/realpseudo.go` — IDA Hex-Rays pseudocode → C
  transpiler with full unit-test coverage (7 transpiler tests, 4 emitter
  tests, all passing). Handles `MEMORY[0x...](...)` fn-ptr calls, balanced
  `*(_DWORD *)(EXPR)` casts, `__intN` / `unsigned __intN` types,
  `__fastcall` param extraction, and LOBYTE/HIBYTE/LOWORD/HIWORD macros
  (with `uintptr_t` coerce and lvalue-assignment rewrite).
- `cmd/fwapplysynth` — V10/V11: variant-name and reverse-lookup body
  propagation (V11 alone took completion from 0.322 → 24.026). V12: only
  lossy transform on real-pseudo bodies is `RESULT = sub_X(args);` →
  `sub_X(args); RESULT = 0;`.
- `cmd/fwfinalize/injectForwardDecls` — Differentiated decls: defined
  functions get `void fn(void);`, undefined callees get `int fn(...);` (GCC
  variadic). Strips pre-existing compose auto-gen block to prevent type
  conflicts. Wider call regex with C-keyword/type-name filter.
- ARM intrinsics emitted as `#define` macros inside synth bodies, not as
  function stubs (the latter silently redirected synth bodies to the stub
  name).
- `tools/score_truth_lane.py` — Per-function PASS/REVIEW/FAIL scoring on
  the 25 critical functions; writes `scorecard.json`/`scorecard.md`.
- `extraction_out/reconstruction/mega7/final/*.c` force-added and committed
  for evidence tracking of the v12 build.

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
- **real-pseudocode transpilation** for functions with Hex-Rays coverage
  (v12 and later)

That means the pipeline is improving actual rebuild behavior rather than only improving isolated tools.

## Constraint To Keep In Mind

Even with strong internal scores, this is still reconstructed firmware behavior from stripped blobs, not original vendor source. The goal is the strongest reproducible, evidence-backed reconstruction we can build from the available artifacts.
