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

// sub_132910 @ 0x132910, size 158 bytes
int  sub_132910(char a1)
{
  unsigned int v1; // r3
  int result; // r0

  v1 = a1 & 0x7F;
  if ( v1 > 0x48 )
  {
    if ( v1 == 96 )
    {
      return 10;
    }
    else if ( v1 == 108 )
    {
      return 11;
    }
    else
    {
      return 255;
    }
  }
  else if ( (a1 & 0x7E) != 0 )
  {
    switch ( a1 & 0x7F )
    {
      case 2:
        result = 0;
        break;
      case 4:
        result = 1;
        break;
      case 0xB:
        result = 2;
        break;
      case 0xC:
        result = 4;
        break;
      case 0x12:
        result = 5;
        break;
      case 0x16:
        result = 3;
        break;
      case 0x18:
        result = 6;
        break;
      case 0x24:
        result = 7;
        break;
      case 0x30:
        result = 8;
        break;
      case 0x48:
        result = 9;
        break;
      default:
        return 255;
    }
  }
  else
  {
    return 255;
  }
  return result;
}

