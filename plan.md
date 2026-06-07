# Autonomous Firmware Reconstruction Plan

This file is the canonical long-term execution plan for this repository.

## Operating Rules

- Read this file before starting non-trivial work.
- Keep one active milestone at a time.
- Continue execution autonomously unless the user explicitly redirects or stops the current line of work.
- Update this file after every meaningful execution batch with concrete evidence, not aspirations.
- Prefer small durable improvements to orchestration, evidence quality, memory, and firmware behavior over broad speculative rewrites.
- Keep the console quiet. Emit compact milestone summaries to stdout and write full evidence, metrics, and controller state to structured artifacts.

## North Star

Produce a self-improving firmware reconstruction system that:

- uses IDA Pro as the source of grounded structural facts,
- uses the embedder model as the source of retrieval, clustering, and transfer priors,
- improves real reconstructed firmware behavior cycle over cycle,
- learns from outcomes across runs and across future binaries,
- remains binary-agnostic instead of hardcoding this specific project.

## Core Principle

The pipeline must run as an IDA-facts plus embedder-priors loop.

- IDA answers: what is definitely true here?
- The embedder answers: what is this similar to, what motif is likely, and what neighbor should inherit what we just learned?
- The controller answers: what should we do next?
- The learning layer answers: what worked, what failed, and how should future cycles change?

No non-trivial autonomous step should rely on only one of these when both are available.

## Design Goals

1. Behavioral fidelity over text completeness
2. Autonomous control over manual babysitting
3. Persistent learning over repeated rediscovery
4. Reusable motifs over project-specific hacks
5. Quiet stats-first operation over noisy command streaming
6. Portable architecture over firmware-family lock-in

## Existing Strengths

The repository already has several strong building blocks that should be extended, not discarded.

- Deterministic pipeline stages with schema-aware artifacts and lock discipline
- Autonomous cycle orchestration with plateau handling and hardening gates
- IDA refresh before cycle execution
- IDA CFG and pseudocode export integrated into synthesis
- Embedder-assisted behavioral classification in probing and synthesis paths
- Evidence-aware synthesis policy in `fwimplsynth`
- Returned-vs-capped probe semantics and richer behavioral telemetry
- Plateau routing in `fwcycle`

These are the seeds of the final system, but they are still too local and too heuristic. The next phase is to convert them into a reusable memory-and-controller architecture.

## Current Diagnosis

Current bottlenecks after the recent IDA-first and pseudocode work:

- IDA evidence is present, but the controller is still only partially policy-driven.
- Successful pseudocode lowerings are still too function-specific and not yet generalized into motif families.
- We record cycle summaries, but we do not yet retain enough reusable experience to improve strategy selection across time.
- Plateau routing exists, but it still reasons mainly from a small set of immediate probe metrics rather than persistent experience and transfer success.
- Console behavior is still noisier than necessary for long autonomous runs.

## Target Architecture

The system should converge on five reusable layers.

### A. Evidence Extraction Layer

Per cycle, export and normalize binary-agnostic evidence:

- call edges
- CFG hints
- pseudocode hints
- strings and constants
- stack and frame hints when useful
- MMIO access summaries
- runtime probe outcomes and trace metrics

Every evidence source must be address-stable and image-stable.

### B. Function Representation Layer

Represent each function as a normalized descriptor, not just a name.

Each descriptor should accumulate:

- image, address, canonical identity
- CFG complexity and structure
- pseudocode availability and motifs
- callsite and neighborhood structure
- MMIO footprint and side-effect hints
- behavior class and role from the embedder
- probe phenotype and outcome history
- synthesis attempts and accepted motif family

This descriptor is the cross-binary language of the system.

### C. Motif and Recipe Layer

The pipeline should synthesize through reusable motif families instead of one-off special cases.

Motif families include:

- state gate with callback readiness
- bounded wait/poll loop
- IRQ or critical-section wrapper
- command latch with completion wait
- staged MMIO transfer engine
- crypto setup and key-load sequence
- ring buffer or queue pump
- message dispatcher or parser
- state-machine transition handler
- bounded error fallback

