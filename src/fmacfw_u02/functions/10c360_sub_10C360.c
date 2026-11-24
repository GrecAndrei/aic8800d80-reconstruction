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


extern double dbl_10C588;
extern double dbl_10C598;
extern uint32_t dword_10C590;
extern uint32_t dword_10C5A0;
extern uint32_t dword_10C5C8;
extern uint32_t dword_10C5CC;
extern uint32_t dword_10C5D4;
extern uint32_t dword_10C5D8;
extern uint32_t off_10C5A8;
extern uint32_t off_10C5AC;
extern uint32_t off_10C5B4;
extern uint32_t off_10C5B8;
extern uint32_t off_10C5BC;
extern uint32_t off_10C5C0;
extern uint32_t off_10C5C4;
extern uint32_t off_10C5D0;
extern uint32_t off_10C5DC;
extern uint32_t off_10C5E0;
extern uint32_t off_10C5E4;
extern uint32_t off_10C5E8;

// sub_10C360 @ 0x10c360, size 546 bytes
unsigned int * sub_10C360(unsigned int *result, int a2, int a3, int a4)
{
  unsigned int v4; // r6
  int v7; // r7
  int v8; // r10
  int v9; // r3
  int v10; // r3
  unsigned int v11; // r0
  int v12; // r0
  uint64_t v13; // r8
  double v14; // d8
  uint64_t v15; // r0
  uint64_t v16; // r2
  uint64_t v17; // r0
  uint64_t v18; // r0
  uint64_t v19; // r2
  uint64_t v20; // r0
  uint64_t v21; // r0
  uint64_t v22; // r2
  uint64_t v23; // r8
  uint64_t v24; // r0
  uint64_t v25; // r2
  uint64_t v26; // r0
  uint64_t v27; // r8
  int a5; // r6
  int v29; // r1
  int v30; // r2
  int *v31; // r5
  int v32; // r0
  int v33; // r1
  int v34; // r2
  int v35; // r3
  int v36; // r0
  int v37; // r1
  int v38; // r2
  int v39; // r3
  int v40; // r1
  int v41; // r2
  int v42; // r3
  int v43; // r0
  uint32_t v44[16]; // [sp+24h] [bp-40h] BYREF

  v4 = *result;
  v7 = (uint8_t)*result >> 6;
  if ( !a3 )
  {
    if ( !a4 )
      return result;
    goto LABEL_3;
  }
  v8 = result[1];
  sub_12ECD0(0x2000, "cal_cfg:%x, alpha=%x\r\n", *result, v8);
  v9 = a2 - 2;
  do
  {
    *(uint16_t *)(v9 + 2) = -32640;
    v9 += 2;
  }
  while ( a2 + 30 != v9 );
  *(uint32_t *)(a2 + 32) = 0;
  *(uint32_t *)(a2 + 36) = 0;
  v10 = a2 + 36;
  do
  {
    *(uint32_t *)(v10 + 4) = 0;
    v10 += 4;
  }
  while ( a2 + 100 != v10 );
  while ( !*(uint32_t *)off_10C5B4 )
    ;
  if ( v7 )
  {
    v11 = (*(uint32_t *)off_10C5B8 >> 5) & 0x1F;
    if ( (*(uint32_t *)off_10C5B8 & 0x400) != 0 )
      v11 *= 2;
    if ( (*(uint32_t *)off_10C5BC & 0x80000) != 0 && (*(uint32_t *)off_10C5BC & 0x40000) != 0 )
      v11 >>= 1;
    v12 = *(uint8_t *)off_10C5C4 * v11;
    *(uint32_t *)off_10C5C0 &= ~1u;
    if ( (uint8_t)v4 >> 7 )
    {
      v13 = *(uint64_t *)&dword_10C5A0;
      v14 = dbl_10C598;
    }
    else
    {
      v13 = *(uint64_t *)&dword_10C590;
      v14 = dbl_10C588;
    }
    v15 = sub_1429D4(v12);
    HIDWORD(v16) = dword_10C5C8;
    LODWORD(v16) = 0;
    v17 = sub_142AA8(v15, v16);
    v18 = sub_142CFC(v13, v17);
    HIDWORD(v19) = dword_10C5CC;
    LODWORD(v19) = 0;
    v20 = sub_142AA8(v18, v19);
    v21 = sub_14261C(v20);
    HIDWORD(v22) = dword_10C5C8;
    v23 = v21;
    LODWORD(v22) = 0;
    v24 = sub_142CFC(*(uint64_t *)&v14, v22);
    v25 = sub_14261C(v24);
    v26 = v23;
    v27 = v25;
    *(uint32_t *)off_10C5E8 = sub_14302C(v26) & 0x7FFFFFFF;
    *(uint32_t *)off_10C5D0 = dword_10C5D4 & (sub_14302C(v27) << 13) | *(uint32_t *)off_10C5D0 & dword_10C5D8;
  }
  sub_103B6C();
  sub_10A9A8((uint8_t)v4, a2, v8, (uint16_t)v4 >> 12, BYTE1(v4) & 0xF, 0);
  result = (unsigned int *)sub_103C14();
  *(uint32_t *)off_10C5B4 = 1;
  if ( a4 )
  {
LABEL_3:
    if ( ((*(uint32_t *)off_10C5A8 & 0x8000000) == 0 || (*(uint32_t *)off_10C5AC & 0x400) != 0) && !v7 )
    {
      a5 = off_10C5E0;
      v29 = ((uint32_t *)(uintptr_t)off_10C5DC)[1];
      v30 = ((uint32_t *)(uintptr_t)off_10C5DC)[2];
      v31 = &((uint32_t *)(uintptr_t)off_10C5DC)[18];
      v44[0] = ((uint32_t *)(uintptr_t)off_10C5DC)[0];
      v44[1] = v29;
      v44[2] = v30;
      sub_103B6C();
      v32 = *v31;
      v33 = v31[1];
      v34 = v31[2];
      v35 = v31[3];
      v31 += 4;
      v44[3] = v32;
      v44[4] = v33;
      v44[5] = v34;
      v44[6] = v35;
      v36 = *v31;
      v37 = v31[1];
      v38 = v31[2];
      v39 = v31[3];
      v31 += 4;
      v44[7] = v36;
      v44[8] = v37;
      v44[9] = v38;
      v44[10] = v39;
      v40 = v31[1];
      v41 = v31[2];
      v42 = v31[3];
      v44[11] = *v31;
      v44[12] = v40;
      v44[13] = v41;
      v44[14] = v42;
      *(uint8_t *)(a5 + 4) = 0;
      v43 = off_10C5E4;
      *(uint8_t *)(a5 + 0xC) = 0;
      *(uint8_t *)(a5 + 0x14) = 0;
      *(uint8_t *)(a5 + 0x1C) = 0;
      *(uint8_t *)(a5 + 0x24) = 0;
      *(uint8_t *)(a5 + 0x2C) = 0;
      *(uint8_t *)(a5 + 0x34) = 0;
      sub_10B010(v43, (uint8_t *)(a2 + 125), a5);
      sub_10B430((int)v44, off_10C5E4, a2 + 104, a2 + 125, (uint16_t *)a5, 6, 1);
      *(uint8_t *)(a5 + 4) = 0;
      *(uint8_t *)(a5 + 0xC) = 0;
      *(uint8_t *)(a5 + 0x14) = 0;
      *(uint8_t *)(a5 + 0x1C) = 0;
      *(uint8_t *)(a5 + 0x24) = 0;
      *(uint8_t *)(a5 + 0x2C) = 0;
      *(uint8_t *)(a5 + 0x34) = 0;
      return (unsigned int *)sub_103C14();
    }
  }
  return result;
}
