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

// process_items @ 0x12248c, size 104 bytes
int  process_items(int a1, int a2)
{
  int v4; // r0
  int v5; // r0
  unsigned int v7; // r4

  if ( a1 <= 1 || (v4 = parse_number(*(uint8_t **)(a2 + 4), nullptr, 0)) == 0 )
  {
    v5 = get_event_handler();
    dispatch_event_handler_1("dbg sev: %d\n", v5);
    return 0;
  }
  if ( v4 == 1 )
  {
    if ( a1 == 2 )
    {
      dispatch_event_handler_1(aInvalidArgs);
    }
    else
    {
      v7 = parse_number(*(uint8_t **)(a2 + 8), nullptr, 0);
      if ( v7 > 5 )
      {
        dispatch_event_handler_1("invalid sev_idx:%d\n", v7);
      }
      else
      {
        dispatch_event_handler_1("Cfg dbg sev: %d\n", v7);
        set_global_variable(v7);
      }
    }
    return 0;
  }
  dispatch_event_handler_1(aInvalidFunc);
  return 0;
}
