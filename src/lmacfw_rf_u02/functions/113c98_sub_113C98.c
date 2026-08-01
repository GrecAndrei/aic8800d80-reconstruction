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

// rf_status_check @ 0x113c98, size 104 bytes
int  rf_status_check(unsigned int a1, int a2)
{
  int v4; // r4
  unsigned int v5; // r4

  v4 = mmio_read32(7u);
  if ( (uint16_t)mmio_read32(8u) | v4 )
  {
    v5 = mmio_read32(8u);
    if ( (HIWORD(v5) << 16) | mmio_read32(9u) )
    {
      return -1;
    }
    else
    {
      mmio_write32(8u, a1 << 16);
      mmio_write32(9u, HIWORD(a1) | (a2 << 16));
      return 0;
    }
  }
  else
  {
    mmio_write32(7u, a1);
    mmio_write32(8u, a2);
    return 1;
  }
}

