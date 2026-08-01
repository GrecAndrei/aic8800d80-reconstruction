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

extern uint32_t dword_118F70;

// phy_is_channel_valid @ 0x118f4c, size 36 bytes
int  phy_is_channel_valid(int a1, int a2, int a3)
{
  if ( (*(uint32_t *)(dword_118F70 + 696 * a1 + 4) & 0x20) != 0 )
    return phy_set_channel(a1, 7, a2, a3);
  else
    return phy_get_channel(a1, a2, a3);
}

