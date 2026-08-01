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

// rf_read_reg @ 0x121ed4, size 30 bytes
int  rf_read_reg(int a1)
{
  uint8_t *v2; // r0

  v2 = (uint8_t *)tx_send_pdu(67, 6, 0, 1);
  *v2 = *(uint8_t *)(a1 + 107);
  return rx_process_packet(v2);
}

