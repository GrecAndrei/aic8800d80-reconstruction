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

// sub_141E00 @ 0x141e00, size 160 bytes
int  sub_141E00(int a1, int a2, int a3, int a4)
{
  int v6; // r0
  int v7; // r1
  int v8; // r1
  int16_t v9; // r3
  int v10; // r5
  int16_t v11; // r3
  int v12; // r4
  int v13; // r1
  uint64_t v14; // r2
  int v16; // [sp+Ch] [bp-8h] BYREF

  v6 = sub_141A30((int)&v16, a1, a2, 6, *(uint8_t *)(a3 + 2));
  v7 = *(uint32_t *)(v16 + 72) + 108;
  *(uint8_t *)(v7 + v6) = -40;
  v8 = v7 + v6;
  *(uint8_t *)(v8 + 2) = (8 * *(uint8_t *)a3) & 0x30;
  v9 = (a4 != 4) | (uint16_t)(2 * a4) | *(uint16_t *)a3 & 0x10 | *(uint16_t *)a3 & 0x20;
  if ( *(uint8_t *)(a3 + 4) )
    v9 |= 0x40u;
  v10 = *(uint32_t *)(a3 + 24);
  v11 = v9 | (*(uint8_t *)(a3 + 5) << 10) | (*(uint8_t *)(a3 + 2) << 7);
  *(uint32_t *)(v8 + 9) = *(uint32_t *)(a3 + 28);
  *(uint32_t *)(v8 + 5) = v10;
  *(uint16_t *)(v8 + 3) = v11;
  *(uint8_t *)(v8 + 13) = *(uint8_t *)(a3 + 7);
  *(uint16_t *)(v8 + 14) = *(uint16_t *)(a3 + 8);
  *(uint8_t *)(v8 + 16) = *(uint8_t *)(a3 + 41);
  *(uint8_t *)(v8 + 1) = 15;
  v12 = v16;
  v13 = *(uint32_t *)(v16 + 76);
  HIDWORD(v14) = (uint16_t)(v6 + 17);
  LODWORD(v14) = *(uint32_t *)(v13 + 28) - 1 + HIDWORD(v14);
  HIDWORD(v14) += 4;
  *(uint64_t *)(v13 + 32) = v14;
  return sub_118B34(v12, 3);
}

