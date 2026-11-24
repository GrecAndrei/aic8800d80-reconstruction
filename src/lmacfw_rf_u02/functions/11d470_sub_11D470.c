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


extern uint32_t off_11D59C;
extern uint32_t off_11D5A0;
extern uint32_t off_11D5A4;
extern uint32_t off_11D5A8;
extern uint32_t off_11D5AC;
extern uint32_t off_11D5B0;
extern uint32_t off_11D5C0;
extern uint32_t off_11D5C4;

// rf_irq_handler_2 @ 0x11d470, size 298 bytes
int rf_irq_handler_2()
{
  int v0; // r4
  int result; // r0
  int *v2; // r4
  int v3; // r1

  v0 = *(uint32_t *)off_11D59C;
  *(uint32_t *)off_11D5A0 = *(uint32_t *)off_11D59C;
  if ( (v0 & 0x400) != 0 )
    rf_state_machine();
  result = v0 << 23;
  if ( (v0 & 0x100) != 0 )
    result = hw_timer_load();
  if ( (v0 & 0x200) != 0 )
  {
    dispatch_event_handler_1(aErrorThereIsNo, v0 << 22);
    while ( 1 )
      ;
  }
  if ( (v0 & 0x800) == 0 )
  {
    if ( (v0 & 0x10) == 0 )
      goto LABEL_8;
LABEL_23:
    mmio_irq_set(4);
    result = llm_pdu_tx_cfg(4u);
    if ( (v0 & 0x2F) == 0 )
      goto LABEL_13;
    goto LABEL_9;
  }
  result = set_busy_flag_alt(0x2000);
  if ( (v0 & 0x10) != 0 )
    goto LABEL_23;
LABEL_8:
  if ( (v0 & 0x2F) == 0 )
    goto LABEL_13;
LABEL_9:
  if ( *(uint8_t *)off_11D5A4 )
  {
    v2 = off_11D5C0;
    gpio_config(*((uint8_t *)off_11D5C0 + 411));
    v3 = *((char *)v2 + 411);
    *(uint8_t *)(off_11D5C4 + 9) = v3;
    return dispatch_event_handler_1("update:%d\n", v3);
  }
  if ( *(uint8_t *)off_11D5A8 )
  {
    result = *(uint32_t *)off_11D5AC << 28;
    if ( result )
      *((uint8_t *)off_11D5A8 + 6) = 1;
  }
LABEL_13:
  if ( **(uint16_t **)off_11D5B0 < 0 )
  {
    if ( (v0 & 1) != 0 )
    {
      return ke_int_lock_1((int)aTimerPendingHa_1, (int)aHalMachwAbsTim, 760);
    }
    else if ( (v0 & 2) != 0 )
    {
      return ke_int_lock_1((int)aTimerPendingHa_2, (int)aHalMachwAbsTim, 761);
    }
    else if ( (v0 & 4) != 0 )
    {
      return ke_int_lock_1((int)aTimerPendingHa_3, (int)aHalMachwAbsTim, 762);
    }
    else
    {
      result = v0 << 28;
      if ( (v0 & 8) != 0 )
      {
        return ke_int_lock_1((int)aTimerPendingHa_0, (int)aHalMachwAbsTim, 763);
      }
      else if ( (v0 & 0x80) != 0 )
      {
        return ke_int_lock_1((int)aTimerPendingHa_5, (int)aHalMachwAbsTim, 765);
      }
      else if ( (v0 & 0x40) != 0 )
      {
        return ke_int_lock_1((int)aTimerPendingHa_4, (int)aHalMachwAbsTim, 767);
      }
      else if ( (v0 & 0x20) != 0 )
      {
        return ke_int_lock_1((int)aTimerPendingHa, (int)aHalMachwAbsTim, 769);
      }
    }
  }
  return result;
}
