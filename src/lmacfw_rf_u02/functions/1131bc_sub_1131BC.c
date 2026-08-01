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

extern uint32_t off_113258;
extern uint32_t off_11325C;
extern uint32_t dword_113260;
extern uint32_t off_113268;
extern uint32_t off_113264;
extern uint32_t off_11326C;
extern uint32_t off_113270;
extern uint32_t off_113274;
extern uint32_t dword_113278;
extern uint32_t off_11327C;

// critical_section_enter_arg @ 0x1131bc, size 156 bytes
void critical_section_enter_arg()
{
  int *v0; // r4
  int v1; // r0
  uint8_t *v2; // r1
  int v3; // r0
  uint16_t v4; // r3
  int v5; // r3
  int v6; // r2
  int v7; // r3
  int v8; // r2
  int v9; // r3
  int v10; // r0
  int v11; // r1
  int v12; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_113258 = 1;
  }
  v0 = (int *)off_11325C;
  v1 = dword_113260;
  ++*(uint32_t *)off_11325C;
  check_kernel_state(v1);
  v2 = off_113268;
  v3 = *(uint8_t *)off_113268;
  v4 = *(uint16_t *)off_113264 + 1;
  *(uint16_t *)off_113264 = v4;
  if ( v3 && *(uint8_t *)off_11326C <= (unsigned int)v4 )
  {
    v7 = *(uint8_t *)off_113270;
    *v2 = 0;
    if ( v7 )
      *((uint32_t *)off_113274 + 512) &= ~0x2000u;
    else
      *((uint32_t *)off_113274 + 713) &= ~1u;
    rf_read_status(1);
    ke_int_lock(1069, 1);
    v10 = check_interrupt_flag(512, dword_113278, v8, v9);
    if ( !*(uint8_t *)off_11327C )
      main_event_handler(v10, v11, v12, *(uint8_t *)off_11327C);
  }
  if ( *v0 )
  {
    v5 = *v0 - 1;
    v6 = *(uint32_t *)off_113258;
    *v0 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
}

