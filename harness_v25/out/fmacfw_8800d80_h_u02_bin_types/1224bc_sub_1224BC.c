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

extern uint32_t off_122644;
extern uint32_t off_122648;
extern uint32_t dword_12264C;
extern uint32_t off_122650;

// sub_1224BC @ 0x1224bc, size 392 bytes
int  sub_1224BC(int a1, int a2, int a3, int *a4)
{
  int v4; // r7
  int v5; // r11
  int v6; // r9
  int v7; // r4
  int v9; // r0
  int v10; // r2
  int v11; // r3
  uint32_t *v12; // r3
  int v13; // r1
  int v14; // r0
  int *v15; // r7
  uint8_t *v16; // r1
  int v17; // r8
  unsigned int v18; // r4
  int v19; // r5
  uint8_t *v20; // r10
  int result; // r0
  int v23; // [sp+10h] [bp-Ch]
  int v24; // [sp+10h] [bp-Ch]
  int v25; // [sp+14h] [bp-8h]

  v4 = a1;
  v5 = *(uint16_t *)(a1 + 28);
  v6 = *(uint32_t *)(*(uint32_t *)(a1 + 8) + 8);
  v7 = a2;
  v25 = *(uint32_t *)(a2 + 124);
  v9 = sub_12DA20(v6 + 36, (uint16_t)(v5 - 36));
  if ( !v9 )
    goto LABEL_7;
  v10 = *(uint8_t *)(v9 + 2);
  v11 = *((uint8_t *)off_122644 + 36);
  if ( !*((uint8_t *)off_122644 + 36) )
  {
    if ( (unsigned int)(v10 - 1) <= 0xD )
    {
      if ( v10 == 14 )
        v11 = 2484;
      else
        v11 = 5 * v10 + 2407;
    }
LABEL_6:
    if ( *(uint16_t *)(v7 + 414) != v11 )
      goto LABEL_8;
    goto LABEL_7;
  }
  if ( v11 == 1 && (uint8_t)(v10 - 1) <= 0xB0u )
  {
    v11 = 5 * v10 + 5000;
    goto LABEL_6;
  }
  if ( !*(uint16_t *)(v7 + 414) )
LABEL_7:
    *(uint8_t *)(v7 + 128) = 0;
LABEL_8:
  if ( *(uint8_t *)(v7 + 147) )
  {
    sub_12249C(*(uint8_t *)(v7 + 107), 1);
    *(uint16_t *)(v7 + 146) = 0;
    *(uint8_t *)(v7 + 148) = 0;
  }
  v12 = off_122648;
  *(uint8_t *)(v7 + 141) = 1;
  if ( dword_12264C - v12[4] + *(uint32_t *)(v7 + 120) < 0 && !sub_118F4C(*(uint8_t *)(v7 + 116), 0, 0) )
    *(uint32_t *)(v7 + 120) = *((uint32_t *)off_122648 + 4);
  v23 = *(char *)(v4 + 45);
  sub_101A40();
  v13 = v23;
  if ( *((uint8_t *)off_122650 + 17) == 1 )
  {
    sub_1221B4((uint32_t *)v7, v23);
    v13 = v23;
  }
  sub_121FE4((uint8_t *)v7, v13);
  v14 = sub_12D3B4(v6 + 32, 4, 0);
  *a4 = 0;
  if ( (uint16_t)(v5 - 36) > 1u )
  {
    v24 = v4;
    v15 = a4;
    v16 = (uint8_t *)(v6 + 36);
    v17 = v7;
    v18 = (uint16_t)(v5 - 36);
    do
    {
      v19 = (uint8_t)v16[1];
      v20 = v16 + 2;
      if ( v19 + 1 >= (int)v18 )
        break;
      if ( *v16 == 5 )
        *v15 = (int)v16;
      else
        v14 = sub_12D3B4(v20, (uint8_t)v16[1], v14);
      v18 = (uint16_t)(v18 + -2 - v19);
      v16 = &v20[v19];
    }
    while ( v18 > 1 );
    v7 = v17;
    a4 = v15;
    v4 = v24;
  }
  *(uint32_t *)(v7 + 124) = v14;
  sub_120700(v6, v5, v4, v7, a3, *a4);
  result = sub_12CD48(4);
  if ( result != 1 )
    return *(uint32_t *)(v7 + 124) != v25;
  return result;
}

