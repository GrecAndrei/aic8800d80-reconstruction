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


extern uint32_t off_118FA0;
extern uint32_t off_118FA8;
extern uint32_t off_118FAC;
extern uint32_t off_118FB4;
extern uint32_t off_118FB8;
extern uint32_t off_118FBC;
extern uint32_t off_118FC0;
extern uint32_t off_118FC4;
extern uint32_t off_118FD4;

// rf_state_process @ 0x118ec8, size 214 bytes
int rf_state_process()
{
  int *v0; // r8
  int *v1; // r4
  int v2; // r3
  volatile unsigned int v3; // r7
  int v4; // r9
  unsigned int v5; // r3
  int v6; // r2
  int v7; // r3
  int v8; // r3
  int result; // r0
  int v10; // r3
  int v11; // r3
  int v12; // r2

  if ( **(uint16_t **)off_118FA0 < 0 && flash_write_byte(0) == 4 )
    flash_ctrl_init((int)aKeStateGetTask, (int)aMmForceIdleReq, 1799);
  check_interrupt_flag(4, aForceIdle);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_118FA8 = 1;
  }
  v0 = (int *)off_118FD4;
  v1 = (int *)off_118FAC;
  ++*(uint32_t *)off_118FD4;
  v2 = *v1;
  *v1 = 0;
  v3 = (*(volatile uint32_t *)0x40501010u);
  v4 = v2 & 0xF;
  while ( *v1 << 28 )
  {
    mmio_status_write();
    v5 = (*(volatile uint32_t *)0x40501010u) - v3;
    if ( v5 > 0x7530 )
      check_interrupt_flag(4, aIdleErr);
  }
  v6 = *(uint32_t *)off_118FB4;
  v7 = *(uint32_t *)off_118FB8;
  if ( v4 )
  {
    while ( (v7 & v6 & 4) == 0 )
    {
      v6 = *(uint32_t *)off_118FB4;
      v7 = *(uint32_t *)off_118FB8;
    }
  }
  v8 = *((uint8_t *)off_118FBC + 90);
  *(uint32_t *)off_118FC0 = 4;
  if ( v8 )
    critical_section_enter_1();
  result = flash_erase_sector(0, 3);
  v10 = *v0;
  *(uint16_t *)(off_118FC4 + 0x10) = 0;
  if ( v10 )
  {
    v11 = v10 - 1;
    v12 = *(uint32_t *)off_118FA8;
    *v0 = v11;
    if ( !v11 )
    {
      if ( v12 )
        __enable_irq();
    }
  }
  return result;
}
