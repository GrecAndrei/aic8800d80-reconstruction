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

extern uint32_t off_10079C;
extern uint32_t off_1007A0;
extern uint32_t off_100798;

// disable_interrupt @ 0x10076c, size 42 bytes
// Doc: disable_interrupt [util]: Firmware initialization early entry point
// disable_interrupt [util]: Firmware initialization early entry point
uint32_t *disable_interrupt()
{
  uint32_t *result; // r0
  unsigned int *v1; // r2

  result = off_10079C;
  v1 = (unsigned int *)off_1007A0;
  *(uint32_t *)off_100798 &= ~0x10000u;
  *result = 1;
  *v1 = *v1 & 0x1FFFFFFE | 0xC0000000;
  return result;
}

