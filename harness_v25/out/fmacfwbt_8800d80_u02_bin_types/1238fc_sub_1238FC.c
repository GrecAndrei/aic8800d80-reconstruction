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

// sub_1238FC @ 0x1238fc, size 32 bytes
// Doc: sub_12238FC [util]: Format/build trace message with ':' separator
// sub_12238FC [util]: Format/build trace message with ':' separator
int  sub_1238FC(int a1, uint8_t *a2, int a3, int a4)
{
  int v4; // r3

  sub_1287E0(*a2);
  message_dispatch_n84(58, a4, a3, v4);
  return 0;
}

