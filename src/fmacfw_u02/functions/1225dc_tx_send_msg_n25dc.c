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

// hci_send_cmd_0x59 @ 0x1225dc, size 30 bytes
// Doc: hci_send_cmd_0x59 [tx]: Send TX/datapath message (id 0x59, param 0xd) via IPC
// hci_send_cmd_0x59 [tx]: Send TX/datapath message (id 0x59, param 0xd) via IPC
int  hci_send_cmd_0x59(char a1, char a2)
{
  uint8_t *v4; // r0

  v4 = (uint8_t *)ke_msg_alloc(89, 13, 0, 2);
  *v4 = a1;
  v4[1] = a2;
  return ke_msg_send(v4);
}

