#!/usr/bin/env python3
"""LLM classification of AIC8800D80 MMIO register semantics.

Input: build/mmio/evidence.json (from mmio_harvest.py) — per-register dynamic
evidence (read/write counts, values, touching functions, echo/poll flags) plus
the static candidate universe.

For each batch (a page, chunked into ~32 contiguous registers), the LLM is
given the full evidence and must classify each register:
  - semantic name (snake_case, e.g. rf_pll_lock_status)
  - role: config | status | strobe | mask | irq | data | clock | unknown
  - confidence 0..1
  - behavior: one of the emulator-consumable rule types
  - fields: bit -> meaning (only where the evidence supports it)

The address-safety rule holds: every address in the LLM's output MUST be one
of the addresses given in the batch evidence. Output is validated and rejected
on invention. The LLM never computes addresses and never writes code.

Output: build/mmio/classifications.jsonl (one JSON per batch) and
build/mmio/classifications.json (merged, keyed by address).
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from datetime import datetime, timezone
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
# Must be inserted BEFORE importing oracle so `import tools` resolves to
# harness_v17/tools.py, not the repo's tools/ package.
sys.path.insert(0, str(REPO / "harness_v17"))

from oracle import call_api  # noqa: E402  (v17 LLM harness; also imports tools)

BATCH_SIZE = 32

SYSTEM = """You are mapping the peripheral register space of the AIC8800D80 WiFi SoC firmware.
You are given MMIO registers with dynamic evidence harvested by emulating the real
firmware (boot + a per-function sweep). Classify each register's semantics.

CRITICAL RULES:
1. You may NOT invent or compute any address. Every address in your output MUST
   be one of the addresses given to you in the evidence. Never add new addresses.
2. Only assign a semantic name and behavior when the evidence supports it.
   Otherwise use role "unknown", confidence 0.0, behavior {"type": "none"}.
3. Output ONLY a single JSON object. No prose, no explanation.
4. The JSON schema is exactly:
{
  "registers": [
    {
      "addr": "0x4003505c",
      "name": "rf_cmd_wait_status",
      "role": "status",
      "confidence": 0.7,
      "behavior": {"type": "poll", "ready_mask": "0x1", "reads_to_ready": 4},
      "fields": {"0x1": "ready bit set when the RF command completes"}
    }
  ]
}
`addr` MUST be copied verbatim from the evidence.

ROLES:
- config: written once to set up a peripheral (write-heavy, no poll)
- status: read to check state; often polled until a ready bit sets
- strobe: a write triggers an action and the value self-clears
- mask: bitmask controlling which interrupt/features are enabled
- irq: interrupt controller register (NVIC)
- data: transmit/receive data FIFO or buffer register
- clock: clock/reset control
- unknown: no evidence to classify

BEHAVIOR TYPES (consumable by the emulator; choose ONE):
- {"type": "none"}          -> reads return 0 (default phantom)
- {"type": "echo"}          -> reads return the last written value
- {"type": "poll", "ready_mask": "0x...", "reads_to_ready": N}
     -> status register a poller waits on. After ~N reads since the last write,
        reads return ready_mask (so `while (!(reg & MASK))` loops can exit).
        ready_mask is your best guess at the bit the poller checks; use low
        confidence when unsure. A function like rf_reg_write_wait reading the
        register many times with zero writes is the classic poll signal.
- {"type": "strobe", "clear_after": N}
     -> a write takes effect then reads return 0 again after N instructions.

EVIDENCE FIELDS you receive per register:
  reads / writes counts; written_values (hex -> count); readback_values;
  touching_functions (firmware fn names -> count; names encode subsystem:
  rf_*, log_*, timer_*, ipc_*, uart_*, sdio_*, crypto_*, ...); echo flag;
  poll flag + poll_note; co_access (same-page siblings touched by the same
  function); last_written.

BE EFFICIENT: a 0x4003xxxx page is RF/PHY control; 0xE000E4xx is NVIC;
0x4000xxxx low pages are small system/timer blocks. Use the register offset
and evidence together. Infer the block's purpose from the function names."""


