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

// sub_12C8D0 @ 0x12c8d0, size 16 bytes
int  sub_12C8D0(int16_t a1, int16_t a2, int16_t a3)
{
  int v3; // r0

  v3 = sub_12C7EC(a1, a2, a3, 0);
  return sub_12C84C(v3);
}

