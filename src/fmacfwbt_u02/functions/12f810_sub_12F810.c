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


extern uint32_t dword_12F868;
extern uint32_t off_12F860;
extern uint32_t off_12F864;
extern uint32_t off_12F86C;

// sub_12F810 @ 0x12f810, size 78 bytes
int  sub_12F810(unsigned int a1, int a2)
{
  int *v3; // r5
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12F860 = 1;
  }
  v3 = (int *)off_12F864;
  ++*(uint32_t *)off_12F864;
  result = sub_116484((uint32_t *)a2);
  if ( a1 <= 4 )
    --*(uint8_t *)(dword_12F868 + a1);
  if ( *v3 )
  {
    v5 = *v3 - 1;
    v6 = *(uint32_t *)off_12F860;
    *v3 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  --*((uint32_t *)off_12F86C + 126);
  return result;
}