def _chunk(regs: list[dict]) -> list[list[dict]]:
    regs = sorted(regs, key=lambda e: int(e["addr"], 16))
    return [regs[i:i + BATCH_SIZE] for i in range(0, len(regs), BATCH_SIZE)]


def _evidence_block(ev: dict) -> str:
    if ev.get("source") == "static":
        return (f"  {ev['addr']}: STATIC REFERENCE only (appears in a firmware constant "
                f"pool, never observed executing). Infer from the page and its siblings; "
                f"low confidence.")
    fn = ", ".join(f"{k}({v})" for k, v in list(ev.get("touching_functions", {}).items())[:6])
    co = ", ".join(f"{int(c):#x}" if isinstance(c, int) else c for c in ev.get("co_access", [])[:6])
    parts = [
        f"  {ev['addr']}: R={ev['reads']} W={ev['writes']} "
        f"size={ev.get('sizes')} echo={ev.get('echo')} poll={ev.get('poll')}",
    ]
    if ev.get("written_values"):
        parts.append(f"    written: {ev['written_values']}")
    if ev.get("readback_values"):
        parts.append(f"    readback: {ev['readback_values']}")
    if fn:
        parts.append(f"    fns: {fn}")
    if ev.get("poll_note"):
        parts.append(f"    poll_note: {ev['poll_note']}")
    if co:
        parts.append(f"    co_access: {co}")
    return "\n".join(parts)


def _batch_prompt(batch: list[dict], page_hex: str) -> str:
    lines = [_evidence_block(ev) for ev in batch]
    return f"""Peripheral page {page_hex} — classify these {len(batch)} registers.

EVIDENCE (address is the register; do not invent others):
{chr(10).join(lines)}

Return your classification JSON now."""


_ADDR_RE = re.compile(r"0x[0-9a-fA-F]{6,}")


def _validate(addrs_output: list[str], allowed: set[str]) -> tuple[bool, list[str]]:
    """Every output address must be verbatim from the batch evidence."""
    invented = [a for a in addrs_output if a not in allowed]
    return (not invented), invented


def _walk_addrs(obj) -> list[str]:
    """Collect every 0x... literal that looks like a register address."""
    out: list[str] = []
    if isinstance(obj, dict):
        for k, v in obj.items():
            if isinstance(k, str) and _ADDR_RE.match(k):
                out.append(k.lower())
            out.extend(_walk_addrs(v))
    elif isinstance(obj, list):
        for v in obj:
            out.extend(_walk_addrs(v))
    elif isinstance(obj, str):
        out.extend(m.group(0).lower() for m in _ADDR_RE.finditer(obj))
    return out


