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

extern uint32_t dword_11AE24;
extern uint32_t dword_11AE0C;
extern uint32_t off_11AE10;
extern uint32_t dword_11AE20;
extern uint32_t dword_11AE1C;
extern uint32_t off_11AE14;
extern uint32_t dword_11AE28;
extern uint32_t dword_11AE2C;
extern uint32_t off_11AE18;

// sub_11AC74 @ 0x11ac74, size 406 bytes
// Doc: sub_121AC74 [unknown]: Multi-register dispatcher with branch on input code (cmp r0, 5)
// sub_121AC74 [unknown]: Multi-register dispatcher with branch on input code (cmp r0, 5)
int  sub_11AC74(int result)
{
  uint32_t *v1; // r5
  int16_t **v2; // r6
  uint32_t *v3; // r4
  int v4; // r3
  int v5; // r2
  int v6; // r7
  int *v7; // r4
  int v8; // r8
  int v9; // r3
  int *v10; // r6
  int v11; // r1
  unsigned int v12; // r3
  int v13; // r9
  int v14; // r4
  int v15; // r10
  int v16; // r3
  int v17; // r3
  int v18; // [sp+4h] [bp-4h] BYREF

  if ( result == 5 )
  {
    v1 = (uint32_t *)dword_11AE24;
  }
  else
  {
    result *= 21;
    v1 = (uint32_t *)(dword_11AE0C + 4 * result);
  }
  v2 = (int16_t **)off_11AE10;
  v3 = (uint32_t *)v1[3];
  if ( **(int16_t **)off_11AE10 < 0 && !v3 )
    result = sub_12F46C(dword_11AE20, dword_11AE1C, 3166);
  while ( 1 )
  {
    v4 = v3[9];
    if ( (v4 & 0x200000) != 0 )
      break;
    if ( *(int *)(v3[19] + 72) < 0 )
    {
      v3 = (uint32_t *)*v3;
      if ( v3 )
        continue;
    }
    return result;
  }
  v5 = **v2;
  if ( v5 >= 0 )
  {
    v6 = v3[17];
    v7 = *(int **)(v6 + 4 * ((uint8_t)*(uint32_t *)off_11AE14 + 82));
    v8 = v7[19];
LABEL_10:
    v9 = v7[9];
    goto LABEL_11;
  }
  if ( (v4 & 0x380000) == 0x280000 )
  {
    v6 = v3[17];
    v7 = *(int **)(v6 + 4 * ((uint8_t)*(uint32_t *)off_11AE14 + 82));
    v8 = v7[19];
  }
  else
  {
    sub_12F46C(dword_11AE28, dword_11AE1C, 3182);
    v6 = v3[17];
    v5 = **v2;
    v7 = *(int **)(v6 + 4 * ((uint8_t)*(uint32_t *)off_11AE14 + 82));
    v8 = v7[19];
    if ( v5 >= 0 )
      goto LABEL_10;
  }
  v9 = v7[9];
  if ( (v9 & 0x380000) == 0x380000 )
  {
    sub_12F46C(dword_11AE2C, dword_11AE1C, 3192);
    v9 = v7[9];
  }
  v5 = **v2;
LABEL_11:
  v10 = (int *)off_11AE18;
  v11 = *(uint32_t *)off_11AE18;
  v7[9] = v9 | 0x380000;
  v12 = v9 & 0xFFC7FEFF | 0x380100;
  if ( *(uint8_t *)(v11 + 1) )
  {
    v15 = v6 + 84;
    v13 = *(uint32_t *)(v6 + 88);
    v14 = *v7;
    *(uint32_t *)(v8 + 68) = v12;
    *(uint32_t *)(v8 + 20) = v6 + 84;
    if ( v5 >= 0 )
      goto LABEL_13;
  }
  else
  {
    v13 = *(uint32_t *)(v6 + 20);
    v14 = *v7;
    *(uint32_t *)(v8 + 68) = v12;
    *(uint32_t *)(v8 + 20) = 0;
    v15 = v6 + 16;
    if ( v5 >= 0 )
      goto LABEL_13;
  }
  if ( !v14 )
    sub_12F46C(dword_11AE20, dword_11AE1C, 3217);
LABEL_13:
  result = sub_11A940(v14, (int)&v18);
  if ( !result )
    return result;
  v16 = *v10;
  *(uint32_t *)(v15 + 4) = result;
  if ( *(uint8_t *)(v16 + 1) )
  {
    v17 = v18;
    *(uint32_t *)(v18 + 4) = v13;
    if ( v13 )
      return result;
    *v1 = v17;
  }
  else if ( (*(uint32_t *)(v18 + 56) & 0x200000) != 0 )
  {
    *(uint32_t *)(result + 4) = v13;
    if ( v13 )
      return result;
  }
  else
  {
    *(uint32_t *)(v18 + 4) = v13;
    if ( v13 )
      return result;
  }
  if ( (*(uint32_t *)(result + 56) & 0x200000) != 0 )
  {
    v1[1] = result;
    v1[2] = 1;
  }
  else
  {
    v1[1] = 0;
    v1[2] = 0;
  }
  return result;
}

