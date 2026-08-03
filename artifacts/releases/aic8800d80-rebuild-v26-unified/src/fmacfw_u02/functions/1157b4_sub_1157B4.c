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

extern uint32_t off_1157D4;

// sub_1157B4 @ 0x1157b4, size 32 bytes
int sub_1157B4()
{
  int v0; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r0

  *((uint8_t *)off_1157D4 + 1) = 0;
  v0 = sub_12F4E8();
  v1 = sub_1321C8(v0);
  v2 = sub_120720(v1);
  v3 = sub_12D210(v2);
  return sub_12F508(v3);
}

