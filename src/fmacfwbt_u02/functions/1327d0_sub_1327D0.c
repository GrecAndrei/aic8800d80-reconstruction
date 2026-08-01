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

// rf_phy_to_power_map2 @ 0x1327d0, size 22 bytes
int  rf_phy_to_power_map2(char a1)
{
  int v1; // r0

  v1 = a1 & 3;
  if ( v1 == 1 )
    return 9;
  if ( v1 == 2 )
    return 11;
  return 7;
}

