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

// sub_12C488 @ 0x12c488, size 26 bytes
BOOL  sub_12C488(int a1, unsigned int a2)
{
  return *(uint16_t *)(a1 + 4) == HIWORD(a2) && *(uint16_t *)(a1 + 6) == (uint16_t)a2;
}

