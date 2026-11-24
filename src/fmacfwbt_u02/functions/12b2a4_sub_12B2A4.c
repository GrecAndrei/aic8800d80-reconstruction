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


extern uint32_t off_12B328;
extern uint32_t off_12B32C;

// bt_send_hci_801 @ 0x12b2a4, size 124 bytes
int  bt_send_hci_801(int a1, int a2, uint16_t a3, uint16_t a4)
{
  uint8_t *v6; // r4
  int v7; // r0
  uint8_t *v8; // r2

  v6 = (uint8_t *)bt_buf_alloc(2049, a4, a3, 1);
  v7 = hci_cmd_send_short(2u);
  state_check_feature(4, "%s:%d\r\n", aScanStartReqHa, v7);
  if ( hci_cmd_send_short(2u) )
  {
    *v6 = 8;
    hci_evt_send((int)v6);
    return 0;
  }
  else
  {
    if ( **(uint16_t **)off_12B328 < 0 && !*(uint8_t *)(a2 + 367) )
      mmio_irq_clear((int)aParamChanCnt0, (int)aScanStartReqHa_0, 73);
    v8 = off_12B32C;
    *v6 = 0;
    *(uint32_t *)v8 = a2;
    v8[10] = 0;
    *((uint16_t *)v8 + 4) = a4;
    bt_save_conn_info(a2);
    hci_evt_send((int)v6);
    return 1;
  }
}
