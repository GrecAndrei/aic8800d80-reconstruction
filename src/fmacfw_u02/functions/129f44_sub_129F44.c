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

extern uint32_t dword_129F60;
extern uint32_t off_129F64;

// llc_reset @ 0x129f44, size 26 bytes
// Doc: sub_1229F44 [util]: Init helper: calls sub with arg=1, then writes 0xff to indexed offset
// sub_1229F44 [util]: Init helper: calls sub with arg=1, then writes 0xff to indexed offset
int *llc_reset()
{
  int *result; // r0
  uint8_t *v1; // r3

  result = memset((int *)dword_129F60, 0, 1u);
  v1 = off_129F64;
  *((uint8_t *)off_129F64 + 113) = -1;
  v1[253] = -1;
  return result;
}

