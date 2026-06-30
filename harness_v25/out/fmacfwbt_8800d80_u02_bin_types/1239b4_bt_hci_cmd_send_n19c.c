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

// bt_hci_cmd_send_n19c @ 0x1239b4, size 32 bytes
// Doc: bt_hci_cmd_send_n19c [bt]: Send BT HCI command opcode 0x0d
// bt_hci_cmd_send_n19c [bt]: Send BT HCI command opcode 0x0d
int  bt_hci_cmd_send_n19c(int a1, uint8_t *a2, int a3, int a4)
{
  int v4; // r3

  rf_chan_param_lookup_n1f0(*a2);
  message_dispatch_n84(13, a4, a3, v4);
  return 0;
}

