"""v18 WFFW repackage: take original WFFW, replace code with v18 compiled bin."""
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent.parent
FW_DIR = REPO / "inputs/firmware"
WORK_DIR = Path("/tmp/v18_blinky")
OUT_DIR = REPO / "artifacts/releases/aic8800d80-rebuild-v1/wffw_v18"
OUT_DIR.mkdir(parents=True, exist_ok=True)

binaries = {
    "fmacfw_8800d80_h_u02": "fmacfw_h",
    "fmacfw_8800d80_u02": "fmacfw",
    "fmacfwbt_8800d80_u02": "fmacfwbt",
    "lmacfw_rf_8800d80_u02": "lmacfw_rf",
}

CODE_OFFSET = 0x100
HEADER_SIZE = 0x100

for bin_name, name in binaries.items():
    src_bin = FW_DIR / f"{bin_name}.bin"
    obj_bin = WORK_DIR / f"{name}.bin"
    out_bin = OUT_DIR / f"{bin_name}_v18.bin"
    src = src_bin.read_bytes()
    obj = obj_bin.read_bytes()
    out = bytearray(src[:HEADER_SIZE])
    out.extend(obj)
    if len(out) < len(src):
        out.extend(b'\x00' * (len(src) - len(out)))
    elif len(out) > len(src):
        out = out[:len(src)]
    out_bin.write_bytes(bytes(out))
    print(f"{bin_name}: src={len(src):,} out={len(out):,} code={len(obj):,}", file=sys.stderr)
print(f"\nWFFW v18 in {OUT_DIR}", file=sys.stderr)
