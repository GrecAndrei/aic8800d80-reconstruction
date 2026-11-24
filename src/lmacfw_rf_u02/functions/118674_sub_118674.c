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


extern uint32_t off_11889C;
extern uint32_t off_1188A0;
extern uint32_t off_1188A4;
extern uint32_t off_1188A8;
extern uint32_t off_1188B0;
extern uint32_t off_1188B4;
extern uint32_t off_1188C0;

// sub_118674 @ 0x118674, size 550 bytes
int  sub_118674(int a1, int a2, int a3, uint32_t *a4, int a5, int a6)
{
  unsigned int v7; // r4
  uint64_t v8; // r10
  int v10; // r5
  int v11; // r3
  char *v12; // r2
  int *v13; // r9
  int *v14; // r0
  uint32_t *v15; // r2
  uint16_t **v16; // r3
  int v17; // r8
  char *v18; // r1
  int *v19; // r0
  uint32_t *v20; // r1
  int v21; // r6
  int v22; // r8
  uint64_t v23; // kr08_8
  int v24; // cf
  int v25; // r4
  uint64_t v26; // r0
  int v27; // r3
  uint64_t v28; // r0
  int v29; // r2
  volatile unsigned int v30; // r4
  int v31; // r4
  int v32; // r0
  unsigned int v33; // r3
  int v34; // r0
  volatile unsigned int v35; // r3
  int result; // r0
  uint64_t v37; // [sp+0h] [bp-1Ch]
  int v38; // [sp+Ch] [bp-10h]
  unsigned int v39; // [sp+10h] [bp-Ch]

  v7 = *(uint32_t *)(a3 + 32);
  v39 = *(uint32_t *)(a3 + 36);
  v8 = *(uint64_t *)(a1 + 24);
  v10 = *(uint16_t *)(a1 + 32) << 10;
  if ( a6 )
  {
    v11 = *(uint8_t *)(a6 + 2);
    if ( !*(uint8_t *)(a6 + 2) )
      v11 = *(uint8_t *)(a6 + 3);
    v38 = v10 * v11;
    if ( !(*(uint8_t *)(a3 + 40) << 28) )
      goto LABEL_5;
LABEL_24:
    v21 = 500;
    v22 = 0;
    goto LABEL_14;
  }
  v38 = *(uint16_t *)(a1 + 32) << 10;
  if ( *(uint8_t *)(a3 + 40) << 28 )
    goto LABEL_24;
LABEL_5:
  v12 = (char *)off_11889C;
  v13 = (int *)off_1188C0;
  v14 = (int *)off_1188A0;
  *(uint32_t *)off_11889C = *((uint8_t *)off_1188C0 + (*(uint8_t *)(a3 + 44) >> 4)) & 0x7F
                        | *(uint32_t *)off_11889C & 0xFFFFFF80;
  v15 = v12 + 8;
  *v14 = a2 | (*(uint8_t *)(a3 + 40) >> 7 << 20);
  *v15 = 0x80000000;
  __dsb(0xFu);
  while ( (*v15 & 0xC0000000) != 0x40000000 )
    ;
  v16 = (uint16_t **)off_1188A4;
  if ( **(uint16_t **)off_1188A4 >= 0 || (*v15 & 0x40000000) != 0 )
  {
    v17 = (uint16_t)*(uint32_t *)off_1188A8;
  }
  else
  {
    sub_121960((int)aNxmacTimeOnAir, (int)aHalMachwRxBcnD, 430);
    v17 = 500;
    v16 = (uint16_t **)off_1188A4;
  }
  if ( !(*(uint8_t *)(a3 + 40) << 28) )
  {
    v18 = (char *)off_11889C;
    v19 = (int *)off_1188A0;
    *(uint32_t *)off_11889C = *((uint8_t *)v13 + (*(uint8_t *)(a3 + 44) >> 4)) & 0x7F
                          | *(uint32_t *)off_11889C & 0xFFFFFF80;
    v20 = v18 + 8;
    *v19 = (*(uint8_t *)(a3 + 40) >> 7 << 20) | 0x18;
    *v20 = 0x80000000;
    __dsb(0xFu);
    while ( (*v20 & 0xC0000000) != 0x40000000 )
      ;
    if ( **v16 >= 0 || (*v20 & 0x40000000) != 0 )
    {
      v21 = (uint16_t)*(uint32_t *)off_1188A8;
      v22 = v17 - v21;
      goto LABEL_14;
    }
    sub_121960((int)aNxmacTimeOnAir, (int)aHalMachwRxBcnD, 430);
  }
  v22 = v17 - 500;
  v21 = 500;
LABEL_14:
  v23 = v8 - __PAIR64__(v39, v7);
  v24 = __CFADD__(v8 - v7, v22);
  v25 = v8 - v7 + v22;
  a4[10] = v25;
  a4[11] = HIDWORD(v23) + v24;
  v26 = sub_127F8C(v8, v10);
  v37 = v8 - (unsigned int)v21;
  v27 = v26 * (v10 >> 31) + v10 * HIDWORD(v26);
  v28 = (unsigned int)v26 * (uint64_t)(unsigned int)v10;
  HIDWORD(v28) += v27;
  if ( v28 < v37 )
    LODWORD(v37) = v28;
  v29 = v37 + v38;
  if ( (*(uint32_t *)off_1188B0 & 0x2000000) != 0 )
    v29 -= v25;
  v30 = (*(volatile uint32_t *)0x40501010u);
  v31 = v30 - *(uint32_t *)off_1188B4 + v29 - 400;
  v32 = sub_101A20();
  v33 = v31 - (*(volatile uint32_t *)0x40501010u) - 4300;
  if ( (int)(v33 - v32) < 0 )
    v31 += v10;
  v34 = sub_101A20();
  v35 = (*(volatile uint32_t *)0x40501010u);
  result = v31 - v35 - 4300 - v34;
  if ( result >= 0 && a4[9] != v31 )
  {
    sub_11AB18(a4 + 6, v31);
    return sub_11C01C((int)a4);
  }
  return result;
}
