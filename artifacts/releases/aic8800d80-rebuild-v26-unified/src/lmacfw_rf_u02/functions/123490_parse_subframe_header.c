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

extern uint32_t off_1234DC;
extern uint32_t off_1234D8;
extern uint32_t off_1234E0;

// parse_subframe_header @ 0x123490, size 70 bytes
// Doc: parse_subframe_header [rx]: Parses subframe header bytes, checks tag 0xc0
// parse_subframe_header [rx]: Parses subframe header bytes, checks tag 0xc0
uint8_t * parse_subframe_header(uint8_t *result)
{
  int v1; // r4
  uint32_t *v2; // r3
  char v3; // r2

  if ( result[1] == 192 && result[2] == 181 && result[3] == 122 )
  {
    v1 = result[4];
    if ( (uint8_t)(v1 + 106) <= 1u )
    {
      v2 = off_1234DC;
      *(uint8_t *)off_1234D8 = result[5];
      result = (uint8_t *)mmio_write_40320150(*v2 + 20000);
      if ( v1 == 150 )
        v3 = 2;
      else
        v3 = 0;
      *(uint8_t *)off_1234E0 = v3;
    }
  }
  return result;
}

