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

extern uint32_t dword_12FE50;
extern uint32_t off_12FE58;
extern uint32_t off_12FE5C;
extern uint32_t off_12FE84;
extern uint32_t off_12FE88;
extern uint32_t off_12FE60;
extern uint32_t off_12FE54;
extern uint32_t dword_12FE64;
extern uint32_t off_12FE8C;
extern uint32_t off_12FE90;
extern uint32_t off_12FE6C;
extern uint32_t dword_12FE68;
extern uint32_t off_12FE94;
extern uint32_t off_12FE70;
extern uint32_t off_12FE74;
extern uint32_t off_12FE78;
extern uint32_t off_12FE98;
extern uint32_t dword_12FE9C;
extern uint32_t dword_12FEA0;
extern uint32_t off_12FE7C;
extern uint32_t dword_12FE80;

// sub_12FCE4 @ 0x12fce4, size 362 bytes
int  sub_12FCE4(int a1, int a2)
{
  uint8_t *v3; // r6
  unsigned int v4; // r6
  uint16_t v5; // r0
  uint8_t *v6; // r5
  uint16_t v7; // r7
  unsigned int v8; // r8
  uint32_t *v9; // r0
  uint32_t *v10; // r1
  uint32_t *v11; // r12
  uint32_t *v12; // lr
  uint32_t *v13; // r3
  uint32_t *v14; // r9
  uint32_t *v15; // lr
  uint32_t *v16; // r0
  uint32_t *v17; // r12
  unsigned int *v18; // r1
  unsigned int v19; // r3
  char *v20; // r0
  int *v21; // r12
  int v22; // lr
  int v23; // r9
  int v24; // r0
  uint8_t v26[4]; // [sp+8h] [bp-Ch] BYREF
  char v27; // [sp+Ch] [bp-8h]

  if ( sub_143E40(*(uint32_t *)(a2 + 4)) != 12 || sub_143E40(*(uint32_t *)(a2 + 8)) != 12 )
    return -2;
  v3 = *(uint8_t **)(a2 + 4);
  sub_143770(v26, v3 + 8, 4);
  v3[8] = 0;
  v27 = 0;
  v4 = sub_12F958(v3, 0, 0x10u);
  v5 = sub_12F958(v26, 0, 0x10u);
  v6 = *(uint8_t **)(a2 + 8);
  v7 = v5;
  sub_143770(v26, v6 + 8, 4);
  v6[8] = 0;
  v27 = 0;
  v8 = sub_12F958(v6, 0, 0x10u);
  LOWORD(v6) = sub_12F958(v26, 0, 0x10u);
  msg_parse(dword_12FE50);
  v9 = off_12FE58;
  v10 = off_12FE5C;
  v11 = off_12FE84;
  v12 = off_12FE88;
  v13 = off_12FE60;
  *(uint32_t *)off_12FE54 = 512;
  *v12 = 7;
  *v9 = 7;
  *v10 = 7;
  *v11 = 7;
  *v13 = 7;
  v9[4] = 7;
  v13 -= 495296;
  v10[4] = 7;
  v11[4] = 7;
  *v13 = 9816;
  *(v9 - 457703) = 50529027;
  *(v10 - 457698) = dword_12FE64;
  v14 = off_12FE8C;
  v15 = off_12FE90;
  v16 = off_12FE6C;
  v13[37597] = dword_12FE68;
  v17 = off_12FE94;
  v18 = (unsigned int *)off_12FE70;
  *v14 = -1;
  *v15 = -1;
  *v16 = -1;
  *v17 = -1;
  *v18 = bswap32(v4);
  v18 += 4;
  *(uint32_t *)off_12FE74 = __rev16(v7);
  v19 = bswap32(v8);
  *v18 = v19;
  v20 = (char *)off_12FE78;
  *(uint32_t *)off_12FE78 = __rev16((uint16_t)v6);
  *(v18 - 380) = v19;
  v21 = (int *)off_12FE98;
  v22 = dword_12FE9C;
  v23 = dword_12FEA0;
  *(uint32_t *)off_12FE7C = __rev16((uint16_t)v6);
  *(uint32_t *)&v20[-148] = 7;
  *(uint32_t *)&v20[-148] = v23;
  v24 = dword_12FE80;
  *v21 = v22;
  msg_parse(v24, v4, v7, v8, (uint16_t)v6);
  return 0;
}

