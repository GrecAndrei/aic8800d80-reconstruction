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

extern uint32_t off_1361AC;
extern uint32_t dword_1361B4;
extern uint32_t dword_1361B0;

// is_tx_enabled @ 0x136150, size 90 bytes
int is_tx_enabled()
{
  int v0; // r0

  if ( **(int16_t **)off_1361AC < 0 && hci_cmd_handler(7u) != 1 && hci_cmd_handler(7u) && hci_cmd_handler(7u) != 3 )
    irq_disable_mmio_write(dword_1361B4, dword_1361B0, 274);
  v0 = hci_cmd_handler(7u);
  if ( v0 != 1 )
  {
    v0 = hci_cmd_handler(7u);
    if ( v0 != 3 )
      return 0;
  }
  acquire_lock_check_state(v0);
  return 0;
}

