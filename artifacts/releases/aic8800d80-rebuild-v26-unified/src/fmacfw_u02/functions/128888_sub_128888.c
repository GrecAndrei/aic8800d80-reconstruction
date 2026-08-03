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

extern uint32_t off_128ACC;
extern uint32_t dword_128AA8;
extern uint32_t dword_128A9C;
extern uint32_t dword_128AB4;
extern uint32_t dword_128AB0;
extern uint32_t dword_128AB8;
extern uint32_t off_128AD0;
extern uint32_t dword_128AC0;
extern uint32_t dword_128AC8;
extern uint32_t dword_128ABC;
extern uint32_t dword_128AC4;
extern uint32_t dword_128AA0;
extern uint32_t dword_128AA4;
extern uint32_t off_128AAC;

// sub_128888 @ 0x128888, size 530 bytes
// Doc: sub_1228888 [scan]: Scan/index lookup using signed halfword key and rsb scaling
// sub_1228888 [scan]: Scan/index lookup using signed halfword key and rsb scaling
int  sub_128888(int a1, int a2)
{
  int16_t **v2; // r10
  int v3; // r8
  int v4; // r7
  int v7; // r6
  int v8; // r9
  int v9; // r1
  uint8_t *v10; // r11
  int v11; // r3
  int v12; // r2
  uint8_t *v13; // r3
  int v14; // r2
  int v15; // r3
  int v16; // r2
  int result; // r0
  int v18; // r3
  char v19; // r0
  int16_t *v20; // r3
  unsigned int v21; // r2
  int v22; // r3
  int v23; // r3
  int v24; // r1

  v2 = (int16_t **)off_128ACC;
  v3 = dword_128AA8;
  v4 = dword_128A9C;
  v7 = dword_128AA8 + 28 * a2;
  if ( **(int16_t **)off_128ACC >= 0
    || *(uint32_t *)(dword_128A9C + 1320 * a1 + 72) && (sub_12F46C(dword_128AB4, dword_128AB0, 3061), **v2 >= 0) )
  {
    v8 = 8 * a2;
  }
  else
  {
    v8 = 8 * a2;
    if ( *(uint8_t *)(v3 + 28 * a2 + 24) == 255 )
      sub_12F46C(dword_128AB8, dword_128AB0, 3062);
  }
  v9 = v3 + 4 * (v8 - a2);
  v10 = off_128AD0;
  v11 = v4 + 1320 * a1;
  v12 = (uint8_t)(*(uint8_t *)(v9 + 25) + 1);
  *(uint8_t *)(v9 + 25) = v12;
  *(uint32_t *)(v11 + 72) = v7;
  *(uint8_t *)(v11 + 85) = 0;
  if ( v12 == 1 )
  {
    v19 = v10[90];
    *(uint8_t *)(v9 + 16) = 1;
    v20 = *v2;
    v21 = (uint8_t)(v19 + 1);
    v10[90] = v21;
    if ( *v20 < 0 && v21 > 2 )
    {
      sub_12F46C(dword_128AC0, dword_128AB0, 3082);
      v21 = (uint8_t)v10[90];
    }
    if ( v21 == 2 )
    {
      sub_12D240(dword_128AC8);
      v23 = dword_128A9C;
      v24 = dword_128A9C + 5280;
      do
      {
        *(uint8_t *)(v23 + 85) &= ~1u;
        v23 += 1320;
      }
      while ( v24 != v23 );
    }
    list_push_tail(dword_128ABC);
    if ( (v10[88] & 0xC) != 0 )
    {
      v22 = *((uint32_t *)v10 + 8);
      if ( **v2 < 0 && !v22 )
      {
        sub_12F46C(dword_128AC4, dword_128AB0, 3097);
        v22 = 0;
      }
      *(uint32_t *)(v22 + 8) = v7;
    }
    else if ( *((uint32_t *)v10 + 11) )
    {
      *((uint32_t *)v10 + 11) = v7;
    }
    else
    {
      sub_1270CC(v7);
    }
  }
  feature_guard_check(256, dword_128AA0);
  v13 = (uint8_t *)(v4 + 1320 * a1);
  v14 = (uint8_t)v13[1224];
  v13[86] = -1;
  if ( v14 && *(uint8_t *)(dword_128AA4 + 140 * (uint8_t)v13[1225] + 112) == 1 )
  {
    v13[85] |= 0x10u;
  }
  else
  {
    v15 = dword_128AA8;
    while ( 1 )
    {
      if ( *(uint8_t *)(v15 + 24) != 255 )
      {
        v16 = *(uint8_t *)(v15 + 27);
        if ( v16 != 255 )
          break;
      }
      v15 += 28;
      if ( dword_128AA8 + 84 == v15 )
        goto LABEL_10;
    }
    if ( *(uint32_t *)(v4 + 1320 * v16 + 72) != v7 )
      *(uint8_t *)(v4 + 1320 * a1 + 85) |= 0x10u;
  }
LABEL_10:
  result = sub_128548(v7);
  v18 = *((uint8_t *)off_128AAC + 16);
  if ( v18 != a1 && v18 != 255 )
    return sub_128AD4(a2);
  return result;
}

