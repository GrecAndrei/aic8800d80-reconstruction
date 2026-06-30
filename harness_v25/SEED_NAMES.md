# Cluster naming provenance

The `name` field on clusters in `harness_v25/out/<img>_clusters.json`
can come from three sources:

1. **`fwstruct names`** — the LLM-named cluster pipeline (requires API keys).
   Currently emits 0 names because the LLM quota was exhausted during
   the latest build. Re-run with `bin/fwstruct names --llm-key-dir /tmp/fw_keys`.

2. **`tools/v22_seeder.py`** (one-time propagation from v22) —
   propagates the LLM-named struct names from harness_v22/SUMMARY.json
   (20 unique structs, 52 named clusters across 4 binaries) into v25's
   clusters by matching on `primary_arg` (with AAPCS normalization:
   `a1/a2/a3/a4/v3/v5/v14` → `r0/r1/r2/r3`).
   Currently produces 4 high-confidence matches; the rest are
   rejected because v25's clusters split by (base, offset) more
   aggressively than v22's primary-arg clusters.

3. **`bin/fwstruct names --llm-key-dir <dir>`** — to fill the gap, run
   the LLM-naming pipeline; it will update each cluster's `name` field
   in place when the LLM returns a valid proposal.

## Re-running the seeder

```bash
# Regenerate clusters first
bin/fwstruct scan structs

# Then run the seeder
python3 - <<'PY'
import json, os

def norm(a):
    m = {'a1':'r0', 'a2':'r1', 'a3':'r2', 'a4':'r3',
         'v3':'r0', 'v5':'r1', 'v14':'r3'}
    return m.get(a, a)

v21 = json.load(open('harness_v21/SUMMARY.json'))
def load_v20_names(img_v25):
    img_v20 = img_v25.replace('_bin', '')
    p = f'harness_v20/access_patterns/{img_v20}_bin_patterns.json'
    if not os.path.exists(p): return {}
    d = json.load(open(p))
    return {f['func_addr']: f['func_name'] for f in d['funcs']}

for img in ['fmacfw_8800d80_h_u02_bin', 'fmacfw_8800d80_u02_bin',
           'fmacfwbt_8800d80_u02_bin', 'lmacfw_rf_8800d80_u02_bin']:
    v25 = json.load(open(f'harness_v25/out/{img}_clusters.json'))
    addr_to_name = load_v20_names(img)
    used = set()
    # Group by normalized primary_arg
    by_pa = {}
    for i, c in enumerate(v25['clusters']):
        by_pa.setdefault(norm(c.get('primary_arg', '')), []).append((i, c))
    # Iterate v21 clusters sorted by descending n_funcs
    v21_in = [c for c in v21['all_clusters']
              if c.get('img') == img and c.get('llm_name')]
    for vc in sorted(v21_in, key=lambda c: c['n_funcs'], reverse=True):
        pa = norm(vc['primary_arg'])
        top = vc.get('top_funcs', [])
        best = None
        best_score = 0
        for i, c in by_pa.get(pa, []):
            if i in used or len(c.get('funcs', [])) < 3:
                continue
            shared = sum(1 for a in c['funcs']
                         if addr_to_name.get(a) in top)
            score = shared * 100 + len(c['funcs'])
            if shared > 0 or len(c['funcs']) >= 10:
                if score > best_score:
                    best_score = score
                    best = i
        if best is not None:
            v25['clusters'][best]['name'] = vc['llm_name']
            used.add(best)
    json.dump(v25, open(f'harness_v25/out/{img}_clusters.json', 'w'),
              indent=2)
PY
bin/fwstruct report
```