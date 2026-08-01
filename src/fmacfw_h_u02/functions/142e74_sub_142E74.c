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

// double_greater_equal @ 0x142e74, size 18 bytes
BOOL  double_greater_equal(int a1, int a2, int a3, int a4)
{
  char v4; // cf
  char v5; // zf

  swap_double_operands(a1, a2, a3, a4);
  return !(!v5 & v4);
}

