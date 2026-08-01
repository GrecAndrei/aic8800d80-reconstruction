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

extern uint32_t off_133E88;
extern uint32_t off_133E8C;
extern uint32_t off_133E90;
extern uint32_t dword_133E94;

// disable_interrupts_and_update @ 0x133dec, size 154 bytes
int  disable_interrupts_and_update(int a1, uint16_t *a2)
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
    *(uint32_t *)off_133E88 = 1;
  }
  v4 = (int *)off_133E8C;
  ++*(uint32_t *)off_133E8C;
  if ( rx_rate_field_parse(6u) || *((uint8_t *)off_133E90 + 14) && ke_task_find(6155, 6) )
  {
    if ( *v4 )
    {
      v10 = *v4 - 1;
      v11 = *(uint32_t *)off_133E88;
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
      v9 = *(uint32_t *)off_133E88;
      *v4 = v8;
      if ( !v8 )
      {
        if ( v9 )
          __enable_irq();
      }
    }
    v5 = dword_133E94 + 1320 * v3;
    v6 = *(uint8_t *)(v5 + 106);
    if ( !*(uint8_t *)(v5 + 106) && *(uint8_t *)(v5 + 108) )
    {
      bt_schedule_ack_timeout(v5, *a2, 1);
      return v6;
    }
    else
    {
      ke_msg_send_no_param(6148, 13, 6);
      return 0;
    }
  }
}

