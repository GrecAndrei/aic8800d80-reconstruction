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

extern uint32_t off_11DCEC;
extern uint32_t off_11DCF0;
extern uint32_t off_11DCF4;
extern uint32_t off_11DD00;
extern uint32_t off_11DD04;
extern uint32_t dword_11DD0C;
extern uint32_t dword_11DD08;
extern uint32_t dword_11DCFC;
extern uint32_t dword_11DCF8;

// ke_int_lock @ 0x11dc54, size 152 bytes
int  ke_int_lock(int result, int a2)
{
  int *v2; // r5
  uint32_t *v3; // r6
  int v4; // r4
  int v5; // r3
  int v6; // r3
  int v7; // r2
  int v8; // r7
  int v9; // r0

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11DCEC = 1;
  }
  v2 = (int *)off_11DCF0;
  v3 = off_11DCF4;
  v4 = *((uint32_t *)off_11DCF4 + 5);
  v5 = *(uint32_t *)off_11DCF0 + 1;
  *(uint32_t *)off_11DCF0 = v5;
  if ( v4 )
  {
    if ( *(uint16_t *)(v4 + 4) == result && *(uint16_t *)(v4 + 6) == a2 )
    {
      list_pop_front(v3 + 5);
      v8 = v3[5];
      v9 = (int)(v3 + 8);
      if ( v8 )
      {
        ke_enter_critical(v9, *(uint32_t *)(v8 + 8));
        if ( **(int16_t **)off_11DD00 < 0 && *(uint32_t *)(v8 + 8) - *((uint32_t *)off_11DD04 + 4) < 0 )
          flash_ctrl_init(dword_11DD0C, dword_11DD08, 232);
      }
      else
      {
        ke_exit_critical(v9);
      }
    }
    else
    {
      result = co_list_process(dword_11DCFC, dword_11DCF8, a2 | (result << 16));
      v4 = result;
      if ( !result )
      {
        v5 = *v2;
        goto LABEL_8;
      }
    }
    result = check_buffer_size(v4);
    v5 = *v2;
  }
LABEL_8:
  if ( v5 )
  {
    v6 = v5 - 1;
    v7 = *(uint32_t *)off_11DCEC;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}

