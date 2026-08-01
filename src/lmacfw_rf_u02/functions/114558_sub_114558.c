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

// bus_read32 @ 0x114558, size 10 bytes
// Doc: sub_1214558 [util]: Trivial stub: r1=r0, r2=4, r0=1 (init/setup helper)
// sub_1214558 [util]: Trivial stub: r1=r0, r2=4, r0=1 (init/setup helper)
int  bus_read32(int a1)
{
  return ke_task_handler(1, a1, 4u);
}

