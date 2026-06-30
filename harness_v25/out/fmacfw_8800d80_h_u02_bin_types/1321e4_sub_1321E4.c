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

// sub_1321E4 @ 0x1321e4, size 48 bytes
int  sub_1321E4(int a1)
{
  uint8_t *v2; // r4

  v2 = (uint8_t *)sub_12C7EC(12, 0, 5, 1u);
  sub_13BCD4(a1);
  *v2 = a1;
  sub_12C84C((int)v2);
  return sub_12C8D0(5130, 13, 5);
}

