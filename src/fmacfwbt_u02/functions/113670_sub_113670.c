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


extern uint32_t dword_1136F0;
extern uint32_t dword_113704;
extern uint32_t off_1136EC;
extern uint32_t off_1136F4;
extern uint32_t off_1136FC;
extern uint32_t off_113700;
extern uint32_t off_11370C;

// bt_evt_sched_high @ 0x113670, size 124 bytes
uint32_t *bt_evt_sched_high()
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

  v0 = off_1136EC;
  result = zero_struct((uint32_t *)dword_1136F0);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 8) )
  {
    v2 = (int *)off_113700;
    v3 = off_1136F4;
    v4 = dword_113704;
    v5 = (uint16_t **)off_11370C;
    v6 = 0;
    do
    {
      v8 = rx_process_item(v4, (uint16_t)(*((uint16_t *)v2 + 153) - 4));
      if ( !v8 )
      {
        ke_event_schedule_1("usb_wlan_rx_pkt_free_list_init alloc fail: %d\n", v6);
        if ( **v5 < 0 )
          mmio_irq_clear(off_1136FC, (int)aUsbWlanRxPktFr_0, 495);
      }
      result = (uint32_t *)check_abort_flag(dword_1136F0, v8);
      v7 = *(uint16_t *)(*(uint32_t *)v0 + 8);
      ++v6;
      ++*v3;
    }
    while ( v7 > v6 );
  }
  return result;
}
