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

extern uint32_t dword_119250;
extern uint32_t off_11923C;
extern uint32_t dword_11924C;
extern uint32_t dword_119248;
extern uint32_t dword_119258;
extern uint32_t off_119240;
extern uint32_t dword_119244;
extern uint32_t dword_119254;

// sub_119124 @ 0x119124, size 278 bytes
int  sub_119124(int a1, int a2, int a3)
{
  int v3; // r3
  int v4; // r3
  int v7; // r3
  BOOL v8; // r0
  int v9; // r8
  int v10; // r0
  int v11; // r2
  int v12; // r6
  int v13; // r5
  uint16_t *v14; // r2
  int16_t v15; // r3
  int16_t v16; // r1
  int v17; // r0

  v3 = *(uint8_t *)(a1 + 106);
  if ( v3 != 2 )
  {
    sub_12E948(dword_119250, v3, a3);
    return 1;
  }
  v4 = *(uint32_t *)(a1 + 72);
  if ( v4 )
  {
    v7 = *(uint8_t *)(v4 + 4);
    if ( **(int16_t **)off_11923C >= 0 || v7 != 2 )
    {
      v8 = (v7 | *(uint8_t *)(a1 + 1224)) != 0;
      goto LABEL_5;
    }
  }
  else if ( **(int16_t **)off_11923C >= 0 )
  {
    goto LABEL_9;
  }
  sub_12F32C(dword_11924C, dword_119248, 520);
LABEL_9:
  v8 = 1;
LABEL_5:
  v9 = dword_119258;
  v10 = sub_118B04(v8, *(uint16_t *)(dword_119258 + 2 * *(uint8_t *)(a1 + 107)));
  v12 = v10;
  if ( v10 )
  {
    sub_12C3A8(a1, v10);
    v13 = *(uint32_t *)(v12 + 72);
    *(uint8_t *)(v13 + 108) = 80;
    *(uint8_t *)(v13 + 109) = 0;
    *(uint8_t *)(v13 + 110) = 0;
    *(uint8_t *)(v13 + 111) = 0;
    sub_143630(v13 + 112, a2, 6);
    v14 = off_119240;
    v15 = *((uint16_t *)off_119240 + 254);
    v16 = *(uint16_t *)(a1 + 104);
    *(uint32_t *)(v13 + 118) = *(uint32_t *)(a1 + 100);
    ++v15;
    v17 = *(uint32_t *)(a1 + 100);
    *(uint16_t *)(v13 + 122) = v16;
    *(uint32_t *)(v13 + 124) = v17;
    *(uint16_t *)(v13 + 128) = v16;
    v14[254] = v15;
    *(uint16_t *)(v13 + 130) = 16 * v15;
    sub_143630(
      v13 + 132,
      dword_119244 + (*(uint8_t *)(a1 + 107) << 9),
      *(uint16_t *)(v9 + 2 * *(uint8_t *)(a1 + 107)) - 24);
    *(uint32_t *)(v12 + 88) = 0;
    *(uint32_t *)(v12 + 92) = 0;
    *(uint8_t *)(v12 + 28) = *(uint8_t *)(a1 + 107);
    *(uint8_t *)(v12 + 29) = -1;
    sub_118B34(v12, 5);
    return 0;
  }
  else
  {
    sub_12E948(dword_119254, *(uint16_t *)(v9 + 2 * *(uint8_t *)(a1 + 107)), v11);
    return 1;
  }
}

