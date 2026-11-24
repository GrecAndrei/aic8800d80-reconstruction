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


extern uint32_t dword_11314C;
extern uint32_t dword_113160;
extern uint32_t off_113148;
extern uint32_t off_113150;
extern uint32_t off_113158;
extern uint32_t off_11315C;
extern uint32_t off_113168;

// timer_event_handler @ 0x1130cc, size 124 bytes
uint32_t *timer_event_handler()
{
  void *v0; // r7
  uint32_t *result; // r0
  int v2; // r9
  uint16_t *v3; // r6
  int v4; // r8
  uint16_t **v5; // r10
  uint16_t v6; // r5
  unsigned int v7; // r1
  uint32_t *v8; // r4

  v0 = off_113148;
  result = list_init_1((uint32_t *)dword_11314C);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 8) )
  {
    v2 = off_11315C[0];
    v3 = off_113150;
    v4 = dword_113160;
    v5 = (uint16_t **)off_113168;
    v6 = 0;
    do
    {
      v8 = list_iterate(v4, (uint16_t)(*(uint16_t *)(v2 + 0x132) - 4));
      if ( !v8 )
      {
        dispatch_event_handler_1("usb_wlan_rx_pkt_free_list_init alloc fail: %d\n", v6);
        if ( **v5 < 0 )
          flash_ctrl_init(off_113158, (int)aUsbWlanRxPktFr_0, 495);
      }
      result = (uint32_t *)check_kernel_state(dword_11314C, v8);
      v7 = *(uint16_t *)(*(uint32_t *)v0 + 8);
      ++v6;
      ++*v3;
    }
    while ( v7 > v6 );
  }
  return result;
}