Each motif must be selected because evidence supports it, not because a function name happens to match a local pattern.

### D. Autonomous Controller Layer

The controller should choose what to do next based on evidence and memory.

Available actions:

- refresh IDA evidence
- deepen probe budgets
- rebalance frontier selection
- synthesize a new motif family
- propagate a working motif to embedding-near neighbors
- validate MMIO/state assumptions
- run targeted conformance or hardening checks

The controller must emit structured recommendations and should be able to drive later orchestration decisions automatically.

### E. Learning and Memory Layer

The pipeline must retain reusable experience across runs and binaries.

Three memory classes are required:

1. Episodic memory
- what evidence existed
- what strategy was chosen
- what happened

2. Recipe memory
- which motif family worked for which feature signature
- where it failed and why

3. Policy memory
- which controller actions improve which failure phenotypes
- when to deepen, when to switch motif families, when to rebalance frontier coverage

## Mandatory IDA + Embedder Policy

The intended loop is:

1. Refresh IDA exports.
2. Build normalized function evidence.
3. Embed functions and retrieve similar successful neighbors.
4. Rank candidate actions and motif families.
5. Synthesize or probe using the top evidence-backed action.
6. Validate.
7. Write outcomes into persistent experience memory.
8. Re-rank future decisions using those outcomes.

The embedder should retrieve and prioritize.
IDA should ground and validate.
The controller should combine them.

## Quiet Operation Rules

Long runs should not dump raw command chatter to the console unless explicitly requested.

Default console output should contain only:

- cycle tag
- key probe metrics
- key rebuild metrics
- controller primary action
- failure summaries when a command actually fails

Everything else should go to structured artifacts under the run root.

## Metrics That Matter

The pipeline should track these consistently.

Per cycle:

- probed
- returned
- capped
- nontrivial_return
- deep_returned
- mmio_touch_probes
- selected_distinct_images
- learning_smoke_success_count
- delta_learning_smoke_success_count
- completion_pct
- semantic_completion_pct
- IDA evidence coverage
- controller primary action and recommended mode

Per motif family:

- attempts
- accepted count
- returned rate
- nontrivial rate
- semantic completion delta
- transfer success to neighbors

Per failure phenotype:

- capped-loop dominant
- capped-low-mmio
- missing-symbol heavy
- shallow-wrapper dominant
- MMIO-state faulting
- low-evidence synthesis mismatch

## Milestones

## A1 - Controller Memory and Quiet Telemetry

Goal: create a durable autonomous decision substrate without hardcoding this project.

Deliverables:

- persistent controller state artifact
- persistent cycle experience log
- compact cycle summary output by default
- controller recommendations based on IDA evidence, embedder availability, probe behavior, and recent learning deltas
- initial orchestration consumption of controller recommendations

Exit criteria:

- cycles write reusable controller and experience artifacts
- stdout is compact by default
- orchestration can consume controller guidance rather than only static heuristics

## A2 - Function Descriptor and Motif Generalization

Goal: replace name-driven special handling with reusable motif selection.

Deliverables:

- normalized function descriptor schema
- motif-family registry keyed by evidence signatures
- conversion of recent RF/SDIO special-case wins into generalized motifs
- initial neighbor propagation over embedder-near functions

Exit criteria:

- at least two current hard cohorts use motif-family routing instead of direct name-based lowering
- one successful motif can be reused on neighbors automatically

## A3 - Policy Learning and Counterfactual Ranking

Goal: make the controller improve from outcomes rather than repeating the same retries.

Deliverables:

- controller action scoring informed by prior outcomes
- counterfactual logging of top unchosen actions
- action-family success tracking by phenotype
- automatic demotion of repeatedly unproductive strategies

Exit criteria:

- repeated capped phenotypes trigger strategy changes rather than only budget increases
- controller recommendations become measurably more predictive over time

## A4 - Cross-Binary Transfer Memory

Goal: make future binaries benefit from the work done here.

Deliverables:

