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

extern uint32_t off_100BD0;
extern uint32_t off_100BD4;
extern uint32_t off_100BD8;
extern uint32_t off_100BDC;
extern uint32_t off_100BCC;

// radio_clock_disable @ 0x100b90, size 60 bytes
uint32_t *radio_clock_disable()
{
  uint32_t *v0; // r3
  uint32_t *result; // r0
  uint32_t *v2; // r1
  uint8_t *v3; // r4

  v0 = off_100BD0;
  result = off_100BD4;
  v2 = off_100BD8;
  v3 = off_100BDC;
  *(uint32_t *)off_100BCC &= 0xFFFFF9FF;
  *v0 &= ~0x40000000u;
  *v0 &= ~0x80000000;
  *result &= ~0x1000u;
  *v2 &= 0xCFFFFFFF;
  *v3 = 0;
  return result;
}

