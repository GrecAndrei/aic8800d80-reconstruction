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

// tx_phy_dispatch_c5ec @ 0x10c5ec, size 74 bytes
// Doc: tx_phy_dispatch_c5ec [tx]: TX PHY frame dispatch with channel/phy parameters
// tx_phy_dispatch_c5ec [tx]: TX PHY frame dispatch with channel/phy parameters
void  __noreturn tx_phy_dispatch_c5ec(int a1, int a2)
{
  sub_101F70(a1, a2, a2, 0);
}

