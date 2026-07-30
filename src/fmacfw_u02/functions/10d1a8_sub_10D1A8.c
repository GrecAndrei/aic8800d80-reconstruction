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

extern uint32_t off_10D1F0;
extern uint32_t off_10D1F4;
extern uint32_t off_10D1F8;

// sub_10D1A8 @ 0x10d1a8, size 70 bytes
int sub_10D1A8()
{
  uint32_t *v0; // r1
  uint32_t *v1; // r4
  uint32_t *v2; // r3

  v0 = off_10D1F0;
  v1 = off_10D1F4;
  v2 = off_10D1F8;
  *(uint32_t *)off_10D1F4 = 13369344;
  *v0 = 13369344;
  *v2 &= 0xFFFFFFCF;
  *v2 &= 0xFFFFFF3F;
  *v2 &= 0xFFFFCFFF;
  *v2 &= 0xFFFF3FFF;
  *v1 = 0x8000000;
  *v0 = 0x8000000;
  *v2 &= 0xFF3FFFFF;
  return 0x8000000;
}

