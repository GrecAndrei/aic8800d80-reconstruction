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

extern uint32_t dword_118C6C;
extern uint32_t dword_118C70;

// sub_118C44 @ 0x118c44, size 38 bytes
// Doc: sub_1218C44 [util]: Resolves handler from table and dispatches call
// sub_1218C44 [util]: Resolves handler from table and dispatches call
int  sub_118C44(int a1, int a2)
{
  int v4; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r4

  v4 = rf_bus_mark_n100_d2d0(dword_118C6C);
  v7 = v4;
  if ( v4 )
  {
    sub_118BB8(v4, a1, a2);
    return v7;
  }
  else
  {
    msg_parse(dword_118C70, v5, v6);
    return 0;
  }
}

