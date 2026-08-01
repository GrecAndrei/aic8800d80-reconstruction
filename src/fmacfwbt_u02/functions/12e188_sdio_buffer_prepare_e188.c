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

// parse_amp_u16 @ 0x12e188, size 32 bytes
// Doc: sdio_buffer_prepare_n_1a2 [tx]: Prepare SDIO buffer descriptor
// sdio_buffer_prepare_n_1a2 [tx]: Prepare SDIO buffer descriptor
uint8_t * parse_amp_u16(uint8_t *a1, int a2)
{
  uint8_t *result; // r0
  uint16_t v3[3]; // [sp+6h] [bp-6h] BYREF

  result = memcpy_loop(a1, a2, 38, v3);
  if ( result )
  {
    if ( v3[0] != 16 )
      return 0;
  }
  return result;
}

