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


extern uint32_t off_12B21C;
extern uint32_t off_12B220;

// ke_timer_wait @ 0x12b18c, size 138 bytes
int ke_timer_wait()
{
  int v0; // r0
  uint8_t *v1; // r4
  int v2; // r0
  unsigned int v3; // r2
  unsigned int v4; // r3
  int v5; // r1

  if ( hci_cmd_send_short(2u) != 3 )
  {
    v0 = hci_cmd_send_short(2u);
    ke_event_schedule_1("end st=%d\n", v0);
  }
  if ( **(uint16_t **)off_12B21C < 0 && hci_cmd_send_short(2u) != 3 )
    mmio_irq_clear((int)aKeStateGetTask_2, (int)aMmScanChannelE, 201);
  v1 = off_12B220;
  v2 = *(uint32_t *)off_12B220;
  v3 = *(uint8_t *)(*(uint32_t *)off_12B220 + 367);
  v4 = (uint8_t)(*((uint8_t *)off_12B220 + 10) + 1);
  *((uint8_t *)off_12B220 + 10) = v4;
  if ( v3 <= v4 || v1[11] )
  {
    jump_to_tx_entry((char *)(v2 - 12));
    v5 = *((uint16_t *)v1 + 4);
    if ( v1[11] )
    {
      bt_send_hci_804(0, v5);
      v1[11] = 0;
    }
    else
    {
      hci_evt_alloc_send(2050, v5, 2);
    }
    hci_cmd_send(2u, 0);
    return 0;
  }
  else
  {
    bt_get_link_state();
    return 0;
  }
}
