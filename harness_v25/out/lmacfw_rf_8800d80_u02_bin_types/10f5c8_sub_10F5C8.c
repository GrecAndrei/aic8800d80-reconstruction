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

extern uint32_t off_10F5F8;

// sub_10F5C8 @ 0x10f5c8, size 48 bytes
// Doc: sub_120F5C8 [rf]: lmacfw RF initialization subroutine, stores bytes and calls helper
// sub_120F5C8 [rf]: lmacfw RF initialization subroutine, stores bytes and calls helper
int sub_10F5C8()
{
  uint8_t *v0; // r4
  char *v1; // r0

  v0 = off_10F5F8;
  v1 = (char *)off_10F5F8 + 1624;
  *((uint16_t *)off_10F5F8 + 810) = 80;
  v0[1622] = 81;
  sub_11E71C(v1);
  *((uint16_t *)v0 + 1216) = 39;
  v0[2434] = 40;
  return sub_11E71C(v0 + 2436);
}

