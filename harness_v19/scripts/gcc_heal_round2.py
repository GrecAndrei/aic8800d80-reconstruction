#!/usr/bin/env python3
"""gcc_heal.py — Single-pass GCC-error-driven fixup.

Applies one round of mechanical fixes based on GCC error messages.
Designed to be idempotent: safe to re-run.
"""
import re
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent.parent
COMPOSED = REPO / "harness_v19/composed"
HEALED_DIR = REPO / "harness_v19/composed_healed"
HEALED_DIR.mkdir(parents=True, exist_ok=True)


def compile_and_count(path):
    r = subprocess.run(["gcc", "-fsyntax-only", "-w", str(path)],
                       capture_output=True, text=True, timeout=60)
    errors = []
    for line in r.stderr.splitlines():
        m = re.match(r'^[^:]+:(\d+):\d+: error: (.+)$', line)
        if m:
            errors.append((int(m.group(1)), m.group(2)))
    return len(errors), errors


def fix_all(lines, errors):
    """Apply fixes. Returns fix count."""
    fixes = 0
    fixed_lines = set()
    
    for lineno, msg in errors:
        if lineno in fixed_lines:
            continue
        idx = lineno - 1
        old = lines[idx]
        new = old
        
        if 'lvalue required' in msg and 'left operand of assignment' in msg:
            # Look at this line or up to 2 lines before
            for back in range(0, min(3, lineno)):
                l = lines[lineno - 1 - back]
                m = re.match(r'^(\s*)(LOBYTE|HIBYTE|LOWORD|HIWORD|LODWORD|HIDWORD)\s*\(\s*(\w+)\s*\)\s*=\s*(.*?);(\s*(?://.*)?)$', l)
                if m:
                    indent, macro, var, expr, trail = m.group(1), m.group(2), m.group(3), m.group(4).strip(), m.group(5)
                    if not expr:
                        continue
                    size_bits = {'LOBYTE': 8, 'HIBYTE': 8, 'LOWORD': 16, 'HIWORD': 16,
                                 'LODWORD': 32, 'HIDWORD': 32}[macro]
                    lo_bit = {'LOBYTE': 0, 'HIBYTE': 8, 'LOWORD': 0, 'HIWORD': 16,
                              'LODWORD': 0, 'HIDWORD': 32}[macro]
                    if macro in ('HIDWORD', 'LODWORD'):
                        repl = f'{var} = (uint32_t)({expr})'
                    else:
                        hi_bit = lo_bit + size_bits - 1
                        if hi_bit >= 32:
                            continue
                        mask_lo = (1 << size_bits) - 1
                        mask = mask_lo << lo_bit
                        invmask = (~mask) & 0xFFFFFFFF
                        repl = (f'{var} = ((unsigned)({var}) & 0x{invmask:08X}U) '
                                f'| (((unsigned)({expr}) & 0x{mask_lo:02X}U) << {lo_bit})')
                    lines[lineno - 1 - back] = f'{indent}{repl};{trail}'
                    fixed_lines.add(lineno - back)
                    fixes += 1
                    break
            continue
        
        if 'assignment to' in msg and 'pointer from integer' in msg:
            m = re.match(r'^(\s*)([\w\.]+(?:\[\d+\])?)(\s*=\s*)(.*);(\s*(?://.*)?)$', old)
            if m:
                indent, lhs, eq, rhs, trail = m.group(1), m.group(2), m.group(3), m.group(4).strip(), m.group(5)
                if rhs and rhs != '(void)0' and '(int)(uintptr_t)' not in rhs and '(void*)' not in rhs[:10]:
                    new = f'{indent}{lhs}{eq}(int)(uintptr_t)({rhs});{trail}'
                    lines[idx] = new
                    fixed_lines.add(lineno)
                    fixes += 1
            continue
        
        if 'too few arguments' in msg:
            m_arg = re.match(r'.*expected (\d+), have (\d+)', msg)
            if m_arg:
                exp, act = int(m_arg.group(1)), int(m_arg.group(2))
                paren_pos = old.index('(')
                depth = 0
                close_pos = None
                for i in range(paren_pos, len(old)):
                    if old[i] == '(': depth += 1
                    elif old[i] == ')':
                        depth -= 1
                        if depth == 0: close_pos = i; break
                if close_pos:
                    inner = old[paren_pos+1:close_pos]
                    missing = exp - act
                    if missing > 0:
                        addition = ', '.join(['0'] * missing)
                        new_inner = (inner + ', ' + addition) if inner.strip() else addition
                        new = old[:paren_pos+1] + new_inner + old[close_pos:]
                        lines[idx] = new
                        fixed_lines.add(lineno)
                        fixes += 1
            continue
        
        if 'too many arguments' in msg:
            m_arg = re.match(r'.*expected (\d+), have (\d+)', msg)
            if m_arg:
                exp, act = int(m_arg.group(1)), int(m_arg.group(2))
                paren_pos = old.index('(')
                depth = 0
                close_pos = None
                for i in range(paren_pos, len(old)):
                    if old[i] == '(': depth += 1
                    elif old[i] == ')':
                        depth -= 1
                        if depth == 0: close_pos = i; break
                if close_pos:
                    inner = old[paren_pos+1:close_pos]
                    args = []
                    cur_start = 0
                    d = 0
                    for i, c in enumerate(inner):
                        if c in '([{': d += 1
                        elif c in ')]}': d -= 1
                        elif c == ',' and d == 0:
                            args.append(inner[cur_start:i])
                            cur_start = i + 1
                    args.append(inner[cur_start:])
                    if len(args) == exp + (act - exp):
                        args = args[:exp]
                    new_inner = ', '.join(a.strip() for a in args)
                    new = old[:paren_pos+1] + new_inner + old[close_pos:]
                    lines[idx] = new
                    fixed_lines.add(lineno)
                    fixes += 1
            continue
        
        if 'called object is not a function' in msg:
            paren_pos = old.index('(')
            callee = old[:paren_pos].rstrip()
            rest = old[paren_pos:]
            if '(void(*)(' not in callee:
                new = f'((void(*)(void))({callee})){rest}'
                lines[idx] = new
                fixed_lines.add(lineno)
                fixes += 1
            continue
        
        if 'subscripted value is neither array nor pointer' in msg and 'subscripted value is neither array nor vector' not in msg:
            m = re.search(r'(\w+)(\s*\[)', old)
            if m and f'((void*)({m.group(1)}))' not in old:
                new = old[:m.start()] + f'((void*)({m.group(1)}))' + old[m.end()-len(m.group(2)):]
                lines[idx] = new
                fixed_lines.add(lineno)
                fixes += 1
            continue
    
    return fixes


