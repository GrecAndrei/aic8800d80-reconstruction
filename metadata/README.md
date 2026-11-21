# Metadata

This directory stores stable metadata associated with the firmware family.

Examples:

- user configuration text
- per-image reconstruction metadata JSON
- image-level descriptors that are useful as durable references

Unlike `extraction_out/`, this directory is intended for stable tracked metadata rather than run-by-run generated state.

## Embedded identifiers

`embedded_identifiers.json` is an index of byte matches, **not a symbol table**.
Each image has a SHA-256 digest of its raw bytes. For each entry:

- `text` is the NUL-terminated ASCII identifier at `string_offset`.
- At each `word_offsets` location, the aligned little-endian 32-bit word equals
  `hardware_base + string_offset`. Both kinds of offsets are relative to the
  start of the raw image, not analysis-space addresses.

The scan considers whole printable runs of at least five characters matching
`[a-z][a-z0-9]*(?:_[a-z0-9]+)+`. Duplicate strings at different offsets are
distinct. A match does not establish that an instruction loads the word, which
function uses it, or whether the text names that function.

This replaces `embedded_names.json`, which attributed each word to the nearest
preceding function start. Do not use that map as labels or to score naming
accuracy. The naming cache and compose inputs are unchanged.

To regenerate, run `tools/fetch_firmware.sh` and then
`python3 tools/recover_embedded_names.py`. No IDA exports or credentials are needed.

## Truth-lane targets

`truth_lane_targets.json` is the fixed input for the unified source smoke check
and original-image verification. The function labels, images and addresses come
from the 25 rows in `artifacts/releases/aic8800d80-rebuild-v1/scorecards/v15_behavioral_25_for_25.json`,
with the documented correction for `log_system_init_mode2` in `AGENTS.md`.
Labels identify historical test cases, not verified vendor names. Addresses
retain the scorecard convention: below `0x100000` they are file offsets;
otherwise they are in analysis space. Pass `--targets` for a different list.

`truth_lane_orig_depth0.json` is the original binaries' depth-0 peripheral
footprint for those targets, written by `tools/aic8800d80_emulator.py verify`
as `orig_depth0_baseline.json`. The smoke check uses it to judge returns that
make no peripheral write; see `docs/TRUTH_LANE_REVIEW_VERDICTS.md`.
