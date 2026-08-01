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

// double_eq @ 0x127af0, size 18 bytes
BOOL  double_eq(unsigned int a1, unsigned int a2, unsigned int a3, int a4)
{
  char v4; // zf

  double_compare_flags(a1, a2, a3, a4);
  return v4 != 0;
}

