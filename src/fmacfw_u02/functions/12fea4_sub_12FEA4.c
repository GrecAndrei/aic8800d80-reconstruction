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

extern uint32_t dword_12FF0C;
extern uint32_t dword_12FF18;
extern uint32_t dword_12FF1C;
extern uint32_t dword_12FF10;
extern uint32_t dword_12FF14;

// sub_12FEA4 @ 0x12fea4, size 104 bytes
int  sub_12FEA4(int a1, int a2)
{
  int v4; // r0
  int v5; // r0
  unsigned int v7; // r4

  if ( a1 <= 1 || (v4 = sub_12F958(*(uint8_t **)(a2 + 4), 0, 0)) == 0 )
  {
    v5 = sub_12EA50();
    msg_parse(dword_12FF0C, v5);
    return 0;
  }
  if ( v4 == 1 )
  {
    if ( a1 == 2 )
    {
      msg_parse(dword_12FF18);
    }
    else
    {
      v7 = sub_12F958(*(uint8_t **)(a2 + 8), 0, 0);
      if ( v7 > 5 )
      {
        msg_parse(dword_12FF1C, v7);
      }
      else
      {
        msg_parse(dword_12FF10, v7);
        sub_12EA38(v7);
      }
    }
    return 0;
  }
  msg_parse(dword_12FF14);
  return 0;
}

