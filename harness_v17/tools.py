#!/usr/bin/env python3
"""v17 tool library: deterministic tools for LLM tool-use.

The LLM may ONLY use these tools to learn anything about addresses, offsets,
sizes, register names, call graph, or behavioral traces. The LLM must NEVER
compute, derive, or reason about any numeric value itself.

Every tool returns Python-native types (int, str, list, dict).
All addresses are 0x-prefixed hex strings.
"""
import json, re, subprocess, struct
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
FW_DIR = REPO / "inputs/firmware"
BEHAVIORAL_DIR = REPO / "artifacts/releases/aic8800d80-rebuild-v1/synth"

# Cached binary contents
_BIN_CACHE = {}
def _bin(name):
    if name not in _BIN_CACHE:
        # Some image names have trailing "_bin" suffix; strip it
        if name.endswith("_bin"):
            name = name[:-4]
        if name not in _BIN_CACHE:
            _BIN_CACHE[name] = (FW_DIR / f"{name}.bin").read_bytes()
    return _BIN_CACHE[name]

# Cached behavioral lookup: (image, function_name) -> (address, body)
_BEHAV_CACHE = {}
def _behav(image, fn):
    key = (image, fn)
    if key in _BEHAV_CACHE:
        return _BEHAV_CACHE[key]
    # image may have trailing _bin suffix; strip it
    img = image[:-4] if image.endswith("_bin") else image
    f = BEHAVIORAL_DIR / f"{fn}__{img}.synth.c"
    if not f.exists():
        _BEHAV_CACHE[key] = None
        return None
    _BEHAV_CACHE[key] = f.read_text()
    return _BEHAV_CACHE[key]

# Cached function index: (image, name) -> address
_FN_INDEX = {}
def _load_fn_index():
    if _FN_INDEX: return
    p = REPO / "harness_v16/all_fns.json"
    if p.exists():
        for d in json.load(open(p)):
            img = d.get('image', '')
            name = d.get('name', '')
            addr = d.get('address', '')
            if name and img:
                _FN_INDEX[(img, name)] = addr
        return
    # Fallback: scan composed C
    pass

def addr_to_file_offset(image, addr):
    """Convert chip runtime address to file offset.
    chip_runtime = 0x100000 + file_offset, so file_offset = chip_runtime - 0x100000."""
    a = int(addr, 16) if isinstance(addr, str) else addr
    return a - 0x100000

def file_offset_to_chip_addr(off):
    return 0x100000 + off

# === MEMORY TOOLS (raw read) ===

def read_byte(image, addr):
    """Read 1 byte at chip runtime address."""
    off = addr_to_file_offset(image, addr)
    if off < 0 or off >= len(_bin(image)):
        return None
    return _bin(image)[off]

def read_dword(image, addr):
    """Read 4 bytes (little-endian) at chip runtime address. Returns 0x... string."""
    off = addr_to_file_offset(image, addr)
    if off < 0 or off + 4 > len(_bin(image)):
        return None
    val = struct.unpack('<I', _bin(image)[off:off+4])[0]
    return f"0x{val:08x}"

def read_word(image, addr):
    """Read 2 bytes (little-endian) at chip runtime address. Returns 0x... string."""
    off = addr_to_file_offset(image, addr)
    if off < 0 or off + 2 > len(_bin(image)):
        return None
    val = struct.unpack('<H', _bin(image)[off:off+2])[0]
    return f"0x{val:04x}"

def read_string_at(image, addr, max_len=128):
    """Read NUL-terminated ASCII string at chip runtime address."""
    off = addr_to_file_offset(image, addr)
    if off < 0 or off >= len(_bin(image)):
        return None
    raw = _bin(image)[off:off+max_len]
    end = raw.find(b'\x00')
    if end >= 0:
        raw = raw[:end]
    try:
        return raw.decode('ascii')
    except UnicodeDecodeError:
        return None

# === DISASSEMBLY TOOLS (r2-backed) ===

_ANSI = re.compile(r'\x1b\[[0-9;]*m')

def disasm_at(image, addr, n=30):
    """Disassemble N instructions at chip runtime address. Returns list of instruction lines."""
    img = image[:-4] if image.endswith("_bin") else image
    cmd = ["r2", "-q", "-a", "arm", "-b", "16", "-m", "0x100000", "-2",
           "-c", f"s {addr}; pd {n}", str(FW_DIR / f"{img}.bin")]
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=15)
        out = _ANSI.sub('', result.stdout).strip()
        lines = [l.strip() for l in out.split('\n') if l.strip().startswith('0x')]
        return lines
    except Exception:
        return []

