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

extern uint32_t dword_140A28;
extern uint32_t dword_140A2C;
extern uint32_t off_140A34;
extern uint32_t dword_140A30;

// sub_1409A4 @ 0x1409a4, size 130 bytes
int  sub_1409A4(int result, int a2)
{
  int v2; // r6
  unsigned int v3; // r4
  int v4; // r7
  int v5; // r3
  int v7; // r0
  int v8; // r4

  v2 = dword_140A28;
  v3 = *(uint8_t *)(dword_140A28 + 6489);
  if ( v3 <= 3 && *(uint8_t *)(dword_140A28 + 6488) <= 0x1Fu )
  {
    v4 = result;
    v5 = *(uint32_t *)(dword_140A2C + 1320 * v3 + 72);
    v7 = v5 ? *(uint8_t *)(v5 + 4) : *((uint8_t *)off_140A34 + 36);
    result = sub_118B04(v7 != 0, 512);
    v8 = result;
    if ( result )
    {
      *(uint8_t *)(result + 28) = *(uint8_t *)(v2 + 6489);
      *(uint8_t *)(result + 29) = *(uint8_t *)(v2 + 6488);
      *(uint8_t *)(result + 51) = 0;
      *(uint8_t *)(result + 53) = 0;
      if ( !a2 )
      {
        *(uint32_t *)(result + 88) = dword_140A30;
        *(uint32_t *)(result + 92) = result;
      }
      sub_140400(result, 1, a2, v4);
      return sub_118B34(v8, 3);
    }
  }
  return result;
}

