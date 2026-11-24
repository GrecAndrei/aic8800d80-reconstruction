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


extern uint32_t off_12B290;
extern uint32_t off_12B298;

// bt_link_connected @ 0x12b22c, size 98 bytes
int bt_link_connected()
{
  int v0; // r5
  int v1; // r4
  int v2; // r0

  v0 = *(uint32_t *)off_12B290;
  v1 = *((uint8_t *)off_12B290 + 10);
  if ( hci_cmd_send_short(2u) != 2 )
  {
    v2 = hci_cmd_send_short(2u);
    ke_event_schedule_1("start st=%d\n", v2);
  }
  if ( **(uint16_t **)off_12B298 < 0 && hci_cmd_send_short(2u) != 2 )
    mmio_irq_clear((int)aKeStateGetTask_3, (int)aMmScanChannelS, 163);
  if ( (*(uint8_t *)(v0 + 6 * v1 + 3) & 1) == 0 )
    bt_update_conn_state();
  hci_cmd_send(2u, 3);
  return 0;
}
