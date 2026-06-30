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

extern uint32_t off_108274;
extern uint32_t off_108270;
extern uint32_t dword_108278;
extern uint32_t off_10827C;

// sub_108238 @ 0x108238, size 56 bytes
int sub_108238()
{
  unsigned int *v0; // r5
  int v1; // r6
  int16_t v2; // r4
  int result; // r0
  uint32_t *v4; // r1

  v0 = (unsigned int *)off_108274;
  v1 = *(uint32_t *)off_108274;
  v2 = (uint16_t)*(uint32_t *)off_108270 >> 4;
  result = feature_guard_check(1, dword_108278);
  v4 = off_10827C;
  *v0 = (v2 + (uint16_t)v1) & 0xFFF | *v0 & 0xFFFFF000;
  *v4 |= 0x400000u;
  return result;
}