def main():
    print("gcc_heal.py — single-pass GCC-driven fixup", file=sys.stderr)
    for img_file in sorted(COMPOSED.glob("*.c")):
        out_path = HEALED_DIR / img_file.name
        lines = img_file.read_text().split('\n')
        
        nerr_initial, errors = compile_and_count(img_file)
        fixes = fix_all(lines, errors)
        out_path.write_text('\n'.join(lines))
        nerr_final, _ = compile_and_count(out_path)
        
        # Second pass
        lines2 = out_path.read_text().split('\n')
        _, errors2 = compile_and_count(out_path)
        fixes2 = fix_all(lines2, errors2)
        out_path.write_text('\n'.join(lines2))
        nerr_final2, _ = compile_and_count(out_path)
        
        print(f"{img_file.name}: {nerr_initial} → {nerr_final} → {nerr_final2} "
              f"(fixes: {fixes}+{fixes2})", file=sys.stderr)



if __name__ == '__main__':
    print("gcc_heal round2", file=sys.stderr)
    for img_file in sorted(COMPOSED.glob("*.c")):
        healed_f = HEALED_DIR / img_file.name
        if not healed_f.exists():
            continue
        lines = healed_f.read_text().split(chr(10))
        nerr, errors = compile_and_count(healed_f)
        fixes = heal_round2(lines, errors)
        healed_f.write_text(chr(10).join(lines))
        nerr2, _ = compile_and_count(healed_f)
        lines2 = healed_f.read_text().split(chr(10))
        _, errors2 = compile_and_count(healed_f)
        fixes2 = heal_round2(lines2, errors2)
        healed_f.write_text(chr(10).join(lines2))
        nerr3, _ = compile_and_count(healed_f)
        print(f"{img_file.name}: {nerr} -> {nerr2} -> {nerr3} (fixes: {fixes}+{fixes2})", file=sys.stderr)
