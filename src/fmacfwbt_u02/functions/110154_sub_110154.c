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

extern uint32_t off_11018C;
extern uint32_t dword_110194;

// critical_enter_1 @ 0x110154, size 54 bytes
// Doc: log_free_dispatch_n31e [util]: Dispatch log buffer free and load next entry header
// log_free_dispatch_n31e [util]: Dispatch log buffer free and load next entry header
int critical_enter_1()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11018C = 1;
  }
  v0 = (int *)log_free_dispatch_n330;
  v1 = dword_110194;
  ++*(uint32_t *)log_free_dispatch_n330;
  result = check_abort_flag(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_11018C;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

