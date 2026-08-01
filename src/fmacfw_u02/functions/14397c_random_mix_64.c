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

extern uint32_t off_1439AC;
extern uint32_t dword_1439B0;
extern uint32_t dword_1439B4;

// scale_timer_value @ 0x14397c, size 46 bytes
// Doc: scale_timer_value [util]: Mix 64-bit value using magic constants (PRNG/random)
// scale_timer_value [util]: Mix 64-bit value using magic constants (PRNG/random)
int scale_timer_value()
{
  unsigned uint64_t v0; // kr00_8

  v0 = *(uint64_t *)(*(uint32_t *)off_1439AC + 168) * __PAIR64__(dword_1439B0, dword_1439B4) + 1;
  *(uint64_t *)(*(uint32_t *)off_1439AC + 168) = v0;
  return HIDWORD(v0) & 0x7FFFFFFF;
}

