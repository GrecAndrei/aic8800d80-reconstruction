"""Drop the spurious duplicate fragment units.

Machine truth (docs/BOOT_DIVERGENCE_ANALYSIS.md, fragment-family section):
tx_complete_check @ 0x135250 (fmacfw_h) and bt_is_conn_flag_set @ 0x135390
(fmacfw_u02) are not function entries. They have zero inbound call edges,
zero jump-table references in either address base, and entry only by
fall-through from the preceding composed unit (mac_dma_setup / its clone),
whose decompile already covers the fragment instruction span completely —
the raw unit files are statement-for-statement identical. The only correct
representation of that code is the enclosing function; the duplicate unit
misrepresents an interior continuation as a callable zero-argument function
and can never match the original when invoked standalone.

Both units are textually unreferenced beyond their forward declaration and
definition, so removal is link-safe. The fragment addresses stay covered:
the enclosing unit's body carries the real logic.
"""
import re, sys, os

SITES = [
    ("fmacfw_h_u02", "0x135250", "tx_complete_check"),
    ("fmacfw_u02", "0x135390", "bt_is_conn_flag_set"),
]

def process(path, img, check):
    lines = open(path).read().splitlines(keepends=True)
    total = 0
    for simg, addr, name in SITES:
        if simg != img:
            continue
        marker = f"// {name} @ {addr}\n"
        # locate the definition: marker line, then lines to the first
        # column-0 closing brace, then the trailing blank lines that precede
        # the next unit marker.
        try:
            mi = lines.index(marker)
        except ValueError:
            continue
        sig = f"int {name}() {{\n"
        if mi + 1 >= len(lines) or lines[mi + 1] != sig:
            continue
        j = mi + 2
        end = None
        while j < len(lines):
            if lines[j] == "}\n":
                end = j
                break
            j += 1
        if end is None:
            continue
        # trailing blank lines after the closing brace
        k = end + 1
        while k < len(lines) and lines[k].strip() == "":
            k += 1
        total += 1
        if not check:
            del lines[mi:k]
            decl = f"int {name}();\n"
            if decl in lines:
                lines.remove(decl)
    if total and not check:
        open(path, "w").write("".join(lines))
    return total

def main():
    check = "--check" in sys.argv
    total = 0
    for img in ("fmacfw_h_u02", "fmacfw_u02", "fmacfwbt_u02", "lmacfw_rf_u02"):
        path = f"src/{img}/main.c"
        if os.path.exists(path):
            n = process(path, img, check)
            if n:
                print(f"[drop_spurious_fragments] {img}: {n} fragment unit(s) {'pending' if check else 'dropped'}")
            total += n
    return 1 if check and total else 0

if __name__ == "__main__":
    sys.exit(main())
