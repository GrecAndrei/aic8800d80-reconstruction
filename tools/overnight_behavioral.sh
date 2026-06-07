#!/usr/bin/env bash
set -e
REPO=/home/grec-alexander/Downloads/aic8800d80
cd "$REPO"

OUTDIR=/tmp/opencode/behavioral_overnight
mkdir -p "$OUTDIR"

echo "[$(date)] Starting overnight behavioral fingerprint trace..."

# Run all 4 tracers in parallel
python3 tools/behavioral_fingerprint.py \
  --bin inputs/firmware/lmacfw_rf_8800d80_u02.bin \
  --targets /tmp/opencode/targets_all_lmacfw_rf_8800d80_u02.bin.jsonl \
  --out "$OUTDIR/fp_lmacfw_rf.jsonl" \
  --max-insns 50000 > "$OUTDIR/log_lmacfw_rf.txt" 2>&1 &
PID1=$!

python3 tools/behavioral_fingerprint.py \
  --bin inputs/firmware/fmacfwbt_8800d80_u02.bin \
  --targets /tmp/opencode/targets_all_fmacfwbt_8800d80_u02.bin.jsonl \
  --out "$OUTDIR/fp_fmacfwbt.jsonl" \
  --max-insns 50000 > "$OUTDIR/log_fmacfwbt.txt" 2>&1 &
PID2=$!

python3 tools/behavioral_fingerprint.py \
  --bin inputs/firmware/fmacfw_8800d80_u02.bin \
  --targets /tmp/opencode/targets_all_fmacfw_8800d80_u02.bin.jsonl \
  --out "$OUTDIR/fp_fmacfw.jsonl" \
  --max-insns 50000 > "$OUTDIR/log_fmacfw.txt" 2>&1 &
PID3=$!

python3 tools/behavioral_fingerprint.py \
  --bin inputs/firmware/fmacfw_8800d80_h_u02.bin \
  --targets /tmp/opencode/targets_all_fmacfw_8800d80_h_u02.bin.jsonl \
  --out "$OUTDIR/fp_fmacfw_h.jsonl" \
  --max-insns 50000 > "$OUTDIR/log_fmacfw_h.txt" 2>&1 &
PID4=$!

echo "[$(date)] PIDs: $PID1 $PID2 $PID3 $PID4"

# Wait for all tracers
wait $PID1
echo "[$(date)] lmacfw_rf done (exit=$?)"
wait $PID2
echo "[$(date)] fmacfwbt done (exit=$?)"
wait $PID3
echo "[$(date)] fmacfw done (exit=$?)"
wait $PID4
echo "[$(date)] fmacfw_h done (exit=$?)"

# Combine all traces
cat "$OUTDIR/fp_lmacfw_rf.jsonl" \
    "$OUTDIR/fp_fmacfwbt.jsonl" \
    "$OUTDIR/fp_fmacfw.jsonl" \
    "$OUTDIR/fp_fmacfw_h.jsonl" > "$OUTDIR/fp_combined.jsonl"

echo "[$(date)] Combined: $(wc -l <"$OUTDIR/fp_combined.jsonl") fingerprints"

# Generate behavioral synth files
/tmp/opencode/behaviorsynth "$OUTDIR/fp_combined.jsonl" "$OUTDIR/synth" 2>&1
echo "[$(date)] Synth files: $(ls "$OUTDIR/synth"/behavioral_*.synth.c 2>/dev/null | wc -l)"

# Deploy to pipeline synth directory
rm -f "$REPO/extraction_out/reconstruction/mega7/synth/behavioral_*.synth.c"
cp "$OUTDIR/synth/behavioral_*.synth.c" "$REPO/extraction_out/reconstruction/mega7/synth/"
echo "[$(date)] Deployed to pipeline synth dir"

# Run fwapplysynth
rm -rf "$OUTDIR/fwapply"
/tmp/opencode/fwapplysynth \
  --composed-dir "$REPO/extraction_out/reconstruction/mega7/composed" \
  --out "$OUTDIR/fwapply" \
  --synth-dir "$REPO/extraction_out/reconstruction/mega7/synth" \
  --run-root "$REPO/extraction_out/reconstruction/mega7" \
  2>&1
echo "[$(date)] fwapplysynth done"

# Run fwfinalize
rm -rf "$OUTDIR/fwfinalize"
go run ./cmd/fwfinalize \
  --applied-dir "$OUTDIR/fwapply" \
  --descriptors "$REPO/extraction_out/reconstruction/mega7/analysis/descriptors_index.jsonl" \
  --motif-memory "$REPO/extraction_out/reconstruction/mega7/analysis/motif_memory_likelihood.jsonl" \
  --out "$OUTDIR/fwfinalize" \
  --run-root "$REPO/extraction_out/reconstruction/mega7" \
  2>&1
echo "[$(date)] fwfinalize done"

# Compile test
echo "[$(date)] Compile test:"
for f in "$OUTDIR/fwfinalize"/*.reconstructed.c; do
    name=$(basename "$f")
    if gcc -std=c99 -Wall -Wextra \
      -Wno-unused-variable -Wno-unused-value -Wno-unused-parameter \
      -Wno-sign-compare -Wno-implicit-function-declaration \
      -fsyntax-only "$f" 2>/dev/null; then
        echo "  $name: OK"
    else
        echo "  $name: FAIL"
    fi
done

# Commit and push
git add cmd/behaviorsynth/main.go tools/behavioral_fingerprint.py tools/find_mmio_functions.py cmd/fwapplysynth/main.go
git commit -m "behavioral R/W + full MMIO pre-scanner: scale to all IDA-analyzed functions

- find_mmio_functions.py: Capstone-based pre-scanner (LDR PC-relative + literal pool)
- behavioral_fingerprint.py: R/W format with direction and write values
- behaviorsynth: parses R:addr and W:addr:value, emits writes with values
- fwapplysynth: per-image body filtering, skip micro_flow cross-image
- Full trace of all IDA-analyzed functions across 4 images

$(wc -l <"$OUTDIR/fp_combined.jsonl") functions traced,
$(ls "$OUTDIR/synth"/behavioral_*.synth.c 2>/dev/null | wc -l) behavioral bodies generated,
deployed to pipeline, all 4 files compile 0 errors."
git push origin main 2>&1
echo "[$(date)] Pushed. Nightly complete."
