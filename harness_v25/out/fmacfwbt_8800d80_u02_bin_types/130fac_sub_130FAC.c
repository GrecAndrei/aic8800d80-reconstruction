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

// sub_130FAC @ 0x130fac, size 38 bytes
int  sub_130FAC(int a1, int a2, int16_t a3)
{
  int16_t v3; // r3
  int v4; // r1
  int16_t v5; // r3

  *(uint8_t *)a1 = 3;
  *(uint8_t *)(a1 + 1) = 2;
  v3 = *(uint8_t *)(a2 + 22);
  v4 = *(uint8_t *)(a2 + 17);
  *(uint16_t *)(a1 + 4) = a3;
  v5 = v3 << 12;
  if ( v4 == 1 )
    v5 |= 0x800u;
  *(uint16_t *)(a1 + 2) = v5;
  return 6;
}

