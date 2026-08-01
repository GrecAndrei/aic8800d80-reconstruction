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
extern uint32_t dword_1131F4;
extern uint32_t dword_11320C;
extern uint32_t off_1131FC;
extern uint32_t off_113200;
extern uint32_t off_1131F8;
extern uint32_t dword_113204;
extern uint32_t dword_113208;

// bt_wait_ready @ 0x11316c, size 126 bytes
int  bt_wait_ready(int a1)
{
  uint16_t *v2; // r4
  int v3; // r1
  int v4; // r2
  uint8_t *v5; // r1
  uint8_t *v6; // r2
  uint32_t *v7; // r7
  int v8; // r6
  int v9; // r1
  int v10; // r4
  int v11; // r2

  if ( (*(uint32_t *)off_1131EC & 0x2000000) != 0 )
  {
    sub_100200((int *)off_1131F0, 0xFFu, 4u);
  }
  else
  {
    v2 = (uint16_t *)off_1131F0;
    sub_100200((int *)off_1131F0, 0xFFu, 4u);
    if ( get_rssi(v2) || (v4 = v2[1], v4 == 0xFFFF) || (v3 = *v2, v3 == 0xFFFF) )
      alloc_tx_event(dword_1131F4, v3, v4);
    else
      alloc_tx_event(dword_11320C, v3, v4);
  }
  v5 = off_1131FC;
  v6 = off_113200;
  *(uint32_t *)off_1131F8 = *(uint32_t *)a1;
  v7 = (uint32_t *)dword_113204;
  v8 = dword_113208;
  *v5 = 0;
  *v6 = 0;
  do
  {
    v9 = *(uint8_t *)(a1 + 8);
    if ( *(uint8_t *)(a1 + 8) )
      v9 = 1;
    v10 = wlan_set_band(v7, v9);
    alloc_tx_event(v8, v10, v11);
  }
  while ( v10 );
  return 0;
}

