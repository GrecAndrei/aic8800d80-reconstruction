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

extern uint32_t off_137120;

// sub_1370CC @ 0x1370cc, size 82 bytes
int  sub_1370CC(int a1, int a2, int a3, int a4)
{
  uint16_t *v4; // r2
  uint64_t v6; // r0
  uint8_t *v8; // r0
  int v9; // r0

  v4 = off_137120;
  *((uint16_t *)off_137120 + 1924) = a4;
  v4[1925] = 0;
  v6 = *(uint64_t *)(a2 + 352);
  *(uint32_t *)v4 = a2;
  *((uint32_t *)v4 + 963) = v6;
  v4[1928] = WORD2(v6);
  if ( a4 == 11 || a4 == 6 )
  {
    sub_138668(v6);
    return 1;
  }
  else
  {
    v8 = (uint8_t *)sub_12C92C(4105, a4, 4, 2u);
    v8[1] = 1;
    *v8 = *(uint8_t *)(a2 + 366);
    v9 = sub_12C98C((int)v8);
    sub_138668(v9);
    return 1;
  }
}

