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

extern uint32_t dword_111D1C;
extern uint32_t off_111D20;
extern uint32_t off_111D24;
extern uint32_t off_111D28;
extern uint32_t dword_111D54;
extern uint32_t off_111D2C;
extern uint32_t off_111D44;
extern uint32_t off_111D48;
extern uint32_t off_111D4C;
extern uint32_t dword_111D50;
extern uint32_t dword_111D30;
extern uint32_t dword_111D38;
extern uint32_t off_111D3C;
extern uint32_t off_111D34;
extern uint32_t dword_111D40;

// ipc_send_request @ 0x111c14, size 262 bytes
int  ipc_send_request(uint32_t *a1, int a2)
{
  uint8_t *v4; // r6
  uint32_t *v5; // r7
  void *v6; // r0
  int v7; // r2
  int v8; // r1
  uint32_t *v9; // r4
  int v10; // r1
  void ( *v11)(int); // r2
  int v12; // r1
  uint32_t *v13; // r3
  uint8_t *v15; // r7
  int v16; // r0
  int v17; // r1
  uint32_t *v18; // r3

  ke_event_schedule(dword_111D1C, 0, a2);
  if ( !a1 )
    return 1;
  if ( !*a1 || !a1[1] || !a1[2] || !a1[5] )
    return 2;
  v4 = off_111D20;
  if ( *(uint8_t *)off_111D20 )
    return 3;
  v5 = off_111D24;
  v6 = off_111D28;
  *(uint8_t *)off_111D20 = 1;
  memcpy_aligned(v6, a1, 80);
  v8 = v5[97];
  if ( v8 )
  {
    ke_event_schedule(dword_111D54, v8, v7);
    timer_set(v5[97]);
  }
  v9 = off_111D2C;
  if ( (*((uint32_t *)off_111D2C + 512) & 0x7F0) != 0 )
  {
    v15 = off_111D44;
    *((uint32_t *)off_111D44 + 1) = 0;
    *((uint32_t *)v15 + 2) = 0;
    *v15 = 0;
    *v4 = 4;
    v16 = tx_pkt_config();
    v17 = *(uint32_t *)off_111D48;
    v18 = *(uint32_t **)off_111D4C;
    *v18 = dword_111D50;
    v18[1] = v17;
    v9[709] = v18;
    v9[706] = v9[706];
    v11 = *((void ( **)(int))off_111D28 + 19);
    v10 = 1;
    v9[704] |= 0x84000000;
    *v15 = 1;
    if ( v11 )
      v11(v16);
  }
  else
  {
    if ( (*((uint32_t *)off_111D2C + 2) & 1) != 0 )
    {
      *((uint32_t *)off_111D2C + 2) &= ~1u;
      v9[513] |= 2u;
    }
    rf_radio_enable();
  }
  ke_event_schedule(dword_111D30, v10, v11);
  v12 = dword_111D38;
  v13 = off_111D3C;
  *(uint32_t *)(*((uint32_t *)off_111D34 + 2) + 320) = dword_111D38;
  v13[2] = 1;
  if ( a2 == 1 )
  {
    while ( *v4 != 4 )
      ;
  }
  ke_event_schedule(dword_111D40, v12, 1);
  return 0;
}

