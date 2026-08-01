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

extern uint32_t dword_13613C;
extern uint32_t dword_136138;
extern uint32_t dword_136140;
extern uint32_t off_136144;
extern uint32_t off_136148;
extern uint32_t off_13614C;
extern uint32_t off_136150;

// ipc_register_handler @ 0x1360a4, size 148 bytes
int  ipc_register_handler(int a1, uint8_t *a2, int16_t a3, int16_t a4)
{
  int16_t v6; // r2
  int v7; // r0
  int value; // r0
  uint32_t *v10; // r1
  uint32_t *v11; // r4
  int v12; // r6
  int v13; // r0
  unsigned int v14; // r3
  int *v15; // r3
  int v16; // r3

  event_dispatch(dword_13613C, dword_136138);
  v6 = a3;
  v7 = dword_136140 + 1320 * *a2;
  if ( *(uint8_t *)(v7 + 106) == 2 && !*(uint8_t *)(v7 + 108) )
  {
    value = rx_rate_field_parse(7u);
    v6 = a3;
    if ( !value )
    {
      sta_get_by_index(*a2);
      *(uint8_t *)off_136144 = 0;
      v6 = a3;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_136148 = 1;
      }
      v10 = off_13614C;
      v11 = off_136150;
      v12 = *(uint32_t *)off_13614C;
      v13 = *(uint32_t *)off_13614C + 1;
      v14 = *((uint32_t *)off_136150 + 1) & 0xFFFFFFEF;
      *(uint32_t *)off_13614C = v13;
      v11[1] = v14;
      if ( v13 )
      {
        v15 = (int *)off_136148;
        *v10 = v12;
        v16 = *v15;
        if ( !v12 )
        {
          if ( v16 )
            __enable_irq();
        }
      }
    }
  }
  ke_msg_send_no_param(7175, a4, v6);
  return 0;
}

