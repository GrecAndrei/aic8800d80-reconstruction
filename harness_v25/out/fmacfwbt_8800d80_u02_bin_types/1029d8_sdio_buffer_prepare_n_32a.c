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

extern uint32_t off_1029F4;

// sdio_buffer_prepare_n_32a @ 0x1029d8, size 26 bytes
// Doc: sdio_buffer_prepare_n_32a [util]: Validate/prepare SDIO buffer length against limit
// sdio_buffer_prepare_n_32a [util]: Validate/prepare SDIO buffer length against limit
int sdio_buffer_prepare_n_32a()
{
  return (uint8_t)((1 << ((uint8_t)*(uint32_t *)off_1029F4 >> 4)) - 1);
}

