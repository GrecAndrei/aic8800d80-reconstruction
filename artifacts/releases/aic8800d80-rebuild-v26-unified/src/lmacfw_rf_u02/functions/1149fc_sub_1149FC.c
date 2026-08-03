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

extern uint32_t off_114A34;
extern uint32_t off_114A38;
extern uint32_t off_114A3C;

// sub_1149FC @ 0x1149fc, size 56 bytes
int  sub_1149FC(int a1)
{
  BOOL v1; // r0
  int *v2; // r4
  int ( *v3)(BOOL); // r2
  int result; // r0
  int v5; // r3
  int v6; // r2

  v1 = a1 != 0;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_114A34 = 1;
  }
  v2 = (int *)off_114A38;
  v3 = (int ( *)(BOOL))off_114A3C;
  ++*(uint32_t *)off_114A38;
  result = v3(v1);
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(uint32_t *)off_114A34;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}

