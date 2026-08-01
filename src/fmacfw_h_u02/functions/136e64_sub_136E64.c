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

extern uint32_t dword_136EA4;
extern uint32_t off_136EA8;

// rf_trace_rate_set2 @ 0x136e64, size 64 bytes
int  rf_trace_rate_set2(int a1, uint16_t *a2, int a3, int16_t a4)
{
  uint8_t *v5; // r4
  char *v6; // r0
  int v7; // r2

  v5 = (uint8_t *)tx_send_pdu(4104, a4, 4, 2u);
  check_feature_flag(8, dword_136EA4);
  v6 = (char *)off_136EA8;
  v7 = *a2;
  *(uint16_t *)off_136EA8 = v7;
  memcpy(v6 + 3, (char *)a2 + 3, v7);
  *v5 = 1;
  v5[1] = *((uint8_t *)a2 + 2);
  rx_process_packet((int)v5);
  return 0;
}

