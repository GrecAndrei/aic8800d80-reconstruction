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

extern uint32_t dword_136E40;

// rf_trace_rate_set @ 0x136e10, size 48 bytes
int  rf_trace_rate_set(int a1, int a2, int a3, int16_t a4)
{
  uint8_t *v5; // r4

  v5 = (uint8_t *)tx_send_pdu(4104, a4, 4, 2u);
  check_feature_flag(8, dword_136E40);
  *v5 = 1;
  v5[1] = *(uint8_t *)(a2 + 2);
  rx_process_packet((int)v5);
  return 0;
}

