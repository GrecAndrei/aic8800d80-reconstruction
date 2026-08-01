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

extern uint32_t off_10DEF8;
extern uint32_t off_10DEFC;
extern uint32_t dword_10DF00;
extern uint32_t dword_10DF04;

// hw_block_reset @ 0x10deb0, size 72 bytes
int hw_block_reset()
{
  uint32_t *v0; // r3
  uint32_t *v1; // r0
  int v2; // r1
  int v3; // r2
  int result; // r0

  v0 = off_10DEF8;
  v1 = off_10DEFC;
  v2 = dword_10DF00;
  v3 = dword_10DF04;
  *(uint32_t *)off_10DEF8 = 0;
  v1[14] = 296;
  v0[2] = v0[2] & 0xF000FFFF | 0x2000000;
  result = v0[3];
  v0[3] = v2 & result | 0xA06A000;
  v0[3] = v3 & v0[3] | 0x100230;
  v0[1] = 1;
  return result;
}

