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

extern uint32_t off_141F18;

// msg_parse_top_nibble @ 0x141ed4, size 68 bytes
// Doc: sub_1241ED8 [util]: Generic helper; saves arg and tail-calls a function
// sub_1241ED8 [util]: Generic helper; saves arg and tail-calls a function
int  msg_parse_top_nibble(int a1)
{
  int16_t v1; // r3
  uint8_t *v3; // r1
  int result; // r0

  v1 = *(uint16_t *)a1;
  if ( (*(uint16_t *)a1 & 8) != 0 )
  {
    v3 = off_141F18;
    *(uint16_t *)a1 = v1 | 0x40;
    if ( v3[1] )
    {
      if ( (v1 & 9) == 9 )
        fmac_init_handler_1e48(a1);
    }
  }
  result = timestamp_remove(a1 + 52);
  if ( !*(uint8_t *)(a1 + 4) )
  {
    result = *(uint8_t *)(a1 + 47);
    *((uint8_t *)off_141F18 + 2) &= ~(1 << result);
  }
  return result;
}

