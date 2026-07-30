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

extern uint32_t off_12B748;

// phy_chan_idx_calc @ 0x12b738, size 16 bytes
// Doc: phy_chan_idx_calc [rf]: compute channel index/offset from PHY state struct
// phy_chan_idx_calc [rf]: compute channel index/offset from PHY state struct
int phy_chan_idx_calc()
{
  return *(uint32_t *)off_12B748 + 6 * *((uint8_t *)off_12B748 + 10);
}