def classify_batch(batch: list[dict], page_hex: str) -> tuple[list[dict] | None, str]:
    allowed = {ev["addr"].lower() for ev in batch}
    prompt = _batch_prompt(batch, page_hex)
    messages = [
        {"role": "system", "content": SYSTEM},
        {"role": "user", "content": prompt},
    ]
    msg, _tool_calls = call_api(messages, None, max_tool_rounds=0)
    content = msg.get("content") or ""
    if not content:
        return None, "no_content"
    # Parse the first balanced JSON object.
    start = content.find("{")
    if start < 0:
        return None, "no_json"
    depth = 0
    end = -1
    for i in range(start, len(content)):
        if content[i] == "{":
            depth += 1
        elif content[i] == "}":
            depth -= 1
            if depth == 0:
                end = i + 1
                break
    if end < 0:
        return None, "no_json"
    try:
        parsed = json.loads(content[start:end])
    except json.JSONDecodeError as e:
        return None, f"json_err:{e}"
    regs = parsed.get("registers")
    if not isinstance(regs, list) or not regs:
        return None, "no_registers_array"
    addrs = _walk_addrs(regs)
    ok, invented = _validate(addrs, allowed)
    if not ok:
        return None, f"invented_addrs:{','.join(sorted(set(invented))[:4])}"
    # Attach the batch page tag and drop registers with unknown addresses.
    clean = []
    for r in regs:
        if r.get("addr", "").lower() not in allowed:
            continue
        r["page"] = page_hex
        clean.append(r)
    return clean, "ok"


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--evidence", type=Path, default=REPO / "build" / "mmio" / "evidence.json")
    ap.add_argument("--out", type=Path, default=REPO / "build" / "mmio" / "classifications.jsonl")
    ap.add_argument("--page", default="", help="only classify this page (e.g. 0x4003) for testing")
    ap.add_argument("--max-pages", type=int, default=0, help="stop after this many pages (testing)")
    ap.add_argument("--workers", type=int, default=1,
                    help="LLM concurrency (gateway 503s on concurrent; keep 1)")
    ap.add_argument("--include-static", action="store_true",
                    help="extend coverage to static candidates in dynamically-touched pages")
    args = ap.parse_args()

    ev = json.loads(args.evidence.read_text())
    regs = dict(ev["registers"])

    # Extend coverage: static candidate registers that live in a dynamically
    # touched page get sibling-context classification (no behavioral rule —
    # the materialize step only applies behavior to dynamic evidence).
    if args.include_static:
        dynamic_pages = {f"0x{((int(a, 16) >> 16) & 0xFFFF):04x}" for a in regs}
        for page, addrs in ev.get("static_candidates", {}).items():
            if page not in dynamic_pages:
                continue
            for a in addrs:
                key = hex(a)
                if key in regs:
                    continue
                regs[key] = {
                    "addr": key,
                    "source": "static",
                    "reads": 0, "writes": 0,
                    "touching_functions": {},
                    "co_access": [],
                }

    # Group by page.
    by_page: dict[str, list[dict]] = {}
    for a, e in regs.items():
        page = f"0x{(int(a, 16) >> 16) & 0xFFFF:04x}"
        by_page.setdefault(page, []).append(e)

    # Resume support: skip registers already classified (in the merged json).
    merged_path = args.out.with_suffix(".json")
    done_addrs: set[str] = set()
    if merged_path.is_file():
        existing = json.loads(merged_path.read_text()).get("classifications", {})
        done_addrs = set(existing)
        print(f"[classify] resuming: {len(done_addrs)} registers already classified")

    pages = sorted(by_page)
    if args.page:
        pages = [p for p in pages if p.lower() == args.page.lower()]
    if args.max_pages:
        pages = pages[:args.max_pages]

    args.out.parent.mkdir(parents=True, exist_ok=True)
    summary = {"pages": 0, "registers": 0, "ok": 0, "failed": 0, "skipped": len(done_addrs), "errors": {}}
    merged: dict[str, dict] = dict(existing) if done_addrs else {}
    append_mode = bool(done_addrs)
    with args.out.open("a" if append_mode else "w", encoding="utf-8") as f:
        for page in pages:
            for batch in _chunk(by_page[page]):
                batch = [ev for ev in batch if ev["addr"].lower() not in done_addrs]
                if not batch:
                    continue
                result, status = classify_batch(batch, page)
                summary["pages"] += 1
                if result is None:
                    summary["failed"] += 1
                    summary["errors"][status] = summary["errors"].get(status, 0) + 1
                    print(f"[classify] {page}: FAIL {status}", flush=True)
                    continue
                row = {
                    "page": page,
                    "generated_at": datetime.now(timezone.utc).isoformat(),
                    "registers": result,
                }
                f.write(json.dumps(row, sort_keys=True) + "\n")
                for r in result:
                    merged[r["addr"].lower()] = r
                    summary["registers"] += 1
                summary["ok"] += 1
                roles = {r.get("role", "?") for r in result}
                print(f"[classify] {page}: OK {len(result)} regs roles={sorted(roles)}", flush=True)
                # Incremental merged write so a partial run survives a restart.
                merged_path.write_text(json.dumps({"classifications": merged}, indent=1))

    print(json.dumps(summary, indent=2))
    print(f"[classify] wrote {args.out}")
    print(f"[classify] wrote {merged_path} ({len(merged)} regs classified)")
    return 0 if summary["failed"] == 0 else 1


if __name__ == "__main__":
    raise SystemExit(main())
