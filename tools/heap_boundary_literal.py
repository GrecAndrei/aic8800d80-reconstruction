#!/usr/bin/env python3
"""heap_boundary_literal.py — patch_alignment's heap end is a literal constant, not hci_tx_alloc code.

Machine evidence (fmacfw_h_u02): patch_alignment @ 0x12c954 executes
``ldr r3, [pc, #0x30]`` at 0x12c96e. The literal address is 0x12c9a0 and the
word there is 0x001922a4, the allocator control-block base / end of the heap
free region. IDA/Hex-Rays incorrectly made 0x12c9a0 the first byte of
hci_tx_alloc (real entry 0x12c9a4; every BL targets that), so the composed C
dereferences the reconstructed hci_tx_alloc function's prologue bytes instead
of using the literal. The byte-identical fmacfw_u02 clone at 0x12ca94 is not
mis-bound and decompiles the same expression as the literal-pool word
``dword_12CAE0 & 0xFFFFFFFC``.

Repair the one h-image expression to the constant the machine loads. The value
is already word-aligned, so the mask is behavior-preserving documentation of
the original ``bic r3,r3,#3``. Idempotent; ``--check`` exits 1 when the rewrite
is pending or the expected site is absent.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
MARKER_RE = re.compile(r"(?m)^// (\S+) @ 0x([0-9a-fA-F]+)")

TARGETS = {
    "fmacfw_h_u02": {
        "addr": 0x12C954,
        "old": "  v4 = (*(volatile uint32_t *)hci_tx_alloc & 0xFFFFFFFC) - (uint32_t)result;",
        "new": "  v4 = (0x1922A4u & 0xFFFFFFFCu) - (uint32_t)result;",
    },
}


def block_span(text: str, addr: int) -> tuple[int, int] | None:
    marks = [(int(m.group(2), 16), m.start()) for m in MARKER_RE.finditer(text)]
    marks.sort()
    for i, (a, pos) in enumerate(marks):
        if a == addr:
            end = marks[i + 1][1] if i + 1 < len(marks) else len(text)
            return pos, end
    return None


def apply_image(text: str, addr: int, old: str, new: str) -> tuple[str, int, str | None]:
    """Return (text, rewrites, error). 0 rewrites with no error is fixed point."""
    span = block_span(text, addr)
    if span is None:
        return text, 0, f"function {addr:#x} not found"
    body = text[span[0]:span[1]]
    n_old = body.count(old)
    n_new = body.count(new)
    if n_old == 1:
        body = body.replace(old, new, 1)
        return text[:span[0]] + body + text[span[1]:], 1, None
    if n_old == 0 and n_new == 1:
        return text, 0, None
    return text, 0, f"expected exactly one pending or repaired site, got old={n_old} new={n_new}"


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--src", default="", help="override src root (testing)")
    args = ap.parse_args()
    root = Path(args.src) if args.src else REPO / "src"
    rc = 0
    for short, spec in TARGETS.items():
        imgroot = root / short
        paths = [imgroot / "main.c"] + sorted((imgroot / "modules").glob("mod*.c"))
        chosen = None
        for path in paths:
            if not path.exists():
                continue
            text = path.read_text(errors="replace")
            out, n, err = apply_image(text, spec["addr"], spec["old"], spec["new"])
            if err and "not found" in err:
                continue
            chosen = (path, out, n, err)
            break
        if chosen is None:
            print(f"[heap_boundary_literal] ERROR {short}: function {spec['addr']:#x} not found", file=sys.stderr)
            rc = 1
            continue
        path, out, n, err = chosen
        if err:
            print(f"[heap_boundary_literal] ERROR {short}: {err}", file=sys.stderr)
            rc = 1
            continue
        print(f"[heap_boundary_literal] {short}: {n} heap-boundary literal(s) "
              f"{'pending' if args.check else 'applied/fixed-point'}")
        if n and args.check:
            rc = 1
        elif n and not args.check:
            path.write_text(out)
    return rc


if __name__ == "__main__":
    sys.exit(main())
