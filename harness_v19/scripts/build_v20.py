#!/usr/bin/env python3
"""build_v20.py — Construct v20 composed files from per-function Hex-Rays output.

Pipeline: decompiled/<img>/*.c → process_types + strip_asm + data_decls + fix_lvalue_macros → composed_v20/<img>.c
"""
import re
import subprocess
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent.parent
DECOMPILED = REPO / "harness_v19/decompiled"
OUT = REPO / "harness_v19/composed_v20"
OUT.mkdir(parents=True, exist_ok=True)

BINARIES = [
    "fmacfw_8800d80_h_u02_bin",
    "fmacfw_8800d80_u02_bin",
    "fmacfwbt_8800d80_u02_bin",
    "lmacfw_rf_8800d80_u02_bin",
]


def process_types(text):
    text = re.sub(r'\bunsigned\s+__int64\b', 'unsigned long long', text)
    text = re.sub(r'\bunsigned\s+__int32\b', 'unsigned int', text)
    text = re.sub(r'\bunsigned\s+__int16\b', 'unsigned short', text)
    text = re.sub(r'\bunsigned\s+__int8\b', 'unsigned char', text)
    text = re.sub(r'\b__int64\b', 'long long', text)
    text = re.sub(r'\b__int32\b', 'int', text)
    text = re.sub(r'\b__int16\b', 'short', text)
    text = re.sub(r'\b__int8\b', 'signed char', text)
    text = re.sub(r'\b_DWORD\b', 'uint32_t', text)
    text = re.sub(r'\b_BYTE\b', 'uint8_t', text)
    text = re.sub(r'\b_WORD\b', 'uint16_t', text)
    text = re.sub(r'\b_QWORD\b', 'uint64_t', text)
    text = re.sub(r'\b__fastcall\b', '', text)
    text = re.sub(r'\b__cdecl\b', '', text)
    text = re.sub(r'\b__stdcall\b', '', text)
    text = re.sub(r'\bBOOL\b', 'int', text)
    text = re.sub(r'\bTRUE\b', '1', text)
    text = re.sub(r'\bFALSE\b', '0', text)
    return text


def strip_asm(text):
    """Strip __asm blocks with brace-aware matching."""
    result = []
    s = text
    pat = re.compile(r'__asm\s*\{')
    i = 0
    while i < len(s):
        m = pat.search(s, i)
        if m is None:
            result.append(s[i:])
            break
        j = m.end()
        depth = 1
        while j < len(s) and depth > 0:
            if s[j] == '{': depth += 1
            elif s[j] == '}': depth -= 1
            j += 1
        result.append(s[i:m.start()])
        result.append('(void)0')
        i = j
    text = ''.join(result)
    text = re.sub(r'__asm\s+volatile\s*\([^)]*\)', '(void)0', text, flags=re.S)
    text = re.sub(r'__asm__\s*\([^)]*\)', '(void)0', text, flags=re.S)
    text = re.sub(r'\b_CF\b', '0', text)
    text = re.sub(r'\b_ZF\b', '1', text)
    text = re.sub(r'\b_NF\b', '0', text)
    text = re.sub(r'\b_OF\b', '0', text)
    text = re.sub(r'\b_R\d+\s*=\s*', '', text)
    text = re.sub(r'\b_LR\s*=\s*', '', text)
    text = re.sub(r'\b_SP\s*=\s*', '', text)
    text = re.sub(r'\b_PC\s*=\s*', '', text)
    text = re.sub(r'\b_R\d+\b', '0', text)
    text = re.sub(r'\b_LR\b', '0', text)
    text = re.sub(r'\b_SP\b', '0', text)
    text = re.sub(r'\b_PC\b', '0', text)
    text = re.sub(r'MEMORY\[0x([0-9a-fA-F]+)\]', r'(*((volatile uint32_t *)0x\1))', text)
    return text


