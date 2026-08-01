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

// rf_set_pa_bit @ 0x101a20, size 20 bytes
unsigned int  rf_set_pa_bit(int a1)
{
  unsigned int result; // r0

  result = (8 * a1) & 8 | *(uint32_t *)off_101A34 & 0xFFFFFFF7;
  *(uint32_t *)off_101A34 = result;
  return result;
}

