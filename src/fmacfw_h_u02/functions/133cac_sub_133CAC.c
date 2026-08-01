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

extern uint32_t off_133D48;
extern uint32_t off_133D4C;
extern uint32_t off_133D50;
extern uint32_t dword_133D54;

// bt_parse_packet @ 0x133cac, size 154 bytes
int  bt_parse_packet(int a1, uint16_t *a2)
{
  int v3; // r6
  int *v4; // r4
  int v5; // r0
  int v6; // r4
  int v8; // r3
  int v9; // r2
  int v10; // r3
  int v11; // r2

  v3 = *((uint8_t *)a2 + 2);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_133D48 = 1;
  }
  v4 = (int *)off_133D4C;
  ++*(uint32_t *)off_133D4C;
  if ( hci_cmd_handler(6u) || *((uint8_t *)off_133D50 + 14) && rf_get_state(6155, 6) )
  {
    if ( *v4 )
    {
      v10 = *v4 - 1;
      v11 = *(uint32_t *)off_133D48;
      *v4 = v10;
      if ( !v10 )
      {
        if ( v11 )
          __enable_irq();
      }
    }
    return 2;
  }
  else
  {
    if ( *v4 )
    {
      v8 = *v4 - 1;
      v9 = *(uint32_t *)off_133D48;
      *v4 = v8;
      if ( !v8 )
      {
        if ( v9 )
          __enable_irq();
      }
    }
    v5 = dword_133D54 + 1320 * v3;
    v6 = *(uint8_t *)(v5 + 106);
    if ( !*(uint8_t *)(v5 + 106) && *(uint8_t *)(v5 + 108) )
    {
      ke_timer_set(v5, *a2, 1);
      return v6;
    }
    else
    {
      mac_write_header_word(6148, 13, 6);
      return 0;
    }
  }
}

