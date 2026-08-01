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

// parse_data_4 @ 0x12dfb0, size 72 bytes
// Doc: phy_calibrate [rf]: Dumps RF fault status and triggers fault handling path
// phy_calibrate [rf]: Dumps RF fault status and triggers fault handling path
uint8_t * parse_data_4(uint8_t *result, int a2)
{
  unsigned int v2; // r1
  unsigned int v3; // r3
  uint8_t *v4; // r4

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    v3 = result[1] + 2;
    v4 = &result[v3];
    if ( !*result )
      break;
    result += v3;
    if ( v2 <= (unsigned int)(v4 + 1) )
      return 0;
  }
  if ( v2 < (unsigned int)v4 )
    return (uint8_t *)*result;
  if ( result )
  {
    if ( v3 < 6 )
      return 0;
  }
  return result;
}

