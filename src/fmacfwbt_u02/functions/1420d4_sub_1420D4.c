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

extern uint32_t off_1420F4;

// clear_data_flag @ 0x1420d4, size 30 bytes
// Doc: sub_12420D4 [util]: Initialize firmware state register
// sub_12420D4 [util]: Initialize firmware state register
int  clear_data_flag(int a1)
{
  int result; // r0
  uint8_t *v3; // r2
  char v4; // r3

  result = set_conn_flag(a1);
  v3 = off_1420F4;
  *(uint16_t *)a1 &= ~1u;
  v4 = *v3 - 1;
  *(uint8_t *)(a1 + 2) = 0;
  *v3 = v4;
  return result;
}

