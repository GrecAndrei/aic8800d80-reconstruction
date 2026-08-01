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

extern uint32_t off_136E08;
extern uint32_t dword_136E0C;

// rf_trace_channel @ 0x136de0, size 40 bytes
int rf_trace_channel()
{
  uint16_t *v0; // r4
  int v1; // r0

  v0 = (uint16_t *)off_136E08;
  v1 = tx_send_pdu(4107, *((uint16_t *)off_136E08 + 1924), 4, 1u);
  rx_process_packet(v1);
  check_feature_flag(8, dword_136E0C, v0[1924]);
  return 0;
}

