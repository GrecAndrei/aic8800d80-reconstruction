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

extern uint32_t dword_11033C;

// is_inquiry_enabled @ 0x1102fc, size 54 bytes
// Doc: log_free_dispatch_n30a [util]: Increments free-counter and dispatches a log/free callback
// log_free_dispatch_n30a [util]: Increments free-counter and dispatches a log/free callback
int is_inquiry_enabled()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)crypto_hw_write32_core = 1;
  }
  v0 = (int *)log_free_dispatch_n330;
  v1 = dword_11033C;
  ++*(uint32_t *)log_free_dispatch_n330;
  result = cmd_handler_a(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)crypto_hw_write32_core;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

