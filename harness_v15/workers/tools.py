#!/usr/bin/env python3
"""Tools the worker exposes to the model via function calling.

Each tool is a Python function the model can invoke. The worker handles
the call, returns the result, and the model iterates.
"""
import json
import os
import re
import subprocess
import sys
import tempfile
from pathlib import Path

# ANSI escape strip
ANSI_RE = re.compile(r"\x1b\[[0-9;]*m")


def _strip_ansi(s: str) -> str:
    return ANSI_RE.sub("", s)


def python_exec(code: str, timeout: float = 10.0, max_chars: int = 4000) -> str:
    """Execute Python code in a subprocess. Returns stdout+stderr (truncated)."""
    try:
        result = subprocess.run(
            [sys.executable, "-c", code],
            capture_output=True,
            text=True,
            timeout=timeout,
            cwd="/tmp",
        )
        out = (result.stdout or "") + (result.stderr or "")
        if len(out) > max_chars:
            out = out[:max_chars] + f"\n[... truncated, {len(out) - max_chars} more chars ...]"
        if not out:
            out = "[no output]"
        return f"exit={result.returncode}\n{out}"
    except subprocess.TimeoutExpired:
        return f"[python timeout after {timeout}s]"
    except Exception as e:
        return f"[python error: {type(e).__name__}: {e}]"


def r2_cmd(cmd: str, binary: Path, load_base: int = 0x120000, timeout: float = 30.0,
           max_chars: int = 8000) -> str:
    """Run an r2 command on the binary. Returns stripped output (truncated)."""
    full_cmd = [
        "r2", "-q", "-A", "-a", "arm", "-b", "16", "-m", f"0x{load_base:x}",
        "-c", cmd,
        str(binary),
    ]
    try:
        result = subprocess.run(full_cmd, capture_output=True, text=True, timeout=timeout)
        out = _strip_ansi((result.stdout or "") + (result.stderr or ""))
        if len(out) > max_chars:
            out = out[:max_chars] + f"\n[... truncated, {len(out) - max_chars} more chars ...]"
        if not out:
            out = "[no output]"
        return out
    except subprocess.TimeoutExpired:
        return f"[r2 timeout after {timeout}s]"
    except FileNotFoundError:
        return "[r2 not found in PATH]"
    except Exception as e:
        return f"[r2 error: {type(e).__name__}: {e}]"


def read_bytes(offset: int, length: int, binary: Path, max_chars: int = 2000) -> str:
    """Read raw bytes from the binary at file offset. Returns hex dump."""
    try:
        with open(binary, "rb") as f:
            f.seek(offset)
            data = f.read(length)
        # Hex dump: offset: hex hex hex hex  |ascii|
        lines = []
        for i in range(0, len(data), 16):
            chunk = data[i:i+16]
            hex_part = " ".join(f"{b:02x}" for b in chunk)
            ascii_part = "".join(chr(b) if 32 <= b < 127 else "." for b in chunk)
            lines.append(f"{offset+i:08x}  {hex_part:<48s}  |{ascii_part}|")
        out = "\n".join(lines)
        if len(out) > max_chars:
            out = out[:max_chars] + f"\n[... truncated ...]"
        return out
    except Exception as e:
        return f"[read error: {e}]"


def get_composed_fn(name: str, composed_path: Path) -> str:
    """Get the body of a function from the composed file."""
    if not composed_path.exists():
        return f"[composed file not found: {composed_path}]"
    text = composed_path.read_text(errors="replace")
    # Find `void name(... ) { ... }` with brace counting
    pat = re.compile(rf"^void\s+{re.escape(name)}\s*\([^)]*\)\s*\{{", re.MULTILINE)
    m = pat.search(text)
    if not m:
        return f"[function '{name}' not found in composed file]"
    start = m.end() - 1
    depth = 0
    pos = start
    while pos < len(text):
        if text[pos] == "{":
            depth += 1
        elif text[pos] == "}":
            depth -= 1
            if depth == 0:
                return text[m.start():pos+1]
        pos += 1
    return "[could not extract function body]"


