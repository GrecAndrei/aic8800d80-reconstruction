#!/usr/bin/env python3
"""v17 tool-use LLM harness.

The LLM is given a task + tool schema. It must:
1. Call tools to gather context (no math in its head)
2. Output a structured JSON response

The harness validates that any address literal in the LLM's response
matches a tool-call result, not an LLM-invented value.
"""
import json, os, re, subprocess, sys, time, threading, urllib.request, uuid
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor, as_completed

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "harness_v17"))
import tools as v17tools
from tools import TOOL_SCHEMA, call_tool

DEFAULT_BASE_URL = "https://token-plan.ap-southeast-1.maas.aliyuncs.com/compatible-mode/v1"
DEFAULT_MODEL = "qwen4-max-preview"
DEFAULT_REASONING_EFFORT = "max"
DEFAULT_USER_AGENT = "aic8800d80-pipeline/1.0"
_SESSION_ID = os.environ.get("OPENCODE_SESSION_ID") or f"ses_{uuid.uuid4().hex}"

# Static >=1,200-token AIC8800D80 firmware reference prefix shared across all
# function-naming calls so Alibaba Token Plan / DashScope hits prompt cache
# (>=1,024-token prefix threshold) on every call.
STATIC_FIRMWARE_SYSTEM_PREFIX = """You are a senior embedded WiFi/Bluetooth firmware reverse engineer specializing in ARM Cortex-M4 Thumb-2 wireless SoC firmware, specifically the AIC8800D80 (Marvell 88W8800 / RivieraWaves RW-NX MAC + LMAC/FMAC split) wireless chipset.

=== TARGET PLATFORM & FIRMWARE ARCHITECTURE ===
1. CPU & ABI:
   - ARM Cortex-M4F (ARMv7E-M, Thumb-2 instruction set, little-endian, 32-bit pointers, VFPv4-SP).
   - AAPCS calling convention: r0..r3 carry arguments a1..a4; r0 (or r0:r1 for 64-bit) returns the result.
   - Four firmware images exist in this repository:
     * fmacfw_8800d80_h_u02_bin: FullMAC WiFi host-interface variant (SDIO/USB high-throughput host offload, ~340 KB).
     * fmacfw_8800d80_u02_bin: FullMAC WiFi standard variant (802.11a/b/g/n/ac/ax MAC, SME/MLME, STA/AP/P2P, ~340 KB).
     * fmacfwbt_8800d80_u02_bin: FullMAC WiFi + Bluetooth/BLE coexistence firmware (adds BT/BLE controller, HCI, PTA coex, ~340 KB).
     * lmacfw_rf_8800d80_u02_bin: LowerMAC + RF test/calibration firmware (PHY/RF front-end, TX/RX calibration, DPD/IQ/LO/DCOC, ~220 KB).
   - Hardware runtime load base is 0x120000; static analysis / decompiled symbols use analysis-space base 0x100000 (file_offset + 0x100000).
   - Peripheral MMIO occupies 0x40000000..0x60000000:
     * 0x40032000: UART / console TX/RX/status registers (0x40032000 data, 0x40032014 status).
     * 0x40100000..0x401fffff: System control, PMU, clock/PLL, GPIO, IOMUX, reset/power gating.
     * 0x40200000..0x402fffff: RF front-end / analog bus / calibration registers (0x40200014 rf_bus_reset_status, 0x40200900+ RF bus).
     * 0x40300000..0x403fffff: RivieraWaves RW-NX MAC-HW, PHY/MDM registers, tick counter (0x40320120 rf_tick_counter).
     * 0x40500000..0x405fffff: Timers (0x40501010 timer_value), watchdog, IPC, DMA, SDIO/USB host controller, crypto/AES/CCMP/GCMP/TKIP.
     * 0x40600000+: Bluetooth / BLE baseband, modem, and WiFi/BT PTA coexistence registers.

2. CORE FIRMWARE SUBSYSTEMS & FUNCTION NAMING CONVENTIONS:
   - rf: RF transceiver control, PLL/synth tuning, TX/RX gain tables, IQ/DCOC/LO/DPD calibration, PA/LNA/FEM switching, thermal compensation, RF bus read/write/poll helpers.
   - mac: 802.11 MAC management (MM/ME/SM/APM/VIF/STA), beacon/TIM/DTIM handling, TSF/TBTT, channel context switching, power save (PS/U-APSD/TWT), rate control (RC), Block Ack (BAM).
   - tx: TX descriptor preparation (txl/txd/tx_hd/tx_pbd), A-MPDU aggregation, EDCA/AC queues, TX confirmation (tx_cfm), TX power control (TPC), frame header/QoS/HT/VHT/HE building.
   - rx: RX descriptor ring management (rxl/rxd/rx_hd/rx_swdesc), defragmentation, reorder buffer, RX vector parsing, management/control/data frame dispatch, promiscuous/monitor mode.
   - ke: RivieraWaves kernel event loop (ke_event, ke_msg, ke_task, ke_timer, ke_state), dynamic heap allocator (ke_malloc/ke_free), singly/doubly linked lists (co_list).
   - scan: Active/passive channel scanning (scan/scanu), Probe Request generation, Probe Response/Beacon parsing, IE parsing, BSS table updates.
   - bt: Bluetooth Classic / BLE controller, HCI command/event/ACL/SCO packet handlers, LMP/LL state machines, inquiry/page/advertising/scanning, WiFi/BT PTA coexistence.
   - sec / crypto: Hardware cipher key table management, WEP/TKIP/CCMP/GCMP/BIP key install/remove, PN/IV replay checks, MFP/PMF.
   - ipc: Host-to-embedded and embedded-to-host IPC rings, SDIO/USB/SPI host transport, mailbox/interrupt signaling, firmware message/data forwarding.
   - patch: Boot ROM patch table installation, patch jump hooks, ROM callback table initialization, OTP/efuse/NVRAM config loading.
   - mmio: Low-level hardware register polling, bitfield read-modify-write, peripheral clock/reset/IRQ enable/disable, DMA/GPIO/UART/timer drivers.
   - util: Compiler/libc/EABI helpers (memcpy, memset, memcmp, strlen, sprintf/vsnprintf, __aeabi_* float/double/div), CRC/checksum, bitmask/ring-buffer utilities.

3. NAMING QUALITY RULES:
   - Always produce a descriptive, idiomatic C snake_case identifier reflecting the function's subsystem and action (e.g., rf_iq_cal_apply, vif_chan_ctxt_link, txl_cfm_evt_handle, ke_timer_schedule, sdio_rx_buf_push, bt_hci_cmd_dispatch).
   - NEVER output generic placeholder names such as sub_*, unknown_*, func_*, bad_func_*, unnamed_*, or raw hex addresses as the function name.
   - Keep names concise (2-5 snake_case words, <= 40 characters) and valid C identifiers matching ^[a-z][a-z0-9_]*$.
   - You may NEVER compute, derive, or invent any numeric address, offset, or size in your head. Only quote addresses that appear verbatim in the prompt or in a tool result."""

