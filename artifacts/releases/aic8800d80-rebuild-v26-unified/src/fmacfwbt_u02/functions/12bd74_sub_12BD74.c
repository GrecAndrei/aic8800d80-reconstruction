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

extern uint32_t off_12BDF8;
extern uint32_t off_12BDFC;
extern uint32_t off_12BDF4;
extern uint32_t off_12BE00;
extern uint32_t off_12BE04;
extern uint32_t off_12BE08;
extern uint32_t dword_12BE0C;
extern uint32_t off_12BE10;
extern uint32_t off_12BE14;

// sub_12BD74 @ 0x12bd74, size 126 bytes
int *sub_12BD74()
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

  v0 = off_12BDF8;
  v1 = off_12BDFC;
  *(uint32_t *)off_12BDF4 &= ~0x80u;
  *v0 = 0;
  *v1 = 60;
  while ( *v0 << 28 )
    ;
  v2 = off_12BDFC;
  v3 = off_12BE00;
  v4 = off_12BE04;
  v5 = (int *)off_12BE08;
  v6 = dword_12BE0C;
  *(uint32_t *)off_12BDFC |= 0x10000u;
  *v3 &= 0xFFFFFF00;
  *v4 = -1;
  *v5 = v6;
  v7 = off_12BE10;
  v8 = off_12BE14;
  v2[8200] |= 0x80000000;
  v9 = v7[1];
  v4[1] |= 0x80000000;
  result = v5 - 8201;
  *v8 |= 0x80000000;
  *result |= 0x80u;
  v7[1] = v9 & 0xFFFFFFFB;
  return result;
}

