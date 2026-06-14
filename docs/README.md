# Docs Index

Start here if you need to understand how this repo is organized.

## Core Docs

- `../README.md`: top-level overview, status, and common entry points
- `../AGENTS.md`: quick reference for AI agents
- `../PIPELINE.md`: end-to-end pipeline reference
- `../plan.md`: canonical long-term architecture and progress log

## Repo Navigation

- `REPO_LAYOUT.md`: what each top-level directory is for
- `RUNBOOK.md`: common commands and operator workflow
- `REBUILD_MILESTONE.md`: current milestone summary for humans

## Per-Layer Documentation

Each firmware reconstruction layer has its own docs:

- **`../harness_v15/README.md`** — synthesis baseline (Unicorn trace)
- **`../harness_v17/README.md`** — LLM tool-use pipeline
- **`../harness_v19/README.md`** — Hex-Rays decompilation pipeline

Subsystem documentation (in `harness_v17/docs/`):
- `bt.md`, `ipc.md`, `ke.md`, `mac.md`, `mmio.md`, `patch.md`,
  `rf.md`, `rx.md`, `scan.md`, `tx.md`, `unknown.md`, `util.md`
- 12 markdown files describing what each subsystem does

## Release Documentation

Per-release READMEs in `artifacts/releases/<release>/`:
- `aic8800d80-rebuild-v1-v15/README.md` — v15 release
- `aic8800d80-rebuild-v1-v17/README.md` — v17 release
- `aic8800d80-rebuild-v1-v18/README.md` — v18 release
- `aic8800d80-rebuild-v1-v19/README.md` — v19 release (latest)
- `aic8800d80-rebuild-v1-v19/docs/ORACLE_RESULTS.md` — quality report

## Historical Notes

- `notes/notes.md`: early triage notes
- `notes/re_notes.md`: large RE notes corpus

## Related Readmes Outside This Folder

- `../artifacts/README.md`: artifact policy and tracked release rules
- `../artifacts/releases/README.md`: release catalog
- `../artifacts/releases/aic8800d80-rebuild-v1/README.md`: v17 working release
- `../cmd/README.md`: command catalog (Go)
- `../tools/README.md`: tool catalog (Python)
- `../internal/README.md`: internal package map
- `../inputs/README.md`: input asset rules
- `../metadata/README.md`: stable metadata notes
- `../extracted_kernel/README.md`: historical kernel extraction notes
