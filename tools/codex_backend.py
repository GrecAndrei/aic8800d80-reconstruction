#!/usr/bin/env python3
"""Codex subscription backend client — flat-rate gpt-6-luna access.

Verified working 2026-11-25: the OAuth access_token in ~/.codex/auth.json
authenticates against https://chatgpt.com/backend-api/codex/responses with
the streaming Responses API. This is subscription-flat-rate access (the
user's Codex/ChatGPT-Work plan), NOT per-token billing — suitable for
high-volume corpus-scale work with no concurrency limits on our side.

Endpoint shape (codex-rs compatible, required):
  POST https://chatgpt.com/backend-api/codex/responses
  Authorization: Bearer <tokens.access_token>
  chatgpt-account-id: <tokens.account_id>
  originator: codex_cli_rs
  OpenAI-Beta: responses=experimental
  body: {model, instructions, input:[{type:message,role,content:[{type:
        input_text,text}]}], store:false, stream:true}
Non-streaming requests are rejected (400); auth failures are 401/403, a 400
means auth passed but the payload shape is wrong.
"""
import json
import urllib.request

ENDPOINT = "https://chatgpt.com/backend-api/codex/responses"
AUTH_PATH = "/home/alex/.codex/auth.json"


def load_tokens(path=AUTH_PATH):
    auth = json.load(open(path))
    return auth["tokens"]


def complete(prompt, instructions="You are a concise assistant.",
             model="gpt-6-luna", reasoning_effort=None, timeout=180,
             tokens=None):
    """Single-turn completion; returns the output text. Streaming SSE is
    consumed and the final response.output_text content reassembled."""
    tok = tokens or load_tokens()
    body = {
        "model": model,
        "instructions": instructions,
        "input": [{
            "type": "message", "role": "user",
            "content": [{"type": "input_text", "text": prompt}],
        }],
        "store": False,
        "stream": True,
    }
    if reasoning_effort:
        body["reasoning"] = {"effort": reasoning_effort}
    req = urllib.request.Request(
        ENDPOINT,
        data=json.dumps(body).encode(),
        headers={
            "Authorization": f"Bearer {tok['access_token']}",
            "Content-Type": "application/json",
            "OpenAI-Beta": "responses=experimental",
            "chatgpt-account-id": tok["account_id"],
            "originator": "codex_cli_rs",
        })
    chunks = []
    with urllib.request.urlopen(req, timeout=timeout) as r:
        for raw in r:
            line = raw.decode("utf-8", "replace").strip()
            if not line.startswith("data:"):
                continue
            payload = line[5:].strip()
            if payload == "[DONE]":
                break
            try:
                ev = json.loads(payload)
            except json.JSONDecodeError:
                continue
            t = ev.get("type", "")
            if t == "response.output_text.delta":
                chunks.append(ev.get("delta", ""))
            elif t == "response.completed":
                # canonical final text if deltas missed anything
                resp = ev.get("response", {})
                if not chunks:
                    for item in resp.get("output", []):
                        for c in item.get("content", []):
                            if c.get("type") == "output_text":
                                chunks.append(c.get("text", ""))
    return "".join(chunks)


if __name__ == "__main__":
    out = complete("reply with exactly: OK")
    print("codex backend smoke:", repr(out[:60]))
