#!/usr/bin/env python3
"""mrs_exception_state.py — restore the distinct MRS registers in the exception dump clone.

Hex-Rays prints CONTROL, xPSR, PSP, MSP, and PRIMASK reads as the same
``__get_CPSR()`` intrinsic. The machine-proven sequence in all three fmac
exception/timeout dump clones is instead::

    mrs r1, CONTROL
    mrs r2, XPSR
    mrs r5, PSP
    mrs r4, MSP
    mrs r3, PRIMASK
    mov r0, lr

with the variadic dump arguments ordered CONTROL, xPSR, PSP, MSP, PRIMASK,
LR. Treating the stack pointers as the PRIMASK shadow makes MSP/PSP zero in
the reconstruction, suppressing part of the dump and changing the number of
``\\r\\n`` rows emitted before the panic line.

Machine evidence:
  fmacfw_h   0x114608+0x24 (hardware 0x13462c)
  fmacfw     0x114748+0x24 (hardware 0x13476c)
  fmacfwbt   0x1145a4+0x24 (hardware 0x1345c8)

Address-keyed and idempotent; --check reports pending rewrites.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
TARGETS = {
    "fmacfw_h_u02": (0x114608, "alloc_tx_event"),
    "fmacfw_u02": (0x114748, "event_dispatch"),
    "fmacfwbt_u02": (0x1145A4, "ke_event_schedule_1"),
}
MARKER_RE = re.compile(r"(?m)^// (\w+) @ 0x([0-9a-fA-F]+)\s*$")


def function_span(text: str, addr: int) -> tuple[int, int] | None:
    starts = [(int(m.group(2), 16), m.start()) for m in MARKER_RE.finditer(text)]
    starts.sort()
    for i, (a, pos) in enumerate(starts):
        if a == addr:
            return pos, starts[i + 1][1] if i + 1 < len(starts) else len(text)
    return None


def transform_body(body: str, helper: str) -> tuple[str, int, str | None]:
    if "__get_CONTROL();" in body:
        expected = f"{helper}(aControl08xXpsr_0, CONTROL, v4, v5, v6, __get_PRIMASK(), (int)__get_LR());"
        return (body, 0, None) if expected in body else (body, 0, "partially repaired CONTROL site")
    required = [
        "unsigned int CPSR; // r1",
        "CPSR = __get_CPSR();",
        "v4 = __get_CPSR();",
        "v5 = __get_CPSR();",
        "v6 = __get_CPSR();",
    ]
    if any(x not in body for x in required):
        return body, 0, "expected CPSR assignment block not found"
    old_call = f"{helper}(aControl08xXpsr_0, CPSR, v4, v5, v6, __get_CPSR(), v2);"
    if old_call not in body:
        return body, 0, "expected variadic CPSR call not found"
    out = body.replace("unsigned int CPSR; // r1", "unsigned int CONTROL; // r1", 1)
    out = out.replace("CPSR = __get_CPSR();", "CONTROL = __get_CONTROL();", 1)
    # Replace only the three consecutive assignments after the CONTROL line.
    head, tail = out.split("CONTROL = __get_CONTROL();", 1)
    prefix, rest = tail.split("v4 = __get_CPSR();", 1)
    rest = rest.replace("v5 = __get_CPSR();", "v5 = __get_PSP();", 1)
    rest = rest.replace("v6 = __get_CPSR();", "v6 = __get_MSP();", 1)
    out = head + "CONTROL = __get_CONTROL();" + prefix + "v4 = __get_XPSR();" + rest
    new_call = f"{helper}(aControl08xXpsr_0, CONTROL, v4, v5, v6, __get_PRIMASK(), (int)__get_LR());"
    out = out.replace(old_call.replace("CPSR,", "CONTROL,"), new_call, 1)
    if old_call in out:
        out = out.replace(old_call, new_call, 1)
    return out, 1, None


def apply_image(text: str, addr: int, helper: str) -> tuple[str, int, str | None]:
    span = function_span(text, addr)
    if span is None:
        return text, 0, f"function {addr:#x} not found"
    body = text[span[0]:span[1]]
    out, n, err = transform_body(body, helper)
    if n:
        text = text[:span[0]] + out + text[span[1]:]
    return text, n, err


def apply_one(root: Path, short: str, addr: int, helper: str, check: bool) -> tuple[int, str | None]:
    imgroot = root / short
    for path in [imgroot / "main.c"] + sorted((imgroot / "modules").glob("mod*.c")):
        if not path.exists():
            continue
        text = path.read_text(errors="replace")
        if f"@ 0x{addr:x}" not in text and f"@ 0x{addr:X}" not in text:
            continue
        out, n, err = apply_image(text, addr, helper)
        if err:
            return n, err
        if n and not check:
            path.write_text(out)
        return n, None
    return 0, f"function {addr:#x} not found in {short}"


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--src", default="", help="override src root (testing)")
    args = ap.parse_args()
    root = Path(args.src) if args.src else REPO / "src"
    rc = 0
    for short, (addr, helper) in TARGETS.items():
        n, err = apply_one(root, short, addr, helper, args.check)
        if err:
            print(f"[mrs_exception_state] ERROR {short}: {err}", file=sys.stderr)
            rc = 1
            continue
        print(f"[mrs_exception_state] {short}: {n} rewrite(s) {'pending' if args.check else 'applied/fixed-point'}")
        if n and args.check:
            rc = 1
    return rc


if __name__ == "__main__":
    sys.exit(main())