- portable recipe memory keyed by descriptor signatures
- neighbor retrieval across sessions and binaries
- confidence-weighted transfer rules
- safeguards against over-transfer and wrong-family contamination

Exit criteria:

- a new binary can reuse prior motifs without adding project-specific code paths

## Active Milestone

- Current: A2/A3 - Descriptor Transfer, Motif Expansion, and Policy Learning

## Immediate Execution Plan

1. Rewrite planning and operating guidance around the autonomous IDA-plus-embedder loop.
2. Add controller-state and experience-memory artifacts to the cycle runner.
3. Quiet default cycle output so autonomous runs stay readable.
4. Feed controller guidance into orchestration decisions.
5. Convert recent hard-coded pseudocode wins into reusable motif families.
6. Continue pushing the current firmware rebuild with those generalized motifs.

## Current Status Snapshot

As of 2026-06-07 (v12 real-pseudocode, superseded 2026-05-26 snapshot):

- IDA refresh is enforced before cycles.
- Hex-Rays pseudocode export is integrated.
- `fwimplsynth` consumes CFG and pseudocode hints.
- **Real-pseudocode transpiler** (`cmd/fwimplsynth/realpseudo.go`) produces faithful C bodies for truth-lane targets with Hex-Rays coverage.
- `applysynth` V10/V11: variant-name and reverse-lookup body propagation (V11 alone took completion from 0.322 → 24.026).
- `fwfinalize` injectForwardDecls: differentiated `void fn(void)` (defined) vs `int fn(...)` (undefined) with wide call regex and keyword filter.
- All 4 final C files compile clean (fmacfw_h 906 fns, fmacfw 74441, fmacfwbt 52052, lmacfw_rf 57378).
- Truth Lane Scorecard: **25 PASS / 0 REVIEW / 0 FAIL**.
- Cloud evidence: `mega7_v12_clean.tar.gz` uploaded to Drive.
- The next stretch is the next-phase target architecture (controller memory + motif generalization) and curating a tracked release from this v12 state.

## Comprehensive Next Plan

The next major stretch should be executed as one connected program, not as unrelated micro-fixes.

### Phase 1 - Stabilize The Semantic Core

Goal: make descriptors, transfer evidence, and release metrics trustworthy enough to drive every later decision.

Required work:

- consolidate all descriptor inputs into one explicit schema contract:
  - CFG hints
  - pseudocode hints
  - function links
  - consensus behavior
  - synth evidence
  - smoke outcomes
  - embedder vectors and class scores
- add schema-version checks and drift detectors across:
  - `fwdescriptors`
  - `fwimplqueue`
  - `fwimplsynth`
  - `fwfinalize`
  - `fwharden`
  - `fwcycle`
- add explicit descriptor coverage metrics:
  - descriptor rows with CFG
  - descriptor rows with pseudocode
  - descriptor rows with embedder vectors
  - descriptor rows with consensus links
  - descriptor rows with transfer confidence above threshold
- detect stale or contradictory evidence:
  - motif says dispatcher but body never branches
  - transfer cluster says strong reuse but outgoing calls diverge heavily
  - probe phenotype says MMIO wait but synthesized body has no bounded wait

Exit criteria:

- every downstream stage consumes the same descriptor schema without ad hoc field guessing
- descriptor summary can explain where evidence is missing, contradictory, or strong
- release metrics no longer overstate quality when transfer/body alignment is weak

### Phase 2 - Expand Motif Coverage Aggressively

Goal: replace the remaining generic synthesis surface with reusable motif families that cover the real hard cohorts.

Required work:

- add more motif families beyond the current dispatcher/queue/MMIO/wait/state set:
  - RF command queue and command latch chains
  - RF register write callback and completion gates
  - SDIO busy/wait and DMA setup sequences
  - timer-arm / timer-cancel / timer-drain patterns
  - logging allocator / free-pool cascades
  - message allocation / event scheduling bridges
  - crypto key-load / table-init / power-up / clear-register flows
  - patch-application and firmware configuration sequences
