# aic8800d80-rebuild-v17 (HuggingFace Dataset)

## What is this?

A dataset of 6,706 reverse-engineered WiFi firmware functions from the AIC8800D80 chip, with:
- Original ARM Thumb-2 disassembly
- Behaviorally-reconstructed C code
- LLM-proposed semantic name
- 1-line docstring
- Subsystem classification

Each function was processed by a tool-use LLM that investigated the function's disassembly, behavioral trace, callers, and callees using 16 deterministic tools. Every address in the LLM's output was cross-checked against tool call results to prevent hallucination.

## Schema

Each row in `v17_ml_pairs.jsonl`:

```json
{
  "function": "rf_bus_write2",
  "image": "fmacfw_8800d80_u02_bin",
  "chip_address": "0x1211504",
  "v17_name": "rf_bus_write2",
  "docstring": "Writes a 2-word value to the RF bus control/data registers",
  "subsystem": "rf",
  "arm_thumb": "0x00111504      384b           ldr r3, ...\n...",
  "behavioral_c": "void rf_bus_write2(void) {\n  *((volatile uint32_t *)0x40041000) = ...;\n  ...\n}",
  "mmio_op_count": 12,
  "disambiguated": false
}
```

## Subsystem distribution

| Subsystem | Count |
|-----------|------:|
| rf        | ~4,500 |
| ipc       | ~700 |
| patch     | ~400 |
| util      | ~300 |
| mac       | ~280 |
| unknown   | ~250 |
| mmio      | ~150 |
| ke        | ~80 |
| bt        | ~50 |
| tx        | ~30 |
| scan      | ~12 |
| rx        | ~10 |

## Provenance

- **Original firmware**: 4 binaries (`fmacfw_8800d80_h_u02`, `fmacfw_8800d80_u02`, `fmacfwbt_8800d80_u02`, `lmacfw_rf_8800d80_u02`), ~1.3 MB total, loaded at chip address 0x100000
- **Behavioral traces**: Reconstructed from execution traces (32,560 traces in `extraction_out/reconstruction/mega7/synth/`)
- **Naming**: Tool-use LLM (MiniMax-M3, 1M context) using 16 deterministic tools. Validator rejects any address literal not from a tool result.
- **Disambiguation**: Functions with colliding LLM-proposed names are disambiguated by appending the lower 16 bits of their address.

## How to use

```python
from datasets import load_dataset
ds = load_dataset("json", data_files="v17_ml_pairs.jsonl")
# ds['train'][0] gives the first record
```

## Limitations

- Functions are mostly behavioral reconstructions. The exact register/field semantics are derived from the LLM's pattern matching, not from documentation.
- The "subsystem" field is the LLM's best guess, not a verified classification.
- "Disambiguated" functions have address-suffixed names because the LLM collapsed multiple variants to a single name.

## License

Original firmware binaries are property of AIC Semiconductor. The disassembly and reconstructed C are released for research purposes only.
