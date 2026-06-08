#!/usr/bin/env bash
# Behavioral fingerprint stage — called by fwcycle when --behavioral is set.
# Pre-scans → traces → generates → resolves names → deploys behavioral synth bodies.
set -e
REPO="${1:-/home/grec-alexander/Downloads/aic8800d80}"
RUN_ROOT="${2:-extraction_out/reconstruction/mega7}"
cd "$REPO"

BEH_OUT="/tmp/opencode/beh_cycle_$(date +%s)"
mkdir -p "$BEH_OUT"
BIN_DIR="inputs/firmware"
IDA_DIR="extraction_out/ida_export_live"

echo "[behavioral] Pre-scanning with Capstone..."
for img in lmacfw_rf_8800d80_u02.bin fmacfwbt_8800d80_u02.bin fmacfw_8800d80_u02.bin fmacfw_8800d80_h_u02.bin; do
    python3 tools/find_mmio_functions.py \
      --bin "$BIN_DIR/$img" --base 0x1200000 \
      --functions "$IDA_DIR/${img}.functions.jsonl" \
      --out "$BEH_OUT/mmio_${img}.jsonl" --max-insns 200
done

echo "[behavioral] Building target files..."
for f in "$BEH_OUT"/mmio_*.jsonl; do
    python3 -c "import json;n=open('/dev/stdout','w');[n.write(json.dumps({'name':d['name'],'image':'','address':d['runtime_address']})+chr(10)) for d in[json.loads(l)for l in open('$f')if l.strip()]if d['has_mmio']]" \
      > "$BEH_OUT/targs_$(basename $f .jsonl | sed 's/mmio_//').jsonl"
done

echo "[behavioral] Tracing with Unicorn..."
python3 tools/behavioral_fingerprint.py \
  --bin "$BIN_DIR/lmacfw_rf_8800d80_u02.bin" \
  --targets "$BEH_OUT/targs_lmacfw_rf_8800d80_u02.bin.jsonl" \
  --out "$BEH_OUT/fp_lmacfw_rf.jsonl" --max-insns 50000 &
python3 tools/behavioral_fingerprint.py \
  --bin "$BIN_DIR/fmacfwbt_8800d80_u02.bin" \
  --targets "$BEH_OUT/targs_fmacfwbt_8800d80_u02.bin.jsonl" \
  --out "$BEH_OUT/fp_fmacfwbt.jsonl" --max-insns 50000 &
python3 tools/behavioral_fingerprint.py \
  --bin "$BIN_DIR/fmacfw_8800d80_u02.bin" \
  --targets "$BEH_OUT/targs_fmacfw_8800d80_u02.bin.jsonl" \
  --out "$BEH_OUT/fp_fmacfw.jsonl" --max-insns 50000 &
python3 tools/behavioral_fingerprint.py \
  --bin "$BIN_DIR/fmacfw_8800d80_h_u02.bin" \
  --targets "$BEH_OUT/targs_fmacfw_8800d80_h_u02.bin.jsonl" \
  --out "$BEH_OUT/fp_fmacfw_h.jsonl" --max-insns 50000 &
wait

echo "[behavioral] Combining and generating synth files..."
cat "$BEH_OUT"/fp_*.jsonl > "$BEH_OUT/combined.jsonl"
/tmp/opencode/behaviorsynth "$BEH_OUT/combined.jsonl" "$BEH_OUT/synth"

echo "[behavioral] Resolving sub_XXXXXX names..."
python3 tools/resolve_names.py \
  --composed-dir "$RUN_ROOT/composed" \
  --synth-dir "$BEH_OUT/synth"

echo "[behavioral] Deploying to $RUN_ROOT/synth/"
find "$BEH_OUT/synth" -name 'behavioral_*.synth.c' -exec cp {} "$REPO/$RUN_ROOT/synth/" \;
echo "[behavioral] Done."
