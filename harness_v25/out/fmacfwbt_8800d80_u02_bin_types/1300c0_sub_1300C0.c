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

extern uint32_t dword_130128;
extern uint32_t dword_130134;
extern uint32_t dword_130138;
extern uint32_t dword_13012C;
extern uint32_t dword_130130;

// sub_1300C0 @ 0x1300c0, size 104 bytes
int  sub_1300C0(int a1, int a2)
{
  int v4; // r0
  int v5; // r0
  unsigned int v7; // r4

  if ( a1 <= 1 || (v4 = sub_12FB74(*(uint8_t **)(a2 + 4), 0, 0)) == 0 )
  {
    v5 = sub_12EC78();
    sub_12ECB0(dword_130128, v5);
    return 0;
  }
  if ( v4 == 1 )
  {
    if ( a1 == 2 )
    {
      sub_12ECB0(dword_130134);
    }
    else
    {
      v7 = sub_12FB74(*(uint8_t **)(a2 + 8), 0, 0);
      if ( v7 > 5 )
      {
        sub_12ECB0(dword_130138, v7);
      }
      else
      {
        sub_12ECB0(dword_13012C, v7);
        sub_12EC60(v7);
      }
    }
    return 0;
  }
  sub_12ECB0(dword_130130);
  return 0;
}

