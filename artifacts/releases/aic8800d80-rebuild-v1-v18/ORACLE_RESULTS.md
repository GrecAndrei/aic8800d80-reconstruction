# v18 Compile-Oracle Results

**19,161 functions compared | 89% at 100% match | 94.1% avg match**

| Bucket | Count | % |
|--------|------:|--:|
| 100% match | 17,070 | 89% |
| ≥80% match | 391 | 2% |
| ≥50% match | 635 | 3% |
| <50% match | 1,065 | 6% |
| **Total ok** | **19,161** | 99% |
| Fail (no symbol / no disasm) | 147 | 1% |

## What this means

For 17,070 functions, the v18 inline-asm body is **byte-for-byte identical** to
the original ARM Thumb code in the firmware binary. The compiled .elf symbol
table points to the same bytes, so any disassembly tool would produce identical
mnemonics and arguments.

The 6% partial-match cases are mostly:
- Functions that share a name across disambiguated variants
- Function-end detection capturing slightly more or less than the real `bx lr`
- Naming pipeline assigning a wrong address (string table vs. code)

The 1% fail cases are where the named function has no symbol in the compiled
ELF (was filtered by bad_addr check) or no disasm available in the original
binary (off the loaded image).
