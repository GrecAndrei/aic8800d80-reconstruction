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

// rx_packet_init @ 0x10c5ec, size 74 bytes
// Doc: rx_packet_init [tx]: TX PHY frame dispatch with channel/phy parameters
// rx_packet_init [tx]: TX PHY frame dispatch with channel/phy parameters
void  __noreturn rx_packet_init(int a1, int a2)
{
  tx_packet_handler(a1, a2, a2, 0);
}

