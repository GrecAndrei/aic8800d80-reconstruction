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

extern uint32_t off_11DBD4;
extern uint32_t off_11DBF4;
extern uint32_t dword_11DC00;
extern uint32_t off_11DBD8;
extern uint32_t off_11DBEC;
extern uint32_t dword_11DBF0;
extern uint32_t dword_11DBE0;
extern uint32_t off_11DBE4;
extern uint32_t off_11DBE8;
extern uint32_t off_11DBF8;
extern uint32_t off_11DBFC;

// radio_init @ 0x11da70, size 356 bytes
int  radio_init(int inited)
{
  uint32_t *v1; // r7
  uint8_t *v2; // r9
  int v3; // r8
  int v4; // r6
  int i; // r5
  int v6; // r3
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r2
  int v12; // r3
  int v13; // r4
  int result; // r0
  int v15; // r1
  int v16; // r2
  void ( *v17)(uint32_t); // r2
  void *v18; // r3
  uint32_t *v19; // r5
  int v20; // [sp+14h] [bp-8h]

  v1 = off_11DBD4;
  v2 = off_11DBF4;
  v3 = dword_11DC00;
  v4 = inited;
  for ( i = 0; ; ++i )
  {
    v13 = rf_status_poll(inited);
    *v1 = 0x10000;
    result = unknown_func_12d14c(0x80000);
    if ( !v13 )
      break;
    if ( !v4 )
    {
      v6 = (uint8_t)v2[192];
      if ( v2[192] )
      {
        v6 = *(uint32_t *)off_11DBD8;
        if ( *(uint32_t *)off_11DBD8 > 0x80000u || i > 31 )
          return unknown_func_12d104(0x80000);
      }
      else if ( i > 3 )
      {
        return unknown_func_12d104(0x80000);
      }
    }
    v7 = check_rom_state(result, v15, v16, v6);
    if ( !v7 || (v7 = rf_chan_enabled(v7, v8, v9, v10)) == 0 )
    {
      v18 = off_11DBEC;
      *((uint8_t *)off_11DBEC + 69) = 1;
      rf_chan_enabled(v7, v8, 1, v18);
      return check_status_bits(1024, dword_11DBF0);
    }
    v11 = *(uint32_t *)(v13 + 20);
    if ( v11 != v3 )
      event_dispatch(dword_11DBE0, v13, v11);
    ke_task_state_get(v13);
    inited = rf_rx_check(v13);
    if ( inited )
    {
      if ( inited != 1 )
        goto LABEL_10;
    }
    else
    {
      inited = tx_check_allow(v13);
      if ( inited )
        goto LABEL_10;
    }
    inited = llm_evt_queue_pop(v13);
LABEL_10:
    v12 = **(uint8_t **)off_11DBE4;
    switch ( v12 )
    {
      case 2:
        goto LABEL_22;
      case 4:
        if ( !*(uint32_t *)off_11DBE8 || *(uint32_t *)(*(uint32_t *)off_11DBE8 + 12) != v13 || (*(uint8_t *)(v13 + 16) & 1) == 0 )
        {
LABEL_22:
          inited = mac_wait_scan();
          continue;
        }
        v20 = *(uint32_t *)off_11DBE8;
        mem_word_load(off_11DBE8);
        v17 = *(void ( **)(uint32_t))(v20 + 4);
        *(uint8_t *)(v20 + 16) = 0;
        if ( v17 )
          v17(*(uint32_t *)(v20 + 8));
        inited = radio_get_status(v13);
        break;
      case 3:
        inited = mac_wait_tx();
        break;
    }
  }
  if ( *((uint8_t *)off_11DBF4 + 192) )
  {
    v19 = off_11DBF8;
    if ( *((uint8_t *)off_11DBF8 + 33) )
    {
      result = unknown_1(*((uint32_t *)off_11DBF8 + 4), *((uint32_t *)off_11DBF8 + 5), *((uint32_t *)off_11DBF8 + 6));
      v19[5] = 0;
      v19[7] = 0;
      v19[4] = 0;
      v19[6] = 0;
      *((uint8_t *)v19 + 33) = 0;
    }
  }
  *(uint32_t *)off_11DBFC |= 0x10000u;
  return result;
}

