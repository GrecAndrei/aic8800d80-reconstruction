#!/usr/bin/env bash
# Behavioral fingerprint stage — called by fwcycle when --behavioral is set.
# Pre-scans from composed file (all functions) → traces MMIO ones → generates → resolves → deploys.
set -e
REPO="${1:-/home/grec-alexander/Downloads/aic8800d80}"
RUN_ROOT="${2:-extraction_out/reconstruction/mega7}"
cd "$REPO"

BEH_OUT="/tmp/opencode/beh_$(date +%s | md5sum | cut -c1-8)"
mkdir -p "$BEH_OUT"
BIN_DIR="inputs/firmware"

echo "[behavioral] Extracting all function addresses from composed files..."
python3 << 'PY'
import json, re, sys
from pathlib import Path

composed_dir = Path(sys.argv[1]) / "composed"
out_dir = Path(sys.argv[2])
BASE = 0x1200000

addr_re = re.compile(r'addr=0x([0-9a-fA-F]+)')
fn_re = re.compile(r'void\s+([a-zA-Z_][a-zA-Z0-9_]+)\s*\(\s*void\s*\)\s*\{')

image_map = {
    'lmacfw_rf': 'lmacfw_rf_8800d80_u02.bin',
    'fmacfwbt': 'fmacfwbt_8800d80_u02.bin',
    'fmacfw': 'fmacfw_8800d80_u02.bin',
    'fmacfw_8800d80_h': 'fmacfw_8800d80_h_u02.bin',
}

for fpath in sorted(composed_dir.glob('*.reconstructed.c')):
    text = fpath.read_text(errors='replace')
    lines = text.split('\n')
    total = 0
    with open(out_dir / f'candidates_{fpath.stem}.jsonl', 'w') as fout:
        for i, line in enumerate(lines):
            m = addr_re.search(line)
            if m:
                file_off = int(m.group(1), 16)
                for j in range(i+1, min(i+5, len(lines))):
                    fm = fn_re.search(lines[j])
                    if fm:
                        fn_name = fm.group(1)
                        runtime = file_off + BASE
                        fout.write(json.dumps({'name': fn_name, 'address': hex(runtime)}) + '\n')
                        total += 1
                        break
    print(f'  {fpath.stem}: {total} candidates', file=sys.stderr)
PY "$REPO/$RUN_ROOT" "$BEH_OUT"

echo "[behavioral] Pre-scanning with Capstone (MMIO filter)..."
declare -A BIN_MAP=(
    ["lmacfw_rf"]="lmacfw_rf_8800d80_u02.bin"
    ["fmacfwbt"]="fmacfwbt_8800d80_u02.bin"
    ["fmacfw"]="fmacfw_8800d80_u02.bin"
    ["fmacfw_8800d80_h"]="fmacfw_8800d80_h_u02.bin"
)
for cand_file in "$BEH_OUT"/candidates_*.jsonl; do
    stem=$(basename "$cand_file" .jsonl | sed 's/candidates_//')
    # Extract image short name: stems are like "fmacfw_8800d80_u02_bin.reconstructed"
    img_key=""
    for key in "${!BIN_MAP[@]}"; do
        if [[ "$stem" == *"$key"* ]]; then
            img_key="$key"
            break
        fi
    done
    [ -z "$img_key" ] && continue
    python3 tools/find_mmio_functions.py \
      --bin "$BIN_DIR/${BIN_MAP[$img_key]}" --base 0x1200000 \
      --functions "$cand_file" --out "$BEH_OUT/mmio_${stem}.jsonl" --max-insns 200 &
done
wait

echo "[behavioral] Building trace target files (MMIO only)..."
for mmio_file in "$BEH_OUT"/mmio_*.jsonl; do
    python3 -c "
import json
with open('$mmio_file') as f:
    for line in f:
        d = json.loads(line)
        if d.get('has_mmio'):
            print(json.dumps({'name': d['name'], 'address': d['runtime_address']}))
" > "$BEH_OUT/targets_$(basename $mmio_file .jsonl | sed 's/mmio_//').jsonl"
done

echo "[behavioral] Tracing with Unicorn..."
python3 tools/behavioral_fingerprint.py --bin "$BIN_DIR/lmacfw_rf_8800d80_u02.bin" --targets "$BEH_OUT/targets_lmacfw_rf_8800d80_u02_bin.jsonl" --out "$BEH_OUT/fp_lm.jsonl" --max-insns 50000 &
python3 tools/behavioral_fingerprint.py --bin "$BIN_DIR/fmacfwbt_8800d80_u02.bin" --targets "$BEH_OUT/targets_fmacfwbt_8800d80_u02_bin.jsonl" --out "$BEH_OUT/fp_bt.jsonl" --max-insns 50000 &
python3 tools/behavioral_fingerprint.py --bin "$BIN_DIR/fmacfw_8800d80_u02.bin" --targets "$BEH_OUT/targets_fmacfw_8800d80_u02_bin.jsonl" --out "$BEH_OUT/fp_fw.jsonl" --max-insns 50000 &
python3 tools/behavioral_fingerprint.py --bin "$BIN_DIR/fmacfw_8800d80_h_u02.bin" --targets "$BEH_OUT/targets_fmacfw_8800d80_h_u02_bin.jsonl" --out "$BEH_OUT/fp_h.jsonl" --max-insns 50000 &
wait

echo "[behavioral] Combining, generating, resolving..."
cat "$BEH_OUT"/fp_*.jsonl > "$BEH_OUT/combined.jsonl"
/tmp/opencode/behaviorsynth "$BEH_OUT/combined.jsonl" "$BEH_OUT/synth"
python3 tools/resolve_names.py --composed-dir "$RUN_ROOT/composed" --synth-dir "$BEH_OUT/synth"

echo "[behavioral] Deploying..."
find "$BEH_OUT/synth" -name 'behavioral_*.synth.c' -exec cp {} "$REPO/$RUN_ROOT/synth/" \;
echo "[behavioral] Done."
