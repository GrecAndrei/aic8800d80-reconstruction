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

extern uint32_t off_116FFC;
extern uint32_t off_117014;
extern uint32_t dword_117020;
extern uint32_t off_117000;
extern uint32_t dword_117008;
extern uint32_t off_11700C;
extern uint32_t off_117010;
extern uint32_t off_117018;
extern uint32_t off_11701C;

// mmio_regs_init @ 0x116ec4, size 312 bytes
int  mmio_regs_init(int a1, int a2, int a3, int a4)
{
  uint32_t *v4; // r7
  uint8_t *v5; // r9
  int v6; // r8
  int v7; // r6
  int i; // r5
  int v9; // r3
  int result; // r0
  int v11; // r4
  int v12; // r1
  int v13; // r2
  void ( *v14)(uint32_t); // r2
  uint32_t *v15; // r5
  int v16; // [sp+14h] [bp-8h]

  v4 = off_116FFC;
  v5 = off_117014;
  v6 = dword_117020;
  v7 = a1;
  for ( i = 0; ; ++i )
  {
    v11 = timer_event_check(a1, a2, a3, a4);
    *v4 = 0x10000;
    result = enter_critical_section(0x400000);
    if ( !v11 )
      break;
    if ( !v7 )
    {
      v9 = (uint8_t)v5[192];
      if ( v5[192] )
      {
        v9 = *(uint32_t *)off_117000;
        if ( *(uint32_t *)off_117000 > 0x400000u || i > 31 )
          return set_busy_flag_alt(0x400000);
      }
      else if ( i > 3 )
      {
        return set_busy_flag_alt(0x400000);
      }
    }
    result = patch_check_enabled(result, v12, v13, v9);
    if ( !result )
      return result;
    if ( *(uint32_t *)(v11 + 20) != v6 )
      dispatch_event_handler(dword_117008, v11);
    rf_cal_offset_apply(v11);
    a1 = wlan_rx_process(v11);
    if ( a1 )
    {
      if ( a1 == 1 )
        a1 = ll_event_timer_handler(v11);
    }
    else
    {
      a1 = tx_acl_queue_process(v11);
    }
    a4 = **(uint8_t **)off_11700C;
    switch ( a4 )
    {
      case 2:
LABEL_22:
        a1 = task_queue_handler_c();
        continue;
      case 4:
        if ( !*(uint32_t *)off_117010 || *(uint32_t *)(*(uint32_t *)off_117010 + 12) != v11 || (*(uint8_t *)(v11 + 16) & 1) == 0 )
          goto LABEL_22;
        v16 = *(uint32_t *)off_117010;
        list_pop_front(off_117010);
        v14 = *(void ( **)(uint32_t))(v16 + 4);
        *(uint8_t *)(v16 + 16) = 0;
        if ( v14 )
          v14(*(uint32_t *)(v16 + 8));
        a1 = timer_is_past(v11);
        break;
      case 3:
        a1 = task_queue_handler_b();
        break;
    }
  }
  if ( *((uint8_t *)off_117014 + 192) )
  {
    v15 = off_117018;
    if ( *((uint8_t *)off_117018 + 33) )
    {
      result = irq_disable_set_flag_3(*((uint32_t *)off_117018 + 4), *((uint32_t *)off_117018 + 5), *((uint32_t *)off_117018 + 6));
      v15[5] = 0;
      v15[7] = 0;
      v15[4] = 0;
      v15[6] = 0;
      *((uint8_t *)v15 + 33) = 0;
    }
  }
  *(uint32_t *)off_11701C |= 0x10000u;
  return result;
}

