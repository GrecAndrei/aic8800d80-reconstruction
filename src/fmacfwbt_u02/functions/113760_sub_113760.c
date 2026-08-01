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

extern uint32_t off_1137FC;
extern uint32_t off_113800;
extern uint32_t dword_113804;
extern uint32_t off_11380C;
extern uint32_t off_113808;
extern uint32_t off_113810;
extern uint32_t off_113814;
extern uint32_t off_113818;
extern uint32_t dword_11381C;
extern uint32_t off_113820;

// critical_section_enter @ 0x113760, size 156 bytes
void critical_section_enter()
{
  int *v0; // r4
  int v1; // r0
  uint8_t *v2; // r1
  int v3; // r0
  uint16_t v4; // r3
  int v5; // r3
  int v6; // r2
  int v7; // r3

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1137FC = 1;
  }
  v0 = (int *)off_113800;
  v1 = dword_113804;
  ++*(uint32_t *)off_113800;
  check_abort_flag(v1);
  v2 = off_11380C;
  v3 = *(uint8_t *)off_11380C;
  v4 = *(uint16_t *)off_113808 + 1;
  *(uint16_t *)off_113808 = v4;
  if ( v3 && *(uint8_t *)off_113810 <= (unsigned int)v4 )
  {
    v7 = *(uint8_t *)off_113814;
    *v2 = 0;
    if ( v7 )
      *((uint32_t *)off_113818 + 512) &= ~0x2000u;
    else
      *((uint32_t *)off_113818 + 713) &= ~1u;
    phy_reg_modify(1);
    irq_lock(1069, 1);
    state_check_feature(512, dword_11381C);
    if ( !*(uint8_t *)off_113820 )
      bt_ctrl_main_task();
  }
  if ( *v0 )
  {
    v5 = *v0 - 1;
    v6 = *(uint32_t *)off_1137FC;
    *v0 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
}

