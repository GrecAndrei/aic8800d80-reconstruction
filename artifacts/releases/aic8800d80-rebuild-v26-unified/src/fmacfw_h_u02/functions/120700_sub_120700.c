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

extern uint32_t off_120A14;
extern uint32_t dword_120A64;
extern uint32_t off_120A18;
extern uint32_t off_120A1C;
extern uint32_t off_120A20;
extern uint32_t dword_120A3C;
extern uint32_t dword_120A38;
extern uint32_t off_120A24;
extern uint32_t dword_120A34;
extern uint32_t off_120A28;
extern uint32_t off_120A2C;
extern uint32_t dword_120A60;
extern uint32_t off_120A30;
extern uint32_t off_120A44;
extern uint32_t off_120A40;
extern uint32_t off_120A4C;
extern uint32_t off_120A48;
extern uint32_t off_120A54;
extern uint32_t off_120A50;
extern uint32_t dword_120A8C;
extern uint32_t dword_120A5C;
extern uint32_t dword_120A58;

// sub_120700 @ 0x120700, size 898 bytes
int  sub_120700(int a1, int a2, int a3, int a4, int a5, int a6)
{
  unsigned int v8; // r9
  int v9; // r3
  unsigned int v10; // r7
  unsigned int v11; // r11
  int v12; // r10
  int v13; // r5
  char *v14; // r2
  int v15; // r8
  int *v16; // r0
  uint32_t *v17; // r2
  int16_t **v18; // r3
  int v19; // r5
  char *v20; // r1
  int *v21; // r0
  uint32_t *v22; // r1
  int v23; // r6
  int v24; // r5
  int v25; // r2
  unsigned uint64_t v26; // kr08_8
  uint64_t v27; // r0
  int v28; // r3
  unsigned uint64_t v29; // r0
  unsigned int v30; // r2
  int v31; // r1
  uint32_t *v32; // r6
  int v33; // r5
  int v34; // r2
  int v35; // r3
  int result; // r0
  uint8_t *v37; // r3
  uint32_t *v38; // r2
  uint8_t *v39; // r5
  int v40; // r1
  uint8_t *v41; // r1
  uint32_t *v42; // r2
  unsigned int v43; // [sp+8h] [bp-1Ch]
  int v44; // [sp+10h] [bp-14h]
  unsigned int v45; // [sp+14h] [bp-10h]
  int v47; // [sp+1Ch] [bp-8h]

  v8 = *(uint32_t *)(a3 + 32);
  v9 = *(uint16_t *)(a1 + 32);
  v45 = *(uint32_t *)(a3 + 36);
  v10 = *(uint32_t *)(a1 + 24);
  v11 = *(uint32_t *)(a1 + 28);
  v12 = v9 << 10;
  if ( !*(uint8_t *)(a4 + 106) && (v13 = *(uint16_t *)(a4 + 112), *(uint16_t *)(a4 + 112)) )
  {
    sub_12ADC8(*(uint8_t *)(a4 + 107), v9, (uint8_t)v13);
    v47 = v12 * v13;
  }
  else if ( a6 )
  {
    v13 = *(uint8_t *)(a6 + 2);
    if ( !*(uint8_t *)(a6 + 2) )
    {
      v13 = *(uint8_t *)(a6 + 3);
      sub_12ADC8(*(uint8_t *)(a4 + 107), v9, v13);
    }
    v47 = v12 * v13;
  }
  else
  {
    v47 = v9 << 10;
    v13 = 1;
  }
  v44 = v13 * *(uint16_t *)(a5 + 30);
  if ( *(uint8_t *)(a3 + 40) << 28 )
  {
    v23 = 500;
    v24 = 0;
  }
  else
  {
    v14 = (char *)off_120A14;
    v15 = dword_120A64;
    v16 = (int *)off_120A18;
    *(uint32_t *)off_120A14 = *(uint8_t *)(dword_120A64 + (*(uint8_t *)(a3 + 44) >> 4)) & 0x7F
                          | *(uint32_t *)off_120A14 & 0xFFFFFF80;
    v17 = v14 + 8;
    *v16 = a2 | (*(uint8_t *)(a3 + 40) >> 7 << 20);
    *v17 = 0x80000000;
    __dsb(0xFu);
    while ( (*v17 & 0xC0000000) != 0x40000000 )
      ;
    v18 = (int16_t **)off_120A1C;
    if ( **(int16_t **)off_120A1C >= 0 || (*v17 & 0x40000000) != 0 )
    {
      v19 = (uint16_t)*(uint32_t *)off_120A20;
    }
    else
    {
      sub_12F2C8(dword_120A3C, dword_120A38, 430, off_120A1C);
      v19 = 500;
      v18 = (int16_t **)off_120A1C;
    }
    if ( !(*(uint8_t *)(a3 + 40) << 28) )
    {
      v20 = (char *)off_120A14;
      v21 = (int *)off_120A18;
      *(uint32_t *)off_120A14 = *(uint8_t *)(v15 + (*(uint8_t *)(a3 + 44) >> 4)) & 0x7F
                            | *(uint32_t *)off_120A14 & 0xFFFFFF80;
      v22 = v20 + 8;
      *v21 = (*(uint8_t *)(a3 + 40) >> 7 << 20) | 0x18;
      *v22 = 0x80000000;
      __dsb(0xFu);
      while ( (*v22 & 0xC0000000) != 0x40000000 )
        ;
      if ( **v18 >= 0 || (*v22 & 0x40000000) != 0 )
      {
        v23 = (uint16_t)*(uint32_t *)off_120A20;
        v24 = v19 - v23;
        goto LABEL_15;
      }
      sub_12F2C8(dword_120A3C, dword_120A38, 430, 2 * *v22);
    }
    v24 = v19 - 500;
    v23 = 500;
  }
LABEL_15:
  v25 = *(uint8_t *)(a4 + 106);
  v26 = __PAIR64__(v11, v10) - __PAIR64__(v45, v8) + (unsigned int)v24;
  *(uint64_t *)(a4 + 40) = v26;
  if ( !v25 )
  {
    *(uint32_t *)(a4 + 132) = v26;
    *(uint32_t *)(a4 + 136) = v44 + 400;
  }
  v27 = sub_1432D4(v10, v11, v12, v12 >> 31);
  v43 = v10 - v23;
  v28 = v27 * (v12 >> 31) + v12 * HIDWORD(v27);
  v29 = (unsigned int)v27 * (unsigned uint64_t)(unsigned int)v12;
  HIDWORD(v29) += v28;
  if ( v29 < __PAIR64__(v11, v10) - (unsigned int)v23 )
    v43 = v29;
  v30 = v43 + v47;
  if ( (*(uint32_t *)off_120A24 & 0x2000000) != 0 )
    v31 = dword_120A34 - v44 - v26 + v30;
  else
    v31 = v30 - v44 - 400;
  v32 = off_120A28;
  v33 = *((uint32_t *)off_120A28 + 4) - *(uint32_t *)off_120A2C + v31;
  if ( v33 - v32[4] - 4300 - sub_101944() < 0 )
    v33 += v12;
  if ( (*(uint32_t *)(a4 + 4) & 1) != 0 )
  {
    v35 = *(uint8_t *)(a4 + 85);
    if ( (v35 & 2) != 0 && v33 - *((uint32_t *)off_120A28 + 4) - 10000 < 0 )
    {
      v33 += v12;
      sub_12E948(dword_120A60, v35 << 30, v34);
    }
  }
  result = v33 - *((uint32_t *)off_120A28 + 4) - 4300 - sub_101944();
  if ( result >= 0 && *(uint32_t *)(a4 + 36) != v33 )
  {
    v37 = off_120A30;
    if ( *((uint32_t *)off_120A30 + 8) != a4 || (v38 = off_120A24, *(uint32_t *)(a4 + 36) = v33, (*v38 & 0x2000000) != 0) )
    {
      sub_124BFC(a4 + 24, v33);
    }
    else
    {
      v39 = (uint8_t *)off_120A44;
      v40 = (uint8_t)v37[36];
      *(uint8_t *)off_120A44 = BYTE2(*(uint32_t *)off_120A40);
      if ( !v40 )
      {
        v41 = *(uint8_t **)off_120A4C;
        v39[1] = *(uint32_t *)off_120A48;
        v37[36] = 1;
        if ( *v41 == 1 )
        {
          v42 = off_120A54;
          *(uint32_t *)off_120A50 = 1;
          *v42 |= 1u;
        }
        if ( *v39 >= (unsigned int)v39[1] )
          sub_12E948(dword_120A8C, *v39, v39[1]);
        if ( **(int16_t **)off_120A1C < 0 && *v39 >= (unsigned int)v39[1] )
          sub_12F32C(dword_120A5C, dword_120A58, 523);
      }
    }
    return sub_127FDC(a4);
  }
  return result;
}

