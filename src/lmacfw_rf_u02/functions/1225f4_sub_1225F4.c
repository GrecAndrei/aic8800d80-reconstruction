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


extern uint32_t off_122664;

// parse_records @ 0x1225f4, size 110 bytes
int  parse_records(int a1, int a2)
{
  int v4; // r0
  int v5; // r7
  int v6; // r6
  int v7; // r4
  unsigned int v9; // r0

  if ( a1 == 1 )
  {
    rf_param_build();
    return 0;
  }
  else
  {
    v4 = parse_number(*(uint8_t **)(a2 + 4), nullptr, 0);
    v5 = v4;
    if ( v4 )
      v5 = 1;
    v6 = v4;
    if ( a1 > 2 )
    {
      v7 = off_122664;
      v9 = parse_number(*(uint8_t **)(a2 + 8), nullptr, 0);
      if ( v9 > 0x7D0 )
        *(uint32_t *)(v7 + 0x16C) = v9;
    }
    else
    {
      v7 = off_122664;
    }
    if ( *(uint8_t *)(v7 + 0x16B) != v5 )
    {
      *(uint8_t *)(v7 + 0x16B) = v5;
      if ( v6 )
      {
        rf_read_trim();
        rf_enable_2();
      }
      else
      {
        rf_disable_2();
      }
    }
    dispatch_event_handler_1("temp_comp en=%d, peroid_ms=%d\n", v5, *(uint32_t *)(v7 + 0x16C));
    return 0;
  }
}
