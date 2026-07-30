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

// sub_13D11C @ 0x13d11c, size 240 bytes
int  sub_13D11C(int a1, unsigned int a2)
{
  int result; // r0
  int v3; // r2
  int v4; // r3
  int v5; // r1

  switch ( (a2 >> 11) & 7 )
  {
    case 0u:
    case 1u:
      return (*(uint16_t *)(a1 + 174) >> (a2 & 0x7F)) & 1;
    case 2u:
    case 3u:
      return (*(uint8_t *)(a1 + ((a2 >> 3) & 3) + 170) >> (a2 & 7)) & 1;
    case 4u:
      v3 = (a2 >> 4) & 7;
      v4 = a2 & 0xF;
      result = v4 <= (((int)*(uint16_t *)(a1 + 170) >> (2 * v3)) & 3) + 7;
      v5 = (a2 >> 7) & 3;
      if ( v4 == 6 )
      {
        if ( v5 == 2 )
        {
          if ( v3 == 3 )
            return 0;
          if ( v3 == 6 )
            return 0;
        }
      }
      else if ( v4 == 9 )
      {
        if ( v5 )
        {
          if ( v5 == 2 )
          {
            if ( v3 == 5 )
              return 0;
          }
          else if ( v5 == 3 && v3 == 2 )
          {
            return 0;
          }
        }
        else if ( v3 != 2 && v3 != 5 )
        {
          return 0;
        }
      }
      return result;
    case 5u:
      return (uint8_t)(a2 & 0xF) <= 2 * (((int)*(uint16_t *)(a1 + 170) >> (2 * ((a2 >> 4) & 7))) & 3)
                                          + 7;
    case 7u:
      result = (a2 >> 7) & 3;
      if ( (a2 & 0xF) <= 2 )
      {
        if ( (a2 & 0xF) == 0 )
          return ((a2 >> 7) & 2 | (a2 >> 4) & 7) == 0;
      }
      else if ( !result )
      {
        return result;
      }
      if ( result != 1 )
        return ((a2 >> 7) & 2 | (a2 >> 4) & 7) == 0;
      return 0;
    default:
      return 1;
  }
}

