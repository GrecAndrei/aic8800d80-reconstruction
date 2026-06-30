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

// sub_127F10 @ 0x127f10, size 24 bytes
unsigned uint64_t  sub_127F10(int a1, int a2)
{
  unsigned uint64_t v3; // [sp+0h] [bp-10h]

  v3 = __PAIR64__(a1, a2);
  sub_127EB0(a2, a1);
  return v3;
}

