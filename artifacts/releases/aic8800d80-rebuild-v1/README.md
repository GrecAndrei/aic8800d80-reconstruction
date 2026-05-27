# aic8800d80-rebuild-v1

This is the current curated tracked release snapshot for the AIC8800D80 reconstruction pipeline.

## Contents

- `final/`: 9 tracked files including the 4 reconstructed image outputs and quality/conformance reports
- `meta/`: 5 tracked files including manifests, checksums, and release metadata
- `synth/`: 2 tracked release-level synthesis metadata files

## Published Metrics

From `final/finalize_manifest.json` and `final/call_conformance.json`:

- `function_count`: `356`
- `implemented_count`: `356`
- `strong_count`: `356`
- `fallback_count`: `0`
- `semantic_completion_pct`: `100.000`
- `evaluable_count`: `352`
- `avg_conformance_pct`: `100.000`

## Key Files

- `final/fmacfw_8800d80_h_u02_bin.reconstructed.c`
- `final/fmacfw_8800d80_u02_bin.reconstructed.c`
- `final/fmacfwbt_8800d80_u02_bin.reconstructed.c`
- `final/lmacfw_rf_8800d80_u02_bin.reconstructed.c`
- `final/finalize_manifest.json`
- `final/finalize_quality.json`
- `final/call_conformance.json`
- `meta/rebuild_manifest.json`
- `meta/applysynth_manifest.json`
- `meta/final_sources.sha256`
- `meta/release_index.json`

## Notes

- This release is the tracked publication boundary.
- The live workspace under `extraction_out/reconstruction/mega7/` may contain newer experimental state than this release.
- Additional local synthesis files may exist in the workspace, but they are not part of the curated tracked release unless explicitly added.
