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

// check_one_12dd08 @ 0x12dd08, size 64 bytes
// Doc: sdio_buffer_prepare_dd16 [mmio]: Prepare SDIO DMA buffer for transfer
// sdio_buffer_prepare_dd16 [mmio]: Prepare SDIO DMA buffer for transfer
uint8_t * check_one_12dd08(uint8_t *result, int a2)
{
  unsigned int v2; // r1
  uint8_t *v3; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    v3 = &result[(uint8_t)result[1] + 2];
    if ( *result == 45 )
      break;
    result += (uint8_t)result[1] + 2;
    if ( v2 <= (unsigned int)(v3 + 1) )
      return 0;
  }
  if ( v2 < (unsigned int)v3 )
    return 0;
  if ( result )
  {
    if ( result[1] != 26 )
      return 0;
  }
  return result;
}

