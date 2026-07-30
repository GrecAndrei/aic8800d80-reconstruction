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

extern uint32_t off_128A88;
extern uint32_t dword_128A9C;
extern uint32_t off_128A90;
extern uint32_t off_128A8C;
extern uint32_t off_128A94;
extern uint32_t dword_128A98;

// sub_1289EC @ 0x1289ec, size 154 bytes
int  sub_1289EC(int a1, int a2, int a3)
{
  int v4; // r0
  int v5; // r1
  int v6; // r5
  uint8_t *v7; // r3
  int v8; // r2
  int v9; // r0
  int v11; // r1

  if ( (a2 & 0x800000) != 0 )
  {
    if ( a1 )
      *(uint8_t *)(a1 + 115) = 0;
    return 1;
  }
  else
  {
    v4 = (uint8_t)(*(uint8_t *)(a1 + 115) + 1);
    v5 = *(uint32_t *)off_128A88;
    *(uint8_t *)(a1 + 115) = v4;
    if ( *(uint8_t *)(v5 + 1) == v4 )
    {
      v11 = dword_128A9C;
      *(uint8_t *)(a1 + 115) = 0;
      sub_12EB90(1024, v11);
      sub_121ED4(a1);
      return 1;
    }
    else
    {
      v6 = *(uint8_t *)(a1 + 108);
      if ( *(uint8_t *)(a1 + 108) )
      {
        sub_118C84(*(uint8_t *)(a1 + 116), a3, a1);
        return 0;
      }
      else
      {
        v7 = off_128A90;
        v8 = *((uint8_t *)off_128A8C + 2);
        *((uint8_t *)off_128A90 + 28) = 1;
        if ( v8 )
          *(uint32_t *)off_128A94 &= ~0x80000000;
        if ( v7[8] )
          --v7[8];
        v9 = dword_128A98;
        v7[29] = 0;
        sub_124CF4(v9);
        *(uint32_t *)(a1 + 4) &= ~0x200u;
        return v6;
      }
    }
  }
}