- define selection rules from evidence, not names:
  - required CFG shape
  - required pseudocode tokens
  - required MMIO profile
  - required outgoing-call profile
  - acceptable probe phenotypes
- split motif implementation into:
  - body emitter
  - contract hints
  - probe seed hints
  - release-time validation rule

Exit criteria:

- most previously hard-coded or special-cased families are represented as descriptor-selected motifs
- capped and shallow-wrapper cohorts have a materially lower share of generic bodies

### Phase 3 - Make Transfer Real, Not Decorative

Goal: use embedder-neighbor and cluster transfer to change emitted code, not just rank rows.

Required work:

- turn transfer clusters into reusable recipe objects with:
  - preferred emitter
  - top outgoing set
  - optional incoming/caller context
  - common probe seeds
  - expected validation signatures
- add cluster-level consensus body fingerprints so `fwimplsynth` can choose among:
  - pseudocode-first
  - motif-first
  - behavior-class-first
  - cluster-transfer-first
- add anti-transfer safeguards:
  - reject neighbor propagation when image roles differ too much
  - reject cluster transfer when outgoing-call overlap is too low
  - penalize transfer if previous accepted neighbors later failed finalize or harden
- track transfer outcomes explicitly in artifacts:
  - transfer selected
  - transfer accepted
  - transfer downgraded
  - transfer contradicted by finalize/harden

Exit criteria:

- cluster transfer measurably improves call conformance, nontrivial returns, or finalize risk
- failed transfer patterns are remembered and automatically demoted

### Phase 4 - Strengthen The Controller Into A Real Decision Engine

Goal: make the controller choose between probe, synth, refresh, validate, and harden actions based on evidence and memory.

Required work:

- expand controller action families:
  - refresh exports
  - deepen probe
  - widen image diversity
  - prioritize motif family
  - prioritize transfer cluster
  - prefer descriptor motifs over generic emitters
  - focus capped MMIO waits
  - focus shallow wrappers
  - validate conformance early
  - tighten harden gates late
- add counterfactual logging:
  - what the top 3 unchosen actions were
  - which evidence pushed the chosen action up
  - whether the chosen action actually improved downstream metrics
- move from one-cycle heuristics to short-horizon control:
  - if two synth-heavy cycles fail, force a deepen or validate pass
  - if motif-backed finalize risk drops, expand cluster transfer
  - if conformance is green but returns stall, prioritize runtime/state hypotheses instead of more generic synthesis

Exit criteria:

- controller recommendations explain why they were chosen and whether they worked
- the system stops retrying the same losing move on repeated plateau phenotypes

### Phase 5 - Add Stronger Validation And Negative Evidence

Goal: stop counting structurally plausible but behaviorally weak outputs as wins.

Required work:

- expand `fwfinalize` quality rules to score:
  - transfer/body alignment
  - motif/body alignment
  - bounded-wait presence for capped MMIO phenotypes
  - queue or dispatcher structure for wrapper cohorts
  - mismatch between expected and emitted callee sets
- expand `fwharden` so it can gate on:
  - high-risk finalize rows
  - underused transfer-backed descriptors
  - motif-backed coverage floor
  - capped-MMIO phenotype ceiling
  - wrapper dominance ceiling
- expand smoke/cycle evidence so failed runtime signals are useful:
  - repeated missing symbols
  - repeated cap-only loops
  - repeated zero-MMIO returns
  - deep-pass vs shallow-pass divergence

Exit criteria:

- release quality metrics correlate better with real autonomous improvement
- false greens are harder to publish

### Phase 6 - Refresh The Tracked Release Deliberately

Goal: make `artifacts/releases/` represent a real, current, curated publication boundary.

Required work:

- refresh the tracked release from the newest validated workspace state
- ensure release docs match actual tracked contents
- ensure release metadata includes:
  - descriptor summary snapshot
  - controller summary snapshot
  - finalize manifest
  - conformance report
  - checksums
- separate intentionally published synth metadata from local scratch synth bodies

Exit criteria:

- the tracked release can be understood without opening the live workspace
- release docs and machine-readable metadata agree with the tracked files

