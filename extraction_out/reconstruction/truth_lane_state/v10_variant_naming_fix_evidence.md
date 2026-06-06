# V10 — Variant naming fix: synth bodies applied to base-name functions

## The bug
The synth emits one body per implqueue task. Tasks for the same
function observed at different addresses get a variant suffix
(`_n<hex>` with optional underscore), so the synth body for
`rf_bus_write2` ended up keyed as `rf_bus_write2_n3cd`.

The final C has the base name (`rf_bus_write2`) since it comes from
the recon/recon_strict canonical name list, not the variant suffix.
`loadSynthBodies` keyed bodies by the extracted function name (the
variant), so the base-name function definition in the final C had
no matching body and stayed a TODO stub.

## The fix (commit 45977d1)
- `loadSynthBodies` now also stores each body under the base name
  (stripping `_n_?[0-9a-f]+$` suffix via `baseVariantName`).
- `applyBodies` rewrites the function signature in the applied body
  to match the source definition's name, so applying a variant body
  to a base-name def does not introduce a variant suffix into the
  final C.

## Verified impact
mega7_v9_test cycle:

| Metric                            | pre-fix | post-fix |
| --------------------------------- | ------- | -------- |
| functions_applied (apply step)    | 33      | 54       |
| unique_functions_applied          | 16      | 23       |
| implemented_count (finalize)      | 177     | 198      |
| todo_count                        | 61509   | 61372    |
| completion_pct                    | 0.287   | 0.322    |
| `rf_bus_write2` body in final C   | TODO    | real synth body (role/pre/evidence + MMIO/state mix) |
| `rf_state_check` body in final C  | TODO    | real synth body |
| `rf_mem_read` body in final C     | TODO    | real synth body |
| variant names in final C          | 0       | 0 (rewritten to base) |
| final C files compile cleanly     | 4/4     | 4/4      |

Canonical `extraction_out/reconstruction/mega7/final/` was promoted
to the post-fix output (TODO count in `lmacfw_rf_8800d80_u02_bin.reconstructed.c`
went 19094 → 19076).

## Test coverage
- `TestBaseVariantNameStripsVariantSuffix`: 6 cases including
  `_n3cd`, `_n92`, `_n_7`, `_n_1a7`, no-suffix passthrough.
- `TestLoadSynthBodiesAlsoStoresUnderBaseName`: writes two synth
  files keyed by `_n3cd` and `_n4d1`, asserts both variant keys AND
  the base key are populated.
- `TestApplyBodiesReplacesBaseNameFromVariantSynth`: applies a
  variant body to a base-name def, asserts body is inlined AND the
  variant suffix is rewritten to the base name.
