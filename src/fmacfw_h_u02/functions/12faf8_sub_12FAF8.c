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

extern uint32_t off_12FB8C;
extern uint32_t dword_12FB90;
extern uint32_t dword_12FB88;
extern uint32_t dword_12FBA0;
extern uint32_t dword_12FB9C;
extern uint32_t dword_12FB94;
extern uint32_t dword_12FB98;

// parse_decimal_string @ 0x12faf8, size 144 bytes
int  parse_decimal_string(int a1, int a2)
{
  int v4; // r0
  uint16_t v6; // r0
  int v7; // r0
  int v8; // r4

  v4 = parse_uint_base(*(uint8_t **)(a2 + 4), 0, 0xAu);
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      if ( a1 <= 2 )
        goto LABEL_5;
      v6 = parse_uint_base(*(uint8_t **)(a2 + 8), 0, 0x10u);
      **(uint16_t **)off_12FB8C = v6;
      alloc_tx_event(dword_12FB90, v6);
      return 0;
    }
    else if ( v4 == 2 )
    {
      if ( a1 <= 2 )
      {
LABEL_5:
        alloc_tx_event(dword_12FB88);
        return 0;
      }
      v8 = parse_uint_base(*(uint8_t **)(a2 + 8), 0, 0x10u);
      alloc_tx_event(dword_12FBA0, v8);
      set_global_field0(v8);
      return 0;
    }
    else
    {
      alloc_tx_event(dword_12FB9C, v4);
      return 0;
    }
  }
  else
  {
    alloc_tx_event(dword_12FB94, **(uint16_t **)off_12FB8C);
    v7 = get_global_field0();
    alloc_tx_event(dword_12FB98, v7);
    return 0;
  }
}

