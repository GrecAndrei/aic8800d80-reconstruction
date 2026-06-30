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

extern uint32_t off_10332C;
extern uint32_t off_103330;

// sub_1032DC @ 0x1032dc, size 78 bytes
unsigned int  sub_1032DC(unsigned int result)
{
  if ( result )
  {
    if ( *((uint8_t *)off_10332C + 362) )
      result = sub_1029DC(0xB5u);
    *(uint32_t *)off_103330 |= 2u;
  }
  else
  {
    if ( *((uint8_t *)off_10332C + 362) )
      result = sub_1029DC(0xC2u);
    *(uint32_t *)off_103330 &= ~2u;
  }
  return result;
}

