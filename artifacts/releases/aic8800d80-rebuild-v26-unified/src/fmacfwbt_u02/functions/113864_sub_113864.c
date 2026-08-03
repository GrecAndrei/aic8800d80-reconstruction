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

extern uint32_t off_113898;
extern uint32_t off_11389C;
extern uint32_t dword_1138A0;

// sub_113864 @ 0x113864, size 52 bytes
// Doc: sub_1213864 [unknown]: Pushes r4/lr; unrecognized instruction pattern with lsls r3,r3,0x1f
// sub_1213864 [unknown]: Pushes r4/lr; unrecognized instruction pattern with lsls r3,r3,0x1f
int sub_113864()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_113898 = 1;
  }
  v0 = (int *)off_11389C;
  v1 = dword_1138A0;
  ++*(uint32_t *)off_11389C;
  result = sub_12D4F8(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_113898;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

