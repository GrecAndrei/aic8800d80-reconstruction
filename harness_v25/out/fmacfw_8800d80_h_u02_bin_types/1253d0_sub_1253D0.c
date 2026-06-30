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

extern uint32_t dword_12548C;
extern uint32_t dword_125490;
extern uint32_t off_125494;
extern uint32_t off_1254A4;
extern uint32_t dword_12549C;
extern uint32_t off_125498;
extern uint32_t dword_1254A0;

// sub_1253D0 @ 0x1253d0, size 186 bytes
int  sub_1253D0(int a1, int a2)
{
  uint32_t *v3; // r5
  int v4; // r1
  int v5; // r3
  int v6; // r8
  int v7; // r7
  int v8; // r11
  int v9; // r6
  int v10; // r10
  int v12; // r3
  int v13; // r1
  int v14; // r2
  int v15; // r0
  int v16; // r6
  int v17; // r11
  uint64_t v18; // r2
  int v19; // r7
  uint32_t *v20; // r1
  int result; // r0

  v3 = *(uint32_t **)(a1 + 192);
  v4 = *(uint16_t *)(a2 + 4);
  v5 = *(uint8_t *)(a2 + 8);
  v6 = v3[7];
  v7 = *(uint16_t *)(a2 + 6);
  v8 = *(uint8_t *)(a1 + 107);
  v9 = dword_12548C;
  v10 = v4 - v5;
  *(uint16_t *)(a1 + 216) = v4 - v5;
  sub_132E78();
  v12 = *(uint16_t *)(a2 + 6);
  v13 = dword_125490;
  v14 = v3[7] + v12 - 1;
  v3[8] = v14;
  v15 = *(uint32_t *)(a1 + 72);
  v16 = v9 + 8 * v8;
  v17 = v13 + 20 * v8;
  LODWORD(v18) = v14 + *(uint8_t *)(a2 + 8) + 1;
  HIDWORD(v18) = ~v12 + v10 + v18;
  *(uint64_t *)(v17 + 8) = v18;
  v19 = v7 + 3;
  *(uint32_t *)(v17 + 16) = 0;
  if ( v15 )
  {
    v20 = off_125494;
    if ( !*(uint8_t *)(a1 + 1224) && !*(uint8_t *)(v15 + 4) )
      v20 = off_1254A4;
  }
  else
  {
    v20 = off_125494;
  }
  result = dword_12549C;
  v20[9] = (uint16_t)(*(uint16_t *)off_125498 << 8) | (uint8_t)*(uint32_t *)off_125498;
  v3[11] = 0;
  v3[12] = v20;
  v3[17] = result;
  v3[6] = dword_1254A0 + 40 * *(uint8_t *)(a1 + 107);
  *(uint8_t *)(a1 + 226) = 1;
  *(uint8_t *)(v16 + 3) = *(uint8_t *)(v6 + v19);
  return result;
}

