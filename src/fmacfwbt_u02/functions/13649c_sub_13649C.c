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
int tx_schedule_radio_task()
{
  int v0; // r0

  if ( **(int16_t **)off_1364F8 < 0 && hci_cmd_send_short(7u) != 1 && hci_cmd_send_short(7u) && hci_cmd_send_short(7u) != 3 )
    mmio_irq_clear(dword_136500, dword_1364FC, 274);
  v0 = hci_cmd_send_short(7u);
  if ( v0 != 1 )
  {
    v0 = hci_cmd_send_short(7u);
    if ( v0 != 3 )
      return 0;
  }
  txpwr_get_state(v0);
  return 0;
}

