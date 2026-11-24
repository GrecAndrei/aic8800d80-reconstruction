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


extern uint32_t dword_12F61C;
extern uint32_t off_12F57C;
extern uint32_t off_12F584;
extern uint32_t off_12F588;
extern uint32_t off_12F58C;
extern uint32_t off_12F590;
extern uint32_t off_12F594;
extern uint32_t off_12F5B4;
extern uint32_t off_12F5B8;
extern uint32_t off_12F5BC;
extern uint32_t off_12F5C0;
extern uint32_t off_12F5E0;
extern uint32_t off_12F5E8;
extern uint32_t off_12F5F0;
extern uint32_t off_12F5F8;
extern uint32_t off_12F600;
extern uint32_t off_12F608;
extern uint32_t off_12F610;
extern uint32_t off_12F618;
extern uint32_t off_12F620;
extern uint32_t off_12F624;
extern uint32_t off_12F628;
extern uint32_t off_12F62C;

// radio_init_2 @ 0x12f3bc, size 448 bytes
int radio_init_2()
{
  uint32_t *v0; // r4
  uint32_t *v1; // r10
  uint32_t *v2; // r6
  uint32_t *v3; // r7
  uint32_t *v4; // r8
  uint32_t *v5; // r9
  uint32_t *v6; // r5
  int v7; // r0
  int v8; // r3
  uint32_t *v9; // r7
  uint32_t *v10; // r5
  int v11; // r4
  int v13; // nf
  uint32_t **v14; // r3

  v0 = off_12F584;
  v1 = off_12F620;
  v2 = off_12F588;
  v3 = off_12F58C;
  v4 = off_12F624;
  v5 = off_12F628;
  v6 = off_12F590;
  ke_event_schedule_1("\x9Bcurrent state is %d\r\n", *(uint32_t *)off_12F57C & 0xF);
  ke_event_schedule_1("\x9B40328188=%08x, 4032818c=%x\r\n", *v0, *(uint32_t *)off_12F594);
  ke_event_schedule_1("txlist cptr 40128540=%08x \r\n", *v1);
  ke_event_schedule_1("ac0 sptr 40328528=%08x \r\n", *v2);
  ke_event_schedule_1("ac1 sptr 4032852c=%08x \r\n", *v3);
  ke_event_schedule_1("ac2 sptr 40328530=%08x \r\n", *v4);
  ke_event_schedule_1("ac3 sptr 40328534=%08x \r\n", *v5);
  ke_event_schedule_1("hiq sptr 4032853c=%08x \r\n", *v6);
  ke_event_schedule_1(
    "\x9Bac0header=%08x, ac1header=%08x, ac2header=%08x, ac3header=%08x, hiqheader=%x\r\n",
    *(uint32_t *)off_12F5B4,
    *(uint32_t *)off_12F5B8,
    *(uint32_t *)off_12F5BC,
    *(uint32_t *)off_12F5C0,
    *(uint32_t *)off_12F62C);
  ke_event_schedule_1("\x9Bstatus of 0x40328528=%08x\r\n", *(uint32_t *)(*v2 + 60));
  ke_event_schedule_1("\x9Bstatus of 0x4032852c=%08x\r\n", *(uint32_t *)(*v3 + 60));
  ke_event_schedule_1("\x9Bstatus of 0x40328530=%08x\r\n", *(uint32_t *)(*v4 + 60));
  ke_event_schedule_1("\x9Bstatus of 0x40328534=%08x\r\n", *(uint32_t *)(*v5 + 60));
  ke_event_schedule_1("\x9Bstatus of 0x4032853c=%08x\r\n", *(uint32_t *)(*v6 + 60));
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
  else if ( (*v0 & 0x20000) != 0 )
  {
    v0 = (uint32_t *)*v5;
  }
  else
  {
    v14 = (uint32_t **)(*v0 << 30);
    v13 = (*v0 & 2) != 0;
    if ( (*v0 & 2) != 0 )
      v14 = (uint32_t **)dword_12F61C;
    else
      v0 = (uint32_t *)*v1;
    if ( v13 )
      v0 = *v14;
  }
  if ( v0 )
  {
    rx_packet_handler_2((int)v0, 68, 1, 0);
    rx_packet_handler_2(v0[9], 52, 1, 0);
    ke_event_schedule_1("\x9Bfrmlen=%x\r\n", v0[6]);
    v7 = v0[4];
    if ( v7 )
    {
      rx_packet_handler_2(v7, v0[5] + 1 - v7, 1, 0);
      v8 = v0[3];
      if ( !v8 )
        goto LABEL_6;
    }
    else
    {
      v8 = v0[3];
      if ( !v8 )
        goto LABEL_6;
    }
    rx_packet_handler_2(*(uint32_t *)(v8 + 8), *(uint32_t *)(v8 + 12) + 1 - *(uint32_t *)(v8 + 8), 1, 0);
  }
LABEL_6:
  v9 = off_12F5E0;
  v10 = off_12F5E8;
  LOBYTE(v11) = 8;
  do
  {
    ke_event_schedule_1("\x9B0x40320500=%08x\r\n", *v9);
    ke_event_schedule_1("\x9B0x40320504=%08x\r\n", *v10);
    v11 = (uint8_t)(v11 - 1);
  }
  while ( v11 );
  ke_event_schedule_1("\x9B0x40320514=%08x\r\n", *(uint32_t *)off_12F5F0);
  ke_event_schedule_1("\x9B0x40320518=%08x\r\n", *(uint32_t *)off_12F5F8);
  ke_event_schedule_1("\x9B0x4032051c=%08x\r\n", *(uint32_t *)off_12F600);
  ke_event_schedule_1("\x9B0x40320520=%08x\r\n", *(uint32_t *)off_12F608);
  return ke_event_schedule_1("\x9B0x40320560=%08x\r\n", *(uint32_t *)off_12F610);
}
