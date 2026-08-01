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

extern uint32_t off_133A0C;
extern uint32_t dword_133A14;
extern uint32_t dword_133A10;

// bt_poll_controller @ 0x1339d8, size 52 bytes
int  bt_poll_controller(int value)
{
  int v2; // r0

  if ( **(int16_t **)off_133A0C >= 0 || (value = hci_cmd_send_short(6u), value == 10) )
  {
    check_fw_ready(value);
    return 0;
  }
  else
  {
    v2 = mmio_irq_clear(dword_133A14, dword_133A10, 1038);
    check_fw_ready(v2);
    return 0;
  }
}

