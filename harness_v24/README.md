# v24: Cross-Binary Function Map (historical)

> **⚠️ Historical. Superseded by v25 `fwstruct diff`.**
> The unified `fwstruct` tool (Go binary in `bin/fwstruct`, source in
> `cmd/fwstruct/`) now does cross-binary comparison via
> `fwstruct diff`. See `harness_v25/README.md`.

Firmware has 4 binaries (fmacfw_h, fmacfw_u02, fmacfwbt, lmacfw_rf).
Same code lives at the same address in fmacfw_h/u02/bt (they're 3 versions
of the same firmware). lmacfw_rf is a different lower-MAC image.

## What it does

1. **Address-based map**: For each function, find equivalent functions
   in other binaries (matched by address, since ROM base is shared).
   
2. **Variant detection**: Different hash at same address = "variant"
   (small code change between firmware versions).
   
3. **Role classification**: Each function gets a role:
   - `all_fmacfw`: in all 3 fmacfw variants (575 funcs - core code)
   - `h_only` / `u02_only` / `bt_only`: unique to one variant
   - `wifi_no_bt`: in h+u02, not bt
   - `lmac_only`: only in lmacfw_rf

4. **Name propagation**: When 0x100200 is `memset_thunk` in fmacfw_u02,
   propagate that name to the same address in fmacfw_h, fmacfwbt, lmacfw_rf.

## Stats

- 4,675 total functions across 4 binaries
- 4,319 unique addresses (most code is unique to one binary)
- 356 shared addresses
- 43 shared with identical hash, 313 with variant hash
- 51 cross-binary rename candidates, 15 actually renamed

## Outputs

- `cross_map.json`: per-function cross-binary mapping
- `navigation.json`: per-image navigable index
- `propagated_names.json`: name propagation map
- `exact_matches.json`: exact hash matches across images
- `group_meta.json`: per-group metadata (role, images, etc)
- `strings.json`: string references per function (limited - v19 output uses pointers)

## Scripts

- `scripts/cross_match.py`: initial hash+callee matching
- `scripts/cross_match_v2.py`: improved with callee fingerprint
- `scripts/strings.py`: extract strings from binaries + link to funcs
- `scripts/cross_map.py`: per-function map with role classification
- `scripts/address_map.py`: address-based map (primary)
- `scripts/propagate_names.py`: propagate LLM names across binaries
- `scripts/build_release.py`: build navigation index

## Caveat

The "fmacfw" binaries (h, u02, bt) are *not* minor variants - they target
different chip revisions and have largely different code. The shared code
is in shared library routines. The 1,040/1,070/1,081 unique-to-each counts
reflect this.
