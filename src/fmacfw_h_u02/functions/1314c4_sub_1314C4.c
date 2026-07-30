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

extern uint32_t dword_13153C;
extern uint32_t dword_131540;
extern uint32_t off_131544;

// sub_1314C4 @ 0x1314c4, size 118 bytes
int  sub_1314C4(int a1, uint8_t *a2, int16_t a3, int16_t a4)
{
  int v4; // r0
  int v7; // r4
  int v8; // r1
  int v9; // r7
  uint8_t *v10; // r0

  v4 = *a2;
  if ( a2[1] )
  {
    v7 = dword_13153C + 696 * v4;
    v8 = *(uint8_t *)(v7 + 34);
    v9 = *(uint8_t *)(dword_131540 + 1320 * v8 + 106);
    *(uint8_t *)(v7 + 52) = 2;
    if ( !v9 && ((*((uint32_t *)off_131544 + 1) >> v8) & 1) != 0 )
    {
      v10 = (uint8_t *)sub_12C7EC(5145, 5, 6, 2u);
      *v10 = 0;
      v10[1] = *(uint8_t *)(v7 + 34);
      sub_12C84C((int)v10);
    }
  }
  else
  {
    *(uint8_t *)(dword_13153C + 696 * v4 + 52) = 1;
  }
  sub_12C8D0(5125, a4, a3);
  return 0;
}

