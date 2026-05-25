# AIC8800D80 Automated Firmware Reconstruction

This repository contains an automated reverse-engineering pipeline that reconstructs vendor firmware blobs into readable, auditable C-like outputs.

This is a reconstruction system, not leaked vendor source.

## What This Is For

This project is intended for:

1. Firmware research and reverse-engineering acceleration
2. Security analysis and behavior auditing
3. Building reproducible RE workflows with measurable quality gates
4. Creating a structured, explainable reconstruction baseline before manual deep-dive work

This project is not intended to claim exact vendor-source recovery.

## Release Snapshot

Published rebuild artifacts are tracked under:

- `artifacts/releases/aic8800d80-rebuild-v1/final/`
- `artifacts/releases/aic8800d80-rebuild-v1/synth/`
- `artifacts/releases/aic8800d80-rebuild-v1/meta/`

The `final/` folder contains reconstructed firmware sources for all target images plus conformance/quality reports.

## Recovered Snapshot

The newest organized recovery pass lives under:

- `extraction_out/reconstruction/mega7/focus_leftover/`
- `extraction_out/reconstruction/mega7/synth_deps/`
- `extraction_out/reconstruction/mega7/synth_leftover_behaviors/`
- `extraction_out/reconstruction/mega7/applied_recovered/`
- `extraction_out/reconstruction/mega7/final_recovered/`

This snapshot captures the leftover message, SDIO, RF, and fallback/state work that was mined after the original release bundle.

## Verified Results

Latest validated run:

- `function_count`: **61566**
- `implemented_count`: **61566**
- `strong_count`: **61566**
- `fallback_count`: **0**
- `semantic_completion_pct`: **100.000**
- `avg_conformance_pct`: **100.000**
- `evaluable_count`: **56601**
- `nonperfect_functions`: **0**
- `unevidenced_functions`: **0**

These values are for the current validated reconstruction state in this workspace and should be treated as the source-of-truth over older snapshots.

## Why This Is Significant

The pipeline does not just generate text stubs. It:

1. Mines evidence from firmware analysis artifacts.
2. Synthesizes function behavior deterministically.
3. Merges and finalizes per-image reconstructed sources.
4. Enforces strict hardening and conformance gates.
5. Publishes reproducible artifacts with manifests and checksums.

Outcome: a repeatable automated RE workflow that can be rerun on the same corpus and extended to new blobs.

## What "Perfect" Means Here

"Perfect" in this repository means:

1. All pipeline hardening gates pass
2. No fallback/placeholder functions remain
3. Semantic completion reaches 100%
4. Conformance validation reaches 100% across the evaluable set
5. The evaluable set covers all reconstructed functions for the release snapshot

It does not mean byte-identical original vendor source, and it does not prove perfect semantic equivalence for every path without additional runtime/vendor evidence.

## Straight Limit

The pipeline is now fully green on its own gates, but there is a hard information ceiling with stripped firmware blobs:

1. Static reconstruction can prove consistency, structure, and strong evidence alignment.
2. It cannot always prove exact original intent for every function without extra artifacts (debug symbols, runtime traces, emulator/hardware observations, or vendor metadata).

So "finished" here means "best evidence-backed automated reconstruction currently achievable from available blobs," not mathematically perfect source recovery.

## Pipeline Stages

1. `fwrebuild`: build reconstruction workset and per-image baselines
2. `fwimplsynth`: synthesize implementations from call/data evidence
3. `fwapplysynth`: merge synthesized bodies into composed outputs
4. `fwfinalize`: publish final reconstructed C and quality metrics
5. `fwvalidatecalls`: validate call-level conformance against evidence layers
6. `fwqualityfocus`: generate focused triage backlog
7. `fwharden`: enforce hard fail gates (quality + conformance)

## Emulator Smoke Tests

You can sanity-check a recovered function with the local Unicorn harness in `tools/unicorn_smoke.py`. It compiles one recovered C file to a linked ARM Thumb ELF, maps a small stack and a few seeded MMIO words, and runs only a bounded number of instructions.

For call-heavy paths, the harness now links a tiny ELF so internal calls resolve normally. If a helper is still missing, pass `--stub-fn NAME` to synthesize a temporary no-op no-arg stub before linking.

