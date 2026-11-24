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


extern uint32_t dword_113260;
extern uint32_t off_113258;
extern uint32_t off_11325C;
extern uint32_t off_113264;
extern uint32_t off_113268;
extern uint32_t off_11326C;
extern uint32_t off_113270;
extern uint32_t off_113274;
extern uint32_t off_11327C;

// critical_section_enter_arg @ 0x1131bc, size 156 bytes
int  critical_section_enter_arg(uint32_t *a1)
{
  int *v2; // r4
  int v3; // r0
  uint8_t *v4; // r1
  int result; // r0
  uint16_t v6; // r3
  int v7; // r3
  int v8; // r2
  int v9; // r3
  int v10; // r1
  int v11; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_113258 = 1;
  }
  v2 = (int *)off_11325C;
  v3 = dword_113260;
  ++*(uint32_t *)off_11325C;
  check_kernel_state(v3, a1);
  v4 = off_113268;
  result = *(uint8_t *)off_113268;
  v6 = *(uint16_t *)off_113264 + 1;
  *(uint16_t *)off_113264 = v6;
  if ( result && *(uint8_t *)off_11326C <= (unsigned int)v6 )
  {
    v9 = *(uint8_t *)off_113270;
    *v4 = 0;
    if ( v9 )
      *((uint32_t *)off_113274 + 512) &= ~0x2000u;
    else
      *((uint32_t *)off_113274 + 713) &= ~1u;
    rf_read_status(1);
    ke_int_lock((char *)0x42D, 1);
    result = check_interrupt_flag(512, aWfr);
    if ( !*(uint8_t *)off_11327C )
      main_event_handler(result, v10, v11, *(uint8_t *)off_11327C);
  }
  if ( *v2 )
  {
    v7 = *v2 - 1;
    v8 = *(uint32_t *)off_113258;
    *v2 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}
