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

// sub_1145DC @ 0x1145dc, size 10 bytes
// Doc: sub_12145DC [mmio]: Small register move helper, likely MMIO/macro stub
// sub_12145DC [mmio]: Small register move helper, likely MMIO/macro stub
int  sub_1145DC(int a1)
{
  return rf_init_or_config_n_318(128, a1, 4u);
}

