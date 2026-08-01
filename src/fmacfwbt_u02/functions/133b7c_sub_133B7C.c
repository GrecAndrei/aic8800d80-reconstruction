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

extern uint32_t off_133BD8;
extern uint32_t dword_133BE0;
extern uint32_t dword_133BDC;

// scan_trigger @ 0x133b7c, size 90 bytes
int scan_trigger()
{
  int v0; // r0

  if ( **(int16_t **)off_133BD8 < 0 && hci_cmd_send_short(6u) != 4 && hci_cmd_send_short(6u) && hci_cmd_send_short(6u) != 10 )
    mmio_irq_clear(dword_133BE0, dword_133BDC, 636);
  v0 = hci_cmd_send_short(6u);
  if ( v0 != 4 )
  {
    v0 = hci_cmd_send_short(6u);
    if ( v0 != 10 )
      return 0;
  }
  check_hw_ready_status(v0);
  return 0;
}

