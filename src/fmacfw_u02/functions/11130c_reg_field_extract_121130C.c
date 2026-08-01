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

// read_random_from_mmio @ 0x11130c, size 124 bytes
// Doc: read_random_from_mmio [mmio]: Extracts a 22-bit field from a register with bit shift adjustment
// read_random_from_mmio [mmio]: Extracts a 22-bit field from a register with bit shift adjustment
int  read_random_from_mmio(int a1)
{
  int *v1; // r3
  int v2; // r2
  int v3; // r1
  int v4; // r1

  v1 = (int *)rf_bus_mark_n_4fc_1388;
  v2 = a1 & 0x3FFFFF;
  v3 = *(uint32_t *)rf_bus_mark_n_4fc_1388 & 0x3FFFFF;
  if ( (a1 & 0x400000) != 0 )
  {
    *(uint32_t *)rf_bus_mark_n_4fc_1388 = v3 | 0x800000;
    *v1 = v3;
    *v1 = v2;
    v4 = v2 | 0x800000;
  }
  else
  {
    *(uint32_t *)rf_bus_mark_n_4fc_1388 = v3 | 0x400000;
    v4 = v2 | 0x400000;
  }
  *v1 = v4;
  *v1 = v2 | 0xC00000;
  return log_printf(rf_bus_mark_n_4f8_138c, *(uint32_t *)rf_bus_mark_n_4fc_1388 & 0x3FFFFF);
}

