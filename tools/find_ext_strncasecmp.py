"""Repair the find_extension inner-loop callee binding.

Machine truth (fmacfwbt 0x12f9a4): the inner-loop call at 0x12f9e0 is
`bl #0x143fdc` = strncasecmp with r0=a1, r1=*v8, r2=v6 — Hex-Rays mis-binds it
as a casted strchr. Control flow is already correct (break when the comparison
returns zero, then verify strlen(entry) == v6).
"""
import re, sys, os

OLD = "if ( !((int (*)())strchr)((void *)(uintptr_t)(a1), *v8, v6) ) break;"
NEW = "if ( !strncasecmp((volatile uint8_t *)(uintptr_t)a1, (volatile uint8_t *)(uintptr_t)*v8, v6) ) break;"

def process(path, check):
    text = open(path).read()
    m = re.search(r"(?m)^// find_extension @ 0x12f9a4\n", text)
    if not m:
        return 0
    nxt = re.search(r"(?m)^// \w+ @ 0x", text[m.end():])
    end = m.end() + (nxt.start() if nxt else len(text))
    body = text[m.end():end]
    pending = body.count(OLD)
    if check or not pending:
        return pending
    body = body.replace(OLD, NEW)
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
                print(f"[find_ext_strncasecmp] {img}: {n} strncasecmp-bind site(s) {'pending' if check else 'applied/fixed-point'}")
            total += n
    return 1 if check and total else 0

if __name__ == "__main__":
    sys.exit(main())
