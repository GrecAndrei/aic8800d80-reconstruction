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

extern uint32_t dword_124F5C;

// set_private_addr @ 0x124f40, size 28 bytes
// Doc: sub_1224F42 [rf]: RF register read wrapper and event post
// sub_1224F42 [rf]: RF register read wrapper and event post
int  set_private_addr(int a1, int a2)
{
  uint8_t v2; // r0

  v2 = parse_number(*(uint8_t **)(a2 + 4), 0, 0);
  rf_write_synth(v2);
  dispatch_event_handler(dword_124F5C);
  return 0;
}

