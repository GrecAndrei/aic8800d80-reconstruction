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

extern uint32_t off_10E2C8;
extern uint32_t off_10E2CC;
extern uint32_t dword_10E2D0;
extern uint32_t dword_10E2D4;
extern uint32_t dword_10E2D8;

// sub_10E21C @ 0x10e21c, size 170 bytes
float sub_10E21C()
{
  uint32_t *v0; // r3
  uint32_t *v1; // r1
  int v2; // r2
  int v3; // r5
  int v4; // r4

  v0 = off_10E2C8;
  v1 = off_10E2CC;
  v2 = dword_10E2D0;
  *(uint32_t *)off_10E2C8 = 0;
  v1[14] = 296;
  v3 = dword_10E2D4;
  v4 = dword_10E2D8;
  v0[2] = v0[2] & 0xF000FFFF | 0x2000000;
  v0[3] = v2 & v0[3] | 0xA06A000;
  v0[3] = v4 | v3 & v0[3];
  v0[2] = v0[2] & 0xEFFFFFF0 | 0xB;
  v0[3] = v0[3] & 0xFFFFF7FE | 1;
  v0[2] &= ~0x10000000u;
  v0[3] = v0[3] & 0xFFFFF7FE | 1;
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  return (float)((float)((float)(unsigned int)v0[4] / flt_10E2DC) - 1.0) * flt_10E2E0;
}

