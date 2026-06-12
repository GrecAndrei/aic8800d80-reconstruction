# WFFW Format Reverse-Engineering Notes

## Overview

The WFFW format is a binary container used by AIC8800D80 firmware to package
ARM Cortex-M firmware with metadata. It includes:
- ARM vector table (boot configuration)
- WFFW magic + section table
- Actual code (ARM Thumb-2)

## Layout (fmacfw_8800d80_h_u02.bin)

```
Offset  Size  Description
0x00    4     SP (Stack Pointer) - 0x001a0000
0x04    4     Reset Vector (entry point) - 0x001201a9 (thumb bit set)
0x08-0x1F  24 Other IVT entries (NMI, HardFault, etc.)
0x20    4     Magic: "WFFW" (57 46 46 57)
0x24-0x9F ?  Section table + metadata
0x100+  ...   Actual code (ARM Thumb-2)
```

## Address Mapping

- File offset 0x00 = Runtime address 0x100000 (chip load base)
- File offset 0x100 = Runtime address 0x100100
- v14 pipeline user-space address = 0x1200000 + file_offset
- Chip runtime address = 0x100000 + file_offset

So conversion:
- v14_addr -> chip_runtime: subtract 0x1100000
- file_offset -> v14_addr: add 0x1200000
- file_offset -> chip_runtime: add 0x100000

## Boot Sequence

Reset vector: 0x001201a8 (Thumb mode)
This is the entry point that the chip's ROM bootloader jumps to on reset.

The first 4 bytes at the reset vector address are the function's first
instruction, which is typically:
- `push {r3-r11, lr}` (function prologue saving registers)
- Or `b <other_func>` (jump to another init function)

## Sections

The WFFW header at 0x20-0x9F contains section information. From observed
patterns, it appears to include:
- 0x2C-0x3F: 4 entries pointing to internal structures
- 0x44: 0x00134411 - code/data pointer
- 0x48: 0x0014beb1 - another pointer (likely end of code section)
- 0x4C-0x5C: more pointers
- 0x60-0x64: pointers near the IVT area

The exact structure varies between binaries but follows this pattern.

## Files

- `fmacfw_8800d80_h_u02.bin` (341KB) - host-side MAC firmware
- `fmacfw_8800d80_u02.bin` (341KB) - MAC firmware (no h)
- `fmacfwbt_8800d80_u02.bin` (341KB) - Bluetooth firmware
- `lmacfw_rf_8800d80_u02.bin` (254KB) - low-MAC/RF firmware
- `fw_patch_8800d80_u02.bin` (24KB) - patch/bootloader
- `fw_patch_table_8800d80_u02.bin` (23KB) - patch table
- `fw_adid_8800d80_u02.bin` (1.7KB) - ADID (chip ID) data

## Init/Boot Code

Currently MISSING from the integrated C source:
- 10,015 TODO stubs (8% of total function bodies)
- These are mostly:
  - mm_* (MAC management): mm_set_idle_req_handler, mm_sta_add_cfm_handler, etc.
  - sm_* (state machine): sm_connect_req_handler, sm_auth_send, etc.
  - ke_* (kernel event): ke_msg_alloc, ke_timer_set, etc.
  - phy_* (physical layer): phy_set_channel, phy_hw_set_channel, etc.
  - txl_* (transmit list): txl_cfm_evt, txl_frame_push, etc.
  - scan_*, rc_*, hal_*, ipc_*, etc.

These are high-level dispatchers that v14 behavioral tracing couldn't capture
because they don't directly touch MMIO - they call other functions.

To complete the runnable replacement, we need to:
1. Use r2 disasm to find the function entry points
2. Look at the call graph to see which functions they call
3. Use LLM-assisted decompilation to reconstruct the C body
