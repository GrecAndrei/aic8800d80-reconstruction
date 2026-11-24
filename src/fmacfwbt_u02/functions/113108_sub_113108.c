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


extern uint32_t off_113188;
extern uint32_t off_11318C;
extern uint32_t off_113194;
extern uint32_t off_113198;
extern uint32_t off_11319C;
extern uint32_t off_1131A0;

// sys_cmu_clock_get @ 0x113108, size 126 bytes
int  sys_cmu_clock_get(int a1)
{
  uint16_t *v2; // r4
  int v3; // r2
  int v4; // r1
  uint8_t *v5; // r1
  uint8_t *v6; // r2
  int v7; // r7
  int v8; // r1
  int v9; // r4

  if ( (*(uint32_t *)off_113188 & 0x2000000) != 0 )
  {
    memset_byte((int *)off_11318C, 0xFFu, 4u);
  }
  else
  {
    v2 = (uint16_t *)off_11318C;
    memset_byte((int *)off_11318C, 0xFFu, 4u);
    if ( ioctl2_cmd_0x400000((int)v2) || (v3 = v2[1], v3 == 0xFFFF) || (v4 = *v2, v4 == 0xFFFF) )
      ke_event_schedule_1(aNoUsbInfoInFla);
    else
      ke_event_schedule_1("get vid %x, pid %x\r\n", v4, v3);
  }
  v5 = off_113198;
  v6 = off_11319C;
  *(uint32_t *)off_113194 = *(uint32_t *)a1;
  v7 = off_1131A0;
  *v5 = 0;
  *v6 = 0;
  do
  {
    v8 = *(uint8_t *)(a1 + 8);
    if ( *(uint8_t *)(a1 + 8) )
      v8 = 1;
    v9 = ipc_send_request(v7, v8);
    ke_event_schedule_1("open res:%d\n", v9);
  }
  while ( v9 );
  return 0;
}
