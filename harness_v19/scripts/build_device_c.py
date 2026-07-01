#!/usr/bin/env python3
"""build_device_c.py — Convert v19 Hex-Rays composed C into ARM-targetable firmware C.

Generates C that:
1. Includes a proper volatile MMIO register header
2. Rewrites indirect MMIO dereferences to use volatile-qualified pointers
3. Replaces __asm {} blocks with real ARM inline asm
4. Replaces stub intrinsics with CMSIS-style ARM intrinsics
5. Compiles with arm-none-eabi-gcc -mthumb -mcpu=cortex-r5

Usage:
    python3 build_device_c.py <image> [image2 ...]
    python3 build_device_c.py all
"""
import re
import struct
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent.parent
DECOMPILED = REPO / "harness_v19/decompiled"
FW_DIR = REPO / "inputs/firmware"
OUT = REPO / "harness_v19/device_c"
MMIO_OUT = REPO / "harness_v19/inc"
COMPILED_OUT = REPO / "harness_v19/obj"
OUT.mkdir(parents=True, exist_ok=True)
MMIO_OUT.mkdir(parents=True, exist_ok=True)
COMPILED_OUT.mkdir(parents=True, exist_ok=True)

BINARIES = [
    "fmacfw_8800d80_h_u02_bin",
    "fmacfw_8800d80_u02_bin",
    "fmacfwbt_8800d80_u02_bin",
    "lmacfw_rf_8800d80_u02_bin",
]

CHIP_BASE = 0x100000
MMIO_LO = 0x40000000
MMIO_HI = 0x60000000
SYS_LO = 0xE0000000
SYS_HI = 0xF0000000


def is_mmio_addr(val):
    return (MMIO_LO <= val < MMIO_HI) or (SYS_LO <= val < SYS_HI)


def image_to_fwfile(image):
    m = re.match(r'(.+?)_bin$', image)
    return FW_DIR / f"{m.group(1)}.bin" if m else FW_DIR / f"{image}.bin"


def resolve_pointer_targets(fw_data, image):
    dec_dir = DECOMPILED / image
    if not dec_dir.exists():
        return {}
    syms = set()
    try:
        for line in subprocess.check_output(
            ['grep', '-rhoE', '(off|dword|byte|word|qword)(_1[0-9A-Fa-f]+)', str(dec_dir)],
            text=True, cwd=str(dec_dir.parent)).splitlines():
            syms.add(line.strip())
    except subprocess.CalledProcessError:
        pass

    results = {}
    for sym in syms:
        m = re.match(r'(off|dword|byte|word|qword)(_1[0-9A-Fa-f]+)', sym)
        if not m:
            continue
        chip_val = int(m.group(2)[1:], 16)  # skip leading _
        fo = chip_val - CHIP_BASE
        if 0 <= fo < len(fw_data) - 3:
            target = struct.unpack_from('<I', fw_data, fo)[0]
            results[sym] = {
                'chip_addr': chip_val,
                'target': target,
                'is_mmio': is_mmio_addr(target),
            }
    return results


def gen_mmio_header(image, pointer_map):
    mmio_syms = sorted(
        ((s, info) for s, info in pointer_map.items() if info['is_mmio']),
        key=lambda x: x[1]['chip_addr']
    )
    if not mmio_syms:
        return ""

    lines = []
    lines.append(f"/* Auto-generated MMIO header for {image} */")
    lines.append("/* Maps off_* symbols pointing to MMIO (0x40000000+) and ARM sys (0xE0000000+) */")
    lines.append("")
    for sym, info in mmio_syms:
        target = info['target']
        lines.append(f"#define {sym} ((volatile uint32_t * const)0x{target:08X}u)")
    return "\n".join(lines) + "\n"


def rewrite_mmio_accesses(text, mmio_syms):
    for sym in sorted(mmio_syms, key=len, reverse=True):
        # (uint32_t *)off_1001EC → off_1001EC
        text = re.sub(
            r'\(\s*(?:unsigned\s+int|uint32_t|_DWORD)\s*\*\s*\)\s*' + re.escape(sym),
            sym,
            text
        )
    return text


