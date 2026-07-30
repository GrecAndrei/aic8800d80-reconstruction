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

extern uint32_t off_12623C;
extern uint32_t off_126240;
extern uint32_t off_126254;
extern uint32_t off_126244;
extern uint32_t off_126248;
extern uint32_t off_12624C;
extern uint32_t off_126250;

// sub_126174 @ 0x126174, size 200 bytes
int sub_126174()
{
  uint64_t *v0; // r5
  uint32_t *v1; // r7
  int v2; // r1
  uint64_t v3; // r0
  uint32_t *v4; // r12
  uint32_t *v5; // r2
  uint32_t *v6; // r1
  uint32_t *v7; // r5
  char v9; // [sp+6h] [bp-46h] BYREF
  char v10; // [sp+7h] [bp-45h] BYREF
  int v11; // [sp+8h] [bp-44h] BYREF
  uint16_t v12; // [sp+Ch] [bp-40h]
  int v13; // [sp+10h] [bp-3Ch] BYREF
  int16_t v14; // [sp+14h] [bp-38h]
  uint8_t v15[8]; // [sp+18h] [bp-34h] BYREF
  int v16; // [sp+20h] [bp-2Ch] BYREF
  int16_t v17; // [sp+24h] [bp-28h]
  uint8_t v18[18]; // [sp+28h] [bp-24h] BYREF
  uint8_t v19[18]; // [sp+3Ah] [bp-12h] BYREF

  v0 = off_12623C;
  v1 = off_126240;
  v2 = *((uint32_t *)off_12623C + 1);
  v13 = *(uint32_t *)off_12623C;
  v14 = v2;
  v9 = 0;
  v10 = 1;
  sub_1282E8(&v11, &v13, 6);
  sub_1282E8(v19, &v11, 6);
  v19[7] = 0;
  sub_123F04(0, 0, 0, 0);
  sub_117E5C((int)&v11, 0, 0, &v10);
  sub_11930C(0, (int)v18, 0, 0);
  v3 = v0[1];
  v17 = *((uint32_t *)v0 + 3);
  v16 = v3;
  sub_1282E8(v15, &v16, 6);
  sub_117E5C((int)v15, 0, 0, &v9);
  v4 = off_126254;
  *(uint32_t *)off_126244 = v11;
  v5 = off_126248;
  v6 = off_12624C;
  v7 = off_126250;
  *v4 = v12;
  *v5 = 0xFFFF;
  *v6 = -1;
  *v1 = 0xFFFF;
  *v7 = -1;
  sub_123FF0(2u, 0, 0);
  sub_12407C(0);
  sub_123F64(1);
  return sub_124178(0);
}

