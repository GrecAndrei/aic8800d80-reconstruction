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


extern uint32_t off_12C1CC;
extern uint32_t off_12C1D0;
extern uint32_t off_12C1D4;
extern uint32_t off_12C1D8;
extern uint32_t off_12C1DC;
extern uint32_t off_12C1E0;
extern uint32_t off_12C1F8;
extern uint32_t off_12C1FC;

// power_state_read @ 0x12c0b4, size 280 bytes
int power_state_read()
{
  int v0; // r4
  int result; // r0
  int *v2; // r4
  int v3; // r1

  v0 = *(uint32_t *)off_12C1CC;
  *(uint32_t *)off_12C1D0 = *(uint32_t *)off_12C1CC;
  result = v0 << 21;
  if ( (v0 & 0x400) != 0 )
  {
    ke_event_schedule_1(aErrorThereIsNo_0);
    while ( 1 )
      ;
  }
  if ( (v0 & 0x100) == 0 )
  {
    if ( (v0 & 0x200) == 0 )
      goto LABEL_4;
LABEL_13:
    ke_event_schedule_1(aErrorThereIsNo);
    while ( 1 )
      ;
  }
  result = seq_count_restart();
  if ( (v0 & 0x200) != 0 )
    goto LABEL_13;
LABEL_4:
  if ( (v0 & 0x10) != 0 )
  {
    mmio_set_bit(4);
    result = conn_get(4u);
  }
  if ( (v0 & 0x2F) != 0 )
  {
    if ( *(uint8_t *)off_12C1D4 )
    {
      v2 = (int *)off_12C1F8;
      write_mmio_byte(HIBYTE(((uint32_t *)(uintptr_t)off_12C1F8)[102]));
      v3 = *((char *)v2 + 411);
      *((uint8_t *)off_12C1FC + 9) = v3;
      return ke_event_schedule_1("update:%d\n", v3);
    }
    if ( *(uint8_t *)off_12C1D8 )
    {
      result = *(uint32_t *)off_12C1DC << 28;
      if ( result )
        *((uint8_t *)off_12C1D8 + 6) = 1;
    }
  }
  if ( **(uint16_t **)off_12C1E0 < 0 )
  {
    if ( (v0 & 1) != 0 )
    {
      return ke_int_lock_1((int)aTimerPendingHa_0, (int)aHalMachwAbsTim, 760);
    }
    else if ( (v0 & 2) != 0 )
    {
      return ke_int_lock_1((int)aTimerPendingHa_5, (int)aHalMachwAbsTim, 761);
    }
    else if ( (v0 & 4) != 0 )
    {
      return ke_int_lock_1((int)aTimerPendingHa_4, (int)aHalMachwAbsTim, 762);
    }
    else
    {
      result = v0 << 28;
      if ( (v0 & 8) != 0 )
      {
        return ke_int_lock_1((int)aTimerPendingHa_3, (int)aHalMachwAbsTim, 763);
      }
      else if ( (v0 & 0x80) != 0 )
      {
        return ke_int_lock_1((int)aTimerPendingHa_2, (int)aHalMachwAbsTim, 765);
      }
      else if ( (v0 & 0x40) != 0 )
      {
        return ke_int_lock_1((int)aTimerPendingHa_1, (int)aHalMachwAbsTim, 767);
      }
      else if ( (v0 & 0x20) != 0 )
      {
        return ke_int_lock_1((int)aTimerPendingHa, (int)aHalMachwAbsTim, 769);
      }
    }
  }
  return result;
}
