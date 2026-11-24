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


extern uint32_t off_12F45C;
extern uint32_t off_12F460;
extern uint32_t off_12F468;

// bad_func_0x12f408 @ 0x12f408, size 82 bytes
int  bad_func_0x12f408(int a1, int a2, int a3)
{
  int *v3; // r4
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12F45C = 1;
  }
  v3 = (int *)off_12F460;
  ++*(uint32_t *)off_12F460;
  result = event_dispatch("\x9BASSERT (%s) at %s:%d\n", (const char *)a1, (const char *)a2, a3 & 0xFFFFF);
  if ( *(int *)off_12F468 >= 0 )
  {
    mmio_clear_irqs();
    result = unknown_func_12d104(0x80000000);
  }
  if ( *v3 )
  {
    v5 = *v3 - 1;
    v6 = *(uint32_t *)off_12F45C;
    *v3 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}
