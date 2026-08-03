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

// sub_1145D0 @ 0x1145d0, size 10 bytes
// Doc: sub_12145D0 [util]: Trivial wrapper setting up 4-byte call with 0x80 argument
// sub_12145D0 [util]: Trivial wrapper setting up 4-byte call with 0x80 argument
int  sub_1145D0(int a1)
{
  return rf_param_setup_44(64, a1, 4u);
}

