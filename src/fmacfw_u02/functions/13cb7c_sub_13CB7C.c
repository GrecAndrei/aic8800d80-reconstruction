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

extern uint32_t dword_13CBE8;

// sub_13CB7C @ 0x13cb7c, size 108 bytes
unsigned int * sub_13CB7C(unsigned int *result)
{
  uint64_t v1; // r2
  int v2; // r1
  unsigned int v3; // r5
  unsigned int v4; // r7
  unsigned int v5; // r1

  v1 = *(uint64_t *)(result + 1);
  v2 = dword_13CBE8;
  v3 = *result;
  v4 = result[3];
  *result = dword_13CBE8 & (*result >> 15) | ((uint32_t)v1 << 17) & 0x1000000 | (2 * *result) & 0xFEFEFEFE;
  LODWORD(v1) = (2 * v1) & 0xFEFEFEFE | v2 & ((unsigned int)v1 >> 15) | (HIDWORD(v1) << 17) & 0x1000000;
  HIDWORD(v1) = (2 * HIDWORD(v1)) & 0xFEFEFEFE | v2 & (HIDWORD(v1) >> 15) | (v4 << 17) & 0x1000000;
  v5 = v2 & (v4 >> 15) | (2 * v4) & 0xFEFEFEFE;
  *(uint64_t *)(result + 1) = v1;
  if ( (v3 & 0x80) != 0 )
    v5 ^= 0x87000000;
  result[3] = v5;
  return result;
}

