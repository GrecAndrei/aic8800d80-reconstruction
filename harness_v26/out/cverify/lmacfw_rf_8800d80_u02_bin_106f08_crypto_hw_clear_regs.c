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

#define off_106F68 ((uint32_t)0x403420ccu)
#define off_106F6C ((uint32_t)0x403420d0u)
#define off_106F70 ((uint32_t)0x403420d4u)
// crypto_hw_clear_regs @ 0x106f08, size 96 bytes
// Doc: crypto_hw_clear_regs [util]: Clear crypto engine HW control/status registers
// crypto_hw_clear_regs [util]: Clear crypto engine HW control/status registers
uint32_t *crypto_hw_clear_regs()
{
  unsigned int *v0; // r2
  uint32_t *v1; // r3
  uint32_t *result; // r0

  v0 = (unsigned int *)off_106F68;
  v1 = off_106F6C;
  result = off_106F70;
  *(uint32_t *)off_106F68 = *(uint32_t *)off_106F68 & 0xC0FFFFFF | 0x3000000;
  *v0 = *v0 & 0xFFC0FFFF | 0x30000;
  *v0 = *v0 & 0xFFFFC0FF | 0x300;
  *v0 = *v0 & 0xFFFFFFC0 | 3;
  *v1 &= 0xC0FFFFFF;
  *v1 &= 0xFFC0FFFF;
  *v1 &= 0xFFFFC0FF;
  *v1 &= 0xFFFFFFC0;
  *result &= 0xFFFFFFC0;
  return result;
}

