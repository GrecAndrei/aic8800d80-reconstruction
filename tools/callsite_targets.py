#!/usr/bin/env python3
"""callsite_targets.py — bind duplicate-named call sites to the callee the binary targets.

The naming dataset gave one name to several distinct functions; compose keeps
the definitions apart with `_1`, `_2`, ... but a call site keeps the bare name,
so it binds to whichever unit got it. `fwstruct compose` corrects that from the
IDA call-edge export, which is not in the tree and misses tail branches. This
rule reads the edges from the firmware bytes instead: every direct `bl` / `b`
in a function's extent whose target is the start of another composed function.

A call site is rewritten only when the name it uses is NOT a target of the
function in the binary, and exactly one function of the same duplicate-name
family IS a target that the body does not otherwise name. It changes which
existing definition a name refers to; it adds no body and renames nothing.
Idempotent; `--check` exits 1 if anything is pending.
"""
import argparse
import bisect
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
IMAGES = {"fmacfw_u02": "fmacfw_8800d80_u02", "fmacfw_h_u02": "fmacfw_8800d80_h_u02",
          "fmacfwbt_u02": "fmacfwbt_8800d80_u02", "lmacfw_rf_u02": "lmacfw_rf_8800d80_u02"}
ANALYSIS_BASE = 0x100000
MARKER = re.compile(r"^// (\w+) @ 0x([0-9a-fA-F]+)[ \t]*$", re.M)
IDENT = re.compile(r"\b[A-Za-z_]\w*\b")
SUFFIX = re.compile(r"_\d+$")
PROTO = re.compile(r"^([A-Za-z_][\w \t\*]*?)\b(\w+)\(([^;{}]*)\);[ \t]*$", re.M)


def split_args(s: str) -> list[str]:
    out, depth, cur = [], 0, ""
    for ch in s:
        depth += ch in "([" 
        depth -= ch in ")]"
        if ch == "," and depth == 0:
            out.append(cur)
            cur = ""
        else:
            cur += ch
    return out + [cur] if cur.strip() else out


def prototypes(text: str) -> dict[str, tuple[bool, int | None]]:
    """name -> (returns void, parameter count or None when unspecified/variadic)."""
    out = {}
    for ret, name, params in PROTO.findall(text):
        params = params.strip()
        n = None if params == "" or "..." in params else (
            0 if params == "void" else len(split_args(params)))
        out.setdefault(name, (ret.strip().endswith("void") and "*" not in ret, n))
    return out


def call_arities(body: str, name: str) -> list[int]:
    """Argument count of every `name(...)` call in body."""
    out = []
    for m in re.finditer(r"\b" + re.escape(name) + r"\s*\(", body):
        depth, i = 1, m.end()
        while i < len(body) and depth:
            depth += body[i] in "(["
            depth -= body[i] in ")]"
            i += 1
        out.append(len(split_args(body[m.end():i - 1])))
    return out


def compiles_as(body: str, old: str, new: str, protos: dict) -> bool:
    """The rebinding must not need a new signature at the call site."""
    if old not in protos or new not in protos:
        return False
    (old_void, _), (new_void, new_n) = protos[old], protos[new]
    if new_void and not old_void:
        return False
    return new_n is None or all(n == new_n for n in call_arities(body, old))


def same_family(a: str, b: str) -> bool:
    """True when compose's `_N` dedupe suffix is all that separates two names."""
    if a == b:
        return False
    return SUFFIX.sub("", a) == b or SUFFIX.sub("", b) == a or (
        SUFFIX.search(a) and SUFFIX.search(b) and SUFFIX.sub("", a) == SUFFIX.sub("", b))


def direct_targets(blob: bytes, start: int, end: int, starts: set[int]) -> set[int]:
    """Function starts reached by a direct branch from [start, end)."""
    from capstone import CS_ARCH_ARM, CS_MODE_MCLASS, CS_MODE_THUMB, Cs
    md = Cs(CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_MCLASS)
    md.skipdata = True
    out = set()
    for ins in md.disasm(blob[start - ANALYSIS_BASE:end - ANALYSIS_BASE], start):
        if ins.mnemonic in ("bl", "b", "b.w") and ins.op_str.startswith("#"):
            t = int(ins.op_str[1:], 16)
            if t in starts and t != start:
                out.add(t)
    return out


def rebind(text: str, blob: bytes) -> tuple[str, list, list]:
    """Return (text, rebound, skipped), each [(caller, old callee, new callee)].

    Skipped: the binary targets the other definition, but its prototype does not
    fit the call as written, so the call site is left alone and reported.
    """
    marks = list(MARKER.finditer(text))
    addr = {m.group(1): int(m.group(2), 16) for m in marks}
    name = {a: n for n, a in addr.items()}
    order = sorted(name)
    starts = set(order)
    protos = prototypes(text)
    parts, changes, skipped, pos = [], [], [], 0
    for i, m in enumerate(marks):
        stop = marks[i + 1].start() if i + 1 < len(marks) else len(text)
        body = text[m.end():stop]
        a = int(m.group(2), 16)
        j = bisect.bisect_right(order, a)
        end = order[j] if j < len(order) else ANALYSIS_BASE + len(blob)
        targets = direct_targets(blob, a, min(end, ANALYSIS_BASE + len(blob)), starts)
        named = {x for x in set(IDENT.findall(body)) if x in addr and x != m.group(1)}
        free = {name[t] for t in targets} - named
        swaps = {}
        for n in sorted(named):
            if addr[n] in targets:
                continue
            cands = [t for t in free if same_family(n, t)]
            if len(cands) == 1:
                if compiles_as(body, n, cands[0], protos):
                    swaps[n] = cands[0]
                else:
                    skipped.append((m.group(1), n, cands[0]))
        # two names must not claim the same target
        if len(set(swaps.values())) != len(swaps):
            swaps = {}
        if swaps:
            body = re.sub(r"\b(" + "|".join(map(re.escape, swaps)) + r")\b",
                          lambda k: swaps[k.group(1)], body)
            changes += [(m.group(1), o, n) for o, n in sorted(swaps.items())]
        parts += [text[pos:m.end()], body]
        pos = stop
    parts.append(text[pos:])
    return "".join(parts), changes, skipped


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    ap.add_argument("-v", "--verbose", action="store_true")
    args = ap.parse_args()
    pending = 0
    for short, long in IMAGES.items():
        path = REPO / "src" / short / "main.c"
        blob = (REPO / "inputs" / "firmware" / f"{long}.bin").read_bytes()
        out, changes, skipped = rebind(path.read_text(errors="replace"), blob)
        pending += len(changes)
        print(f"[callsite_targets] {short}: {len(changes)} call-site names in "
              f"{len({c for c, _, _ in changes})} functions "
              f"{'pending' if args.check else 'rebound'}; {len(skipped)} left "
              f"(prototype of the binary's callee does not fit the call)")
        if args.verbose:
            for c, o, n in changes:
                print(f"    {c}: {o} -> {n}")
            for c, o, n in skipped:
                print(f"    {c}: {o} -> {n} (left)")
        if changes and not args.check:
            path.write_text(out)
    return 1 if args.check and pending else 0


if __name__ == "__main__":
    sys.exit(main())
