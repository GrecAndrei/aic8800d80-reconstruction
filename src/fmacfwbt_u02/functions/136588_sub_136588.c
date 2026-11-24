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


extern uint32_t off_136614;
extern uint32_t off_136618;

// tx_schedule_radio_task_alt @ 0x136588, size 140 bytes
int tx_schedule_radio_task_alt()
{
  uint16_t **v0; // r4

  v0 = (uint16_t **)off_136614;
  if ( **(uint16_t **)off_136614 < 0 && hci_cmd_send_short(7u) != 1 && hci_cmd_send_short(7u) && hci_cmd_send_short(7u) != 3 )
    mmio_irq_clear((int)aKeStateGetTask_14, (int)aMeSetActiveCfm_0, 341);
  if ( hci_cmd_send_short(7u) == 1 )
  {
    if ( **v0 < 0 && *((uint32_t *)off_136618 + 1) )
      mmio_irq_clear((int)aCoListIsEmptyA, (int)aMeSetActiveCfm_0, 349);
    rf_core_enable();
  }
  else if ( hci_cmd_send_short(7u) == 3 )
  {
    hci_evt_alloc_send(7171, 13, 7);
    hci_cmd_send(7u, 0);
  }
  return 0;
}
