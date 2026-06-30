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

// sub_12D8DC @ 0x12d8dc, size 60 bytes
uint8_t * sub_12D8DC(uint8_t *result, int a2, uint8_t *a3)
{
  unsigned int v3; // r1
  int v4; // r4
  uint8_t *v5; // r5

  v3 = (unsigned int)&result[a2];
  if ( v3 <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    v4 = (uint8_t)result[1];
    v5 = &result[v4 + 2];
    if ( *result == 50 )
      break;
    result += v4 + 2;
    if ( v3 <= (unsigned int)(v5 + 1) )
      return 0;
  }
  if ( v3 >= (unsigned int)v5 )
  {
    if ( !result )
      return result;
    if ( result[1] )
    {
      *a3 = v4;
      return result;
    }
  }
  return 0;
}

