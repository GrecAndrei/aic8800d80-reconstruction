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

extern uint32_t off_110278;
extern uint32_t off_110284;

// critical_enter_4 @ 0x110238, size 62 bytes
// Doc: log_free_dispatch_0274 [util]: Dispatch and free log buffer entries
// log_free_dispatch_0274 [util]: Dispatch and free log buffer entries
int critical_enter_4()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_110278 = 1;
  }
  v0 = (int *)log_free_dispatch_n41c;
  v1 = log_free_dispatch_n420;
  ++*(uint32_t *)log_free_dispatch_n41c;
  result = list_pop_front(v1);
  if ( result )
    --*(uint32_t *)off_110284;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_110278;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

