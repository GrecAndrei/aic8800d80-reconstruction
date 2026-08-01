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

extern uint32_t off_12F584;
extern uint32_t off_12F620;
extern uint32_t off_12F588;
extern uint32_t off_12F58C;
extern uint32_t off_12F624;
extern uint32_t off_12F628;
extern uint32_t off_12F590;
extern uint32_t dword_12F580;
extern uint32_t off_12F57C;
extern uint32_t dword_12F598;
extern uint32_t off_12F594;
extern uint32_t dword_12F59C;
extern uint32_t dword_12F5A0;
extern uint32_t dword_12F5A4;
extern uint32_t dword_12F5A8;
extern uint32_t dword_12F5AC;
extern uint32_t dword_12F5B0;
extern uint32_t dword_12F5C4;
extern uint32_t off_12F5B4;
extern uint32_t off_12F5B8;
extern uint32_t off_12F5BC;
extern uint32_t off_12F5C0;
extern uint32_t off_12F62C;
extern uint32_t dword_12F5C8;
extern uint32_t dword_12F5CC;
extern uint32_t dword_12F5D0;
extern uint32_t dword_12F5D4;
extern uint32_t dword_12F5D8;
extern uint32_t off_12F618;
extern uint32_t dword_12F61C;
extern uint32_t dword_12F5DC;
extern uint32_t off_12F5E0;
extern uint32_t dword_12F5E4;
extern uint32_t off_12F5E8;
extern uint32_t dword_12F5EC;
extern uint32_t dword_12F5F4;
extern uint32_t off_12F5F0;
extern uint32_t dword_12F5FC;
extern uint32_t off_12F5F8;
extern uint32_t dword_12F604;
extern uint32_t off_12F600;
extern uint32_t dword_12F60C;
extern uint32_t off_12F608;
extern uint32_t dword_12F614;
extern uint32_t off_12F610;

// radio_init @ 0x12f3bc, size 448 bytes
int radio_init()
{
  uint32_t *v0; // r4
  uint32_t *v1; // r10
  uint32_t *v2; // r6
  uint32_t *v3; // r7
  uint32_t *v4; // r8
  uint32_t *v5; // r9
  uint32_t *v6; // r5
  int v7; // r2
  unsigned int v8; // r0
  int v9; // r3
  uint32_t *v10; // r7
  int v11; // r6
  uint32_t *v12; // r5
  int v13; // r4
  int v15; // nf
  uint32_t **v16; // r3

  v0 = off_12F584;
  v1 = off_12F620;
  v2 = off_12F588;
  v3 = off_12F58C;
  v4 = off_12F624;
  v5 = off_12F628;
  v6 = off_12F590;
  ke_event_schedule(dword_12F580, *(uint32_t *)off_12F57C & 0xF);
  ke_event_schedule(dword_12F598, *v0, *(uint32_t *)off_12F594);
  ke_event_schedule(dword_12F59C, *v1);
  ke_event_schedule(dword_12F5A0, *v2);
  ke_event_schedule(dword_12F5A4, *v3);
  ke_event_schedule(dword_12F5A8, *v4);
  ke_event_schedule(dword_12F5AC, *v5);
  ke_event_schedule(dword_12F5B0, *v6);
  ke_event_schedule(
    dword_12F5C4,
    *(uint32_t *)off_12F5B4,
    *(uint32_t *)off_12F5B8,
    *(uint32_t *)off_12F5BC,
    *(uint32_t *)off_12F5C0,
    *(uint32_t *)off_12F62C);
  ke_event_schedule(dword_12F5C8, *(uint32_t *)(*v2 + 60));
  ke_event_schedule(dword_12F5CC, *(uint32_t *)(*v3 + 60));
  ke_event_schedule(dword_12F5D0, *(uint32_t *)(*v4 + 60));
  ke_event_schedule(dword_12F5D4, *(uint32_t *)(*v5 + 60));
  ke_event_schedule(dword_12F5D8, *(uint32_t *)(*v6 + 60));
  v7 = *v0 << 6;
  if ( (*v0 & 0x2000000) != 0 )
  {
    v0 = (uint32_t *)*v6;
  }
  else if ( (*v0 & 0x200000) != 0 )
  {
    v0 = *(uint32_t **)off_12F618;
  }
  else if ( (*v0 & 0x20) != 0 )
  {
    v0 = (uint32_t *)*v2;
  }
  else if ( (*v0 & 0x200) != 0 )
  {
    v0 = (uint32_t *)*v3;
  }
  else if ( (*v0 & 0x2000) != 0 )
  {
    v0 = (uint32_t *)*v4;
  }
  else
  {
    v7 = *v0 << 14;
    if ( (*v0 & 0x20000) != 0 )
    {
      v0 = (uint32_t *)*v5;
    }
    else
    {
      v16 = (uint32_t **)(*v0 << 30);
      v15 = (*v0 & 2) != 0;
      if ( (*v0 & 2) != 0 )
        v16 = (uint32_t **)dword_12F61C;
      else
        v0 = (uint32_t *)*v1;
      if ( v15 )
        v0 = *v16;
    }
  }
  if ( v0 )
  {
    rx_packet_handler((unsigned int)v0, 68, 1, 0);
    rx_packet_handler(v0[9], 52, 1, 0);
    ke_event_schedule(dword_12F5DC, v0[6]);
    v8 = v0[4];
    if ( v8 )
    {
      rx_packet_handler(v8, v0[5] + 1 - v8, 1, 0);
      v9 = v0[3];
      if ( !v9 )
        goto LABEL_6;
    }
    else
    {
      v9 = v0[3];
      if ( !v9 )
        goto LABEL_6;
    }
    rx_packet_handler(*(uint32_t *)(v9 + 8), *(uint32_t *)(v9 + 12) + 1 - *(uint32_t *)(v9 + 8), 1, 0);
  }
LABEL_6:
  v10 = off_12F5E0;
  v11 = dword_12F5E4;
  v12 = off_12F5E8;
  LOBYTE(v13) = 8;
  do
  {
    ke_event_schedule(v11, *v10, v7);
    ke_event_schedule(dword_12F5EC, *v12);
    v13 = (uint8_t)(v13 - 1);
  }
  while ( v13 );
  ke_event_schedule(dword_12F5F4, *(uint32_t *)off_12F5F0);
  ke_event_schedule(dword_12F5FC, *(uint32_t *)off_12F5F8);
  ke_event_schedule(dword_12F604, *(uint32_t *)off_12F600);
  ke_event_schedule(dword_12F60C, *(uint32_t *)off_12F608);
  return ke_event_schedule(dword_12F614, *(uint32_t *)off_12F610);
}

