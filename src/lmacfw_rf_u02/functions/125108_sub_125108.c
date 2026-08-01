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

extern uint32_t dword_125138;
extern uint32_t dword_125134;

// set_clock_offset @ 0x125108, size 42 bytes
int  set_clock_offset(int a1, int a2)
{
  uint8_t v2; // r0

  if ( a1 <= 1 )
  {
    dispatch_event_handler(dword_125138);
    return 1;
  }
  else
  {
    v2 = parse_number(*(uint8_t **)(a2 + 4), 0, 0xAu);
    set_reg_1807fc_bits24_27(v2);
    dispatch_event_handler(dword_125134);
    return 0;
  }
}

