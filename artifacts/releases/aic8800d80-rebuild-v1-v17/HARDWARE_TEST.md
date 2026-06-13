# Hardware Test Path

The user has an AIC8800D80 WiFi chip. To actually test the v17 binaries:

## Step 1: Identify the chip's debug interface

The AIC8800D80 is a WiFi+BT SoC. Common debug interfaces:
- **UART**: TX/RX on GPIO pads, default 115200 baud
- **JTAG/SWD**: TCK/TMS/TDI/TDO on test pads (need to identify from datasheet)
- **SDIO**: The chip can be a WiFi SDIO device (most common in laptops)

Look for a UART header on the board. Connect a USB-UART adapter at 3.3V.

## Step 2: Identify the boot sequence

The chip's ROM bootloader reads `fw_patch.bin` first, then `fw_patch_table.bin`, then one of the WFFW files (depending on which mode).

```
ROM bootloader (in chip)
    ↓ loads
fw_patch.bin (24KB)  -- patch table
    ↓ loads
fw_patch_table.bin (23KB)  -- entry table
    ↓ loads
fmacfw_8800d80_h_u02.bin (341KB)  -- main firmware
```

The reset vector in all 4 WFFW files points to 0x1201a8, which is mid-function in `fcn.00120130`. This is the boot entry after fw_patch has set things up.

## Step 3: Try connecting

1. **Power on the chip with original firmware**: should output something on UART (debug prints). Verify the UART is wired correctly.
2. **Replace with v17 firmware**: power on, look for any output. Most likely: nothing, because v17 code is incomplete.
3. **Use a logic analyzer or scope** to check if the chip is doing anything (clock, GPIO toggles, SDIO activity).

## Step 4: What's needed to make v17 boot

The v17 WFFW has a custom entry that calls v17_main, which calls:
- v17_subsystems_init
- v17_rf_init
- v17_mac_init
- v17_tx_init
- v17_rx_init
- v17_ke_init

All of these are empty stubs. Even if the chip boots our code, it does nothing useful.

To make the chip actually do WiFi, we'd need:
1. Properly initialize the clock tree (the `clock_calc` function)
2. Initialize the SDIO host interface (`feature_guard_sdio`)
3. Initialize the radio PHY (`rf_*` functions)
4. Bring up the kernel scheduler (`ke_*` functions)

This is roughly 100-200 critical functions, of which we've named ~5K. The implementation is still mostly stubs.

## Step 5: What we can verify

Even without full boot, we can verify:
- **The chip can read our WFFW**: if it CRC-errors, the WFFW format is wrong
- **The chip executes our code**: trace GPIO/SDIO activity, see if it differs from baseline
- **Specific functions work**: if we can write a small test that calls one function (e.g., `rf_bus_read` for a known register) and observe the result, we can validate one piece at a time

## Practical recommendation

**Before hardware test**: 
1. Build a v18 where the init functions are properly implemented (not stubs)
2. Focus on the 25 truth-lane functions: get them all to a real implementation
3. Add register-level documentation: which address means what, what's the boot sequence

**With the chip**:
1. Connect UART, see what comes out
2. Replace one WFFW at a time, see what breaks
3. Don't expect full WiFi; expect to find bugs in our reconstruction

The path from "v17 compiles" to "v18 boots the chip" is roughly:
- 25 truth-lane functions fully implemented
- Boot sequence (reset vector → v17_main → init → idle) complete
- IRQ vector table installed
- At least one MMIO register write observable

Estimated effort: 1-2 weeks of focused reverse engineering on those 25 functions + IRQ handling.