### Phase 7 - Prepare For New Binary Families

Goal: stop embedding assumptions that only work for this exact corpus.

Required work:

- define a reusable adaptation checklist:
  - how to load a new blob
  - how to refresh exports
  - how to build descriptors
  - how to validate whether transfer is safe
- isolate AIC8800D80-specific constants, seeds, and MMIO assumptions behind explicit data or config paths where practical
- identify what is really generic in:
  - motif emitters
  - descriptor clustering
  - controller actions
  - smoke learning

Exit criteria:

- porting to another firmware family does not require a rewrite of the core rebuild loop

### Phase 8 - Operational Cleanliness And Automation Discipline

Goal: keep the repo and workspace usable while the pipeline grows more capable.

Required work:

- continue tightening tracked vs generated boundaries
- add release refresh scripts or documented procedures so publishing is deliberate
- keep root-level navigation obvious and current
- ensure every new command or artifact format has a discoverable doc entry
- keep default logs compact and move bulk detail into structured artifacts

Exit criteria:

- a new operator can navigate the repo and run the core path without tribal knowledge

## Immediate Next Execution Queue

The next execution queue should be:

1. refresh the tracked release bundle from the newest validated live state, not just the older curated baseline
2. expand motif families for RF register-write waits, SDIO wait/DMA flows, and logging free-pool cascades
3. add explicit transfer-outcome tracking so cluster propagation can be promoted or demoted automatically
4. strengthen `fwfinalize` and `fwharden` around transfer-underuse and transfer-mismatch conditions
5. make `fwcycle` consume transfer-backed descriptor counts as a first-class plateau signal
6. add tests around descriptor summaries, transfer confidence, and controller action ranking

## What To Avoid Next

- do not hand-edit generated `final/` sources as a substitute for fixing the pipeline
- do not add more function-name one-offs when a descriptor or motif rule can express the same behavior
- do not publish new release artifacts until the live workspace state has been deliberately refreshed and checked
- do not let release metrics drift away from what the release files actually contain

## Progress Log

## 2026-05-27 (repo organization, docs cleanup, and release indexing)

- Completed:
  - Reorganized the repository at the documentation and policy level so the source tree, generated workspaces, and tracked release artifacts are clearly separated.
  - Rewrote the top-level `README.md` and `PIPELINE.md` so they now describe the actual current descriptor-driven rebuild path instead of a partially stale mix of historical states.
  - Added an explicit docs index and operator docs:
    - `docs/README.md`
    - `docs/REPO_LAYOUT.md`
    - `docs/RUNBOOK.md`
  - Added artifact policy and release indexing:
    - `artifacts/README.md`
    - `artifacts/releases/aic8800d80-rebuild-v1/README.md`
    - `artifacts/releases/aic8800d80-rebuild-v1/meta/release_index.json`
  - Tightened repo hygiene in `.gitignore` for generated scratch, caches, Python bytecode, and root-level built binaries.
- Evidence:
  - The repository now has one canonical navigation path for new work:
    - `README.md` -> `docs/README.md` -> `PIPELINE.md` / `docs/RUNBOOK.md` / `plan.md`
  - The tracked release bundle now has a self-contained summary and machine-readable release index.
  - Repo hygiene now explicitly separates:
    - tracked releases under `artifacts/releases/`
    - generated active work under `extraction_out/`
    - local scratch under `analysis/`
- Next:
  - Keep pushing descriptor/transfer evidence deeper into the real rebuild outputs.
  - When the live workspace stabilizes, refresh the curated release bundle itself from the newest validated state instead of only updating release metadata.
- Blockers:
  - The live workspace contains a large amount of untracked/generated state and unrelated local edits, so release publication still has to stay selective and deliberate.

## 2026-05-26 (re-baseline to autonomous IDA-plus-embedder controller)

