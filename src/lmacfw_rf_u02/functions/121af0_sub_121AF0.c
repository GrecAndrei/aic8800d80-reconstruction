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


extern uint32_t dword_121B3C;
extern uint32_t off_121B34;
extern uint32_t off_121B38;

// sub_121AF0 @ 0x121af0, size 66 bytes
int  sub_121AF0(unsigned int a1, int a2)
{
  int *v3; // r5
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_121B34 = 1;
  }
  v3 = (int *)off_121B38;
  ++*(uint32_t *)off_121B38;
  result = sub_1152CC((uint32_t *)a2);
  if ( a1 <= 3 )
    --*(uint8_t *)(dword_121B3C + a1);
  if ( *v3 )
  {
    v5 = *v3 - 1;
    v6 = *(uint32_t *)off_121B34;
    *v3 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}
