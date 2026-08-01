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

// send_cmd_0x0b @ 0x122b64, size 40 bytes
// Doc: bt_hci_cmd_alloc_2b66 [bt]: Allocate and prepare HCI command buffer (opcode 0xb)
// bt_hci_cmd_alloc_2b66 [bt]: Allocate and prepare HCI command buffer (opcode 0xb)
int  send_cmd_0x0b(int a1, int a2, int a3, int a4)
{
  uint8_t *v5; // r4

  v5 = (uint8_t *)bt_buf_alloc(11, a4, a3, 3);
  *v5 = buffer_alloc(a2, v5 + 1, v5 + 2);
  hci_evt_send(v5);
  return 0;
}

