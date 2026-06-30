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

extern uint32_t off_12D820;
extern uint32_t dword_12D828;
extern uint32_t dword_12D824;

// sub_12D788 @ 0x12d788, size 150 bytes
// Doc: sub_122D788 [util]: Memory copy/fill utility over a length range
// sub_122D788 [util]: Memory copy/fill utility over a length range
uint8_t * sub_12D788(uint8_t *a1, int a2, uint8_t *a3, int a4, uint16_t *a5)
{
  unsigned int v5; // r9
  unsigned int v6; // r7
  int v7; // lr
  uint8_t *v8; // r5
  int v9; // r4
  int v10; // r3
  uint8_t *v11; // r8
  uint8_t *v13; // r4
  uint8_t *v14; // r9
  int v15; // t1

  v5 = (unsigned int)&a1[a2];
  v6 = (unsigned int)&a1[a2];
  if ( a1 >= &a1[a2] )
  {
LABEL_15:
    if ( **(int16_t **)off_12D820 < 0 && (uint8_t *)v6 != a1 )
      sub_12F46C(dword_12D828, dword_12D824, 180);
  }
  else
  {
    v7 = a4 + 2;
    v8 = &a3[a4];
    while ( 1 )
    {
      v11 = a1;
      if ( v5 <= (unsigned int)(a1 + 1) )
        break;
      v9 = *a1;
      v10 = a1[1] + 2;
      a1 += v10;
      if ( v9 == 221 )
      {
        if ( v5 < (unsigned int)a1 )
          return 0;
        *a5 = v10;
        if ( !v11 || (unsigned int)&v11[v7] > v6 )
          return 0;
        v13 = a3;
        while ( 1 )
        {
          v14 = &v11[(uint32_t)v13];
          v15 = *v13++;
          if ( v15 != v14[2 - (uint32_t)a3] )
            break;
          if ( v13 == v8 )
            return v11;
        }
        a2 = (uint16_t)(a2 - v10);
        if ( v6 <= (unsigned int)a1 )
          goto LABEL_15;
        v5 = (unsigned int)&a1[a2];
      }
    }
  }
  return 0;
}

