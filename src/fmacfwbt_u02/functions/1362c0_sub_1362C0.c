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

extern uint32_t dword_136354;
extern uint32_t dword_136350;
extern uint32_t dword_136358;
extern uint32_t off_13635C;
extern uint32_t off_136360;
extern uint32_t off_136364;

// tx_send_packet @ 0x1362c0, size 142 bytes
int  tx_send_packet(int a1, uint8_t *a2, int16_t a3, int16_t a4)
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

  ke_event_schedule(dword_136354, dword_136350);
  v6 = a3;
  v7 = dword_136358 + 1320 * *a2;
  if ( *(uint8_t *)(v7 + 106) == 2 && !*(uint8_t *)(v7 + 108) )
  {
    value = hci_cmd_send_short(7u);
    v6 = a3;
    if ( !value )
    {
      get_entry_by_index(*a2);
      v6 = a3;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_13635C = 1;
      }
      v10 = off_136360;
      v11 = off_136364;
      v12 = *(uint32_t *)off_136360;
      v13 = *(uint32_t *)off_136360 + 1;
      v14 = *((uint32_t *)off_136364 + 1) & 0xFFFFFFEF;
      *(uint32_t *)off_136360 = v13;
      v11[1] = v14;
      if ( v13 )
      {
        v15 = (int *)off_13635C;
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
  hci_evt_alloc_send(7175, a4, v6);
  return 0;
}

