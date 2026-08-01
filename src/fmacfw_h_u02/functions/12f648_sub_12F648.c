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

// split_on_dot @ 0x12f648, size 136 bytes
uint32_t * split_on_dot(int a1, uint32_t *a2, int a3)
{
  int v5; // r0
  int v6; // r11
  int v7; // r9
  uint32_t *v8; // r4
  int v9; // r5
  int v10; // r6
  uint32_t *v11; // r10

  v5 = memset(a1, 46);
  if ( v5 )
    v6 = v5 - a1;
  else
    v6 = memcpy_aligned(a1);
  if ( a3 )
  {
    v7 = 0;
    v8 = a2;
    v9 = 0;
    do
    {
      while ( 1 )
      {
        v10 = *v8;
        ++v9;
        v11 = v8;
        if ( !memcpy_fixed(a1, *v8, v6) )
          break;
        v8 += 4;
        if ( a3 == v9 )
          goto LABEL_9;
      }
      if ( memcpy_aligned(v10) == v6 )
        return v11;
      a2 = v8;
      ++v7;
      v8 += 4;
    }
    while ( a3 != v9 );
LABEL_9:
    if ( v7 == 1 )
      return a2;
  }
  return 0;
}

