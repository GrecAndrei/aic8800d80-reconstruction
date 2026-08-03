#!/usr/bin/env python3
"""Name every remaining anonymous function in the v26 naming dataset.

The v26 dataset ("artifacts/releases/aic8800d80-rebuild-v26-unified/names/")
carries one JSON record per function. Records where BOTH ``fn`` and ``name``
are ``sub_<addr>`` placeholders are genuinely unnamed (the LLM returned
nothing / no_content during the original pass). Separately, the emulator's
function table (harness_v25/out/*_bin_funcs.jsonl) contains a handful of
functions the dataset has no record for at all.

This tool merges both sets into one target list and runs the v17 batched
naming pipeline (20 functions per LLM call, same prompt shape as
naming_batch.py) over them, writing each result straight into the v26 names
dir so the emulator picks the names up on the next run.

Output records follow the dataset convention: the ``name`` field carries the
LLM label (the emulator's ``_load_v26_names`` reads ``name`` with ``fn`` as
fallback). ``fn`` is set to the same label; the file may keep the
``sub_<addr>`` filename exactly like the bulk of the fmacfw_h records already
do — the emulator only globs ``*__{img}.json`` and reads the content.
"""
import argparse
import json
import re
import sys
import time
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "harness_v17"))

import tools as v17tools  # noqa: E402
from oracle import call_api  # noqa: E402

# Default output: the v26 release names dir the emulator reads (NAMES_GLOB).
DEFAULT_OUT = REPO / "artifacts/releases/aic8800d80-rebuild-v26-unified/names"

_PLACEHOLDER_RE = re.compile(
    r"^(sub_|loc_|unk_|off_|j_|log_sub_)", re.IGNORECASE
)


def is_placeholder(name: str) -> bool:
    n = (name or "").strip()
    return bool(_PLACEHOLDER_RE.match(n)) or n == ""


def _bin_size(image: str) -> int:
    name = image[:-4] if image.endswith("_bin") else image
    p = REPO / f"inputs/firmware/{name}.bin"
    return p.stat().st_size if p.exists() else 0


def _disasm_at(image: str, a: int, n: int = 8):
    """Disasm from the precomputed linear-sweep cache (r2 fallback on miss)."""
    got = v17tools.disasm_at(image, f"0x{a:x}", n)
    if got:
        return got
    # Data pool before the function start shifts a fresh r2 linear decode by
    # 2 bytes; use the proven r2 invocation for function starts (AGENTS.md).
    img = image[:-4] if image.endswith("_bin") else image
    import subprocess

    cmd = ["r2", "-q", "-2", "-a", "arm", "-b", "16", "-m", "0x100000",
           "-c", f"s 0x{a:x}; pd {n}", str(REPO / f"inputs/firmware/{img}.bin")]
    try:
        r = subprocess.run(cmd, capture_output=True, text=True, timeout=15)
    except Exception:
        return []
    out = re.sub(r"\x1b\[[0-9;]*m", "", r.stdout).strip()
    return [l.strip() for l in out.split("\n") if l.strip().startswith("0x")]


def build_batch(targets):
    """Build a prompt for one batch. Returns (valid_indices, prompt_text)."""
    valid = []
    lines = []
    for i, t in enumerate(targets):
        a = t["addr"]
        img = t["img"]
        size = _bin_size(img)
        if a < 0x100000 or a - 0x100000 >= size:
            continue
        disasm = _disasm_at(img, a, 8)
        if not disasm or all("invalid" in l.lower() for l in disasm):
            continue
        text = []
        for l in disasm[:8]:
            parts = l.split()
            text.append(" ".join(parts[2:]) if len(parts) >= 3 else l)
        valid.append((i, t))
        lines.append(f"[{i}] name=sub_{a:X} addr=0x{a:x}\n  disasm: {' ; '.join(text)}")
    return valid, "\n\n".join(lines)


def process_batch(targets):
    """Batch-name up to batch_size targets in one LLM call."""
    valid, batch_prompt = build_batch(targets)
    if not valid:
        return ["no_disasm"] * len(targets)
    system = """You name anonymous ARM Cortex-M firmware functions. For each function in the batch, output JSON with:
- "i": index (0-based, matching the input)
- "name": snake_case_name (best guess based on disasm)
- "doc": 1-line description
- "sub": rf|mac|tx|rx|ke|scan|bt|patch|ipc|mmio|util|unknown

CRITICAL: Return EXACTLY one entry per function in the input.

Output ONLY a JSON array (no prose). Be terse. Prefer descriptive names like
wifi_tx_handle, never sub_ placeholders."""
    user = (f"Name these {len(valid)} functions. You MUST return exactly "
            f"{len(valid)} JSON entries.\n\n{batch_prompt}\n\n"
            f"Output a JSON array with {len(valid)} entries. Each entry: "
            '{"i": <index>, "name": "...", "doc": "...", "sub": "..."}')
    messages = [
        {"role": "system", "content": system},
        {"role": "user", "content": user},
    ]
    try:
        msg, _tool_calls = call_api(messages, [], max_tool_rounds=0)
    except Exception as e:
        return [f"err:{e}"] * len(targets)
    content = (msg.get("content") or "").strip()
    if not content:
        return ["no_content"] * len(targets)
    start = content.find("[")
    if start < 0:
        return ["no_json"] * len(targets)
    depth, end = 0, -1
    for i in range(start, len(content)):
        if content[i] == "[":
            depth += 1
        elif content[i] == "]":
            depth -= 1
            if depth == 0:
                end = i + 1
                break
    if end < 0:
        return ["no_json"] * len(targets)
    try:
        results = json.loads(content[start:end])
    except Exception as e:
        return [f"json_err:{e}"] * len(targets)
    by_idx = {i: t for i, t in valid}
    statuses = ["filtered"] * len(targets)
    for r in results:
        if not isinstance(r, dict):
            continue
        try:
            i = int(r.get("i", -1))
        except Exception:
            continue
        t = by_idx.get(i)
        if t is None:
            continue
        proposed = (r.get("name") or "").strip()
        if is_placeholder(proposed):
            statuses[i] = "placeholder"
            continue
        ok = write_record(t, proposed, r.get("doc", ""), r.get("sub", "unknown"))
        statuses[i] = "ok" if ok else "write_err"
    return statuses


