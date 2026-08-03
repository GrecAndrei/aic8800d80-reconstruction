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

// sub_130F1C @ 0x130f1c, size 162 bytes
uint8_t * sub_130F1C(uint8_t *a1, int a2, int a3, uint8_t *a4)
{
  uint8_t *result; // r0
  uint8_t v7; // r2
  unsigned int v8; // r1
  unsigned int v9; // r5
  uint64_t v10; // r2

  result = sub_12DBA0(a1, a2);
  *a4 = 0;
  if ( result )
  {
    v7 = result[8];
    if ( *(uint8_t *)(a3 + 18) != (v7 & 0xF) )
    {
      *a4 = 1;
      *(uint8_t *)(a3 + 16) = v7;
      *(uint8_t *)(a3 + 18) = v7 & 0xF;
      v8 = *(uint32_t *)(result + 14);
      v9 = *(uint32_t *)(result + 10);
      HIDWORD(v10) = *(uint32_t *)(result + 22) & 0xF | (16 * (*(uint32_t *)(result + 22) >> 8));
      LODWORD(v10) = *(uint32_t *)(result + 18) & 0xF | (16 * (*(uint32_t *)(result + 18) >> 8));
      *(uint8_t *)(a3 + 17) = ((v8 & 0x10) != 0)
                          | (*(uint32_t *)(result + 18) >> 2) & 4
                          | (*(uint32_t *)(result + 22) >> 1) & 8
                          | (v9 >> 3) & 2;
      *(uint32_t *)a3 = v8 & 0xF | (16 * (v8 >> 8));
      *(uint32_t *)(a3 + 4) = v9 & 0xF | (16 * (v9 >> 8));
      *(uint64_t *)(a3 + 8) = v10;
    }
    return (uint8_t *)1;
  }
  else
  {
    *(uint32_t *)a3 = 2627;
    *(uint32_t *)(a3 + 4) = 2627;
    *(uint32_t *)(a3 + 8) = 2627;
    *(uint32_t *)(a3 + 12) = 2627;
  }
  return result;
}

