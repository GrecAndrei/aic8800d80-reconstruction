#!/usr/bin/env python3
"""signed_halfwords.py — restore Hex-Rays signed `__int16` (`int16_t`) semantics.

Hex-Rays distinguishes unsigned `_WORD` / `unsigned __int16` (`uint16_t`)
from signed `__int16` (`int16_t`, matching ARM `ldrsh` / `sxth`). The earlier
per-function conversion replaced bare `__int16` with `uint16_t`, turning
signed target thresholds (e.g. `gpio_mode_set` and `gpio_pad_ctrl_set`) and
negative halfword checks (`if ( **(int16_t **)off_... < 0 )`) into unsigned
reads and always-false branches.

Anchored to `harness_v25/out/<image>_bin_types/`, this rule restores `int16_t`
per function on matching local/array declarations, `(volatile) uint16_t */**`
data-symbol casts, always-false `**(volatile uint16_t **) < 0` comparisons,
and matching `(int16_t)(...)` casts. Idempotent; `--check` exits 1 if anything
is pending.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
IMAGES = {
    "fmacfw_u02": "fmacfw_8800d80_u02",
    "fmacfw_h_u02": "fmacfw_8800d80_h_u02",
    "fmacfwbt_u02": "fmacfwbt_8800d80_u02",
    "lmacfw_rf_u02": "lmacfw_rf_8800d80_u02",
}
MARKER = re.compile(r"^// (\S+) @ 0x([0-9a-fA-F]+)[ \t]*$", re.M)
BODIES = "/* --- function bodies --- */"
BT_LOCAL = re.compile(r"^\s+int16_t(?:\s*\*+\s*|\s+)([A-Za-z_]\w*)(?:\[[^\]]*\])?;", re.M)
BT_PTRCAST = re.compile(r"\(\s*int16_t\s*(\*+)\)\s*([A-Za-z_]\w*)")
BT_HEXCAST = re.compile(r"\(\s*int16_t\s*(\*+)\)\s*(?:off|dword|word|unk)_([0-9A-Fa-f]{4,8})\b")
BT_VALCAST = re.compile(r"\(\s*int16_t\s*\)\s*\(([^()\n]+)\)")
ANY_INT16 = re.compile(r"(?<!u)int16_t\b")


def apply_function(body: str, bin_types_text: str) -> tuple[str, int]:
    """Restore signed `int16_t` sites in one composed function body."""
    if not ANY_INT16.search(bin_types_text) or "{" not in bin_types_text or "{" not in body:
        return body, 0
    bt_body = bin_types_text[bin_types_text.index("{"):]
    changes = 0

    locs = sorted(set(BT_LOCAL.findall(bt_body)))
    if locs:
        alt = "|".join(re.escape(v) for v in locs)
        pat_loc = re.compile(
            rf"(\b(?:volatile\s+)?)uint16_t((?:\s*\*+\s*|\s+)(?:{alt})(?:\[[^\]]*\])?;)"
        )
        body, n = pat_loc.subn(r"\1int16_t\2", body)
        changes += n

    for stars, sym in sorted(set(BT_PTRCAST.findall(bt_body))):
        pat_ptr = re.compile(
            r"(\(\s*(?:volatile\s+)?)uint16_t(\s*" + re.escape(stars) + r"\)\s*" + re.escape(sym) + r"\b)"
        )
        body, n = pat_ptr.subn(r"\1int16_t\2", body)
        changes += n

    for stars, hex_addr in sorted(set(BT_HEXCAST.findall(bt_body))):
        pat_hex = re.compile(
            r"(\(\s*(?:volatile\s+)?)uint16_t(\s*"
            + re.escape(stars)
            + r"\)\s*(?:off|dword|word|unk)_"
            + re.escape(hex_addr)
            + r"\b)"
        )
        body, n = pat_hex.subn(r"\1int16_t\2", body)
        changes += n

    # Value casts `(int16_t)(...)` matching exact expressions or when unsigned
    # `(uint16_t)` does not appear in the bin_types body.
    if re.search(r"\(\s*int16_t\s*\)", bt_body):
        if not re.search(r"\(\s*uint16_t\s*\)", bt_body):
            body, n = re.subn(r"\(\s*uint16_t\s*\)", "(int16_t)", body)
            changes += n
        else:
            for expr in sorted(set(BT_VALCAST.findall(bt_body))):
                pat_val = re.compile(r"\(\s*uint16_t\s*\)\s*\(" + re.escape(expr) + r"\)")
                body, n = pat_val.subn(f"(int16_t)({expr})", body)
                changes += n

    # Any remaining `**(volatile uint16_t **)<sym> < 0` in a function where
    # bin_types has `int16_t` (name-divergent globals across renames).
    if re.search(r"\*\*\(\s*int16_t\s*\*\*\)", bt_body):
        pat_dbl = re.compile(r"(\*\*\(\s*(?:volatile\s+)?)uint16_t(\s*\*\*\)\s*\S+\s*(?:<|>=)\s*0\b)")
        body, n = pat_dbl.subn(r"\1int16_t\2", body)
        changes += n

    # Propagate signed pointer types across assignments when variable names in
    # bin_types diverged or a data symbol was renamed:
    # (A) `lhs = (volatile int16_t **)rhs;` -> promote `lhs`'s `uint16_t` decl.
    rhs_signed = sorted({m.group(1) for m in re.finditer(
        r"^\s*([A-Za-z_]\w*)\s*=\s*\(\s*(?:volatile\s+)?int16_t\s*\*+\s*\)", body, re.M
    )})
    if rhs_signed:
        alt_r = "|".join(re.escape(v) for v in rhs_signed)
        pat_r = re.compile(
            rf"(\b(?:volatile\s+)?)uint16_t((?:\s*\*+\s*|\s+)(?:{alt_r})\s*;)"
        )
        body, n = pat_r.subn(r"\1int16_t\2", body)
        changes += n

    # (B) `lhs` declared `(volatile) int16_t *` assigned from `(volatile uint16_t *)sym` ->
    # promote the RHS cast to `(volatile int16_t *)`.
    decl_signed = sorted({m.group(1) for m in re.finditer(
        r"^\s+(?:volatile\s+)?int16_t(?:\s*\*+\s*|\s+)([A-Za-z_]\w*)\s*;", body, re.M
    )})
    if decl_signed:
        alt_d = "|".join(re.escape(v) for v in decl_signed)
        pat_l = re.compile(
            rf"(^\s*(?:{alt_d})\s*=\s*\(\s*(?:volatile\s+)?)uint16_t(\s*\*+\s*\))",
            re.M,
        )
        body, n = pat_l.subn(r"\1int16_t\2", body)
        changes += n

    return body, changes


def apply_image(text: str, types_dir: Path) -> tuple[str, int]:
    """Return (text, total replacements) for one composed main.c."""
    if not types_dir.is_dir():
        return text, 0
    by_addr = {p.name.split("_", 1)[0].lower(): p for p in types_dir.glob("*.c")}
    split = text.index(BODIES)
    head, tail = text[:split], text[split:]
    marks = list(MARKER.finditer(tail))
    pieces, last, total = [], 0, 0
    for i, m in enumerate(marks):
        tp = by_addr.get(m.group(2).lower())
        if tp is None:
            continue
        end = marks[i + 1].start() if i + 1 < len(marks) else len(tail)
        updated, n = apply_function(tail[m.end():end], tp.read_text(errors="replace"))
        if n:
            pieces.append(tail[last:m.end()])
            pieces.append(updated)
            last = end
            total += n
    pieces.append(tail[last:])
    return head + "".join(pieces), total


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    pending = 0
    for short, image in IMAGES.items():
        path = REPO / "src" / short / "main.c"
        types_dir = REPO / "harness_v25" / "out" / f"{image}_bin_types"
        out, n = apply_image(path.read_text(errors="replace"), types_dir)
        pending += n
        print(f"[signed_halfwords] {short}: {n} sites {'pending' if args.check else 'restored'}")
        if n and not args.check:
            path.write_text(out)
    return 1 if args.check and pending else 0


if __name__ == "__main__":
    sys.exit(main())
