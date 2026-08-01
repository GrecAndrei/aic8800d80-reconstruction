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

extern uint32_t off_137014;
extern uint32_t dword_137018;

// rf_trace_channel2 @ 0x136fe4, size 48 bytes
int  rf_trace_channel2(int a1, uint8_t *a2)
{
  uint16_t *v2; // r5
  int v4; // r0

  v2 = (uint16_t *)off_137014;
  v4 = tx_send_pdu(4107, *((uint16_t *)off_137014 + 1924), 4, 1u);
  rx_process_packet(v4);
  check_feature_flag(8, dword_137018, v2[1924]);
  util_hex_convert(*a2);
  return 0;
}

