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


extern uint32_t off_114194;
extern uint32_t off_114198;
extern uint32_t off_11419C;
extern uint32_t off_1141A0;

// assert_fail @ 0x11414c, size 72 bytes
int  assert_fail(uint32_t *a1)
{
  int *v1; // r5
  uint32_t *v2; // r4
  int result; // r0
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_114194 = 1;
  }
  v1 = (int *)off_114198;
  v2 = off_11419C;
  ++*(uint32_t *)off_114198;
  while ( !*v2 )
    ;
  result = wlan_ioctl_handler_1(((uint32_t *)(uintptr_t)off_1141A0)[0] + 628, a1);
  *v2 = 1;
  if ( *v1 )
  {
    v4 = *v1 - 1;
    v5 = *(uint32_t *)off_114194;
    *v1 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  return result;
}
