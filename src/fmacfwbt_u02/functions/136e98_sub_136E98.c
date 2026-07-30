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

extern uint32_t off_136F90;
extern uint32_t off_136F94;
extern uint32_t dword_136F9C;
extern uint32_t dword_136F98;

// sub_136E98 @ 0x136e98, size 246 bytes
int  sub_136E98(int a1, int a2)
{
  int v2; // r3
  int v5; // r3
  int result; // r0
  int v7; // r5
  int v8; // r6
  uint16_t *v9; // r2
  int16_t v10; // r3
  int16_t v11; // r1
  int v12; // r0
  int v13; // r0
  int v14; // r1
  uint64_t v15; // r2

  v2 = *(uint32_t *)(a1 + 72);
  if ( v2 )
  {
    v5 = *(uint8_t *)(v2 + 4);
    if ( **(int16_t **)off_136F90 >= 0 || v5 != 2 )
    {
      result = sub_119084((v5 | *(uint8_t *)(a1 + 1224)) != 0, 512);
      v7 = result;
      if ( !result )
        return result;
LABEL_4:
      message_dispatch_n_4a3(a1, result);
      v8 = *(uint32_t *)(v7 + 72);
      *(uint8_t *)(v8 + 108) = -64;
      *(uint8_t *)(v8 + 109) = 0;
      *(uint8_t *)(v8 + 110) = 0;
      *(uint8_t *)(v8 + 111) = 0;
      sub_14380C(v8 + 112, a2, 6);
      v9 = off_136F94;
      v10 = *((uint16_t *)off_136F94 + 254);
      v11 = *(uint16_t *)(a1 + 104);
      *(uint32_t *)(v8 + 118) = *(uint32_t *)(a1 + 100);
      ++v10;
      v12 = *(uint32_t *)(a1 + 100);
      *(uint16_t *)(v8 + 122) = v11;
      *(uint32_t *)(v8 + 124) = v12;
      *(uint16_t *)(v8 + 128) = v11;
      v9[254] = v10;
      *(uint16_t *)(v8 + 130) = 16 * v10;
      *(uint32_t *)(v7 + 88) = 0;
      *(uint32_t *)(v7 + 92) = a1;
      *(uint8_t *)(v7 + 28) = *(uint8_t *)(a1 + 107);
      *(uint8_t *)(v7 + 29) = -1;
      v13 = sub_130A54((uint16_t *)(v8 + 132), 7);
      v14 = *(uint32_t *)(v7 + 76);
      LODWORD(v15) = *(uint32_t *)(v14 + 28) + 23 + v13;
      HIDWORD(v15) = v13 + 28;
      *(uint64_t *)(v14 + 32) = v15;
      return sub_1190B4(v7, 5);
    }
    goto LABEL_6;
  }
  if ( **(int16_t **)off_136F90 < 0 )
LABEL_6:
    sub_12F694(dword_136F9C, dword_136F98, 520);
  result = sub_119084(1, 512);
  v7 = result;
  if ( result )
    goto LABEL_4;
  return result;
}

