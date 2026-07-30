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

extern uint32_t off_12C7E0;
extern uint32_t off_12C7E4;
extern uint32_t dword_12C7E8;

// sub_12C798 @ 0x12c798, size 72 bytes
int sub_12C798()
{
  int *v0; // r5
  int v1; // r4
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12C7E0 = 1;
  }
  v0 = (int *)off_12C7E4;
  v1 = dword_12C7E8;
  ++*(uint32_t *)off_12C7E4;
  sub_12D00C(0x10000000);
  while ( 1 )
  {
    result = sub_12D190(v1);
    if ( !result )
      break;
    sub_12CA88(result);
  }
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_12C7E0;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

