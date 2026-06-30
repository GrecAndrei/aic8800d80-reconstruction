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

extern uint32_t off_1030A8;
extern uint32_t off_1030AC;

// sub_103058 @ 0x103058, size 78 bytes
unsigned int  sub_103058(unsigned int result)
{
  if ( result )
  {
    if ( *((uint8_t *)off_1030A8 + 362) )
      result = sub_1029F8(0xB5u);
    *(uint32_t *)off_1030AC |= 2u;
  }
  else
  {
    if ( *((uint8_t *)off_1030A8 + 362) )
      result = sub_1029F8(0xC2u);
    *(uint32_t *)off_1030AC &= ~2u;
  }
  return result;
}

