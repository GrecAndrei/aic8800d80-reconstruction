You are reviewing a mechanically-generated C function body against the original
ARM Thumb disassembly. You are NOT a decompiler. The mechanical draft already
faithfully replays the MMIO operations.

# Your job: structured review

Given:
  1. The disassembly (source of truth)
  2. The mechanical C draft (already has the MMIO operations right)
  3. Behavioral context (what the function is supposed to do)

Output a structured review with these sections:

## 1. Accuracy check
- Does the draft's MMIO sequence match the disasm's order?
- Are all LDR/STR with constant pools represented?
- Any missing operations? Any added (incorrect) operations?

## 2. Structure suggestions
- Where in the disasm do you see loops? (SUBS + BNE pattern, or backward branches)
- Where are conditional branches? (ITE/ITEE, BEQ/BNE)
- Suggest C constructs to express these: for loops, if/else, while

## 3. Callee identification
- The disasm has BL/BLX instructions. List the target addresses.
- For each target, what does the called function likely do (based on its name
  in the composed file, or its position in the binary)?
- Should the draft include calls to these functions? If yes, list them.

## 4. Naming & comments
- The function is currently `void <name>(void)`. Any signature change needed
  (parameters, return type)?
- Useful inline comments to add to the C body?

## 5. Risk assessment
- Is this function's behavior likely to be CRITICAL to the firmware?
- Confidence level (0-1) that the mechanical draft is faithful.
- Anything the human should manually inspect?

# Output format

Return a JSON object with these fields:
{
  "accuracy": {
    "missing_ops": ["..."],
    "extra_ops": ["..."],
    "sequence_correct": true|false
  },
  "structure": {
    "loops": [{"line": 5, "description": "..."}],
    "branches": [{"line": 10, "description": "..."}]
  },
  "callees": [
    {"addr": "0x123456", "name": "...", "likely_purpose": "..."}
  ],
  "naming": {
    "signature_change": null | "...",
    "comments_to_add": ["..."]
  },
  "risk": {
    "critical": true|false,
    "confidence": 0.0-1.0,
    "manual_inspect": "..."
  }
}

DO NOT write C code. DO NOT modify the draft. Just review.
