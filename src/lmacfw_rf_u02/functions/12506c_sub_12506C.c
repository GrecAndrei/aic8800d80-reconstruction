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

extern uint32_t dword_12509C;
extern uint32_t dword_125098;

// set_rf_byte @ 0x12506c, size 42 bytes
int  set_rf_byte(int a1, int a2)
{
  uint8_t v2; // r0

  if ( a1 <= 1 )
  {
    dispatch_event_handler(dword_12509C);
    return 1;
  }
  else
  {
    v2 = parse_number(*(uint8_t **)(a2 + 4), 0, 0xAu);
    set_reg_158a08_bit16(v2);
    dispatch_event_handler(dword_125098);
    return 0;
  }
}

