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


extern uint32_t off_124788;
extern uint32_t off_12478C;
extern uint32_t off_124790;
extern uint32_t off_124794;
extern uint32_t off_124798;
extern uint32_t off_12479C;

// rx_process_pending @ 0x1246f0, size 152 bytes
int  rx_process_pending(int a1, int a2)
{
  int v3; // r1
  unsigned int v4; // r2
  uint8_t *v5; // r6
  int *v6; // r5
  int v7; // r3
  int v8; // r2
  uint32_t *v9; // r5
  int v10; // r4

  if ( (*(uint32_t *)off_124788 & 2) != 0
    && ((v3 = *(uint8_t *)a2, v4 = *(uint16_t *)(a2 + 4), v3 == 1) || v4 > 0x1387) )
  {
    dispatch_event_handler_1("un-support band=%d, freq=%d\n", v3, v4);
    return -1;
  }
  else
  {
    v5 = (uint8_t *)off_12478C;
    if ( !*(uint8_t *)off_12478C )
    {
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_124790 = 1;
      }
      v6 = (int *)off_124794;
      ++*(uint32_t *)off_124794;
      rf_cmd_wait();
      rf_acquire();
      if ( *v6 )
      {
        v7 = *v6 - 1;
        v8 = *(uint32_t *)off_124790;
        *v6 = v7;
        if ( !v7 )
        {
          if ( v8 )
            __enable_irq();
        }
      }
    }
    v9 = off_12479C;
    ++*(uint8_t *)off_124798;
    *v9 |= 0x500000u;
    tx_set_power((uint8_t *)a2, 0);
    *v9 &= 0xFF87FFFF;
    v10 = (uint8_t)*v5;
    if ( *v5 )
    {
      return 0;
    }
    else
    {
      write_bb_control();
      util_alloc_buffer();
      return v10;
    }
  }
}