def find_symbols(pattern: str, composed_path: Path, max_n: int = 100) -> str:
    """Find function names in the composed file matching a regex pattern."""
    if not composed_path.exists():
        return f"[composed file not found: {composed_path}]"
    text = composed_path.read_text(errors="replace")
    try:
        rx = re.compile(pattern)
    except re.error as e:
        return f"[bad regex: {e}]"
    matches = sorted(set(m.group(1) for m in re.finditer(r"^void\s+(\w+)\s*\(", text, re.MULTILINE) if rx.search(m.group(1))))
    if not matches:
        return f"[no symbols matching /{pattern}/]"
    if len(matches) > max_n:
        matches = matches[:max_n] + [f"... ({len(matches) - max_n} more)"]
    return "\n".join(matches)


# OpenAI-compatible tool definitions
TOOL_DEFS = [
    {
        "type": "function",
        "function": {
            "name": "python_exec",
            "description": "Execute Python code in a sandboxed subprocess (cwd=/tmp, no network). Use to validate C syntax, compute bit operations, check addresses, transform code. Returns exit code + stdout+stderr.",
            "parameters": {
                "type": "object",
                "properties": {
                    "code": {
                        "type": "string",
                        "description": "Python code to execute",
                    }
                },
                "required": ["code"],
            },
        },
    },
    {
        "type": "function",
        "function": {
            "name": "r2_cmd",
            "description": "Run an r2 command on the loaded binary. ARM Thumb, big-endian, loaded at 0x120000. Examples: 'pdf @ 0x122adc' (disasm function), 'axt @ 0x122adc' (xrefs to this addr), 'afl~crypto' (functions matching), 'iS' (sections), 'iz' (strings), 'px 64 @ 0x122adc' (hex dump).",
            "parameters": {
                "type": "object",
                "properties": {
                    "cmd": {
                        "type": "string",
                        "description": "r2 command to run",
                    }
                },
                "required": ["cmd"],
            },
        },
    },
    {
        "type": "function",
        "function": {
            "name": "read_bytes",
            "description": "Read raw bytes from the binary at a file offset. Returns hex+ASCII dump. Use to inspect instruction encodings, constant pools, data tables.",
            "parameters": {
                "type": "object",
                "properties": {
                    "offset": {"type": "integer", "description": "File offset in bytes"},
                    "length": {"type": "integer", "description": "Number of bytes (max 256)"},
                },
                "required": ["offset", "length"],
            },
        },
    },
    {
        "type": "function",
        "function": {
            "name": "get_composed_fn",
            "description": "Get the body of a named function from the project's composed C file. Use to see how the project currently models a callee, including which other functions it calls.",
            "parameters": {
                "type": "object",
                "properties": {
                    "name": {"type": "string", "description": "Function name to look up"},
                },
                "required": ["name"],
            },
        },
    },
    {
        "type": "function",
        "function": {
            "name": "find_symbols",
            "description": "Find function names in the composed file matching a regex. Use to discover what helper functions exist (e.g., 'crypto_.*', 'rf_bus.*', 'timer_.*').",
            "parameters": {
                "type": "object",
                "properties": {
                    "pattern": {"type": "string", "description": "Regex pattern (e.g., 'crypto_.*', '^rf_bus_mark$')"},
                },
                "required": ["pattern"],
            },
        },
    },
]


def execute_tool(name: str, args_json: str, *, binary: Path, composed_path: Path) -> str:
    """Dispatch a tool call to its handler. Returns the result string."""
    try:
        args = json.loads(args_json)
    except json.JSONDecodeError:
        return f"[bad tool args: {args_json[:200]}]"

    if name == "python_exec":
        return python_exec(args.get("code", ""))
    if name == "r2_cmd":
        return r2_cmd(args.get("cmd", ""), binary)
    if name == "read_bytes":
        # Tolerate string hex like "0x9d8" or int
        raw_offset = args.get("offset", 0)
        if isinstance(raw_offset, str):
            offset = int(raw_offset, 16) if raw_offset.startswith("0x") else int(raw_offset)
        else:
            offset = int(raw_offset)
        raw_length = args.get("length", 0)
        if isinstance(raw_length, str):
            length = int(raw_length, 16) if raw_length.startswith("0x") else int(raw_length)
        else:
            length = int(raw_length)
        length = min(length, 256)
        return read_bytes(offset, length, binary)
    if name == "get_composed_fn":
        return get_composed_fn(args.get("name", ""), composed_path)
    if name == "find_symbols":
        return find_symbols(args.get("pattern", ""), composed_path)
    return f"[unknown tool: {name}]"


if __name__ == "__main__":
    # Smoke test
    print("python_exec(1+1):", python_exec("print(1+1)"))
