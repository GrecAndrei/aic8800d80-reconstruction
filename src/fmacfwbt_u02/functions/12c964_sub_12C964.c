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


extern uint32_t dword_12CA0C;
extern uint32_t off_12C9FC;
extern uint32_t off_12CA00;
extern uint32_t off_12CA04;
extern uint32_t off_12CA08;
extern uint32_t off_12CA10;

// irq_lock @ 0x12c964, size 152 bytes
char * irq_lock(char *result, int a2)
{
  int *v2; // r5
  uint32_t *v3; // r6
  char *v4; // r4
  int v5; // r3
  int v6; // r3
  int v7; // r2
  int v8; // r7
  uint32_t *v9; // r0
  volatile unsigned int v10; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12C9FC = 1;
  }
  v2 = (int *)off_12CA00;
  v3 = off_12CA04;
  v4 = *((char **)off_12CA04 + 5);
  v5 = *(uint32_t *)off_12CA00 + 1;
  *(uint32_t *)off_12CA00 = v5;
  if ( v4 )
  {
    if ( (char *)*((uint16_t *)v4 + 2) == result && *((uint16_t *)v4 + 3) == a2 )
    {
      list_pop_front((int)(v3 + 5));
      v8 = v3[5];
      v9 = v3 + 8;
      if ( v8 )
      {
        ke_event_lock(v9, *(uint32_t *)(v8 + 8));
        if ( **(uint16_t **)off_12CA10 < 0 )
        {
          v10 = (*(volatile uint32_t *)0x40501010u);
          if ( (int)(*(uint32_t *)(v8 + 8) - v10) < 0 )
            mmio_irq_clear((int)aFirstHalMachwT, (int)aKeTimerClear, 232);
        }
      }
      else
      {
        ke_event_set_lock(v9);
      }
    }
    else
    {
      result = (char *)tx_list_foreach(
                         dword_12CA0C,
                         (int ( *)(uint32_t *, int))off_12CA08,
                         a2 | ((uint32_t)result << 16));
      v4 = result;
      if ( !result )
      {
        v5 = *v2;
        goto LABEL_8;
      }
    }
    result = (char *)hci_tx_packet(v4);
    v5 = *v2;
  }
LABEL_8:
  if ( v5 )
  {
    v6 = v5 - 1;
    v7 = *(uint32_t *)off_12C9FC;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}