_CACHE_LOCK = threading.Lock()
CACHE_STATS = {"calls": 0, "prompt_tokens": 0, "cached_tokens": 0}


def get_cache_stats():
    with _CACHE_LOCK:
        return dict(CACHE_STATS)


def _record_usage(completion):
    usage = getattr(completion, "usage", None)
    if not usage:
        return
    ptok = getattr(usage, "prompt_tokens", 0) or 0
    details = getattr(usage, "prompt_tokens_details", None)
    ctok = (getattr(details, "cached_tokens", 0) if details else 0) or 0
    if not ctok:
        ctok = getattr(usage, "cache_read_input_tokens", 0) or 0
    with _CACHE_LOCK:
        CACHE_STATS["calls"] += 1
        CACHE_STATS["prompt_tokens"] += int(ptok)
        CACHE_STATS["cached_tokens"] += int(ctok)


def _apply_prompt_cache(messages, enabled=True):
    if not enabled or not messages:
        return messages
    out = list(messages)
    first = out[0]
    if first.get("role") == "system" and isinstance(first.get("content"), str) and first["content"]:
        out[0] = {
            "role": "system",
            "content": [{
                "type": "text",
                "text": first["content"],
                "cache_control": {"type": "ephemeral"},
            }],
        }
    return out


def _load_keys():
    keys_path = REPO / "harness_v15/keys/keys.json"
    if keys_path.exists():
        try:
            providers = json.loads(keys_path.read_text()).get("providers", [])
            if providers:
                return providers
        except Exception:
            pass
    env_key = (
        os.environ.get("DASHSCOPE_API_KEY")
        or os.environ.get("BAILIAN_API_KEY")
        or os.environ.get("ALIBABA_API_KEY")
        or os.environ.get("OPENCODE_API_KEY")
        or os.environ.get("AIC8800D80_LLM_KEY_1")
    )
    if env_key:
        return [{
            "name": "env_default",
            "base_url": DEFAULT_BASE_URL,
            "api_key": env_key,
            "model": DEFAULT_MODEL,
            "reasoning_effort": DEFAULT_REASONING_EFFORT,
            "prompt_cache": True,
        }]
    return []


