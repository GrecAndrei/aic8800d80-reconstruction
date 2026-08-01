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

extern uint32_t off_115DB0;
extern uint32_t off_115DB4;
extern uint32_t off_115DB8;

// critical_section_enter @ 0x115d64, size 76 bytes
// Doc: sub_1215D64 [util]: Helper routine with stack frame and shift op
// sub_1215D64 [util]: Helper routine with stack frame and shift op
int critical_section_enter()
{
  int *v0; // r6
  uint8_t *v1; // r7
  uint8_t *v2; // r5
  int i; // r4
  int v4; // r3
  int result; // r0
  int v6; // r3
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_115DB0 = 1;
  }
  v0 = (int *)off_115DB4;
  v1 = off_115DB8;
  ++*(uint32_t *)off_115DB4;
  v2 = v1;
  for ( i = 4; i != -1; --i )
  {
    v4 = *((uint32_t *)v2 + 28);
    result = (uint8_t)i;
    v2 -= 28;
    if ( v4 )
      result = mmio_irq_set(result);
  }
  v6 = *v0;
  v1[143] = 1;
  if ( v6 )
  {
    v7 = v6 - 1;
    v8 = *(uint32_t *)off_115DB0;
    *v0 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}

