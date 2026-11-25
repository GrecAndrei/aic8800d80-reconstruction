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
    text = open(path).read()
    total = 0
    for simg, addr, name in SITES:
        if simg != img:
            continue
        # remove the definition block: marker line through the closing brace
        # and following blank lines
        pat = re.compile(
            r"(?m)^// " + re.escape(name) + r" @ " + addr + r"\n"
            r"int " + re.escape(name) + r"\(\) \{.*?\n\}\n\n\n\n",
            re.S)
        m = pat.search(text)
        decl = f"int {name}();\n"
        has_decl = decl in text
        if m:
            total += 1
            if not check:
                text = text[:m.start()] + text[m.end():]
                if has_decl:
                    text = text.replace(decl, "", 1)
    if total and not check:
        open(path, "w").write(text)
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
