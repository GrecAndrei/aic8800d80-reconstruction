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

extern uint32_t off_10DAD4;

// rf_channel_valid @ 0x10da88, size 74 bytes
// Doc: rf_channel_valid [util]: Computes power-of-two bitmask for given bit index
// rf_channel_valid [util]: Computes power-of-two bitmask for given bit index
int  rf_channel_valid(int result)
{
  int v1; // r2

  v1 = 1 << result;
  if ( result <= 1 || (unsigned int)(result - 8) <= 1 )
  {
    result = 4 * result + 1079001088;
    *(uint32_t *)result = *(uint32_t *)result & 0xFFFFFFF0 | 1;
  }
  else if ( result <= 15 )
  {
    result = 4 * result + 1079001088;
    *(uint32_t *)result &= 0xFFFFFFF0;
  }
  *((uint32_t *)off_10DAD4 + 1) |= v1;
  return result;
}

