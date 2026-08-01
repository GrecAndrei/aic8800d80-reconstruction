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

// mac_hash_calc @ 0x12dfb0, size 30 bytes
// Doc: sdio_buf_align_or_mask [mac]: Align SDIO buffer address and check magic constant 0xfac12
// sdio_buf_align_or_mask [mac]: Align SDIO buffer address and check magic constant 0xfac12
int  mac_hash_calc(int a1, int16_t a2)
{
  return rf_bus_reset_n_32
       & ((((32 * (*(uint8_t *)(a1 + 5) ^ (*(uint8_t *)(a1 + 5) >> 4))) & 0x1E0) + (a2 & 0x1FF)) << 22)
       | 0x3F0000;
}

