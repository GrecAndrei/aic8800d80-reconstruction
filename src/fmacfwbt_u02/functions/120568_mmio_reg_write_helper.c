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

extern uint32_t off_120578;

// mmio_reg_write_helper @ 0x120568, size 16 bytes
// Doc: mmio_reg_write_helper [mmio]: Writes to MMIO register window at 0x40501000 with computed offset and value
// mmio_reg_write_helper [mmio]: Writes to MMIO register window at 0x40501000 with computed offset and value
int  mmio_reg_write_helper(int a1)
{
  return timestamp_update_4f60(a1 + 48, *((uint32_t *)off_120578 + 4) + 10000);
}

