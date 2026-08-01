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

extern uint32_t off_1132F4;
extern uint32_t off_1132F8;
extern uint32_t dword_1132FC;

// disable_interrupts @ 0x1132c0, size 52 bytes
// Doc: sub_12132C0 [unknown]: Thin wrapper routine (push r4,lr; small arithmetic tail)
// sub_12132C0 [unknown]: Thin wrapper routine (push r4,lr; small arithmetic tail)
int disable_interrupts()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1132F4 = 1;
  }
  v0 = (int *)off_1132F8;
  v1 = dword_1132FC;
  ++*(uint32_t *)off_1132F8;
  result = list_pop_front(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_1132F4;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

