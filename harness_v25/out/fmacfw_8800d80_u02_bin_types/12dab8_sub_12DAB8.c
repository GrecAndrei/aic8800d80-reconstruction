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

// sub_12DAB8 @ 0x12dab8, size 66 bytes
uint8_t * sub_12DAB8(uint8_t *result, int a2, int *a3)
{
  unsigned int v3; // r1
  uint8_t *v4; // r4

  v3 = (unsigned int)&result[a2];
  if ( v3 <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    v4 = &result[(uint8_t)result[1] + 2];
    if ( *result == 62 )
      break;
    result += (uint8_t)result[1] + 2;
    if ( v3 <= (unsigned int)(v4 + 1) )
      return 0;
  }
  if ( v3 < (unsigned int)v4 )
    return 0;
  if ( result )
    *a3 = result[1] == 1;
  return result;
}

