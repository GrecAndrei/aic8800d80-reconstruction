#!/usr/bin/env python3
"""qwen3.8-flash client — Alibaba token plan, OpenAI-completions compatible.

Endpoint (from omp models.db): token-plan.ap-southeast-1.maas.aliyuncs.com
/compatible-mode/v1 — standard OpenAI chat completions shape.
Key: harness_v15/keys/alibaba_token_plan.json (gitignored, from omp agent.db).

Model facts (researched 2026-11-25, Alibaba Model Studio docs):
- qwen3.8-flash: 1M context, 131k max output, reasoning effort
  low/medium/xhigh (xhigh is the TOP — there is no 'max')
- implicit prompt caching: AUTOMATIC, no config, min 1024-token shared
  prefix, cached input bills at ~20%. Hit not guaranteed but batch workloads
  with a stable mega-prefix are exactly the designed case.
- explicit context cache: deterministic, 5-minute TTL (resets on hit),
  hits at ~10%, creation at 125% — only worth it for very hot reuse within
  a tight window; implicit is the right default for the batch.
"""
import json
import os
import urllib.request

KEY_PATH = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                        "../harness_v15/keys/alibaba_token_plan.json")
ENDPOINT = ("https://token-plan.ap-southeast-1.maas.aliyuncs.com"
            "/compatible-mode/v1/chat/completions")


def load_key(path=KEY_PATH):
    return json.load(open(path))["key"]


def complete(prompt, instructions, model="qwen3.8-flash", effort="xhigh",
             timeout=300, key=None, max_tokens=16384):
    """Single-turn completion via chat completions. Instructions go in the
    system message — it is the head of the shared prefix, which is what the
    implicit cache keys on. Returns (text, usage_dict)."""
    body = {
        "model": model,
        "messages": [
            {"role": "system", "content": instructions},
            {"role": "user", "content": prompt},
        ],
        "max_tokens": max_tokens,
        "enable_thinking": True,
        "thinking": {"type": "enabled"},
    }
    # effort: token-plan openai-compatible mode accepts reasoning_effort
    if effort:
        body["reasoning_effort"] = effort
    req = urllib.request.Request(
        ENDPOINT, data=json.dumps(body).encode(),
        headers={"Authorization": f"Bearer {key or load_key()}",
                 "Content-Type": "application/json"})
    with urllib.request.urlopen(req, timeout=timeout) as r:
        resp = json.loads(r.read().decode())
    msg = resp["choices"][0]["message"]
    text = msg.get("content") or ""
    return text, resp.get("usage", {})


if __name__ == "__main__":
    text, usage = complete("Reply with exactly OK", "You are a concise assistant.",
                           effort="low", max_tokens=64)
    print("qwen smoke:", repr(text[:40]))
    print("usage:", json.dumps(usage)[:200])
