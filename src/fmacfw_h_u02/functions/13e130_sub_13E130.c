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

// util_read_halfword @ 0x13e130, size 78 bytes
uint16_t * util_read_halfword(uint16_t *result)
{
  unsigned int v1; // r3
  int v2; // r1
  unsigned int v3; // r2
  int v4; // r4
  int v5; // r3

  v1 = *result;
  if ( *result )
  {
    v2 = *((uint8_t *)result + 9);
    v3 = result[1] << 16;
    *((uint8_t *)result + 8) = 0;
    v4 = v3 / v1;
    if ( v2 )
    {
      result[2] = (3 * (unsigned int)result[2] + v4) >> 2;
    }
    else
    {
      if ( v3 >= v1 )
        LOWORD(v2) = v4 - 1;
      result[2] = v2;
      *((uint8_t *)result + 9) = 1;
    }
  }
  else
  {
    v5 = *((uint8_t *)result + 8);
    if ( v5 != 255 )
      *((uint8_t *)result + 8) = v5 + 1;
  }
  return result;
}

