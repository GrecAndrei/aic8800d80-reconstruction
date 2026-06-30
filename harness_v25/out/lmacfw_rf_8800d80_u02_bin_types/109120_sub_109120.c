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

// sub_109120 @ 0x109120, size 98 bytes
int  sub_109120(uint64_t a1, int a2, uint32_t *a3)
{
  uint8_t v3; // r5
  uint32_t *v4; // r6
  int v5; // r4
  uint32_t *v6; // r3

  if ( a1 )
  {
    LODWORD(a1) = HIDWORD(a1) + a1;
    if ( (uint32_t)a1 )
    {
      HIDWORD(a1) = 0;
      while ( 1 )
      {
        v3 = BYTE4(a1) + 1;
        v4 = &a3[HIDWORD(a1)];
        if ( *v4 <= a2 )
          break;
        HIDWORD(a1) = v3;
        if ( v3 >= (int)a1 )
          goto LABEL_12;
      }
      LODWORD(a1) = (uint8_t)a1;
      if ( (unsigned int)(uint8_t)a1 > HIDWORD(a1) )
      {
        v5 = (int)&a3[(uint8_t)a1 - 1 - (uint8_t)(a1 - 1 - BYTE4(a1))];
        v6 = &a3[(uint8_t)a1];
        do
        {
          *v6 = *(v6 - 1);
          --v6;
        }
        while ( v6 != (uint32_t *)v5 );
      }
      *v4 = a2;
    }
    else
    {
LABEL_12:
      a3[(uint32_t)a1] = a2;
    }
  }
  else
  {
    *a3 = a2;
  }
  return a1;
}

