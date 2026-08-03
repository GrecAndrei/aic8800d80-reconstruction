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

// sub_14054C @ 0x14054c, size 94 bytes
int  sub_14054C(int a1, int a2, int a3)
{
  int v3; // r3
  int v4; // r4
  uint8_t *v5; // r2
  uint8_t *v6; // r0
  int v7; // t1
  uint8_t *v9; // r2
  uint8_t *v10; // r3
  int v11; // t1

  if ( !a3 )
    return 1;
  v3 = *(uint32_t *)(a3 + 8);
  if ( v3 )
  {
    if ( a1 != 255 )
    {
      if ( v3 > 0 )
      {
        v9 = (uint8_t *)(a3 + 12);
        v10 = &v9[v3];
        while ( 1 )
        {
          v11 = *v9++;
          if ( v11 == a1 )
            break;
          if ( v9 == v10 )
            return 0;
        }
        return 1;
      }
      return 0;
    }
    v4 = *(uint32_t *)(a3 + 20);
LABEL_5:
    if ( v4 > 0 )
    {
      v5 = (uint8_t *)(a3 + 24);
      v6 = &v5[v4];
      while ( 1 )
      {
        v7 = *v5++;
        if ( a2 == v7 )
          break;
        if ( v5 == v6 )
          return 0;
      }
      return 1;
    }
    return 0;
  }
  v4 = *(uint32_t *)(a3 + 20);
  if ( !v4 )
    return 1;
  if ( a1 == 255 )
    goto LABEL_5;
  return *(uint32_t *)(a3 + 8);
}

