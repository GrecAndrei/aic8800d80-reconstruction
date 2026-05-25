# Agent Guide

This repository is a live firmware-reconstruction workspace.
The goal is to keep pushing the rebuilt firmware closer to a runnable,
evidence-backed image while committing and pushing validated progress often.

## Primary Objective

- Continue advancing the firmware rebuild in small, real increments.
- Prefer evidence-backed progress over broad guesses.
- Keep the repository current with frequent commits and pushes.
- Expand the validated runtime surface whenever possible.
- Use better tools when they materially improve the work.

## Working Style

- Move in short, high-signal batches.
- Validate before claiming progress.
- Record every newly confirmed checkpoint in `README.md`.
- Commit and push often enough that the remote state tracks the local work.
- If a path faults in the emulator, use the exact fault address as the next seed.
- Do not widen the emulation model unless the path actually demands it.

## Canonical Workflow

1. Find a fresh helper family or hot path that is not already recorded.
2. Smoke-test it under `tools/unicorn_smoke.py`.
3. If it faults, rerun with only the missing MMIO words seeded.
4. Keep the seed set as small as possible.
5. Once the path is green, add it to the smoke checkpoint list in `README.md`.
6. Commit the documentation and push immediately.
7. Return to step 1.
8. Record smoke outcomes (`--record-outcome .../smoke_observations.jsonl`) so the next extraction run re-weights targets automatically.
9. For unattended batches, run `tools/smoke_learn_loop.py` against the latest queue and source pool, then rerun `fwextract` to ingest the new outcomes.
10. Prefer `tools/recon_cycle.py` when you want one command to execute probe+ingest+report and preserve cycle-to-cycle trend evidence.

## Validation Rules

- Prefer the local Unicorn smoke harness for function-level checks.
- Treat `gcc -fsyntax-only` or `python3 -m py_compile` as hygiene checks, not proof of firmware correctness.
- A path is only a checkpoint after it actually runs cleanly in the harness.
- If a function needs a seed at `0x400000XX`, use that exact address first.
- If a function needs a vector-table address, seed the exact system register words it reads.
- Keep the extraction loop dynamic: every run should ingest the latest smoke outcomes and checkpoint-derived learning signals.

## What Good Progress Looks Like

- More real helper families become smoke-clean.
- The README checkpoint list grows steadily.
- The harness continues to work on new targets without broad refactors.
- The rebuilt firmware stays compilable and runnable in smoke form.
- New blocks of the codebase are converted from static text into validated paths.

## What Not To Do

- Do not keep re-testing already-recorded green paths unless the harness changed.
- Do not inflate the emulation model just to avoid one missing register word.
- Do not stop at explanations when a real run or a real patch is possible.
- Do not treat a fault as failure if it can be resolved with one or two exact seeds.
- Do not mark the overall job done until the evidence genuinely supports it.

## Current Tooling

- `tools/unicorn_smoke.py` is the main function-level validation harness.
- The harness compiles one recovered C file into a linked ARM Thumb ELF.
- It maps the ELF load segments, seeds MMIO, and runs bounded instruction counts.
- The harness should stay small, surgical, and easy to extend.

## Current Subagent Roles

These are the live lanes used during the reconstruction effort:

- `Tesla`: wrapper-style helper cleanup.
- `Meitner`: high-value stateful gaps in boot, init, RF, SDIO, IRQ, and queue paths.
- `Kuhn`: emulation-first target selection and minimal-seed expansion.

Each subagent should stay bounded and autonomous:

- Give each one a specific lane.
- Avoid vague "go do the whole firmware" tasks.
- Prefer concrete outputs: a target list, a fault seed list, or a set of newly validated helpers.

## Recommended Target Priority

When choosing the next batch, prefer:

- direct helpers that are not yet recorded
- RF and SDIO paths with small state needs
- init and timer helpers
- IRQ/vector helpers
- message and queue helpers
- wrapper-like thunks that can be flattened cleanly

## File Conventions

- Keep `README.md` as the user-facing checkpoint log.
- Keep `agents.md` as the coordination and process guide.
- Keep harness code in `tools/`.
- Prefer small changes that make the next validation easier.

## Commit Discipline

- Commit after each validated batch.
- Push immediately after committing.
- Keep commit messages short and specific.
- If a harness fix enables a new family, include the harness fix and the README update in the same commit when practical.

## Handling Faults

When a helper faults under Unicorn:

- Note the exact fault address.
- Seed the missing word or words only.
- Rerun the same helper.
- If the helper still fails, continue with the next exact address.
- If the helper becomes too irregular, move to another fresh target and return later.

## Handling Success

When a helper runs cleanly:

- Add it to the smoke checkpoint list.
- Commit the docs update.
- Push the commit.
- Move to the next fresh family right away.

## Long-Term Direction

The end state is not just a pile of passing smoke tests.
The end state is a firmware rebuild that is progressively more complete,
more runnable, and more faithful to the original image.

That means:

- keep widening the verified surface
- keep reducing wrapper noise
- keep improving the harness only when it helps real targets
- keep using evidence to choose the next move

## Practical Rule of Thumb

If you are unsure what to do next:

1. Look for an unrecorded helper family.
2. Smoke-test it.
3. Seed the exact missing MMIO addresses.
4. Record the checkpoint.
5. Push it.

Repeat until the next meaningful blocker appears.
