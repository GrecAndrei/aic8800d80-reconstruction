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

// hci_send_cmd_0x68 @ 0x122b18, size 14 bytes
// Doc: sub_1222B18 [util]: Calls helper with 0x68 opcode/arg and returns 0
// sub_1222B18 [util]: Calls helper with 0x68 opcode/arg and returns 0
int  hci_send_cmd_0x68(int a1, int a2, int a3, int a4)
{
  ke_msg_send_no_param(104, a4, a3);
  return 0;
}

