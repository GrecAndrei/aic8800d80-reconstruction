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

// sub_1312B0 @ 0x1312b0, size 38 bytes
uint8_t * sub_1312B0(uint8_t *a1, int a2, uint8_t *a3)
{
  uint8_t *result; // r0
  unsigned int v5; // r3

  result = sdio_buffer_prepare_n_19c(a1, a2);
  if ( result )
  {
    v5 = result[3];
    *a3 = v5 & 7;
    a3[1] = (v5 >> 3) & 7;
    return (uint8_t *)1;
  }
  else
  {
    *a3 = 3;
    a3[1] = 5;
  }
  return result;
}

