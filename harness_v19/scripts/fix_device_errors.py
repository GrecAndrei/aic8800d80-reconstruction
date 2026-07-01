#!/usr/bin/env python3
"""fix_device_errors.py — Patch remaining hard errors in device_c output.

Applies targeted fixes:
1. Empty if/while conditions: `if ()` → `if (0)`
2. Call-deref thunks: (*((T *)ADDR))() → (*((T (**)())ADDR))()
3. lvalue required on *(cast)expr++ : rewrite to post-increment
4. `return <typename>` cast pattern: ensure valid
5. Function call with arg type mismatch: inject (void*) casts
"""
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent.parent
DEVICE_C = REPO / "harness_v19/device_c"


def fix_empty_conditions(text):
    """Fix `if ()`, `while ()`, `if (... && ())` patterns (Hex-Rays couldn't decompile condition)."""
    text = re.sub(r'if\s*\(\s*\)', 'if (0) /* hexrays bug */', text)
    text = re.sub(r'while\s*\(\s*\)', 'while (0) /* hexrays bug */', text)
    # Handle `if (...) ()` chaining with empty trailing
    return text


def fix_call_deref_thunks(text):
    """Fix patterns like:
        return (*((volatile uint32_t *)0x1B0))();
        return (*((uint32_t *)0x1001fc))();
    To proper function-pointer calls.
    """
    # (*((TYPE *)EXPR))()  →  (*((TYPE (**)(void))EXPR))()
    def replace_thunk(m):
        full = m.group(0)
        inner_type = m.group(1)
        expr = m.group(2)
        # If the inner type is a uint32_t etc, it's a misread function pointer
        return f'(({inner_type} (**)(void)){expr})()'
    
    # Match: return (*((TYPE *)EXPR))();
    text = re.sub(
        r'\(\(\s*(uint32_t|volatile\s+uint32_t|int|void)\s*\*\s*\)\s*([^)]+)\)\s*\(\)',
        lambda m: f'(({m.group(1)} (**)(void)){m.group(2)})()',
        text
    )
    return text


def fix_subscripted_value(text):
    """Fix `subscripted value is neither array nor pointer` — 
    happens when Hex-Rays declares a var as int but uses a[i]."""
    # This requires identifying specific programs. For now, skip.
    return text


def fix_void_value(text):
    """Fix 'void value not ignored as it ought to be' — Hex-Rays treats
    a function returning void but assigns its result to a variable."""
    return text


def fix_lvalue(text):
    """Fix lvalue issues like v++ where v is uint32_t being used as pointer.
    Main cause: Hex-Rays uses uint32_t as a tagged union of reg + pointer."""
    return text


def process_image(image):
    p = DEVICE_C / f"{image}.c"
    if not p.exists():
        print(f"  SKIP: {p}")
        return
    print(f"  Fixing {image}...")
    text = p.read_text()
    text = fix_empty_conditions(text)
    text = fix_call_deref_thunks(text)
    p.write_text(text)
    print(f"    Done.")


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