KEYS = _load_keys()
_local = threading.local()
def get_key():
    if not KEYS:
        raise RuntimeError("No LLM API providers configured in harness_v15/keys/keys.json or DASHSCOPE_API_KEY")
    if not hasattr(_local, 'i'):
        _local.i = 0
    k = KEYS[_local.i % len(KEYS)]
    _local.i += 1
    return k


def _get_client(api_key, base_url, sid):
    from openai import OpenAI
    pool = getattr(_local, "clients", None)
    if pool is None:
        pool = {}
        _local.clients = pool
    ckey = (base_url, api_key, sid)
    client = pool.get(ckey)
    if client is None:
        headers = {"User-Agent": DEFAULT_USER_AGENT}
        if "opencode.ai" in base_url:
            headers["x-opencode-session"] = sid
        client = OpenAI(
            api_key=api_key,
            base_url=base_url,
            default_headers=headers,
            timeout=None,
            max_retries=5,
        )
        pool[ckey] = client
    return client

def call_api(messages, tools, max_tokens=None, temperature=0.0, max_tool_rounds=6, reasoning_effort=None, session_id=None):
    """Call LLM with tools via the OpenAI SDK. Loops until LLM gives a final
    answer or hits max_tool_rounds.
    Returns (final_message_dict, all_tool_calls_made).

    Uses persistent thread-local keep-alive clients, explicit prompt caching on
    the leading system block, no output cap (max_tokens omitted), and no HTTP
    timeout (timeout=None).
    """
    key = get_key()
    base_url = key.get('base_url', DEFAULT_BASE_URL).rstrip('/')
    model = key.get('model', DEFAULT_MODEL)
    effort = reasoning_effort if reasoning_effort is not None else key.get('reasoning_effort', DEFAULT_REASONING_EFFORT)
    prompt_cache = key.get('prompt_cache', True)
    sid = session_id or _SESSION_ID
    client = _get_client(key['api_key'], base_url, sid)
    messages = _apply_prompt_cache(messages, enabled=prompt_cache)
    tool_results_seen = []  # collect every tool result for validation
    for round_n in range(max_tool_rounds + 1):
        # On the last round, force a final answer (no tools)
        is_final_round = (round_n == max_tool_rounds)
        try:
            kwargs = {
                "model": model,
                "messages": messages,
                "temperature": temperature,
            }
            if effort:
                kwargs["reasoning_effort"] = effort
            if max_tokens is not None:
                kwargs["max_tokens"] = max_tokens
            if tools and not is_final_round:
                kwargs["tools"] = tools
            if is_final_round:
                # Force a final answer
                messages.append({
                    "role": "user",
                    "content": "STOP using tools. Output your final JSON answer NOW based on what you've seen. No more tool calls."
                })
            completion = None
            for attempt in range(4):
                completion = client.chat.completions.create(**kwargs)
                _record_usage(completion)
                msg = completion.choices[0].message
                if msg.tool_calls or (msg.content and msg.content.strip()):
                    break
                if attempt < 3:
                    time.sleep(2 ** attempt)
            msg = completion.choices[0].message
            if msg.tool_calls and not is_final_round:
                # Execute each tool call
                assistant_msg = {
                    "role": "assistant",
                    "content": msg.content,
                    "tool_calls": [tc.model_dump(exclude_none=True) for tc in msg.tool_calls],
                }
                rc = getattr(msg, "reasoning_content", None)
                if rc:
                    assistant_msg["reasoning_content"] = rc
                messages.append(assistant_msg)
                for tc in msg.tool_calls:
                    fn_name = tc.function.name
                    try:
                        fn_args = json.loads(tc.function.arguments)
                    except Exception:
                        fn_args = {}
                    result = call_tool(fn_name, fn_args)
                    tool_results_seen.append({'name': fn_name, 'args': fn_args, 'result': result})
                    messages.append({
                        "role": "tool",
                        "tool_call_id": tc.id,
                        "content": json.dumps(result),
                    })
                continue
            # No tool calls: LLM gave a final answer
            return {"content": msg.content, "tool_calls": msg.tool_calls}, tool_results_seen
        except Exception as e:
            return {'content': None, 'error': str(e)}, tool_results_seen
    return {'content': None, 'error': 'max_tool_rounds'}, tool_results_seen

