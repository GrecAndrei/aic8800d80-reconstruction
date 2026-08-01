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

extern uint32_t off_10CF38;

// enable_uart @ 0x10cf2c, size 10 bytes
// Doc: enable_uart [mmio]: Write 0x100 to MMIO register 0x40035100 then return
// enable_uart [mmio]: Write 0x100 to MMIO register 0x40035100 then return
void enable_uart()
{
  *(uint32_t *)off_10CF38 = 256;
}

