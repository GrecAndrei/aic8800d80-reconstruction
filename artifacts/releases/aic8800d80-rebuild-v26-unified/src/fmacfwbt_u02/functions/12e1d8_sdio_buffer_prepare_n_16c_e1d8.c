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

// sdio_buffer_prepare_n_16c_e1d8 @ 0x12e1d8, size 30 bytes
// Doc: sdio_buffer_prepare_n_16c_e1d8 [mmio]: Prepare SDIO transfer buffer address with channel offset
// sdio_buffer_prepare_n_16c_e1d8 [mmio]: Prepare SDIO transfer buffer address with channel offset
int  sdio_buffer_prepare_n_16c_e1d8(int a1, int16_t a2)
{
  return sdio_buffer_prepare_n_14c
       & ((((32 * (*(uint8_t *)(a1 + 5) ^ (*(uint8_t *)(a1 + 5) >> 4))) & 0x1E0) + (a2 & 0x1FF)) << 22)
       | 0x3F0000;
}

