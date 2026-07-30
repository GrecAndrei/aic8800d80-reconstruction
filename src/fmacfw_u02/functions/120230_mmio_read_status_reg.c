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

extern uint32_t off_120240;

// mmio_read_status_reg @ 0x120230, size 16 bytes
// Doc: mmio_read_status_reg [mmio]: Read status register at 0x40501000+0x2710
// mmio_read_status_reg [mmio]: Read status register at 0x40501000+0x2710
int  mmio_read_status_reg(int a1)
{
  return timestamp_update(a1 + 48, *((uint32_t *)off_120240 + 4) + 10000);
}

