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


extern uint32_t off_105F28;
extern uint32_t off_105F30;
extern uint32_t off_105F34;

// load_device_desc @ 0x105e94, size 146 bytes
int  load_device_desc(int a1, int a2)
{
  int v4; // r1
  int v5; // r2
  int v6; // r3
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int *v13; // r4
  int v14; // r0
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r0
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r1
  int v23; // r2
  int v24; // r3
  int v25; // r6
  int v26; // r2
  int *v27; // r3
  int v28; // r1
  unsigned int *v29; // r4
  int v30; // r3
  int tbl[27]; // [sp+0h] [bp-6Ch] BYREF

  v4 = ((uint32_t *)(uintptr_t)off_105F28)[1];
  v5 = ((uint32_t *)(uintptr_t)off_105F28)[2];
  v6 = ((uint32_t *)(uintptr_t)off_105F28)[3];
  tbl[0] = ((uint32_t *)(uintptr_t)off_105F28)[0];
  tbl[1] = v4;
  tbl[2] = v5;
  tbl[3] = v6;
  v7 = ((uint32_t *)(uintptr_t)off_105F28)[5];
  v8 = ((uint32_t *)(uintptr_t)off_105F28)[6];
  v9 = ((uint32_t *)(uintptr_t)off_105F28)[7];
  tbl[4] = ((uint32_t *)(uintptr_t)off_105F28)[4];
  tbl[5] = v7;
  tbl[6] = v8;
  tbl[7] = v9;
  v10 = ((uint32_t *)(uintptr_t)off_105F28)[9];
  v11 = ((uint32_t *)(uintptr_t)off_105F28)[10];
  v12 = ((uint32_t *)(uintptr_t)off_105F28)[11];
  tbl[8] = ((uint32_t *)(uintptr_t)off_105F28)[8];
  tbl[9] = v10;
  tbl[10] = v11;
  tbl[11] = v12;
  v13 = &((uint32_t *)(uintptr_t)off_105F28)[13];
  tbl[12] = ((uint32_t *)(uintptr_t)off_105F28)[12];
  v14 = *v13;
  v15 = v13[1];
  v16 = v13[2];
  v17 = v13[3];
  v13 += 4;
  tbl[13] = v14;
  tbl[14] = v15;
  tbl[15] = v16;
  tbl[16] = v17;
  v18 = *v13;
  v19 = v13[1];
  v20 = v13[2];
  v21 = v13[3];
  v13 += 4;
  tbl[17] = v18;
  tbl[18] = v19;
  tbl[19] = v20;
  tbl[20] = v21;
  v22 = v13[1];
  v23 = v13[2];
  v24 = v13[3];
  tbl[21] = *v13;
  tbl[22] = v22;
  tbl[23] = v23;
  tbl[24] = v24;
  v25 = *(uint32_t *)(a1 + 4 * a2 + 140);
  tbl[25] = v13[4];
  check_interrupt_flag(1, "shift_idx=%d ", v25);
  if ( v25 > 25 )
    v26 = 12;
  else
    v26 = (v25 / 2) & ~((v25 / 2) >> 31);
  v27 = &tbl[v26 + 26];
  v28 = *(v27 - 26);
  v29 = (unsigned int *)off_105F34;
  v30 = *(v27 - 13);
  *(uint32_t *)off_105F30 = (8 * v28) & 0x38 | *(uint32_t *)off_105F30 & 0xFFFFFFC7;
  *v29 = (4 * v30) & 0x1C | *v29 & 0xFFFFFFE3;
  return check_interrupt_flag(1, "index=%d\n", v26);
}
