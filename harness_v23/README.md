# v23: Annotated v19 C + Field Invariants

Builds on v19 (Hex-Rays decompilation) + v22 (named structs).

## What it does

1. **Annotated C**: For each function in v19 decompiled output, prepend a header
   with the cluster it belongs to, the named struct, and the field list.
   This gives every function a "type context" - which struct it operates on.

2. **Field Invariants**: For each named struct field, build per-field stats:
   - read_count, write_count
   - common readers (top 5 functions reading this field)
   - common writers (top 5 functions writing this field)
   - per-binary breakdown
   - These are real firmware facts derived from instruction patterns

## Outputs

- `annotated/`: 5,945 annotated C files, one per function
  - 251 with named-struct annotations (across 4 binaries)
- `FIELD_INVARIANTS.json`: per-field stats for 20 named structs

## Stats

| Binary | Funcs | Annotated | With named struct |
|--------|-------|-----------|-------------------|
| fmacfw_h | 1290 | 62 | 55 |
| fmacfw_u02 | 1735 | 106 | 63 |
| lmacfw_rf | 1179 | 104 | 70 |
| fmacfwbt | 1741 | 121 | 63 |

## Scripts

- `scripts/annotate_funcs.py`: per-function annotation
- `scripts/field_invariants.py`: per-field stats
