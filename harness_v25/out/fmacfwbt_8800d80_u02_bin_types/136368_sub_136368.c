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

extern uint32_t dword_1363F8;
extern uint32_t dword_1363FC;
extern uint32_t dword_136400;
extern uint32_t off_136404;

// sub_136368 @ 0x136368, size 142 bytes
int  sub_136368(int a1, uint8_t *a2, int16_t a3, int16_t a4)
{
  int v7; // r2
  int v8; // r3
  int v9; // r1
  char v10; // r7
  char *v11; // r0
  int v13; // r0
  uint8_t v14[5]; // [sp+7h] [bp-5h] BYREF

  v7 = a2[9];
  v8 = *a2;
  v14[0] = 0;
  sub_12ECB0(dword_1363F8, dword_1363FC, v7, v8);
  v9 = dword_136400 + 1320 * a2[10];
  if ( *(uint8_t *)(v9 + 106) == 2 )
  {
    if ( *(uint8_t *)(v9 + 108) || sub_12D0B0(7u) )
    {
      v10 = 8;
    }
    else
    {
      v13 = sub_127F58(a2, v14);
      v10 = v13;
      if ( v13 )
      {
        v10 = 1;
      }
      else
      {
        sub_128AAC(a2[10], v14[0]);
        *((uint32_t *)off_136404 + 1) |= 0x10u;
      }
    }
  }
  else
  {
    v10 = 4;
  }
  v11 = (char *)sub_12CB54(7173, a4, a3, 2u);
  *v11 = v10;
  v11[1] = v14[0];
  sub_12CBB4((int)v11);
  return 0;
}

