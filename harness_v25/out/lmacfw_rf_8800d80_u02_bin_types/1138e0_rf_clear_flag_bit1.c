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

extern uint32_t off_1138F0;

// rf_clear_flag_bit1 @ 0x1138e0, size 14 bytes
// Doc: rf_clear_flag_bit1 [mmio]: Clears bit 1 in shared mmio control register (bic r3, r3, 2)
// rf_clear_flag_bit1 [mmio]: Clears bit 1 in shared mmio control register (bic r3, r3, 2)
void rf_clear_flag_bit1()
{
  *(uint32_t *)(*(uint32_t *)off_1138F0 + 8) &= ~2u;
}

