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

// parse_hex10 @ 0x12fc38, size 144 bytes
int  parse_hex10(int a1, int a2)
{
  int v4; // r0
  uint16_t v6; // r0
  int v7; // r0
  int v8; // r4

  v4 = parse_hex_or_dec(*(uint8_t **)(a2 + 4), nullptr, 0xAu);
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      if ( a1 <= 2 )
        goto LABEL_5;
      v6 = parse_hex_or_dec(*(uint8_t **)(a2 + 8), nullptr, 0x10u);
      **(uint16_t **)off_12FCCC = v6;
      event_dispatch("cfg dbg_msk: 0x%x\n", v6);
      return 0;
    }
    else if ( v4 == 2 )
    {
      if ( a1 <= 2 )
      {
LABEL_5:
        event_dispatch(aInvalidArgs);
        return 0;
      }
      v8 = parse_hex_or_dec(*(uint8_t **)(a2 + 8), nullptr, 0x10u);
      event_dispatch("cfg dbg mod: %08X\n", v8);
      ipc_set_data0(v8);
      return 0;
    }
    else
    {
      event_dispatch("invalid func: %d\n", v4);
      return 0;
    }
  }
  else
  {
    event_dispatch("cur dbg_msk: 0x%x\n", **(uint16_t **)off_12FCCC);
    v7 = ipc_get_data0();
    event_dispatch("dbg mod: %08X\n", v7);
    return 0;
  }
}
