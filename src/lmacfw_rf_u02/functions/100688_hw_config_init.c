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

extern uint32_t off_1006B8;
extern uint32_t off_1006BC;
extern uint32_t off_1006B4;

// get_device_config @ 0x100688, size 42 bytes
uint32_t *get_device_config()
{
  uint32_t *result; // r0
  unsigned int *v1; // r2

  result = off_1006B8;
  v1 = (unsigned int *)off_1006BC;
  *(uint32_t *)off_1006B4 &= ~0x10000u;
  *result = 1;
  *v1 = *v1 & 0x1FFFFFFE | 0xC0000000;
  return result;
}

