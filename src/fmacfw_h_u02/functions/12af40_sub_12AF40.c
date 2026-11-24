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


extern uint32_t off_12AFC4;
extern uint32_t off_12AFC8;

// send_vendor_command @ 0x12af40, size 124 bytes
int  send_vendor_command(int a1, int a2, uint16_t a3, uint16_t a4)
{
  uint8_t *v6; // r4
  int v7; // r0
  uint8_t *v8; // r2

  v6 = (uint8_t *)tx_send_pdu(2049, a4, a3, 1);
  v7 = hci_cmd_handler(2u);
  check_feature_flag(4, "%s:%d\r\n", aScanStartReqHa, v7);
  if ( hci_cmd_handler(2u) )
  {
    *v6 = 8;
    rx_process_packet_1((int)v6);
    return 0;
  }
  else
  {
    if ( **(uint16_t **)off_12AFC4 < 0 && !*(uint8_t *)(a2 + 367) )
      irq_disable_mmio_write((int)aParamChanCnt0, (int)aScanStartReqHa_0, 73);
    v8 = off_12AFC8;
    *v6 = 0;
    *(uint32_t *)v8 = a2;
    v8[10] = 0;
    *((uint16_t *)v8 + 4) = a4;
    log_trace_event(a2);
    rx_process_packet_1((int)v6);
    return 1;
  }
}
