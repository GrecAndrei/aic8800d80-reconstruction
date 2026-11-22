# Makefile for AIC8800D80 Reconstructed Firmware C Source Tree

CROSS_COMPILE ?= arm-none-eabi-
CC            = $(CROSS_COMPILE)gcc
OPT           ?= -O2
# The source is decompiler output, so the compiler must read it with the
# machine's semantics, not ISO C's: Hex-Rays `char` is the signed 8-bit type
# (unsigned is always spelled uint8_t), arithmetic wraps, address 0 is mapped
# (boot ROM callback slots), and objects are accessed through casts of any type.
DIALECT       = -fsigned-char -fwrapv -fno-delete-null-pointer-checks -fno-strict-aliasing
CFLAGS        = -mcpu=cortex-m4 -mthumb $(OPT) $(DIALECT) -Iinclude -w -std=gnu99 -ffunction-sections -fdata-sections -include include/aic8800d80_types.h -Wno-int-conversion -Wno-incompatible-pointer-types -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast

SRCS_FMAC_U02  = fmacfw_u02/main.c
SRCS_FMAC_H    = fmacfw_h_u02/main.c
SRCS_FMAC_BT   = fmacfwbt_u02/main.c
SRCS_LMAC_RF   = lmacfw_rf_u02/main.c

ALL_TARGETS = fmacfw_8800d80_u02.o fmacfw_8800d80_h_u02.o fmacfwbt_8800d80_u02.o lmacfw_rf_8800d80_u02.o

.PHONY: all clean check reproduce

all: check

check:
	@echo "Compiling C source tree with ARM Cortex-M cross compiler..."
	$(CC) $(CFLAGS) -c $(SRCS_FMAC_U02) -o fmacfw_8800d80_u02.o
	$(CC) $(CFLAGS) -c $(SRCS_FMAC_H) -o fmacfw_8800d80_h_u02.o
	$(CC) $(CFLAGS) -c $(SRCS_FMAC_BT) -o fmacfwbt_8800d80_u02.o
	$(CC) $(CFLAGS) -c $(SRCS_LMAC_RF) -o lmacfw_rf_8800d80_u02.o
	@echo "SUCCESS: All 4 firmware C source targets compiled cleanly into ARM Cortex-M object modules."

# Regenerate the four main.c from src/<image>/functions/ (compose, heal, the
# mechanical rules) and fail if the result differs from the tracked files.
reproduce:
	cd .. && go build -trimpath -o bin/fwstruct ./cmd/fwstruct && bin/fwstruct compose
	cd .. && git diff --exit-code --stat -- src metadata/libmatch.json
	@echo "SUCCESS: a fresh compose reproduces the tracked src/."

clean:
	rm -f $(ALL_TARGETS) *.o
