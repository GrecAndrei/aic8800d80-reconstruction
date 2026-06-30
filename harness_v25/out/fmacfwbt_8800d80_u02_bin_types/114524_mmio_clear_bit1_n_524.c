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

extern uint32_t off_114534;

// mmio_clear_bit1_n_524 @ 0x114524, size 14 bytes
// Doc: mmio_clear_bit1_n_524 [mmio]: Clears bit 1 in MMIO register at offset 8
// mmio_clear_bit1_n_524 [mmio]: Clears bit 1 in MMIO register at offset 8
void mmio_clear_bit1_n_524()
{
  *(uint32_t *)(*(uint32_t *)off_114534 + 8) &= ~2u;
}

