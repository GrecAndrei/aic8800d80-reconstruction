#!/usr/bin/env python3
"""v20 Step 3 v4: send thinking + ask for JSON in second turn."""
import json, os, re, sys, time
from pathlib import Path
from collections import defaultdict

REPO = Path(__file__).resolve().parent.parent.parent
sys.path.insert(0, str(REPO / "harness_v17"))
from oracle import call_api, get_key  # type: ignore

v19_structs = json.load(open(REPO / "harness_v20/../harness_v19/structs.json"))
all_groups = []
for p in (REPO / "harness_v20/structs").glob("*_clusters.json"):
    d = json.load(open(p))
    for g in d['significant_groups']:
        all_groups.append({
            'img': d['img'],
            'arg': g['primary_arg'],
            'n_funcs': g['func_count'],
            'fingerprint': tuple(tuple(p) for p in g['fingerprint']),
        })
fp_groups = defaultdict(list)
for g in all_groups:
    fp_groups[g['fingerprint']].append(g)
sorted_fps = sorted(fp_groups.items(), key=lambda x: -sum(g['n_funcs'] for g in x[1]))

# Top 8
proposals = []
for i, (fp, gs) in enumerate(sorted_fps[:8]):
    n_total = sum(g['n_funcs'] for g in gs)
    args = sorted(set(g['arg'] for g in gs))
    sample_funcs = set()
    for p in (REPO / "harness_v20/structs").glob("*_clusters.json"):
        d = json.load(open(p))
        for g in d['significant_groups']:
            if tuple(tuple(p) for p in g['fingerprint']) == fp:
                for sf in g.get('sample_funcs', [])[:3]:
                    sample_funcs.add(f"{sf['func_name']}@0x{sf['func_addr']:x}")
                break
    proposals.append({
        'group_id': i,
        'fingerprint': [[o, s] for o, s in fp],
        'n_total_funcs': n_total,
        'args': args,
        'sample_funcs': sorted(sample_funcs)[:4],
    })

v19_ref = "\n".join(f"  {sname}: {', '.join(f'{fname}=0x{off:x}' for fname, off in fields.items())}"
                    for sname, fields in v19_structs.items())

patterns_text = ""
for p in proposals:
    fp_text = ','.join(f"+0x{o:04x}({s})" for o, s in p['fingerprint'])
    patterns_text += f"#{p['group_id']} {p['n_total_funcs']}fns arg={p['args']} [{fp_text}] funcs:{','.join(p['sample_funcs'][:3])}\n"

# Multi-turn approach: ask for analysis first, then JSON
key = get_key()
# First turn: brief analysis
messages = [
    {"role": "system", "content": "You are a reverse engineer. Be brief and direct. Output JSON when asked."},
    {"role": "user", "content": f"Reference structs (AIC8800D80 firmware):\n{v19_ref}\n\nFor each pattern below, give a 1-line name guess:\n{patterns_text}\n\nFormat your answer as: '#N: name' lines only. No prose."}
]
m1, _ = call_api(messages, tools=None, max_tokens=2000, temperature=0.0)
r1 = m1.get("content", "") if isinstance(m1, dict) else str(m1)
print(f"Turn 1: {len(r1)} chars")
print(r1[:1000])

# Second turn: detailed JSON
messages.append({"role": "assistant", "content": r1})
messages.append({"role": "user", "content": "Now expand each name into a full struct with field names. Use this JSON schema:\n{\"groups\":[{\"id\":N,\"name\":\"...\",\"fields\":[{\"name\":\"f\",\"off\":0,\"size\":4,\"type\":\"uint32_t\"}]}]}\nSkip sp-arg stack locals. Output JSON only, no prose, no markdown."})
m2, _ = call_api(messages, tools=None, max_tokens=4000, temperature=0.0)
r2 = m2.get("content", "") if isinstance(m2, dict) else str(m2)
print(f"\nTurn 2: {len(r2)} chars")
print(r2[:500])
print("...")
print(r2[-500:])

# Parse
m = re.search(r'\{[\s\S]*"groups"[\s\S]*\}', r2)
parsed = None
if m:
    try:
        parsed = json.loads(m.group(0))
        print(f"Parsed {len(parsed.get('groups', []))} groups!")
    except json.JSONDecodeError as e:
        print(f"JSON parse failed: {e}")
        # Try to find array
        m2 = re.search(r'\{"groups":\s*\[[\s\S]*?\]\s*\}', r2)
        if m2:
            try:
                parsed = json.loads(m2.group(0))
                print(f"Parsed {len(parsed.get('groups', []))} groups (array-only)!")
            except:
                pass

out_path = REPO / "harness_v20/structs/proposals_v4.json"
out_path.write_text(json.dumps({
    'proposals': proposals,
    'r1': r1,
    'r2': r2,
    'parsed': parsed,
    'timestamp': time.time(),
}, indent=2))
print(f"Saved to {out_path}")
