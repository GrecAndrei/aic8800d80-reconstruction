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


extern uint32_t dword_115CF8;
extern uint32_t dword_115CFC;
extern uint32_t dword_115D00;
extern uint32_t dword_115D04;
extern uint32_t dword_115D08;
extern uint32_t dword_115D0C;
extern uint32_t dword_115D10;
extern uint32_t dword_115D14;
extern uint32_t dword_115D1C;
extern uint32_t dword_115D20;
extern uint32_t dword_115D24;
extern uint32_t dword_115D28;
extern uint32_t dword_115D30;
extern uint32_t dword_115D34;
extern uint32_t dword_115D38;
extern uint32_t dword_115D3C;
extern uint32_t dword_115D40;

// clear_rx_config @ 0x115ae4, size 532 bytes
void  clear_rx_config(int result)
{
  uint8_t **v1; // r5
  uint8_t *v2; // r1
  uint8_t **v3; // r6
  int v4; // r3
  int *v5; // r3
  uint8_t *v6; // r4
  uint8_t *v7; // r4
  int v8; // r3
  volatile unsigned int v9; // r2
  volatile unsigned int v10; // r1
  unsigned int v11; // r1
  int v12; // r3
  unsigned int v13; // r2
  char v14; // r0
  char v15; // r0
  char v16; // r0

  if ( !*(uint8_t *)dword_115CF8 || (*(uint32_t *)(dword_115CFC + 0x10) & 0xFFFF00) != 0x10000 )
  {
    if ( *(uint8_t *)(dword_115CFC + 0x12) )
    {
      v6 = (uint8_t *)dword_115D14;
      goto LABEL_23;
    }
    v1 = (uint8_t **)dword_115D00;
    v2 = *(uint8_t **)dword_115D00;
    if ( **(uint8_t **)dword_115D00 )
    {
      v3 = (uint8_t **)dword_115D04;
    }
    else
    {
      v5 = *(int **)(dword_115CFC + 8);
      v6 = (uint8_t *)dword_115D14;
      *(uint8_t *)dword_115D14 = 1;
      while ( v5 )
      {
        if ( *((uint8_t *)v5 + 106) )
        {
          if ( *((uint8_t *)v5 + 106) == 2 )
          {
LABEL_20:
            if ( **(uint8_t **)dword_115D04 != 3 )
              check_status_bits(2, "lp=%d, ignore=%d\n", *v2, 0);
LABEL_23:
            *v6 = 0;
            return;
          }
        }
        else if ( *((uint8_t *)v5 + 108) )
        {
          goto LABEL_20;
        }
        v5 = (int *)*v5;
      }
      v3 = (uint8_t **)dword_115D04;
      if ( **(uint8_t **)dword_115D04 == 3 )
        goto LABEL_8;
      check_status_bits(2, "lp=%d, ignore=%d\n", *v2, 1);
      *v6 = 1;
    }
    v4 = **v3;
    if ( v4 == 1 )
    {
      if ( **v1 == 3 )
      {
        v15 = rf_read_status_bit();
        *(uint8_t *)dword_115D20 = v15;
        if ( v15 )
          event_dispatch(aWifiidleBtAllo);
        else
          event_dispatch(aWifiidleBtNotA);
        if ( get_status_flag() )
          gpio_read_input();
        ipc_wait_flag();
        return;
      }
      if ( !get_status_flag() || *(uint8_t *)dword_115D30 )
        return;
    }
    else if ( v4 == 2 )
    {
      return;
    }
LABEL_8:
    if ( !wlc_bss_state()
      || *(uint32_t *)(dword_115D08 + 0x1F8)
      || !((*(uint32_t *)dword_115D0C >> 25) & 1 | *(uint8_t *)(dword_115D10 + 0x24))
      || *(uint8_t *)(dword_115D10 + 0x1D)
      || !rf_read_irq_flags() )
    {
      return;
    }
    v14 = rf_read_status_bit();
    *(uint8_t *)dword_115D20 = v14;
    if ( !v14 )
    {
      event_dispatch(aBt1);
      ipc_wait_flag();
    }
    if ( (uint8_t)**v1 > 1u )
      return;
LABEL_46:
    gpio_read_input();
    return;
  }
  v7 = (uint8_t *)dword_115D20;
  v8 = *(uint8_t *)dword_115D1C;
  *(uint8_t *)dword_115D20 = 0;
  if ( v8 )
  {
    check_status_bits(2, aApPsForbid);
    return;
  }
  if ( !*(uint8_t *)dword_115D24 )
  {
    check_status_bits(2, aAa);
    return;
  }
  if ( *(uint32_t *)dword_115D28 )
  {
    v9 = (*(volatile uint32_t *)0x40501010u);
    if ( (int)(*(uint32_t *)(*(uint32_t *)dword_115D28 + 12) - v9 - 5000) < 0 )
    {
      check_status_bits(2, aMm);
      return;
    }
  }
  if ( !*(uint8_t *)dword_115D30
    && !*(uint32_t *)(dword_115D08 + 0x1F8)
    && ((dword_115D38 & *(uint32_t *)dword_115D34) == 0 || (unsigned int)(32 * *(uint32_t *)dword_115D3C) > 0x1387) )
  {
    ipc_wait_flag();
    v10 = (*(volatile uint32_t *)0x40501010u);
    v11 = v10 + 28;
    do
      v12 = v11 - (*(volatile uint32_t *)0x40501010u);
    while ( v12 >= 0 );
    if ( **(uint8_t **)dword_115D04 == 1 )
    {
      v16 = rf_read_status_bit();
      *v7 = v16;
      if ( !v16 )
      {
        check_status_bits(2, aWifiidleBtNotA);
        return;
      }
    }
    v13 = dword_115D40;
    *(uint8_t *)dword_115D14 = 1;
    *(uint32_t *)(v13 + 0x38) |= 0x10u;
    if ( !get_status_flag() )
    {
      check_status_bits(2, aSdioNotAllowed);
      return;
    }
    goto LABEL_46;
  }
}