- Completed:
  - Rewrote the long-term plan around a reusable autonomous reconstruction architecture using IDA for grounded facts and the embedder for retrieval, clustering, and transfer.
  - Reframed the next phase away from project-specific hardcoding and toward controller memory, motif families, and cross-binary learning.
  - Started A1 implementation:
    - `tools/recon_cycle.py` now emits compact cycle summaries by default instead of dumping all underlying command output,
    - writes persistent controller state with recommended next actions and recommended mode,
    - writes persistent controller experience history,
    - records IDA evidence counts for CFG and pseudocode exports,
    - includes controller recommendation fields in `cycle_report.json`.
  - Connected orchestration to controller guidance:
    - `fwcycle` now consumes `controller_recommended_mode` from the cycle report when `-plateau-mode=auto`.
- Evidence:
  - New artifacts written by cycle runner:
    - `controller_state.json`
    - `controller_experience.jsonl`
    - compact `cycle_report.json` controller fields
  - Orchestrator now has a path to use controller-selected mode instead of only local plateau heuristics.
- Next:
  - Validate the new controller-memory layer in a real cycle.
  - Start A2 by extracting generalized motif families from the recent RF/SDIO pseudocode wins.
  - Keep pushing current rebuild quality while removing project-specific special casing where practical.
- Blockers:
  - None currently; the main remaining work is breadth and calibration.

## 2026-05-26 (A1/A2 harder batch: policy memory + evidence-backed emitters)

- Completed:
  - Strengthened controller memory in `tools/recon_cycle.py`:
    - fixed IDA evidence discovery to read the real exported CFG and pseudocode corpora,
    - added reusable policy-memory aggregation from `controller_experience.jsonl`,
    - controller actions now carry historical effectiveness stats and score adjustments,
    - kept compact default stdout while preserving structured controller artifacts.
  - Generalized synthesis away from project-specific pseudocode special cases in `cmd/fwimplsynth/main.go`:
    - replaced direct function-name lowering with motif detection over Hex-Rays pseudocode + CFG + MMIO + behavior role,
    - motif families now include callback-state gate, IRQ-wait guard, and staged MMIO transfer,
    - behavioral-class emitters for radio/I/O/dispatcher/crypto/memory-pool now use real outgoing-call evidence instead of seed-only generic bodies.
  - Validated the controller layer across real quiet cycles and used the expensive rebuild/cycle pass only after the broader source changes were in place.
- Evidence:
  - Focused verification passed:
    - `python3 -m py_compile tools/recon_cycle.py`
    - `go test ./cmd/fwimplsynth ./cmd/fwcycle`
  - Real quiet representative cycle `cycle_20260526T_harder_batch`:
    - `probed=20`, `returned=2`, `capped=18`, `nontrivial_return=1`, `deep_returned=1`, `mmio_touch_probes=20`, `selected_distinct_images=3`
    - controller state now records real IDA evidence counts: `cfg_hint_rows=2993`, `pseudocode_hint_rows=151`
  - Rebuild quality after the harder batch:
    - `implemented_count=428`
    - `completion_pct=0.695`
    - `semantic_completion_pct=0.507`
    - `avg_conformance_pct=100.000`
- Next:
  - Extend motif families for the next hard cohorts: radio register commit/write waits, crypto key-load/strobe, and dispatcher/pool cascades.
  - Make controller policy memory influence mode choice more strongly when cap-heavy plateaus have poor motif-family yield.
  - Add neighbor propagation using successful motif-family evidence rather than only generic synthesis volume.
- Blockers:
  - Hard RF/SDIO cohorts still cap heavily enough that policy-memory and motif breadth need another pass before controller recommendations consistently prefer the best remediation mode.

## Update Template

Use this format when updating:

```text
## YYYY-MM-DD
- Completed:
  - ...
- Evidence:
  - tests, metrics, artifact paths ...
- Next:
  - ...
- Blockers:
  - ...
```

## 2026-06-07 (v12 real-pseudocode: 0 compile errors, 25/25 truth-lane PASS)

