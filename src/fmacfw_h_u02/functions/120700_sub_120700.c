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


extern uint32_t dword_120A34;
extern uint32_t off_120A14;
extern uint32_t off_120A18;
extern uint32_t off_120A1C;
extern uint32_t off_120A20;
extern uint32_t off_120A24;
extern uint32_t off_120A2C;
extern uint32_t off_120A30;
extern uint32_t off_120A40;
extern uint32_t off_120A44;
extern uint32_t off_120A48;
extern uint32_t off_120A4C;
extern uint32_t off_120A50;
extern uint32_t off_120A54;
extern uint32_t off_120A64;
extern uint32_t off_120A84;
extern uint32_t off_120A88;

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
  int *v15; // r8
  int *v16; // r0
  uint32_t *v17; // r2
  uint16_t **v18; // r3
  int v19; // r5
  char *v20; // r1
  int *v21; // r0
  uint32_t *v22; // r1
  int v23; // r6
  int v24; // r5
  int v25; // r2
  uint64_t v26; // kr08_8
  uint64_t v27; // r0
  int v28; // r3
  uint64_t v29; // r0
  int v30; // r2
  int v31; // r1
  volatile unsigned int v32; // r5
  int v33; // r5
  signed int v34; // r0
  int v35; // r3
  int v36; // r1
  volatile unsigned int v37; // r3
  int v38; // r0
  volatile unsigned int v39; // r3
  int result; // r0
  uint8_t *v41; // r3
  uint32_t *v42; // r2
  uint8_t *v43; // r5
  int v44; // r1
  uint8_t *v45; // r1
  uint32_t *v46; // r2
  uint64_t v47; // [sp+8h] [bp-1Ch]
  int v48; // [sp+10h] [bp-14h]
  unsigned int v49; // [sp+14h] [bp-10h]
  int v51; // [sp+1Ch] [bp-8h]

  v8 = *(uint32_t *)(a3 + 32);
  v9 = *(uint16_t *)(a1 + 32);
  v49 = *(uint32_t *)(a3 + 36);
  v10 = *(uint32_t *)(a1 + 24);
  v11 = *(uint32_t *)(a1 + 28);
  v12 = v9 << 10;
  if ( !*(uint8_t *)(a4 + 106) && (v13 = *(uint16_t *)(a4 + 112), *(uint16_t *)(a4 + 112)) )
  {
    sub_12ADC8(*(uint8_t *)(a4 + 107), v9, (uint8_t)v13);
    v51 = v12 * v13;
  }
  else if ( a6 )
  {
    v13 = *(uint8_t *)(a6 + 2);
    if ( !*(uint8_t *)(a6 + 2) )
    {
      v13 = *(uint8_t *)(a6 + 3);
      sub_12ADC8(*(uint8_t *)(a4 + 107), v9, v13);
    }
    v51 = v12 * v13;
  }
  else
  {
    v51 = v9 << 10;
    v13 = 1;
  }
  v48 = v13 * *(uint16_t *)(a5 + 30);
  if ( *(uint8_t *)(a3 + 40) << 28 )
  {
    v23 = 500;
    v24 = 0;
  }
  else
  {
    v14 = (char *)off_120A14;
    v15 = (int *)off_120A64;
    v16 = (int *)off_120A18;
    *(uint32_t *)off_120A14 = *((uint8_t *)off_120A64 + (*(uint8_t *)(a3 + 44) >> 4)) & 0x7F
                          | *(uint32_t *)off_120A14 & 0xFFFFFF80;
    v17 = v14 + 8;
    *v16 = a2 | (*(uint8_t *)(a3 + 40) >> 7 << 20);
    *v17 = 0x80000000;
    __dsb(0xFu);
    while ( (*v17 & 0xC0000000) != 0x40000000 )
      ;
    v18 = (uint16_t **)off_120A1C;
    if ( **(uint16_t **)off_120A1C >= 0 || (*v17 & 0x40000000) != 0 )
    {
      v19 = (uint16_t)*(uint32_t *)off_120A20;
    }
    else
    {
      sub_12F2C8((int)aNxmacTimeOnAir, (int)aHalMachwRxBcnD, 430);
      v19 = 500;
      v18 = (uint16_t **)off_120A1C;
    }
    if ( !(*(uint8_t *)(a3 + 40) << 28) )
    {
      v20 = (char *)off_120A14;
      v21 = (int *)off_120A18;
      *(uint32_t *)off_120A14 = *((uint8_t *)v15 + (*(uint8_t *)(a3 + 44) >> 4)) & 0x7F
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
      sub_12F2C8((int)aNxmacTimeOnAir, (int)aHalMachwRxBcnD, 430);
    }
    v24 = v19 - 500;
    v23 = 500;
  }
