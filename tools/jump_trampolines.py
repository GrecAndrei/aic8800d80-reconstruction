"""Repair the tail-jump trampoline forwarding family.

Machine truth (capstone disassembly of the original binaries): each of these
three functions is a single unconditional branch — a transparent tail jump
that forwards every argument register to its target:

  fmacfw_h  0x1211fc: b.w #0x12abc8   -> get_acl_flag
  fmacfw    0x12133c: b.w #0x12ad08   -> ctx_byte_get
  fmacfwbt  0x12159c: b.w #0x12af2c   -> bt_conn_set_bit

The three targets are byte-identical clones of the same logic (ldrb [r0,#0x4c8]
/ cbz / ldrb [r0,#0x6c] / cbz / ldr [r0,#4] / orr #0x40), composed as
`int TARGET(int result)` — they read r0 only, so forwarding a single argument
is behaviorally exact.

Hex-Rays instead decompiled each trampoline as a zero-argument casted call
(`return ((int (*)())TARGET)();`), silently dropping the caller's r0 — the
target then reads uninitialized stack garbage instead of the connection/packet
pointer the original forwards. The repair restores the forwarding tail call.
"""
import re, sys, os

SITES = [
    # (image, tramp marker address, tramp name, target name)
    ("fmacfw_h_u02",   "0x1211fc", "jump_0x12abc8", "get_acl_flag"),
    ("fmacfw_u02",     "0x12133c", "jump_to_12ad08", "ctx_byte_get"),
    ("fmacfwbt_u02",   "0x12159c", "jump_to_12af2c", "bt_conn_set_bit"),
]

def process(path, img, check):
    text = open(path).read()
    total = 0
    for simg, addr, tramp, target in SITES:
        if simg != img:
            continue
        old = f"int {tramp}() {{\n  return ((int (*)()){target})();\n}}"
        new = f"int {tramp}(int a1) {{\n  return {target}(a1);\n}}"
        if old in text:
            total += 1
            if not check:
                text = text.replace(old, new)
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
                print(f"[jump_trampolines] {img}: {n} trampoline(s) {'pending' if check else 'applied/fixed-point'}")
            total += n
    return 1 if check and total else 0

if __name__ == "__main__":
    sys.exit(main())
