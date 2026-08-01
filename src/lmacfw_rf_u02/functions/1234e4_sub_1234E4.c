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

extern uint32_t off_1236C4;
extern uint32_t off_1236C8;
extern uint32_t off_1236CC;
extern uint32_t off_1236D0;
extern uint32_t dword_1236F0;
extern uint32_t dword_1236F4;
extern uint32_t dword_1236F8;
extern uint32_t off_1236DC;
extern uint32_t off_1236D4;
extern uint32_t dword_1236D8;
extern uint32_t dword_1236EC;
extern uint32_t dword_1236E0;
extern uint32_t off_1236E4;
extern uint32_t dword_1236E8;

// read_irq_status @ 0x1234e4, size 480 bytes
void read_irq_status()
{
  uint8_t *v0; // r6
  uint8_t *v1; // r5
  uint8_t *v2; // r7
  uint64_t v3; // r2
  uint8_t v4; // r4
  int v5; // r3
  int v6; // r3
  int v7; // r7
  int v8; // r4
  int v9; // r0
  int n; // r4
  int v11; // r3
  int v12; // r6
  int v13; // r4
  int v14; // r0
  int *v15; // r2
  int v16; // r4
  int v17; // r0
  int v18; // r0
  int v19; // r3
  int v20; // r4
  int v21; // r2
  int v22; // r0
  int v23; // r4
  int v24; // r0
  uint8_t v25; // [sp+Eh] [bp-6h] BYREF
  uint8_t v26[5]; // [sp+Fh] [bp-5h] BYREF

  v0 = off_1236C4;
  v1 = (uint8_t *)off_1236C8;
  v2 = off_1236CC;
  HIDWORD(v3) = *(uint8_t *)off_1236CC;
  LODWORD(v3) = *(uint8_t *)off_1236C4 | *(uint8_t *)off_1236C8;
  v4 = BYTE4(v3) | v3;
  if ( !v3 )
  {
    mmio_set_control();
    if ( (*(uint8_t *)off_1236D0 & 0xFD) == 1 )
    {
      v25 = v4;
      v26[0] = v4;
      mmio_read_status(&v25);
      mmio_read_byte(v26);
      dispatch_event_handler(dword_1236F0, v25, v26[0]);
      v22 = v25;
      if ( v25 )
      {
        if ( v25 > 0x1Fu )
        {
          v22 = 31;
          v25 = 31;
        }
        set_xtal_ftune(v22);
        dispatch_event_handler(dword_1236F4, v25);
      }
      if ( v26[0] )
      {
        if ( v26[0] > 0x3Fu )
        {
          v26[0] = 63;
          v23 = 16515072;
        }
        else
        {
          v23 = (v26[0] << 18) & 0xFC0000;
        }
        v24 = dword_1236F8;
        *(uint32_t *)off_1236DC = *(uint32_t *)off_1236DC & 0xFF03FFFF | v23;
        dispatch_event_handler(v24);
      }
    }
    BYTE4(v3) = *v2;
  }
  v5 = (uint8_t)(BYTE4(v3) + 1);
  if ( v5 != 8 )
  {
    *v2 = v5;
    return;
  }
  v6 = (uint8_t)*v0;
  *v2 = 0;
  if ( !v6 )
  {
    v7 = *(uint32_t *)off_1236D4;
    if ( (*(uint8_t *)off_1236D0 & 0xFD) != 1 )
    {
      if ( (v7 & 0x1000000) != 0 )
        v8 = 1;
      else
        v8 = -1;
      v9 = get_xtal_ftune() + v8;
      if ( v9 < 1 )
        v9 = 1;
      if ( v9 >= 31 )
        v9 = 31;
      set_xtal_ftune(v9);
    }
    n = get_xtal_ftune();
    rf_cmd_check((uint8_t)n);
    dispatch_event_handler(dword_1236D8, *v1, n, v7);
    v11 = (uint8_t)(*v1 + 1);
    if ( v11 != 16 )
      goto LABEL_15;
    goto LABEL_33;
  }
  if ( v6 == 1 )
  {
    v19 = *(uint32_t *)off_1236D4;
    if ( (*(uint8_t *)off_1236D0 & 0xFD) != 1 )
    {
      if ( (v19 & 0x1000000) != 0 )
        v20 = 1;
      else
        v20 = -1;
      v21 = ((*(uint32_t *)off_1236DC >> 18) & 0x3F) + v20;
      if ( v21 < 1 )
        v21 = 1;
      if ( v21 >= 63 )
        v21 = 63;
      *(uint32_t *)off_1236DC = *(uint32_t *)off_1236DC & 0xFF03FFFF | (v21 << 18);
    }
    dispatch_event_handler(dword_1236EC, *v1, (*(uint32_t *)off_1236DC >> 18) & 0x3F, v19);
    v11 = (uint8_t)(*v1 + 1);
    if ( v11 != 32 )
      goto LABEL_15;
LABEL_33:
    ++*v0;
    *v1 = 0;
    return;
  }
  v12 = *(uint32_t *)off_1236D4;
  if ( (*(uint32_t *)off_1236D4 & 0x1000000) != 0 )
    v13 = 0x2000000 - v12;
  else
    v13 = *(uint32_t *)off_1236D4;
  v14 = get_xtal_ftune();
  dispatch_event_handler(dword_1236E0, v14, (*(uint32_t *)off_1236DC >> 18) & 0x3F, v12, v13);
  v15 = (int *)off_1236E4;
  v11 = (uint8_t)(*v1 + 1);
  v16 = v13 + *(uint32_t *)off_1236E4;
  *(uint32_t *)off_1236E4 = v16;
  if ( v11 != 16 )
  {
LABEL_15:
    *v1 = v11;
    return;
  }
  v17 = dword_1236E8;
  *v1 = 0;
  *v15 = v16 / 16;
  v18 = dispatch_event_handler(v17);
  if ( (unsigned int)*(uint8_t *)off_1236D0 - 2 <= 1 )
    ll_state_reset(v18);
  else
    rf_set_flag(2);
}

