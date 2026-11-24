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


extern double dbl_10C448;
extern double dbl_10C458;
extern uint32_t dword_10C450;
extern uint32_t dword_10C460;
extern uint32_t dword_10C488;
extern uint32_t dword_10C48C;
extern uint32_t dword_10C494;
extern uint32_t dword_10C498;
extern uint32_t off_10C468;
extern uint32_t off_10C46C;
extern uint32_t off_10C474;
extern uint32_t off_10C478;
extern uint32_t off_10C47C;
extern uint32_t off_10C480;
extern uint32_t off_10C484;
extern uint32_t off_10C490;
extern uint32_t off_10C49C;
extern uint32_t off_10C4A0;
extern uint32_t off_10C4A4;
extern uint32_t off_10C4A8;

// sub_10C220 @ 0x10c220, size 546 bytes
unsigned int * sub_10C220(unsigned int *result, int a2, int a3, int a4)
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
  sub_12EB90(0x2000, "cal_cfg:%x, alpha=%x\r\n", *result, v8);
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
  while ( !*(uint32_t *)off_10C474 )
    ;
  if ( v7 )
  {
    v11 = (*(uint32_t *)off_10C478 >> 5) & 0x1F;
    if ( (*(uint32_t *)off_10C478 & 0x400) != 0 )
      v11 *= 2;
    if ( (*(uint32_t *)off_10C47C & 0x80000) != 0 && (*(uint32_t *)off_10C47C & 0x40000) != 0 )
      v11 >>= 1;
    v12 = *(uint8_t *)off_10C484 * v11;
    *(uint32_t *)off_10C480 &= ~1u;
    if ( (uint8_t)v4 >> 7 )
    {
      v13 = *(uint64_t *)&dword_10C460;
      v14 = dbl_10C458;
    }
    else
    {
      v13 = *(uint64_t *)&dword_10C450;
      v14 = dbl_10C448;
    }
    v15 = sub_142894(v12);
    HIDWORD(v16) = dword_10C488;
    LODWORD(v16) = 0;
    v17 = sub_142968(v15, v16);
    v18 = sub_142BBC(v13, v17);
    HIDWORD(v19) = dword_10C48C;
    LODWORD(v19) = 0;
    v20 = sub_142968(v18, v19);
    v21 = sub_1424DC(v20);
    HIDWORD(v22) = dword_10C488;
    v23 = v21;
    LODWORD(v22) = 0;
    v24 = sub_142BBC(*(uint64_t *)&v14, v22);
    v25 = sub_1424DC(v24);
    v26 = v23;
    v27 = v25;
    *(uint32_t *)off_10C4A8 = sub_142EEC(v26) & 0x7FFFFFFF;
    *(uint32_t *)off_10C490 = dword_10C494 & (sub_142EEC(v27) << 13) | *(uint32_t *)off_10C490 & dword_10C498;
  }
  sub_103A54();
  sub_10A868((uint8_t)v4, a2, v8, (uint16_t)v4 >> 12, BYTE1(v4) & 0xF, 0);
  result = (unsigned int *)sub_103AFC();
  *(uint32_t *)off_10C474 = 1;
  if ( a4 )
  {
LABEL_3:
    if ( ((*(uint32_t *)off_10C468 & 0x8000000) == 0 || (*(uint32_t *)off_10C46C & 0x400) != 0) && !v7 )
    {
      a5 = off_10C4A0;
      v29 = ((uint32_t *)(uintptr_t)off_10C49C)[1];
      v30 = ((uint32_t *)(uintptr_t)off_10C49C)[2];
      v31 = &((uint32_t *)(uintptr_t)off_10C49C)[18];
      v44[0] = ((uint32_t *)(uintptr_t)off_10C49C)[0];
      v44[1] = v29;
      v44[2] = v30;
      sub_103A54();
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
      v43 = off_10C4A4;
      *(uint8_t *)(a5 + 0xC) = 0;
      *(uint8_t *)(a5 + 0x14) = 0;
      *(uint8_t *)(a5 + 0x1C) = 0;
      *(uint8_t *)(a5 + 0x24) = 0;
      *(uint8_t *)(a5 + 0x2C) = 0;
      *(uint8_t *)(a5 + 0x34) = 0;
      sub_10AED0(v43, (uint8_t *)(a2 + 125), a5);
      sub_10B2F0((int)v44, off_10C4A4, a2 + 104, a2 + 125, (uint16_t *)a5, 6, 1);
      *(uint8_t *)(a5 + 4) = 0;
      *(uint8_t *)(a5 + 0xC) = 0;
      *(uint8_t *)(a5 + 0x14) = 0;
      *(uint8_t *)(a5 + 0x1C) = 0;
      *(uint8_t *)(a5 + 0x24) = 0;
      *(uint8_t *)(a5 + 0x2C) = 0;
      *(uint8_t *)(a5 + 0x34) = 0;
      return (unsigned int *)sub_103AFC();
    }
  }
  return result;
}
