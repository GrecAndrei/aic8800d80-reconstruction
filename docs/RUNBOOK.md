# Runbook

This is the operator runbook for the current reconstruction pipeline.

## Common Paths

```bash
RUN_ROOT=extraction_out/reconstruction/mega7
RELEASE_ROOT=artifacts/releases/aic8800d80-rebuild-v1
```

## Full Rebuild Path

```bash
go run ./cmd/fwcompose
go run ./cmd/fwdescriptors -run-root "$RUN_ROOT"
go run ./cmd/fwimplqueue -max-tasks 128
go run ./cmd/fwimplsynth -max-tasks 128
go run ./cmd/fwapplysynth
go run ./cmd/fwfinalize
go run ./cmd/fwvalidatecalls
go run ./cmd/fwharden
```

## Autonomous Cycle

Single cycle:

```bash
go run ./cmd/fwcycle -run-root "$RUN_ROOT" -tag cycle_demo
```

Detached multi-cycle supervisor:

```bash
nohup go run ./cmd/fwcycleauto -run-root "$RUN_ROOT" > /tmp/fwcycleauto.log 2>&1 &
```

Stop detached supervisor:

```bash
touch "$RUN_ROOT/.fwcycleauto.stop"
```

## Focused Verification

```bash
go test ./cmd/fwdescriptors ./cmd/fwcompose ./cmd/fwimplqueue ./cmd/fwimplsynth ./cmd/fwapplysynth ./cmd/fwfinalize ./cmd/fwharden ./cmd/fwcycle
python3 -m py_compile tools/recon_cycle.py tools/smoke_learn_loop.py
```

## Truth-Lane Scoring

The truth-lane scorecard runs `fwimplsynth` against the focused queue of
the 25 critical functions and scores each PASS/REVIEW/FAIL on
function-level semantic fidelity (callee calls, helper signatures, MMIO
profile, motif alignment).

```bash
python3 tools/score_truth_lane.py \
  --run-root extraction_out/reconstruction/mega7 \
  --out-dir /tmp/opencode/truth_lane_score \
  --label v12_realpseudocode
```

Outputs:

- `scorecard.json`: machine-readable per-target results
- `scorecard.md`: human-readable summary

The current v12 build reports 25 PASS / 0 REVIEW / 0 FAIL.

## Real-Pseudocode Transpiler

Functions with Hex-Rays pseudocode coverage in
`extraction_out/ida_export_pseudo/pseudocode_hints.jsonl` are lowered
through the real-pseudocode transpiler
(`cmd/fwimplsynth/realpseudo.go`) instead of motif-body synthesis. The
transpiler preserves:

- function pointer calls (`MEMORY[0x...](...)`)
- MMIO writes to fixed addresses
- nested if/else control flow
- helper calls (with their args intact)
- `__intN` types, `__fastcall` params, LOBYTE/HIBYTE/LOWORD/HIWORD macros
- ARM intrinsics (emitted as `#define` macros)

Verify the transpiler:

```bash
go test ./cmd/fwimplsynth -run TestTranspile -v
```

This runs the 7 transpiler unit tests and 4 emitter unit tests.

## Final C File Compile Check

Confirm the four final C files compile clean:

```bash
for f in extraction_out/reconstruction/mega7/final/*.reconstructed.c; do
  echo "==> $f"
  aarch64-linux-gnu-gcc -Wall -Wextra -c "$f" -o /tmp/$(basename "$f").o 2>&1 | head -5
done
```

The v12 build produces 0 errors per file.

## Release Refresh

After producing a release-quality state, refresh the tracked release bundle deliberately:

1. copy curated final outputs and manifests into `artifacts/releases/<name>/`
2. refresh release docs and metadata
3. verify the release README and release index match the actual files

## Housekeeping

- keep generated state in `extraction_out/`
- keep scratch in `analysis/`
- keep tracked release data in `artifacts/releases/`
- do not edit generated `final/` files by hand; change the real pipeline inputs instead