def fix_lvalue_macros(text, _dbg=False):
    """Rewrite LOBYTE/HIBYTE/LOWORD/HIDWORD/LODWORD/HIDWORD(var) = expr assignments."""
    result = []
    s = text
    pat = re.compile(r'\b(LOBYTE|HIBYTE|LOWORD|HIWORD|LODWORD|HIDWORD)\(')
    i = 0
    while i < len(s):
        m = pat.search(s, i)
        if m is None:
            result.append(s[i:])
            break
        macro = m.group(1)
        j = m.end()
        depth = 1
        while j < len(s) and depth > 0:
            if s[j] == '(': depth += 1
            elif s[j] == ')': depth -= 1
            j += 1
        if depth != 0:
            result.append(s[i:j]); i = j; continue
        var = s[m.end():j - 1].strip()
        if not re.match(r'^[a-zA-Z_]\w*$', var):
            result.append(s[i:j]); i = j; continue
        k = j
        while k < len(s) and s[k] in ' \t': k += 1
        if k >= len(s) or s[k] != '=':
            result.append(s[i:j]); i = j; continue
        k += 1
        while k < len(s) and s[k] in ' \t': k += 1
        expr_start = k
        d = 0
        while k < len(s):
            if s[k] in '(': d += 1
            elif s[k] in ')': d -= 1
            elif s[k] == ';' and d == 0: break
            elif s[k] in ',\n' and d == 0: break
            k += 1
        expr = s[expr_start:k].strip()
        if not expr:
            result.append(s[i:j]); i = j; continue
        window = s[max(0, i - 2000):m.start()]
        is_64bit = bool(re.search(
            r'\b(?:long\s+long|uint64_t|unsigned\s+long\s+long|__int64)\b\s+\**\s*' + re.escape(var) + r'\b',
            window
        )) or bool(var.startswith('kr') and '_' in var)
        size_map = {'LOBYTE': (8,0), 'HIBYTE': (8,8), 'LOWORD': (16,0), 'HIWORD': (16,16),
                     'LODWORD': (32,0), 'HIDWORD': (32,32)}
        size_bits, lo_bit = size_map[macro]
        if macro in ('HIDWORD', 'LODWORD') and not is_64bit:
            # Non-64-bit HIDWORD/LODWORD: just assign (uint32 cast)
            repl = f'{var} = (uint32_t)({expr})'
        elif is_64bit:
            mask_lo = (1 << size_bits) - 1
            mask = mask_lo << lo_bit
            invmask = (~mask) & ((1 << 64) - 1)
            repl = (f'{var} = ({var} & 0x{invmask:016X}ULL) '
                    f'| (((unsigned long long)({expr}) & 0x{mask_lo:03X}ULL) << {lo_bit})')
        else:
            hi_bit = lo_bit + size_bits - 1
            if hi_bit >= 32:
                result.append(s[i:j]); i = j; continue
            mask_lo = (1 << size_bits) - 1
            mask = mask_lo << lo_bit
            invmask = (~mask) & 0xFFFFFFFF
            repl = (f'{var} = ((unsigned)({var}) & 0x{invmask:08X}U) '
                    f'| (((unsigned)({expr}) & 0x{mask_lo:02X}U) << {lo_bit})')
        result.append(s[i:m.start()])
        result.append(repl)
        i = k
    return ''.join(result)


def process_file(repl_map, cfile):
    text = cfile.read_text()
    text = process_types(text)
    text = strip_asm(text)
    text = re.sub(r'\b(?:dword|off|unk|algn|byte|word|qword)_(?:0x)?[0-9A-Fa-f]+\b',
                  lambda m: repl_map.get(m.group(0), m.group(0)), text)
    text = fix_lvalue_macros(text)
    return text


def extract_sig(text):
    """Return (ret, name, params_str) from cleaned function text."""
    sm = re.search(
        r'^\s*(?:unsigned\s+|signed\s+|short\s+|long\s+)*'
        r'(?:int|void|char|__int\w*|uint8_t|uint16_t|uint32_t|uint64_t|'
        r'_DWORD|_QWORD|_WORD|_BYTE|\*|bool)'
        r'\s*\*?\s+(\w+)\s*\(([^)]*)\)\s*\{',
        text, re.M
    )
    if not sm:
        return None
    name = sm.group(1)
    params = sm.group(2).strip()
    end_idx = sm.group(0).index(name)
    pre = text[sm.start():sm.start() + end_idx].strip()
    pre = re.sub(r'\b__fastcall\b|\b__cdecl\b|\b__stdcall\b', '', pre).strip()
    return (pre, name, params if params else 'void')


