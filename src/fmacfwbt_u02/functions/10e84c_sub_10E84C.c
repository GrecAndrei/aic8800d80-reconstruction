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


extern uint32_t off_10E95C;
extern uint32_t off_10E968;

// sub_10E84C @ 0x10e84c, size 272 bytes
int  sub_10E84C(int a1)
{
  uint16_t *v1; // r9
  int v2; // r7
  int v3; // r5
  int v4; // r3
  unsigned int *v5; // r8
  int v6; // r6
  int v7; // r10
  int v8; // r2
  int v9; // r4
  int v10; // r3
  int v11; // r0
  int v12; // r3
  int v14; // r1
  int v15; // r2
  int v16; // [sp+0h] [bp-Ch]
  int v17; // [sp+4h] [bp-8h]

  v1 = (uint16_t *)off_10E968;
  *(uint32_t *)off_10E95C = (a1 << 26) & 0x1C000000 | *(uint32_t *)off_10E95C & 0xE3FFFFFF;
  v2 = a1;
  v3 = sub_10E040();
  sub_12ECB0("cal start, reg_init=%d, i_pa_init=%d, i_pa_target=%d\n", v2, v3, *v1);
  v4 = *v1;
  if ( v4 > v3 )
  {
    v16 = 1;
  }
  else
  {
    if ( v4 >= v3 )
      return 0;
    v16 = -1;
  }
  v5 = (unsigned int *)off_10E95C;
  v17 = v2;
  v6 = 4;
  v7 = 0;
  while ( 1 )
  {
    v2 += v16;
    if ( v2 <= 7 )
    {
      if ( v2 < 0 )
      {
        v2 = 0;
        v8 = 0;
        v7 = -v17;
      }
      else
      {
        v8 = v2 << 26;
        v7 += v16;
      }
    }
    else
    {
      v8 = 469762048;
      v7 = 7 - v17;
      v2 = 7;
    }
    *v5 = *v5 & 0xE3FFFFFF | v8;
    v9 = sub_10E040();
    sub_12ECB0("reg_val=%d, i_pa=%d\n", v2, v9);
    v10 = *v1;
    v11 = v9 - v10;
    v12 = v3 - v10;
    if ( v12 * v11 <= 0 )
      break;
    --v6;
    v3 = v9;
    if ( !v6 )
      return v7;
  }
  v14 = v12;
  if ( v12 < 0 )
    v14 = -v12;
  if ( v11 < 0 )
    v11 = -v11;
  v15 = v9;
  if ( v14 <= v11 )
  {
    v7 -= v16;
    v15 = v3;
    *v5 = ((v2 - v16) << 26) & 0x1C000000 | *v5 & 0xE3FFFFFF;
  }
  sub_12ECB0("cal done, offset_res=%d, i_pa_res=%d\n", v7, v15);
  return v7;
}
