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
extern uint32_t dword_113190;
extern uint32_t dword_1131A8;
extern uint32_t off_113198;
extern uint32_t off_11319C;
extern uint32_t off_113194;
extern uint32_t dword_1131A0;
extern uint32_t dword_1131A4;

// sys_cmu_clock_get @ 0x113108, size 126 bytes
int  sys_cmu_clock_get(int a1)
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

  if ( (*(uint32_t *)off_113188 & 0x2000000) != 0 )
  {
    memset_byte((int *)off_11318C, 0xFFu, 4u);
  }
  else
  {
    v2 = (uint16_t *)off_11318C;
    memset_byte((int *)off_11318C, 0xFFu, 4u);
    if ( ioctl2_cmd_0x400000(v2) || (v4 = v2[1], v4 == 0xFFFF) || (v3 = *v2, v3 == 0xFFFF) )
      ke_event_schedule(dword_113190, v3, v4);
    else
      ke_event_schedule(dword_1131A8, v3, v4);
  }
  v5 = off_113198;
  v6 = off_11319C;
  *(uint32_t *)off_113194 = *(uint32_t *)a1;
  v7 = (uint32_t *)dword_1131A0;
  v8 = dword_1131A4;
  *v5 = 0;
  *v6 = 0;
  do
  {
    v9 = *(uint8_t *)(a1 + 8);
    if ( *(uint8_t *)(a1 + 8) )
      v9 = 1;
    v10 = ipc_send_request(v7, v9);
    ke_event_schedule(v8, v10, v11);
  }
  while ( v10 );
  return 0;
}

