#!/usr/bin/env bash
# Build the unified-series release tarball: src/ (4 images, real bodies,
# materialized data segment, headers) + the LLM naming dataset.
set -euo pipefail
cd "$(dirname "$0")/.."
REL="artifacts/releases/aic8800d80-rebuild-v26-unified"
mkdir -p "$REL"
rm -rf "$REL/src" "$REL/names"
cp -r src "$REL/src"
cp -r harness_v17/names "$REL/names"
(
  cd "$REL"
  find src names -type f -name '*.o' -delete
  tar czf ../aic8800d80-rebuild-v26-unified.tar.gz .
)
du -h "$REL.tar.gz" 2>/dev/null || du -h "artifacts/releases/aic8800d80-rebuild-v26-unified.tar.gz"
echo "release: artifacts/releases/aic8800d80-rebuild-v26-unified.tar.gz"
