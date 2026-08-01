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

extern uint32_t off_10DB80;

// gpio_clear_bit_reg0 @ 0x10db6c, size 18 bytes
int  gpio_clear_bit_reg0(char a1)
{
  int result; // r0

  result = 1 << a1;
  *(uint32_t *)off_10DB80 &= ~result;
  return result;
}

