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

// sub_12D2D0 @ 0x12d2d0, size 22 bytes
uint32_t * sub_12D2D0(int a1)
{
  uint32_t *v1; // r3
  uint32_t *v2; // r2

  v1 = *(uint32_t **)a1;
  if ( *(uint32_t *)a1 )
  {
    v2 = *(uint32_t **)(a1 + 4);
    *(uint32_t *)a1 = *v1;
    if ( v2 == v1 )
      *(uint32_t *)(a1 + 4) = 0;
  }
  return v1;
}

