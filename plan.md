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

- Current: A1 - Controller Memory and Quiet Telemetry

## Immediate Execution Plan

1. Rewrite planning and operating guidance around the autonomous IDA-plus-embedder loop.
2. Add controller-state and experience-memory artifacts to the cycle runner.
3. Quiet default cycle output so autonomous runs stay readable.
4. Feed controller guidance into orchestration decisions.
5. Convert recent hard-coded pseudocode wins into reusable motif families.
6. Continue pushing the current firmware rebuild with those generalized motifs.

## Current Status Snapshot

As of 2026-05-26:

- IDA refresh is enforced before cycles.
- Hex-Rays pseudocode export is integrated.
- `fwimplsynth` can consume CFG and pseudocode hints.
- Adaptive probe budgets exist.
- Plateau routing exists.
- Recent direct pseudocode lowering improved representative hard-cohort behavior.
- The next necessary step is not more one-off lowering. It is persistent controller memory plus motif generalization.

## Progress Log

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
