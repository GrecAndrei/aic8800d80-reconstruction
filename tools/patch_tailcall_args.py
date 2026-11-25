"""Repair the patch_handle_data tail-call argument extraction.

Machine truth (fmacfw_u02 0x13376c): crypto_mix_round @ 0x1335b0 reads [r0]/[r1],
writes its mix result to memory through r1, and never writes r0 or r1. The first
call's result register assignment (`v4 =`) is a decompiler artifact of a void-in-r0
callee, and the tail call reuses the preserved registers: r0=a1, r1=a1+4, r2=0.
Since r0 is never written by the callee, patch_handle_data returns its input a1.
Hex-Rays instead emits `return crypto_mix_round(v4, v5, 0)` with v5 uninitialized.
"""
import re, sys, os

OLD1 = "  v4 = crypto_mix_round((volatile uint32_t *)a1, (volatile int *)(a1 + 4), (90 << (8 * v2)) | v1);\n  return crypto_mix_round(v4, v5, 0);"
NEW1 = "  crypto_mix_round((volatile uint32_t *)a1, (volatile int *)(a1 + 4), (90 << (8 * v2)) | v1);\n  crypto_mix_round((volatile uint32_t *)a1, (volatile int *)(a1 + 4), 0);\n  return (volatile uint32_t *)a1;"

def process(path, check):
    text = open(path).read()
    m = re.search(r"(?m)^// patch_handle_data @ 0x13376c\n", text)
    if not m:
        return 0
    nxt = re.search(r"(?m)^// \w+ @ 0x", text[m.end():])
    end = m.end() + (nxt.start() if nxt else len(text))
    body = text[m.end():end]
    pending = body.count(OLD1)
    if check or not pending:
        return pending
    body = body.replace(OLD1, NEW1)
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
                print(f"[patch_tailcall_args] {img}: {n} tailcall-arg site(s) {'pending' if check else 'applied/fixed-point'}")
            total += n
    return 1 if check and total else 0

if __name__ == "__main__":
    sys.exit(main())
