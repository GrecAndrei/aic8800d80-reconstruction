#!/usr/bin/env python3
"""v22: ask LLM for more struct names for 20+ more clusters."""
import json, re, sys
from pathlib import Path
from collections import defaultdict
sys.path.insert(0, str(Path(__file__).resolve().parent.parent.parent / "harness_v17"))
from oracle import call_api, get_key

REPO = Path(__file__).resolve().parent.parent.parent

# Get all unnamed clusters
named_fps = set()
props = json.load(open(REPO / "harness_v20/structs/proposals_v4.json"))
for g in props.get('parsed', {}).get('groups', []):
    fp = tuple(sorted((f['off'], f['size']) for f in g.get('fields', [])))
    named_fps.add(fp)

named_names = {g['name']: tuple(sorted((f['off'], f['size']) for f in g.get('fields', []))) for g in props.get('parsed', {}).get('groups', [])}

all_unnamed = []
for f in (REPO / "harness_v20/structs").glob("*_clusters.json"):
    d = json.load(open(f))
    img = d['img']
    for g in d['significant_groups']:
        fp = tuple(sorted(tuple(p) for p in g['fingerprint']))
        if fp not in named_fps:
            all_unnamed.append({
                'img': img,
                'gid': g['group_id'],
                'arg': g['primary_arg'],
                'n': g['func_count'],
                'fp': fp,
                'sample': [sf['func_name'] for sf in g.get('sample_funcs', [])[:3]],
            })
all_unnamed.sort(key=lambda x: -x['n'])
top = all_unnamed[:20]

v22_ref = "Reference - already known struct names:\n"
for n in named_names:
    v22_ref += f"  struct {n}\n"

patterns_text = ""
for i, u in enumerate(top):
    fp_text = ','.join(f"+0x{off:04x}({sz})" for off, sz in u['fp'])
    patterns_text += f"#{i} {u['n']}fns img={u['img']}/g{u['gid']} arg={u['arg']} [{fp_text}] funcs:{','.join(u['sample'][:3])}\n"

prompt = f"Output strict JSON only. Schema: {{\"groups\":[{{\"id\":N,\"name\":\"...\",\"fields\":[{{\"name\":\"f\",\"off\":0,\"size\":4,\"type\":\"uint32_t\"}}]}}]}}\n\n"
prompt += v22_ref
prompt += "\nFor each pattern below, give a struct name. Skip sp-arg stack locals. Output JSON only, no prose:\n"
prompt += patterns_text

key = get_key()
m1, _ = call_api([
    {"role": "system", "content": "You are a reverse engineer. Be brief. Output JSON when asked."},
    {"role": "user", "content": f"Reference: {v22_ref}\n\nFor each, give 1-line name guess:\n{patterns_text}\n\nFormat: '#N: name' lines only."}
], tools=None, max_tokens=1500, temperature=0.0)
r1 = m1.get("content", "") if isinstance(m1, dict) else str(m1)
print(f"Turn 1: {len(r1)} chars")
print(r1[:500])

m2, _ = call_api([
    {"role": "system", "content": "You are a reverse engineer. Be brief. Output JSON when asked."},
    {"role": "user", "content": f"Reference: {v22_ref}\n\nFor each pattern, give 1-line name:\n{patterns_text}\n\nFormat: '#N: name' lines only."},
    {"role": "assistant", "content": r1},
    {"role": "user", "content": "Now expand each name into a full struct with field names. Skip sp-arg. Schema: {\"groups\":[{\"id\":N,\"name\":\"...\",\"fields\":[{\"name\":\"f\",\"off\":0,\"size\":4,\"type\":\"uint32_t\"}]}]}\nOutput JSON only, no prose, no markdown."}
], tools=None, max_tokens=5000, temperature=0.0)
r2 = m2.get("content", "") if isinstance(m2, dict) else str(m2)
print(f"\nTurn 2: {len(r2)} chars")
print(r2[:300])
print("...")
print(r2[-500:])

m = re.search(r'\{[\s\S]*"groups"[\s\S]*\}', r2)
parsed = None
if m:
    try:
        parsed = json.loads(m.group(0))
        print(f"Parsed {len(parsed.get('groups', []))} groups!")
    except json.JSONDecodeError as e:
        print(f"JSON parse failed: {e}")

out_path = REPO / "harness_v22/structs/proposals.json"
out_path.parent.mkdir(parents=True, exist_ok=True)
out_path.write_text(json.dumps({
    'input_clusters': top,
    'r1': r1, 'r2': r2, 'parsed': parsed,
}, indent=2))
print(f"Saved to {out_path}")
