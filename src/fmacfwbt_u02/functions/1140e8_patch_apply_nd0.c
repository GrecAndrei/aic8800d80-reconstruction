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

extern uint32_t off_114130;
extern uint32_t off_114134;
extern uint32_t off_114138;
extern uint32_t off_11413C;

// set_busy_flag @ 0x1140e8, size 72 bytes
// Doc: set_busy_flag [patch]: Apply 0xff-terminated patch entries to a register window
// set_busy_flag [patch]: Apply 0xff-terminated patch entries to a register window
int set_busy_flag()
{
  int *v0; // r5
  uint32_t *v1; // r4
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_114130 = 1;
  }
  v0 = (int *)off_114134;
  v1 = off_114138;
  ++*(uint32_t *)off_114134;
  while ( !*v1 )
    ;
  result = check_abort_flag(*(uint32_t *)off_11413C + 564);
  *v1 = 1;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_114130;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

