#!/usr/bin/env python3
import re
import sys
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent.parent
DEVICE_C = REPO / "harness_v19/device_c"


def fix_arg_counts(text):
    """Fix function declarations to match actual call site usage."""
    # 1. Find all call sites
    call_counts = defaultdict(lambda: defaultdict(int))
    
    # Pattern: callee(args);
    pattern = re.compile(r'(sub_\w+|off_\w+)\s*\(([^;]{0,500}?)\)\s*[;]')
    for m in pattern.finditer(text):
        callee = m.group(1)
        args_str = m.group(2).strip()
        if not args_str or args_str == 'void':
            n = 0
        else:
            depth = 0
            n = 1
            for ch in args_str:
                if ch in '([{':
                    depth += 1
                elif ch in ')]}':
                    depth -= 1
                elif ch == ',' and depth == 0:
                    n += 1
        call_counts[callee][n] += 1
    
    # 2. Parse forward declarations
    decl_pattern = re.compile(r'(extern\s+\w+\s+(sub_\w+)\s*\()([^)]*)(\)\s*;)')
    
    def replace_decl(m):
        prefix = m.group(1)
        callee = m.group(2)
        args_str = m.group(3).strip()
        suffix = m.group(4)
        
        if callee not in call_counts:
            return m.group(0)
        
        if not args_str or args_str == 'void':
            decl_n = 0
        else:
            depth = 0
            decl_n = 1
            for ch in args_str:
                if ch in '([{':
                    depth += 1
                elif ch in ')]}':
                    depth -= 1
                elif ch == ',' and depth == 0:
                    decl_n += 1
        
        # Get the most common call count
        counts = call_counts[callee]
        most_common_n = max(counts, key=counts.get)
        
        if most_common_n == decl_n:
            return m.group(0)
        
        # If most_common > decl_n: add extra `int` params
        # If most_common < decl_n: remove trailing params
        if most_common_n > decl_n:
            extras = ', '.join(['int a%d' % (i+1) for i in range(decl_n, most_common_n)])
            if args_str and args_str != 'void':
                new_args = args_str + ', ' + extras
            else:
                new_args = extras
        else:
            # Remove trailing args
            if most_common_n == 0:
                new_args = 'void'
            else:
                depth = 0
                parts = []
                current = ''
                for ch in args_str:
                    if ch in '([{':
                        depth += 1
                    elif ch in ')]}':
                        depth -= 1
                    if ch == ',' and depth == 0:
                        parts.append(current.strip())
                        current = ''
                    else:
                        current += ch
                if current.strip():
                    parts.append(current.strip())
                new_args = ', '.join(parts[:most_common_n])
        
        return prefix + new_args + suffix
    
    return decl_pattern.sub(replace_decl, text)


def process_image(image):
    p = DEVICE_C / f"{image}.c"
    if not p.exists():
        print(f"  SKIP: {p}")
        return
    print(f"  Fixing arg counts in {image}...")
    text = p.read_text()
    before = len(text)
    text = fix_arg_counts(text)
    p.write_text(text)
    print(f"    {before} → {len(text)} bytes")


def main():
    images = sys.argv[1:] if len(sys.argv) > 1 else [
        "fmacfw_8800d80_h_u02_bin",
        "fmacfw_8800d80_u02_bin",
        "fmacfwbt_8800d80_u02_bin",
        "lmacfw_rf_8800d80_u02_bin",
    ]
    for image in images:
        process_image(image)


if __name__ == "__main__":
    main()
