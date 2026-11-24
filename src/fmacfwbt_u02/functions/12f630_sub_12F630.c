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


extern uint32_t off_12F684;
extern uint32_t off_12F688;
extern uint32_t off_12F690;

// ke_int_lock_1 @ 0x12f630, size 82 bytes
int  ke_int_lock_1(int a1, int a2, int a3)
{
  int *v3; // r4
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12F684 = 1;
  }
  v3 = (int *)off_12F688;
  ++*(uint32_t *)off_12F688;
  result = ke_event_schedule_1("\x9BASSERT (%s) at %s:%d\n", (const char *)a1, (const char *)a2, a3 & 0xFFFFF);
  if ( *(int *)off_12F690 >= 0 )
  {
    mmio_clear_high_bits();
    result = set_system_flag_1(0x80000000);
  }
  if ( *v3 )
  {
    v5 = *v3 - 1;
    v6 = *(uint32_t *)off_12F684;
    *v3 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}
