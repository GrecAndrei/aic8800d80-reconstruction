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


extern uint32_t off_1131EC;
extern uint32_t off_1131F0;
extern uint32_t off_1131F8;
extern uint32_t off_1131FC;
extern uint32_t off_113200;

// bt_wait_ready @ 0x11316c, size 126 bytes
int  bt_wait_ready(int a1)
{
  uint16_t *v2; // r4
  int v3; // r2
  int v4; // r1
  uint8_t *v5; // r1
  uint8_t *v6; // r2
  int v7; // r1
  int v8; // r4

  if ( (*(uint32_t *)off_1131EC & 0x2000000) != 0 )
  {
    memset_thunk((int *)off_1131F0, 0xFFu, 4u);
  }
  else
  {
    v2 = (uint16_t *)off_1131F0;
    memset_thunk((int *)off_1131F0, 0xFFu, 4u);
    if ( get_rssi((int)v2) || (v3 = v2[1], v3 == 0xFFFF) || (v4 = *v2, v4 == 0xFFFF) )
      alloc_tx_event(aNoUsbInfoInFla);
    else
      alloc_tx_event("get vid %x, pid %x\r\n", v4, v3);
  }
  v5 = off_1131FC;
  v6 = off_113200;
  *(uint32_t *)off_1131F8 = *(uint32_t *)a1;
  *v5 = 0;
  *v6 = 0;
  do
  {
    v7 = *(uint8_t *)(a1 + 8);
    if ( *(uint8_t *)(a1 + 8) )
      v7 = 1;
    v8 = wlan_set_band((int)asc_1532B0, v7);
    alloc_tx_event("open res:%d\n", v8);
  }
  while ( v8 );
  return 0;
}
