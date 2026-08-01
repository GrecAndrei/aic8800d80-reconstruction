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

extern uint32_t off_113F50;
extern uint32_t off_113F54;

// util_call_deep @ 0x113f18, size 56 bytes
int util_call_deep()
{
  int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  dma_ring_alloc_2();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_113F50 = 1;
  }
  v0 = (int *)off_113F54;
  ++*(uint32_t *)off_113F54;
  result = irq_disable_global_3(128);
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(uint32_t *)off_113F50;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}

