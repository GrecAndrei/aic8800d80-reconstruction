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

// sub_130A20 @ 0x130a20, size 52 bytes
// Doc: sub_1230A20 [util]: Store packed halfword values into buffer
// sub_1230A20 [util]: Store packed halfword values into buffer
int  sub_130A20(int a1, int16_t a2, int16_t a3, int16_t a4, char *a5)
{
  char *v5; // r2
  uint8_t *v6; // r3
  char v7; // t1

  *(uint16_t *)a1 = a2;
  *(uint16_t *)(a1 + 2) = a3;
  *(uint16_t *)(a1 + 4) = a4;
  if ( !a5 )
    return 6;
  *(uint8_t *)(a1 + 6) = 16;
  *(uint8_t *)(a1 + 7) = 0x80;
  v5 = a5;
  do
  {
    v6 = v5 + 8;
    v7 = *v5++;
    *(uint8_t *)(v6 - a5 + a1) = v7;
  }
  while ( v5 != a5 + 128 );
  return 136;
}

