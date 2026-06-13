#!/usr/bin/env python3
"""v17 batched naming: process 20 functions per LLM call.

LLM gets a list of (name, addr, disasm-snippet, behavioral-snippet) tuples
and returns a JSON array of {name, params, docstring, subsystem} objects.

The LLM is told: "use tools ONLY if needed for the trickiest cases; for the
rest, just give your best guess based on the disasm snippet."
"""
import json, sys, time, argparse, re, threading
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor, as_completed

REPO = Path("/home/grec-alexander/Downloads/aic8800d80")
sys.path.insert(0, str(REPO / "harness_v17"))
import tools as v17tools
from oracle import call_api, call_tool, TOOL_SCHEMA, validate_no_invented_addresses
from naming import load_targets, _bin_size

OUT = REPO / "harness_v17/names"
OUT.mkdir(parents=True, exist_ok=True)


def addr_to_chip(a):
    """Convert v14 address to chip runtime if needed."""
    a = int(a, 16) if isinstance(a, str) else a
    if a >= 0x200000:
        a = a - 0x1100000
    return a


def build_batch(targets):
    """Build a prompt for a batch of functions.
    Returns (filtered_targets, prompt_text).
    """
    valid = []
    lines = []
    for i, t in enumerate(targets):
        fn, img, addr = t['fn'], t['img'], t['addr']
        try:
            a = int(addr, 16) if addr else 0
            a = addr_to_chip(a)
            size = _bin_size(img)
            if a < 0x100000 or a - 0x100000 >= size:
                continue
        except Exception:
            continue
        img_arg = img if img.endswith("_bin") else img + "_bin"
        disasm = v17tools.disasm_at(img_arg, f"0x{a:x}", 8)
        if not disasm or all('invalid' in l.lower() for l in disasm):
            continue
        # Strip ANSI from disasm, take only the meaningful part
        def disasm_line(l):
            parts = l.split()
            if len(parts) >= 3:
                return ' '.join(parts[2:])
            return l
        disasm_str = " ; ".join(disasm_line(l) for l in disasm[:8])
        behav = t.get('behav_text')
        behav_str = behav[:200] if behav else "(none)"
        valid.append((i, t))
        lines.append(f"[{i}] name={fn} addr=0x{a:x}\n  disasm: {disasm_str}\n  behav: {behav_str}")
    return valid, "\n\n".join(lines)


def process_batch(targets):
    """Process a batch of 20 functions in one LLM call."""
    valid, batch_prompt = build_batch(targets)
    if not valid:
        return ["no_target"] * len(targets)
    system = """You name anonymous firmware functions. For each function in the batch, output JSON with:
- "i": index (0-based, matching the input)
- "name": snake_case_name (best guess based on disasm)
- "doc": 1-line description
- "sub": rf|mac|tx|rx|ke|scan|bt|patch|ipc|mmio|util|unknown

CRITICAL: Return EXACTLY one entry per function in the input.

Output ONLY a JSON array (no prose). Be terse."""
    user = f"""Name these {len(valid)} functions. You MUST return exactly {len(valid)} JSON entries.

{batch_prompt}

Output a JSON array with {len(valid)} entries. Each entry: {{"i": <index>, "name": "...", "doc": "...", "sub": "..."}}"""
    messages = [
        {"role": "system", "content": system},
        {"role": "user", "content": user},
    ]
    try:
        msg, tool_calls = call_api(messages, [], max_tokens=4000, max_tool_rounds=0)
    except Exception as e:
        return [f"err:{e}"] * len(targets)
    content = (msg.get('content') or '').strip()
    if not content:
        return ["no_content"] * len(targets)
    # Parse JSON array
    start = content.find('[')
    if start < 0:
        return ["no_json"] * len(targets)
    depth, end = 0, -1
    for i in range(start, len(content)):
        if content[i] == '[': depth += 1
        elif content[i] == ']':
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
    # Map results back to targets by index
    out_statuses = ["filtered"] * len(targets)  # default: target was filtered out
    valid_indices = {idx for idx, _ in valid}
    for r in results:
        if not isinstance(r, dict): continue
        try:
            i = int(r.get('i', -1))
        except Exception:
            continue
        if i not in valid_indices: continue
        # Find the target with index i
        t = next((tt for ii, tt in valid if ii == i), None)
        if t is None: continue
        fn, img, addr = t['fn'], t['img'], t['addr']
        out_path = OUT / f"{fn}__{img}.json"
        if out_path.exists():
            out_statuses[i] = "skip"
            continue
        out = {
            'fn': fn, 'img': img, 'addr': addr, 'status': 'ok',
            'name': r.get('name'),
            'params': [],
            'docstring': r.get('doc', ''),
            'subsystem': r.get('sub', 'unknown'),
            'tool_call_count': 0,
            'tool_calls': [],
        }
        out_path.write_text(json.dumps(out))
        out_statuses[i] = "ok"
    return out_statuses


def chunked(lst, n):
    for i in range(0, len(lst), n):
        yield lst[i:i+n]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--batch-size', type=int, default=20)
    ap.add_argument('--workers', type=int, default=12)
    ap.add_argument('--limit', type=int, default=0)
    args = ap.parse_args()
    targets = load_targets()
    # Filter out targets that already have names
    targets = [t for t in targets if not (OUT / f"{t['fn']}__{t['img']}.json").exists()]
    if args.limit:
        targets = targets[:args.limit]
    print(f"Processing {len(targets)} targets in batches of {args.batch_size} with {args.workers} workers", file=sys.stderr, flush=True)
    batches = list(chunked(targets, args.batch_size))
    t0 = time.time()
    done = ok = fail = nodis = 0
    statuses = {}
    with ThreadPoolExecutor(max_workers=args.workers) as ex:
        futures = {ex.submit(process_batch, b): b for b in batches}
        for f in as_completed(futures):
            results = f.result()
            for r in results:
                done += 1
                statuses[r] = statuses.get(r, 0) + 1
                if r == "ok": ok += 1
            if done % 200 == 0:
                rate = done / (time.time() - t0)
                eta = (len(targets) - done) / rate if rate > 0 else 0
                print(f"  {done}/{len(targets)} ok={ok} rate={rate:.1f}/s eta={eta:.0f}s", file=sys.stderr, flush=True)
                print(f"    statuses: {dict(sorted(statuses.items(), key=lambda x: -x[1])[:6])}", file=sys.stderr, flush=True)
    print(f"\nDONE: {done} in {time.time()-t0:.1f}s ok={ok}", file=sys.stderr)


if __name__ == "__main__":
    main()
