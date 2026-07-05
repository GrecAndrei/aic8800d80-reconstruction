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

#define off_11C79C ((uint32_t)0x40320324u)
// mmio_set_bit7 @ 0x11c790, size 12 bytes
// Doc: mmio_set_bit7 [mmio]: Set bit 0x80 in MMIO register at 0x40320324
// mmio_set_bit7 [mmio]: Set bit 0x80 in MMIO register at 0x40320324
void mmio_set_bit7()
{
  *(uint32_t *)off_11C79C |= 0x80u;
}

