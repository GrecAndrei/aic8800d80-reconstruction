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

extern uint32_t off_121B34;
extern uint32_t off_121B38;
extern uint32_t dword_121B3C;

// sub_121AF0 @ 0x121af0, size 66 bytes
int  sub_121AF0(unsigned int a1)
{
  int *v2; // r5
  int result; // r0
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_121B34 = 1;
  }
  v2 = (int *)off_121B38;
  ++*(uint32_t *)off_121B38;
  result = sub_1152CC();
  if ( a1 <= 3 )
    --*(uint8_t *)(dword_121B3C + a1);
  if ( *v2 )
  {
    v4 = *v2 - 1;
    v5 = *(uint32_t *)off_121B34;
    *v2 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  return result;
}

