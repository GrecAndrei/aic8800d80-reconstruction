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

extern uint32_t dword_12A5BC;

// sub_12A4B4 @ 0x12a4b4, size 264 bytes
int  sub_12A4B4(int a1, int a2, char a3, char a4, unsigned int a5, int a6, int a7)
{
  int v7; // r6
  int v8; // r7
  uint8_t *v9; // r4
  int v10; // r9
  uint8_t *v11; // r5
  int v13; // r0
  int v14; // r10
  int v15; // lr
  int v16; // zf
  int v17; // r1
  char v18; // r11
  char v19; // r11
  char v20; // r4
  int v21; // r7

  v7 = dword_12A5BC;
  v8 = *(uint8_t *)(a1 + 1225);
  v9 = (uint8_t *)(dword_12A5BC + 140 * v8);
  if ( v9[112] != 1 )
    return 255;
  v10 = v9[16];
  v11 = (uint8_t *)(dword_12A5BC + 140 * v8);
  if ( v9[16] )
  {
    if ( v9[64] )
      return 255;
    v10 = 1;
    v13 = 140 * v8 + 48 + dword_12A5BC;
    v14 = 1;
  }
  else
  {
    v13 = dword_12A5BC + 140 * v8;
    v14 = v9[16];
  }
  v15 = dword_12A5BC + 140 * v8;
  v16 = a2 == 0;
  v17 = dword_12A5BC + 140 * v8 + 48 * v14;
  v18 = *(uint8_t *)(v15 + 121);
  *(uint8_t *)(v17 + 19) = a4;
  *(uint8_t *)(v17 + 20) = a4;
  *(uint32_t *)(v17 + 28) = a5;
  v19 = v18 + 1;
  *(uint32_t *)(v17 + 24) = a6;
  v20 = v16;
  *(uint32_t *)(v17 + 36) = a7;
  *(uint8_t *)(v17 + 33) = a3;
  *(uint8_t *)(v17 + 32) = v20;
  *(uint8_t *)(v15 + 121) = v19;
  if ( !v16 )
    ++*(uint8_t *)(v15 + 122);
  if ( a5 )
    *(uint32_t *)(140 * v8 + 48 * v14 + v7 + 40) = 0x80000000 / a5 - 1;
  sub_124BFC(v13, a7);
  v21 = 140 * v8;
  *(uint8_t *)(v7 + v21 + 48 * v14 + 16) = 1;
  sub_125B98(*(uint8_t *)(v21 + v7 + 113), 3);
  sub_129404((int)v11, v10);
  sub_129458((int)v11);
  sub_1296C4(v11);
  return v10;
}

