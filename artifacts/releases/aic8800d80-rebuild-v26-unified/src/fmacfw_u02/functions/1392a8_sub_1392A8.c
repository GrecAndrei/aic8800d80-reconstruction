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

// sub_1392A8 @ 0x1392a8, size 76 bytes
// Doc: sub_12392A8 [util]: Generic firmware helper, context unclear
// sub_12392A8 [util]: Generic firmware helper, context unclear
int  sub_1392A8(int result, unsigned int a2)
{
  uint16_t v2; // r2
  char v3; // r7
  char v4; // r4
  int v5; // r3
  int v6; // r3
  char v7; // r7
  int16_t v8; // r1

  if ( a2 )
  {
    v2 = 0;
    v3 = *(uint8_t *)(result + 10);
    do
    {
      v4 = *(uint8_t *)(result + 11);
      v5 = (v3 + (uint8_t)v2++) & 0x3F;
      v6 = result + 4 * v5;
      if ( !v4 )
        break;
      if ( *(uint32_t *)(v6 + 16) )
      {
        *(uint32_t *)(v6 + 16) = 0;
        *(uint8_t *)(result + 11) = v4 - 1;
      }
    }
    while ( v2 < a2 );
  }
  else
  {
    v3 = *(uint8_t *)(result + 10);
  }
  v7 = v3 + a2;
  v8 = (a2 + *(uint16_t *)(result + 8)) & 0xFFF;
  *(uint8_t *)(result + 10) = v7 & 0x3F;
  *(uint16_t *)(result + 8) = v8;
  return idx_table_lookup_n3958(result);
}

