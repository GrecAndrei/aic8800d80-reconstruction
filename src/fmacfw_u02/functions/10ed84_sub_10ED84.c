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

extern uint32_t off_10EDCC;
extern uint32_t off_10EDD0;
extern uint32_t off_10EDD4;

// mmio_read32 @ 0x10ed84, size 70 bytes
int  mmio_read32(int a1, int a2)
{
  int *v2; // r5
  uint32_t *v3; // r4
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_10EDCC = 1;
  }
  v2 = (int *)off_10EDD0;
  ++*(uint32_t *)off_10EDD0;
  if ( a2 )
  {
    v3 = off_10EDD4;
    while ( !*(uint32_t *)off_10EDD4 )
      ;
    result = call_ptr_1b0();
    *v3 = 1;
  }
  else
  {
    result = call_ptr_1b0();
  }
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(uint32_t *)off_10EDCC;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}

