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

// bt_hci_cmd_send_n18c @ 0x12b18c, size 138 bytes
// Doc: bt_hci_cmd_send_n18c [bt]: Sends HCI command (opcode 2) via bluetooth mailbox interface
// bt_hci_cmd_send_n18c [bt]: Sends HCI command (opcode 2) via bluetooth mailbox interface
int bt_hci_cmd_send_n18c()
{
  int value; // r0
  int v1; // r2
  uint8_t *v2; // r4
  int v3; // r0
  unsigned int v4; // r2
  unsigned int v5; // r3
  int v6; // r1

  if ( msg_get_value(2) != 3 )
  {
    value = msg_get_value(2);
    sub_12ECB0(dword_12B218, value, v1);
  }
  if ( **(int16_t **)off_12B21C < 0 && msg_get_value(2) != 3 )
    sub_12F694(dword_12B228, dword_12B224, 201);
  v2 = off_12B220;
  v3 = *(uint32_t *)off_12B220;
  v4 = *(uint8_t *)(*(uint32_t *)off_12B220 + 367);
  v5 = (uint8_t)(*((uint8_t *)off_12B220 + 10) + 1);
  *((uint8_t *)off_12B220 + 10) = v5;
  if ( v4 <= v5 || v2[11] )
  {
    j_buffer_pool_get(v3 - 12);
    v6 = *((uint16_t *)v2 + 4);
    if ( v2[11] )
    {
      sub_12B708(0, v6);
      v2[11] = 0;
    }
    else
    {
      message_dispatch_n84(2050, v6, 2, (uint8_t)v2[11]);
    }
    rf_bus_mark_n_3b7(2);
    return 0;
  }
  else
  {
    sub_12B3C8();
    return 0;
  }
}

