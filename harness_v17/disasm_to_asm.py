#!/usr/bin/env python3
"""v18: faithful inline-asm reconstruction (FAST).

For each named function, extract the original raw bytes from the firmware binary
(up to the first bx lr / pop {...,pc}) and emit C with __asm__(".byte ...") inside
a naked function. This is O(1) per function and reproduces the original machine
code byte-for-byte.
"""
import json, sys, re, subprocess, time
from pathlib import Path

REPO = Path("/home/grec-alexander/Downloads/aic8800d80")
NAMES_DIR = REPO / "harness_v17/names"
OUT_DIR = REPO / "artifacts/releases/aic8800d80-rebuild-v1/composed_v18"
OUT_DIR.mkdir(parents=True, exist_ok=True)

binaries = {
    "fmacfw_8800d80_h_u02_bin": "fmacfw_8800d80_h_u02",
    "fmacfw_8800d80_u02_bin": "fmacfw_8800d80_u02",
    "fmacfwbt_8800d80_u02_bin": "fmacfwbt_8800d80_u02",
    "lmacfw_rf_8800d80_u02_bin": "lmacfw_rf_8800d80_u02",
}


def load_all_fns():
    p = REPO / "harness_v16/all_fns.json"
    if not p.exists():
        return {}
    content = p.read_text().lstrip()
    data = []
    dec = json.JSONDecoder()
    idx = 0
    while idx < len(content):
        try:
            obj, end = dec.raw_decode(content, idx)
            if isinstance(obj, list):
                data.extend(obj)
            else:
                data.append(obj)
            idx = end
            while idx < len(content) and content[idx] in ' \n\r\t,':
                idx += 1
        except Exception:
            break
    return data

ALL_FNS = load_all_fns()
print(f"Loaded {len(ALL_FNS)} entries from all_fns.json", file=sys.stderr)


def find_function_end(image, addr, raw, max_insn=30):
    """Use r2 to disasm up to max_insn instructions. Find first bx lr / pop {..pc}.
    Returns (end_offset, body_bytes) or None."""
    bin_path = REPO / f"inputs/firmware/{binaries[image]}.bin"
    cmd = ["r2", "-q", "-2", "-m", "0x100000", "-c",
           f"e asm.arch=arm; e asm.bits=16; pd {max_insn} @ {addr}",
           str(bin_path)]
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=10)
    except Exception:
        return None
    out = re.sub(r'\x1b\[[0-9;]*m', '', result.stdout)
    a = int(addr, 16)
    end = None
    for line in out.split('\n'):
        m = re.match(r'\s*(?:[│┌└─> ]*)\s*0x([0-9a-f]+)\s+([0-9a-f]+)(?:\s+([0-9a-f]+))?\s*(.*)', line)
        if not m:
            continue
        cur = int(m.group(1), 16)
        if cur < a:
            continue
        insn = m.group(4)
        if 'bx lr' in insn or ('pop' in insn and 'pc' in insn):
            end = cur + 2
            break
    if end is None:
        end = a + 32
    off_start = a - 0x100000
    off_end = end - 0x100000
    if off_start < 0 or off_end > len(raw) or off_end <= off_start:
        return None
    return raw[off_start:off_end]


def emit_inline_asm(name, body_bytes):
    """Emit a C function that contains the raw bytes as inline asm.
    Uses \\n in each .byte string to ensure GAS sees them on separate lines."""
    byte_lines = []
    for b in body_bytes:
        byte_lines.append(f'        ".byte 0x{b:02x}\\n"')
    byte_list = '\n'.join(byte_lines)
    return f'''__attribute__((naked, used, section(".text.v18")))
void {name}(void) {{
    __asm__ volatile(
{byte_list}
    );
}}
'''


def main():
    # Build a map: (fn, img) -> chip runtime addr
    fn_addrs = {}
    for d in ALL_FNS:
        fn = d.get('function', '')
        for loc in d.get('locations', []):
            img = loc.get('image', '')
            addr = loc.get('address', '')
            if not addr or not img or img not in binaries:
                continue
            a = int(addr, 16)
            if a < 0x200000:
                chip = a + 0x100000
            else:
                chip = a
            fn_addrs[(fn, img)] = f"0x{chip:x}"

    NAMINGS = {}
    for f in NAMES_DIR.glob("*.json"):
        try:
            d = json.load(open(f))
            if d.get('status') == 'ok':
                NAMINGS[(d['fn'], d['img'])] = d
        except Exception:
            pass
    print(f"Loaded {len(NAMINGS)} successful namings", file=sys.stderr)

    out_by_image = {img: [] for img in binaries}
    stats = {'found': 0, 'no_addr': 0, 'no_bytes': 0, 'total_bytes': 0, 'fail': 0}

    for img in binaries:
        bin_path = REPO / f"inputs/firmware/{binaries[img]}.bin"
        raw = bin_path.read_bytes()
        img_fns = []
        for (fn, im), d in NAMINGS.items():
            if im != img: continue
            name = d.get('name', '')
            if not name or not re.match(r'^[a-zA-Z_][a-zA-Z0-9_]*$', name):
                continue
            addr = fn_addrs.get((fn, img))
            if not addr:
                stats['no_addr'] += 1
                continue
            img_fns.append((addr, name, fn))
        img_fns.sort()
        print(f"\n=== {img}: {len(img_fns)} functions ===", file=sys.stderr)

        t0 = time.time()
        for i, (addr, name, fn) in enumerate(img_fns):
            try:
                body = find_function_end(img, addr, raw)
            except Exception as e:
                stats['fail'] += 1
                continue
            if not body or len(body) < 2:
                stats['no_bytes'] += 1
                continue
            stats['found'] += 1
            stats['total_bytes'] += len(body)
            out_by_image[img].append(emit_inline_asm(name, body))
            if (i + 1) % 500 == 0:
                rate = (i + 1) / (time.time() - t0)
                eta = (len(img_fns) - i - 1) / rate if rate > 0 else 0
                print(f"  {i+1}/{len(img_fns)} found={stats['found']} rate={rate:.1f}/s eta={eta:.0f}s", file=sys.stderr)

    for img, fns in out_by_image.items():
        if not fns:
            continue
        out_path = OUT_DIR / f"{img}.reconstructed_v18.c"
        header = f"""/* v18: faithful inline-asm reconstruction */
/* image: {img}.bin */
/* {len(fns)} functions */
#include <stdint.h>
"""
        out_path.write_text(header + '\n'.join(fns))
        print(f"  Wrote {out_path.name}: {len(fns)} functions, {sum(1 for _ in open(out_path))} lines, {out_path.stat().st_size:,} bytes", file=sys.stderr)

    print(f"\nStats: {stats}", file=sys.stderr)


if __name__ == "__main__":
    main()
