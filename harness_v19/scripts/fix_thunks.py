#!/usr/bin/env python3
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent.parent
DEVICE_C = REPO / "harness_v19/device_c"


def find_matching_paren(s, start):
    """Find matching ) for an open ( at index `start`."""
    depth = 1
    i = start
    while i < len(s) and depth > 0:
        if s[i] == '(':
            depth += 1
        elif s[i] == ')':
            depth -= 1
        i += 1
    return i if depth == 0 else -1


def fix_call_deref_thunks(text):
    """Find `(*((TYPE *)ADDR))()` patterns and convert to function pointer calls."""
    result = []
    i = 0
    while i < len(text):
        # Look for `(*(` pattern (deref + open paren)
        if text[i:i+3] == '(*(':
            # Find the matching `))` at top level after the first `(`
            j = i + 2  # position after `(*`
            # We need to find: `((TYPE *)EXPR))()` — a paren group that ends with `)`
            # then is followed by `()`
            k = find_matching_paren(text, j)
            if k > 0 and k < len(text) - 1 and text[k-1] == ')':
                # We found: `(*( <inner> ))` 
                # Check if followed by `()`
                m = re.match(r'\s*\(\)', text[k:])
                if m:
                    inner = text[j:k-1]  # between `(*` and closing `))`
                    # inner should be: `(TYPE *)ADDR`
                    typem = re.match(r'^\(\s*(.+?)\s*\*\s*\)\s*(.+)$', inner)
                    if typem:
                        typ = typem.group(1).strip().rstrip('*').strip()
                        addr = typem.group(2).strip()
                        if typ in ('uint32_t', 'uint16_t', 'uint8_t', 'int',
                                   'unsigned int', 'volatile uint32_t', 'void'):
                            # Convert: (*((TYPE *)ADDR))() → (int (*)(void))(ADDR)()
                            result.append('(void (*)(void))(})'.split('{}')[0] + addr + ')()')
                            i = k + m.end()
                            continue
        result.append(text[i])
        i += 1
    return ''.join(result)


def process_image(image):
    p = DEVICE_C / f"{image}.c"
    if not p.exists():
        print(f"  SKIP: {p}")
        return
    text = p.read_text()
    new_text = fix_call_deref_thunks(text)
    p.write_text(new_text)
    if new_text != text:
        print(f"  Fixed {image}")
    else:
        print(f"  No changes to {image}")


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
