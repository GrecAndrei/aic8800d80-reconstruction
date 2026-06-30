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

extern uint32_t off_12F684;
extern uint32_t off_12F688;
extern uint32_t dword_12F68C;
extern uint32_t off_12F690;

// sub_12F630 @ 0x12f630, size 82 bytes
// Doc: sub_122F630 [bt]: BT/LMAC helper: branches on shifted flag and dispatches
// sub_122F630 [bt]: BT/LMAC helper: branches on shifted flag and dispatches
int  sub_12F630(int a1, int a2, int a3)
{
  int *v4; // r4
  int v5; // r0
  int result; // r0
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12F684 = 1;
  }
  v4 = (int *)off_12F688;
  v5 = dword_12F68C;
  ++*(uint32_t *)off_12F688;
  result = sub_12ECB0(v5, a1, a2, a3 & 0xFFFFF);
  if ( *(int *)off_12F690 >= 0 )
  {
    sub_12BD48();
    result = irq_nesting_or(0x80000000);
  }
  if ( *v4 )
  {
    v7 = *v4 - 1;
    v8 = *(uint32_t *)off_12F684;
    *v4 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}

