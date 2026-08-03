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

extern uint32_t off_101814;
extern uint32_t off_101810;

// sub_101800 @ 0x101800, size 14 bytes
uint32_t * sub_101800(uint32_t *result, uint32_t *a2)
{
  uint32_t *v2; // r3

  v2 = off_101814;
  *result = *(uint32_t *)off_101810;
  *a2 = *v2;
  return result;
}

