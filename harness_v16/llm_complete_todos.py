#!/usr/bin/env python3
"""Parallel LLM completion of TODO stubs.

For each TODO function:
1. Get the disassembly from r2
2. Get any similar functions in the dataset (for context)
3. Prompt LLM to write a C body
4. Save LLM output
5. Verify with strong verifier

Run with: python3 llm_complete_todos.py [--limit N] [--workers N]
"""
import json, subprocess, sys, time, argparse, os, re
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor, as_completed
import urllib.request, urllib.error
import threading

REPO = Path(__file__).resolve().parent.parent
TARGETS = REPO / "harness_v16/todo_targets.json"
OUT_DIR = REPO / "harness_v16/out/llm_todos"
OUT_DIR.mkdir(parents=True, exist_ok=True)
KEYS = json.load(open(REPO / "harness_v15/keys/keys.json"))['providers']

ANSI = re.compile(r'\x1b\[[0-9;]*m')
def strip_ansi(s): return ANSI.sub('', s)

# Per-thread round-robin key
_local = threading.local()
def get_key():
    if not hasattr(_local, 'i'):
        _local.i = 0
    k = KEYS[_local.i % len(KEYS)]
    _local.i += 1
    return k

def get_disasm(image, v14_addr):
    """Get ARM Thumb disasm at the given v14 address."""
    bin_name = image.replace('_bin', '')
    bin_path = REPO / f"inputs/firmware/{bin_name}.bin"
    if not bin_path.exists():
        return ""
    # Address could be chip runtime (0x1XXXXX) or file_offset (smaller)
    # If larger than file size, it's chip runtime - subtract 0x100000
    import os
    fsize = os.path.getsize(REPO / f"inputs/firmware/{bin_name}.bin")
    a = int(v14_addr, 16) if v14_addr.startswith("0x") else 0
    if a > fsize:
        # Chip runtime - r2 maps file at 0x100000, so pass directly
        chip_addr = hex(a)
    else:
        # File offset - r2 maps at 0x100000, so add base
        chip_addr = hex(a + 0x100000)
    cmd = ["r2", "-q", "-a", "arm", "-b", "16", "-m", "0x100000", "-2",
           "-c", f"s {chip_addr}; pd 40", str(bin_path)]
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=15)
        out = strip_ansi(result.stdout).strip()
        # Keep only disasm lines
        lines = [l.strip() for l in out.split('\n') if l.strip().startswith('0x')]
        return '\n'.join(lines)
    except Exception:
        return ""

def call_llm(system, user, max_tokens=2000, temperature=0.0):
    """Make LLM call with retry."""
    key = get_key()
    last_err = None
    for attempt in range(3):
        try:
            req = urllib.request.Request(
                "https://api.tokenrouter.com/v1/chat/completions",
                data=json.dumps({
                    "model": key['model'],
                    "messages": [
                        {"role": "system", "content": system},
                        {"role": "user", "content": user}
                    ],
                    "max_tokens": max_tokens,
                    "temperature": temperature
                }).encode(),
                headers={
                    "Authorization": f"Bearer {key['api_key']}",
                    "Content-Type": "application/json"
                }
            )
            r = urllib.request.urlopen(req, timeout=120)
            resp = json.loads(r.read())
            content = resp['choices'][0]['message']['content']
            return content, resp.get('usage', {})
        except Exception as e:
            last_err = e
            time.sleep(2 ** attempt)
    return None, {}

def process_one(target):
    """Process one TODO target: get disasm, prompt LLM, save result."""
    fn = target['function']
    img = target['image']
    addr = target['address']
    out_path = OUT_DIR / f"{fn}__{img}.json"
    if out_path.exists():
        return "skip"
    disasm = get_disasm(img, addr)
    if not disasm: return "no_disasm"
    # Filter out string data
    lines = [l for l in disasm.split(chr(10)) if l.strip().startswith("0x")]
    if not lines: return "no_disasm"
    # If most bytes are printable ASCII, it is string data not code
    first_line = lines[0]
    parts = first_line.split()
    if len(parts) >= 2:
        bytes_str = parts[1]
        try:
            bs = bytes.fromhex(bytes_str)
            ascii_count = sum(1 for b in bs if 32 <= b < 127)
            if ascii_count >= len(bs) * 0.7:
                return "string_data"
        except Exception:
            pass
        # Try with chip address directly
        return "no_disasm"
    # Check for string data BEFORE calling LLM (saves API cost)
    lines = [l for l in disasm.split(chr(10)) if l.strip().startswith("0x")]
    if not lines: return "no_disasm"
    first_line = lines[0]
    parts = first_line.split()
    if len(parts) >= 2:
        bytes_str = parts[1]
        try:
            bs = bytes.fromhex(bytes_str)
            ascii_count = sum(1 for b in bs if 32 <= b < 127)
            if ascii_count >= len(bs) * 0.7:
                return "string_data"
        except Exception:
            pass
    # Build prompt
    system = "You are an ARM Thumb-2 expert. Output ONLY valid C function body code. No prose, no explanation, no thinking - just the C code that implements the disassembly. Be terse."
    user = f"""Function: {fn}
Image: {img}
Address: {addr}

Disassembly:
{disasm}

Write a C function body that implements this disassembly. Use the function name `{fn}`. Body only, no signature."""
    response, usage = call_llm(system, user, max_tokens=3000)
    if response is None:
        return "llm_fail"
    # Strip any preamble/markdown
    response = response.strip()
    if response.startswith("```c"):
        response = re.sub(r'^```c\s*\n?', '', response)
        response = re.sub(r'\n?```\s*$', '', response)
    elif response.startswith("```"):
        response = re.sub(r'^```\s*\n?', '', response)
        response = re.sub(r'\n?```\s*$', '', response)
    out = {
        'function': fn,
        'image': img,
        'address': addr,
        'disasm': disasm,
        'llm_output': response,
        'usage': usage,
    }
    out_path.write_text(json.dumps(out))
    return "ok"

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--limit', type=int, default=0, help='Limit N targets (0=all)')
    ap.add_argument('--workers', type=int, default=24, help='Thread count')
    args = ap.parse_args()

    targets = json.load(open(TARGETS))
    if args.limit:
        targets = targets[:args.limit]
    print(f"Processing {len(targets)} targets with {args.workers} workers", file=sys.stderr)

    t0 = time.time()
    done = 0
    skip = 0
    fail = 0
    no_disasm = 0
    with ThreadPoolExecutor(max_workers=args.workers) as ex:
        futures = {ex.submit(process_one, t): t for t in targets}
        for f in as_completed(futures):
            r = f.result()
            done += 1
            if r == "skip": skip += 1
            elif r == "no_disasm": no_disasm += 1
            elif r == "llm_fail": fail += 1
            if done % 100 == 0:
                rate = done / (time.time() - t0)
                eta = (len(targets) - done) / rate if rate > 0 else 0
                print(f"  {done}/{len(targets)} ({skip} skip, {no_disasm} no_disasm, {fail} fail) {rate:.1f}/s eta={eta:.0f}s", file=sys.stderr)

    print(f"\nDONE: {done} in {time.time()-t0:.1f}s ({skip} skip, {no_disasm} no_disasm, {fail} fail)", file=sys.stderr)

if __name__ == "__main__":
    main()
