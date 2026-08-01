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

extern uint32_t off_12F72C;

// timer_clear @ 0x12f710, size 26 bytes
// Doc: timer_clear [util]: Initialize firmware buffer/memory region
// timer_clear [util]: Initialize firmware buffer/memory region
int *timer_clear()
{
  uint64_t *v0; // r4
  int *result; // r0

  v0 = off_12F72C;
  result = memset_byte((int *)off_12F72C, 0, 8u);
  *v0 = 0x2FFFFFFFFLL;
  return result;
}