LABEL_15:
  v25 = *(uint8_t *)(a4 + 106);
  v26 = __PAIR64__(v11, v10) - __PAIR64__(v49, v8) + (unsigned int)v24;
  *(uint64_t *)(a4 + 40) = v26;
  if ( !v25 )
  {
    *(uint32_t *)(a4 + 132) = v26;
    *(uint32_t *)(a4 + 136) = v48 + 400;
  }
  v27 = sub_1432D4(__PAIR64__(v11, v10), v12);
  v47 = __PAIR64__(v11, v10) - (unsigned int)v23;
  v28 = v27 * (v12 >> 31) + v12 * HIDWORD(v27);
  v29 = (unsigned int)v27 * (uint64_t)(unsigned int)v12;
  HIDWORD(v29) += v28;
  if ( v29 < v47 )
    v47 = v29;
  v30 = v47 + v51;
  if ( (*(uint32_t *)off_120A24 & 0x2000000) != 0 )
    v31 = dword_120A34 - v48 - v26 + v30;
  else
    v31 = v30 - v48 - 400;
  v32 = (*(volatile uint32_t *)0x40501010u);
  v33 = v32 - *(uint32_t *)off_120A2C + v31;
  v34 = v33 - (*(volatile uint32_t *)0x40501010u) - 4300 - sub_101944();
  if ( v34 < 0 )
    v33 += v12;
  if ( (*(uint32_t *)(a4 + 4) & 1) != 0 )
  {
    v35 = *(uint8_t *)(a4 + 85);
    v36 = v35 << 30;
    if ( (v35 & 2) != 0 )
    {
      v37 = (*(volatile uint32_t *)0x40501010u);
      if ( (int)(v33 - v37 - 10000) < 0 )
      {
        v33 += v12;
        sub_12E948(aMoveTbtt, v36);
      }
    }
  }
  v38 = sub_101944();
  v39 = (*(volatile uint32_t *)0x40501010u);
  result = v33 - v39 - 4300 - v38;
  if ( result >= 0 && *(uint32_t *)(a4 + 36) != v33 )
  {
    v41 = off_120A30;
    if ( *((uint32_t *)off_120A30 + 8) != a4 || (v42 = off_120A24, *(uint32_t *)(a4 + 36) = v33, (*v42 & 0x2000000) != 0) )
    {
      sub_124BFC((uint32_t *)(a4 + 24), v33);
    }
    else
    {
      v43 = (uint8_t *)off_120A44;
      v44 = (uint8_t)v41[36];
      *(uint8_t *)off_120A44 = BYTE2(*(uint32_t *)off_120A40);
      if ( !v44 )
      {
        v45 = *(uint8_t **)off_120A4C;
        v43[1] = *(uint32_t *)off_120A48;
        v41[36] = 1;
        if ( *v45 == 1 )
        {
          v46 = off_120A54;
          *(uint32_t *)off_120A50 = 1;
          *v46 |= 1u;
        }
        if ( *v43 >= (unsigned int)v43[1] )
          sub_12E948(
            "dtim:%d,%d,%d,%d\r\n",
            *v43,
            v43[1],
            HIWORD(*(uint32_t *)off_120A88),
            (uint8_t)*(uint32_t *)off_120A84);
        if ( **(uint16_t **)off_120A1C < 0 && *v43 >= (unsigned int)v43[1] )
          sub_12F32C((int)aVolatileUint8T, (int)aMmTbttCompute, 523);
      }
    }
    return sub_127FDC(a4);
  }
  return result;
}
