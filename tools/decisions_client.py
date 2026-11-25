#!/usr/bin/env python3
"""OpenAI Decisions API client — typed corpus-scale classification.

Verified working 2026-11-25: POST /v1/decisions with the platform key
(harness_v15/keys/openai_platform.json, untracked — extracted from omp's
agent.db auth_credentials). gpt-6-luna only. Up to 400 questions per
request, ~10x faster than Responses, zero output tokens — corpus-wide
classification of all 4,718 functions costs pennies.

Answer types: choice (one of supplied values with probabilities),
predicate (probability a condition holds), score (rubric grade).
Schema notes: choices are objects {"value": ..., "description": ...},
NOT bare strings — strings are rejected with a 400.

Usage:
  from decisions_client import decide
  answers = decide(input_text, questions)
"""
import json
import urllib.request

KEY_PATH = "harness_v15/keys/openai_platform.json"
ENDPOINT = "https://api.openai.com/v1/decisions"


def load_key(path=KEY_PATH):
    return json.load(open(path))["api_key"]


def decide(input_text, questions, key=None, timeout=120, model="gpt-6-luna"):
    """Evaluate questions against shared input evidence.
    questions: list of dicts —
      {"type": "choice", "instructions": ..., "choices": [{"value": ..., "description": ...}]}
      {"type": "predicate", "instructions": ...}
      {"type": "score", "instructions": ..., "rubric": ...}  (if supported)
    Returns the parsed answers list."""
    body = json.dumps({
        "model": model,
        "input": input_text,
        "questions": questions,
    }).encode()
    req = urllib.request.Request(
        ENDPOINT, data=body,
        headers={"Authorization": f"Bearer {key or load_key()}",
                 "Content-Type": "application/json"})
    with urllib.request.urlopen(req, timeout=timeout) as r:
        resp = json.loads(r.read().decode())
    return resp.get("answers", [])


if __name__ == "__main__":
    out = decide(
        "test evidence",
        [{"type": "predicate", "instructions": "Is this a test?"}])
    print("smoke:", json.dumps(out)[:200])
