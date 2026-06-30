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

// sub_127B04 @ 0x127b04, size 18 bytes
BOOL  sub_127B04(unsigned int a1, unsigned int a2, unsigned int a3, int a4)
{
  char v4; // cf

  sub_127AE0(a1, a2, a3, a4);
  return !v4;
}

