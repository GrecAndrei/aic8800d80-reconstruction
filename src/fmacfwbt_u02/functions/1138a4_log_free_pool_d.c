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

extern uint32_t off_1138DC;
extern uint32_t off_1138E0;
extern uint32_t dword_1138E4;

// critical_section_enter_no_set @ 0x1138a4, size 54 bytes
// Doc: critical_section_enter_no_set [util]: Logs a free pool entry with debug info
// critical_section_enter_no_set [util]: Logs a free pool entry with debug info
int critical_section_enter_no_set()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1138DC = 1;
  }
  v0 = (int *)off_1138E0;
  v1 = dword_1138E4;
  ++*(uint32_t *)off_1138E0;
  result = check_abort_flag(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_1138DC;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

