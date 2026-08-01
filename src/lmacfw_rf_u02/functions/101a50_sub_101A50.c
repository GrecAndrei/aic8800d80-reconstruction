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

extern uint32_t off_101A64;

// ctrl_bit3_set @ 0x101a50, size 20 bytes
unsigned int  ctrl_bit3_set(int a1)
{
  unsigned int result; // r0

  result = (8 * a1) & 8 | *(uint32_t *)off_101A64 & 0xFFFFFFF7;
  *(uint32_t *)off_101A64 = result;
  return result;
}

