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

extern uint32_t off_136818;
extern uint32_t dword_136814;
extern uint32_t dword_13681C;

// sub_136734 @ 0x136734, size 222 bytes
uint32_t * sub_136734(int a1)
{
  uint32_t *v1; // r8
  int v3; // r6
  uint8_t *v4; // r4
  char v5; // r3
  int v7; // r7
  int v8; // r0
  int v9; // r9
  int16_t v10; // r2
  int v11; // r3
  int v12; // r12
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r7
  char v17; // r3

  v1 = off_136818;
  v3 = *(uint32_t *)off_136818;
  v4 = (uint8_t *)sub_12C92C(7169, 13, 7, 4u);
  if ( a1 )
  {
    v5 = *(uint8_t *)(v3 + 51);
  }
  else
  {
    v7 = *(uint8_t *)(v3 + 51);
    v8 = sub_12C92C(30, 0, 7, 4u);
    v9 = dword_136814 + 1320 * v7;
    *(uint8_t *)(v8 + 2) = 1;
    *(uint8_t *)(v8 + 3) = *(uint8_t *)(v9 + 107);
    sub_12C98C(v8);
    v10 = *(uint16_t *)(v3 + 48);
    v11 = *(uint32_t *)(v9 + 72);
    *(uint32_t *)(v9 + 1208) = *(uint32_t *)(v3 + 44);
    *(uint16_t *)(v9 + 236) = v10;
    *(uint8_t *)(v9 + 234) = 0;
    v4[2] = *(uint8_t *)(v11 + 24);
    v12 = dword_13681C;
    v4[3] = *(uint8_t *)(v3 + 51) + 32;
    v13 = *(uint32_t *)(v3 + 4);
    v14 = *(uint32_t *)(v3 + 8);
    v15 = *(uint32_t *)(v3 + 12);
    v16 = v12 + 696 * (v7 + 32);
    *(uint32_t *)(v16 + 192) = *(uint32_t *)v3;
    *(uint32_t *)(v16 + 196) = v13;
    *(uint32_t *)(v16 + 200) = v14;
    *(uint8_t *)(v16 + 52) = 2;
    *(uint8_t *)(v16 + 204) = v15;
    sub_13289C(v16);
    v17 = *(uint8_t *)(v16 + 350);
    *(uint16_t *)(v16 + 38) = 1;
    *(uint8_t *)(v16 + 350) = v17 | 0x10;
    v5 = *(uint8_t *)(v3 + 51);
    *(uint8_t *)(v16 + 37) = 1;
    *(uint8_t *)(v16 + 35) = v5 + 32;
  }
  v4[1] = v5;
  *v4 = a1;
  sub_12C98C((int)v4);
  sub_12CA38(v3 - 12);
  *v1 = 0;
  return sub_12CD34(7u, 0);
}

