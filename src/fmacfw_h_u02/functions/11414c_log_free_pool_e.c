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
// Doc: assert_fail [util]: Return buffer to log free pool variant E
// assert_fail [util]: Return buffer to log free pool variant E
int assert_fail()
{
  int *v0; // r5
  uint32_t *v1; // r4
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_114194 = 1;
  }
  v0 = (int *)off_114198;
  v1 = off_11419C;
  ++*(uint32_t *)off_114198;
  while ( !*v1 )
    ;
  result = wlan_ioctl_handler_1(*(uint32_t *)off_1141A0 + 628);
  *v1 = 1;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_114194;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

