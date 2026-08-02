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

// sub_13C520 @ 0x13c520, size 146 bytes
BOOL  sub_13C520(char a1, unsigned int a2)
{
  int v2; // r3

  if ( (a1 & 0xC) != 0 )
    return 0;
  v2 = a1 & 0xF0;
  if ( v2 == 192 )
    return 1;
  if ( v2 != 208 )
    return v2 == 160;
  if ( a2 <= 0x16 )
  {
    if ( a2 > 3 )
    {
      switch ( a2 )
      {
        case 4u:
        case 7u:
        case 0xBu:
        case 0xFu:
        case 0x16u:
          return 0;
        default:
          return 1;
      }
    }
    return 1;
  }
  return a2 != 127;
}
