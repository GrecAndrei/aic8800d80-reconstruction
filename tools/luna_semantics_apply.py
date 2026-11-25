#!/usr/bin/env python3
"""Apply luna docstrings and variable renames — the readability payload of
the analysis batch, as a deterministic post-compose rule.

Two applications, both confidence-gated and collision-guarded:

1. docstrings — a `/* ... */` comment above the function definition body,
   one line, sanitized (no comment-close sequences). Zero risk: additive
   comment text only. Applied for medium confidence and up.

2. var_renames — vN variables renamed inside the owning function body ONLY
   when safe: the replacement is a valid C identifier, does not appear
   anywhere else in the function text (no capture), is not a keyword, and
   the original vN token is actually declared/used. High confidence only:
   medium-confidence semantic guesses about individual registers are not
   trustworthy enough to rewrite code. Word-boundary replacement, applied
   per-function in isolation.

Both are idempotent: docstring insertion is keyed on the comment marker and
vN renames are no-ops once the vN token is gone. Re-running on re-composed
(virgin) slices reproduces the same result — fixed-point safe.

Usage: python3 tools/luna_semantics_apply.py [--check]
"""
import json
import glob
import re
import sys

IMAGES = ("fmacfw_h_u02", "fmacfw_u02", "fmacfwbt_u02", "lmacfw_rf_u02")

C_KEYWORDS = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if", "int",
    "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile",
    "while", "result",
}

IDENT = re.compile(r"^[a-z][a-z0-9_]{2,38}$")


def load_batch():
    out = {}
    for f in glob.glob("metadata/luna_analysis/*.json"):
        try:
            o = json.load(open(f))
            d = json.loads(o["text"])
            out[(o["img"], o["fn"])] = d
        except Exception:
            continue
    return out


def sanitize_doc(s):
    s = re.sub(r"\s+", " ", s).strip()
    s = s.replace("/*", "").replace("*/", "").replace("//", "")
    return s[:150]


def process_function_body(text, d):
    """Apply var renames within one function unit text. Returns (new_text, n)."""
    renames = d.get("var_renames") or {}
    if not renames or d.get("confidence") != "high":
        return text, 0
    n = 0
    for old, new in sorted(renames.items()):
        if not re.fullmatch(r"v\d{1,2}", old or ""):
            continue
        if not IDENT.match(new or "") or new in C_KEYWORDS:
            continue
        if not re.search(rf"\b{old}\b", text):
            continue
        # collision guard: the new identifier must not already exist in the body
        if re.search(rf"\b{re.escape(new)}\b", text):
            continue
        text = re.sub(rf"\b{old}\b", new, text)
        n += 1
    return text, n


def apply_image(img, batch, check=False):
    files = sorted(glob.glob(f"src/{img}/modules/mod*.c"))
    if not files:
        return 0, 0
    ndocs = 0
    nvars = 0
    changed = {}
    for path in files:
        text = open(path).read()
        units = list(re.finditer(r"(?m)^// (\S+) @ 0x([0-9a-f]+)\n", text))
        if not units:
            continue
        out = []
        pos = 0
        dirty = False
        for i, m in enumerate(units):
            end = units[i + 1].start() if i + 1 < len(units) else len(text)
            out.append(text[pos:m.start()])
            body = text[m.start():end]
            name = m.group(1)
            d = batch.get((img, name))
            if d:
                # var renames first (they operate on the whole unit)
                body, nv = process_function_body(body, d)
                nvars += nv
                if nv:
                    dirty = True
                # docstring insertion after the marker comment line
                doc = sanitize_doc(d.get("docstring", ""))
                # high-confidence only: measured 2026-11-25 — medium-confidence
                # docstrings frequently describe semantics contradicting the
                # function they annotate (rx_packet_pending documented as
                # "reinitializes the RWNX core"); misleading documentation is
                # worse than none
                if doc and d.get("confidence") == "high" and "/*" not in body.split("\n", 2)[1][:2]:
                    first_nl = body.find("\n")
                    if first_nl > 0 and "luna:" not in body[:first_nl + 160]:
                        insert = f"/* luna: {doc} */\n"
                        body = body[:first_nl + 1] + insert + body[first_nl + 1:]
                        ndocs += 1
                        dirty = True
            out.append(body)
            pos = end
        out.append(text[pos:])
        if dirty:
            changed[path] = "".join(out)
    if not check:
        for path, t in changed.items():
            open(path, "w").write(t)
    return ndocs, nvars


def main():
    check = "--check" in sys.argv
    batch = load_batch()
    print(f"{len(batch)} luna analyses loaded")
    total_docs = total_vars = 0
    for img in IMAGES:
        nd, nv = apply_image(img, batch, check=check)
        total_docs += nd
        total_vars += nv
        print(f"{img}: {nd} docstrings, {nv} variable renames")
    if check:
        sys.exit(1 if (total_docs or total_vars) else 0)
    print(f"applied {total_docs} docstrings, {total_vars} variable renames")


if __name__ == "__main__":
    main()