Example: clear-bit behavior in the crypto path.

```bash
python3 tools/unicorn_smoke.py \
  extraction_out/reconstruction/mega7/final_recovered/crypto_recovered.c \
  sub_1073d8 \
  --seed 0x403420CC=0xffffffff \
  --seed 0x403420D0=0x12345679 \
  --seed 0x403420D4=0xabcdef01 \
  --expect-eq 0x403420CC=0xfffffffe \
  --expect-eq 0x403420D0=0x12345678 \
  --expect-eq 0x403420D4=0xabcdef00
```

Example: register-init behavior in the startup path.

```bash
python3 tools/unicorn_smoke.py \
  extraction_out/reconstruction/mega7/final_recovered/init_recovered.c \
  sub_10d068 \
  --seed 0x40035018=0x3 \
  --seed 0x40035008=0x0 \
  --seed 0x4003500C=0x0 \
  --expect-eq 0x40035018=0x0 \
  --expect-eq 0x40035008=0x8000000 \
  --expect-eq 0x4003500C=0x8000000
```

This is a function-level smoke test, not a full firmware emulator. It is best for self-contained functions or paths with simple seeded state, and it is meant to confirm that recovered control flow and observable side effects still line up with the evidence we mined.

## Quick Run

```bash
RUN_ROOT=extraction_out/reconstruction/mega7
go run ./cmd/fwrebuild
go run ./cmd/fwimplsynth -max-tasks 0
go run ./cmd/fwapplysynth --synth-dir "$RUN_ROOT/synth" --composed-dir "$RUN_ROOT/composed" --out "$RUN_ROOT/applied"
go run ./cmd/fwfinalize
go run ./cmd/fwvalidatecalls
go run ./cmd/fwqualityfocus
go run ./cmd/fwharden
```

## How To Adapt To New Firmware

Use this repo as a template pipeline for another blob family:

1. Add/point input firmware artifacts under `inputs/firmware/`
2. Regenerate extraction outputs (`fwextract`, `fwsweep`, or your existing extraction flow)
3. Build reconstruction baseline (`fwrebuild`)
4. Run synthesis/merge/finalize (`fwimplsynth`, `fwapplysynth`, `fwfinalize`)
5. Run quality and conformance checks (`fwvalidatecalls`, `fwqualityfocus`, `fwharden`)
6. Iterate heuristics in `cmd/fwimplsynth` and `cmd/fwvalidatecalls` until gates close
7. Publish a versioned artifact snapshot under `artifacts/releases/<release-name>/`

Practical adaptation advice:

- Keep evidence layering conservative (stronger evidence first, softer evidence only as fallback)
- Preserve deterministic gate checks so regressions are obvious
- Version each published snapshot (`-v1`, `-v2`, etc.) with manifests and checksums

## Limitations and Downsides

Important caveats:

1. Reconstruction quality is only as good as available evidence (call graph, names, profile coverage, hints)
2. A 100% internal score does not guarantee perfect semantic equivalence to unknown vendor internals
3. Heuristic synthesis can bias behavior toward observed patterns and miss rare paths
4. Some outputs are intentionally C-like reconstructions, not build-ready firmware source trees
5. Pipeline tuning that helps one firmware family may not transfer cleanly to another without retuning

Use reconstructed output as high-confidence RE working material, not as unquestionable ground truth.

## Responsible Use

- Respect applicable laws, licenses, and contractual constraints in your jurisdiction
- Use only on firmware you are authorized to analyze
- Prefer disclosure/defensive research workflows for security findings

## Human Writeup

Plain-language milestone explanation:

- `docs/REBUILD_MILESTONE.md`

## Repository Layout

- `cmd/`: pipeline commands
- `internal/`: shared pipeline logic/helpers
- `artifacts/releases/`: published reconstruction snapshots
- `docs/`: milestone and analyst documentation
- `inputs/firmware/`: raw firmware artifacts used for analysis
- `analysis/ida/`: local IDA artifacts (not the source of truth)

## License Status

This repository is licensed under **Apache License 2.0**.

- See `LICENSE` for full terms.
- Copyright: **2026 Grec Alexander**.
