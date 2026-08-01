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

extern uint32_t dword_124F3C;

// set_random_addr @ 0x124f20, size 26 bytes
int  set_random_addr(int a1, int a2)
{
  int v2; // r0

  v2 = parse_number(*(uint8_t **)(a2 + 4), 0, 0xAu);
  set_reg_180800_bit9(v2);
  dispatch_event_handler(dword_124F3C);
  return 0;
}

