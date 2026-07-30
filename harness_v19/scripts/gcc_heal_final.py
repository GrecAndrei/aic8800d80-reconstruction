#!/usr/bin/env python3
"""gcc_heal_v2.py — Two-round GCC-driven fix, with correct cast direction."""
import re
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent.parent
COMPOSED = REPO / "harness_v19/composed"
HEALED = REPO / "harness_v19/composed_healed_v2"
HEALED.mkdir(parents=True, exist_ok=True)

def compile_and_count(path):
    r = subprocess.run(["gcc","-fsyntax-only","-w",str(path)], capture_output=True, text=True, timeout=60)
    errors = []
    for line in r.stderr.splitlines():
        m = re.match(r'^[^:]+:(\d+):\d+: error: (.+)$', line)
        if m:
            errors.append((int(m.group(1)), m.group(2)))
    return len(errors), errors

def heal(lines, errors, reverse=False):
    """Apply fixes. reverse=False: ptr←int needs (void*)(int)(uintptr_t).
                  reverse=True:  int←ptr needs (int)(uintptr_t)."""
    fixes = 0
    for lineno, msg in errors:
        idx = lineno - 1
        old = lines[idx]
        
        if 'assignment to' in msg and 'pointer from integer' in msg and not reverse:
            m = re.match(r'^(\s*)([\w\.]+(?:\[\d+\])?)(\s*=\s*)(.*);(\s*(?://.*)?)$', old)
            if m:
                indent, lhs, eq, rhs, trail = m.group(1), m.group(2), m.group(3), m.group(4).strip(), m.group(5)
                if rhs and '(void*)' not in rhs[:10] and '(int)(uintptr_t)' not in rhs:
                    lines[idx] = f'{indent}{lhs}{eq}(void*)(int)({rhs});{trail}'
                    fixes += 1
            continue
        
        if 'assignment to' in msg and 'integer from pointer' in msg and reverse:
            m = re.match(r'^(\s*)([\w\.]+(?:\[\d+\])?)(\s*=\s*)(.*);(\s*(?://.*)?)$', old)
            if m:
                indent, lhs, eq, rhs, trail = m.group(1), m.group(2), m.group(3), m.group(4).strip(), m.group(5)
                if rhs and '(int)(uintptr_t)' not in rhs and '*(' not in rhs[:5]:
                    lines[idx] = f'{indent}{lhs}{eq}(int)(uintptr_t)({rhs});{trail}'
                    fixes += 1
            continue
        
        if 'lvalue required' in msg and 'left operand of assignment' in msg:
            for back in range(0, min(5, lineno)):
                l = lines[lineno - 1 - back]
                m = re.match(r'^(\s*)(LOBYTE|HIBYTE|LOWORD|HIWORD|LODWORD|HIDWORD)\s*\(\s*(\w+)\s*\)\s*=\s*(.*?);(\s*(?://.*)?)$', l)
                if m:
                    indent, macro, var, expr, trail = m.group(1), m.group(2), m.group(3), m.group(4).strip(), m.group(5)
                    if not expr: continue
                    sb = {'LOBYTE': 8, 'HIBYTE': 8, 'LOWORD': 16, 'HIWORD': 16, 'LODWORD': 32, 'HIDWORD': 32}[macro]
                    lb = {'LOBYTE': 0, 'HIBYTE': 8, 'LOWORD': 0, 'HIWORD': 16, 'LODWORD': 0, 'HIDWORD': 32}[macro]
                    if var.isdigit() or var == '0':
                        repl = f'(void)({expr})'
                    elif macro in ('HIDWORD', 'LODWORD'):
                        repl = f'{var} = (uint32_t)({expr})'
                    else:
                        hi = lb + sb - 1
                        if hi >= 32: continue
                        ml = (1 << sb) - 1
                        inv = (~(ml << lb)) & 0xFFFFFFFF
                        repl = f'{var} = ((unsigned)({var}) & 0x{inv:08X}U) | (((unsigned)({expr}) & 0x{ml:02X}U) << {lb})'
                    lines[lineno - 1 - back] = f'{indent}{repl};{trail}'
                    fixes += 1
                    break
            if 'lvalue required' in msg:
                # Direct numeric constant on LHS (e.g. 0 = expr;) -> replace with (void)(expr);
                m_num = re.match(r'^(\s*)(\d+|[A-Z0-9_]+)\s*(=|\+=|-=|\*=|\&=|\|=|\^=)\s*(.*?);(\s*(?://.*)?)$', old)
                if m_num and m_num.group(2).isdigit():
                    indent, num, op, expr, trail = m_num.group(1), m_num.group(2), m_num.group(3), m_num.group(4).strip(), m_num.group(5)
                    lines[idx] = f'{indent}(void)({expr});{trail}'
                    fixes += 1
            continue
    return fixes

def main():
    for img_file in sorted(COMPOSED.glob("*.c")):
        out_path = HEALED / img_file.name
        lines = img_file.read_text().split('\n')
        n_init = compile_and_count(out_path)[0] if out_path.exists() else compile_and_count(img_file)[0]
        
        # Round 1: pointer-from-integer
        for _ in range(5):
            out_path.write_text('\n'.join(lines))
            n, errors = compile_and_count(out_path)
            fixes = heal(lines, errors, reverse=False)
            if fixes == 0: break
        
        # Round 2: integer-from-pointer
        for _ in range(5):
            out_path.write_text('\n'.join(lines))
            n, errors = compile_and_count(out_path)
            fixes = heal(lines, errors, reverse=True)
            if fixes == 0: break
        
        # Round 3: any remaining lvalue errors
        for _ in range(3):
            out_path.write_text('\n'.join(lines))
            n, errors = compile_and_count(out_path)
            fixes = heal(lines, errors, reverse=False)
            if fixes == 0: break
        
        out_path.write_text('\n'.join(lines))
        n_final = compile_and_count(out_path)[0]
        print(f"{img_file.name}: {n_init} -> {n_final} (-{n_init-n_final})", file=sys.stderr)

if __name__ == '__main__':
    main()
