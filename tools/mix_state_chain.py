#!/usr/bin/env python3
"""mix_state_chain.py — repair machine-proven Michael-mix state chaining.

Hex-Rays emits uninitialized r1 variables in the four-round descriptor mix
constructors. Machine truth is narrower and exact: the caller initializes two
state words at a1/a1+4, forms r1=a1+4 once, and invokes the byte-identical
mix helper four times. The helper reads and writes only through those two
state pointers; it never writes r0 or r1. Consequently every round uses the
same two state pointers and the caller returns a1.

Machine proof anchors:
  fmacfw_h  caller 0x1334a4, helper 0x133470
  fmacfw    caller 0x1335e4, helper 0x1335b0
  fmacfwbt  caller 0x133800, helper 0x1337cc

Helper bodies are byte-identical clones. They contain no `mov`/`add`/pop-write
to r0 or r1 before `bx lr`; both argument registers are preserved. The bogus
`v12`, `v14`, and `v16` operands in the decompiled chain are therefore not
input data or machine state — they are uninitialized decompiler artifacts.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
TARGETS = {
    "fmacfw_h_u02": (0x1334A4, "bt_packet_parse", "crypto_mix_round"),
    "fmacfw_u02": (0x1335E4, "crypto_load_args", "crypto_mix_round"),
    "fmacfwbt_u02": (0x133800, "assemble_bt_descriptor", "hash_mix_words"),
}

CHAIN = (
    "  v11 = {callee}((volatile uint32_t *)a1, (volatile int *)(a1 + 4), v8);\n"
    "  v13 = {callee}(v11, v12, v9);\n"
    "  v15 = {callee}(v13, v14, v6);\n"
    "  return {callee}(v15, v16, v10);"
)
FIXED = (
    "  {callee}((volatile uint32_t *)a1, (volatile int *)(a1 + 4), v8);\n"
    "  {callee}((volatile uint32_t *)a1, (volatile int *)(a1 + 4), v9);\n"
    "  {callee}((volatile uint32_t *)a1, (volatile int *)(a1 + 4), v6);\n"
    "  {callee}((volatile uint32_t *)a1, (volatile int *)(a1 + 4), v10);\n"
    "  return (volatile uint32_t *)a1;"
)
DECLS = (
    "  volatile uint32_t *v11; // r0\n"
    "  volatile int *v12; // r1\n"
    "  volatile uint32_t *v13; // r0\n"
    "  volatile int *v14; // r1\n"
    "  volatile uint32_t *v15; // r0\n"
    "  volatile int *v16; // r1\n"
)


def transform_body(body: str, callee: str):
    """Rewrite one exact machine-proven chain; return (body, count, error)."""
    old = CHAIN.format(callee=callee)
    if old not in body:
        if FIXED.format(callee=callee) in body:
            return body, 0, None
        return body, 0, "machine-proven mix chain not found"
    out = body.replace(old, FIXED.format(callee=callee), 1)
    out = out.replace(DECLS, "", 1)
    return out, 1, None


def transform(text: str, addr: int, callee: str):
    m = re.search(rf"(?m)^// \w+ @ 0x{addr:x}\s*$", text)
    if not m:
        return text, 0, "marker not found"
    end = text.find("\n// ", m.end())
    end = len(text) if end < 0 else end
    body = text[m.start():end]
    out, n, err = transform_body(body, callee)
    if n:
        text = text[:m.start()] + out + text[end:]
    return text, n, err


def apply_one(root: Path, short: str, addr: int, callee: str, check: bool):
    for path in [root / short / "main.c"] + sorted((root / short / "modules").glob("mod*.c")):
        if not path.exists():
            continue
        text = path.read_text(errors="replace")
        if f"@ 0x{addr:x}" not in text:
            continue
        out, n, err = transform(text, addr, callee)
        if n and not check:
            path.write_text(out)
        return n, err
    return 0, "function not found"


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--src", default="")
    args = ap.parse_args()
    root = Path(args.src) if args.src else REPO / "src"
    rc = 0
    for short, (addr, _name, callee) in TARGETS.items():
        n, err = apply_one(root, short, addr, callee, args.check)
        print(f"[mix_state_chain] {short}: {n} rewrite(s)" + (" pending" if args.check else " applied/fixed-point"))
        if err:
            print(f"[mix_state_chain] ERROR {short}: {err}", file=sys.stderr)
            rc = 1
        elif n and args.check:
            rc = 1
    return rc


if __name__ == "__main__":
    sys.exit(main())
