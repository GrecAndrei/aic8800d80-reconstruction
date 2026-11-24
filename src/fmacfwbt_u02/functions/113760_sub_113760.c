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


extern uint32_t dword_113804;
extern uint32_t off_1137FC;
extern uint32_t off_113800;
extern uint32_t off_113808;
extern uint32_t off_11380C;
extern uint32_t off_113810;
extern uint32_t off_113814;
extern uint32_t off_113818;
extern uint32_t off_113820;

// critical_section_enter @ 0x113760, size 156 bytes
int  critical_section_enter(uint32_t *a1)
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
    *(uint32_t *)off_1137FC = 1;
  }
  v2 = (int *)off_113800;
  v3 = dword_113804;
  ++*(uint32_t *)off_113800;
  check_abort_flag(v3, a1);
  v4 = off_11380C;
  result = *(uint8_t *)off_11380C;
  v6 = *(uint16_t *)off_113808 + 1;
  *(uint16_t *)off_113808 = v6;
  if ( result && *(uint8_t *)off_113810 <= (unsigned int)v6 )
  {
    v9 = *(uint8_t *)off_113814;
    *v4 = 0;
    if ( v9 )
      *((uint32_t *)off_113818 + 512) &= ~0x2000u;
    else
      *((uint32_t *)off_113818 + 713) &= ~1u;
    phy_reg_modify(1);
    irq_lock((char *)0x42D, 1);
    result = state_check_feature(512, aWfr);
    if ( !*(uint8_t *)off_113820 )
      bt_ctrl_main_task(result, v10, v11, *(uint8_t *)off_113820);
  }
  if ( *v2 )
  {
    v7 = *v2 - 1;
    v8 = *(uint32_t *)off_1137FC;
    *v2 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}
