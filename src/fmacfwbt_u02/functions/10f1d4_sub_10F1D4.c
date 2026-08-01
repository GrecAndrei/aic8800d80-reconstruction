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

extern uint32_t off_10F204;

// send_msg @ 0x10f1d4, size 48 bytes
// Doc: sub_120F1D4 [util]: Initialize config struct fields and call sub
// sub_120F1D4 [util]: Initialize config struct fields and call sub
int send_msg()
{
  uint8_t *v0; // r4
  char *v1; // r0

  v0 = off_10F204;
  v1 = (char *)off_10F204 + 1624;
  *((uint16_t *)off_10F204 + 810) = 80;
  v0[1622] = 81;
  zero_struct(v1);
  *((uint16_t *)v0 + 1216) = 39;
  v0[2434] = 40;
  return zero_struct(v0 + 2436);
}

