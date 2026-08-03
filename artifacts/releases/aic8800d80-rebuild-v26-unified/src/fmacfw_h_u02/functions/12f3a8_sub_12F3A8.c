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

extern uint32_t off_12F3C4;

// sub_12F3A8 @ 0x12f3a8, size 26 bytes
int *sub_12F3A8()
{
  uint64_t *v0; // r4
  int *result; // r0

  v0 = off_12F3C4;
  result = sub_100200((int *)off_12F3C4, 0, 8u);
  *v0 = 0x2FFFFFFFFLL;
  return result;
}

