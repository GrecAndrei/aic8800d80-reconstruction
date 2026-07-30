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

extern uint32_t off_101A34;

// mmio_bit_modify @ 0x101a20, size 20 bytes
// Doc: mmio_bit_modify [mmio]: Read-modify-write MMIO register at 0x403410a0 clearing/setting bit 3 based on arg
// mmio_bit_modify [mmio]: Read-modify-write MMIO register at 0x403410a0 clearing/setting bit 3 based on arg
unsigned int  mmio_bit_modify(int a1)
{
  unsigned int result; // r0

  result = (8 * a1) & 8 | *(uint32_t *)off_101A34 & 0xFFFFFFF7;
  *(uint32_t *)off_101A34 = result;
  return result;
}