def decode_ldr_literal(image, ldr_addr):
    """Decode a PC-relative LDR literal at the given address.
    Returns the actual value that would be loaded. The LLM MUST use this
    instead of computing the offset itself.
    """
    lines = disasm_at(image, ldr_addr, 1)
    if not lines:
        return None
    # Parse: "0x10d7a4      024b           ldr r3, [0x0010d7b0]        ; [0x10d7b0:4]=0x40032000"
    m = re.search(r'\[(0x[0-9a-fA-F]+)\]', lines[0])
    if not m:
        return None
    target = int(m.group(1), 16)
    return read_dword(image, f"0x{target:x}")

def decode_constant_pool(image, addr, n_words=4):
    """Decode a literal pool starting at addr. Returns list of dwords."""
    return [read_dword(image, f"0x{addr_to_file_offset(image, addr) + 4*i + 0x100000:x}")
            for i in range(n_words)]

# === REGISTER DATABASE (built from binary MMIO patterns) ===

# Build MMIO register map by scanning binary for STR/STRB/LDR to 0x40000000-0x60000000
_REGISTER_MAP = None
def _build_register_map():
    global _REGISTER_MAP
    if _REGISTER_MAP is not None:
        return _REGISTER_MAP
    addrs = set()
    # Find LDR pc-relative loads that target 0x40000000-0x60000000 range (MMIO)
    # and constant pool values in that range.
    for img in ["fmacfw_8800d80_h_u02", "fmacfw_8800d80_u02",
                "fmacfwbt_8800d80_u02", "lmacfw_rf_8800d80_u02"]:
        bin_data = _bin(img)
        # Look for uint32_t values in 0x40000000-0x60000000 range in constant pool
        for off in range(0, len(bin_data) - 4, 2):
            v = int.from_bytes(bin_data[off:off+4], 'little')
            if 0x40000000 <= v < 0x60000000 and (v & 0xfff) < 0x1000:
                # Looks like an MMIO register address
                addrs.add(v)
    pages = {}
    for a in addrs:
        page = (a >> 16) & 0xffff
        pages.setdefault(page, []).append(a)
    # Heuristic: only keep pages with >5 distinct addresses (real register pages, not noise)
    real_pages = {p: v for p, v in pages.items() if len(v) > 5}
    _REGISTER_MAP = {
        'pages': {f"0x{p:04x}": len(v) for p, v in real_pages.items()},
        'all_addrs': sorted(addrs),
    }
    return _REGISTER_MAP

def register_at(addr):
    """Return a name suggestion for an MMIO address based on the register page.
    Format: REG_<PAGE>_<OFFSET> where page is the 16-bit page number.
    The LLM may rename these but must not invent the address itself.
    """
    a = int(addr, 16) if isinstance(addr, str) else addr
    page = (a >> 16) & 0xffff
    off = a & 0xffff
    return f"REG_{page:04x}_{off:04x}"

def registers_in_page(page_hex):
    """Return all known MMIO addresses within a 64K page."""
    m = _build_register_map()
    page = int(page_hex, 16) if isinstance(page_hex, str) else page_hex
    return [f"0x{a:x}" for a in m.get('all_addrs', [])
            if ((a >> 16) & 0xffff) == page]

# === STRUCT DATABASE ===
# The LLM picks struct/field names; we manage the offsets in a known table.

_STRUCTS = {
    # Common CoPilot/WiFi firmware struct field conventions
    'vif_info': {
        'idx': 0, 'flags': 4, 'mac_addr': 8, 'bssid': 14,
        'ssid': 20, 'channel': 52, 'band': 56, 'type': 60,
        'state': 64, 'tx_power': 68,
    },
    'tx_queue': {
        'head': 0, 'tail': 4, 'count': 8, 'lock': 12, 'max_len': 16,
    },
    'rx_desc': {
        'addr': 0, 'len': 4, 'status': 8, 'next': 12,
    },
    'tx_desc': {
        'addr': 0, 'len': 4, 'ctrl': 8, 'next': 12, 'status': 16,
    },
    'ke_env': {
        'task_head': 0, 'task_tail': 4, 'msg_queue': 8, 'state': 16,
    },
    'scan_req': {
        'ssid': 0, 'ssid_len': 32, 'channels': 36, 'n_channels': 100, 'flags': 104,
    },
}

