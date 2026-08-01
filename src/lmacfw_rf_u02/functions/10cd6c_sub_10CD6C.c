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

extern uint32_t off_10CE58;
extern uint32_t off_10CE70;
extern uint32_t dword_10CE74;
extern uint32_t off_10CE5C;
extern uint32_t off_10CE78;
extern uint32_t off_10CE7C;
extern uint32_t dword_10CE64;
extern uint32_t off_10CE60;
extern uint32_t dword_10CE6C;
extern uint32_t off_10CE68;

// handle_interrupt_save @ 0x10cd6c, size 236 bytes
int  handle_interrupt_save(char a1)
{
  int v1; // r5
  uint8_t *v2; // r11
  int v3; // r8
  int *v4; // r7
  uint32_t *v5; // r10
  unsigned int v6; // r1
  unsigned int v7; // r2
  unsigned int v8; // r4
  int *v9; // r9
  int v10; // r0
  int v11; // r1
  int v12; // r3
  int v13; // r1
  int v14; // r2
  int v15; // r0
  int result; // r0

  enter_critical_section(0x10000);
  v1 = *(uint32_t *)off_10CE58;
  if ( *(uint32_t *)(*(uint32_t *)off_10CE58 + 588) )
  {
    v2 = (uint8_t *)off_10CE70;
    v3 = dword_10CE74;
    v4 = (int *)off_10CE5C;
    v5 = off_10CE78;
    while ( 1 )
    {
      v6 = v2[1621];
      v7 = v2[1622];
      if ( v6 >= v7 )
        break;
      v8 = v2[1620]
         + 1
         - 81 * ((unsigned int)(((unsigned int)v3 * (unsigned uint64_t)((unsigned int)v2[1620] + 1)) >> 32) >> 6);
      v2[1621] = v6 + 1;
      v2[1620] = v8;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v4 = 1;
      }
      v9 = (int *)off_10CE7C;
      ++*(uint32_t *)off_10CE7C;
      while ( !*v5 )
        ;
      v10 = list_pop_front(v1 + 588);
      v11 = *v9;
      *v5 = 1;
      v12 = v10;
      if ( v11 )
      {
        v13 = v11 - 1;
        v14 = *v4;
        *v9 = v13;
        if ( !v13 )
        {
          if ( v14 )
            __enable_irq();
        }
      }
      v15 = dword_10CE64;
      *(uint32_t *)&v2[20 * v8 + 4] = v12 + *(uint32_t *)off_10CE60;
      check_kernel_state(v15);
      if ( !*(uint32_t *)(v1 + 588) )
        goto LABEL_13;
    }
    log_printf(dword_10CE6C, v6, v7);
  }
LABEL_13:
  result = set_busy_flag_alt(2048);
  *(uint32_t *)off_10CE68 = (1 << (a1 + 8)) & 0xF00;
  return result;
}

