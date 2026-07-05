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

#define off_10DBCC ((uint32_t)0x40505000u)
// irq_disable @ 0x10dbb8, size 18 bytes
// Doc: irq_disable [util]: Clear interrupt bit in NVIC/IRQ mask register
// irq_disable [util]: Clear interrupt bit in NVIC/IRQ mask register
int  irq_disable(char a1)
{
  int result; // r0

  result = 1 << a1;
  *(uint32_t *)off_10DBCC &= ~result;
  return result;
}

