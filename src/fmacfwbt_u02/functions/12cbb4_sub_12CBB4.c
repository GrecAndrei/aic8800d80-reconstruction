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

// hci_evt_send @ 0x12cbb4, size 106 bytes
// Doc: message_dispatch_n52_cc06 [ipc]: Dispatches an incoming IPC message by ID
// message_dispatch_n52_cc06 [ipc]: Dispatches an incoming IPC message by ID
int  hci_evt_send(int a1)
{
  int16_t v1; // r3
  uint16_t *v4; // r0

  v1 = *(uint16_t *)(a1 - 6);
  if ( **(int16_t **)message_dispatch_c20 >= 0 || (uint8_t)v1 <= 0xEu )
  {
    if ( (uint8_t)v1 <= 0xCu )
    {
      check_abort_flag(message_dispatch_n70);
      return set_system_flag_1(0x4000000);
    }
  }
  else
  {
    mmio_irq_clear(message_dispatch2_cc2c, message_dispatch_n74, 183);
  }
  ke_event_schedule(message_dispatch_n7c, *(uint16_t *)(a1 - 8), *(uint16_t *)(a1 - 4));
  v4 = (uint16_t *)(a1 - 12);
  if ( *(uint8_t *)message_dispatch_n80 )
    return hci_tx_packet(v4);
  else
    return patch_jump(v4);
}

