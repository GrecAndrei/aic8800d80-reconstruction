#include <stdint.h>
#define BYTE1(x) ((uint8_t)(((uint32_t)(x) >> 8) & 0xFFu))
#define BYTE2(x) ((uint8_t)(((uint32_t)(x) >> 16) & 0xFFu))
#define BYTE3(x) ((uint8_t)(((uint32_t)(x) >> 24) & 0xFFu))
#define __noreturn
#define _VF 0
#define _CF 0
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <inttypes.h>

#define LOBYTE(x) ((uint8_t)((x) & 0xFF))
#define HIBYTE(x) ((uint8_t)(((x) >> 8) & 0xFF))
#define LOWORD(x) ((uint16_t)((x) & 0xFFFF))
#define HIWORD(x) ((uint16_t)(((x) >> 16) & 0xFFFF))
#define LODWORD(x) ((uint32_t)(x))
#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32)))

#define off_10D6A4 ((uint32_t)0x40032014u)
// mmio_reg_bit0_read @ 0x10d698, size 10 bytes
// Doc: mmio_reg_bit0_read [mmio]: Reads bit 0 of MMIO register at 0x40032014
// mmio_reg_bit0_read [mmio]: Reads bit 0 of MMIO register at 0x40032014
int mmio_reg_bit0_read()
{
  return *(uint32_t *)off_10D6A4 & 1;
}

