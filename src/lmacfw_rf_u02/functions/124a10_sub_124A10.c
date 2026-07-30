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

extern uint32_t dword_124A48;
extern uint32_t dword_124A4C;
extern uint32_t off_124A44;

// sub_124A10 @ 0x124a10, size 52 bytes
int  sub_124A10(int a1, int a2)
{
  int v2; // r3

  if ( a1 <= 1 )
  {
    msg_parse(dword_124A48);
    return 1;
  }
  else
  {
    v2 = parse_int(*(uint8_t **)(a2 + 4), 0, 0xAu);
    if ( (unsigned int)(v2 - 1) <= 0x30 )
    {
      msg_parse(dword_124A4C);
      return 1;
    }
    else
    {
      *(uint32_t *)off_124A44 = v2;
      return 0;
    }
  }
}

