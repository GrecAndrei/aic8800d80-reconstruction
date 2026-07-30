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

// crypto_hw_clk_toggle_3c6c @ 0x103c6c, size 50 bytes
// Doc: crypto_hw_clk_toggle_3c6c [mmio]: Toggle crypto hardware clock bits in MMIO register
// crypto_hw_clk_toggle_3c6c [mmio]: Toggle crypto hardware clock bits in MMIO register
int crypto_hw_clk_toggle_3c6c()
{
  uint32_t *v0; // r4
  int result; // r0

  v0 = off_103CA0;
  *(uint32_t *)off_103CA0 &= ~0x400000u;
  *v0 &= ~0x200000u;
  delay_us_0644(2);
  *v0 |= 0x200000u;
  result = delay_us_0644(2);
  *v0 |= 0x400000u;
  return result;
}

