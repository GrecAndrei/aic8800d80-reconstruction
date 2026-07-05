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

#define off_11E0B0 ((uint32_t)0x4032010cu)
#define off_11E0AC ((uint32_t)0x40320324u)
// mmio_reg_bit_modify @ 0x11e080, size 44 bytes
// Doc: mmio_reg_bit_modify [mmio]: Reads/modifies MMIO register at 0x40320xxx by setting/clearing a bit field from index
// mmio_reg_bit_modify [mmio]: Reads/modifies MMIO register at 0x40320xxx by setting/clearing a bit field from index
unsigned int  mmio_reg_bit_modify(int a1)
{
  unsigned int *v1; // r1
  unsigned int result; // r0

  v1 = (unsigned int *)off_11E0B0;
  *(uint32_t *)off_11E0AC = (a1 << 10) & 0x400 | *(uint32_t *)off_11E0AC & 0xFFFFFBFF;
  result = (a1 << 19) & 0x80000 | *v1 & 0xFFF7FFFF;
  *v1 = result;
  return result;
}

