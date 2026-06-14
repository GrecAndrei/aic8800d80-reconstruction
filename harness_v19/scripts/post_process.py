"""Post-process Hex-Rays decompiled output to make it GCC-compilable."""
import re
import os
import json
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
    text = re.sub(r'\b__cdecl\b', '', text)
    text = re.sub(r'\b__stdcall\b', '', text)
    text = re.sub(r'\b__noreturn\b', '__attribute__((noreturn))', text)
    text = re.sub(r'\bBOOL\b', 'int', text)
    text = re.sub(r'\bTRUE\b', '1', text)
    text = re.sub(r'\bFALSE\b', '0', text)
    return text


def process_pseudo(pseudo, data_decls=None):
    if data_decls is None:
        data_decls = {}
    
    pseudo = process_types(pseudo)
    
    # Remove __asm blocks
    pseudo = re.sub(r'__asm\s*\{[^}]*\}', '(void)0', pseudo, flags=re.S)
    pseudo = re.sub(r'__asm__\s*\([^)]*\)', '(void)0', pseudo, flags=re.S)
    
    # Flags
    pseudo = re.sub(r'\b_CF\b', '0', pseudo)
    pseudo = re.sub(r'\b_ZF\b', '1', pseudo)
    pseudo = re.sub(r'\b_NF\b', '0', pseudo)
    pseudo = re.sub(r'\b_OF\b', '0', pseudo)
    
    # Register assignments
    pseudo = re.sub(r'\b_R\d+\s*=\s*', '', pseudo)
    pseudo = re.sub(r'\b_LR\s*=\s*', '', pseudo)
    pseudo = re.sub(r'\b_SP\s*=\s*', '', pseudo)
    pseudo = re.sub(r'\b_PC\s*=\s*', '', pseudo)
    pseudo = re.sub(r'\b_R\d+\b', '0', pseudo)
    pseudo = re.sub(r'\b_LR\b', '0', pseudo)
    pseudo = re.sub(r'\b_SP\b', '0', pseudo)
    pseudo = re.sub(r'\b_PC\b', '0', pseudo)
    
    # MEMORY[0xNNN]
    def replace_mem(m):
        addr = m.group(1)
        return f'(*((volatile uint32_t *)0x{addr}))'
    pseudo = re.sub(r'MEMORY\[0x([0-9a-fA-F]+)\]', replace_mem, pseudo)
    
    # dword_/off_/unk_/algn_/byte_/word_/qword_ -> data_decls
    def replace_data(m):
        name = m.group(0)
        if name in data_decls:
            return f'({data_decls[name]})'
        return name
    pseudo = re.sub(r'\b(?:dword|off|unk|algn|byte|word|qword)_(?:0x)?[0-9A-Fa-f]+\b', replace_data, pseudo)
    
    # Handle function calls through data: `(*((uint32_t *)0xADDR))()` -> cast to function ptr
    # The replacement above already wraps in parens, so we get `((data_decl))()`
    # data_decl is `*((uint32_t *)0xADDR)`. So we have `((*((uint32_t *)0xADDR)))()`
    # This is calling through volatile pointer. Cast to function pointer.
    def replace_call(m):
        inner = m.group(1)  # The pointer expression
        return f'((uint32_t(*)(void))({inner}))()'
    pseudo = re.sub(r'\(\(\(\(uint32_t\s*\*\)\s*0x[0-9a-fA-F]+\)\)\)\(\)', replace_call, pseudo)
    # Also handle the case from data_decls (which uses *((uint32_t *)0xADDR))
    # Pattern: `((*((uint32_t *)0xADDR)))()` - extra parens
    pseudo = re.sub(r'\(\(\(\*\(\(uint32_t\s*\*\)0x[0-9a-fA-F]+\)\)\)\(\)', lambda m: f'((uint32_t(*)(void))0x{m.group(0).split("0x")[1].split(")")[0]})()', pseudo)
    
    return pseudo


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
            addr = int(addr_hex, 16)
            if name not in refs:
                refs[name] = (kind, addr)
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
        m = re.search(r'^\s*((?:static\s+)?(?:inline\s+)?(?:[\w\s\*]+?))\s+(\w+)\s*\(([^)]*)\)\s*\{', text, re.M)
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


def add_casts(text):
    """Add explicit casts for problematic assignments.
    Pattern: X[N] = pointer_var  ->  X[N] = (uint32_t)(uintptr_t)pointer_var
    Pattern: X = pointer_var  ->  X = (uint32_t)(uintptr_t)pointer_var
    """
    # Detect common pointer->int assignments
    # For now, just wrap any `*X = Y` where Y looks like a pointer (starts with `a`, `v`, `p`)
    # and X is `*X` (deref)
    # This is rough but should catch most
    
    # `X[N] = pointer_var`  (N is index)
    # Look for X[index] = name where name is short (likely pointer)
    text = re.sub(
        r'(\b\w+\[\d+\])\s*=\s*(\b[a-zA-Z_]\w{0,4}\b)(?!\s*[\(\.])',
        lambda m: f'{m.group(1)} = (uint32_t)(uintptr_t){m.group(2)}' if _looks_like_pointer(text, m.group(2)) else m.group(0),
        text
    )
    return text


def _looks_like_pointer(text, name):
    """Heuristic: does this name look like a pointer variable?"""
    # Look for declarations like `TYPE *NAME` in the function
    pat = rf'\b\w+\s*\*\s*{re.escape(name)}\b'
    return bool(re.search(pat, text))


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
            out.write('/* v19 Hex-Rays decompilation - GCC-compatible C */\n')
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
                pseudo = add_casts(pseudo)
                out.write(pseudo)
                out.write('\n')
        
        size = out_path.stat().st_size
        print(f"  {img}: {out_path} ({size//1024} KB)")


if __name__ == '__main__':
    main()
