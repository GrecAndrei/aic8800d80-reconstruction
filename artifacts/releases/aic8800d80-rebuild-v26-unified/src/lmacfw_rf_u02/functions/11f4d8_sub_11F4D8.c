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

extern uint32_t off_11F500;

// sub_11F4D8 @ 0x11f4d8, size 40 bytes
BOOL  sub_11F4D8(unsigned int a1, unsigned int a2)
{
  BOOL result; // r0

  if ( a1 > 9 )
    return 0;
  result = (*(uint32_t *)off_11F500 >> a1) & 1;
  if ( result )
    return *((uint32_t *)off_11F500 + 1) >= a2;
  return result;
}