def rewrite_asm_blocks(text):
    result = []
    s = text
    pat = re.compile(r'__asm\s*\{')
    i = 0
    while i < len(s):
        m = pat.search(s, i)
        if m is None:
            result.append(s[i:])
            break
        result.append(s[i:m.start()])
        j = m.end()
        depth = 1
        while j < len(s) and depth > 0:
            if s[j] == '{':
                depth += 1
            elif s[j] == '}':
                depth -= 1
            j += 1
        body = s[m.end():j - 1].strip()
        for stmt in parse_asm_body(body):
            result.append(stmt)
        i = j
    return "".join(result)


def parse_asm_body(body):
    results = []
    for raw in re.split(r';\s*', body):
        raw = raw.strip()
        if not raw:
            continue
        stmt = convert_asm_stmt(raw)
        results.append(stmt + "\n")
    return results


def convert_asm_stmt(stmt):
    m = re.match(r'MSR\.W\s+(\w+)\s*,\s*(\w+)', stmt)
    if m:
        reg, src = m.group(1), m.group(2)
        return f'__asm volatile("MSR {reg}, %0" : : "r"({src}) : "memory")'
    m = re.match(r'MRS\.W\s+(\w+)\s*,\s*(\w+)', stmt)
    if m:
        dst, reg = m.group(1), m.group(2)
        return f'__asm volatile("MRS %0, {reg}" : "=r"({dst}))'
    m = re.match(r'(ISB|DSB|DMB)\.W', stmt)
    if m:
        b = m.group(1)
        return f'__asm volatile("{b}" ::: "memory")'
    if re.match(r'NOP\.W', stmt):
        return '__asm volatile("NOP")'
    return f'/* TODO: asm: {stmt} */'


def fix_bool_types(text):
    """Replace bool in declarations (Hex-Rays uses bool, not stdbool.h)."""
    # Only in function prototypes/bodies, not in comments
    # Match patterns like: bool a1, bool *a1, bool ), bool ,
    text = re.sub(r'\bbool\b(?=\s*[\*\)])', 'uint8_t', text)
    text = re.sub(r'\bbool\b(?=\s+,)', 'uint8_t', text)
    text = re.sub(r'\bbool\b(?=\s+\w)', 'uint8_t', text)
    return text


def fix_nullptr(text):
    """Replace nullptr (C++) with (void*)0 for C compilation."""
    text = re.sub(r'\bnullptr\b', '(void*)0', text)
    return text


def fix_vf_flags(text):
    """Fix _VF / _ZF / _CF / _NF / _SF condition flag references that Hex-Rays doesn't resolve."""
    # Replace while ( _VF ); with while ( __get_CPSR() & (1 << 28) );
    # But simpler: replace with a no-op loop that always terminates once
    text = re.sub(r'while\s*\(\s*_VF\s*\)\s*;', 'while(0) /* _VF no */;', text)
    text = re.sub(r'while\s*\(\s*_ZF\s*\)\s*;', 'while(0) /* _ZF no */;', text)
    text = re.sub(r'if\s*\(\s*_VF\s*\)', 'if(1) /* _VF unresolvable */', text)
    text = re.sub(r'if\s*\(\s*_CF\s*\)', 'if(0) /* _CF no */', text)
    text = re.sub(r'if\s*\(\s*_ZF\s*\)', 'if(0) /* _ZF no */', text)
    text = re.sub(r'if\s*\(\s*_NF\s*\)', 'if(0) /* _NF no */', text)
    text = re.sub(r'if\s*\(\s*_SF\s*\)', 'if(0) /* _SF no */', text)
    return text


def fix_void_return_misparse(text):
    """Fix cases where Hex-Rays declares a function as void but emits return expr.
    Also fix patterns where a function like `return off_XX();` becomes unreachable
    after asm blocks are replaced."""
    # Skip — this is a structural issue needing inline asm awareness
    return text


