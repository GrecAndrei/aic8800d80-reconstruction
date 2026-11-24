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

// rf_execute_cmd @ 0x12b3a4, size 40 bytes
uint32_t * rf_execute_cmd(char a1, uint16_t a2)
{
  char *v3; // r4

  v3 = (char *)tx_send_pdu(2052, a2, 2, 1);
  check_feature_flag(4, "%s\r\n", aScanSendCancel);
  *v3 = a1;
  return rx_process_packet_1((int)v3);
}
