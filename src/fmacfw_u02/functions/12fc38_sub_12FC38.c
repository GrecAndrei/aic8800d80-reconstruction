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

extern uint32_t off_12FCCC;
extern uint32_t dword_12FCD0;
extern uint32_t dword_12FCC8;
extern uint32_t dword_12FCE0;
extern uint32_t dword_12FCDC;
extern uint32_t dword_12FCD4;
extern uint32_t dword_12FCD8;

// parse_hex10 @ 0x12fc38, size 144 bytes
// Doc: sub_122FC38 [util]: Calls helper with args from struct, sets up state
// sub_122FC38 [util]: Calls helper with args from struct, sets up state
int  parse_hex10(int a1, int a2)
{
  int v4; // r0
  uint16_t v6; // r0
  int v7; // r0
  int v8; // r4

  v4 = parse_hex_or_dec(*(uint8_t **)(a2 + 4), 0, 0xAu);
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      if ( a1 <= 2 )
        goto LABEL_5;
      v6 = parse_hex_or_dec(*(uint8_t **)(a2 + 8), 0, 0x10u);
      **(uint16_t **)off_12FCCC = v6;
      event_dispatch(dword_12FCD0, v6);
      return 0;
    }
    else if ( v4 == 2 )
    {
      if ( a1 <= 2 )
      {
LABEL_5:
        event_dispatch(dword_12FCC8);
        return 0;
      }
      v8 = parse_hex_or_dec(*(uint8_t **)(a2 + 8), 0, 0x10u);
      event_dispatch(dword_12FCE0, v8);
      ipc_set_data0(v8);
      return 0;
    }
    else
    {
      event_dispatch(dword_12FCDC, v4);
      return 0;
    }
  }
  else
  {
    event_dispatch(dword_12FCD4, **(uint16_t **)off_12FCCC);
    v7 = ipc_get_data0();
    event_dispatch(dword_12FCD8, v7);
    return 0;
  }
}

