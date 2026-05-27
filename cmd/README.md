# Command Catalog

This directory contains the executable Go entry points for the repository.

## Extraction And Frontiering

- `fwextract`: normalize firmware evidence into JSONL artifacts
- `fwsweep`: run multi-threshold frontier sweeps
- `fwstats`: collect and aggregate statistics
- `fwdashboard`: serve a live dashboard over extracted stats

## Reconstruction Path

- `fwcompose`: build composed reconstruction units
- `fwdescriptors`: build descriptor, motif, and transfer artifacts
- `fwimplqueue`: rank implementation tasks
- `fwimplsynth`: synthesize function bodies
- `fwapplysynth`: merge synthesized bodies into composed units
- `fwfinalize`: normalize and publish final reconstructed outputs
- `fwvalidatecalls`: validate emitted calls against evidence
- `fwconformancefocus`: surface call-conformance triage rows
- `fwqualityfocus`: surface finalize-quality triage rows
- `fwharden`: enforce release and behavioral hardening gates

## Reconstruction Control

- `fwcycle`: run one autonomous probe-and-rebuild cycle
- `fwcycletrend`: summarize cycle history and apply trend gates
- `fwcycleauto`: run repeated `fwcycle` passes in a detached supervisor loop

## Supporting Utilities

- `fwlift`, `fwrebuild`, `fwqueue`, `fwfocus`, `fwcompact`, `fwcluster`, `fwmega`, `fwrecon`, `fwimplwork`

For the current recommended workflow, use `docs/RUNBOOK.md` and `PIPELINE.md`.
