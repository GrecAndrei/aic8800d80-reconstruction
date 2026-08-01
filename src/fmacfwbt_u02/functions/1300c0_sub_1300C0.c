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

// buf_array_clear_multiple @ 0x1300c0, size 104 bytes
int  buf_array_clear_multiple(int a1, int a2)
{
  int v4; // r0
  int v5; // r0
  unsigned int v7; // r4

  if ( a1 <= 1 || (v4 = parse_integer(*(uint8_t **)(a2 + 4), 0, 0)) == 0 )
  {
    v5 = state_get_value();
    ke_event_schedule(dword_130128, v5);
    return 0;
  }
  if ( v4 == 1 )
  {
    if ( a1 == 2 )
    {
      ke_event_schedule(dword_130134);
    }
    else
    {
      v7 = parse_integer(*(uint8_t **)(a2 + 8), 0, 0);
      if ( v7 > 5 )
      {
        ke_event_schedule(dword_130138, v7);
      }
      else
      {
        ke_event_schedule(dword_13012C, v7);
        state_set_value(v7);
      }
    }
    return 0;
  }
  ke_event_schedule(dword_130130);
  return 0;
}

