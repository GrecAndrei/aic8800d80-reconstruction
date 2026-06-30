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

extern uint32_t off_1104B8;
extern uint32_t dword_1104BC;

// sub_110480 @ 0x110480, size 52 bytes
// Doc: log_free_dispatch_n48e [util]: Increment log free counter and invoke free callback
// log_free_dispatch_n48e [util]: Increment log free counter and invoke free callback
int sub_110480()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)log_free_dispatch_n4ac = 1;
  }
  v0 = (int *)off_1104B8;
  v1 = dword_1104BC;
  ++*(uint32_t *)off_1104B8;
  result = rf_bus_mark_n100_d2d0(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)log_free_dispatch_n4ac;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

