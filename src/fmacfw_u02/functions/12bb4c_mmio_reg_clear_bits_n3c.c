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

extern uint32_t off_12BBD0;
extern uint32_t off_12BBD4;
extern uint32_t off_12BBCC;
extern uint32_t off_12BBD8;
extern uint32_t off_12BBDC;
extern uint32_t off_12BBE0;
extern uint32_t dword_12BBE4;
extern uint32_t off_12BBE8;
extern uint32_t off_12BBEC;

// mmio_reg_clear_bits_n3c @ 0x12bb4c, size 126 bytes
// Doc: mmio_reg_clear_bits_n3c [mmio]: Clear MMIO register bits with loop
// mmio_reg_clear_bits_n3c [mmio]: Clear MMIO register bits with loop
int *mmio_reg_clear_bits_n3c()
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

  v0 = off_12BBD0;
  v1 = off_12BBD4;
  *(uint32_t *)off_12BBCC &= ~0x80u;
  *v0 = 0;
  *v1 = 60;
  while ( *v0 << 28 )
    ;
  v2 = off_12BBD4;
  v3 = off_12BBD8;
  v4 = off_12BBDC;
  v5 = (int *)off_12BBE0;
  v6 = dword_12BBE4;
  *(uint32_t *)off_12BBD4 |= 0x10000u;
  *v3 &= 0xFFFFFF00;
  *v4 = -1;
  *v5 = v6;
  v7 = off_12BBE8;
  v8 = off_12BBEC;
  v2[8200] |= 0x80000000;
  v9 = v7[1];
  v4[1] |= 0x80000000;
  result = v5 - 8201;
  *v8 |= 0x80000000;
  *result |= 0x80u;
  v7[1] = v9 & 0xFFFFFFFB;
  return result;
}

