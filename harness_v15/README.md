# Harness v15

Decompile 12 critical FAIL functions + enhance 8 REVIEWs in the AIC8800D80 truth lane
using parallel model workers. Strong verifier rejects v13 templates.

## Layout

```
harness_v15/
├── orchestrator.py          # distribute tasks to N parallel workers
├── load_balancer.py         # round-robin key pool + <think> strip
├── verifier/verify.py       # strong verifier (rejects templates, leaves with fake calls)
├── workers/worker.py        # one task: r2 disasm + model call + verify
├── prompts/decompile_system.md  # system prompt for the model
├── tasks/*.json             # 20 task definitions (12 FAILs + 8 REVIEWs)
├── keys/keys.json           # API keys (NOT in git)
└── out/<task_id>/           # per-worker output: synth.c, verify.json, disasm.txt
```

## Usage

```bash
# 1. Configure keys
cp harness_v15/keys/keys.example.json harness_v15/keys/keys.json
# Edit keys.json with your real API keys + base_url

# 2. Smoke-test the verifier (no API call)
python3 harness_v15/verifier/verify.py \
  --task harness_v15/tasks/fail_03_crypto_hw_disable_lmacfw_rf_8800d80_u02.json \
  --synth artifacts/releases/aic8800d80-rebuild-v1/synth/252_crypto_hw_disable.synth.c
# Should fail with: template_detected

# 3. Pilot 1 task (1 worker, 1 task)
python3 harness_v15/workers/worker.py \
  --task harness_v15/tasks/fail_03_crypto_hw_disable_lmacfw_rf_8800d80_u02.json \
  --out harness_v15/out/pilot \
  --config harness_v15/keys/keys.json

# 4. Run all 20 tasks with 10 workers in parallel
python3 harness_v15/orchestrator.py \
  --tasks harness_v15/tasks/ \
  --out harness_v15/out/ \
  --config harness_v15/keys/keys.json \
  --max-workers 10

# 5. Only run FAILs
python3 harness_v15/orchestrator.py ... --filter fail_

# 6. Aggregate accepted synth files
python3 harness_v15/aggregate.py --out harness_v15/out/ --release artifacts/releases/aic8800d80-rebuild-v1/synth/
```

## Verifier rules (the truth)

1. **Reject v13 behavior_lift template** — `state = 0x...U; state ^= ...; switch (dispatch & 3U)`
2. **Leaf functions** (r2 shows 0 BL targets): body must have real register/MMIO ops
3. **Leaf with fake callees**: REJECT (function doesn't actually call anything)
4. **Calling functions**: at least 1 callee must match r2 BL target
5. **Helper keywords** required: at least 1 callee must contain rf_/crypto_/timer_init/etc.

## Tasks

20 total:
- 12 `fail_*` — truth lane FAILs, need full decompilation
- 8 `review_*` — truth lane REVIEWs, need additional callee analysis

Each task JSON contains: function, address, image, binary, load_base, min_callees, min_helpers.

## Output

Each worker writes to `out/<task_id>/`:
- `synth.c` — generated C function body
- `disasm.txt` — r2 disassembly used as source
- `symbols.txt` — composed file symbol list
- `response_raw.txt` — raw model output (with <think> stripped)
- `verify.json` — verifier verdict + evidence
- `result.json` — final aggregate

## Cost

12 FAILs × ~5K tokens (system) + ~10K tokens (disasm + symbols) + ~2K tokens (response)
= ~17K tokens × 20 tasks = ~340K total. At 1M context, plenty of headroom.
