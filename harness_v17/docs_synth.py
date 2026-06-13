#!/usr/bin/env python3
"""v17 documentation synthesizer.

For each subsystem, gather all named functions, their docstrings, and behavioral summaries.
Use tool-use LLM to write a markdown documentation of the subsystem.

Outputs: harness_v17/docs/{subsystem}.md
"""
import json, sys, time, re
from pathlib import Path
from collections import defaultdict
from concurrent.futures import ThreadPoolExecutor, as_completed

REPO = Path("/home/grec-alexander/Downloads/aic8800d80")
sys.path.insert(0, str(REPO / "harness_v17"))
import tools as v17tools
from oracle import call_api, call_tool, TOOL_SCHEMA, validate_no_invented_addresses

NAMES_DIR = REPO / "harness_v17/names"
OUT_DIR = REPO / "harness_v17/docs"
OUT_DIR.mkdir(parents=True, exist_ok=True)


def load_namings_by_subsystem():
    """Group namings by subsystem."""
    by_sub = defaultdict(list)
    for f in NAMES_DIR.glob("*.json"):
        try:
            d = json.load(open(f))
            if d.get('status') != 'ok': continue
            by_sub[d.get('subsystem', 'unknown')].append(d)
        except Exception:
            pass
    return by_sub


def synthesize_subsystem_docs(subsystem, fns):
    """Use tool-use LLM to write subsystem documentation."""
    # Build context: list of function names + docstrings
    lines = []
    for d in fns[:100]:  # limit to 100 per call
        lines.append(f"- {d['name']}: {d.get('docstring', '(no doc)')}")
    fn_list = "\n".join(lines)

    system = """You write firmware subsystem documentation. You have tools to look up specific functions, see their disasm and behavioral traces.

Output a markdown document with:
1. One-paragraph overview of what this subsystem does
2. List of major function groups (e.g., "TX path", "RX path", "Control")
3. Key data flow (just describe it; do NOT compute addresses)
4. Notable patterns observed in the functions

Do NOT include raw addresses in the markdown (or if you do, only addresses returned by tools). Be terse and informative."""
    user = f"""Subsystem: {subsystem}

Functions ({len(fns)} total, showing first 100):
{fn_list}

Write a markdown document explaining this subsystem."""
    messages = [
        {"role": "system", "content": system},
        {"role": "user", "content": user},
    ]
    try:
        msg, tool_calls = call_api(messages, TOOL_SCHEMA, max_tokens=3000, max_tool_rounds=4)
    except Exception as e:
        return None, f"err:{e}"
    content = (msg.get('content') or '').strip()
    if not content:
        return None, "no_content"
    is_valid, invented = validate_no_invented_addresses(content, tool_calls, user)
    if not is_valid:
        return None, f"invented:{','.join(invented[:3])}"
    return content, "ok"


def main():
    by_sub = load_namings_by_subsystem()
    print(f"Found {len(by_sub)} subsystems", file=sys.stderr)
    for sub, fns in sorted(by_sub.items(), key=lambda x: -len(x[1])):
        print(f"  {sub}: {len(fns)} functions", file=sys.stderr)

    # Process each subsystem
    t0 = time.time()
    done = 0
    ok = 0
    with ThreadPoolExecutor(max_workers=4) as ex:
        futures = {ex.submit(synthesize_subsystem_docs, sub, fns): sub
                   for sub, fns in by_sub.items()}
        for f in as_completed(futures):
            sub = futures[f]
            content, status = f.result()
            done += 1
            if content:
                out_path = OUT_DIR / f"{sub}.md"
                out_path.write_text(f"# {sub} Subsystem\n\n{content}\n")
                ok += 1
                print(f"  {sub}: ok ({len(content)} chars)", file=sys.stderr)
            else:
                print(f"  {sub}: {status}", file=sys.stderr)
    print(f"\nDONE: {done} in {time.time()-t0:.1f}s ok={ok}", file=sys.stderr)


if __name__ == "__main__":
    main()
