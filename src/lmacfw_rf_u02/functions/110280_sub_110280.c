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


extern uint32_t dword_1102C8;
extern uint32_t off_1102C0;
extern uint32_t off_1102C4;
extern uint32_t off_1102CC;

// irq_disable_set @ 0x110280, size 62 bytes
int  irq_disable_set(uint32_t *a1)
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
    *(uint32_t *)off_1102C0 = 1;
  }
  v2 = (int *)off_1102C4;
  v3 = dword_1102C8;
  ++*(uint32_t *)off_1102C4;
  result = check_kernel_state(v3, a1);
  v5 = *v2;
  ++*(uint32_t *)off_1102CC;
  if ( v5 )
  {
    v6 = v5 - 1;
    v7 = *(uint32_t *)off_1102C0;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}
