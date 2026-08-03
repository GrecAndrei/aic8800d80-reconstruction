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

// sub_124F40 @ 0x124f40, size 28 bytes
// Doc: sub_1224F42 [rf]: RF register read wrapper and event post
// sub_1224F42 [rf]: RF register read wrapper and event post
int  sub_124F40(int a1, int a2)
{
  uint8_t v2; // r0

  v2 = parse_int(*(uint8_t **)(a2 + 4), 0, 0);
  sub_124150(v2);
  msg_parse(dword_124F5C);
  return 0;
}

