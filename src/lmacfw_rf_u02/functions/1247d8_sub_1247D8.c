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

extern uint32_t off_124880;
extern uint32_t off_124884;
extern uint32_t off_12489C;
extern uint32_t off_1248A0;
extern uint32_t off_124888;
extern uint32_t off_12488C;
extern uint32_t off_124894;
extern uint32_t off_124890;
extern uint32_t dword_124898;

// util_buf_clear @ 0x1247d8, size 168 bytes
// Doc: sub_12247D8 [unknown]: Branch on state value, push r3-r5/lr prologue
// sub_12247D8 [unknown]: Branch on state value, push r3-r5/lr prologue
int  util_buf_clear(int a1, int a2)
{
  int *v2; // r5
  int v3; // r0
  uint8_t *v4; // r3
  int *v5; // r4
  int v6; // r3
  int v7; // r2
  int v9; // r0
  uint8_t *v10; // r2

  if ( a1 > 1 )
  {
    v2 = (int *)off_124880;
    v3 = parse_number(*(uint8_t **)(a2 + 4), 0, 0xAu);
    v4 = off_124884;
    *v2 = v3;
    if ( *v4 == 1 )
    {
      v10 = off_12489C;
      *v4 = 0;
      *v10 = 0;
      ke_int_lock(144, 0);
      *(uint32_t *)off_1248A0 = 0;
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_124888 = 1;
    }
    v5 = (int *)off_12488C;
    ++*(uint32_t *)off_12488C;
    rf_cmd_wait();
    rf_acquire();
    write_bb_control();
    if ( *v5 )
    {
      v6 = *v5 - 1;
      v7 = *(uint32_t *)off_124888;
      *v5 = v6;
      if ( !v6 )
      {
        if ( v7 )
          __enable_irq();
      }
    }
    if ( *v2 )
    {
      *(uint32_t *)off_124894 = 2;
      util_alloc_buffer();
      util_alloc_buffer();
      v9 = *(uint32_t *)off_124890;
      if ( !*(uint32_t *)off_124890 )
        return 0;
      if ( *v2 )
      {
LABEL_15:
        init_with_stack(v9);
        return 0;
      }
    }
    else if ( !*(uint32_t *)off_124890 )
    {
      return 0;
    }
    v9 = 0;
    goto LABEL_15;
  }
  dispatch_event_handler(dword_124898);
  return 1;
}

