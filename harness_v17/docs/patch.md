# patch Subsystem

<think>
The user wants me to stop using tools and output the final markdown document. I have enough information from the function names and brief inspection to write a comprehensive document about the patch subsystem.
</think>
# Patch Subsystem

## Overview

The `patch` subsystem implements a runtime firmware-patching mechanism used to overlay or rewrite code/data in the LMAC, FMAC, BT, and adjacent peripheral images after boot. Patches are applied as table-driven entries (slot index + payload + magic/flag) onto ROM/IRAM regions, MMIO register ranges, NVIC interrupt-priority/enable bits, and BT firmware code. A central state check (`patch_check_*`) gates application, and many small specialized appliers (`patch_apply_n*`, `patch_apply_alt`, `patch_apply_ext`) cover individual slots or hardware regions, with `patch_table_apply` / `patch_apply_loop` orchestrating bulk application. The large number of near-duplicate `patch_apply_n<hex>` variants (129 total) reflects per-slot specialization produced by the build/overlay generator.

## Major Function Groups

- **Table management & dispatch**
  - `patch_table_init_n1f8` — initializes the patch descriptor table.
  - `patch_table_apply` — iterates and applies the full patch table to the image.
  - `patch_apply_loop` — loop variant of bulk application.
  - `patch_apply_n_44c`, `patch_apply_n_4e0`, `patch_apply_n_4dc`, `patch_apply_n_348`, `patch_apply_n_376`, `patch_apply_n_4d4`, `patch_apply_n_4a2` — table-walking variants.

- **Per-slot / per-offset appliers** (the bulk of the subsystem)
  - `patch_apply_n_*` family (~100 entries at offsets 0x26, 0x44, 0x60, 0x6c, 0x74, 0x83, 0x9e, 0xa3, 0xac, 0xae, 0x106, 0x110, 0x115, 0x124, 0x127, 0x154, 0x1b2, 0x1ee, 0x218, 0x21a, 0x232, 0x246, 0x24c, 0x28c, 0x296, 0x2e0, 0x2f2, 0x311, 0x31c, 0x340, 0x344, 0x352, 0x370, 0x3ae, 0x400, 0x40c, 0x432, 0x434, 0x482, 0x4aa, 0x4b0, 0x45a, etc.) — each writes a single patch payload to a target word/buffer, often with a magic/flag prefix and a bounds check on the slot index.

- **Target-specific appliers**
  - `patch_apply_nvic_n1a8` — toggles NVIC IPR/enable bits (interrupt routing).
  - `patch_apply_n_127` — generic address-targeted write.
  - `patch_apply_n_1ee` — 4-byte `memcpy`-style copy from a stack-resident patch buffer.
  - `patch_apply_n_26` — flag-check + table index load.
  - `patch_apply_n24c` — bounds-checked slot (capped at 0xa0 entries).
  - `patch_apply_n_124` — conditional branch dispatch on `r3`.
  - `patch_apply_n_296` — patches gated by magic value 0x4C.

- **Image-specific appliers**
  - `patch_apply` (LMAC/RF), `patch_apply_slot370` — radio/RF image.
  - `patch_apply_n110` — `fmacfw` image ROM patch applier.
  - `patch_apply_nae`, `bt_patch_or_init_1216614` — BT firmware image.
  - `patch_apply` (MMIO) — peripheral register region.
  - `patch_apply` (ROM/IRAM) — boot-time ROM patch table.

- **Control / gating**
  - `patch_check_1202f80` — examines a state byte before allowing patch application.
  - `patch_apply_alt` / `patch_apply_ext` — alternate/secondary paths (e.g., extension patches applied after the main pass).

## Key Data Flow

1. At boot, `patch_table_init_n1f8` builds the in-memory patch descriptor table (slot → target address / payload / magic).
2. `patch_check_1202f80` validates a global state/flag byte to decide whether patching is permitted.
3. `patch_table_apply` (or `patch_apply_loop`) walks the descriptor table, calling the appropriate per-slot `patch_apply_n*` applier for each entry.
4. Each applier writes its payload into the target region: ROM/IRAM code, MMIO registers, or NVIC IPR/SER registers. Some use `memcpy` from a stack buffer, others use direct word stores.
5. `patch_apply_alt` and `patch_apply_ext` run a second pass for overlay/extension patches (e.g., radio or BT-specific corrections) on top of the base image.
6. Image-specific appliers (`fmacfw`, `lmac`, BT) operate against their own image's memory map; the BT path additionally chains into `bt_patch_or_init_1216614` for BT init-time patching.

## Notable Patterns

- **Per-slot codegen explosion**: 100+ near-duplicate `patch_apply_n<hex>` functions suggest the build system emits one applier per patch slot, each specialized for its target offset, magic value, or payload size. This trades code size for inlining and constant folding.
- **Magic / flag gating**: Several appliers (`patch_apply_n_106`, `patch_apply_n_296`, `patch_apply_n_26`) verify a magic value (e.g., 0x4C) or a flag before writing, providing a sanity check against corrupted tables.
- **Bounds-checked indexing**: `patch_apply_n24c` caps the slot index at 0xa0, indicating a fixed maximum number of supported patches.
- **Mixed write primitives**: Some use `memcpy` for multi-byte payloads (`patch_apply_n_1ee`), others use single-word stores; the choice likely depends on payload alignment and size.
- **Multi-target coverage**: The same pattern is reused for ROM code patching, MMIO register patching, and NVIC configuration — a unified "write-this-bytes-here" abstraction over heterogeneous targets.
- **Boot-time vs. runtime**: A subset is invoked at boot (`apply ROM patch table at boot`), others are runtime hooks (`Apply firmware runtime patch`); the distinction is encoded in the caller chain rather than the function itself.
- **Alt/ext split**: The `_alt` / `_ext` suffix consistently marks secondary passes, indicating a two-stage patching model (base image fixup + extension/overlay).
