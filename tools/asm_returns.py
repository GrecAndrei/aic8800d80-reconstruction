#!/usr/bin/env python3
"""asm_returns.py — put back the returns the `__asm` strip deleted.

Where a function leaves through its epilogue from the middle of a block,
Hex-Rays prints the epilogue as a statement, `__asm { POP {R4-R6,PC} }`: a
return of whatever r0 holds. The v19 post-processing stripped every `__asm`
block, so `if ( !v20 ) LABEL_11: __asm { POP.W {R4-R11,PC} }` became an `if`
with an empty line under it, and the `if` now guards the statement after it:
the function falls through where the binary returns.

The Hex-Rays text before the strip is tracked under
`harness_v25/out/<image>_bin_annotated/`. The strip kept the line structure, so
a statement sits the same number of lines above the function's closing brace in
both. For each `__asm { POP ... PC }` line there, if the composed line at the
same distance is empty (blank, or the `{ }` the strip left), it becomes
`return;` in a void function and `return result;` where the function has
Hex-Rays' r0 variable `result`. Other functions and other `__asm` blocks are
left alone. Idempotent; `--check` exits 1 if anything is pending.
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
POP_PC = re.compile(r"^(\s*)__asm\s*\{\s*POP(?:\.W)?\s+\{[^}]*\bPC\}\s*\}\s*$")
EMPTY = ("", "{ }")


def return_statement(body: str) -> str | None:
    """The return this function's epilogue stands for, or None if unknown."""
    head = body.lstrip().split("{", 1)[0]
    if re.match(r"void\s+(?!\*)[A-Za-z_]\w*\s*\(", head):
        return "return;"
    if re.search(r"\bresult\b", head) or re.search(r"^\s*[\w \*]+\bresult; //", body, re.M):
        return "return result;"
    return None


def restore(body: str, annotated: str) -> tuple[str, int, int]:
    """(body, returns restored, epilogue slots left) for one function."""
    ann = annotated.rstrip().split("\n")
    stripped = body.rstrip()
    lines = stripped.split("\n")
    stmt = return_statement(body)
    done = left = 0
    for k, text in enumerate(ann):
        m = POP_PC.match(text)
        if not m:
            continue
        i = len(lines) - (len(ann) - k)
        if i < 0 or lines[i].strip() not in EMPTY:
            continue
        if stmt is None:
            left += 1
            continue
        lines[i] = m.group(1) + stmt
        done += 1
    if not done:
        return body, 0, left
    return "\n".join(lines) + body[len(stripped):], done, left


def restore_image(text: str, annotated_dir: Path) -> tuple[str, list[str], int]:
    """(text, functions changed, slots left) for one composed main.c."""
    by_addr = {p.name.split("_", 1)[0]: p for p in annotated_dir.glob("*.c")}
    marks = list(MARKER.finditer(text))
    out, changed, left, pos = [], [], 0, 0
    for i, m in enumerate(marks):
        path = by_addr.get(m.group(2).lower())
        if path is None:
            continue
        ann = path.read_text(errors="replace")
        if "__asm" not in ann:
            continue
        end = marks[i + 1].start() if i + 1 < len(marks) else len(text)
        body, n, l = restore(text[m.end():end], ann)
        left += l
        if n:
            out.append(text[pos:m.end()])
            out.append(body)
            pos = end
            changed.append(m.group(1))
    out.append(text[pos:])
    return "".join(out), changed, left


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    pending = 0
    for short, image in IMAGES.items():
        path = REPO / "src" / short / "main.c"
        out, changed, left = restore_image(path.read_text(errors="replace"),
                                           REPO / "harness_v25" / "out" / f"{image}_bin_annotated")
        pending += len(changed)
        print(f"[asm_returns] {short}: {len(changed)} functions "
              f"{'pending' if args.check else 'restored'} ({', '.join(changed) or '-'}); "
              f"{left} epilogue slots left (no `result`, not void)")
        if changed and not args.check:
            path.write_text(out)
    return 1 if args.check and pending else 0


if __name__ == "__main__":
    sys.exit(main())
