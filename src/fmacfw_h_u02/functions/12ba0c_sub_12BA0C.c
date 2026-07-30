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

extern uint32_t off_12BA90;
extern uint32_t off_12BA94;
extern uint32_t off_12BA8C;
extern uint32_t off_12BA98;
extern uint32_t off_12BA9C;
extern uint32_t off_12BAA0;
extern uint32_t dword_12BAA4;
extern uint32_t off_12BAA8;
extern uint32_t off_12BAAC;

// sub_12BA0C @ 0x12ba0c, size 126 bytes
int *sub_12BA0C()
{
  uint32_t *v0; // r1
  uint32_t *v1; // r0
  uint32_t *v2; // r2
  uint32_t *v3; // r1
  uint32_t *v4; // r5
  int *v5; // r0
  int v6; // r4
  uint32_t *v7; // r1
  uint32_t *v8; // r4
  int v9; // r3
  int *result; // r0

  v0 = off_12BA90;
  v1 = off_12BA94;
  *(uint32_t *)off_12BA8C &= ~0x80u;
  *v0 = 0;
  *v1 = 60;
  while ( *v0 << 28 )
    ;
  v2 = off_12BA94;
  v3 = off_12BA98;
  v4 = off_12BA9C;
  v5 = (int *)off_12BAA0;
  v6 = dword_12BAA4;
  *(uint32_t *)off_12BA94 |= 0x10000u;
  *v3 &= 0xFFFFFF00;
  *v4 = -1;
  *v5 = v6;
  v7 = off_12BAA8;
  v8 = off_12BAAC;
  v2[8200] |= 0x80000000;
  v9 = v7[1];
  v4[1] |= 0x80000000;
  result = v5 - 8201;
  *v8 |= 0x80000000;
  *result |= 0x80u;
  v7[1] = v9 & 0xFFFFFFFB;
  return result;
}

