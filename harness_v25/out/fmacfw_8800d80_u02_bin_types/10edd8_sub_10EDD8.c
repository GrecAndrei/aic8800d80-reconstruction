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

extern uint32_t off_10EE20;
extern uint32_t off_10EE24;
extern uint32_t off_10EE28;

// sub_10EDD8 @ 0x10edd8, size 70 bytes
int  sub_10EDD8(int a1, int a2, int a3)
{
  int *v3; // r5
  uint32_t *v4; // r4
  int result; // r0
  int v6; // r3
  int v7; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_10EE20 = 1;
  }
  v3 = (int *)off_10EE24;
  ++*(uint32_t *)off_10EE24;
  if ( a3 )
  {
    v4 = off_10EE28;
    while ( !*(uint32_t *)off_10EE28 )
      ;
    result = sub_10ED74();
    *v4 = 1;
  }
  else
  {
    result = sub_10ED74();
  }
  if ( *v3 )
  {
    v6 = *v3 - 1;
    v7 = *(uint32_t *)off_10EE20;
    *v3 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}

