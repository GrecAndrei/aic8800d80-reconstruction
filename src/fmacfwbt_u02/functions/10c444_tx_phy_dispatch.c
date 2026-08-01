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

// sdio_transfer_setup @ 0x10c444, size 74 bytes
// Doc: sdio_transfer_setup [tx]: TX PHY dispatch entry, zero frame header and route to PHY tx path
// sdio_transfer_setup [tx]: TX PHY dispatch entry, zero frame header and route to PHY tx path
void  __noreturn sdio_transfer_setup(int a1, int a2)
{
  format_log_message(a1, a2, a2, 0);
}

