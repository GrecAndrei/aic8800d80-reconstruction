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

extern uint32_t dword_129F74;
extern uint32_t off_129F78;
extern uint32_t dword_129F88;
extern uint32_t dword_129F84;
extern uint32_t off_129F80;
extern uint32_t off_129F7C;

// lookup_table_entry @ 0x129ebc, size 182 bytes
// Doc: sub_1229EBC [util]: Computes array offset via mla with stride 0x528 and reads from data table
// sub_1229EBC [util]: Computes array offset via mla with stride 0x528 and reads from data table
unsigned int  lookup_table_entry(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // r6
  int v6; // r7
  unsigned int v7; // r5
  unsigned int v8; // r3
  unsigned int v9; // r5
  int16_t **v10; // r3
  uint32_t *v11; // r2
  unsigned int v12; // r3
  unsigned int result; // r0
  uint32_t *v14; // r1

  v4 = a3;
  v6 = dword_129F74 + 1320 * a2;
  if ( a4 < a3 )
  {
    v9 = 0;
  }
  else
  {
    if ( *(uint8_t *)(a1 + 19) == 1 )
      return 0;
    v7 = *(uint32_t *)(a1 + 28);
    v8 = (a4 - a3) / v7;
    v4 = a3 + v7 + v8 * v7;
    v9 = v8 + 1;
  }
  v10 = (int16_t **)off_129F78;
  *(uint32_t *)(a1 + 44) = v4;
  if ( **v10 < 0 && *(uint8_t *)(v6 + 106) )
    mmio_irq_clear(dword_129F88, dword_129F84, 98);
  v11 = off_129F80;
  v12 = *(uint8_t *)(a1 + 19);
  result = *((uint32_t *)off_129F80 + 4) - *(uint32_t *)off_129F7C - *(uint32_t *)(v6 + 132) + v4;
  if ( v12 == 255 )
  {
    if ( (int)(result - *((uint32_t *)off_129F80 + 4)) < 0 )
      goto LABEL_10;
    return result;
  }
  if ( v12 > v9 )
    LOBYTE(v12) = v12 - v9;
  else
    LOBYTE(v12) = 0;
  v12 = (uint8_t)v12;
  *(uint8_t *)(a1 + 19) = v12;
  if ( (int)(result - v11[4]) < 0 )
  {
LABEL_10:
    v14 = off_129F80;
    while ( v12 )
    {
      while ( 1 )
      {
        result += *(uint32_t *)(a1 + 28);
        if ( v12 != 255 )
          break;
        if ( (int)(result - v14[4]) >= 0 )
          return result;
      }
      v12 = (uint8_t)(v12 - 1);
      *(uint8_t *)(a1 + 19) = v12;
      if ( (int)(result - v14[4]) >= 0 )
        goto LABEL_14;
    }
    return 0;
  }
LABEL_14:
  if ( !v12 )
    return 0;
  return result;
}

