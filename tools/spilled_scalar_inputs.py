#!/usr/bin/env python3
"""spilled_scalar_inputs.py — recover argument values spilled then reloaded on the stack.

Hex-Rays occasionally loses the initializing store in a prologue of the form

    str rN, [sp, #off]
    ldr rM, [sp, #off]

and emits only an undersized, never-written local annotated at that stack
offset. The composed C then reads uninitialized stack memory even though the
original unambiguously reloaded argument rN. This rule is machine-grounded:
it only rewrites a function when the original bytes contain that exact
store/reload pair before the input register is overwritten, the composed local
is never otherwise used, and every use is a scalar uint32_t read of the slot.

AAPCS argument mapping: r0→a1, r1→a2, r2→a3, r3→a4.
Idempotent; --check exits 1 if anything is pending.
"""
import argparse
import re
import sys
from pathlib import Path

from capstone import CS_ARCH_ARM, CS_MODE_MCLASS, CS_MODE_THUMB, Cs

REPO = Path(__file__).resolve().parent.parent
IMAGES = {
    "fmacfw_u02": "fmacfw_8800d80_u02",
    "fmacfw_h_u02": "fmacfw_8800d80_h_u02",
    "fmacfwbt_u02": "fmacfwbt_8800d80_u02",
    "lmacfw_rf_u02": "lmacfw_rf_8800d80_u02",
}
MARKER = re.compile(r"^// (\S+) @ (0x[0-9a-fA-F]+)[ \t]*$", re.M)
STR_RE = re.compile(r"^r([0-3]),\[sp,#(\d+)\]$")
LDR_RE = re.compile(r"^r\d+,\[sp,#(\d+)\]$")


def spilled_input(image: bytes, addr: int) -> tuple[int, int] | None:
    """Return (argument register number, sp offset) proven by the prologue."""
    off = addr - 0x100000
    if not 0 <= off < len(image):
        return None
    md = Cs(CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_MCLASS)
    ins = list(md.disasm(image[off:off + 16], addr, count=5))
    for i, first in enumerate(ins[:-1]):
        if first.mnemonic != "str":
            continue
        sm = STR_RE.match(first.op_str.replace(" ", ""))
        if not sm:
            continue
        regno, slot = int(sm.group(1)), int(sm.group(2))
        second = ins[i + 1]
        lm = LDR_RE.match(second.op_str.replace(" ", ""))
        if second.mnemonic == "ldr" and lm and int(lm.group(1)) == slot:
            return regno, slot
    return None


def rewrite_body(body: str, arg: str, slot: int) -> tuple[str, int]:
    decl = re.compile(
        rf"^\s+(?:uint8_t|uint32_t)\s+(vars\d+)\[[^\]]+\];[^\n]*\[sp\+{slot:x}h\][^\n]*\n",
        re.M,
    )
    dm = decl.search(body)
    if not dm:
        return body, 0
    var = dm.group(1)
    read = re.compile(rf"\*\((?:volatile\s+)?uint32_t\s*\*\)\s*{re.escape(var)}\b")
    reads = len(read.findall(body))
    if not reads:
        return body, 0

    candidate = read.sub(arg, body)
    # Safety: after replacing every scalar read, the declaration must be the
    # only remaining use. Any store, address-of, indexing, or independent use
    # means the stack slot has semantics this rule does not understand.
    rest = candidate[:dm.start()] + candidate[dm.end():]
    if re.search(rf"\b{re.escape(var)}\b", rest):
        return body, 0
    candidate = candidate[:dm.start()] + candidate[dm.end():]
    return candidate, reads


def apply(text: str, image: bytes) -> tuple[str, int]:
    matches = list(MARKER.finditer(text))
    if not matches:
        return text, 0
    out = [text[:matches[0].start()]]
    total = 0
    for idx, m in enumerate(matches):
        end = matches[idx + 1].start() if idx + 1 < len(matches) else len(text)
        body = text[m.start():end]
        evidence = spilled_input(image, int(m.group(2), 16))
        if evidence is not None:
            regno, slot = evidence
            body, n = rewrite_body(body, f"a{regno + 1}", slot)
            total += n
        out.append(body)
    return "".join(out), total


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    pending = 0
    for short, long in IMAGES.items():
        path = REPO / "src" / short / "main.c"
        fw = REPO / "inputs" / "firmware" / f"{long}.bin"
        out, n = apply(path.read_text(errors="replace"), fw.read_bytes())
        pending += n
        print(f"[spilled_inputs] {short}: {n} spilled-input reads {'pending' if args.check else 'recovered'}")
        if n and not args.check:
            path.write_text(out)
    return 1 if args.check and pending else 0


if __name__ == "__main__":
    sys.exit(main())
