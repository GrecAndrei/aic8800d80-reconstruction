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

extern uint32_t off_12BC9C;
extern uint32_t off_12BCA0;
extern uint32_t off_12BCA4;
extern uint32_t off_12BCA8;
extern uint32_t dword_12BCAC;
extern uint32_t off_12BCB4;
extern uint32_t dword_12BCBC;
extern uint32_t dword_12BCB8;
extern uint32_t off_12BCB0;

// sub_12BC2C @ 0x12bc2c, size 110 bytes
unsigned int sub_12BC2C()
{
  uint32_t *v0; // r2
  uint32_t *v1; // r0
  int16_t **v2; // r5
  int *v3; // r4
  int v4; // r3
  int16_t *v5; // r2
  unsigned int result; // r0
  uint32_t *v7; // r2

  v0 = off_12BC9C;
  v1 = off_12BCA0;
  *(uint32_t *)off_12BC9C &= ~1u;
  v2 = (int16_t **)off_12BCA4;
  v3 = (int *)off_12BCA8;
  v4 = dword_12BCAC;
  *v0 &= ~2u;
  *v1 |= 0x700u;
  v5 = *v2;
  *v3 = v4;
  if ( *v5 < 0 && *(uint32_t *)off_12BCB4 << 28 )
  {
    sub_12F49C(dword_12BCBC, dword_12BCB8, 472);
    v4 = *v3;
  }
  *(uint32_t *)off_12BCB0 = v4 | v3[1];
  result = mmio_reg_bit_modify(1);
  v7 = off_12BCA0;
  *(uint32_t *)off_12BCA0 = *(uint32_t *)off_12BCA0 & 0xFFFE3FFF | 0x10000;
  *v7 |= 0x2000u;
  return result;
}

