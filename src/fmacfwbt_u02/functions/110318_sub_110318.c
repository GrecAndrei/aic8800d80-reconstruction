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

// critical_enter_7 @ 0x110318, size 54 bytes
// Doc: log_free_dispatch_n4ec [util]: Dispatch free-list logging routine (variant 4ec)
// log_free_dispatch_n4ec [util]: Dispatch free-list logging routine (variant 4ec)
int critical_enter_7()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)log_free_dispatch_n4f0 = 1;
  }
  v0 = (int *)log_free_dispatch_n4f4;
  v1 = log_free_dispatch_0358;
  ++*(uint32_t *)log_free_dispatch_n4f4;
  result = check_abort_flag(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)log_free_dispatch_n4f0;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

