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

extern uint32_t off_1364F8;
extern uint32_t dword_136500;
extern uint32_t dword_1364FC;

// tx_schedule_radio_task @ 0x13649c, size 90 bytes
// Doc: tx_schedule_radio_task [rf]: Poll signed halfword RF sub-state and branch
// tx_schedule_radio_task [rf]: Poll signed halfword RF sub-state and branch
int tx_schedule_radio_task()
{
  int value; // r0

  if ( **(int16_t **)off_1364F8 < 0 && hci_cmd_send_short(7u) != 1 && hci_cmd_send_short(7u) && hci_cmd_send_short(7u) != 3 )
    mmio_irq_clear(dword_136500, dword_1364FC, 274);
  value = hci_cmd_send_short(7u);
  if ( value != 1 )
  {
    value = hci_cmd_send_short(7u);
    if ( value != 3 )
      return 0;
  }
  txpwr_get_state(value);
  return 0;
}

