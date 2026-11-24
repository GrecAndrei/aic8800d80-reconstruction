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


extern uint32_t dword_11B020;
extern uint32_t dword_11B040;
extern uint32_t off_11B024;
extern uint32_t off_11B028;
extern uint32_t off_11B034;
extern uint32_t off_11B03C;

// ke_task_handler_1 @ 0x11af78, size 166 bytes
int  ke_task_handler_1(int a1, int a2, int a3)
{
  uint32_t *v6; // r0
  uint32_t *v7; // r4
  int v8; // r5
  int v9; // r0
  int v10; // r6
  int result; // r0
  int *v12; // r6
  int v13; // r1
  volatile unsigned int v14; // r3
  int v15; // r0
  int v16; // r2
  int *v17; // r3
  int v18; // r3
  int v19; // r3
  int v20; // r2

  v6 = list_pop_front(dword_11B020);
  v7 = v6;
  if ( **(uint16_t **)off_11B024 < 0 && !v6 )
    flash_ctrl_init((int)aChSwitchNull, (int)aChanSwitchAllo, 227);
  v8 = off_11B028;
  v9 = off_11B028 + 0x20;
  v10 = *(uint32_t *)(off_11B028 + 0x20);
  v7[3] = a3;
  v7[1] = a1;
  v7[2] = a2;
  result = check_kernel_state(v9, v7);
  if ( !v10 )
  {
    *(uint32_t *)(v8 + 0x48) = v7;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_11B034 = 1;
    }
    v12 = (int *)off_11B03C;
    v13 = v7[1];
    v14 = (*(volatile uint32_t *)0x40501010u);
    v15 = *(uint32_t *)off_11B03C;
    v16 = *(uint32_t *)off_11B03C + 1;
    *(uint32_t *)off_11B03C = v16;
    if ( (int)(v13 - v14 - 64) >= 0 )
    {
      result = ke_enter_critical((uint32_t *)dword_11B040, v13);
      if ( *v12 )
      {
        v19 = *v12 - 1;
        v20 = *(uint32_t *)off_11B034;
        *v12 = v19;
        if ( !v19 )
        {
          if ( v20 )
            __enable_irq();
        }
      }
    }
    else
    {
      if ( v16 )
      {
        v17 = (int *)off_11B034;
        *v12 = v15;
        v18 = *v17;
        if ( !v15 )
        {
          if ( v18 )
            __enable_irq();
        }
      }
      return (*(int ( **)(uint32_t *))(v8 + 0x44))(v7);
    }
  }
  return result;
}
