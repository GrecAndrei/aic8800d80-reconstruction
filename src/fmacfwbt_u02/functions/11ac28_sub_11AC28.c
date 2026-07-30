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

extern uint32_t off_11AC6C;
extern uint32_t off_11AC74;
extern uint32_t dword_11AC70;

// sub_11AC28 @ 0x11ac28, size 68 bytes
// Doc: sub_121ac28 [unknown]: Unknown helper with push and shifted value setup
// sub_121ac28 [unknown]: Unknown helper with push and shifted value setup
int  sub_11AC28(int result)
{
  int *v1; // r4
  int v2; // r2
  int v3; // r1
  int v4; // r3
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11AC6C = 1;
  }
  v1 = (int *)off_11AC74;
  v2 = dword_11AC70 + 84 * result;
  v3 = *(uint8_t *)(v2 + 80);
  v4 = *(uint32_t *)off_11AC74 + 1;
  *(uint32_t *)off_11AC74 = v4;
  if ( !v3 && *(uint32_t *)(v2 + 44) )
  {
    result = sub_11A308(result);
    v4 = *v1;
  }
  if ( v4 )
  {
    v5 = v4 - 1;
    v6 = *(uint32_t *)off_11AC6C;
    *v1 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}

