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

extern uint32_t off_10CB3C;
extern uint32_t off_10CB40;

// invoke_alt_handler @ 0x10cb10, size 44 bytes
int invoke_alt_handler()
{
  uint32_t *v0; // r4
  int result; // r0

  v0 = off_10CB3C;
  while ( !*(uint32_t *)off_10CB3C )
    ;
  result = *(uint32_t *)(*(uint32_t *)off_10CB40 + 596);
  if ( result )
  {
    result = list_pop(*(uint32_t *)off_10CB40 + 596);
    *v0 = 1;
    if ( result )
      result += 4;
  }
  else
  {
    *(uint32_t *)off_10CB3C = 1;
  }
  return result;
}

