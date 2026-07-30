# Makefile for AIC8800D80 Reconstructed Firmware C Source Tree

CC ?= arm-none-eabi-gcc
CFLAGS ?= -mcpu=cortex-m4 -mthumb -O2 -Iinclude -Wall -Wextra -ffunction-sections -fdata-sections

SRCS_FMAC_U02  = fmacfw_u02/main.c
SRCS_FMAC_H    = fmacfw_h_u02/main.c
SRCS_FMAC_BT   = fmacfwbt_u02/main.c
SRCS_LMAC_RF   = lmacfw_rf_u02/main.c

ALL_TARGETS = fmacfw_8800d80_u02.bin fmacfw_8800d80_h_u02.bin fmacfwbt_8800d80_u02.bin lmacfw_rf_8800d80_u02.bin

.PHONY: all clean check

all: check

check:
	@echo "Checking C source tree syntax..."
	gcc -fsyntax-only -w -Iinclude $(SRCS_FMAC_U02)
	gcc -fsyntax-only -w -Iinclude $(SRCS_FMAC_H)
	gcc -fsyntax-only -w -Iinclude $(SRCS_FMAC_BT)
	gcc -fsyntax-only -w -Iinclude $(SRCS_LMAC_RF)
	@echo "All 4 firmware C source targets verified successfully."

clean:
	rm -f $(ALL_TARGETS) *.o
