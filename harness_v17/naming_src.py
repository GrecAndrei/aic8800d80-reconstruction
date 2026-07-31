#!/usr/bin/env python3
"""Unified series: name all anonymous sub_* functions in the src/ tree.

Scans src/<image>/functions/ for files named <addr>_sub_<HEX>.c, batches
them 20-per-LLM-call (same format as naming_batch.py), and writes results
to harness_v17/names/{fn}__{img}.json (shared cache, skip-if-exists).

Images are the 4 firmware binaries:
  fmacfw_u02      -> fmacfw_8800d80_u02_bin
  fmacfw_h_u02    -> fmacfw_8800d80_h_u02_bin
  fmacfwbt_u02    -> fmacfwbt_8800d80_u02_bin
  lmacfw_rf_u02   -> lmacfw_rf_8800d80_u02_bin
"""
import json, re, sys, time, argparse, subprocess
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor, as_completed

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "harness_v17"))
import naming_batch as nb
import tools as v17tools

SRC_DIR = REPO / "src"
OUT = nb.OUT
FW_DIR = REPO / "inputs/firmware"

_ANSI = re.compile(r'\x1b\[[0-9;]*m')

_orig_disasm_at = v17tools.disasm_at


def disasm_at_fallback(image, addr, n=8):
    """Cache-aware disasm_at with per-address r2 fallback for function starts
    the linear-sweep cache missed (data pool before the function shifts r2's
    linear decode by 2 bytes). Uses the proven r2 form from AGENTS.md."""
    got = _orig_disasm_at(image, addr, n)
    if got:
        return got
    img = image[:-4] if image.endswith("_bin") else image
    cmd = ["r2", "-q", "-2", "-a", "arm", "-b", "16", "-m", "0x100000",
           "-c", f"s {addr}; pd {n}", str(FW_DIR / f"{img}.bin")]
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=15)
    except Exception:
        return []
    out = _ANSI.sub('', result.stdout).strip()
    lines = [l.strip() for l in out.split('\n') if l.strip().startswith('0x')]
    return lines


def _disasm_at_wrapper(image, addr, n=8):
    """Stand-in for v17tools.disasm_at used by naming_src naming runs."""
    return disasm_at_fallback(image, addr, n)

IMG_MAP = {
    "fmacfw_u02": "fmacfw_8800d80_u02_bin",
    "fmacfw_h_u02": "fmacfw_8800d80_h_u02_bin",
    "fmacfwbt_u02": "fmacfwbt_8800d80_u02_bin",
    "lmacfw_rf_u02": "lmacfw_rf_8800d80_u02_bin",
}

_FILE_RE = re.compile(r"^([0-9a-fA-F]+)_sub_([0-9a-fA-F]+)\.c$")


def discover_targets():
    targets = []
    for sub in sorted(SRC_DIR.iterdir()):
        if not sub.is_dir() or sub.name not in IMG_MAP:
            continue
        img = IMG_MAP[sub.name]
        for f in sorted((sub / "functions").glob("*.c")):
            m = _FILE_RE.match(f.name)
            if not m:
                continue
            addr = int(m.group(1), 16)
            fn = f"sub_{m.group(2).upper()}"
            if addr < 0x100000:
                continue
            targets.append({"fn": fn, "img": img, "addr": f"0x{addr:x}", "has_behav": False, "behav_text": None})
    return targets


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--batch-size", type=int, default=20)
    ap.add_argument("--workers", type=int, default=12)
    ap.add_argument("--limit", type=int, default=0)
    args = ap.parse_args()

    v17tools.disasm_at = _disasm_at_wrapper
    targets = discover_targets()

    def _is_named(t):
        p = OUT / f"{t['fn']}__{t['img']}.json"
        if not p.exists():
            return False
        try:
            return json.loads(p.read_text()).get('status') == 'ok'
        except Exception:
            return False

    targets = [t for t in targets if not _is_named(t)]
    if args.limit:
        targets = targets[:args.limit]
    print(f"src unnamed targets: {len(targets)} (cached-skip applied)", file=sys.stderr, flush=True)
    if not targets:
        return

    batches = list(nb.chunked(targets, args.batch_size))
    t0 = time.time()
    done = ok = fail = 0
    statuses = {}
    with ThreadPoolExecutor(max_workers=args.workers) as ex:
        futures = {ex.submit(nb.process_batch, b): b for b in batches}
        for f in as_completed(futures):
            results = f.result()
            for r in results:
                done += 1
                statuses[r] = statuses.get(r, 0) + 1
                if r == "ok":
                    ok += 1
                elif r not in ("filtered", "no_target"):
                    fail += 1
            if done % 100 == 0 or done == len(batches) * args.batch_size:
                rate = done / max(time.time() - t0, 1e-6)
                eta = (len(targets) - done) / rate if rate > 0 else 0
                print(f"  {done}/{len(targets)} ok={ok} rate={rate:.1f}/s eta={eta:.0f}s", file=sys.stderr, flush=True)
    print(f"\nDONE: {done} ok={ok} fail={fail} in {time.time()-t0:.1f}s", file=sys.stderr)
    top = sorted(statuses.items(), key=lambda x: -x[1])[:8]
    print("statuses:", top, file=sys.stderr)


if __name__ == "__main__":
    main()
