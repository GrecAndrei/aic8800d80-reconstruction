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

extern uint32_t dword_129E20;
extern uint32_t off_129E24;

// sub_129E04 @ 0x129e04, size 26 bytes
int *sub_129E04()
{
  int *result; // r0
  uint8_t *v1; // r3

  result = sub_100200((int *)dword_129E20, 0, 1u);
  v1 = off_129E24;
  *((uint8_t *)off_129E24 + 113) = -1;
  v1[253] = -1;
  return result;
}

