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
extern uint32_t dword_1247A0;
extern uint32_t off_12478C;
extern uint32_t off_124790;
extern uint32_t off_124794;
extern uint32_t off_12479C;
extern uint32_t off_124798;

// rx_process_pending @ 0x1246f0, size 152 bytes
// Doc: rx_process_pending [rf]: Get current RF state value
// rx_process_pending [rf]: Get current RF state value
int  rx_process_pending(int a1, int a2)
{
  uint8_t *v3; // r6
  int *v4; // r5
  int v5; // r3
  int v6; // r2
  uint32_t *v7; // r5
  int v8; // r4

  if ( (*(uint32_t *)off_124788 & 2) != 0 && (*(uint8_t *)a2 == 1 || *(uint16_t *)(a2 + 4) > 0x1387u) )
  {
    dispatch_event_handler(dword_1247A0);
    return -1;
  }
  else
  {
    v3 = off_12478C;
    if ( !*(uint8_t *)off_12478C )
    {
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_124790 = 1;
      }
      v4 = (int *)off_124794;
      ++*(uint32_t *)off_124794;
      rf_cmd_wait();
      rf_acquire();
      if ( *v4 )
      {
        v5 = *v4 - 1;
        v6 = *(uint32_t *)off_124790;
        *v4 = v5;
        if ( !v5 )
        {
          if ( v6 )
            __enable_irq();
        }
      }
    }
    v7 = off_12479C;
    ++*(uint8_t *)off_124798;
    *v7 |= 0x500000u;
    tx_set_power((uint8_t *)a2, 0);
    *v7 &= 0xFF87FFFF;
    v8 = (uint8_t)*v3;
    if ( *v3 )
    {
      return 0;
    }
    else
    {
      write_bb_control();
      util_alloc_buffer();
      return v8;
    }
  }
}

