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


extern uint32_t dword_113754;
extern uint32_t dword_113768;
extern uint32_t off_113750;
extern uint32_t off_113758;
extern uint32_t off_113760;
extern uint32_t off_113764;
extern uint32_t off_113770;

// rf_read_status_1 @ 0x1136d4, size 124 bytes
uint32_t *rf_read_status_1()
{
  void *v0; // r7
  uint32_t *result; // r0
  int *v2; // r9
  uint16_t *v3; // r6
  int v4; // r8
  uint16_t **v5; // r10
  uint16_t v6; // r5
  unsigned int v7; // r1
  uint32_t *v8; // r4

  v0 = off_113750;
  result = clear_stats_buf((uint32_t *)dword_113754);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 8) )
  {
    v2 = (int *)off_113764;
    v3 = off_113758;
    v4 = dword_113768;
    v5 = (uint16_t **)off_113770;
    v6 = 0;
    do
    {
      v8 = tx_irq_handler(v4, (uint16_t)(*((uint16_t *)v2 + 153) - 4));
      if ( !v8 )
      {
        alloc_tx_event("usb_wlan_rx_pkt_free_list_init alloc fail: %d\n", v6);
        if ( **v5 < 0 )
          irq_disable_mmio_write(off_113760, (int)aUsbWlanRxPktFr_0, 495);
      }
      result = (uint32_t *)wlan_ioctl_handler_1(dword_113754, v8);
      v7 = *(uint16_t *)(*(uint32_t *)v0 + 8);
      ++v6;
      ++*v3;
    }
    while ( v7 > v6 );
  }
  return result;
}
