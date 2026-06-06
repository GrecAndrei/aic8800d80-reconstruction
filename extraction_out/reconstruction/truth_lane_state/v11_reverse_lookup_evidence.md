# V11 — Reverse lookup: base synth body applied to per-address variants

## Background
V10 (`45977d1`) fixed the case where a synth file keyed by a
variant name (e.g. `rf_bus_write2_n3cd`) was not being applied to
the base-name def (`rf_bus_write2`) in the final C. The base body
now reaches the base def, and the function signature is rewritten
to drop the variant suffix.

## The next layer
The final C also contains per-address variant defs like
`rf_bus_mark_n_456`, `rf_bus_mark_n_221`, ... that the function
resolver created (one def per `name × address` pair). These share
a base name with the canonical def, and the synth body for the
base is by construction a motif-based template that applies to
all variants.

V11 makes `applyBodies` fall back to `bodies[baseVariantName(fn)]`
when `bodies[fn]` misses, so a single base body is propagated to
every variant def in the file. The signature-rewrite logic from
V10 already handles the rename from base to variant signature.

## Verified impact (mega7_v9_test cycle)

| metric                       | pre-fix | v10 (base→var) | v11 (base↔var) |
| ---------------------------- | ------- | -------------- | -------------- |
| functions_applied (apply)    | 33      | 54             | 14649          |
| unique_functions_applied     | 16      | 23             | 12499          |
| implemented_count (finalize) | 177     | 198            | 14793          |
| completion_pct               | 0.287   | 0.322          | 24.026         |
| semantic_completion_pct      | 0.062   | 0.133          | 23.838         |
| TODO count (finalize)        | 61509   | 61372          | 46777          |
| TODO in lmacfw_rf file       | 19094   | 19076          | 9553           |
| final C files compile        | 4/4     | 4/4            | 4/4            |

Canonical `extraction_out/reconstruction/mega7/final/` was promoted
to the V11 output. CI compile check (`tools/ci_compile_final.py`):
all 4 files compile cleanly.

## Caveat
Completion_pct = 24% counts any non-TODO body, including the
synth motif templates. The synth currently produces generic
"register_commit" / "bounded_poll" templates with role/pre/
evidence comments and a state-mix preamble, but does not yet
emit function-specific logic. The next fidelity gap is making
synth bodies actually reflect the function's observed behavior
(register accesses, call patterns, cross-image projections) —
not just the motif template.
