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

extern uint32_t off_141F18;

// clear_ll_flag @ 0x141ef8, size 30 bytes
int  clear_ll_flag(int a1)
{
  int result; // r0
  uint8_t *v3; // r2
  char v4; // r3

  result = update_ll_flags(a1);
  v3 = off_141F18;
  *(uint16_t *)a1 &= ~1u;
  v4 = *v3 - 1;
  *(uint8_t *)(a1 + 2) = 0;
  *v3 = v4;
  return result;
}

