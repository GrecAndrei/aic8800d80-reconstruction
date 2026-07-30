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

// rf_bus_mark_n100_d2d0 @ 0x12d2d0, size 22 bytes
// Doc: rf_bus_mark_n100_d2d0 [rf]: Marks a tagged slot on the RF shared bus structure
// rf_bus_mark_n100_d2d0 [rf]: Marks a tagged slot on the RF shared bus structure
uint32_t * rf_bus_mark_n100_d2d0(int a1)
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

