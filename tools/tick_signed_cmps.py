#!/usr/bin/env python3
"""tick_signed_cmps.py — tick-delta deadline comparisons are signed in the original machine code.

CANDIDATE RULE — NOT YET WIRED INTO tools/post_compose.py. Machine evidence:
/tmp/unsigned_cmp_analysis/report.md.

Hex-Rays prints the firmware's wraparound-safe tick comparisons as plain
arithmetic chains ending in `< 0` / `>= 0`, e.g.

    while ( *((volatile uint32_t *)off_10066C + 4) - result < 0 );

Because one operand is a `uint32_t` load (or a `uint32_t` data symbol), C's
usual arithmetic conversions make the whole chain unsigned: `< 0` is
statically false and `>= 0` statically true, so the compiler deletes the test
(and the loop body / reset / error path it guarded). The original machine
code instead tests the sign bit of the wrapped 32-bit result with a SIGNED
branch:

  family 1  subs r3,r3,r0 ; cmp r3,#0 ; blt            (mmio_read32 clones)
  family 2  subs r2,r2,r0 ; cmn r2,r1 ; bmi            (process_rx_packet clones)
  family 3  subs x2       ; cmp.w r7,#0xfa0 ; bpl      (radio_disabled_check clones)
  family 4  subs/sub #0x1380/subs #8 ; cmp #0 ; bge.w/blt/it-ge  (lll_conn_event_prepare clones)
  family 5  subs chains   ; cmp r3,#0 ; blt/bge        (rf_radio_status clones)
  family 6  subs r3,r3,r2 ; cmp r3,#0 ; bge            (invalid_handler clones)

The repair is the same idiom as timer_signed_diffs.py: wrap the chain in
(int)(...) so the wrapped unsigned arithmetic is reinterpreted as signed
before the zero comparison — exactly the machine semantics, since mod-2^32
arithmetic is associative and the branch only reads bit 31.

Scope per function is machine-verified; every replacement site in a function
backed by the sequences above. fmacfwbt_u02's family-6 clone already carries
Hex-Rays' own (int) cast and needs no rule. Idempotent; `--check` exits 1
when a rewrite is pending or an expected pattern is absent.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
MARKER_RE = re.compile(r"(?m)^// (\S+) @ 0x([0-9a-fA-F]+)")

def cast0(expr: str) -> str:
    """(int)(chain) < 0 / >= 0 rewrite pair for a chain ending in the operator."""
    return f"(int)({expr})"

def ge(chain):  return (f"{chain} >= 0", f"(int)({chain}) >= 0")
def lt0(chain): return (f"{chain} < 0",  f"(int)({chain}) < 0")

# ---------------- family chains ----------------
def fam1(offsym):
    return [lt0(f"*((volatile uint32_t *){offsym} + 4) - result")]

def fam2(dword):
    return [lt0(f"{dword} - v12[4] + *(volatile uint32_t *)(v7 + 120)")]

def fam3(var, ptrvar):
    return [lt0(f"{var} - *(volatile uint32_t *)({ptrvar} + 4) - result - 4000")]

def fam4(offsym):
    gechain = f"v8 - *((volatile uint32_t *){offsym} + 4) - 5000"
    return [
        (ge(gechain)[0],  ge(gechain)[1],  4),   # four >= 0 deadline tests
        (lt0(gechain)[0], lt0(gechain)[1], 1),   # the do-while tail test
        (ge("v8 - v11[4] - 5000")[0], ge("v8 - v11[4] - 5000")[1], 1),
    ]

def fam5(off_x0, off_x1, off_x2):
    t0old = (f"32 * *(volatile uint32_t *){off_x0}\n"
             f"     - 2000\n"
             f"     - *((volatile uint16_t *){off_x1} + 92)\n"
             f"     - *((volatile uint16_t *){off_x1} + 93) < 0")
    t0new = (f"(int)(32 * *(volatile uint32_t *){off_x0}\n"
             f"     - 2000\n"
             f"     - *((volatile uint16_t *){off_x1} + 92)\n"
             f"     - *((volatile uint16_t *){off_x1} + 93)) < 0")
    return [
        (t0old, t0new, 1),
        (lt0(f"v3 - *((volatile uint32_t *){off_x2} + 4) - 2000 - *((volatile uint16_t *){off_x1} + 92) - v4") +
         (1,)),
        (lt0(f"v3 - *((volatile uint32_t *){off_x2} + 4) + 5000") + (1,)),
        (lt0(f"v3 - *((volatile uint32_t *){off_x2} + 4) - v4") + (1,)),
    ]

def fam6(offsym):
    return [lt0(f"*(volatile uint32_t *)(v8 + 8) - *((volatile uint32_t *){offsym} + 4)") + (1,)]

def triples(rules):
    out = []
    for r in rules:
        if len(r) == 2:
            out.append((r[0], r[1], 1))
        else:
            out.append(r)
    return out

# image -> [(function_addr, [(old, new, count), ...]), ...]
TARGETS = {
    "fmacfw_h_u02": [
        (0x100644, triples(fam1("off_10066C"))),
        (0x1224bc, triples(fam2("dword_12264C"))),
        (0x127fdc, triples(fam3("v11", "v6"))),
        (0x12a6a0, triples(fam4("off_12A978"))),
        (0x12bc00, triples(fam5("off_12BCE0", "off_12BCE4", "off_12BCDC"))),
        (0x12c5fc, triples(fam6("off_12C6AC"))),
    ],
    "fmacfw_u02": [
        (0x100644, triples(fam1("off_10066C"))),
        (0x1225fc, triples(fam2("dword_12278C"))),
        (0x12811c, triples(fam3("v11", "v6"))),
        (0x12a7e0, triples(fam4("off_12AAB8"))),
        (0x12bd40, triples(fam5("off_12BE20", "off_12BE24", "off_12BE1C"))),
        (0x12c73c, triples(fam6("off_12C7EC"))),
    ],
    "fmacfwbt_u02": [
        (0x100644, triples(fam1("off_10066C"))),
        (0x122830, triples(fam2("dword_1229C0"))),
        (0x128340, triples(fam3("v11", "v6"))),
        (0x12aa04, triples(fam4("off_12ACDC"))),
        (0x12bf68, triples(fam5("off_12C048", "off_12C04C", "off_12C044"))),
        # family 6 already correct in the decompile ((int) cast present, line 57554)
    ],
    "lmacfw_rf_u02": [
        (0x100560, triples(fam1("off_100588"))),
        (0x11c01c, triples(fam3("v8", "v3"))),
        (0x11dc54, triples(fam6("off_11DD04"))),
    ],
}


def block_span(text: str, addr: int):
    marks = [(int(m.group(2), 16), m.start()) for m in MARKER_RE.finditer(text)]
    marks.sort()
    for i, (a, pos) in enumerate(marks):
        if a == addr:
            end = marks[i + 1][1] if i + 1 < len(marks) else len(text)
            return pos, end
    return None


def apply_image(text: str, entries) -> tuple[str, int, list]:
    """Apply all rules; returns (text, n_applied, errors)."""
    total = 0
    errors = []
    for addr, rules in entries:
        span = block_span(text, addr)
        if span is None:
            errors.append(f"function {addr:#x} not found")
            continue
        body = text[span[0]:span[1]]
        for old, new, want in rules:
            n_old = body.count(old)
            n_new = body.count(new)
            if n_old == 0:
                if n_new == want:
                    continue  # fixed point
                errors.append(f"{addr:#x}: neither old ({n_old}) nor fixed-point new ({n_new}!={want}) for {old[:60]!r}")
                continue
            if n_old != want:
                errors.append(f"{addr:#x}: old count {n_old} != {want} for {old[:60]!r}")
                continue
            body = body.replace(old, new)
            total += n_old
        text = text[:span[0]] + body + text[span[1]:]
    return text, total, errors


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--src", default="", help="override src root (testing)")
    args = ap.parse_args()
    root = Path(args.src) if args.src else REPO / "src"
    rc = 0
    for short, entries in TARGETS.items():
        path = root / short / "main.c"
        text = path.read_text(errors="replace")
        out, n, errors = apply_image(text, entries)
        for e in errors:
            print(f"[tick_signed_cmps] ERROR {short}: {e}", file=sys.stderr)
            rc = 1
        print(f"[tick_signed_cmps] {short}: {n} signed comparison(s) "
              f"{'pending' if args.check else 'applied/fixed-point'}")
        if n and args.check:
            rc = 1
        elif n and not args.check:
            path.write_text(out)
    return rc


if __name__ == "__main__":
    sys.exit(main())