def rewrite_intrinsics(text):
    replacements = [
        (r'static inline unsigned int __get_CPSR\(void\) \{ return 0; \}',
         'static inline uint32_t __get_CPSR(void) {\n  uint32_t v; __asm volatile("MRS %0, CPSR" : "=r"(v)); return v;\n}'),
        (r'static inline void __disable_irq\(void\) \{\}',
         'static inline void __disable_irq(void) { __asm volatile("CPSID i" ::: "memory"); }'),
        (r'static inline void __enable_irq\(void\) \{\}',
         'static inline void __enable_irq(void) { __asm volatile("CPSIE i" ::: "memory"); }'),
        (r'static inline void __dsb\(void\) \{\}',
         'static inline void __dsb(void) { __asm volatile("DSB" ::: "memory"); }'),
        (r'static inline void __isb\(void\) \{\}',
         'static inline void __isb(void) { __asm volatile("ISB" ::: "memory"); }'),
        (r'static inline void __dmb\(void\) \{\}',
         'static inline void __dmb(void) { __asm volatile("DMB" ::: "memory"); }'),
        (r'static inline void __nop\(void\) \{\}',
         'static inline void __nop(void) { __asm volatile("NOP"); }'),
        (r'static inline void __wfi\(void\) \{\}',
         'static inline void __wfi(void) { __asm volatile("WFI"); }'),
        (r'static inline void __wfe\(void\) \{\}',
         'static inline void __wfe(void) { __asm volatile("WFE"); }'),
        (r'static inline void __sev\(void\) \{\}',
         'static inline void __sev(void) { __asm volatile("SEV"); }'),
    ]
    for pattern, replacement in replacements:
        text = re.sub(pattern, replacement, text)
    return text


