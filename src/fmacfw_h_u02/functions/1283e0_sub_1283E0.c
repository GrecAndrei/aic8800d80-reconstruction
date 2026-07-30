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

extern uint32_t off_128404;

// sub_1283E0 @ 0x1283e0, size 34 bytes
BOOL  sub_1283E0(int a1)
{
  BOOL result; // r0

  result = sub_128390(a1);
  if ( result )
    return !*((uint32_t *)off_128404 + 11) || *(uint8_t *)(*((uint32_t *)off_128404 + 10) + 16) == 6;
  return result;
}

