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

extern uint32_t off_1018D0;

// sdio_buffer_prepare_n_2e2 @ 0x1018c4, size 10 bytes
// Doc: sdio_buffer_prepare_n_2e2 [mac]: SDIO buffer prepare trampoline returning arg2
// sdio_buffer_prepare_n_2e2 [mac]: SDIO buffer prepare trampoline returning arg2
int sdio_buffer_prepare_n_2e2()
{
  return (*(uint32_t *)off_1018D0 >> 28) & 1;
}

