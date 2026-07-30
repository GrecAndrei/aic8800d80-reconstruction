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

// sub_13BA0C @ 0x13ba0c, size 22 bytes
// Doc: sub_123BA0C [patch]: Stub/trampoline: nop + load pointer (patch hook)
// sub_123BA0C [patch]: Stub/trampoline: nop + load pointer (patch hook)
int  sub_13BA0C(int16_t a1)
{
  return timer_set_relative(8194, (uint16_t)(a1 << 8) | 8, 0x1F4000u);
}

