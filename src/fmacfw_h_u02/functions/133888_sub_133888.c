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

extern uint32_t off_1338BC;
extern uint32_t dword_1338C4;
extern uint32_t dword_1338C0;

// ble_state_check_133888 @ 0x133888, size 52 bytes
int  ble_state_check_133888(int a1)
{
  int v2; // r0

  if ( **(int16_t **)off_1338BC >= 0 || (a1 = hci_cmd_handler(6u), a1 == 4) )
  {
    ble_reset_controller(a1);
    return 0;
  }
  else
  {
    v2 = irq_disable_mmio_write(dword_1338C4, dword_1338C0, 670);
    ble_reset_controller(v2);
    return 0;
  }
}

