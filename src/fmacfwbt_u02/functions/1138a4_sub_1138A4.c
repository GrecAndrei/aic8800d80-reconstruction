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


extern uint32_t dword_1138E4;
extern uint32_t off_1138DC;
extern uint32_t off_1138E0;

// critical_section_enter_no_set @ 0x1138a4, size 54 bytes
int  critical_section_enter_no_set(uint32_t *a1)
{
  int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1138DC = 1;
  }
  v2 = (int *)off_1138E0;
  v3 = dword_1138E4;
  ++*(uint32_t *)off_1138E0;
  result = check_abort_flag(v3, a1);
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(uint32_t *)off_1138DC;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}
