#!/usr/bin/env python3
"""API key load balancer for harness v15.

Manages a pool of API keys, distributes requests round-robin,
tracks per-key rate limits, and falls back to next key on failure.

Config format (keys.json):
{
  "providers": [
    {
      "name": "minimax-promo-1",
      "base_url": "https://api.example.com/v1",
      "api_key": "sk-...",
      "model": "minimax-m3",
      "rpm_limit": 60,
      "context_window": 1000000
    },
    ...
  ],
  "strategy": "round_robin"
}
"""
import json
import time
from collections import defaultdict
from pathlib import Path
from threading import Lock


class KeyState:
    __slots__ = ("provider", "last_used", "failure_count", "consecutive_429s", "cooldown_until")

    def __init__(self, provider: dict):
        self.provider = provider
        self.last_used = 0.0
        self.failure_count = 0
        self.consecutive_429s = 0
        self.cooldown_until = 0.0

    def is_available(self) -> bool:
        return time.time() >= self.cooldown_until


class LoadBalancer:
    """Round-robin key pool with cooldown on rate-limit errors."""

    def __init__(self, config_path: str | Path):
        cfg = json.loads(Path(config_path).read_text())
        self.providers: list[KeyState] = [KeyState(p) for p in cfg["providers"]]
        self.strategy = cfg.get("strategy", "round_robin")
        self._idx = 0
        self._lock = Lock()
        self.stats = defaultdict(lambda: {"requests": 0, "failures": 0, "rate_limited": 0, "cooldowns": 0})

    def acquire(self) -> KeyState | None:
        """Return next available key, or None if all are in cooldown."""
        with self._lock:
            n = len(self.providers)
            for i in range(n):
                idx = (self._idx + i) % n
                ks = self.providers[idx]
                if ks.is_available():
                    self._idx = (idx + 1) % n
                    ks.last_used = time.time()
                    self.stats[ks.provider["name"]]["requests"] += 1
                    return ks
            return None

    def report_success(self, ks: KeyState):
        ks.failure_count = 0
        ks.consecutive_429s = 0

    def report_rate_limit(self, ks: KeyState, cooldown_seconds: float = 5.0):
        # Reactive only: if server says 429, wait briefly. No proactive throttling.
        ks.consecutive_429s += 1
        ks.cooldown_until = max(ks.cooldown_until, time.time() + cooldown_seconds)
        self.stats[ks.provider["name"]]["rate_limited"] += 1
        self.stats[ks.provider["name"]]["cooldowns"] += 1

    def report_failure(self, ks: KeyState):
        ks.failure_count += 1
        self.stats[ks.provider["name"]]["failures"] += 1
        # Track failures but don't impose local throttling. The server decides.

    def summary(self) -> dict:
        return {
            "providers": [
                {
                    "name": ks.provider["name"],
                    "available": ks.is_available(),
                    "failure_count": ks.failure_count,
                    "consecutive_429s": ks.consecutive_429s,
                    "cooldown_until": ks.cooldown_until,
                    **self.stats[ks.provider["name"]],
                }
                for ks in self.providers
            ]
        }


def strip_think_tags(text: str) -> str:
    """Remove <think>...</think> blocks from model output.

    Models with extended thinking emit reasoning before the final answer.
    We strip these so the verifier only sees the actual response.
    """
    import re
    # Strip <think>...</think> (greedy across newlines)
    text = re.sub(r"<think>.*?</think>", "", text, flags=re.DOTALL)
    return text.strip()


def make_chat_completion_payload(
    *,
    system: str,
    user: str,
    model: str,
    max_tokens: int = 4096,
    temperature: float = 0.0,
) -> dict:
    """Build an OpenAI-compatible chat completion request body."""
    return {
        "model": model,
        "max_tokens": max_tokens,
        "temperature": temperature,
        "messages": [
            {"role": "system", "content": system},
            {"role": "user", "content": user},
        ],
    }


def call_provider(ks: KeyState, payload: dict, timeout: float = 300.0) -> tuple[bool, str, str]:
    """Call the API. Returns (ok, response_text, error_msg).

    ok=True on success; ok=False on error (rate limit, network, etc).
    """
    import urllib.request
    import urllib.error

    base = ks.provider["base_url"].rstrip("/")
    url = f"{base}/chat/completions"
    data = json.dumps(payload).encode("utf-8")
    req = urllib.request.Request(
        url,
        data=data,
        headers={
            "Content-Type": "application/json",
            "Authorization": f"Bearer {ks.provider['api_key']}",
        },
        method="POST",
    )
    try:
        with urllib.request.urlopen(req, timeout=timeout) as resp:
            body = resp.read().decode("utf-8")
    except urllib.error.HTTPError as e:
        body = ""
        if e.code == 429:
            return False, "", f"rate_limited: HTTP 429"
        return False, "", f"http_error: {e.code} {e.reason}"
    except Exception as e:
        return False, "", f"network_error: {type(e).__name__}: {e}"

    try:
        obj = json.loads(body)
    except json.JSONDecodeError:
        return False, "", f"bad_json: {body[:200]}"

    if "error" in obj:
        return False, "", f"api_error: {obj['error']}"

    try:
        text = obj["choices"][0]["message"]["content"]
    except (KeyError, IndexError):
        return False, "", f"unexpected_response: {json.dumps(obj)[:200]}"

    return True, strip_think_tags(text), ""


def main() -> int:
    import argparse
    ap = argparse.ArgumentParser()
    ap.add_argument("--config", required=True, help="path to keys.json")
    ap.add_argument("--dry-run", action="store_true", help="show key pool, don't make calls")
    args = ap.parse_args()

    lb = LoadBalancer(args.config)
    print(json.dumps(lb.summary(), indent=2))

    if args.dry_run:
        return 0

    # Demo call
    ks = lb.acquire()
    if not ks:
        print("No keys available")
        return 1
    print(f"\nAcquired: {ks.provider['name']}")
    payload = make_chat_completion_payload(
        system="You are a test.",
        user="Reply with the single word: ok",
        model=ks.provider["model"],
    )
    ok, text, err = call_provider(ks, payload)
    if ok:
        print(f"Response: {text!r}")
        lb.report_success(ks)
    else:
        print(f"Error: {err}")
        lb.report_failure(ks)
    return 0 if ok else 1


if __name__ == "__main__":
    raise SystemExit(main())
