#!/usr/bin/env python3
"""timer_signed_diffs.py — timer expiry deltas are signed in the four timer reinsert epilogues.

Machine evidence (fmacfw_h_u02 ``mem_copy_util`` 0x124bfc, write-traced at
``read_rf_timer`` boot_ptr): the original epilogue recomputes the expiry delta
with

    subs r4, r4, r1
    cmp  r4, #0
    blt  <tailcall>              ; and the mirrored cpsie path uses bge to skip it
    mov.w r0, #0x20000000
    b.w  irq_pending_bits_set

The intervening ``cmp r4,#0`` means the taken condition is exactly the sign bit
of the wrapped 32-bit delta. In the traced boot_ptr run both sides read the
same counter sequence 0xc8, 0x12c, 0x190 from 0x40501010; the original then
calls the pending-bit setter and writes 0x20000000 to the shared event-pending
word at 0x1922a4. The linked reconstruction read the same values but did not
branch: Hex-Rays printed the test as ``a2 - *(volatile uint32_t ...) < 0``.
Because the pointee is unsigned, C makes the subtraction unsigned, so ``< 0``
is statically false and the compiler deletes the tailcall.

The same machine pattern exists in all four copies of the timer reinsert
routine (different LLM names, same body):

  fmacfw_h_u02  0x124bfc  mem_copy_util      off_124CD8
  fmacfw_u02    0x124d3c  unknown_worker     off_124E18
  fmacfwbt_u02  0x124f60  ke_event_lock      off_12503C
  lmacfw_rf_u02 0x11ab18  ke_enter_critical  off_11ABF4

Repair only the two epilogue tests in each of those blocks by casting the
wrapped difference back to ``int`` before the zero comparison, the same source
idiom already used elsewhere in the composed timer code. Idempotent;
``--check`` exits 1 when a rewrite is pending or the expected pair is absent.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
MARKER_RE = re.compile(r"(?m)^// (\S+) @ 0x([0-9a-fA-F]+)")

# short image -> (function address, timer-base data symbol)
TARGETS = {
    "fmacfw_h_u02": (0x124BFC, "off_124CD8"),
    "fmacfw_u02": (0x124D3C, "off_124E18"),
    "fmacfwbt_u02": (0x124F60, "off_12503C"),
    "lmacfw_rf_u02": (0x11AB18, "off_11ABF4"),
}


def block_span(text: str, addr: int) -> tuple[int, int] | None:
    marks = [(int(m.group(2), 16), m.start()) for m in MARKER_RE.finditer(text)]
    marks.sort()
    for i, (a, pos) in enumerate(marks):
        if a == addr:
            end = marks[i + 1][1] if i + 1 < len(marks) else len(text)
            return pos, end
    return None


def apply_image(text: str, addr: int, offsym: str) -> tuple[str, int]:
    span = block_span(text, addr)
    if span is None:
        return text, -1
    body = text[span[0]:span[1]]
    old = f"a2 - *((volatile uint32_t *){offsym} + 4) < 0"
    new = f"(int)(a2 - *((volatile uint32_t *){offsym} + 4)) < 0"
    if old not in body:
        # Fixed point is exactly two repaired epilogue occurrences and no raw ones.
        if body.count(new) == 2:
            return text, 0
        return text, -1
    out, n = body.replace(old, new), body.count(old)
    if n != 2 or out.count(new) != 2:
        return text, -1
    return text[:span[0]] + out + text[span[1]:], n


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--src", default="", help="override src root (testing)")
    args = ap.parse_args()
    root = Path(args.src) if args.src else REPO / "src"
    rc = 0
    for short, (addr, offsym) in TARGETS.items():
        path = root / short / "main.c"
        text = path.read_text(errors="replace")
        out, n = apply_image(text, addr, offsym)
        if n < 0:
            print(f"[timer_signed_diffs] ERROR: {short} timer epilogue not matched at {addr:#x}",
                  file=sys.stderr)
            rc = 1
            continue
        print(f"[timer_signed_diffs] {short}: {n} signed delta test(s) "
              f"{'pending' if args.check else 'applied/fixed-point'}")
        if n and args.check:
            rc = 1
        elif n and not args.check:
            path.write_text(out)
    return rc


if __name__ == "__main__":
    sys.exit(main())
