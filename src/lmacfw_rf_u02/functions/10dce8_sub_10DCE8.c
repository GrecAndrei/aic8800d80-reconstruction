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

extern uint32_t dword_10DD18;
extern uint32_t off_10DD1C;

// gpio_init_pin_12 @ 0x10dce8, size 48 bytes
int gpio_init_pin_12()
{
  int result; // r0
  uint32_t *v1; // r3

  result = call_slot_0x1b8(dword_10DD18, 4096, 15360);
  v1 = off_10DD1C;
  *((uint32_t *)off_10DD1C + 2) |= 0xFu;
  v1[2] |= 0x10000000u;
  v1[3] &= 0xFFFFF7FE;
  return result;
}

