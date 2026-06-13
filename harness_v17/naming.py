#!/usr/bin/env python3
"""v17 naming oracle driver.

Process all 11,464 behavioral functions in parallel using tool-use LLM.
Output: harness_v17/names/{fn}__{img}.json with name, params, docstring, subsystem.
"""
import json, sys, time, argparse, threading, re
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor, as_completed

REPO = Path("/home/grec-alexander/Downloads/aic8800d80")
sys.path.insert(0, str(REPO / "harness_v17"))
import tools as v17tools
from oracle import name_function, call_tool, TOOL_SCHEMA

OUT = REPO / "harness_v17/names"
OUT.mkdir(parents=True, exist_ok=True)
BEHAV_DIR = REPO / "extraction_out/reconstruction/mega7/synth"
ALL_FNS = REPO / "harness_v16/all_fns.json"


def load_targets():
    """Get all functions: behavioral first, then the rest from all_fns.json."""
    targets = []
    seen = set()
    # Behavioral files (highest priority — these are functions with actual traces)
    for f in BEHAV_DIR.glob("behavioral_*.synth.c"):
        m = re.match(r"behavioral_(.+?)__(.+?)\.synth\.c", f.name)
        if m:
            fn, img = m.group(1), m.group(2)
            key = (fn, img)
            if key in seen: continue
            seen.add(key)
            # Read header for address
            text = f.read_text(errors='ignore')
            am = re.search(r'addr=0x([0-9a-fA-F]+)', text)
            addr = f"0x{int(am.group(1), 16):x}" if am else None
            targets.append({'fn': fn, 'img': img, 'addr': addr, 'has_behav': True, 'behav_text': text[:2000]})
    # All other functions (from all_fns.json which has function + locations[])
    if ALL_FNS.exists():
        for d in json.load(open(ALL_FNS)):
            name = d.get('function', '')
            for loc in d.get('locations', []):
                img = loc.get('image', '')
                addr = loc.get('address', '')
                key = (name, img)
                if key in seen or not name or not img: continue
                seen.add(key)
                targets.append({'fn': name, 'img': img, 'addr': addr, 'has_behav': False, 'behav_text': None})
    return targets


_BIN_SIZES = {}

def _bin_size(image):
    """Get binary size in bytes (chip runtime = 0x100000 + file_size)."""
    if image in _BIN_SIZES:
        return _BIN_SIZES[image]
    name = image
    if name.endswith("_bin"):
        name = name[:-4]
    p = REPO / f"inputs/firmware/{name}.bin"
    if not p.exists():
        _BIN_SIZES[image] = 0
        return 0
    s = p.stat().st_size
    _BIN_SIZES[image] = s
    return s


def process_one(target):
    fn, img, addr = target['fn'], target['img'], target['addr']
    out_path = OUT / f"{fn}__{img}.json"
    if out_path.exists():
        return "skip"
    if not addr or addr == "0x0":
        return "no_addr"
    try:
        a = int(addr, 16) if isinstance(addr, str) else addr
        # v14 addresses (>= 0x200000) need conversion: chip = v14 - 0x1100000
        if a >= 0x200000:
            a = a - 0x1100000
        if a < 0x100000 or a > 0x20000000:
            return "bad_addr"
        # Validate address is in binary's valid range
        size = _bin_size(img)
        if size == 0 or a - 0x100000 >= size:
            return "addr_oob"
        # Update addr to chip runtime
        addr = f"0x{a:x}"
    except Exception:
        return "bad_addr"
    # Get disasm
    img_arg = img if img.endswith("_bin") else img + "_bin"
    disasm_lines = v17tools.disasm_at(img_arg, addr, 20)
    if not disasm_lines:
        return "no_disasm"
    # Skip if all instructions are "invalid" (data/string region)
    if all('invalid' in l.lower() or l.count('0x') == 1 for l in disasm_lines):
        return "data_region"
    # Get behavioral
    behav = target.get('behav_text')
    # Call oracle
    try:
        result, tool_calls, status = name_function(fn, img_arg, addr, disasm_lines, behav, max_tool_rounds=4)
    except Exception as e:
        return f"err:{e}"
    if not result:
        out_path.write_text(json.dumps({
            'fn': fn, 'img': img, 'addr': addr, 'status': status,
            'tool_call_count': len(tool_calls),
            'tool_calls': [{'name': tc['name'], 'args': tc['args']} for tc in tool_calls],
        }))
        return f"fail:{status}"
    out = {
        'fn': fn, 'img': img, 'addr': addr, 'status': 'ok',
        'name': result.get('name'),
        'params': result.get('params', []),
        'docstring': result.get('docstring', ''),
        'subsystem': result.get('subsystem', 'unknown'),
        'tool_call_count': len(tool_calls),
        'tool_calls': [{'name': tc['name'], 'args': tc['args']} for tc in tool_calls],
    }
    out_path.write_text(json.dumps(out))
    return "ok"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--limit', type=int, default=0)
    ap.add_argument('--workers', type=int, default=24)
    ap.add_argument('--only-behavioral', action='store_true', help='Only process behavioral functions')
    args = ap.parse_args()

    targets = load_targets()
    if args.only_behavioral:
        targets = [t for t in targets if t['has_behav']]
    if args.limit:
        targets = targets[:args.limit]
    print(f"Processing {len(targets)} targets with {args.workers} workers", file=sys.stderr, flush=True)

    t0 = time.time()
    done = skip = ok = fail = no_disasm = bad_addr = 0
    with ThreadPoolExecutor(max_workers=args.workers) as ex:
        futures = {ex.submit(process_one, t): t for t in targets}
        for f in as_completed(futures):
            r = f.result()
            done += 1
            if r == "skip": skip += 1
            elif r == "ok": ok += 1
            elif r == "no_disasm": no_disasm += 1
            elif r == "bad_addr": bad_addr += 1
            elif r.startswith("fail:") or r.startswith("err:"): fail += 1
            if done % 25 == 0:
                rate = done / (time.time() - t0)
                eta = (len(targets) - done) / rate if rate > 0 else 0
                print(f"  {done}/{len(targets)} ok={ok} skip={skip} fail={fail} nodis={no_disasm} bad={bad_addr} rate={rate:.1f}/s eta={eta:.0f}s", file=sys.stderr, flush=True)
    print(f"\nDONE: {done} in {time.time()-t0:.1f}s (ok={ok} skip={skip} fail={fail} nodis={no_disasm} bad={bad_addr})", file=sys.stderr)


if __name__ == "__main__":
    main()
