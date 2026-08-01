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

extern uint32_t off_12222C;
extern uint32_t dword_122230;
extern uint32_t dword_122228;
extern uint32_t dword_122240;
extern uint32_t dword_12223C;
extern uint32_t dword_122234;
extern uint32_t dword_122238;

// parse_decimal_value @ 0x122198, size 144 bytes
// Doc: rf_cmd_dispatch_n2ca [rf]: Dispatch RF command to handler
// rf_cmd_dispatch_n2ca [rf]: Dispatch RF command to handler
int  parse_decimal_value(int a1, int a2)
{
  int v4; // r0
  uint16_t v6; // r0
  int f4c0; // r0
  int v8; // r4

  v4 = parse_number(*(uint8_t **)(a2 + 4), 0, 0xAu);
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      if ( a1 <= 2 )
        goto LABEL_5;
      v6 = parse_number(*(uint8_t **)(a2 + 8), 0, 0x10u);
      **(uint16_t **)off_12222C = v6;
      dispatch_event_handler(dword_122230, v6);
      return 0;
    }
    else if ( v4 == 2 )
    {
      if ( a1 <= 2 )
      {
LABEL_5:
        dispatch_event_handler(dword_122228);
        return 0;
      }
      v8 = parse_number(*(uint8_t **)(a2 + 8), 0, 0x10u);
      dispatch_event_handler(dword_122240, v8);
      set_global_ptr(v8);
      return 0;
    }
    else
    {
      dispatch_event_handler(dword_12223C, v4);
      return 0;
    }
  }
  else
  {
    dispatch_event_handler(dword_122234, **(uint16_t **)off_12222C);
    f4c0 = get_event_flags();
    dispatch_event_handler(dword_122238, f4c0);
    return 0;
  }
}

