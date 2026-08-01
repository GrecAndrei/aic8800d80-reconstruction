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

// hci_send_cmd_0x0b @ 0x122930, size 40 bytes
// Doc: sub_1222932 [unknown]: unknown behavioral stub function
// sub_1222932 [unknown]: unknown behavioral stub function
int  hci_send_cmd_0x0b(int a1, int a2, int a3, int a4)
{
  uint8_t *v5; // r4

  v5 = (uint8_t *)ke_msg_alloc(11, a4, a3, 3);
  *v5 = call_fw_handler(a2, v5 + 1, v5 + 2);
  ke_msg_send(v5);
  return 0;
}

