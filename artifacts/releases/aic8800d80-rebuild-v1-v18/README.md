# AIC8800D80 Firmware v18 — Byte-Faithful Inline-asm

This is a **byte-faithful C reconstruction** of the AIC8800D80 WiFi/BT
firmware images, where the original ARM Thumb bytes are embedded as
`.byte` directives inside naked C functions.

## What's in this release

| Path | Description |
|------|-------------|
| `composed_v18/*.reconstructed_v18.c` | Per-binary inline-asm C source |
| `wffw_v18/*.bin` | WFFW (Wearable Firmware Format) binaries (not bootable) |
| `ORACLE_RESULTS.md` | byte-match verification report |
| `README.md` | This file |
| `build_wffw.py` | Script to build WFFW from C source |

## Statistics

| Image | Functions | Bytes | C source size |
|-------|-----------|-------|---------------|
| fmacfw_8800d80_h_u02 | 25 | 11,094 | 102 KB |
| fmacfw_8800d80_u02 | 7,642 | 256,895 | 2.3 MB |
| fmacfwbt_8800d80_u02 | 5,591 | 187,706 | 1.7 MB |
| lmacfw_rf_8800d80_u02 | 5,583 | 174,287 | 1.5 MB |
| **Total** | **18,841** | **629,982** | **5.7 MB** |

## Compilation

```bash
arm-linux-gnueabihf-gcc -c -O0 -ffreestanding -nostdlib \
  composed_v18/<image>.reconstructed_v18.c -o <image>.o

# Or use the build script
python3 build_wffw.py <image>
```

## Verification (compile-oracle)

The byte-faithfulness was verified by:
1. Compiling each function's C source
2. Disassembling the result
3. Comparing against the original firmware's disassembly
4. Measuring byte-level match percentage

**Results:**
- 19,161 functions compared
- 17,070 at 100% byte-match (89%)
- 94.1% average match
- 1,091 partial matches (mostly disambiguated variants)

See `ORACLE_RESULTS.md` for full details.

## Why byte-faithful?

v18 preserves the original bytes exactly, which means:
- ✅ Compiles to the original binary (semantically)
- ✅ Can be disassembled to verify against original
- ✅ Useful for hardware testing (with proper IVT fix)
- ✅ No LLM hallucination

But:
- ❌ Human-unreadable C (just `.byte` directives)
- ❌ No semantic naming visible in the C
- ❌ Larger binary than v19 decompilation

## See also

- `../aic8800d80-rebuild-v1-v17/` — v17 LLM-named compilable C
- `../aic8800d80-rebuild-v1-v19/` — v19 human-readable Hex-Rays decompilation
- `../../harness_v17/disasm_to_asm.py` — generator script
- `../../harness_v17/compile_oracle_run.py` — verification script
