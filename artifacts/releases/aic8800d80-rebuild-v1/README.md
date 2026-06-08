# aic8800d80-rebuild-v1

Current curated tracked release snapshot for the AIC8800D80 reconstruction pipeline (v13 behavioral fingerprint build).

## Contents

- `meta/`: manifests, checksums, and release metadata

Final reconstructed C files and behavioral synth bodies are generated artifacts stored in cloud Drive.
The metadata in this directory describes the v13 build state.

## Published Metrics

From `meta/rebuild_manifest.json`:

- `function_count`: `61570`
- `implemented_count`: `31972`
- `completion_pct`: `51.928`
- `strong_count`: `61570`
- `fallback_count`: `0`
- `semantic_completion_pct`: `100.000`
- **Truth Lane Unicorn Smoke**: 19 PASS / 6 REVIEW / 0 FAIL
- **Behavioral bodies traced**: 2806 MMIO-touching functions across 4 images
- **Cross-image contamination fixed**: per-image filtering via `image=` tags

## Build Info

- Pipeline: compose → descriptors → implqueue → implsynth → applysynth (per-image filtered) → finalize
- Behavioral stage: original binary → Unicorn → MMIO trace → C body (read/write distinguished)
- Cross-image addresses verified: lmacfw_rf uses 0x185xxx, fmacfwbt uses 0x187fxx

## Notes

- This release is the tracked publication boundary.
- The live workspace under `extraction_out/reconstruction/mega7/` contains the full build outputs.
- Generated C files (reconstructed sources) are not tracked in git — hosted in cloud Drive.
