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


extern uint32_t dword_11EDA8;
extern uint32_t dword_11EDAC;
extern uint32_t dword_11EDB4;
extern uint32_t dword_11EDB8;
extern uint32_t dword_11EDBC;
extern uint32_t dword_11EDC0;
extern uint32_t dword_11EDC4;
extern uint32_t off_11EDB0;

// controller_init_pools @ 0x11ecb0, size 248 bytes
int controller_init_pools()
{
  int v0; // r5
  int v1; // r7
  uint32_t *v2; // r6
  uint32_t *v3; // r4
  uint32_t *v4; // r0
  int i; // r5
  uint32_t *v6; // r4
  uint32_t *v7; // r0
  int v8; // r4
  int v9; // r6
  int v10; // r5
  int v11; // r3
  int result; // r0
  int v13; // r3

  v0 = dword_11EDAC;
  v1 = dword_11EDA8;
  clear_stats_buf((uint32_t *)dword_11EDA8);
  v2 = (uint32_t *)(v0 + 22272);
  do
  {
    check_ll_event_queue(v0 - 624);
    wlan_ioctl_handler_1(v1, (uint32_t *)(v0 - 624));
    v3 = (uint32_t *)(v0 - 40);
    do
    {
      clear_stats_buf(v3);
      v4 = v3 + 10;
      v3 += 2;
      clear_stats_buf(v4);
    }
    while ( v3 != (uint32_t *)v0 );
    v0 = (int)(v3 + 174);
  }
  while ( v3 + 174 != v2 );
  for ( i = 2784; i != 3132; i += 87 )
  {
    v6 = v2 - 10;
    do
    {
      clear_stats_buf(v6);
      v7 = v6 + 10;
      v6 += 2;
      clear_stats_buf(v7);
    }
    while ( v6 != v2 );
    v2 = v6 + 174;
  }
  v8 = off_11EDB0;
  v9 = dword_11EDB4;
  v10 = dword_11EDB8;
  check_ll_event_queue(off_11EDB0);
  *(uint32_t *)(v8 + 0x20) = 0x20000000;
  *(uint32_t *)(v8 + 0x150) = v9;
  *(uint32_t *)(v8 + 0xBC) = v10;
  *(uint8_t *)(v8 + 0x34) = 0;
  check_ll_event_queue(v8 + 696);
  *(uint32_t *)(v8 + 0x408) = v9 + 64;
  v11 = dword_11EDBC;
  *(uint32_t *)(v8 + 0x374) = v10 + 1320;
  *(uint32_t *)(v8 + 0x2D8) = v11;
  *(uint8_t *)(v8 + 0x2EC) = 0;
  check_ll_event_queue(v8 + 1392);
  *(uint32_t *)(v8 + 0x6C0) = v9 + 128;
  *(uint32_t *)(v8 + 0x590) = dword_11EDC0;
  *(uint8_t *)(v8 + 0x5A4) = 0;
  *(uint32_t *)(v8 + 0x62C) = v10 + 2640;
  result = check_ll_event_queue(v8 + 2088);
  v13 = dword_11EDC4;
  *(uint8_t *)(v8 + 0x85C) = 0;
  *(uint32_t *)(v8 + 0x978) = v9 + 192;
  *(uint32_t *)(v8 + 0x8E4) = v10 + 3960;
  *(uint32_t *)(v8 + 0x848) = v13;
  return result;
}
