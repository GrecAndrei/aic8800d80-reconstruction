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

// radio_reg_config @ 0x137030, size 40 bytes
int radio_reg_config()
{
  int v0; // r0
  int v1; // r0

  v0 = tx_send_pdu(2051, 2, 4, 1);
  rx_process_packet_1(v0);
  v1 = hci_cmd_handler(4u);
  check_feature_flag(8, "scanu cancel:%d\r\n", v1);
  return 0;
}
