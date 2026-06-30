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

extern uint32_t dword_10EF0C;
extern uint32_t dword_10EF08;
extern uint32_t dword_10EF10;

// sub_10EED8 @ 0x10eed8, size 46 bytes
int  sub_10EED8(int a1)
{
  sub_10EE2C(dword_10EF0C, 196608, dword_10EF08, 1);
  rf_reg_write_wait(dword_10EF10, a1 << 15, 1);
  return sub_10EE2C(1879048192, 1, 1, 1);
}

