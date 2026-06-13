#!/usr/bin/env python3
"""v17 pattern library: cluster behavioral traces by similarity.

For each cluster, ask LLM to identify the common pattern (idiom).
Output: harness_v17/patterns/{cluster_id}.json
"""
import json, sys, re, time
from pathlib import Path
from collections import defaultdict
from concurrent.futures import ThreadPoolExecutor, as_completed

REPO = Path("/home/grec-alexander/Downloads/aic8800d80")
sys.path.insert(0, str(REPO / "harness_v17"))
import tools as v17tools
from oracle import call_api, call_tool, TOOL_SCHEMA, validate_no_invented_addresses

BEHAV_DIR = REPO / "extraction_out/reconstruction/mega7/synth"
OUT_DIR = REPO / "harness_v17/patterns"
OUT_DIR.mkdir(parents=True, exist_ok=True)


def extract_signature(behav_text):
    """Extract a normalized signature from a behavioral trace."""
    # Get unique MMIO addresses accessed
    addrs = set()
    pat = re.compile(r'\(uintptr_t\)\s*0x([0-9a-fA-F]+)')
    for m in pat.finditer(behav_text):
        addrs.add(m.group(1).lower())
    # Get function calls
    fns = set()
    fn_pat = re.compile(r'\b([a-z][a-z0-9_]{3,})\s*\(\s*\)')
    for m in fn_pat.finditer(behav_text):
        fns.add(m.group(1))
    # Get offset patterns (0x1, 0x4, etc.)
    offs = set()
    off_pat = re.compile(r'\(uintptr_t\)\s*0x([0-9a-fA-F]+)\b')
    for m in off_pat.finditer(behav_text):
        v = int(m.group(1), 16)
        if v < 0x10000:  # likely offset
            offs.add(m.group(1).lower())
    return {
        'addrs': sorted(addrs)[:20],  # cap
        'fns': sorted(fns)[:20],
        'offs': sorted(offs)[:20],
        'op_count': len(behav_text.split('\n')),
    }


def cluster_by_signature():
    """Group behavioral files by signature similarity."""
    clusters = defaultdict(list)
    for f in BEHAV_DIR.glob("behavioral_*.synth.c"):
        try:
            text = f.read_text(errors='ignore')
            sig = extract_signature(text)
            # Use first 5 MMIO addresses and first 5 function calls as cluster key
            key_parts = tuple(sig['addrs'][:3] + sig['fns'][:3])
            if not key_parts: continue
            key = '|'.join(key_parts)
            clusters[key].append({'file': f.name, 'sig': sig})
        except Exception:
            pass
    return clusters


def name_cluster(cluster_id, members):
    """Use tool-use LLM to name a cluster of similar functions."""
    # Sample 3-5 functions from the cluster
    samples = members[:5]
    sample_texts = []
    for m in samples:
        f = BEHAV_DIR / m['file']
        if f.exists():
            text = f.read_text(errors='ignore')
            sample_texts.append(f"--- {m['file']} ---\n{text[:500]}")
    samples_str = "\n\n".join(sample_texts)

    system = """You identify firmware function patterns. You have tools to look up specific functions.

For the cluster, output JSON:
- "pattern_name": short snake_case name (e.g., "rf_bus_write_polling", "struct_zero_init")
- "description": 1-line description
- "category": mmio_write|mmio_poll|mmio_read|struct_init|memset|dispatcher|util
- "template_c": a C template (e.g., "func(struct *p) { p->a = 0; p->b = 0; }")

Be terse. Use the tools to verify your guesses if needed."""
    user = f"""Cluster ({len(members)} functions). Sample behaviors:

{samples_str}

Output JSON with pattern_name, description, category, template_c."""
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
    clusters = cluster_by_signature()
    print(f"Found {len(clusters)} clusters from {sum(len(v) for v in clusters.values())} functions", file=sys.stderr)
    # Sort by size, biggest first
    sorted_clusters = sorted(clusters.items(), key=lambda x: -len(x[1]))
    # Take top 100 clusters (the most common patterns)
    sorted_clusters = sorted_clusters[:100]
    t0 = time.time()
    done = 0
    ok = 0
    with ThreadPoolExecutor(max_workers=4) as ex:
        futures = {ex.submit(name_cluster, cid, members): cid
                   for cid, members in sorted_clusters}
        for f in as_completed(futures):
            cid = futures[f]
            result, status = f.result()
            done += 1
            if result:
                out_path = OUT_DIR / f"cluster_{hash(cid) & 0xffff:04x}.json"
                out_path.write_text(json.dumps({
                    'cluster_id': cid,
                    'size': len(clusters[cid]),
                    'pattern': result,
                }, indent=2))
                ok += 1
                print(f"  {done}/{len(sorted_clusters)} ok ({len(clusters[cid])} funcs): {result.get('pattern_name', '?')}", file=sys.stderr)
            else:
                print(f"  {done}/{len(sorted_clusters)} {status}", file=sys.stderr)
    print(f"\nDONE: {done} in {time.time()-t0:.1f}s ok={ok}", file=sys.stderr)


if __name__ == "__main__":
    main()