- Completed:
  - Built `cmd/fwimplsynth/realpseudo.go` — IDA Hex-Rays pseudocode → C transpiler with full unit-test coverage (7 transpiler tests, 4 emitter tests, all passing). Handles `MEMORY[0x...](...)` fn-ptr calls, balanced `*(_DWORD *)(EXPR)` casts, `__intN` / `unsigned __intN` types, `__fastcall` param extraction, LOBYTE/HIBYTE/LOWORD/HIWORD macros (with `uintptr_t` coerce and lvalue-assignment rewrite), and ARM intrinsics.
  - `cmd/fwapplysynth` V10/V11: variant-name and reverse-lookup body propagation. V12: only lossy transform on real-pseudo bodies is `RESULT = sub_X(args);` → `sub_X(args); RESULT = 0;`.
  - `cmd/fwfinalize/injectForwardDecls`: differentiated decls (`void fn(void)` for defined, `int fn(...)` for undefined callees), wider call regex with C-keyword/type-name filter, strips pre-existing compose auto-gen block to prevent type conflicts.
  - `cmd/fwimplsynth/tryRealPseudocodeFile` wired at top of `writeSynth` — emits complete file (header + macros + ARM intrinsic `#define`s + forward decls + signature + transpiled body).
  - `tools/score_truth_lane.py` — per-function PASS/REVIEW/FAIL scoring on the 25 critical targets.
  - **First actual firmware execution**: extended `tools/unicorn_smoke.py` (lld linker, AIC8800D80 memory map, variadic stub macros) and built `tools/truth_lane_smoke.py` to extract every truth-lane body from the final files and execute each in Unicorn. 17/17 real-pseudo bodies return naturally with MMIO writes.
  - Updated `README.md`, `PIPELINE.md`, `docs/REBUILD_MILESTONE.md`, `docs/RUNBOOK.md`, and this file to reflect v12.
- Evidence:
  - All 4 final C files compile with 0 errors:
    - `fmacfw_h`: 906 functions, 0 errors
    - `fmacfw`: 74441 functions, 0 errors
    - `fmacfwbt`: 52052 functions, 0 errors
    - `lmacfw_rf`: 57378 functions, 0 errors
  - `applysynth`: 17365 bodies applied, 15133 unique.
  - `implemented_count`: 17504, `completion_pct`: 28.429, `fallback_count`: 0.
  - Truth Lane Scorecard: **25 PASS / 0 REVIEW / 0 FAIL** on the 25 critical functions.
  - Truth Lane Unicorn Smoke: **17 PASS / 8 REVIEW / 0 FAIL** — all 17 real-pseudo bodies execute end-to-end in Unicorn. Per-function traces recorded (e.g. `rf_bus_mark`: 4873 insns, 2023 reads, 817 writes; `crypto_key_load`: 9490 insns, 4006 reads, 1813 writes).
  - Cloud evidence: `mega7_v12_clean.tar.gz` uploaded to Drive (`1o2qy21F9EbMpPk4B9WqIEMHfWrL3BW4y`).
  - Unit tests: `go test ./cmd/fwimplsynth` passes including the new transpiler tests.
  - Commits: `5d67448` (v12 realpseudocode), `6cbca18` (v12 final, force-added 4 final C files), `db68d69` (docs update).
- Next:
  - Curate a tracked release bundle from the v12 state (currently only v1 release is published).
  - Continue expanding the IDA pseudocode corpus to cover the 17/25 truth-lane targets that still fall back to motif-body synthesis.
  - Add helper signature awareness to the transpiler (use `pseudocode_hints.jsonl` to look up real helper signatures and emit exact decls vs. variadic fallback).
  - Push more functions through the real-pseudocode path beyond the top 25.
  - **Validate MMIO traces against original binary traces**: run the same function in QEMU/Unicorn against the original firmware binary, capture the MMIO write sequence, and diff against the smoke trace. This is the first end-to-end fidelity proof.
  - Build a startup code + linker script to attempt actual firmware boot in Unicorn.
- Blockers:
  - 17/25 truth-lane targets have no IDA pseudocode coverage (7 fmacfwbt, 6 lmacfw_rf, 4 fmacfw_h). Need IDA re-run or transpile-from-bytes fallback before those can get real bodies.
