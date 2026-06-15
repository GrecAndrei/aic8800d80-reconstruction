#!/usr/bin/env python3
"""v20 Step 3 v3: split thinking + answer into 2 calls."""
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

# Direct prompt with explicit JSON schema
v19_ref = "\n".join(f"  struct {sname}: {', '.join(f'{fname}=0x{off:x}' for fname, off in fields.items())}"
                    for sname, fields in v19_structs.items())

prompt = "Output ONLY a JSON object, no prose. Schema:\n"
prompt += '{"groups":[{"id":N,"name":"struct_name","fields":[{"name":"f","off":0,"size":4,"type":"uint32_t"}]}]}\n\n'
prompt += "Reference structs from AIC8800D80 firmware:\n"
prompt += v19_ref + "\n\n"
prompt += "Identify each pattern (skip sp-arg stack locals). Match to v19 structs or propose new:\n"

for p in proposals:
    fp_text = ','.join(f"+0x{o:04x}({s})" for o, s in p['fingerprint'])
    prompt += f"#{p['group_id']} {p['n_total_funcs']}fns arg={p['args']} [{fp_text}] funcs:{','.join(p['sample_funcs'][:3])}\n"

key = get_key()
messages = [{"role": "user", "content": prompt}]
# Increase max_tokens significantly
result_msg, _ = call_api(messages, tools=None, max_tokens=8000, temperature=0.0)
result = result_msg.get("content", "") if isinstance(result_msg, dict) else str(result_msg)
print(f"Result: {len(result)} chars")
print("First 500:", result[:500])
print("...")
print("Last 500:", result[-500:])

# Try to parse JSON
m = re.search(r'\{[\s\S]*"groups"[\s\S]*\}', result)
parsed = None
if m:
    try:
        parsed = json.loads(m.group(0))
        print(f"Parsed {len(parsed.get('groups', []))} groups!")
    except json.JSONDecodeError as e:
        print(f"JSON parse failed: {e}")

# Save
out_path = REPO / "harness_v20/structs/proposals_v3.json"
out_path.write_text(json.dumps({
    'proposals': proposals,
    'llm_response': result,
    'parsed': parsed,
    'timestamp': time.time(),
}, indent=2))
print(f"Saved to {out_path}")
