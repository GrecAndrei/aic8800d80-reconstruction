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

extern uint32_t off_1372D8;
extern uint32_t off_1372DC;

// sub_1372A8 @ 0x1372a8, size 48 bytes
int sub_1372A8()
{
  uint8_t *v0; // r2
  char v1; // r3
  unsigned int v2; // r1

  v0 = off_1372D8;
  v1 = *((uint8_t *)off_1372D8 + 3851);
  if ( !v1 )
  {
    v2 = *((uint16_t *)off_1372D8 + 2);
    if ( v2 >= 7 )
      v2 = 7;
    *(uint32_t *)off_1372DC = *(uint32_t *)off_1372DC & 0xFFFFFE3F | (v2 << 6);
  }
  v0[3851] = v1 + 1;
  sub_1383E0();
  return 0;
}

