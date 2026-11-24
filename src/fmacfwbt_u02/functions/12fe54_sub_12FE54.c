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


extern uint32_t off_12FEE8;

// buf_clear10 @ 0x12fe54, size 144 bytes
int  buf_clear10(int a1, int a2)
{
  int v4; // r0
  uint16_t v6; // r0
  int v7; // r0
  int v8; // r4

  v4 = parse_integer(*(uint8_t **)(a2 + 4), nullptr, 0xAu);
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      if ( a1 <= 2 )
        goto LABEL_5;
      v6 = parse_integer(*(uint8_t **)(a2 + 8), nullptr, 0x10u);
      **(uint16_t **)off_12FEE8 = v6;
      ke_event_schedule_1("cfg dbg_msk: 0x%x\n", v6);
      return 0;
    }
    else if ( v4 == 2 )
    {
      if ( a1 <= 2 )
      {
LABEL_5:
        ke_event_schedule_1(aInvalidArgs);
        return 0;
      }
      v8 = parse_integer(*(uint8_t **)(a2 + 8), nullptr, 0x10u);
      ke_event_schedule_1("cfg dbg mod: %08X\n", v8);
      state_set_flags(v8);
      return 0;
    }
    else
    {
      ke_event_schedule_1("invalid func: %d\n", v4);
      return 0;
    }
  }
  else
  {
    ke_event_schedule_1("cur dbg_msk: 0x%x\n", **(uint16_t **)off_12FEE8);
    v7 = state_get_flags();
    ke_event_schedule_1("dbg mod: %08X\n", v7);
    return 0;
  }
}
