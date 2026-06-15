#!/usr/bin/env python3
"""v20 Step 3: use LLM to propose struct field names from access fingerprints.

For each cross-binary recurring fingerprint, ask the LLM to identify what
struct it could be, using the v19 known structs as a reference.
"""
import json, os, re, sys, time
from pathlib import Path
from collections import defaultdict

REPO = Path(__file__).resolve().parent.parent.parent
sys.path.insert(0, str(REPO / "harness_v17"))
from oracle import call_api, get_key  # type: ignore

# Load v19 known structs
v19_structs = json.load(open(REPO / "harness_v20/../harness_v19/structs.json"))

# Load v20 clusters
all_groups = []
for p in (REPO / "harness_v20/structs").glob("*_clusters.json"):
    d = json.load(open(p))
    img = d['img']
    for g in d['significant_groups']:
        all_groups.append({
            'img': img,
            'arg': g['primary_arg'],
            'n_funcs': g['func_count'],
            'fingerprint': tuple(tuple(p) for p in g['fingerprint']),
        })
# Group by fingerprint
fp_groups = defaultdict(list)
for g in all_groups:
    fp_groups[g['fingerprint']].append(g)

# Sort by total funcs
sorted_fps = sorted(fp_groups.items(), key=lambda x: -sum(g['n_funcs'] for g in x[1]))

# Build prompt
def fingerprint_to_text(fp):
    parts = []
    for o, s in fp:
        parts.append(f"  +0x{o:04x} (size {s})")
    return '\n'.join(parts)

# Format v19 known structs as reference
v19_ref = "Reference - already known struct definitions:\n"
for sname, fields in v19_structs.items():
    v19_ref += f"\nstruct {sname} {{\n"
    for fname, off in fields.items():
        v19_ref += f"    uint32_t {fname};  // offset 0x{off:x}\n"
    v19_ref += "}\n"

# Take top 20 fingerprints
proposals = []
for i, (fp, gs) in enumerate(sorted_fps[:20]):
    n_total = sum(g['n_funcs'] for g in gs)
    imgs = sorted(set(g['img'] for g in gs))
    args = sorted(set(g['arg'] for g in gs))
    # Sample function names from each image
    sample_funcs = set()
    for p in (REPO / "harness_v20/structs").glob("*_clusters.json"):
        d = json.load(open(p))
        for g in d['significant_groups']:
            if tuple(tuple(p) for p in g['fingerprint']) == fp:
                for sf in g.get('sample_funcs', [])[:3]:
                    sample_funcs.add(f"{sf['func_name']} @0x{sf['func_addr']:x}")
                break
    proposals.append({
        'group_id': i,
        'fingerprint': [[o, s] for o, s in fp],
        'n_total_funcs': n_total,
        'images': imgs,
        'args': args,
        'sample_funcs': sorted(sample_funcs)[:8],
    })

# Build LLM prompt
prompt = f"""You are a reverse engineer analyzing ARM Thumb firmware from the AIC8800D80 WiFi/BT chip.

The firmware uses the following KNOWN struct definitions (from previous analysis):
{v19_ref}

Now we have discovered new access patterns from disassembly. For each pattern, the firmware
accesses a struct-like object with the given offsets. Identify the most likely struct name
and field names based on:
1. The offset pattern
2. The argument register (r0-r7 are function args, sp is stack frame)
3. The sample function names
4. The count of functions using this pattern (more = more confident)

Output JSON only. Format: {{"groups": [{{"group_id": N, "struct_name": "...", "rationale": "...", "fields": [{{"name": "...", "offset": 0, "size": 4, "type": "uint32_t"}}]}}, ...]}}

For fields: use uint8_t, uint16_t, uint32_t, or pointer. If unsure, write "unknown".

Patterns:
"""

for p in proposals:
    fp_text = '\n'.join(f"  +0x{o:04x} (size {s})" for o, s in p['fingerprint'])
    prompt += f"""
Group {p['group_id']} ({p['n_total_funcs']} funcs across {len(p['images'])} images, arg={p['args']}):
{fp_text}
Sample functions: {', '.join(p['sample_funcs'][:5])}
"""

print(f"Prompt: {len(prompt)} chars, {len(proposals)} groups")
print(prompt[:500] + "...")
print("---")
print("Calling LLM...")

# Call LLM
key = get_key()
messages = [{"role": "user", "content": prompt}]
result_msg, _ = call_api(messages, tools=None, max_tokens=4096, temperature=0.1)
result = result_msg.get("content", "") if isinstance(result_msg, dict) else str(result_msg)
print(f"Result: {len(result)} chars")
print(result[:500])

# Save
out_path = REPO / "harness_v20/structs/proposals.json"
out_path.write_text(json.dumps({
    'proposals': proposals,
    'llm_response': result,
    'timestamp': time.time(),
}, indent=2))
print(f"Saved to {out_path}")
