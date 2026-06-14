#!/usr/bin/env python3
"""v17 tool-use LLM harness.

The LLM is given a task + tool schema. It must:
1. Call tools to gather context (no math in its head)
2. Output a structured JSON response

The harness validates that any address literal in the LLM's response
matches a tool-call result, not an LLM-invented value.
"""
import json, re, subprocess, sys, time, threading, urllib.request
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor, as_completed

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "harness_v17"))
import tools as v17tools
from tools import TOOL_SCHEMA, call_tool

KEYS = json.load(open(REPO / "harness_v15/keys/keys.json"))['providers']
_local = threading.local()
def get_key():
    if not hasattr(_local, 'i'):
        _local.i = 0
    k = KEYS[_local.i % len(KEYS)]
    _local.i += 1
    return k

def call_api(messages, tools, max_tokens=2000, temperature=0.0, max_tool_rounds=6):
    """Call LLM with tools. Loops until LLM gives a final answer or hits max_tool_rounds.
    Returns (final_message, all_tool_calls_made).
    """
    key = get_key()
    tool_results_seen = []  # collect every tool result for validation
    for round_n in range(max_tool_rounds + 1):
        # On the last round, force a final answer (no tools)
        is_final_round = (round_n == max_tool_rounds)
        try:
            payload = {
                "model": key['model'],
                "messages": messages,
                "max_tokens": max_tokens,
                "temperature": temperature,
            }
            if tools and not is_final_round:
                payload["tools"] = tools
            if is_final_round:
                # Force a final answer
                messages.append({
                    "role": "user",
                    "content": "STOP using tools. Output your final JSON answer NOW based on what you've seen. No more tool calls."
                })
            req = urllib.request.Request(
                "https://api.tokenrouter.com/v1/chat/completions",
                data=json.dumps(payload).encode(),
                headers={
                    "Authorization": f"Bearer {key['api_key']}",
                    "Content-Type": "application/json"
                }
            )
            r = urllib.request.urlopen(req, timeout=120)
            resp = json.loads(r.read())
            msg = resp['choices'][0]['message']
            if msg.get('tool_calls') and not is_final_round:
                # Execute each tool call
                messages.append(msg)
                for tc in msg['tool_calls']:
                    fn_name = tc['function']['name']
                    try:
                        fn_args = json.loads(tc['function']['arguments'])
                    except Exception:
                        fn_args = {}
                    result = call_tool(fn_name, fn_args)
                    tool_results_seen.append({'name': fn_name, 'args': fn_args, 'result': result})
                    messages.append({
                        "role": "tool",
                        "tool_call_id": tc['id'],
                        "content": json.dumps(result),
                    })
                continue
            # No tool calls: LLM gave a final answer
            return msg, tool_results_seen
        except Exception as e:
            return {'content': None, 'error': str(e)}, tool_results_seen
    return {'content': None, 'error': 'max_tool_rounds'}, tool_results_seen

_ADDR_RE = re.compile(r'0x[0-9a-fA-F]+')
def validate_no_invented_addresses(content, tool_results, original_prompt=None):
    """Reject LLM output that contains address literals NOT seen in tool results
    or in the original prompt. Returns (is_valid, list_of_invented_addrs).
    """
    if not content:
        return True, []
    allowed = set()
    # Collect from tool results
    for tr in tool_results:
        r = tr.get('result', {})
        if isinstance(r, dict):
            result = r.get('result')
            if isinstance(result, str):
                for m in _ADDR_RE.findall(result):
                    allowed.add(m.lower())
            elif isinstance(result, list):
                for item in result:
                    if isinstance(item, str):
                        for m in _ADDR_RE.findall(item):
                            allowed.add(m.lower())
            elif isinstance(result, dict):
                for v in result.values():
                    if isinstance(v, str):
                        for m in _ADDR_RE.findall(v):
                            allowed.add(m.lower())
        # Also allow tool inputs
        for v in tr.get('args', {}).values():
            if isinstance(v, str):
                for m in _ADDR_RE.findall(v):
                    allowed.add(m.lower())
    # Collect from original prompt (the LLM has seen this, may quote from it)
    if original_prompt:
        for m in _ADDR_RE.finditer(original_prompt):
            allowed.add(m.group(0).lower())
    # Find addresses in LLM output
    invented = []
    # Common sentinel values that are NOT memory addresses
    SENTINELS = {'0xffffffff', '0xfffffffe', '0xffffffffffffffff', '0xdeadbeef', '0xdeadc0de', '0xdeadc001'}
    # Normalize: keep both raw and stripped (no leading zeros) forms
    def _strip_zeros(s):
        if not s.startswith('0x'): return s
        body = s[2:].lstrip('0')
        return '0x' + (body if body else '0')
    allowed_normalized = set()
    for a in allowed:
        allowed_normalized.add(a)
        allowed_normalized.add(_strip_zeros(a))
    for m in _ADDR_RE.finditer(content):
        addr = m.group(0).lower()
        if addr in allowed_normalized or addr in SENTINELS:
            continue
        n = int(addr, 16)
        if n < 0x10000:
            continue
        # Skip non-memory values: 0xFF000000+ are often high-bit-set constants
        if n >= 0xff000000:
            continue
        invented.append(addr)
    return (len(invented) == 0), invented

