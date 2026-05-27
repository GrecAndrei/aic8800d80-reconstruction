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
go test ./cmd/fwdescriptors ./cmd/fwcompose ./cmd/fwimplqueue ./cmd/fwimplsynth ./cmd/fwfinalize ./cmd/fwharden ./cmd/fwcycle
python3 -m py_compile tools/recon_cycle.py tools/smoke_learn_loop.py
```

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
