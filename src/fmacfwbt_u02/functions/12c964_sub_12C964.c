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

extern uint32_t off_12CA04;
extern uint32_t dword_12CA1C;
extern uint32_t dword_12CA18;
extern uint32_t dword_12CA0C;
extern uint32_t dword_12CA08;

// irq_lock @ 0x12c964, size 152 bytes
// Doc: message_dispatch_n_1de [ipc]: Dispatch message and compare against timestamp at 0x40501000
// message_dispatch_n_1de [ipc]: Dispatch message and compare against timestamp at 0x40501000
int  irq_lock(int result, int a2)
{
  int *v2; // r5
  uint32_t *v3; // r6
  int v4; // r4
  int v5; // r3
  int v6; // r3
  int v7; // r2
  int v8; // r7
  int v9; // r0

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)message_dispatch_n_1b8_c9fc = 1;
  }
  v2 = (int *)message_dispatch_ca00;
  v3 = off_12CA04;
  v4 = *((uint32_t *)off_12CA04 + 5);
  v5 = *(uint32_t *)message_dispatch_ca00 + 1;
  *(uint32_t *)message_dispatch_ca00 = v5;
  if ( v4 )
  {
    if ( *(uint16_t *)(v4 + 4) == result && *(uint16_t *)(v4 + 6) == a2 )
    {
      list_pop_front(v3 + 5);
      v8 = v3[5];
      v9 = (int)(v3 + 8);
      if ( v8 )
      {
        ke_event_lock(v9, *(uint32_t *)(v8 + 8));
        if ( **(int16_t **)message_dispatch_n_1a4_ca10 < 0
          && *(uint32_t *)(v8 + 8) - *((uint32_t *)message_dispatch_n_1a0_ca14 + 4) < 0 )
        {
          mmio_irq_clear(dword_12CA1C, dword_12CA18, 232);
        }
      }
      else
      {
        ke_event_set_lock(v9);
      }
    }
    else
    {
      result = tx_list_foreach(dword_12CA0C, dword_12CA08, a2 | (result << 16));
      v4 = result;
      if ( !result )
      {
        v5 = *v2;
        goto LABEL_8;
      }
    }
    result = hci_tx_packet(v4);
    v5 = *v2;
  }
LABEL_8:
  if ( v5 )
  {
    v6 = v5 - 1;
    v7 = *(uint32_t *)message_dispatch_n_1b8_c9fc;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}

