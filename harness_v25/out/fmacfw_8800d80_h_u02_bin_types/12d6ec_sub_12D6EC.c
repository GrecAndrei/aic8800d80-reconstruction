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

extern uint32_t off_12D750;
extern uint32_t dword_12D758;
extern uint32_t dword_12D754;

// sub_12D6EC @ 0x12d6ec, size 100 bytes
uint8_t * sub_12D6EC(uint8_t *a1, int a2, int a3, uint16_t *a4)
{
  unsigned int v4; // r7
  unsigned int v5; // r12
  int v6; // r6
  int v7; // r4
  uint8_t *v8; // r5

  v4 = (unsigned int)&a1[a2];
  v5 = (unsigned int)&a1[a2];
  if ( a1 < &a1[a2] )
  {
    while ( 1 )
    {
      v8 = a1;
      if ( v4 <= (unsigned int)(a1 + 1) )
        break;
      v6 = *a1;
      v7 = a1[1] + 2;
      a1 += v7;
      if ( v6 == 255 )
      {
        if ( v4 < (unsigned int)a1 )
          return 0;
        *a4 = v7;
        if ( !v8 || (unsigned int)(v8 + 3) > v5 )
          return 0;
        if ( v8[2] == a3 )
          return v8;
        a2 = (uint16_t)(a2 - v7);
        if ( v5 <= (unsigned int)a1 )
          goto LABEL_13;
        v4 = (unsigned int)&a1[a2];
      }
    }
  }
  else
  {
LABEL_13:
    if ( **(int16_t **)off_12D750 < 0 && (uint8_t *)v5 != a1 )
      sub_12F35C(dword_12D758, dword_12D754, 127);
  }
  return 0;
}

