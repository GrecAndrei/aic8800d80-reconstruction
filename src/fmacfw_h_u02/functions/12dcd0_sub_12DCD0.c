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

// sub_12DCD0 @ 0x12dcd0, size 64 bytes
uint8_t * sub_12DCD0(uint8_t *result, int a2)
{
  uint8_t *v2; // r1
  uint8_t *v3; // r2

  v2 = &result[a2];
  if ( v2 <= result + 1 )
    return nullptr;
  while ( 1 )
  {
    v3 = &result[(uint8_t)result[1] + 2];
    if ( *result == 85 )
      break;
    result += (uint8_t)result[1] + 2;
    if ( v2 <= v3 + 1 )
      return nullptr;
  }
  if ( v2 < v3 )
    return nullptr;
  if ( result )
  {
    if ( !result[1] )
      return nullptr;
  }
  return result;
}