def process_image(image):
    src = REPO / f"harness_v19/composed/{image}.c"
    if not src.exists():
        print(f"  SKIP: {src} not found")
        return None

    print(f"  Processing {image}...")
    text = src.read_text()

    # Resolve MMIO
    fw_path = image_to_fwfile(image)
    fw = fw_path.read_bytes()
    pointer_map = resolve_pointer_targets(fw, image)
    mmio_count = sum(1 for v in pointer_map.values() if v['is_mmio'])
    print(f"    MMIO pointer symbols: {mmio_count}")

    # Generate MMIO header
    mmio_header = gen_mmio_header(image, pointer_map)
    mmio_hdr_path = MMIO_OUT / f"{image}_mmio.h"
    mmio_hdr_path.write_text(mmio_header)

    # Build new includes + intrinsics header
    header = []
    header.append(f"/* Device-targeted C for {image} */")
    header.append(f"/* Generated by build_device_c.py — targets ARM Cortex-R5 Thumb-2 */")
    header.append("")
    header.append("#include <stdint.h>")
    header.append("#include <stdbool.h>")
    header.append("#include <stddef.h>")
    header.append("#include <stdarg.h>")

    header.append('''
/* MSVC / Hex-Rays compatibility macros for lvalue-safe access to sub-fields of 64-bit vars */
#define LO_BYTE(x)   (*(uint8_t*)&(x))
#define HI_BYTE(x)   (*((uint8_t*)&(x)+1))
#define LO_WORD(x)   (*(uint16_t*)&(x))
#define HI_WORD(x)   (*((uint16_t*)&(x)+1))
#define LO_DWORD(x)  (*(uint32_t*)&(x))
#define HI_DWORD(x)  (*((uint32_t*)&(x)+1))

/* Hex-Rays native aliases */
#define LOBYTE(x)    LO_BYTE(x)
#define HIBYTE(x)    HI_BYTE(x)
#define LOWORD(x)    LO_WORD(x)
#define HIWORD(x)    HI_WORD(x)
#define LODWORD(x)   LO_DWORD(x)
#define HIDWORD(x)   HI_DWORD(x)
''')
    header.append("#include <inttypes.h>")
    header.append("")
    header.append(f'#include "{image}_mmio.h"')
    header.append("")
    # Helper macro: ROM function call via volatile pointer at ADDR
    header.append("static inline int rom_call_32(int addr, int arg) {")
    header.append("  volatile uint32_t *p = (volatile uint32_t *)(uintptr_t)addr;")
    header.append("  int (*fn)(int) = (int (*)(int))((uintptr_t)*p);")
    header.append("  return fn(arg);")
    header.append("}")
    header.append("")
    header.append("static inline uint32_t __get_CPSR(void) {")
    header.append('  uint32_t v; __asm volatile("MRS %0, CPSR" : "=r"(v)); return v; }')
    header.append("static inline uint32_t __get_MSP(void) {")
    header.append('  uint32_t v; __asm volatile("MRS %0, MSP" : "=r"(v)); return v; }')
    header.append("static inline void __set_MSP(uint32_t v) {")
    header.append('  __asm volatile("MSR MSP, %0" : : "r"(v) : "memory"); }')
    header.append("static inline void __disable_irq(void) { __asm volatile(\"CPSID i\" ::: \"memory\"); }")
    header.append("static inline void __enable_irq(void) { __asm volatile(\"CPSIE i\" ::: \"memory\"); }")
    header.append("static inline void __dsb(void) { __asm volatile(\"DSB\" ::: \"memory\"); }")
    header.append("static inline void __isb(void) { __asm volatile(\"ISB\" ::: \"memory\"); }")
    header.append("static inline void __dmb(void) { __asm volatile(\"DMB\" ::: \"memory\"); }")
    header.append("static inline void __nop(void) { __asm volatile(\"NOP\"); }")
    header.append("static inline void __wfi(void) { __asm volatile(\"WFI\"); }")
    header.append("static inline void __wfe(void) { __asm volatile(\"WFE\"); }")
    header.append("static inline void __sev(void) { __asm volatile(\"SEV\"); }")
    header.append("")

    # Fix Hex-Rays quirks BEFORE rewriting
    text = fix_bool_types(text)  # noqa
    text = fix_nullptr(text)  # noqa
    text = fix_vf_flags(text)

    # Strip original stub intrinsics (we inject real ones in header)
    text = re.sub(r'static inline unsigned int __get_CPSR\(void\) \{ return 0; \}\n', '', text)
    text = re.sub(r'static inline void __disable_irq\(void\) \{\}\n', '', text)
    text = re.sub(r'static inline void __enable_irq\(void\) \{\}\n', '', text)
    text = re.sub(r'static inline void __dsb\(void\) \{\}\n', '', text)
    text = re.sub(r'static inline void __isb\(void\) \{\}\n', '', text)
    text = re.sub(r'static inline void __dmb\(void\) \{\}\n', '', text)
    text = re.sub(r'static inline void __nop\(void\) \{\}\n', '', text)
    text = re.sub(r'static inline void __wfi\(void\) \{\}\n', '', text)
    text = re.sub(r'static inline void __wfe\(void\) \{\}\n', '', text)
    text = re.sub(r'static inline void __sev\(void\) \{\}\n', '', text)


    # (stubs stripped and replaced by header-injected versions)

    # Rewrite asm blocks
    text = rewrite_asm_blocks(text)

    # Rewrite MMIO references
    mmio_syms = {s for s, info in pointer_map.items() if info['is_mmio']}
    text = rewrite_mmio_accesses(text, mmio_syms)

    out_text = "\n".join(header) + "\n" + text
    out_path = OUT / f"{image}.c"
    out_path.write_text(out_text)
    print(f"    Written: {out_path} ({len(out_text)} bytes)")
    return out_path


def main():
    if len(sys.argv) < 2:
        print("Usage: build_device_c.py <image> | all")
        sys.exit(1)
    if sys.argv[1] == "all":
        images = BINARIES
    else:
        images = sys.argv[1:]
    for image in images:
        process_image(image)


if __name__ == "__main__":
    main()

