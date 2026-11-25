#!/usr/bin/env python3
"""Arbitrate high-confidence name disagreements between the GLM naming pass
and the luna batch, using the OpenAI Decisions API.

Measured motivation (2026-11-25): ~295 corpus-wide disagreements at luna
high confidence, and sampling shows half are genuine contradictions where
either namer could be right (double_compare_core vs double_divide). Neither
source is authoritative in isolation — so arbitrate per-function with the
function body as evidence: one choice question per function, "which name
better matches the actual behavior?"

Cost: ~300 single-question requests x ~1.5k input tokens — pennies.
Cache: metadata/luna_arbitration/<img>__<fn>.json, skip-if-exists.

Usage: python3 tools/luna_arbitrate.py [--limit N] [--workers 8]
"""
import glob
import json
import os
import re
import sys
from concurrent.futures import ThreadPoolExecutor, as_completed

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from decisions_client import decide

OUTDIR = "metadata/luna_arbitration"


def load_disagreements():
    out = []
    for f in glob.glob("metadata/luna_analysis/*.json"):
        try:
            o = json.load(open(f))
            d = json.loads(o["text"])
        except Exception:
            continue
        cur, new = o["fn"], d.get("name", "")
        if (cur != new and d.get("confidence") == "high"
                and re.fullmatch(r"[a-z][a-z0-9_]{2,40}", new or "")):
            out.append({"img": o["img"], "fn": cur, "luna": new,
                        "doc": d.get("docstring", "")})
    return out


def find_body(img, fn):
    for path in sorted(glob.glob(f"src/{img}/modules/mod*.c")):
        text = open(path).read()
        m = re.search(rf"(?m)^// {re.escape(fn)} @ 0x[0-9a-f]+\n", text)
        if m:
            end = text.find("\n// ", m.end())
            body = text[m.start(): end if end > 0 else len(text)]
            return body[:4500]
    return None


def arbitrate_one(item):
    key = f"{item['img']}__{item['fn']}"
    path = os.path.join(OUTDIR, key + ".json")
    if os.path.exists(path):
        return key, "cached"
    body = find_body(item["img"], item["fn"])
    if not body:
        return key, "nobody"
    q = [{
        "type": "choice",
        "instructions": (
            "This decompiled firmware function has two candidate names from "
            "independent analysts. Judge strictly by the actual behavior of "
            "the code, not by which name sounds better. If neither name "
            "matches the behavior even loosely, pick 'neither'."),
        "choices": [
            {"value": item["fn"], "description": f"candidate A: {item['fn']}"},
            {"value": item["luna"], "description": f"candidate B: {item['luna']} — analyst rationale: {item['doc'][:120]}"},
            {"value": "neither", "description": "neither name matches the behavior"},
        ],
    }]
    try:
        answers = decide(body, q)
        rec = dict(item)
        rec["answers"] = answers
        rec["status"] = "ok"
    except Exception as e:
        rec = dict(item)
        rec["status"] = "error"
        rec["error"] = str(e)[:200]
    tmp = path + ".tmp"
    with open(tmp, "w") as f:
        json.dump(rec, f, indent=1)
    os.replace(tmp, path)
    return key, "ok"


def main():
    os.makedirs(OUTDIR, exist_ok=True)
    limit = 100000
    workers = 8
    args = sys.argv[1:]
    if "--limit" in args:
        limit = int(args[args.index("--limit") + 1])
    if "--workers" in args:
        workers = int(args[args.index("--workers") + 1])
    items = load_disagreements()[:limit]
    print(f"{len(items)} high-confidence disagreements to arbitrate")
    done = err = 0
    with ThreadPoolExecutor(max_workers=workers) as ex:
        futs = {ex.submit(arbitrate_one, it): it for it in items}
        for fut in as_completed(futs):
            key, status = fut.result()
            if status == "ok":
                done += 1
            elif status == "cached":
                pass
            else:
                err += 1
            if (done + err) % 25 == 0:
                print(f"  progress: {done} ok, {err} err")
    print(f"arbitration complete: {done} new, {err} errors")


if __name__ == "__main__":
    main()