_ADDR_RE = re.compile(r'0x[0-9a-fA-F]+')
def _collect_addrs(obj, allowed):
    if isinstance(obj, str):
        for m in _ADDR_RE.findall(obj):
            allowed.add(m.lower())
    elif isinstance(obj, dict):
        for v in obj.values():
            _collect_addrs(v, allowed)
    elif isinstance(obj, (list, tuple)):
        for item in obj:
            _collect_addrs(item, allowed)


def validate_no_invented_addresses(content, tool_results, original_prompt=None):
    """Reject LLM output that contains address literals NOT seen in tool results
    or in the original prompt. Returns (is_valid, list_of_invented_addrs).
    """
    if not content:
        return True, []
    allowed = set()
    _collect_addrs(tool_results, allowed)
    if original_prompt:
        _collect_addrs(original_prompt, allowed)
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
    system = STATIC_FIRMWARE_SYSTEM_PREFIX + """

=== SINGLE-FUNCTION TOOL-USE MODE ===
You have a set of tools to look up addresses, structs, registers, callers, and behavioral traces.
1. If you need a struct field offset, call struct_field_offset. If you need a register name, call register_at.
2. Output ONLY a single JSON object as your final answer. No prose, no explanation, no code.
3. The JSON schema is exactly: {"name": "snake_case_name", "params": [{"type": "type_name", "purpose": "1-line"}], "docstring": "1-line description", "subsystem": "rf|mac|tx|rx|ke|scan|bt|sec|ipc|patch|mmio|util|unknown"}
4. BE EFFICIENT: Make 3-5 tool calls max. After 3-5 tool calls you should have enough to answer."""

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
    msg, tool_calls = call_api(messages, TOOL_SCHEMA, max_tool_rounds=max_tool_rounds)
    content = msg.get('content') or ''
    if not content:
        return None, tool_calls, "no_content"
    # Validate: no invented addresses (allowed = tool_results + system/user prompt)
    is_valid, invented = validate_no_invented_addresses(content, tool_calls, system + "\n" + user)
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
