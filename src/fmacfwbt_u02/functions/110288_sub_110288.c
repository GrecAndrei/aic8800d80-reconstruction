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


extern uint32_t dword_1102D0;
extern uint32_t off_1102C8;
extern uint32_t off_1102CC;
extern uint32_t off_1102D4;

// critical_enter_5 @ 0x110288, size 62 bytes
int  critical_enter_5(uint32_t *a1)
{
  int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r3
  int v7; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1102C8 = 1;
  }
  v2 = (int *)off_1102CC;
  v3 = dword_1102D0;
  ++*(uint32_t *)off_1102CC;
  result = check_abort_flag(v3, a1);
  v5 = *v2;
  ++*(uint32_t *)off_1102D4;
  if ( v5 )
  {
    v6 = v5 - 1;
    v7 = *(uint32_t *)off_1102C8;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}
