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

extern uint32_t off_101898;

// sub_101888 @ 0x101888, size 14 bytes
// Doc: sub_1201888 [util]: Returns 1 if value equals 1, else 0
// sub_1201888 [util]: Returns 1 if value equals 1, else 0
BOOL sub_101888()
{
  return *(uint32_t *)off_101898 > 1u;
}