def struct_field_offset(struct_name, field_name):
    """Return the offset of a field in a struct, as a 0x... string.
    The LLM picks the names; we return the offset. The LLM MUST NOT compute offsets itself.
    """
    s = _STRUCTS.get(struct_name)
    if s is None:
        return None
    off = s.get(field_name)
    if off is None:
        return None
    return f"0x{off:x}"

def struct_size(struct_name):
    """Return the size of a struct in bytes."""
    s = _STRUCTS.get(struct_name)
    if s is None:
        return None
    if not s:
        return "0x0"
    return f"0x{max(s.values()) + 4:x}"

def arr_offset(elem_size, index):
    """Return elem_size * index as a 0x... string.
    The LLM MUST NOT do pointer arithmetic itself.
    """
    if not isinstance(elem_size, int):
        return None
    if not isinstance(index, int):
        return None
    return f"0x{elem_size * index:x}"

# === MMIO CODE GENERATORS (canonical patterns) ===

def mmio_write_c(addr, val='val', width='uint32_t'):
    """Return canonical C code for a memory-mapped register write.
    The address MUST come from a tool call (read_dword, register_at, etc).
    """
    reg = register_at(addr)
    a = int(addr, 16) if isinstance(addr, str) else addr
    return f"  *((volatile {width} *)(uintptr_t)0x{a:08x}) = {val};  /* {reg} */"

def mmio_read_c(addr, var='val', width='uint32_t'):
    """Return canonical C code for a memory-mapped register read."""
    reg = register_at(addr)
    a = int(addr, 16) if isinstance(addr, str) else addr
    return f"  {var} = *((volatile {width} *)(uintptr_t)0x{a:08x});  /* {reg} */"

def mmio_poll_c(addr, mask='mask', width='uint32_t'):
    """Return canonical C code for a busy-wait poll."""
    reg = register_at(addr)
    a = int(addr, 16) if isinstance(addr, str) else addr
    return f"  while (!(*((volatile {width} *)(uintptr_t)0x{a:08x}) & {mask}));  /* poll {reg} */"

# === CALL GRAPH TOOLS ===

def find_callers(function_name, image=None):
    """Find all callers of a function. Returns list of (caller_name, caller_addr)."""
    _load_fn_index()
    callers = []
    for f in BEHAVIORAL_DIR.glob(f"*{function_name}*__*.synth.c"):
        # Crude: search for the function name in other behavioral files
        for other in BEHAVIORAL_DIR.glob("*.synth.c"):
            if other == f:
                continue
            text = other.read_text()
            if function_name in text:
                # extract function name from filename
                fn = other.name.split('__')[0]
                callers.append(fn)
                break
    return list(set(callers))[:20]

def find_callees(function_name, image):
    """Find all functions called by this function. Returns list of callee names."""
    text = _behav(image, function_name)
    if not text:
        return []
    # Match identifiers in the body
    fns = []
    for m in re.finditer(r'\b([a-z][a-z0-9_]{2,})\s*\(', text):
        fns.append(m.group(1))
    # Filter out C keywords
    KW = {'if', 'for', 'while', 'switch', 'return', 'sizeof', 'memcpy', 'memset',
          'strlen', 'strcpy', 'malloc', 'free', 'assert', 'printf', 'snprintf',
          'sprintf', 'memcmp', 'strcmp'}
    return [f for f in fns if f not in KW][:20]

def xref_to(image, addr):
    """Find cross-references to an address."""
    img = image[:-4] if image.endswith("_bin") else image
    # Use r2 for xrefs
    a = int(addr, 16) if isinstance(addr, str) else addr
    cmd = ["r2", "-q", "-a", "arm", "-b", "16", "-m", "0x100000", "-2",
           "-c", f"axt 0x{a:x}", str(FW_DIR / f"{img}.bin")]
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=15)
        out = _ANSI.sub('', result.stdout).strip()
        return [l.strip() for l in out.split('\n') if l.strip().startswith('0x')][:20]
    except Exception:
        return []

# === BEHAVIORAL TOOLS ===

def behavioral_at(function_name, image):
    """Get the behavioral trace (synthesized C body) for a function."""
    text = _behav(image, function_name)
    if not text:
        return None
    return text

def behavioral_mmio_summary(function_name, image):
    """Get a summary of all MMIO accesses in a function's behavioral trace."""
    text = _behav(image, function_name)
    if not text:
        return None
    addrs = []
    pat = re.compile(r'\(uintptr_t\)\s*(0x[0-9a-fA-F]+)')
    for m in pat.finditer(text):
        addrs.append(m.group(1))
    return {
        'unique_addrs': sorted(set(addrs)),
        'access_count': len(addrs),
        'unique_count': len(set(addrs)),
    }

