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

extern uint32_t dword_110478;

// is_sniff_mode @ 0x110430, size 62 bytes
// Doc: log_free_dispatch_n464 [util]: Free a log buffer entry and dispatch log processing
// log_free_dispatch_n464 [util]: Free a log buffer entry and dispatch log processing
int is_sniff_mode()
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
  v0 = (int *)log_free_dispatch_n46c;
  v1 = dword_110478;
  ++*(uint32_t *)log_free_dispatch_n46c;
  result = cmd_handler_a(v1);
  v3 = *v0;
  ++*(uint32_t *)log_free_dispatch_n474_047c;
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

