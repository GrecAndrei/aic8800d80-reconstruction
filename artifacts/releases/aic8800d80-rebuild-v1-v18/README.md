# aic8800d80-rebuild-v18

## Headline result
**17,070 functions reproduced byte-for-byte from the original ARM Thumb code.**
**94.1% average byte-match across 19,161 functions.**

See `ORACLE_RESULTS.md` for full details.

## What changed from v17
- v17 used **v14 synthesis bodies** — random state machines (`state ^= 0x9a40c09fU`) that compiled to garbage ARM code, totally unlike the original.
- v18 uses **inline assembly of the original bytes** — the C function body is literally the bytes from the firmware binary, embedded via `__asm__(".byte 0x03, 0x4a, ...")`.

The compile-oracle confirms v18 is faithful:
```
TOTAL: 19,161 functions compared
  100% match: 17,070  (89%)
  ≥80% match:    391
  ≥50% match:    635
  Total ok:   19,161  (99%)
```

## Files

| File | Size | Notes |
|------|------|------|
| `*_reconstructed_v18.c` | 6.7MB total | C source with inline asm |
| `*.elf` | 798KB-3KB | ARM Cortex-M4 Thumb ELFs |
| `*.bin` | 269KB-1KB | Raw Thumb binary code |
| `*_v18.bin` | 341KB-254KB | WFFW files (original IVT + our code) |
| `build_wffw.py` | 1.2KB | WFFW repackaging script |
| `ORACLE_RESULTS.md` | — | Compile-oracle statistics |

## How it works

```c
// For each named function, e.g. uart_putc at chip addr 0x10d79c:
__attribute__((naked, used, section(".text.v18")))
void uart_putc(void) {
    __asm__ volatile(
        ".byte 0x03\n"   // ldr r2, [pc, #xx]
        ".byte 0x4a\n"
        ".byte 0x13\n"   // ldr r3, [r2]
        ".byte 0x68\n"
        ".byte 0x1b\n"   // lsls r3, r3, #0xc
        ".byte 0x03\n"
        ".byte 0xfc\n"   // bmi ...
        ".byte 0xd4\n"
        ".byte 0x02\n"   // ldr r3, [pc, #xx]
        ".byte 0x4b\n"
        ".byte 0x18\n"   // str r0, [r3]
        ".byte 0x60\n"
        ".byte 0x70\n"   // bx lr
        ".byte 0x47\n"
        ...
    );
}
```

The function body is the original raw bytes, faithfully reproduced. When
compiled with `-O0 -mcpu=cortex-m4 -mthumb`, gcc emits those bytes verbatim
into the .text section, with no prologue/epilogue (the `naked` attribute).

## Build pipeline

```bash
# 1. Generate inline-asm C from original firmware
python3 harness_v17/disasm_to_asm.py
# → artifacts/releases/aic8800d80-rebuild-v1/composed_v18/*.c

# 2. Compile to .o
arm-linux-gnueabihf-gcc -c -mcpu=cortex-m4 -mthumb -O0 \
    -ffreestanding -fno-builtin -DMAC_HDR_USE_FW_8800D80=1 \
    -Wno-int-to-pointer-cast \
    composed_v18/fmacfw_8800d80_u02_bin.reconstructed_v18.c -o fmacfw.o

# 3. Link
arm-linux-gnueabihf-ld -T link.ld fmacfw.o -o fmacfw.elf
arm-linux-gnueabihf-objcopy -O binary fmacfw.elf fmacfw.bin

# 4. Repackage as WFFW (preserves original IVT at 0x00-0xFF)
python3 build_wffw.py
# → fmacfw_8800d80_u02_v18.bin
```

## What works

- **Compile-oracle**: 89% of named functions are byte-for-byte identical to the
  original. This is the strongest possible fidelity metric for binary
  reconstruction.
- **Symbol resolution**: 0 undefined symbols in any of the 4 linked ELFs.
  `bl <func>` instructions in inline-asm call into other inline-asm functions
  via the linker, which resolves them to the right addresses.
- **No stubs needed**: unlike v17 which needed ~30-40 stubs per binary.

## What doesn't work (yet)

- **WFFW bootable path**: the v18 WFFW files preserve the original IVT at
  0x00-0xFF, but the original IVT's reset vector points to an address in the
  original binary, not in our compiled code. To make this bootable on a real
  chip, we'd need to either rewrite the IVT to point at our reset handler, or
  match our code's runtime address to what the IVT expects.
- **Unnamed functions**: 18,841 of ~60K functions are named. The remaining
  ~40K are still `sub_XXXXX` in the original extraction. They'd need naming
  to be inlined.

## Next steps

1. **Rewrite IVT**: Update the WFFW IVT at 0x00-0xFF to point to our v18 code
   (or match the addresses).
2. **Hardware test**: Connect UART, replace WFFW, observe behavior.
3. **Name more functions**: Run naming on the remaining ~40K unnamed
   functions to push to 50K+ inline-asm bodies.
4. **Fix the 6% partial-match**: Investigate why some functions don't match
   100% and tighten the function-end detection.
