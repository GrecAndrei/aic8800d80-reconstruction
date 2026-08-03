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

extern uint32_t dword_124F98;
extern uint32_t dword_124F94;

// sub_124F60 @ 0x124f60, size 50 bytes
int  sub_124F60(int a1, int a2)
{
  int v2; // r4

  if ( a1 <= 1 )
  {
    msg_parse(dword_124F98);
    return 1;
  }
  else
  {
    v2 = (uint8_t)parse_int(*(uint8_t **)(a2 + 4), 0, 0xAu);
    sub_123F64(v2);
    if ( v2 )
      msg_parse(dword_124F94);
    return 0;
  }
}

