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

// tx_phy_dispatch @ 0x10c444, size 74 bytes
// Doc: tx_phy_dispatch [tx]: TX PHY dispatch entry, zero frame header and route to PHY tx path
// tx_phy_dispatch [tx]: TX PHY dispatch entry, zero frame header and route to PHY tx path
void  __noreturn tx_phy_dispatch(int a1, int a2)
{
  sub_101DE8(a1, a2, a2, 0);
}

