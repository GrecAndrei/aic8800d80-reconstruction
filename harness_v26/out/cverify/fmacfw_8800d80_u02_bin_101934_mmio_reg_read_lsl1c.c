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

#define off_10194C ((uint32_t)0x403410a8u)
#define off_101950 ((uint32_t)0x403410acu)
// mmio_reg_read_lsl1c @ 0x101934, size 24 bytes
// Doc: mmio_reg_read_lsl1c [util]: Reads MMIO register and applies left-shift by 0x1c on value
// mmio_reg_read_lsl1c [util]: Reads MMIO register and applies left-shift by 0x1c on value
int  mmio_reg_read_lsl1c(int result, int a2, int a3)
{
  if ( (*(uint32_t *)off_10194C & 8) != 0 )
  {
    result = sub_11ED58(result, a2, a3, *(uint32_t *)off_10194C << 28);
    *(uint32_t *)off_101950 = 8;
  }
  return result;
}

