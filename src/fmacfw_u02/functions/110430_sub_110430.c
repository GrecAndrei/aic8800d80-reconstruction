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

extern uint32_t off_110470;
extern uint32_t off_110474;
extern uint32_t dword_110478;
extern uint32_t off_11047C;

// sub_110430 @ 0x110430, size 62 bytes
int sub_110430()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_110470 = 1;
  }
  v0 = (int *)off_110474;
  v1 = dword_110478;
  ++*(uint32_t *)off_110474;
  result = sub_12D248(v1);
  v3 = *v0;
  ++*(uint32_t *)off_11047C;
  if ( v3 )
  {
    v4 = v3 - 1;
    v5 = *(uint32_t *)off_110470;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  return result;
}

