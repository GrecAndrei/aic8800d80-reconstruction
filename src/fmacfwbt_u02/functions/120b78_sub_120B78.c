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


extern uint32_t dword_120EAC;
extern uint32_t off_120E8C;
extern uint32_t off_120E90;
extern uint32_t off_120E94;
extern uint32_t off_120E98;
extern uint32_t off_120E9C;
extern uint32_t off_120EA4;
extern uint32_t off_120EA8;
extern uint32_t off_120EB8;
extern uint32_t off_120EBC;
extern uint32_t off_120EC0;
extern uint32_t off_120EC4;
extern uint32_t off_120EC8;
extern uint32_t off_120ECC;
extern uint32_t off_120EDC;
extern uint32_t off_120EFC;
extern uint32_t off_120F00;

// sub_120B78 @ 0x120b78, size 898 bytes
int  sub_120B78(int a1, int a2, int a3, int a4, int a5, int a6)
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
    sub_12B12C(*(uint8_t *)(a4 + 107), v9, (uint8_t)v13);
    v51 = v12 * v13;
  }
  else if ( a6 )
  {
    v13 = *(uint8_t *)(a6 + 2);
    if ( !*(uint8_t *)(a6 + 2) )
    {
      v13 = *(uint8_t *)(a6 + 3);
      sub_12B12C(*(uint8_t *)(a4 + 107), v9, v13);
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
    v14 = (char *)off_120E8C;
    v15 = (int *)off_120EDC;
    v16 = (int *)off_120E90;
    *(uint32_t *)off_120E8C = *((uint8_t *)off_120EDC + (*(uint8_t *)(a3 + 44) >> 4)) & 0x7F
                          | *(uint32_t *)off_120E8C & 0xFFFFFF80;
    v17 = v14 + 8;
    *v16 = a2 | (*(uint8_t *)(a3 + 40) >> 7 << 20);
    *v17 = 0x80000000;
    __dsb(0xFu);
    while ( (*v17 & 0xC0000000) != 0x40000000 )
      ;
    v18 = (uint16_t **)off_120E94;
    if ( **(uint16_t **)off_120E94 >= 0 || (*v17 & 0x40000000) != 0 )
    {
      v19 = (uint16_t)*(uint32_t *)off_120E98;
    }
    else
    {
      sub_12F630((int)aNxmacTimeOnAir, (int)aHalMachwRxBcnD, 430);
      v19 = 500;
      v18 = (uint16_t **)off_120E94;
    }
    if ( !(*(uint8_t *)(a3 + 40) << 28) )
    {
      v20 = (char *)off_120E8C;
      v21 = (int *)off_120E90;
      *(uint32_t *)off_120E8C = *((uint8_t *)v15 + (*(uint8_t *)(a3 + 44) >> 4)) & 0x7F
                            | *(uint32_t *)off_120E8C & 0xFFFFFF80;
      v22 = v20 + 8;
      *v21 = (*(uint8_t *)(a3 + 40) >> 7 << 20) | 0x18;
      *v22 = 0x80000000;
      __dsb(0xFu);
      while ( (*v22 & 0xC0000000) != 0x40000000 )
        ;
      if ( **v18 >= 0 || (*v22 & 0x40000000) != 0 )
      {
        v23 = (uint16_t)*(uint32_t *)off_120E98;
        v24 = v19 - v23;
        goto LABEL_15;
      }
      sub_12F630((int)aNxmacTimeOnAir, (int)aHalMachwRxBcnD, 430);
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
  v27 = sub_1434B0(__PAIR64__(v11, v10), v12);
  v47 = __PAIR64__(v11, v10) - (unsigned int)v23;
  v28 = v27 * (v12 >> 31) + v12 * HIDWORD(v27);
  v29 = (unsigned int)v27 * (uint64_t)(unsigned int)v12;
  HIDWORD(v29) += v28;
  if ( v29 < v47 )
    v47 = v29;
  v30 = v47 + v51;
  if ( (*(uint32_t *)off_120E9C & 0x2000000) != 0 )
    v31 = dword_120EAC - v48 - v26 + v30;
  else
    v31 = v30 - v48 - 400;
  v32 = (*(volatile uint32_t *)0x40501010u);
  v33 = v32 - *(uint32_t *)off_120EA4 + v31;
  v34 = v33 - (*(volatile uint32_t *)0x40501010u) - 4300 - sub_10186C();
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
        sub_12ECB0(aMoveTbtt, v36);
      }
    }
  }
  v38 = sub_10186C();
  v39 = (*(volatile uint32_t *)0x40501010u);
  result = v33 - v39 - 4300 - v38;
  if ( result >= 0 && *(uint32_t *)(a4 + 36) != v33 )
  {
    v41 = off_120EA8;
    if ( *((uint32_t *)off_120EA8 + 8) != a4 || (v42 = off_120E9C, *(uint32_t *)(a4 + 36) = v33, (*v42 & 0x2000000) != 0) )
    {
      sub_124F60((uint32_t *)(a4 + 24), v33);
    }
    else
    {
      v43 = (uint8_t *)off_120EBC;
      v44 = (uint8_t)v41[36];
      *(uint8_t *)off_120EBC = BYTE2(*(uint32_t *)off_120EB8);
      if ( !v44 )
      {
        v45 = *(uint8_t **)off_120EC4;
        v43[1] = *(uint32_t *)off_120EC0;
        v41[36] = 1;
        if ( *v45 == 1 )
        {
          v46 = off_120ECC;
          *(uint32_t *)off_120EC8 = 1;
          *v46 |= 1u;
        }
        if ( *v43 >= (unsigned int)v43[1] )
          sub_12ECB0(
            "dtim:%d,%d,%d,%d\r\n",
            *v43,
            v43[1],
            HIWORD(*(uint32_t *)off_120F00),
            (uint8_t)*(uint32_t *)off_120EFC);
        if ( **(uint16_t **)off_120E94 < 0 && *v43 >= (unsigned int)v43[1] )
          sub_12F694((int)aVolatileUint8T, (int)aMmTbttCompute, 523);
      }
    }
    return sub_128340(a4);
  }
  return result;
}
