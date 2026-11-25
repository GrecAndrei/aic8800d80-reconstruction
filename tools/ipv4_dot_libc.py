"""Repair the parse_ipv4_dot libc callee bindings.

Machine truth (fmacfw_u02 0x12f788): the function is a byte-similar clone of
find_extension (fmacfwbt 0x12f9a4). The first call target 0x1439b8 is strchr
(206-byte word-scan body, byte-identical across images), the inner-loop
three-argument call target 0x143f1c is strncasecmp (ctype table + 0x20 case
folding, bounded loop), and 0x143e40 is strlen — see tools/libc_names.py for
the machine-verified ownership table.

Hex-Rays binds both calls to memset: the first as a casted two-argument call
(`memset(a1, 46)` where 46 = '.', the dot being scanned for), the second as a
three-argument fill whose middle "byte value" is actually the entry pointer
*v8. memset neither returns a scan pointer nor compares strings, so the
reconstruction diverges: the correct semantics are strchr(a1, '.') for the
prefix scan and strncasecmp(a1, *v8, v6) for the per-entry comparison (break
when the comparison returns zero), exactly as in the repaired find_extension.
"""
import re, sys, os

OLD_STRCHR = "  v5 = ((int (*)())memset)((void *)(uintptr_t)(a1), 46);"
NEW_STRCHR = "  v5 = (int)(uintptr_t)(strchr((void *)(uintptr_t)(a1), 46));"

OLD_CMP = "if ( !memset((void *)(uintptr_t)(a1), *v8, v6) ) break;"
NEW_CMP = "if ( !strncasecmp((volatile uint8_t *)(uintptr_t)a1, (volatile uint8_t *)(uintptr_t)*v8, v6) ) break;"

def process(path, check):
    text = open(path).read()
    m = re.search(r"(?m)^// parse_ipv4_dot @ 0x12f788\n", text)
    if not m:
        return 0
    nxt = re.search(r"(?m)^// \w+ @ 0x", text[m.end():])
    end = m.end() + (nxt.start() if nxt else len(text))
    body = text[m.end():end]
    pending = body.count(OLD_STRCHR) + body.count(OLD_CMP)
    if check or not pending:
        return pending
    body = body.replace(OLD_STRCHR, NEW_STRCHR).replace(OLD_CMP, NEW_CMP)
    open(path, "w").write(text[:m.end()] + body + text[end:])
    return 1

def main():
    check = "--check" in sys.argv
    total = 0
    for img in ("fmacfw_h_u02", "fmacfw_u02", "fmacfwbt_u02", "lmacfw_rf_u02"):
        path = f"src/{img}/main.c"
        if os.path.exists(path):
            n = process(path, check)
            if n:
                print(f"[ipv4_dot_libc] {img}: {n} libc-bind site(s) {'pending' if check else 'applied/fixed-point'}")
            total += n
    return 1 if check and total else 0

if __name__ == "__main__":
    sys.exit(main())
