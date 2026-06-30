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

extern uint32_t dword_1250D0;
extern uint32_t dword_1250CC;

// sub_1250A0 @ 0x1250a0, size 42 bytes
int  sub_1250A0(int a1, int a2)
{
  uint8_t v2; // r0

  if ( a1 <= 1 )
  {
    msg_parse(dword_1250D0);
    return 1;
  }
  else
  {
    v2 = parse_int(*(uint8_t **)(a2 + 4), 0, 0xAu);
    sub_123FA0(v2);
    msg_parse(dword_1250CC);
    return 0;
  }
}

