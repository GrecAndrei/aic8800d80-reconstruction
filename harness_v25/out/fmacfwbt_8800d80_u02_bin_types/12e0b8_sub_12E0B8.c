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

// sub_12E0B8 @ 0x12e0b8, size 40 bytes
// Doc: sdio_buffer_prepare_280 [mmio]: Prepares SDIO buffer state via internal helper
// sdio_buffer_prepare_280 [mmio]: Prepares SDIO buffer state via internal helper
uint8_t * sub_12E0B8(uint8_t *a1, int a2, uint8_t *a3)
{
  uint8_t *result; // r0
  uint16_t v5; // [sp+6h] [bp-2h] BYREF

  result = sub_12DA54(a1, a2, 35, &v5);
  if ( result )
  {
    if ( (unsigned int)v5 - 24 > 0x21 )
      return 0;
    else
      *a3 = v5 - 3;
  }
  return result;
}

