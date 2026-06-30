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

// rf_bus_reset_nac_baa8 @ 0x13baa8, size 22 bytes
// Doc: rf_bus_reset_nac_baa8 [rf]: Reset RF bus control registers (0x40200900 region)
// rf_bus_reset_nac_baa8 [rf]: Reset RF bus control registers (0x40200900 region)
int  rf_bus_reset_nac_baa8(int16_t a1)
{
  return rf_level_apply_80c(8194, (uint16_t)(a1 << 8) | 8, 0x1F4000u);
}

