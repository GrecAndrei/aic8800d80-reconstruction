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

// util_is_zero @ 0x127f8c, size 48 bytes
int  util_is_zero(uint64_t a1, int a2, int a3)
{
  if ( a3 || a2 )
  {
    LODWORD(a1) = util_memcpy(a1);
  }
  else if ( a1 )
  {
    LODWORD(a1) = -1;
  }
  return a1;
}

