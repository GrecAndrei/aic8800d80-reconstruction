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

// rf_phy_to_power_map @ 0x1327b8, size 22 bytes
int  rf_phy_to_power_map(char a1)
{
  int v1; // r0

  v1 = a1 & 3;
  if ( v1 == 1 )
    return 8;
  if ( v1 == 2 )
    return 9;
  return 7;
}

