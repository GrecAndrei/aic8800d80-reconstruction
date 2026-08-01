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

extern uint32_t off_10ECCC;
extern uint32_t off_10ECD0;
extern uint32_t off_10ECD4;

// atomic_reg_write @ 0x10ec84, size 70 bytes
// Doc: atomic_reg_write [rf]: Guard wrapper validating/serializing RF register writes
// atomic_reg_write [rf]: Guard wrapper validating/serializing RF register writes
int  atomic_reg_write(int a1, int a2, int a3, int a4)
{
  int *v4; // r5
  uint32_t *v5; // r4
  int result; // r0
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_10ECCC = 1;
  }
  v4 = (int *)off_10ECD0;
  ++*(uint32_t *)off_10ECD0;
  if ( a4 )
  {
    v5 = off_10ECD4;
    while ( !*(uint32_t *)off_10ECD4 )
      ;
    result = call_vector_1b8();
    *v5 = 1;
  }
  else
  {
    result = call_vector_1b8();
  }
  if ( *v4 )
  {
    v7 = *v4 - 1;
    v8 = *(uint32_t *)off_10ECCC;
    *v4 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}

