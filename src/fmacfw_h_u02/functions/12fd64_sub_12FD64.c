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

extern uint32_t dword_12FDCC;
extern uint32_t dword_12FDD8;
extern uint32_t dword_12FDDC;
extern uint32_t dword_12FDD0;
extern uint32_t dword_12FDD4;

// parse_format_switch @ 0x12fd64, size 104 bytes
int  parse_format_switch(int a1, int a2)
{
  int v4; // r0
  int v5; // r0
  unsigned int v7; // r4

  if ( a1 <= 1 || (v4 = parse_uint_base(*(uint8_t **)(a2 + 4), 0, 0)) == 0 )
  {
    v5 = get_global_field4();
    alloc_tx_event(dword_12FDCC, v5);
    return 0;
  }
  if ( v4 == 1 )
  {
    if ( a1 == 2 )
    {
      alloc_tx_event(dword_12FDD8);
    }
    else
    {
      v7 = parse_uint_base(*(uint8_t **)(a2 + 8), 0, 0);
      if ( v7 > 5 )
      {
        alloc_tx_event(dword_12FDDC, v7);
      }
      else
      {
        alloc_tx_event(dword_12FDD0, v7);
        set_global_field4(v7);
      }
    }
    return 0;
  }
  alloc_tx_event(dword_12FDD4);
  return 0;
}

