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


extern uint32_t dword_11E040;
extern uint32_t off_11E014;
extern uint32_t off_11E018;
extern uint32_t off_11E01C;
extern uint32_t off_11E024;
extern uint32_t off_11E028;
extern uint32_t off_11E02C;
extern uint32_t off_11E034;
extern uint32_t off_11E038;
extern uint32_t off_11E03C;
extern uint32_t off_11E044;
extern uint32_t off_11E048;

// rf_hw_init @ 0x11deb0, size 356 bytes
int  rf_hw_init(int a1)
{
  uint32_t *v1; // r7
  int *v2; // r9
  int v3; // r8
  uint32_t *v4; // r11
  uint32_t *v5; // r10
  int i; // r5
  int v8; // r2
  BOOL v9; // r0
  int v10; // r3
  unsigned int v11; // r4
  int result; // r0
  void ( *v13)(uint32_t); // r2
  BOOL v14; // r0
  uint32_t *v15; // r5
  int v16; // [sp+14h] [bp-8h]

  v1 = off_11E014;
  v2 = (int *)off_11E034;
  v3 = dword_11E040;
  v4 = off_11E044;
  v5 = off_11E048;
  for ( i = 0; ; ++i )
  {
    v11 = mac_irq_check();
    *v1 = 0x10000;
    result = set_system_flag_2(0x80000);
    if ( !v11 )
      break;
    if ( !a1 )
    {
      if ( *((uint8_t *)v2 + 192) )
      {
        if ( *(uint32_t *)off_11E018 > 0x80000u || i > 31 )
          return set_system_flag_1(0x80000);
      }
      else if ( i > 3 )
      {
        return set_system_flag_1(0x80000);
      }
    }
    if ( !state_ready_check() || !rf_is_channel_idle() )
    {
      *((uint8_t *)off_11E02C + 69) = 1;
      v14 = rf_is_channel_idle();
      return state_check_feature(1024, "no host buffer:%d\r\n", !v14);
    }
    v8 = *(uint32_t *)(v11 + 20);
    if ( v8 != v3 )
      ke_event_schedule_1(
        "rxbuf1 %08x,%08x: start %08x, end %08x, read %08x, wrptr %08x, rdptr %08x\r\n",
        v11,
        v8,
        *(uint32_t *)off_11E01C,
        *((uint32_t *)off_11E01C + 1),
        *((uint32_t *)off_11E01C + 2),
        *v4,
        *v5);
    rx_timeout_check(v11);
    v9 = rx_process_packet(v11);
    if ( v9 )
    {
      if ( !v9 )
        goto LABEL_10;
    }
    else if ( rf_cal_check_band(v11) )
    {
      goto LABEL_10;
    }
    tx_packet_finish(v11);
LABEL_10:
    v10 = **(uint8_t **)off_11E024;
    switch ( v10 )
    {
      case 2:
        goto LABEL_22;
      case 4:
        if ( !*(uint32_t *)off_11E028 || *(uint32_t *)(*(uint32_t *)off_11E028 + 12) != v11 || (*(uint8_t *)(v11 + 16) & 1) == 0 )
        {
LABEL_22:
          rf_wait_idle();
          continue;
        }
        v16 = *(uint32_t *)off_11E028;
        list_pop_front(off_11E028);
        v13 = *(void ( **)(uint32_t))(v16 + 4);
        *(uint8_t *)(v16 + 16) = 0;
        if ( v13 )
          v13(*(uint32_t *)(v16 + 8));
        rf_tx_timestamp_check(v11);
        break;
      case 3:
        tx_unlock();
        break;
    }
  }
  if ( LOBYTE(((uint32_t *)(uintptr_t)off_11E034)[48]) )
  {
    v15 = off_11E038;
    if ( *((uint8_t *)off_11E038 + 33) )
    {
      result = ke_int_lock(*((uint32_t *)off_11E038 + 4), *((uint32_t *)off_11E038 + 5), *((uint32_t *)off_11E038 + 6));
      v15[5] = 0;
      v15[7] = 0;
      v15[4] = 0;
      v15[6] = 0;
      *((uint8_t *)v15 + 33) = 0;
    }
  }
  *(uint32_t *)off_11E03C |= 0x10000u;
  return result;
}
