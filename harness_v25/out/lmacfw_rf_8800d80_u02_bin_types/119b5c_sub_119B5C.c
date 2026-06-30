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

// sub_119B5C @ 0x119b5c, size 50 bytes
int  sub_119B5C(int a1, uint8_t *a2, int a3, int a4)
{
  int v7; // [sp+4h] [bp-8h]
  int v8; // [sp+4h] [bp-8h]

  if ( a2[2] )
  {
    v8 = a3;
    sub_11C540(*a2);
    a3 = v8;
  }
  v7 = a3;
  sub_11C38C(*a2, a2[1]);
  sub_11DED8(56, a4, v7);
  return 0;
}

