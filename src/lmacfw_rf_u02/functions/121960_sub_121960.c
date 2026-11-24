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


extern uint32_t off_1219B4;
extern uint32_t off_1219B8;
extern uint32_t off_1219C0;

// sub_121960 @ 0x121960, size 82 bytes
int  sub_121960(int a1, int a2, int a3)
{
  int *v3; // r4
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1219B4 = 1;
  }
  v3 = (int *)off_1219B8;
  ++*(uint32_t *)off_1219B8;
  result = sub_11F504("\x9BASSERT (%s) at %s:%d\n", (const char *)a1, (const char *)a2, a3 & 0xFFFFF);
  if ( *(int *)off_1219C0 >= 0 )
  {
    sub_11D31C();
    result = sub_11E5E0(0x80000000);
  }
  if ( *v3 )
  {
    v5 = *v3 - 1;
    v6 = *(uint32_t *)off_1219B4;
    *v3 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}
