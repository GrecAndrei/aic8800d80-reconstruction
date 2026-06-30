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

extern uint32_t off_10CAD4;
extern uint32_t off_10CAD8;

// sub_10CAA8 @ 0x10caa8, size 44 bytes
int sub_10CAA8()
{
  uint32_t *v0; // r4
  int result; // r0

  v0 = off_10CAD4;
  while ( !*(uint32_t *)off_10CAD4 )
    ;
  result = *(uint32_t *)(*(uint32_t *)off_10CAD8 + 532);
  if ( result )
  {
    result = sub_12D4F8(*(uint32_t *)off_10CAD8 + 532);
    *v0 = 1;
    if ( result )
      result += 4;
  }
  else
  {
    *(uint32_t *)off_10CAD4 = 1;
  }
  return result;
}

