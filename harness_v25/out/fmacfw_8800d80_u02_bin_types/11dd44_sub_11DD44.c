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

extern uint32_t off_11DE50;
extern uint32_t off_11DE60;
extern uint32_t dword_11DE58;
extern uint32_t dword_11DE54;
extern uint32_t dword_11DE5C;

// sub_11DD44 @ 0x11dd44, size 266 bytes
// Doc: sub_121DD44 [util]: Generic entry, pushes 9 regs; init routine
// sub_121DD44 [util]: Generic entry, pushes 9 regs; init routine
uint32_t * sub_11DD44(uint32_t *a1, int a2, uint16_t *a3)
{
  int *v3; // r7
  int v4; // r10
  uint32_t *v5; // r6
  int16_t **v6; // r11
  uint32_t *v7; // r8
  int v9; // r9
  int v10; // r5
  int v11; // r0
  int v12; // r3
  uint32_t *v13; // r4
  int v14; // r2
  int v15; // r0
  int v16; // r1
  uint32_t *v17; // r3
  int16_t v18; // r5
  int16_t v19; // r2
  int v20; // r1
  int v22; // [sp+8h] [bp-14h]
  int v23; // [sp+8h] [bp-14h]
  int16_t v24; // [sp+8h] [bp-14h]
  uint32_t *v25; // [sp+Ch] [bp-10h]

  v3 = (int *)off_11DE50;
  v4 = (uint16_t)*a3;
  v5 = (uint32_t *)*a1;
  v6 = (int16_t **)off_11DE60;
  v7 = 0;
  *((uint8_t *)off_11DE50 + 32) = 1;
  v9 = 0;
  v25 = 0;
  while ( 1 )
  {
    v18 = *((uint16_t *)v5 + 4);
    v19 = v5[3] + 1;
    v20 = (uint16_t)(v19 - v18);
    if ( a2 + v4 >= v20 )
      break;
    v23 = a2;
    v11 = sub_1102BC();
    v10 = 0;
    v12 = v23;
    v9 = 1;
    v13 = (uint32_t *)v11;
    if ( !v11 )
      goto LABEL_15;
LABEL_5:
    v14 = v3[1];
    if ( !v14 )
      *v3 = v11;
    v15 = **v6;
    v3[3] += v12;
    v3[1] = v14 + 1;
    v16 = v5[2];
    if ( v15 < 0 && !v16 )
    {
      v24 = v12;
      sub_12F46C(dword_11DE58, dword_11DE54, 683);
      v16 = v5[2];
      LOWORD(v12) = v24;
    }
    sub_11113C(v13, v16, 0, v12, v9);
    if ( v7 )
      v7[1] = v13;
    v3[2] = (int)v13;
    if ( !v10 )
      goto LABEL_16;
    v17 = (uint32_t *)v5[1];
    if ( **v6 < 0 && !v17 )
    {
      sub_12F46C(dword_11DE5C, dword_11DE54, 704);
      v17 = 0;
    }
    v25 = v5;
    v7 = v13;
    v5 = v17;
    a2 = v10;
  }
  v10 = (uint16_t)(v18 + a2 + v4 - v19);
  v22 = (uint16_t)(v20 - v4);
  if ( !v10 )
    v9 = 1;
  v11 = sub_1102BC();
  v4 = 0;
  v12 = v22;
  v13 = (uint32_t *)v11;
  if ( v11 )
    goto LABEL_5;
LABEL_15:
  *((uint8_t *)v3 + 32) = v11;
LABEL_16:
  *a1 = v5;
  *a3 = v4;
  return v25;
}

