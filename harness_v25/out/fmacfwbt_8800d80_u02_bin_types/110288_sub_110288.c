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

extern uint32_t off_1102CC;

// sub_110288 @ 0x110288, size 62 bytes
// Doc: log_free_dispatch_n444 [util]: Dispatches log buffer free request variant n444
// log_free_dispatch_n444 [util]: Dispatches log buffer free request variant n444
int sub_110288()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)log_free_dispatch_n468 = 1;
  }
  v0 = (int *)off_1102CC;
  v1 = log_free_dispatch_02d0;
  ++*(uint32_t *)off_1102CC;
  result = list_push_tail(v1);
  v3 = *v0;
  ++*(uint32_t *)log_free_dispatch_n474;
  if ( v3 )
  {
    v4 = v3 - 1;
    v5 = *(uint32_t *)log_free_dispatch_n468;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  return result;
}

