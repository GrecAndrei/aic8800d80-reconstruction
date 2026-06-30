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

extern uint32_t off_1371D4;
extern uint32_t off_1371D8;

// sub_1371A4 @ 0x1371a4, size 48 bytes
// Doc: sub_12371A4 [util]: Helper reading shared flag/state at offset 0xf0b
// sub_12371A4 [util]: Helper reading shared flag/state at offset 0xf0b
int sub_1371A4()
{
  uint8_t *v0; // r2
  char v1; // r3
  unsigned int v2; // r1

  v0 = off_1371D4;
  v1 = *((uint8_t *)off_1371D4 + 3851);
  if ( !v1 )
  {
    v2 = *((uint16_t *)off_1371D4 + 2);
    if ( v2 >= 7 )
      v2 = 7;
    *(uint32_t *)off_1371D8 = *(uint32_t *)off_1371D8 & 0xFFFFFE3F | (v2 << 6);
  }
  v0[3851] = v1 + 1;
  sub_1382DC();
  return 0;
}

