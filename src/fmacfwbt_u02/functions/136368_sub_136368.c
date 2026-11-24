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


extern uint32_t dword_136400;
extern uint32_t off_136404;

// tx_build_packet @ 0x136368, size 142 bytes
int  tx_build_packet(int a1, uint8_t *a2, int a3, int a4)
{
  uint16_t v5; // r6
  uint16_t v6; // r5
  int v7; // r2
  int v8; // r3
  int v9; // r1
  char v10; // r7
  char *v11; // r0
  int v13; // r0
  uint8_t a2a[5]; // [sp+7h] [bp-5h] BYREF

  v5 = a3;
  v6 = a4;
  v7 = a2[9];
  v8 = *a2;
  a2a[0] = 0;
  ke_event_schedule_1("%s %x %d\n", aApmStartCacReq, v7, v8);
  v9 = dword_136400 + 1320 * a2[10];
  if ( *(uint8_t *)(v9 + 106) == 2 )
  {
    if ( *(uint8_t *)(v9 + 108) || hci_cmd_send_short(7u) )
    {
      v10 = 8;
    }
    else
    {
      v13 = find_free_conn(a2, a2a);
      v10 = v13;
      if ( v13 )
      {
        v10 = 1;
      }
      else
      {
        update_entries_from_config(a2[10], a2a[0]);
        *((uint32_t *)off_136404 + 1) |= 0x10u;
      }
    }
  }
  else
  {
    v10 = 4;
  }
  v11 = (char *)bt_buf_alloc(7173, v6, v5, 2);
  *v11 = v10;
  v11[1] = a2a[0];
  hci_evt_send((int)v11);
  return 0;
}
