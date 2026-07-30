#!/usr/bin/env python3
"""post_process.py — Hex-Rays decompilation cleanup for GCC.

Pipeline:
  - process_types: MSVC → C99 type rewrite
  - strip_asm: remove __asm blocks (brace-aware for nested braces)
  - collect_data_refs / build_data_decls: replace off_/dword_/etc symbols
  - fix_lvalue_macros: LOBYTE(var) = expr → bitfield masking
  - compose per-function → one .c per binary
"""
import re
import os
import json
import subprocess
from pathlib import Path


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
    re.sub(r'\b__cdecl\b', '', text)
    text = re.sub(r'\b__stdcall\b', '', text)
    text = re.sub(r'\b__noreturn\b', '__attribute__((noreturn))', text)
    text = re.sub(r'\bBOOL\b', 'int', text)
    text = re.sub(r'\bTRUE\b', '1', text)
    text = re.sub(r'\bFALSE\b', '0', text)
    return text


def strip_asm(text):
    """Strip __asm blocks with proper nested-brace handling."""
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
        result.append('(void)0;')
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


def collect_data_refs(img_dir):
    refs = {}
    for c_file in img_dir.glob('*.c'):
        if c_file.name.startswith('_'):
            continue
        text = c_file.read_text()
        for m in re.finditer(r'\b(dword|off|unk|algn|byte|word|qword)_([0-9A-Fa-f]+)\b', text):
            kind = m.group(1)
            addr_hex = m.group(2)
            name = f'{kind}_{addr_hex}'
            if name not in refs:
                refs[name] = (kind, int(addr_hex, 16))
    return refs


def build_data_decls(refs):
    decls = {}
    for name, (kind, addr) in refs.items():
        if kind == 'dword':
            decls[name] = f'*((uint32_t *)0x{addr:x})'
        elif kind == 'word':
            decls[name] = f'*((uint16_t *)0x{addr:x})'
        elif kind == 'byte':
            decls[name] = f'*((uint8_t *)0x{addr:x})'
        elif kind == 'qword':
            decls[name] = f'*((uint64_t *)0x{addr:x})'
        elif kind in ('off', 'unk', 'algn'):
            decls[name] = f'*((uint32_t *)0x{addr:x})'
    return decls


def collect_func_signatures(img_dir):
    sigs = {}
    for c_file in img_dir.glob('*.c'):
        if c_file.name.startswith('_'):
            continue
        text = c_file.read_text()
        m = re.search(
            r'^\s*((?:static\s+)?(?:inline\s+)?(?:[\w\s\*]+?))\s+(\w+)\s*\(([^)]*)\)\s*\{',
            text, re.M
        )
        if m:
            ret_type = m.group(1).strip()
            name = m.group(2)
            params = m.group(3).strip()
            if name in ('if', 'for', 'while', 'switch', 'do', 'return'):
                continue
            ret_type = process_types(ret_type)
            params = process_types(params) if params else 'void'
            sigs[name] = f'{ret_type} {name}({params})'
    return sigs


def fix_lvalue_macros(text):
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
        if not expr or expr.startswith('(('):
            result.append(s[i:j]); i = j; continue
        window = s[max(0, i - 2000):m.start()]
        is_64bit = bool(re.search(
            r'\b(?:long\s+long|uint64_t|unsigned\s+long\s+long|__int64)\b\s+\**\s*'
            + re.escape(var) + r'\b', window
        )) or bool(var.startswith('kr') and '_' in var)
        size_map = {'LOBYTE': (8,0), 'HIBYTE': (8,8), 'LOWORD': (16,0), 'HIWORD': (16,16),
                     'LODWORD': (32,0), 'HIDWORD': (32,32)}
        size_bits, lo_bit = size_map[macro]
        if macro in ('HIDWORD', 'LODWORD') and not is_64bit:
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


def add_casts(text):
    """Add explicit casts for pointer/integer mismatches."""
    def _looks_like_pointer(t, name):
        pat = rf'\b\w+\s*\*\s*{re.escape(name)}\b'
        return bool(re.search(pat, t))

    text = re.sub(
        r'(\b\w+\[\d+\])\s*=\s*(\b[a-zA-Z_]\w{0,4}\b)(?!\s*[\(\.])',
        lambda m: (f'{m.group(1)} = (uint32_t)(uintptr_t){m.group(2)}'
                   if _looks_like_pointer(text, m.group(2)) else m.group(0)),
        text
    )
    return text


def process_pseudo(pseudo, data_decls=None):
    if data_decls is None:
        data_decls = {}
    pseudo = process_types(pseudo)
    pseudo = strip_asm(pseudo)

    def replace_data(m):
        name = m.group(0)
        if name in data_decls:
            return f'({data_decls[name]})'
        return name
    pseudo = re.sub(r'\b(?:dword|off|unk|algn|byte|word|qword)_(?:0x)?[0-9A-Fa-f]+\b',
                    replace_data, pseudo)

    pseudo = fix_lvalue_macros(pseudo)
    pseudo = add_casts(pseudo)
    return pseudo


def main():
    base = Path('harness_v19/decompiled')
    out_base = Path('harness_v19/composed')
    out_base.mkdir(exist_ok=True, parents=True)

    for img_dir in sorted(base.iterdir()):
        img = img_dir.name
        out_path = out_base / f'{img}.c'

        data_refs = collect_data_refs(img_dir)
        data_decls = build_data_decls(data_refs)
        sigs = collect_func_signatures(img_dir)

        with open(out_path, 'w') as out:
            out.write('/* v19 Hex-Rays decompilation - GCC-compatible C (with lvalue-macro fix) */\n')
            out.write(f'/* Image: {img} */\n')
            out.write(f'/* Functions: {len(sigs)} */\n')
            out.write(f'/* Data refs: {len(data_refs)} */\n')
            out.write('#include <stdint.h>\n')
            out.write('#include <stddef.h>\n')
            out.write('#include <stdarg.h>\n')
            out.write('#include <inttypes.h>\n')
            out.write('\n')
            out.write('/* ARM intrinsics stubs */\n')
            out.write('static inline unsigned int __get_CPSR(void) { return 0; }\n')
            out.write('static inline void __disable_irq(void) {}\n')
            out.write('static inline void __enable_irq(void) {}\n')
            out.write('static inline void __dsb(void) {}\n')
            out.write('static inline void __isb(void) {}\n')
            out.write('static inline void __dmb(void) {}\n')
            out.write('static inline void __nop(void) {}\n')
            out.write('static inline void __wfi(void) {}\n')
            out.write('static inline void __wfe(void) {}\n')
            out.write('static inline void __sev(void) {}\n')
            out.write('\n')
            out.write('/* Forward declarations */\n')
            for sig in sorted(set(sigs.values())):
                out.write(f'extern {sig};\n')
            out.write('\n')

            for c_file in sorted(img_dir.glob('*.c')):
                if c_file.name.startswith('_'):
                    continue
                text = c_file.read_text()
                lines = [l for l in text.split('\n') if not l.startswith('// Doc:')]
                pseudo = '\n'.join(lines)
                pseudo = process_pseudo(pseudo, data_decls=data_decls)
                out.write(pseudo)
                out.write('\n')

        # Verify
        res = subprocess.run(['gcc', '-fsyntax-only', '-w', str(out_path)],
                              capture_output=True, text=True, timeout=60)
        size = out_path.stat().st_size
        nerr = res.stderr.count('error:')
        bal = out_path.read_text().count('{') - out_path.read_text().count('}')
        print(f"  {img}: {out_path} ({size//1024} KB), {nerr} errors, brace_balance={bal}")


if __name__ == '__main__':
    main()