def write_record(t, proposed, doc, sub):
    """Write one named record into the dataset (in place if a record exists)."""
    a = t["addr"]
    img = t["img"]
    out_dir = t["out_dir"]
    record = {
        "fn": proposed,
        "img": img,
        "addr": f"0x{a:x}",
        "status": "ok",
        "name": proposed,
        "params": [],
        "docstring": doc or "",
        "subsystem": sub or "unknown",
        "tool_call_count": 0,
        "tool_calls": [],
    }
    # Existing record for this address -> update in place.
    for p in out_dir.glob(f"*__{img}.json"):
        try:
            j = json.loads(p.read_text())
        except Exception:
            continue
        if j.get("addr") and int(j.get("addr"), 16) == a:
            p.write_text(json.dumps(record))
            return True
    # No record yet -> create one (collision-free sub_<addr> filename).
    p = out_dir / f"sub_{a:X}__{img}.json"
    if p.exists():
        # Another record already owns this path but not the address: keep it.
        try:
            j = json.loads(p.read_text())
        except Exception:
            j = None
        if j is None or int(j.get("addr", "0x0"), 16) == a:
            p.write_text(json.dumps(record))
            return True
        p = out_dir / f"sub_{a:X}_{int(time.time())}__{img}.json"
    p.write_text(json.dumps(record))
    return True


def chunked(lst, n):
    for i in range(0, len(lst), n):
        yield lst[i:i + n]


def load_targets(path: Path, out_dir: Path):
    raw = json.loads(path.read_text())
    targets = []
    for d in raw:
        img = d.get("img")
        addr = d.get("addr")
        if not img or not addr:
            continue
        try:
            a = int(addr, 16) if isinstance(addr, str) else int(addr)
        except (ValueError, TypeError):
            continue
        targets.append({"img": img, "addr": a, "out_dir": out_dir})
    # Drop targets that already carry a meaningful name in the dataset.
    seen = {}  # (img, addr) -> record
    for p in out_dir.glob("*.json"):
        try:
            j = json.loads(p.read_text())
        except Exception:
            continue
        addr = j.get("addr")
        if addr:
            try:
                seen[(j.get("img"), int(addr, 16))] = j
            except (ValueError, TypeError):
                pass
    fresh = []
    for t in targets:
        j = seen.get((t["img"], t["addr"]))
        if j is not None and not is_placeholder(j.get("name")):
            continue
        fresh.append(t)
    return fresh


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--targets", required=True,
                    help="JSON list of {img, addr} to name")
    ap.add_argument("--out-dir", default=str(DEFAULT_OUT))
    ap.add_argument("--batch-size", type=int, default=20)
    ap.add_argument("--workers", type=int, default=12)
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--log", help="append progress to this file")
    args = ap.parse_args()

    out_dir = Path(args.out_dir)
    out_dir.mkdir(parents=True, exist_ok=True)
    targets = load_targets(Path(args.targets), out_dir)
    if args.limit:
        targets = targets[:args.limit]
    print(f"Processing {len(targets)} unnamed targets (batch={args.batch_size}, "
          f"workers={args.workers})", file=sys.stderr, flush=True)

    def note(line):
        print(line, file=sys.stderr, flush=True)
        if args.log:
            with open(args.log, "a") as f:
                f.write(line + "\n")

    batches = list(chunked(targets, args.batch_size))
    t0 = time.time()
    done = 0
    status_counts = {}
    ok = 0
    with ThreadPoolExecutor(max_workers=args.workers) as ex:
        futures = {ex.submit(process_batch, b): b for b in batches}
        for f in as_completed(futures):
            for r in f.result():
                done += 1
                status_counts[r] = status_counts.get(r, 0) + 1
                if r == "ok":
                    ok += 1
            if done % 100 == 0 or done == len(targets):
                rate = done / (time.time() - t0)
                eta = (len(targets) - done) / rate if rate > 0 else 0
                note(f"  {done}/{len(targets)} ok={ok} rate={rate:.1f}/s "
                     f"eta={eta:.0f}s statuses="
                     f"{dict(sorted(status_counts.items(), key=lambda x: -x[1])[:6])}")
    note(f"DONE: {len(targets)} targets in {time.time()-t0:.1f}s "
         f"ok={ok} statuses={status_counts}")
    if args.log:
        manifest = Path(args.log).with_suffix(".manifest.json")
        rows = []
        for p in sorted(out_dir.glob("*.json")):
            try:
                j = json.loads(p.read_text())
            except Exception:
                continue
            if not is_placeholder(j.get("name")) and j.get("status") == "ok":
                rows.append({"file": p.name, "img": j.get("img"),
                             "addr": j.get("addr"), "name": j.get("name"),
                             "subsystem": j.get("subsystem")})
        manifest.write_text(json.dumps(rows, indent=1))
        note(f"manifest written: {manifest} ({len(rows)} records)")


if __name__ == "__main__":
    main()
