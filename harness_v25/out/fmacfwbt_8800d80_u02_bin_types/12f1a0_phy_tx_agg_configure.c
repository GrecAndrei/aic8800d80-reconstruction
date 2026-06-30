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

extern uint32_t dword_12F1CC;
extern uint32_t off_12F1D0;

// phy_tx_agg_configure @ 0x12f1a0, size 42 bytes
// Doc: phy_tx_agg_configure [tx]: Configure TX aggregation via sub_12ECB0
// phy_tx_agg_configure [tx]: Configure TX aggregation via sub_12ECB0
int  phy_tx_agg_configure(int a1, uint32_t *a2, int16_t a3, int16_t a4)
{
  sub_12ECB0(dword_12F1CC, *a2);
  *((uint32_t *)off_12F1D0 + 1) = *a2;
  message_dispatch_n84(1031, a4, a3);
  return 0;
}

