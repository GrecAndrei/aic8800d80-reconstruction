#!/usr/bin/env python3
"""Logical composed-source loader.

After ``demonolithize.py``, ``src/<image>/main.c`` is an umbrella whose
function bodies live in ``modules/modNNN*.c``. Most analysis tools were
written against the logical single translation unit produced by compose.
This helper reconstructs that text in include order; for a not-yet-split
main.c it is the identity transformation.
"""
from __future__ import annotations

import re
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
MODULE_INCLUDE_RE = re.compile(r'#include "(modules/mod[^"]+\.c)"\s*$')


def load_composed_text(short_image: str) -> str:
    """Return the logical monolithic text for ``src/<short_image>/main.c``.

    Module includes are expanded exactly in umbrella order. Missing module
    files are an error: silently leaving the include line would make function
    inventory depend on whether a consumer happened to notice the absence.
    """
    base = REPO / "src" / short_image
    umbrella_path = base / "main.c"
    umbrella = umbrella_path.read_text(errors="replace")
    parts: list[str] = []
    for line in umbrella.splitlines(keepends=True):
        inc = MODULE_INCLUDE_RE.match(line)
        if inc:
            module_path = base / inc.group(1)
            parts.append(module_path.read_text(errors="replace"))
        else:
            parts.append(line)
    return "".join(parts)
