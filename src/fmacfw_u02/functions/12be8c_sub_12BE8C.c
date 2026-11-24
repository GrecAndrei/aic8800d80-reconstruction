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


extern uint32_t off_12BFA4;
extern uint32_t off_12BFA8;
extern uint32_t off_12BFAC;
extern uint32_t off_12BFB0;
extern uint32_t off_12BFB4;
extern uint32_t off_12BFB8;
extern uint32_t off_12BFD0;
extern uint32_t off_12BFD4;

// mmio_copy_reg @ 0x12be8c, size 280 bytes
int mmio_copy_reg()
{
  int v0; // r4
  int result; // r0
  int *v2; // r4
  int v3; // r1

  v0 = *(uint32_t *)off_12BFA4;
  *(uint32_t *)off_12BFA8 = *(uint32_t *)off_12BFA4;
  result = v0 << 21;
  if ( (v0 & 0x400) != 0 )
  {
    event_dispatch(aErrorThereIsNo_0);
    while ( 1 )
      ;
  }
  if ( (v0 & 0x100) == 0 )
  {
    if ( (v0 & 0x200) == 0 )
      goto LABEL_4;
LABEL_13:
    event_dispatch(aErrorThereIsNo);
    while ( 1 )
      ;
  }
  result = rf_counter_get();
  if ( (v0 & 0x200) != 0 )
    goto LABEL_13;
LABEL_4:
  if ( (v0 & 0x10) != 0 )
  {
    mmio_set_bit_1(4);
    result = phy_band_validate(4u);
  }
  if ( (v0 & 0x2F) != 0 )
  {
    if ( *(uint8_t *)off_12BFAC )
    {
      v2 = (int *)off_12BFD0;
      write_phy_config(HIBYTE(((uint32_t *)(uintptr_t)off_12BFD0)[102]));
      v3 = *((char *)v2 + 411);
      *((uint8_t *)off_12BFD4 + 9) = v3;
      return event_dispatch("update:%d\n", v3);
    }
    if ( *(uint8_t *)off_12BFB0 )
    {
      result = *(uint32_t *)off_12BFB4 << 28;
      if ( result )
        *((uint8_t *)off_12BFB0 + 6) = 1;
    }
  }
  if ( **(uint16_t **)off_12BFB8 < 0 )
  {
    if ( (v0 & 1) != 0 )
    {
      return bad_func_0x12f408((int)aTimerPendingHa_0, (int)aHalMachwAbsTim, 760);
    }
    else if ( (v0 & 2) != 0 )
    {
      return bad_func_0x12f408((int)aTimerPendingHa_5, (int)aHalMachwAbsTim, 761);
    }
    else if ( (v0 & 4) != 0 )
    {
      return bad_func_0x12f408((int)aTimerPendingHa_4, (int)aHalMachwAbsTim, 762);
    }
    else
    {
      result = v0 << 28;
      if ( (v0 & 8) != 0 )
      {
        return bad_func_0x12f408((int)aTimerPendingHa_3, (int)aHalMachwAbsTim, 763);
      }
      else if ( (v0 & 0x80) != 0 )
      {
        return bad_func_0x12f408((int)aTimerPendingHa_2, (int)aHalMachwAbsTim, 765);
      }
      else if ( (v0 & 0x40) != 0 )
      {
        return bad_func_0x12f408((int)aTimerPendingHa_1, (int)aHalMachwAbsTim, 767);
      }
      else if ( (v0 & 0x20) != 0 )
      {
        return bad_func_0x12f408((int)aTimerPendingHa, (int)aHalMachwAbsTim, 769);
      }
    }
  }
  return result;
}
