#!/usr/bin/env python3
"""v17 compilation oracle runner.

For each function in the integrated C, compare:
- Original disasm (from r2 on the original binary)
- Compiled disasm (from r2 on the integrated .o file)
Have LLM find divergences and propose mechanical fixes.

Output: harness_v17/compile_oracle/{fn}__{img}.json with divergence list.
"""
import json, sys, time, re, subprocess
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor, as_completed

REPO = Path("/home/grec-alexander/Downloads/aic8800d80")
sys.path.insert(0, str(REPO / "harness_v17"))
import tools as v17tools
from oracle import call_api, call_tool, TOOL_SCHEMA, validate_no_invented_addresses

NAMES_DIR = REPO / "harness_v17/names"
OUT_DIR = REPO / "harness_v17/compile_oracle"
OUT_DIR.mkdir(parents=True, exist_ok=True)

V17_BLINKY = Path("/tmp/v17_blinky")
FW_DIR = REPO / "inputs/firmware"

binaries = {
    "fmacfw_8800d80_h_u02_bin": "fmacfw_h",
    "fmacfw_8800d80_u02_bin": "fmacfw",
    "fmacfwbt_8800d80_u02_bin": "fmacfwbt",
    "lmacfw_rf_8800d80_u02_bin": "lmacfw_rf",
}


def get_function_at(image, addr):
    """Get the disasm of the original function at addr."""
    img_name = image[:-4] if image.endswith("_bin") else image
    bin_path = FW_DIR / f"{img_name}.bin"
    if not bin_path.exists():
        return []
    # Get 30 instructions starting at addr
    return v17tools.disasm_at(image, addr, 30)


def find_compiled_function(name, image, elf_path):
    """Find the compiled function in the ELF and return its disasm."""
    # Use r2 to find the function symbol and get its disasm
    cmd = ["r2", "-q", "-a", "arm", "-b", "16", "-m", "0x100000", "-2",
           "-c", f"s sym.{name}; pd 30", str(elf_path)]
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=15)
        import re
        out = re.sub(r'\x1b\[[0-9;]*m', '', result.stdout).strip()
        lines = [l.strip() for l in out.split('\n') if l.strip().startswith('0x')]
        return lines
    except Exception:
        return []


def compare_function(name, image, addr, elf_path):
    """Compare original vs compiled disasm. Ask LLM for divergences."""
    original = get_function_at(image, addr)
    compiled = find_compiled_function(name, image, elf_path)
    if not original and not compiled:
        return None, "no_disasm"
    if not original:
        return None, "no_original"
    if not compiled:
        return None, "no_compiled"

    system = """You are comparing the disassembly of a function from the ORIGINAL firmware binary vs the disassembly of a MECHANICALLY RECONSTRUCTED C function (compiled to ARM).

You have tools:
- read_dword, read_byte: read raw bytes
- decode_ldr_literal: decode PC-relative LDR
- disasm_at: disassemble at any address
- behavioral_at: see behavioral trace

CRITICAL RULES:
1. You may NOT compute addresses in your head. Use tools.
2. Output ONLY a JSON object: {"divergences": [{"type": "missing|extra|wrong_op|wrong_imm", "original": "<line>", "compiled": "<line>", "fix_hint": "1-line fix as hint to mechanical generator"}], "match_pct": 0-100, "concerns": ["..."]}
3. If they match well, return match_pct: 95+ and empty divergences.
4. Focus on STRUCTURAL divergences (missing reads, wrong immediate, wrong register). Don't be pedantic about redundant movs."""

    user = f"""Function: {name}
Image: {image}
Address: {addr}

ORIGINAL DISASM (truth):
{chr(10).join(original[:20])}

COMPILED DISASM (our reconstruction):
{chr(10).join(compiled[:20])}

Use tools to verify your findings. Output JSON."""

    messages = [
        {"role": "system", "content": system},
        {"role": "user", "content": user},
    ]
    try:
        msg, tool_calls = call_api(messages, TOOL_SCHEMA, max_tokens=2000, max_tool_rounds=4)
    except Exception as e:
        return None, f"err:{e}"
    content = (msg.get('content') or '').strip()
    if not content:
        return None, "no_content"
    is_valid, invented = validate_no_invented_addresses(content, tool_calls, user)
    if not is_valid:
        return None, f"invented:{','.join(invented[:3])}"
    # Parse JSON
    start = content.find('{')
    if start < 0: return None, "no_json"
    depth, end = 0, -1
    for i in range(start, len(content)):
        if content[i] == '{': depth += 1
        elif content[i] == '}':
            depth -= 1
            if depth == 0:
                end = i + 1
                break
    if end < 0: return None, "no_json"
    try:
        return json.loads(content[start:end]), "ok"
    except Exception as e:
        return None, f"json_err:{e}"


def main():
    # Get all named functions that have behavioral traces
    targets = []
    for f in NAMES_DIR.glob("*.json"):
        try:
            d = json.load(open(f))
            if d.get('status') != 'ok': continue
            name = d.get('name')
            if not name: continue
            # Skip generated/random names
            if re.match(r'^(sub|message|patch|rf|sdio|log)_[a-z0-9_]+_n?[0-9a-f]{2,4}$', name):
                continue
            # Get address
            addr = d.get('addr', '')
            if not addr: continue
            # Convert v14 to chip
            a = int(addr, 16) if isinstance(addr, str) else 0
            if a >= 0x200000: a -= 0x1100000
            if a < 0x100000: continue
            targets.append({'fn': name, 'img': d['img'], 'addr': f"0x{a:x}"})
        except Exception:
            pass
    print(f"Loaded {len(targets)} candidate functions", file=sys.stderr)
    # Sort by frequency: most-called functions first
    # For now, just shuffle and process
    import random
    random.shuffle(targets)
    targets = targets[:200]  # limit to 200 for first pass

    t0 = time.time()
    done = 0
    ok = 0
    fail = 0
    with ThreadPoolExecutor(max_workers=4) as ex:
        futures = {}
        for t in targets:
            img = t['img']
            if img not in binaries: continue
            name = t['fn']
            elf = V17_BLINKY / f"{binaries[img]}.elf"
            if not elf.exists():
                print(f"  ELF not found: {elf}", file=sys.stderr)
                continue
            out_path = OUT_DIR / f"{name}__{img}.json"
            if out_path.exists():
                continue
            futures[ex.submit(compare_function, name, img, t['addr'], elf)] = t
        for f in as_completed(futures):
            t = futures[f]
            result, status = f.result()
            done += 1
            if result:
                out_path = OUT_DIR / f"{t['fn']}__{t['img']}.json"
                out_path.write_text(json.dumps({
                    'function': t['fn'],
                    'image': t['img'],
                    'addr': t['addr'],
                    'result': result,
                }, indent=2))
                ok += 1
                match = result.get('match_pct', 0)
                n_div = len(result.get('divergences', []))
                print(f"  {t['fn']:40s} {t['img'][:20]:20s} match={match}% div={n_div}", file=sys.stderr)
            else:
                fail += 1
                if fail < 5:
                    print(f"  {t['fn']}: {status}", file=sys.stderr)
            if done % 25 == 0:
                rate = done / (time.time() - t0)
                eta = (len(targets) - done) / rate if rate > 0 else 0
                print(f"  {done}/{len(targets)} ok={ok} fail={fail} rate={rate:.1f}/s eta={eta:.0f}s", file=sys.stderr)
    print(f"\nDONE: {done} in {time.time()-t0:.1f}s ok={ok} fail={fail}", file=sys.stderr)


if __name__ == "__main__":
    main()
