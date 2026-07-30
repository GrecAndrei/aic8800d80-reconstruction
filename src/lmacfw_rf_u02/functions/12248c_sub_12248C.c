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

extern uint32_t dword_1224F4;
extern uint32_t dword_122500;
extern uint32_t dword_1224F8;
extern uint32_t dword_1224FC;

// sub_12248C @ 0x12248c, size 104 bytes
// Doc: rf_mem_write_n46a [rf]: Write value to RF register/memory via internal helper
// rf_mem_write_n46a [rf]: Write value to RF register/memory via internal helper
int  sub_12248C(int a1, int a2)
{
  int v4; // r0
  int n_c8; // r0
  unsigned int v7; // r4

  if ( a1 <= 1 || (v4 = parse_int(*(uint8_t **)(a2 + 4), 0, 0)) == 0 )
  {
    n_c8 = rf_mem_read_n_c8();
    msg_parse(dword_1224F4, n_c8);
    return 0;
  }
  if ( v4 == 1 )
  {
    if ( a1 == 2 )
    {
      msg_parse(dword_122500);
    }
    else
    {
      v7 = parse_int(*(uint8_t **)(a2 + 8), 0, 0);
      if ( v7 > 5 )
      {
        msg_parse(rf_mem_write_n4d8, v7);
      }
      else
      {
        msg_parse(dword_1224F8, v7);
        rf_bus_write_n144(v7);
      }
    }
    return 0;
  }
  msg_parse(dword_1224FC);
  return 0;
}

