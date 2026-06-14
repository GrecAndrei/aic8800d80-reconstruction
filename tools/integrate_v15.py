#!/usr/bin/env python3
"""O(n) integration using list-join."""
import re, json, sys, time
from pathlib import Path
from collections import defaultdict

REPO = Path(__file__).resolve().parent.parent
V15_SYNTH = REPO / "artifacts/releases/aic8800d80-rebuild-v1/synth"
COMPOSED_DIR = REPO / "extraction_out/reconstruction/mega7/final"
OUT_DIR = REPO / "artifacts/releases/aic8800d80-rebuild-v1/composed"
OUT_DIR.mkdir(parents=True, exist_ok=True)

BINARIES = [
    "fmacfw_8800d80_h_u02_bin",
    "fmacfw_8800d80_u02_bin",
    "fmacfwbt_8800d80_u02_bin",
    "lmacfw_rf_8800d80_u02_bin",
]


def extract_behavioral_body(behavioral_text: str) -> str | None:
    m = re.search(r'\b(?:void|int|unsigned\s+int|uint\d+_t|char|long|short|bool)\s+\w+\s*\([^)]*\)\s*\{', behavioral_text)
    if not m:
        return None
    start = m.end() - 1
    depth = 0
    i = start
    while i < len(behavioral_text):
        ch = behavioral_text[i]
        if ch == '{':
            depth += 1
        elif ch == '}':
            depth -= 1
            if depth == 0:
                return behavioral_text[start + 1:i]
        i += 1
    return None


def load_behavioral_index() -> dict[str, dict[str, str]]:
    index = defaultdict(dict)
    t0 = time.time()
    for f in V15_SYNTH.glob("behavioral_*.synth.c"):
        text = f.read_text(errors='replace')
        name_part = f.stem
        if name_part.endswith(".synth"):
            name_part = name_part[:-len(".synth")]
        if not name_part.startswith("behavioral_"):
            continue
        rest = name_part[len("behavioral_"):]
        if "__" not in rest:
            continue
        fn, img = rest.split("__", 1)
        body = extract_behavioral_body(text)
        if body is not None:
            index[img][fn] = body
    print(f"[index] {sum(len(v) for v in index.values())} bodies in {time.time()-t0:.1f}s", file=sys.stderr)
    return index


def find_function_blocks(text: str) -> list[tuple[int, int, str, str, int]]:
    """Find (start, end, name, body, open_brace_pos) for each function in text."""
    pattern = re.compile(
        r'\b(void|int|unsigned\s+int|uint8_t|uint16_t|uint32_t|uint64_t|'
        r'size_t|char|long|short|signed|bool|float|double)\b\s+'
        r'(\w+)\s*\([^)]*\)\s*\{',
        re.MULTILINE
    )
    blocks = []
    for m in pattern.finditer(text):
        name = m.group(2)
        start = m.start()
        open_brace_pos = m.end() - 1
        depth = 0
        i = open_brace_pos
        while i < len(text):
            ch = text[i]
            if ch == '{':
                depth += 1
            elif ch == '}':
                depth -= 1
                if depth == 0:
                    end = i + 1
                    body = text[open_brace_pos + 1:i]
                    blocks.append((start, end, name, body, open_brace_pos))
                    break
            i += 1
    return blocks


def integrate(image: str, behavioral_index) -> dict:
    src = COMPOSED_DIR / f"{image}.reconstructed.c"
    text = src.read_text(errors='replace')
    print(f"[{image}] {len(text):,} bytes loaded", file=sys.stderr)

    available = behavioral_index.get(image, {})
    t0 = time.time()
    blocks = find_function_blocks(text)
    print(f"[{image}] {len(blocks)} function blocks ({time.time()-t0:.1f}s)", file=sys.stderr)

    # Build O(n) replacement list: (start, end, new_block_text)
    # Sort by start ASCENDING so we can build the new text in one pass
    repls = []
    todo_total = 0
    no_match = []
    for start, end, name, body, open_brace_pos in blocks:
        if 'TODO' in body:
            todo_total += 1
            if name in available:
                behavioral_body = available.get(name, "").strip()
                new_body = "  /* v15 behavioral: replaced TODO stub */\n  " + behavioral_body + "\n"
                # text[start:end] = sig + "{" + body + "}"
                # We want: sig + "{" + new_body + "}"
                # sig = text[start:open_brace_pos] (everything BEFORE the original '{')
                sig = text[start:open_brace_pos]
                new_block = sig + "{" + new_body + "}"  # add our own '{' and '}'
                repls.append((start, end, new_block))
            else:
                no_match.append(name)

    repls.sort(key=lambda x: x[0])  # ascending

    # O(n) splice
    t0 = time.time()
    pieces = []
    last = 0
    for start, end, replacement in repls:
        if start > last:
            pieces.append(text[last:start])
        pieces.append(replacement)
        last = end
    if last < len(text):
        pieces.append(text[last:])
    new_text = ''.join(pieces)
    print(f"[{image}] spliced in {time.time()-t0:.1f}s", file=sys.stderr)

    out_path = OUT_DIR / f"{image}.reconstructed.c"
    out_path.write_text(new_text)
    print(f"[{image}] Wrote {len(new_text):,} bytes -> {out_path.name}", file=sys.stderr)

    return {
        "image": image,
        "total_blocks": len(blocks),
        "replaced": len(repls),
        "todo_total": todo_total,
        "todo_kept": len(no_match),
        "no_match_count": len(no_match),
        "no_match_sample": no_match[:30],
    }


def main() -> int:
    t0 = time.time()
    print("Indexing behavioral files...", file=sys.stderr)
    index = load_behavioral_index()

    report = {}
    for image in BINARIES:
        t_img = time.time()
        r = integrate(image, index)
        report[image] = r
        print(f"[{image}] {r['replaced']}/{r['total_blocks']} replaced, {r['todo_kept']}/{r['todo_total']} TODOs kept, took {time.time()-t_img:.1f}s", file=sys.stderr)

    out_report = OUT_DIR / "_integration_report.json"
    out_report.write_text(json.dumps(report, indent=2))
    print(f"\nReport: {out_report}", file=sys.stderr)

    total_replaced = sum(r['replaced'] for r in report.values())
    total_todos = sum(r['todo_total'] for r in report.values())
    total_kept = sum(r['todo_kept'] for r in report.values())
    print(f"\nTOTAL: {total_replaced} stubs replaced, {total_kept}/{total_todos} TODOs still remaining", file=sys.stderr)
    print(f"Total time: {time.time()-t0:.1f}s", file=sys.stderr)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