def name_function(function_name, image, address, disasm_lines, behavioral_text, max_tool_rounds=6):
    """Use tool-use LLM to propose: name, parameter types, 1-line docstring.
    LLM may NOT compute addresses/offsets - it must use tools.
    Returns: dict with name, params, docstring, tool_calls
    """
    system = """You are reverse-engineering a WiFi firmware function. You have a set of tools to look up addresses, structs, registers, callers, and behavioral traces.

CRITICAL RULES:
1. You may NOT compute, derive, or invent any numeric address, offset, or size in your head. If you need an address/offset, call a tool.
2. If a tool result gives you an address (e.g., "0x40040000"), you may quote it back in your final answer.
3. If you need a struct field offset, call struct_field_offset. If you need a register name, call register_at.
4. Output ONLY a single JSON object as your final answer. No prose, no explanation, no code.
5. The JSON schema is exactly: {"name": "snake_case_name", "params": [{"type": "type_name", "purpose": "1-line"}], "docstring": "1-line description", "subsystem": "rf|mac|tx|rx|ke|scan|...|unknown"}

BE EFFICIENT: Make 3-5 tool calls max. Don't keep exploring forever. After 3-5 tool calls you should have enough to answer. If you find it has no behavioral trace and basic disasm, just give your best guess."""

    user = f"""Function: {function_name} (current anonymous name)
Image: {image}
Address: {address}

Disassembly (first 20 lines):
{chr(10).join(disasm_lines[:20])}

Behavioral trace (if available):
{behavioral_text or 'NO BEHAVIORAL TRACE'}

Propose: (a) a real function name based on what it does, (b) parameter types, (c) 1-line docstring, (d) subsystem. Use tools to verify your guesses (e.g., check find_callers, register_at, behavioral_mmio_summary)."""

    messages = [
        {"role": "system", "content": system},
        {"role": "user", "content": user},
    ]
    msg, tool_calls = call_api(messages, TOOL_SCHEMA, max_tokens=1500, max_tool_rounds=max_tool_rounds)
    content = msg.get('content') or ''
    if not content:
        return None, tool_calls, "no_content"
    # Validate: no invented addresses (allowed = tool_results + original prompt)
    is_valid, invented = validate_no_invented_addresses(content, tool_calls, user)
    if not is_valid:
        return None, tool_calls, f"invented_addrs:{','.join(invented[:5])}"
    # Try to parse JSON — find first '{' and balance braces
    start = content.find('{')
    if start < 0:
        return None, tool_calls, "no_json"
    depth = 0
    end = -1
    for i in range(start, len(content)):
        if content[i] == '{': depth += 1
        elif content[i] == '}':
            depth -= 1
            if depth == 0:
                end = i + 1
                break
    if end < 0:
        return None, tool_calls, "no_json"
    try:
        result = json.loads(content[start:end])
        return result, tool_calls, "ok"
    except Exception as e:
        return None, tool_calls, f"json_err:{e}"

if __name__ == "__main__":
    # Quick test: name uart_putc
    import sys
    sys.path.insert(0, str(REPO / "harness_v17"))
    disasm = v17tools.disasm_at("fmacfw_8800d80_h_u02_bin", "0x10d79c", 5)
    print("Disasm:", disasm)
    result, tool_calls, status = name_function(
        "uart_putc", "fmacfw_8800d80_h_u02_bin", "0x10d79c",
        disasm, "*(volatile uint32_t *)0x40032000 = c;"
    )
    print("Status:", status)
    print("Result:", json.dumps(result, indent=2) if result else None)
    print("Tool calls made:", len(tool_calls))
    for tc in tool_calls:
        print(f"  {tc['name']}({tc['args']})")
