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


extern uint32_t dword_113340;
extern uint32_t off_113338;
extern uint32_t off_11333C;

// lock_acquire @ 0x113300, size 54 bytes
int  lock_acquire(uint32_t *a1)
{
  int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_113338 = 1;
  }
  v2 = (int *)off_11333C;
  v3 = dword_113340;
  ++*(uint32_t *)off_11333C;
  result = check_kernel_state(v3, a1);
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(uint32_t *)off_113338;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}
