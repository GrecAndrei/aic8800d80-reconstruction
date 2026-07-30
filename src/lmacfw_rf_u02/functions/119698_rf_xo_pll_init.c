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

// rf_xo_pll_init @ 0x119698, size 20 bytes
// Doc: rf_xo_pll_init [rf]: Initializes RF XO/PLL subsystem (cmd 0x76)
// rf_xo_pll_init [rf]: Initializes RF XO/PLL subsystem (cmd 0x76)
int  rf_xo_pll_init(int a1, int a2, int a3, int a4)
{
  int v4; // r0

  v4 = rf_setup_dispatch(118, a4, a3, 12);
  sub_11DE50(v4);
  return 0;
}

