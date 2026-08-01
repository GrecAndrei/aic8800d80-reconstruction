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

// mmio_read_status @ 0x113b88, size 40 bytes
int  mmio_read_status(uint8_t *a1)
{
  int16_t v2; // r0

  v2 = mmio_read32(6u);
  if ( (v2 & 0xFF00) != 0 )
  {
    *a1 = HIBYTE(v2);
    return 0;
  }
  else
  {
    *a1 = v2;
    if ( (uint8_t)v2 )
      return 1;
    else
      return 2;
  }
}

