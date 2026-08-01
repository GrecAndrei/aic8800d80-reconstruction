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
extern uint32_t dword_118FD0;
extern uint32_t dword_118FCC;
extern uint32_t dword_118FA4;
extern uint32_t off_118FA8;
extern uint32_t off_118FD4;
extern uint32_t off_118FAC;
extern uint32_t off_118FB0;
extern uint32_t dword_118FC8;
extern uint32_t off_118FB4;
extern uint32_t off_118FB8;
extern uint32_t off_118FBC;
extern uint32_t off_118FC0;
extern uint32_t off_118FC4;

// rf_state_process @ 0x118ec8, size 214 bytes
int  rf_state_process(int a1, int a2, int a3)
{
  int v3; // r3
  int *v4; // r8
  int *v5; // r4
  uint32_t *v6; // r5
  int v7; // r3
  int v8; // r7
  int v9; // r9
  int v10; // r2
  unsigned int v11; // r3
  int v12; // r2
  int v13; // r3
  int v14; // r3
  int result; // r0
  int v16; // r3
  int v17; // r3
  int v18; // r2

  v3 = **(int16_t **)off_118FA0;
  if ( v3 < 0 && flash_write_byte(0) == 4 )
    flash_ctrl_init(dword_118FD0, dword_118FCC, 1799);
  check_interrupt_flag(4, dword_118FA4, a3, v3);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_118FA8 = 1;
  }
  v4 = (int *)off_118FD4;
  v5 = (int *)off_118FAC;
  v6 = off_118FB0;
  ++*(uint32_t *)off_118FD4;
  v7 = *v5;
  *v5 = 0;
  v8 = v6[4];
  v9 = v7 & 0xF;
  while ( *v5 << 28 )
  {
    mmio_status_write();
    v11 = v6[4] - v8;
    if ( v11 > 0x7530 )
      check_interrupt_flag(4, dword_118FC8, v10, v11);
  }
  v12 = *(uint32_t *)off_118FB4;
  v13 = *(uint32_t *)off_118FB8;
  if ( v9 )
  {
    while ( (v13 & v12 & 4) == 0 )
    {
      v12 = *(uint32_t *)off_118FB4;
      v13 = *(uint32_t *)off_118FB8;
    }
  }
  v14 = *((uint8_t *)off_118FBC + 90);
  *(uint32_t *)off_118FC0 = 4;
  if ( v14 )
    critical_section_enter();
  result = flash_erase_sector(0);
  v16 = *v4;
  *((uint16_t *)off_118FC4 + 8) = 0;
  if ( v16 )
  {
    v17 = v16 - 1;
    v18 = *(uint32_t *)off_118FA8;
    *v4 = v17;
    if ( !v17 )
    {
      if ( v18 )
        __enable_irq();
    }
  }
  return result;
}

