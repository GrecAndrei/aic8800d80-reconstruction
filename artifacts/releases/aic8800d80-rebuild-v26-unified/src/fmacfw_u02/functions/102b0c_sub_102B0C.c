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

// sub_102B0C @ 0x102b0c, size 62 bytes
int  sub_102B0C(unsigned int a1)
{
  if ( a1 > 0x1666 )
    return 5;
  if ( a1 > 0x1616 )
    return 4;
  if ( a1 > 0x15C6 )
    return 3;
  if ( a1 > 0x1571 )
    return 2;
  return a1 > 0x1486;
}