# === TOOL SCHEMA (for LLM function calling) ===

TOOL_SCHEMA = [
    {
        "type": "function",
        "function": {
            "name": "read_dword",
            "description": "Read 4 bytes (little-endian) at a chip runtime address. Returns '0x...' string. USE THIS to learn the value at an address; do NOT compute it yourself.",
            "parameters": {
                "type": "object",
                "properties": {
                    "image": {"type": "string", "enum": ["fmacfw_8800d80_h_u02_bin", "fmacfw_8800d80_u02_bin", "fmacfwbt_8800d80_u02_bin", "lmacfw_rf_8800d80_u02_bin"]},
                    "addr": {"type": "string", "description": "Chip runtime address as 0x-prefixed hex string."}
                },
                "required": ["image", "addr"]
            }
        }
    },
    {
        "type": "function",
        "function": {
            "name": "read_byte",
            "description": "Read 1 byte at a chip runtime address. Returns integer 0-255. USE THIS instead of guessing byte values.",
            "parameters": {
                "type": "object",
                "properties": {
                    "image": {"type": "string"},
                    "addr": {"type": "string"}
                },
                "required": ["image", "addr"]
            }
        }
    },
    {
        "type": "function",
        "function": {
            "name": "read_string_at",
            "description": "Read NUL-terminated ASCII string at a chip runtime address. Use to identify string literals referenced by code.",
            "parameters": {
                "type": "object",
                "properties": {
                    "image": {"type": "string"},
                    "addr": {"type": "string"},
                    "max_len": {"type": "integer", "default": 128}
                },
                "required": ["image", "addr"]
            }
        }
    },
    {
        "type": "function",
        "function": {
            "name": "decode_ldr_literal",
            "description": "Decode a PC-relative LDR literal at the given instruction address. Returns the actual value loaded. CRITICAL: do NOT interpret LDR literals yourself — always call this.",
            "parameters": {
                "type": "object",
                "properties": {
                    "image": {"type": "string"},
                    "ldr_addr": {"type": "string", "description": "Address of the LDR instruction, not the literal pool target."}
                },
                "required": ["image", "ldr_addr"]
            }
        }
    },
    {
        "type": "function",
        "function": {
            "name": "decode_constant_pool",
            "description": "Decode a literal pool of N consecutive dwords starting at addr. Returns list of '0x...' strings.",
            "parameters": {
                "type": "object",
                "properties": {
                    "image": {"type": "string"},
                    "addr": {"type": "string"},
                    "n_words": {"type": "integer", "default": 4}
                },
                "required": ["image", "addr"]
            }
        }
    },
    {
        "type": "function",
        "function": {
            "name": "disasm_at",
            "description": "Disassemble N Thumb-2 instructions at a chip runtime address. Returns list of instruction lines.",
            "parameters": {
                "type": "object",
                "properties": {
                    "image": {"type": "string"},
                    "addr": {"type": "string"},
                    "n": {"type": "integer", "default": 30}
                },
                "required": ["image", "addr"]
            }
        }
    },
    {
        "type": "function",
        "function": {
            "name": "register_at",
            "description": "Return a register name hint for an MMIO address. Format: REG_<PAGE>_<OFFSET>. The LLM may rename this but the address must come from this or another tool call.",
            "parameters": {
                "type": "object",
                "properties": {
                    "addr": {"type": "string"}
                },
                "required": ["addr"]
            }
        }
    },
    {
        "type": "function",
        "function": {
            "name": "registers_in_page",
            "description": "List all known MMIO addresses within a 64K page (e.g., '0x4004').",
            "parameters": {
                "type": "object",
                "properties": {
                    "page_hex": {"type": "string"}
                },
                "required": ["page_hex"]
            }
        }
    },
    {
        "type": "function",
        "function": {
            "name": "struct_field_offset",
            "description": "Return the offset of a field in a struct (known structs: vif_info, tx_queue, rx_desc, tx_desc, ke_env, scan_req). CRITICAL: do NOT compute struct offsets yourself.",
            "parameters": {
                "type": "object",
                "properties": {
                    "struct_name": {"type": "string"},
                    "field_name": {"type": "string"}
                },
                "required": ["struct_name", "field_name"]
            }
        }
    },
    {
        "type": "function",
        "function": {
            "name": "arr_offset",
            "description": "Return elem_size * index as a '0x...' string. Use for array indexing into structs/buffers. CRITICAL: do NOT compute pointer arithmetic yourself.",
            "parameters": {
                "type": "object",
                "properties": {
                    "elem_size": {"type": "integer"},
                    "index": {"type": "integer"}
                },
                "required": ["elem_size", "index"]
            }
        }
    },
    {
        "type": "function",
        "function": {
            "name": "mmio_write_c",
            "description": "Return canonical C code for an MMIO write: '*((volatile TYPE *)(uintptr_t)0xADDR) = val;  /* REG_NAME */'. The address MUST come from a prior tool call.",
            "parameters": {
                "type": "object",
                "properties": {
                    "addr": {"type": "string"},
                    "val": {"type": "string", "default": "val"},
                    "width": {"type": "string", "default": "uint32_t"}
                },
                "required": ["addr"]
            }
        }
    },
    {
        "type": "function",
        "function": {
            "name": "mmio_read_c",
            "description": "Return canonical C code for an MMIO read.",
            "parameters": {
                "type": "object",
                "properties": {
                    "addr": {"type": "string"},
                    "var": {"type": "string", "default": "val"},
                    "width": {"type": "string", "default": "uint32_t"}
                },
                "required": ["addr"]
            }
        }
    },
    {
        "type": "function",
        "function": {
            "name": "mmio_poll_c",
            "description": "Return canonical C code for a busy-wait MMIO poll.",
            "parameters": {
                "type": "object",
                "properties": {
                    "addr": {"type": "string"},
                    "mask": {"type": "string", "default": "mask"},
                    "width": {"type": "string", "default": "uint32_t"}
                },
                "required": ["addr"]
            }
        }
    },
    {
        "type": "function",
        "function": {
            "name": "find_callers",
            "description": "Find all functions that call this function. Returns list of function names.",
            "parameters": {
                "type": "object",
                "properties": {
                    "function_name": {"type": "string"}
                },
                "required": ["function_name"]
            }
        }
    },
    {
        "type": "function",
        "function": {
            "name": "find_callees",
            "description": "Find all functions called by this function. Returns list of function names.",
            "parameters": {
                "type": "object",
                "properties": {
                    "function_name": {"type": "string"},
                    "image": {"type": "string"}
                },
                "required": ["function_name", "image"]
            }
        }
    },
    {
        "type": "function",
        "function": {
            "name": "xref_to",
            "description": "Find all cross-references to an address in the binary. Returns list of instruction addresses.",
            "parameters": {
                "type": "object",
                "properties": {
                    "image": {"type": "string"},
                    "addr": {"type": "string"}
                },
                "required": ["image", "addr"]
            }
        }
    },
    {
        "type": "function",
        "function": {
            "name": "behavioral_at",
            "description": "Get the synthesized behavioral C body for a function. Returns null if no behavioral trace exists.",
            "parameters": {
                "type": "object",
                "properties": {
                    "function_name": {"type": "string"},
                    "image": {"type": "string"}
                },
                "required": ["function_name", "image"]
            }
        }
    },
    {
        "type": "function",
        "function": {
            "name": "behavioral_mmio_summary",
            "description": "Get summary of MMIO accesses in a function's behavioral trace: unique addresses, access counts.",
            "parameters": {
                "type": "object",
                "properties": {
                    "function_name": {"type": "string"},
                    "image": {"type": "string"}
                },
                "required": ["function_name", "image"]
            }
        }
    },
]

# === TOOL DISPATCHER ===

def call_tool(name, args):
    """Dispatch a tool call by name. Returns a JSON-serializable result."""
    fn = globals().get(name)
    if fn is None:
        return {"error": f"unknown tool: {name}"}
    try:
        result = fn(**args)
        return {"ok": True, "result": result}
    except Exception as e:
        return {"error": f"{type(e).__name__}: {e}"}

if __name__ == "__main__":
    import sys
    # Quick test
    print("read_dword at 0x100000+4:", read_dword("fmacfw_8800d80_h_u02_bin", "0x100004"))
    print("register_at 0x40040000:", register_at("0x40040000"))
    print("struct_field_offset vif_info.channel:", struct_field_offset("vif_info", "channel"))
    print("mmio_write_c 0x40040000:", mmio_write_c("0x40040000", "10"))
    print("registers_in_page 0x4004 (first 10):", registers_in_page("0x4004")[:10])
    print("decode_ldr_literal 0x10d7a4:", decode_ldr_literal("fmacfw_8800d80_h_u02_bin", "0x10d7a4"))
    print("arr_offset(4, 5):", arr_offset(4, 5))
