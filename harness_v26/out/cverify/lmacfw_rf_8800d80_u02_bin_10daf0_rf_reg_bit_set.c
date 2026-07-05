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

#define off_10DB00 ((uint32_t)0x4010b000u)
// rf_reg_bit_set @ 0x10daf0, size 16 bytes
// Doc: rf_reg_bit_set [mmio]: Sets a bit in RF MMIO register at 0x4010b000
// rf_reg_bit_set [mmio]: Sets a bit in RF MMIO register at 0x4010b000
int  rf_reg_bit_set(char a1)
{
  int result; // r0

  result = (1 << a1) | *((uint32_t *)off_10DB00 + 2);
  *((uint32_t *)off_10DB00 + 2) = result;
  return result;
}

