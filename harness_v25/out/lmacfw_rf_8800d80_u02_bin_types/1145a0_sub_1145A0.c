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

// sub_1145A0 @ 0x1145a0, size 10 bytes
// Doc: sub_12145A0_5a0 [rf]: lmac RF behavioral stub
// sub_12145A0_5a0 [rf]: lmac RF behavioral stub
int  sub_1145A0(int a1)
{
  return rf_init_or_config_n_318(8, a1, 4u);
}

