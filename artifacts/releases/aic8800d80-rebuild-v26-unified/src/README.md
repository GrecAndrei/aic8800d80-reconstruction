# AIC8800D80 Reconstructed C Source Tree (`src/`)

This directory contains the finalized, human-readable **C source tree** for the AIC8800D80 Wi-Fi and Bluetooth firmware binaries.

---

## Directory Structure

```
src/
├── Makefile                     # Build & syntax validation Makefile
├── README.md                    # This documentation file
├── include/                     # Shared C headers
│   ├── aic8800d80_mmio.h        # 25,815 MMIO register definitions
│   ├── aic8800d80_structs.h     # Inferred C struct type definitions
│   └── aic8800d80_types.h       # Standard C99 types & byte macro definitions
├── fmacfw_u02/                  # FullMAC Wi-Fi Main Controller Firmware
│   ├── main.c                   # Single-file composed C device source
│   └── functions/               # Individual per-function C source files
├── fmacfw_h_u02/                # FullMAC Host Interface Firmware
│   ├── main.c                   # Single-file composed C device source
│   └── functions/               # Individual per-function C source files
├── fmacfwbt_u02/                # Bluetooth Combo Controller Firmware
│   ├── main.c                   # Single-file composed C device source
│   └── functions/               # Individual per-function C source files
└── lmacfw_rf_u02/               # LowMAC RF & Signal Controller Firmware
    ├── main.c                   # Single-file composed C device source
    └── functions/               # Individual per-function C source files
```

---

## Build & Syntax Verification

To verify syntax across all four firmware C source targets using `gcc` or `arm-none-eabi-gcc`:

```bash
make -C src check
```

---

## Technical Features

1. **Clean C99 Types**: All Hex-Rays MSVC types (`_DWORD`, `_BYTE`, `__int64`) have been refactored into standard C99 integer types (`uint32_t`, `uint8_t`, `int64_t`).
2. **Deterministic Struct Recovery**: All 1,394 memory access patterns are represented as C struct layouts.
3. **Symbol Propagation**: Function names and handler names are synchronized across image boundaries.
