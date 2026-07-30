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

extern uint32_t off_11D33C;
extern uint32_t off_11D340;
extern uint32_t off_11D344;

// sub_11D31C @ 0x11d31c, size 32 bytes
void *sub_11D31C()
{
  void *result; // r0
  uint32_t *v1; // r1
  uint32_t *v2; // r2

  result = off_11D33C;
  v1 = off_11D340;
  v2 = off_11D344;
  *(uint32_t *)off_11D33C &= ~0x80000000;
  *v1 &= ~0x80000000;
  *v2 &= ~0x80000000;
  return result;
}

