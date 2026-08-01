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

// send_hci_command_status @ 0x1227f0, size 40 bytes
int  send_hci_command_status(int a1, int a2, int a3, int a4)
{
  uint8_t *v5; // r4

  v5 = (uint8_t *)tx_send_pdu(11, a4, a3, 3);
  *v5 = ke_send_msg(a2, v5 + 1, v5 + 2);
  rx_process_packet(v5);
  return 0;
}

