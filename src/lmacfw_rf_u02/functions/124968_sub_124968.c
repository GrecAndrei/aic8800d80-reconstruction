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


extern uint32_t off_1249E8;
extern uint32_t off_1249EC;
extern uint32_t off_1249F4;
extern uint32_t off_1249F8;
extern uint32_t off_1249FC;
extern uint32_t off_124A00;

// mmio_check_status @ 0x124968, size 128 bytes
int mmio_check_status()
{
  int *v0; // r6
  uint32_t *v1; // r4
  volatile unsigned int v2; // r7
  unsigned int v3; // r3
  int v4; // r1
  int v5; // r3
  int v6; // r2

  if ( *(uint32_t *)off_1249E8 << 28 )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_124A00 = 1;
    }
    v0 = (int *)off_1249EC;
    v1 = off_1249E8;
    ++*(uint32_t *)off_1249EC;
    *v1 = 0;
    v2 = (*(volatile uint32_t *)0x40501010u);
    while ( *v1 << 28 )
    {
      v3 = (*(volatile uint32_t *)0x40501010u) - v2;
      if ( v3 > 0x7530 )
        dispatch_event_handler_1(aIdleErr, *v1 << 28, 30000);
    }
    v4 = off_1249F8;
    while ( (*(uint32_t *)off_1249F8 & *(uint32_t *)off_1249F4 & 4) == 0 )
      ;
    *(uint32_t *)off_1249FC = 4;
    if ( *v0 )
    {
      v5 = *v0 - 1;
      v6 = *(uint32_t *)off_124A00;
      *v0 = v5;
      if ( !v5 )
      {
        if ( v6 )
          __enable_irq();
      }
    }
    dispatch_event_handler_1(aForceIdled, v4);
  }
  dispatch_event_handler_1(aRxStatStop);
  return 0;
}
