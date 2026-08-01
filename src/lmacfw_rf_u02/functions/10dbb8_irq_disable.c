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

extern uint32_t off_10DBCC;

// gpio_clear_pin @ 0x10dbb8, size 18 bytes
// Doc: gpio_clear_pin [util]: Clear interrupt bit in NVIC/IRQ mask register
// gpio_clear_pin [util]: Clear interrupt bit in NVIC/IRQ mask register
int  gpio_clear_pin(char a1)
{
  int result; // r0

  result = 1 << a1;
  *(uint32_t *)off_10DBCC &= ~result;
  return result;
}

