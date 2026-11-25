"""Repair the discarded-validate-result forwarding family.

Machine truth (capstone disassembly of the original binaries): in both
byte-cloned phy-status functions the scan loop accumulates the maximum
stripped byte in r0, and that value is passed straight into the validate
helper, whose result is forwarded as the second argument of the mode call:

  fmacfw_h  get_phy_status_byte @ 0x13275c:
    0x13278e bl #0x1325b4 (cmd_char_validate — reads r0: `and r3,r0,#0x7f`)
    0x132792 mov r1, r0 / mov r0, r5 / 0x132796 bl #0x13f278 (rf_set_mode)
  fmacfw_u02 patch_check_version @ 0x13289c (byte-identical structure):
    0x1328ce bl #0x1326f4 (is_valid_rate_code)
    0x1328d2 mov r1, r0 / mov r0, r5 / 0x1328d6 bl #0x13f3b8 (ble_ll_conn_set_phy)

When the byte count at [a1+0xc0] is zero the scan loop is skipped and r0 is
still zero — the accumulator's initial value — so v5 must be zero-initialized
for the skip path to be exact.

Hex-Rays dropped both data flows: the validate call is emitted with no
argument and its result discarded, and the mode call receives v8 — a variable
never written anywhere in the body. Both functions fail every comparable
vector in the corpus. The repair restores the forwarding chain.
"""
import re, sys, os

SITES = [
    # (image, function, validate call old text, validate name, mode call name)
    ("fmacfw_h_u02", "get_phy_status_byte",
     "((int (*)())cmd_char_validate)();", "cmd_char_validate", "rf_set_mode"),
    ("fmacfw_u02", "patch_check_version",
     "((int (*)())is_valid_rate_code)();", "is_valid_rate_code", "ble_ll_conn_set_phy"),
]

def process(path, img, check):
    text = open(path).read()
    total = 0
    for simg, func, oldcall, vname, mname in SITES:
        if simg != img:
            continue
        m = re.search(r"(?m)^// " + func + r" @ 0x[0-9a-f]+\n", text)
        if not m:
            continue
        end = text.find("\n// ", m.end())
        body = text[m.start():end if end > 0 else len(text)]
        if oldcall not in body:
            continue
        total += 1
        if check:
            continue
        newbody = body.replace(
            oldcall + "\n  result = " + mname + "(a1, v8);",
            "v8 = " + vname + "(v5);\n  result = " + mname + "(a1, v8);")
        newbody = newbody.replace("int v5; // r0", "int v5 = 0; // r0", 1)
        text = text[:m.start()] + newbody + text[(end if end > 0 else len(text)):]
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
                print(f"[validate_forward_args] {img}: {n} forwarding defect(s) {'pending' if check else 'repaired'}")
            total += n
    return 1 if check and total else 0

if __name__ == "__main__":
    sys.exit(main())
