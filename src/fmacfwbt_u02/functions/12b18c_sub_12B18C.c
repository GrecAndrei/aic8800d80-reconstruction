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

extern uint32_t dword_12B218;
extern uint32_t off_12B21C;
extern uint32_t dword_12B228;
extern uint32_t dword_12B224;
extern uint32_t off_12B220;

// ke_timer_wait @ 0x12b18c, size 138 bytes
int ke_timer_wait()
{
  int v0; // r0
  int v1; // r2
  uint8_t *v2; // r4
  int v3; // r0
  unsigned int v4; // r2
  unsigned int v5; // r3
  int v6; // r1

  if ( hci_cmd_send_short(2) != 3 )
  {
    v0 = hci_cmd_send_short(2);
    ke_event_schedule(dword_12B218, v0, v1);
  }
  if ( **(int16_t **)off_12B21C < 0 && hci_cmd_send_short(2) != 3 )
    mmio_irq_clear(dword_12B228, dword_12B224, 201);
  v2 = off_12B220;
  v3 = *(uint32_t *)off_12B220;
  v4 = *(uint8_t *)(*(uint32_t *)off_12B220 + 367);
  v5 = (uint8_t)(*((uint8_t *)off_12B220 + 10) + 1);
  *((uint8_t *)off_12B220 + 10) = v5;
  if ( v4 <= v5 || v2[11] )
  {
    jump_to_tx_entry(v3 - 12);
    v6 = *((uint16_t *)v2 + 4);
    if ( v2[11] )
    {
      bt_send_hci_804(0, v6);
      v2[11] = 0;
    }
    else
    {
      hci_evt_alloc_send(2050, v6, 2, (uint8_t)v2[11]);
    }
    hci_cmd_send(2);
    return 0;
  }
  else
  {
    bt_get_link_state();
    return 0;
  }
}

