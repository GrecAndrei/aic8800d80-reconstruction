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

extern uint32_t dword_117CCC;
extern uint32_t off_117CC8;
extern uint32_t dword_117D00;
extern uint32_t off_117CD0;
extern uint32_t dword_117CD4;
extern uint32_t off_117CD8;
extern uint32_t off_117CDC;
extern uint32_t dword_117CFC;
extern uint32_t off_117CE0;
extern uint32_t off_117CE4;
extern uint32_t off_117CE8;
extern uint32_t off_117CEC;
extern uint32_t off_117CF0;
extern uint32_t off_117CF4;
extern uint32_t dword_117CF8;

// conn_rx @ 0x117ae0, size 488 bytes
int  conn_rx(int a1, int a2)
{
  char *v4; // r7
  int v5; // r10
  int v6; // r8
  int v7; // r11
  int v8; // r9
  int v10; // r3
  int16_t v11; // r1
  int v12; // r6
  int v13; // r3
  int *v14; // r6
  int v15; // r2
  char v16; // r3
  int v17; // r0
  int v18; // r1
  uint8_t *v19; // r3
  int v20; // r3
  int v21; // r2
  int v22; // r2
  int v23; // r1
  int16_t v24; // r3
  int *v25; // r3
  int v26; // r3
  int v27; // r2
  int v28; // r3
  int v29; // r2
  uint32_t *v30; // r3
  int v31; // [sp+4h] [bp-8h]

  if ( a2 == 5 )
    v4 = (char *)dword_117CCC;
  else
    v4 = (char *)off_117CC8 + 84 * a2;
  v5 = *(uint8_t *)(a1 + 28);
  v6 = dword_117D00;
  v7 = *(uint32_t *)(a1 + 76);
  v8 = dword_117D00 + 1320 * v5;
  if ( init_once(v8)
    && ((v10 = *(uint8_t *)(a1 + 28), *(uint8_t *)(v6 + 1320 * v10 + 106))
     || *(uint8_t *)(a1 + 29) > 0x23u
     || *(uint16_t *)(a1 + 4)
     || (v11 = *(uint16_t *)(*(uint32_t *)(a1 + 72) + 108), (uint8_t)v11 != 192)
     && (uint8_t)v11 != 176
     && (v11 & 0xDF) != 0
     || (v12 = *((uint32_t *)off_117CD0 + 10)) == 0
     || *(uint8_t *)(v12 + 24) <= 2u
     || (v13 = *(uint32_t *)(v6 + 1320 * v10 + 72)) == 0
     || (v31 = v13, ke_event_schedule(dword_117CD4, v12 == v13, (uint8_t)v11), v12 == v31))
    && phy_check_core_mode(a1) )
  {
    *(uint32_t *)(v7 + 68) |= 0x100u;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_117CD8 = 1;
    }
    v14 = (int *)off_117CDC;
    v15 = *((uint32_t *)v4 + 11);
    v16 = v4[80] + 1;
    ++*(uint32_t *)off_117CDC;
    v4[80] = v16;
    if ( v15 )
      llc_tx_llcp_handler(a2);
    if ( !*((uint32_t *)v4 + 5) )
    {
      v30 = *(uint32_t **)(a1 + 72);
      v30[4] = dword_117CFC;
      v30[2] = a1;
      v30[3] = a1;
    }
    v17 = check_abort_flag(v4 + 12);
    v18 = *((uint32_t *)off_117CE0 + 8);
    ++*((uint32_t *)off_117CC8 + 126);
    if ( v18 )
    {
      v19 = *(uint8_t **)off_117CE4;
      v17 = 0x80000000;
      *(uint32_t *)off_117CE8 = 0x80000000;
      if ( *v19 == 3 && v18 == v8 )
        *(uint32_t *)(v6 + 1320 * v5 + 120) = *((uint32_t *)off_117CEC + 4);
    }
    if ( **(uint8_t **)off_117CF0 == 2 && (*(uint32_t *)off_117CF4 & dword_117CF8) == 0 )
      log_and_check_hw(v17, v18, *(uint32_t *)off_117CF4);
    if ( *v14 )
    {
      v20 = *v14 - 1;
      v21 = *(uint32_t *)off_117CD8;
      *v14 = v20;
      if ( !v20 )
      {
        if ( v21 )
          __enable_irq();
      }
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_117CD8 = 1;
    }
    v22 = *v14;
    v23 = *v14 + 1;
    v24 = *(uint16_t *)(a1 + 82) | 1;
    *v14 = v23;
    *(uint16_t *)(a1 + 82) = v24;
    if ( v23 )
    {
      v25 = (int *)off_117CD8;
      *v14 = v22;
      v26 = *v25;
      if ( !v22 )
      {
        if ( v26 )
          __enable_irq();
      }
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_117CD8 = 1;
    }
    v27 = *(uint32_t *)(a1 + 72);
    ++*v14;
    mac_set_flag(a1, a1, v27, a2);
    if ( *v14 )
    {
      v28 = *v14 - 1;
      v29 = *(uint32_t *)off_117CD8;
      *v14 = v28;
      if ( !v28 )
      {
        if ( v29 )
          __enable_irq();
      }
    }
    return 1;
  }
  else if ( *(uint8_t *)(a1 + 29) == 255 )
  {
    ble_conn_event_handler(a1, 0);
    return 0;
  }
  else
  {
    get_sta_entry((uint8_t *)a1, a2);
    return 1;
  }
}

