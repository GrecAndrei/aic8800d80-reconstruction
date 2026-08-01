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
extern uint32_t dword_12F464;
extern uint32_t off_12F468;

// bad_func_0x12f408 @ 0x12f408, size 82 bytes
int  bad_func_0x12f408(int a1, int a2, int a3)
{
  int *v4; // r4
  int v5; // r0
  int result; // r0
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12F45C = 1;
  }
  v4 = (int *)off_12F460;
  v5 = dword_12F464;
  ++*(uint32_t *)off_12F460;
  result = event_dispatch(v5, a1, a2, a3 & 0xFFFFF);
  if ( *(int *)off_12F468 >= 0 )
  {
    mmio_clear_irqs();
    result = unknown_func_12d104(0x80000000);
  }
  if ( *v4 )
  {
    v7 = *v4 - 1;
    v8 = *(uint32_t *)off_12F45C;
    *v4 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}

