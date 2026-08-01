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

// check_one_12dd48 @ 0x12dd48, size 64 bytes
// Doc: sdio_buffer_prepare_n_3ac [mmio]: Validate channel/type against 6 and return status
// sdio_buffer_prepare_n_3ac [mmio]: Validate channel/type against 6 and return status
uint8_t * check_one_12dd48(uint8_t *result, int a2)
{
  unsigned int v2; // r1
  unsigned int v3; // r3
  uint8_t *v4; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    v3 = (uint8_t)result[1] + 2;
    v4 = &result[v3];
    if ( *result == 71 )
      break;
    result += v3;
    if ( v2 <= (unsigned int)(v4 + 1) )
      return 0;
  }
  if ( v2 < (unsigned int)v4 )
    return 0;
  if ( result )
  {
    if ( v3 < 6 )
      return 0;
  }
  return result;
}

