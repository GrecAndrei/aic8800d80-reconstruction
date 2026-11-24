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


extern uint32_t dword_113894;
extern uint32_t dword_1138A8;
extern uint32_t off_113890;
extern uint32_t off_113898;
extern uint32_t off_1138A0;
extern uint32_t off_1138A4;
extern uint32_t off_1138B0;

// ke_state_get @ 0x113814, size 124 bytes
uint32_t *ke_state_get()
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

  v0 = off_113890;
  result = zero_8_bytes((uint32_t *)dword_113894);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 8) )
  {
    v2 = (int *)off_1138A4;
    v3 = off_113898;
    v4 = dword_1138A8;
    v5 = (uint16_t **)off_1138B0;
    v6 = 0;
    do
    {
      v8 = rx_packet_handler_1(v4, (uint16_t)(*((uint16_t *)v2 + 153) - 4));
      if ( !v8 )
      {
        event_dispatch("usb_wlan_rx_pkt_free_list_init alloc fail: %d\n", v6);
        if ( **v5 < 0 )
          mmio_clear_register(off_1138A0, (int)aUsbWlanRxPktFr_0, 495);
      }
      result = (uint32_t *)cmd_handler_a(dword_113894, v8);
      v7 = *(uint16_t *)(*(uint32_t *)v0 + 8);
      ++v6;
      ++*v3;
    }
    while ( v7 > v6 );
  }
  return result;
}
