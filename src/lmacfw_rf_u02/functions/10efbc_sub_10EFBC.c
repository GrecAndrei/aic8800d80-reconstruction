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

extern uint32_t off_10F004;
extern uint32_t off_10F008;
extern uint32_t off_10F00C;

// critical_enter @ 0x10efbc, size 70 bytes
int  critical_enter(int a1, int a2)
{
  int *v2; // r5
  uint32_t *v3; // r4
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_10F004 = 1;
  }
  v2 = (int *)off_10F008;
  ++*(uint32_t *)off_10F008;
  if ( a2 )
  {
    v3 = off_10F00C;
    while ( !*(uint32_t *)off_10F00C )
      ;
    result = call_indirect_table();
    *v3 = 1;
  }
  else
  {
    result = call_indirect_table();
  }
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(uint32_t *)off_10F004;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}

