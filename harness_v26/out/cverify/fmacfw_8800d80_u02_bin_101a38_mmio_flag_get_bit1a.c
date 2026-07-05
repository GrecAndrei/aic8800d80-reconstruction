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

#define off_101A44 ((uint32_t)0x40330000u)
// mmio_flag_get_bit1a @ 0x101a38, size 10 bytes
// Doc: mmio_flag_get_bit1a [mmio]: Read flag bit 0x1a from MMIO register 0x40330000
// mmio_flag_get_bit1a [mmio]: Read flag bit 0x1a from MMIO register 0x40330000
int mmio_flag_get_bit1a()
{
  return (*(uint32_t *)off_101A44 >> 26) & 1;
}

