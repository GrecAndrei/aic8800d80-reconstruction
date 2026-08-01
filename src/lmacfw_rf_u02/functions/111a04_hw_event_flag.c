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

// rf_read_status @ 0x111a04, size 32 bytes
// Doc: rf_bus_write2_n4f8 [rf]: Write to RF bus register with mode check
// rf_bus_write2_n4f8 [rf]: Write to RF bus register with mode check
int  rf_read_status(int a1)
{
  int result; // r0
  int v2; // r3

  result = 32 * a1 + 1075838976;
  v2 = *(uint32_t *)(result + 2816);
  if ( v2 < 0 )
    *(uint32_t *)(result + 2816) = v2 & 0x7BFFFFFF | 0x4000000;
  return result;
}

