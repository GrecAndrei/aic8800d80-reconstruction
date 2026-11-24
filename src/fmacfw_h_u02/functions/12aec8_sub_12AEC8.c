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


extern uint32_t off_12AF2C;
extern uint32_t off_12AF34;

// is_phy_ready @ 0x12aec8, size 98 bytes
int is_phy_ready()
{
  int v0; // r5
  int v1; // r4
  int v2; // r0

  v0 = *(uint32_t *)off_12AF2C;
  v1 = *((uint8_t *)off_12AF2C + 10);
  if ( hci_cmd_handler(2u) != 2 )
  {
    v2 = hci_cmd_handler(2u);
    alloc_tx_event("start st=%d\n", v2);
  }
  if ( **(uint16_t **)off_12AF34 < 0 && hci_cmd_handler(2u) != 2 )
    irq_disable_mmio_write((int)aKeStateGetTask_3, (int)aMmScanChannelS, 163);
  if ( (*(uint8_t *)(v0 + 6 * v1 + 3) & 1) == 0 )
    get_fw_info();
  hci_cmd_preprocess(2u, 3);
  return 0;
}