def main():
    for img in BINARIES:
        # Build data refs map
        refs = {}
        for cfile in sorted((DECOMPILED / img).glob('*.c')):
            for m in re.finditer(r'\b(dword|off|unk|algn|byte|word|qword)_([0-9A-Fa-f]+)\b',
                                ' ' + cfile.read_text()):
                name = f'{m.group(1)}_{m.group(2)}'
                if name not in refs:
                    try:
                        addr = int(m.group(2), 16)
                    except ValueError:
                        continue
                    refs[name] = (m.group(1), addr)
        repl_map = {}
        for name, (kind, addr) in refs.items():
            if kind == 'dword':
                repl_map[name] = f'(*((uint32_t *)0x{addr:x}))'
            elif kind == 'word':
                repl_map[name] = f'(*((uint16_t *)0x{addr:x}))'
            elif kind == 'byte':
                repl_map[name] = f'(*((uint8_t *)0x{addr:x}))'
            elif kind == 'qword':
                repl_map[name] = f'(*((uint64_t *)0x{addr:x}))'
            else:
                repl_map[name] = f'(*((uint32_t *)0x{addr:x}))'

        files = sorted((DECOMPILED / img).glob('*.c'))
        fixed = {}
        sigs = {}
        defined = set()
        called = set()
        for cfile in files:
            text = process_file(repl_map, cfile)
            fixed[cfile.name] = text
            sig = extract_sig(text)
            if sig:
                ret, name, params = sig
                sigs[name] = f'{ret} {name}({params})'
                defined.add(name)
            for cm in re.finditer(r'\b([a-zA-Z_]\w{4,})\s*\(', text):
                cn = cm.group(1)
                if cn in ('if','for','while','switch','return','sizeof',
                          '__get_CPSR','__disable_irq','LOBYTE','HIBYTE',
                          'LOWORD','HIWORD','LODWORD','HIDWORD'):
                    continue
                called.add(cn)
        out_path = OUT / f'{img}.c'
        with open(out_path, 'w') as out:
            out.write('/* v20: Hex-Rays decompilation + type fixes (lvalue-macro) */\n')
            out.write(f'/* Image: {img} */\n')
            out.write('#include <stdint.h>\n#include <stddef.h>\n#include <inttypes.h>\n')
            out.write('#define LOBYTE(x) ((uint8_t)(x))\n')
            out.write('#define HIBYTE(x) ((uint8_t)((uint16_t)(x) >> 8))\n')
            out.write('#define LOWORD(x) ((uint16_t)(x))\n')
            out.write('#define HIWORD(x) ((uint16_t)((uint32_t)(x) >> 16))\n')
            out.write('#define LODWORD(x) ((uint32_t)(x))\n')
            out.write('#define HIDWORD(x) ((uint32_t)((uint64_t)(x) >> 32))\n\n')
            out.write('static inline unsigned __get_CPSR(void) { return 0; }\n')
            out.write('static inline void __disable_irq(void) {}\n\n')
            externs = called - defined
            for name in sorted(externs):
                sig = sigs.get(name)
                if sig:
                    out.write(f'extern {sig};\n')
                else:
                    out.write(f'extern int {name}(...);\n')
            out.write('\n')
            for cfile in files:
                out.write(fixed[cfile.name])
                out.write('\n')
        nerr = subprocess.run(['gcc', '-fsyntax-only', '-w', str(out_path)],
                              capture_output=True, text=True, timeout=60).stderr.count('error:')
        print(f"[v20] {img}: {out_path.stat().st_size//1024} KB, {nerr} errors")


if __name__ == '__main__':
    main()
