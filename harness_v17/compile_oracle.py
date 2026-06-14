#!/usr/bin/env python3
"""v17 compilation oracle.

For each integrated function in the composed C, compile it to ARM, get the disasm,
and compare against the original binary's disasm. LLM uses tool-use to find
divergences and propose fixes.
"""
import json, sys, re, time
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor, as_completed

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "harness_v17"))
import tools as v17tools
from oracle import call_api, call_tool, TOOL_SCHEMA, validate_no_invented_addresses

def compare_function(function_name, image, addr, composed_text, original_disasm):
    """Use tool-use LLM to find divergences between mechanical (compiled) disasm
    and original disasm. Returns: list of {offset, divergence, proposed_fix}.
    LLM is NOT allowed to compute addresses.
    """
    system = """You are reviewing the output of a mechanical C->ARM compiler against the original disassembly.

You have tools to:
- read_dword, disasm_at: examine bytes
- decode_ldr_literal: decode PC-relative LDR pools
- behavioral_at: see behavioral trace
- mmio_write_c, mmio_read_c: get canonical MMIO patterns

CRITICAL RULES:
1. You may NOT compute addresses/offsets in your head. Call tools.
2. Compare line-by-line and find: (a) missing instructions, (b) extra instructions, (c) wrong register operands, (d) wrong immediate values
3. For each divergence, propose a fix as a HINT to the mechanical generator (not as code)
4. Output JSON: {"divergences": [{"offset": "0x...", "type": "missing|extra|wrong_op|wrong_imm", "original": "<orig insn>", "compiled": "<my insn>", "fix_hint": "1-line"}, ...], "match_pct": 0-100}
5. Output ONLY the JSON, no prose."""

    user = f"""Function: {function_name}
Image: {image}
Address: {addr}

ORIGINAL DISASSEMBLY (ground truth):
{chr(10).join(original_disasm[:30])}

MECHANICAL DISASSEMBLY (my C compiled to ARM):
{chr(10).join(composed_text[:30])}

Use tools to verify your findings. Output JSON."""

    messages = [
        {"role": "system", "content": system},
        {"role": "user", "content": user},
    ]
    msg, tool_calls = call_api(messages, TOOL_SCHEMA, max_tokens=2500, max_tool_rounds=10)
    content = msg.get('content') or ''
    if not content:
        return None, tool_calls, "no_content"
    is_valid, _ = validate_no_invented_addresses(content, tool_calls, user)
    if not is_valid:
        return None, tool_calls, "invented"
    # Parse JSON
    start = content.find('{')
    if start < 0: return None, tool_calls, "no_json"
    depth, end = 0, -1
    for i in range(start, len(content)):
        if content[i] == '{': depth += 1
        elif content[i] == '}':
            depth -= 1
            if depth == 0:
                end = i + 1
                break
    if end < 0: return None, tool_calls, "no_json"
    try:
        return json.loads(content[start:end]), tool_calls, "ok"
    except Exception as e:
        return None, tool_calls, f"json_err:{e}"

if __name__ == "__main__":
    # Test with uart_putc
    addr = "0x10d79c"
    img = "fmacfw_8800d80_h_u02_bin"
    fn = "uart_putc"
    orig = v17tools.disasm_at(img, addr, 5)
    print("Original disasm:")
    for l in orig: print(f"  {l}")
    # Compiled would be the actual ARM output of the C function
    compiled_lines = [
        "0x00000000      80b5           push {r7, lr}",
        "0x00000002      0148           ldr r0, [pc, #4]  ; 0xc",
        "0x00000004      0160           str r1, [r0]",
        "0x00000006      80bd           pop {r7, pc}",
    ]
    print("\n=== Running compare ===")
    result, tcs, status = compare_function(fn, img, addr, compiled_lines, orig)
    print(f"Status: {status}")
    print(f"Result: {json.dumps(result, indent=2) if result else None}")
    print(f"Tool calls: {len(tcs)}")
