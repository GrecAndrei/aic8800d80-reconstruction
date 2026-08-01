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

extern uint32_t dword_125D00;
extern uint32_t dword_125D0C;
extern uint32_t dword_125D14;
extern uint32_t dword_125D10;
extern uint32_t dword_125D04;
extern uint32_t dword_125D08;

// process_bt_ble_event @ 0x125bfc, size 258 bytes
// Doc: process_bt_ble_event [ipc]: Handles IPC message with payload parsing
// process_bt_ble_event [ipc]: Handles IPC message with payload parsing
int  process_bt_ble_event(int a1, uint8_t **a2)
{
  int v4; // r8
  int v5; // r4
  int v6; // r5
  int v7; // r6
  BOOL v9; // r0
  BOOL v10; // r0

  v4 = (*a2)[4];
  v5 = parse_number(a2[1], 0, 0);
  v6 = parse_number(a2[2], 0, 0);
  if ( v6 )
  {
    if ( a1 <= 3 )
      return -1;
    v7 = parse_number(a2[3], 0, 0);
    if ( v4 == 97 )
      goto LABEL_4;
  }
  else
  {
    v7 = 0;
    if ( v4 == 97 )
    {
LABEL_4:
      if ( v5 <= 15 )
      {
        rf_channel_valid(v5);
        if ( v6 )
        {
          gpio_cfg_set(v5);
          if ( v7 )
            gpio_out_set(v5);
          else
            gpio_out_clear(v5);
          dispatch_event_handler(dword_125D00, v5, v7);
          return 0;
        }
        else
        {
          gpio_cfg_clear(v5);
          v10 = gpio_read_pin(v5);
          dispatch_event_handler(dword_125D0C, v5, v10);
          return 0;
        }
      }
      dispatch_event_handler(dword_125D14, v5);
      return -2;
    }
  }
  if ( v5 > 15 )
  {
    dispatch_event_handler(dword_125D10, v5);
    return -2;
  }
  pinmux_config(v5);
  if ( !v6 )
  {
    gpio_disable_interrupt(v5);
    v9 = gpio_get_pin(v5);
    dispatch_event_handler(dword_125D04, v5, v9);
    return v6;
  }
  gpio_set_pin(v5);
  if ( v7 )
    gpio_set_pin_out(v5);
  else
    gpio_clear_pin(v5);
  dispatch_event_handler(dword_125D08, v5, v7);
  return 0;
}

