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

extern uint32_t off_103CA0;

// clear_chip_ctrl_clk @ 0x103c6c, size 50 bytes
// Doc: clear_chip_ctrl_clk [mmio]: Toggle crypto hardware clock bits in MMIO register
// clear_chip_ctrl_clk [mmio]: Toggle crypto hardware clock bits in MMIO register
int clear_chip_ctrl_clk()
{
  uint32_t *v0; // r4
  int result; // r0

  v0 = off_103CA0;
  *(uint32_t *)off_103CA0 &= ~0x400000u;
  *v0 &= ~0x200000u;
  timer_delay(2);
  *v0 |= 0x200000u;
  result = timer_delay(2);
  *v0 |= 0x400000u;
  return result;
}

