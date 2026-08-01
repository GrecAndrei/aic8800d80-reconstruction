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

extern uint32_t off_10DE90;
extern uint32_t off_10DE94;
extern uint32_t dword_10DE98;
extern uint32_t dword_10DE9C;

// gpio_reset @ 0x10de48, size 72 bytes
int gpio_reset()
{
  uint32_t *v0; // r3
  uint32_t *v1; // r0
  int v2; // r1
  int v3; // r2
  int result; // r0

  v0 = off_10DE90;
  v1 = off_10DE94;
  v2 = dword_10DE98;
  v3 = dword_10DE9C;
  *(uint32_t *)off_10DE90 = 0;
  v1[14] = 296;
  v0[2] = v0[2] & 0xF000FFFF | 0x2000000;
  result = v0[3];
  v0[3] = v2 & result | 0xA06A000;
  v0[3] = v3 & v0[3] | 0x100230;
  v0[1] = 1;
  return result;
}

