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

extern uint32_t off_1138FC;
extern uint32_t off_113900;
extern uint32_t dword_113904;

// sub_1138C8 @ 0x1138c8, size 52 bytes
int sub_1138C8()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1138FC = 1;
  }
  v0 = (int *)off_113900;
  v1 = dword_113904;
  ++*(uint32_t *)off_113900;
  result = sub_12D190(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_1138FC;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

