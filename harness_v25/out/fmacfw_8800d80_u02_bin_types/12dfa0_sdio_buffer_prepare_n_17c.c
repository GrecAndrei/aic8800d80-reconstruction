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

// sdio_buffer_prepare_n_17c @ 0x12dfa0, size 14 bytes
// Doc: sdio_buffer_prepare_n_17c [mmio]: Compute SDIO buffer pointer by combining two byte fields with bit-or and shift
// sdio_buffer_prepare_n_17c [mmio]: Compute SDIO buffer pointer by combining two byte fields with bit-or and shift
int  sdio_buffer_prepare_n_17c(int a1)
{
  return ((2 * *(uint8_t *)(a1 + 5)) | (*(uint8_t *)(a1 + 4) >> 7)) << 22;
}

