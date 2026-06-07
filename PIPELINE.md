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
  - For functions with IDA Hex-Rays pseudocode coverage, the **real-pseudocode transpiler** (`cmd/fwimplsynth/realpseudo.go`) produces a faithful C body: function pointer calls, MMIO writes, control flow, and helper calls all preserved. See "Stage 3.5: Real-Pseudocode Transpilation" below.
- `fwapplysynth`: merges synthesized bodies into the composed outputs
  - The only lossy transform on real-pseudo bodies is `RESULT = sub_X(args);` → `sub_X(args); RESULT = 0;` (keeps the call, discards the return value). All other semantics are preserved.
- `fwfinalize`: normalizes, scores, and publishes final reconstructed sources and quality reports
  - `injectForwardDecls` emits `void fn(void);` for defined functions and `int fn(...);` (GCC variadic) for undefined callees, with a wider call regex and C-keyword/type-name filter. Strips any pre-existing compose auto-gen block to prevent type conflicts.
- `fwvalidatecalls`: checks emitted call behavior against evidence
- `fwharden`: enforces hard fail gates over quality and conformance outputs

## Stage 3.5: Real-Pseudocode Transpilation

`cmd/fwimplsynth/realpseudo.go` (`transpileIDAPseudocode`) converts Hex-Rays
pseudocode into faithful C. It handles:

- `MEMORY[0x...](...)` → fn-ptr call `(int (*)(uint32_t))0x...u`
- `*(_DWORD *)(EXPR)` and `(_BYTE *)(EXPR)` casts (balanced parens, 1-level)
- `__intN` and `unsigned __intN` types (latter processed first to avoid prefix collision)
- `__fastcall` parameter declarations (preserving pointer stars)
- `LOBYTE(x)` / `HIBYTE(x)` / `LOWORD(x)` / `HIWORD(x)` macros, with `uintptr_t` coerce so they work on pointer inputs
- `LOBYTE(lvalue) = rhs;` → bit-field-style assignment: `x = ((x) & ~0xFFu) | (... & 0xFFu)`
- ARM intrinsics emitted as `#define __get_CPSR() (0u)`, `#define __disable_irq() ((void)0)` — **not** as `void fn(void){}` functions, which would collide with `applysynth`'s extraction regex

The transpiler is exercised by:

- 7 transpiler unit tests + 4 emitter unit tests (`realpseudo_test.go`), all passing
- The truth-lane scorecard on the 25 critical targets

Per-target coverage is 8/25 today (those with `pseudocode_hints.jsonl` entries);
the remaining 17 still fall back to motif-body synthesis and are tracked as a
known gap.

## Stage 4: Autonomous Cycle

Autonomous loop entry point:

```bash
go run ./cmd/fwcycle -run-root extraction_out/reconstruction/mega7 -tag cycle_demo
```

Supporting tools:

- `tools/recon_cycle.py`: quiet controller and probe loop
- `tools/smoke_learn_loop.py`: batch smoke learning
- `tools/unicorn_smoke.py`: per-function bounded smoke harness
- `tools/score_truth_lane.py`: per-function PASS/REVIEW/FAIL scoring on the top 25 critical targets
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

The active v12 workspace produces full-size final outputs (fmacfw_h, fmacfw,
fmacfwbt, lmacfw_rf) which compile cleanly. These are force-added under
`extraction_out/reconstruction/mega7/final/` for evidence tracking. A
curated release bundle refresh from this state is part of the next deliberate
publish step.

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
