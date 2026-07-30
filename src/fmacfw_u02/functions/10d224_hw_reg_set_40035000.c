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

extern uint32_t off_10D230;

// hw_reg_set_40035000 @ 0x10d224, size 10 bytes
// Doc: hw_reg_set_40035000 [mmio]: Write 0x02000000 to MMIO register at 0x40035000
// hw_reg_set_40035000 [mmio]: Write 0x02000000 to MMIO register at 0x40035000
void hw_reg_set_40035000()
{
  *(uint32_t *)off_10D230 = 0x2000000;
}

