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

extern uint32_t dword_127CB4;
extern uint32_t off_127CB8;
extern uint32_t dword_127CBC;

// sub_127BF4 @ 0x127bf4, size 190 bytes
int  sub_127BF4(uint8_t *a1, uint8_t *a2)
{
  int v2; // r6
  int v5; // r3
  int i; // r5
  int v7; // r0
  char v8; // r6
  int v9; // r1
  unsigned int v11; // r1
  unsigned int v12; // r2
  int v13; // r0
  uint32_t *v14; // r1
  int16_t v15; // lr
  int v16; // r2

  v2 = dword_127CB4;
  v5 = dword_127CB4;
  for ( i = 0; i != 3; ++i )
  {
    if ( *(uint8_t *)(v5 + 24) != 255
      && *(uint8_t *)(v5 + 4) == *a1
      && *(uint16_t *)(v5 + 6) == *((uint16_t *)a1 + 1) )
    {
      v11 = *(uint8_t *)(v5 + 5);
      v12 = a1[1];
      if ( v11 == v12 )
      {
        if ( *(uint16_t *)(v5 + 8) == *((uint16_t *)a1 + 2)
          && *(uint16_t *)(v5 + 10) == *((uint16_t *)a1 + 3) )
        {
          goto LABEL_16;
        }
      }
      else
      {
        if ( v11 < v12 && v11 != 3 )
        {
          v13 = dword_127CB4 + 28 * i;
          v14 = off_127CB8;
          *(uint8_t *)(v13 + 5) = v12;
          v15 = *((uint16_t *)a1 + 2);
          *(uint16_t *)(v13 + 10) = *((uint16_t *)a1 + 3);
          v16 = v14[10];
          *(uint16_t *)(v13 + 8) = v15;
          if ( v16 == v13 && *((uint8_t *)v14 + 90) == 1 )
            sub_102970((uint16_t *)(v2 + 28 * i + 4), 0);
LABEL_16:
          *a2 = i;
          return 0;
        }
        if ( v11 > v12 && v12 != 3 )
          goto LABEL_16;
      }
    }
    v5 += 28;
  }
  v7 = sub_12D190(off_127CB8);
  if ( !v7 )
    return 1;
  v8 = dword_127CBC * ((v7 - v2) >> 2);
  *(uint8_t *)(v7 + 24) = v8;
  *a2 = v8;
  v9 = *((uint32_t *)a1 + 1);
  *(uint32_t *)(v7 + 4) = *(uint32_t *)a1;
  *(uint32_t *)(v7 + 8) = v9;
  *(uint16_t *)(v7 + 12) = *((uint16_t *)a1 + 4);
  return 0;
}

