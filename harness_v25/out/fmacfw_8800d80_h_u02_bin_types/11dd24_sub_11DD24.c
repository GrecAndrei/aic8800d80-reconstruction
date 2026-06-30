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

extern uint32_t off_11DE34;
extern uint32_t off_11DE38;
extern uint32_t off_11DE28;
extern uint32_t dword_11DE30;
extern uint32_t dword_11DE2C;

// sub_11DD24 @ 0x11dd24, size 258 bytes
uint32_t * sub_11DD24(uint32_t *a1, unsigned int a2, int a3, uint32_t *a4, int a5)
{
  uint8_t **v5; // r9
  uint32_t *v6; // r7
  int v7; // r5
  int v8; // r12
  int16_t **v9; // r10
  uint32_t *v10; // r6
  uint32_t *result; // r0
  unsigned int v13; // r4
  int v14; // r3
  uint32_t *v15; // r3
  uint32_t *v16; // r11
  int v17; // r4
  int16_t v18; // r3
  signed int v19; // r2
  uint32_t *v20; // r3
  uint16_t *v22; // [sp+Ch] [bp-8h]

  v5 = (uint8_t **)off_11DE34;
  v6 = (uint32_t *)*a1;
  v7 = *(uint16_t *)a4;
  v8 = **(uint8_t **)off_11DE34;
  v9 = (int16_t **)off_11DE38;
  v22 = a4;
  if ( a2 >= 0x640 )
    a2 = 1600;
  if ( v8 == 3 )
    a4 = off_11DE28;
  v10 = &v6[12 * a5 + 5];
  if ( v8 == 3 )
    *a4 = v10;
  result = 0;
  while ( 1 )
  {
    v17 = v6[2];
    v18 = v6[3] + 1;
    v19 = (uint16_t)(v18 - v17);
    v10[1] = a3;
    *v10 = v7 + v17;
    if ( (int)(a2 + v7) >= v19 )
    {
      v13 = (uint16_t)(v17 - v18 + v7 + a2);
      a2 = (uint16_t)(v19 - v7);
      v7 = 0;
    }
    else
    {
      v13 = 0;
    }
    if ( v8 == 3 )
    {
      v14 = a2;
      if ( a2 >= 0x800 )
        v14 = 2048;
      v10[2] = v14 | 0xA3000000;
      v10[3] = a2;
      v10[4] = a2;
      v10[5] = 262148;
    }
    a3 += a2;
    if ( !v13 )
      break;
    v15 = (uint32_t *)v6[1];
    v16 = v15 + 5;
    if ( **v9 < 0 && !v15 )
    {
      sub_12F32C(dword_11DE30, dword_11DE2C, 928);
      v15 = 0;
      v8 = **v5;
    }
    if ( v8 == 3 )
      v10[8] = v16;
    result = v6;
    v10 = v16;
    v6 = v15;
    a2 = v13;
  }
  if ( v8 == 3 )
  {
    v20 = off_11DE28;
    v10[8] = 0;
    v20[1] = v10;
  }
  *a1 = v6;
  *v22 = v7;
  return result;
}

