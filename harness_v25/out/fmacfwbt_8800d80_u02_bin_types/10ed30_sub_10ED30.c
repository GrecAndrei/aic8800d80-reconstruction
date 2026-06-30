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

extern uint32_t dword_10ED64;
extern uint32_t dword_10ED60;
extern uint32_t dword_10ED68;

// sub_10ED30 @ 0x10ed30, size 46 bytes
int  sub_10ED30(int a1)
{
  rf_reg_write_guard(dword_10ED64, 196608, dword_10ED60, 1);
  sub_10EC30(dword_10ED68, a1 << 15, 1);
  return rf_reg_write_guard(1879048192, 1, 1, 1);
}

