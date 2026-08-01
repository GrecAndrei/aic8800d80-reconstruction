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

extern uint32_t off_115CF8;
extern uint32_t off_115CFC;
extern uint32_t off_115D1C;
extern uint32_t off_115D20;
extern uint32_t dword_115D48;
extern uint32_t off_115D24;
extern uint32_t dword_115D4C;
extern uint32_t off_115D28;
extern uint32_t off_115D2C;
extern uint32_t dword_115D54;
extern uint32_t off_115D30;
extern uint32_t off_115D08;
extern uint32_t dword_115D38;
extern uint32_t off_115D34;
extern uint32_t off_115D3C;
extern uint32_t off_115D14;
extern uint32_t off_115D00;
extern uint32_t off_115D04;
extern uint32_t dword_115D18;
extern uint32_t dword_115D5C;
extern uint32_t dword_115D50;
extern uint32_t off_115D0C;
extern uint32_t off_115D10;
extern uint32_t dword_115D58;

// clear_rx_config @ 0x115ae4, size 532 bytes
// Doc: gpio_read_input [ipc]: IPC doorbell interrupt handler that processes incoming doorbell messages and dispatches IPC events.
// gpio_read_input [ipc]: IPC doorbell interrupt handler that processes incoming doorbell messages and dispatches IPC events.
int  clear_rx_config(int result)
{
  uint8_t **v1; // r5
  uint8_t **v2; // r6
  int v3; // r3
  int *v4; // r3
  uint8_t *v5; // r4
  int v6; // r3
  int v7; // r1
  void *v8; // r2
  char v9; // r0
  int v10; // r1
  void *v11; // r2
  int v12; // r0

  if ( *(uint8_t *)off_115CF8 && (*((uint32_t *)off_115CFC + 4) & 0xFFFF00) == 0x10000 )
  {
    v6 = *(uint8_t *)off_115D1C;
    *(uint8_t *)off_115D20 = 0;
    if ( v6 )
      return check_status_bits(2, dword_115D48);
    if ( !*(uint8_t *)off_115D24 )
      return check_status_bits(2, dword_115D4C);
    if ( *(uint32_t *)off_115D28 && *(uint32_t *)(*(uint32_t *)off_115D28 + 12) - *((uint32_t *)off_115D2C + 4) - 5000 < 0 )
      return check_status_bits(2, dword_115D54);
    if ( !*(uint8_t *)off_115D30
      && !*((uint32_t *)off_115D08 + 126)
      && ((dword_115D38 & *(uint32_t *)off_115D34) == 0 || (unsigned int)(32 * *(uint32_t *)off_115D3C) > 0x1387) )
    {
      ((void (*)(void))ipc_wait_flag)();
      while ( 1 )
        ;
    }
    return result;
  }
  if ( *((uint8_t *)off_115CFC + 18) )
  {
    v5 = off_115D14;
    goto LABEL_23;
  }
  v1 = (uint8_t **)off_115D00;
  if ( **(uint8_t **)off_115D00 )
  {
    v2 = (uint8_t **)off_115D04;
    goto LABEL_6;
  }
  v4 = *((int **)off_115CFC + 2);
  v5 = off_115D14;
  *(uint8_t *)off_115D14 = 1;
  if ( !v4 )
  {
LABEL_38:
    v2 = (uint8_t **)off_115D04;
    if ( **(uint8_t **)off_115D04 == 3 )
      goto LABEL_8;
    result = check_status_bits(2, dword_115D18);
    *v5 = 1;
LABEL_6:
    v3 = **v2;
    if ( v3 == 1 )
    {
      if ( **v1 == 3 )
      {
        v9 = rf_read_status_bit();
        v11 = off_115D20;
        *(uint8_t *)off_115D20 = v9;
        if ( v9 )
          event_dispatch(dword_115D5C, v10, v11);
        else
          event_dispatch(dword_115D50, v10, v11);
        if ( get_status_flag() )
          gpio_read_input();
        return ((int (*)(void))ipc_wait_flag)();
      }
      result = get_status_flag();
      if ( !result || *(uint8_t *)off_115D30 )
        return result;
    }
    else if ( v3 == 2 )
    {
      return result;
    }
LABEL_8:
    result = wlc_bss_state(result);
    if ( result )
    {
      if ( !*((uint32_t *)off_115D08 + 126) )
      {
        if ( (*(uint32_t *)off_115D0C >> 25) & 1 | *((uint8_t *)off_115D10 + 36) )
        {
          if ( !*((uint8_t *)off_115D10 + 29) )
          {
            result = rf_read_irq_flags();
            if ( result )
            {
              LOBYTE(result) = rf_read_status_bit();
              v8 = off_115D20;
              result = (uint8_t)result;
              *(uint8_t *)off_115D20 = result;
              if ( !(uint8_t)result )
              {
                v12 = event_dispatch(dword_115D58, v7, v8);
                result = ipc_wait_flag(v12);
              }
              if ( (uint8_t)**v1 <= 1u )
                return (int)gpio_read_input();
            }
          }
        }
      }
    }
    return result;
  }
  while ( !*((uint8_t *)v4 + 106) )
  {
    if ( *((uint8_t *)v4 + 108) )
      goto LABEL_20;
LABEL_17:
    v4 = (int *)*v4;
    if ( !v4 )
      goto LABEL_38;
  }
  if ( *((uint8_t *)v4 + 106) != 2 )
    goto LABEL_17;
LABEL_20:
  if ( **(uint8_t **)off_115D04 != 3 )
    result = check_status_bits(2, dword_115D18);
LABEL_23:
  *v5 = 0;
  return result;
}

