"""Repair the mix/hash tail-call argument extraction family.

Machine truth (fmacfw_u02 0x13376c, fmacfw_h 0x13362c, fmacfwbt 0x133988):
the mix callees (crypto_mix_round / hash_mix_words) are byte-identical clones
that read [r0]/[r1], write their mix result to memory through r1, and never
write r0 or r1. The first call's result register assignment (`v4 =`) is a
decompiler artifact of a void-in-r0 callee, and the tail call reuses the
preserved registers: r0=a1, r1=a1+4, r2=0. Since r0 is never written by the
callee, the caller returns its input a1. Hex-Rays instead emits
`return <mix>(v4, v5, 0)` with v5 uninitialized.

The defect shape is exactly:

  v4 = <mix>((volatile uint32_t *)a1, (volatile int *)(a1 + 4), (90 << (8 * v2)) | v1);
  return <mix>(v4, v5, 0);

and the rewrite drops the artifact assignment, reuses the preserved argument
registers for the tail call, and returns a1. Restricted to the machine-
verified byte-identical callee family; validated on patch_handle_data in the
v8 corpus measurement (DIFFER->MATCH, 0 regressions).
"""
import re, sys, os

CALLEES = ("crypto_mix_round", "hash_mix_words")

PAT = re.compile(
    r"  v4 = (crypto_mix_round|hash_mix_words)\(\(volatile uint32_t \*\)a1, \(volatile int \*\)\(a1 \+ 4\), \(90 << \(8 \* v2\)\) \| v1\);\n"
    r"  return \1\(v4, v5, 0\);"
)

def repl(m):
    callee = m.group(1)
    return (
        f"  {callee}((volatile uint32_t *)a1, (volatile int *)(a1 + 4), (90 << (8 * v2)) | v1);\n"
        f"  {callee}((volatile uint32_t *)a1, (volatile int *)(a1 + 4), 0);\n"
        "  return (volatile uint32_t *)a1;"
    )

def process(path, check):
    text = open(path).read()
    pending = len(PAT.findall(text))
    if check or not pending:
        return pending
    out = PAT.sub(repl, text)
    open(path, "w").write(out)
    return pending

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
