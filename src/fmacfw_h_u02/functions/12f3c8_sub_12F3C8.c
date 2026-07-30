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

extern uint32_t dword_12F3E4;

// sub_12F3C8 @ 0x12f3c8, size 26 bytes
int sub_12F3C8()
{
  int v0; // r4

  v0 = dword_12F3E4;
  sub_100200((int *)dword_12F3E4, 0, 0x10u);
  sub_12D100((uint32_t *)(v0 + 8));
  return 0;
}

