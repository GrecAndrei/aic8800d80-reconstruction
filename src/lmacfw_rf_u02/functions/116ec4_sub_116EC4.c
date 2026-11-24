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


extern uint32_t dword_117020;
extern uint32_t off_116FFC;
extern uint32_t off_117000;
extern uint32_t off_117004;
extern uint32_t off_11700C;
extern uint32_t off_117010;
extern uint32_t off_117014;
extern uint32_t off_117018;
extern uint32_t off_11701C;
extern uint32_t off_117024;
extern uint32_t off_117028;

// mmio_regs_init @ 0x116ec4, size 312 bytes
int  mmio_regs_init(int a1)
{
  uint32_t *v1; // r7
  int *v2; // r9
  int v3; // r8
  uint32_t *v4; // r11
  uint32_t *v5; // r10
  int i; // r5
  int result; // r0
  int v9; // r2
  int v10; // r0
  int v11; // r3
  unsigned int v12; // r4
  void ( *v13)(uint32_t); // r2
  uint32_t *v14; // r5
  int v15; // [sp+14h] [bp-8h]

  v1 = off_116FFC;
  v2 = off_117014;
  v3 = dword_117020;
  v4 = off_117024;
  v5 = off_117028;
  for ( i = 0; ; ++i )
  {
    v12 = timer_event_check();
    *v1 = 0x10000;
    result = enter_critical_section_1(0x400000);
    if ( !v12 )
      break;
    if ( !a1 )
    {
      if ( *((uint8_t *)v2 + 192) )
      {
        if ( *(uint32_t *)off_117000 > 0x400000u || i > 31 )
          return set_busy_flag_alt(0x400000);
      }
      else if ( i > 3 )
      {
        return set_busy_flag_alt(0x400000);
      }
    }
    result = patch_check_enabled();
    if ( !result )
      return result;
    v9 = *(uint32_t *)(v12 + 20);
    if ( v9 != v3 )
      dispatch_event_handler_1(
        "rxbuf1 %08x,%08x: start %08x, end %08x, read %08x, wrptr %08x, rdptr %08x\r\n",
        v12,
        v9,
        *(uint32_t *)off_117004,
        *((uint32_t *)off_117004 + 1),
        *((uint32_t *)off_117004 + 2),
        *v4,
        *v5);
    rf_cal_offset_apply(v12);
    v10 = wlan_rx_process(v12);
    if ( v10 )
    {
      if ( v10 == 1 )
        ll_event_timer_handler(v12);
    }
    else
    {
      tx_acl_queue_process(v12);
    }
    v11 = **(uint8_t **)off_11700C;
    switch ( v11 )
    {
      case 2:
LABEL_22:
        task_queue_handler_c();
        continue;
      case 4:
        if ( !*(uint32_t *)off_117010 || *(uint32_t *)(*(uint32_t *)off_117010 + 12) != v12 || (*(uint8_t *)(v12 + 16) & 1) == 0 )
          goto LABEL_22;
        v15 = *(uint32_t *)off_117010;
        list_pop_front(off_117010);
        v13 = *(void ( **)(uint32_t))(v15 + 4);
        *(uint8_t *)(v15 + 16) = 0;
        if ( v13 )
          v13(*(uint32_t *)(v15 + 8));
        timer_is_past(v12);
        break;
      case 3:
        task_queue_handler_b();
        break;
    }
  }
  if ( *((uint8_t *)off_117014 + 192) )
  {
    v14 = off_117018;
    if ( *((uint8_t *)off_117018 + 33) )
    {
      result = irq_disable_set_flag_3(*((uint32_t *)off_117018 + 4), *((uint32_t *)off_117018 + 5), *((uint32_t *)off_117018 + 6));
      v14[5] = 0;
      v14[7] = 0;
      v14[4] = 0;
      v14[6] = 0;
      *((uint8_t *)v14 + 33) = 0;
    }
  }
  *(uint32_t *)off_11701C |= 0x10000u;
  return result;
}
