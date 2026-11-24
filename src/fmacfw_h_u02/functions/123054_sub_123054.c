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


extern uint32_t dword_12308C;

// ke_send_msg_85 @ 0x123054, size 56 bytes
int  ke_send_msg_85(int a1, int a2, uint16_t a3, uint16_t a4)
{
  uint8_t *v4; // r4
  unsigned int v5; // r0
  int v6; // r3

  v4 = (uint8_t *)tx_send_pdu(133, a4, a3, 1);
  v5 = mmio_read32_1(dword_12308C, 1);
  v6 = (BYTE2(v5) ^ 1) & 1;
  *v4 = v6;
  alloc_tx_event("read reg =%x, wifi disable regbit = %d, cfm->wifi_disable=%d\n", v5, HIWORD(v5) & 1, v6);
  rx_process_packet_1((int)v4);
  return 0;
}
