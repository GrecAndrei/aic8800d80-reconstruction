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

extern uint32_t off_116E18;
extern uint32_t off_116E1C;
extern uint32_t off_116E20;

// task_queue_handler_b @ 0x116d98, size 126 bytes
int task_queue_handler_b()
{
  int *v0; // r5
  int v1; // r4
  int result; // r0
  int *v3; // r8
  int *v4; // r9
  int v5; // r7
  void ( *v6)(uint32_t); // r2
  int v7; // r3
  int v8; // r2

  v0 = (int *)off_116E18;
  v1 = *(uint32_t *)off_116E18;
  result = enter_critical_section(0x800000);
  if ( v1 )
  {
    v3 = (int *)off_116E1C;
    v4 = (int *)off_116E20;
    v5 = 0;
    do
    {
      if ( (*(uint8_t *)(v1 + 16) & 1) == 0 )
      {
        if ( v5 )
          return result;
        v5 = 1;
      }
      list_pop_front(v0);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v3 = 1;
      }
      v6 = *(void ( **)(uint32_t))(v1 + 4);
      ++*v4;
      *(uint8_t *)(v1 + 16) = 0;
      if ( v6 )
        v6(*(uint32_t *)(v1 + 8));
      result = *(uint32_t *)(v1 + 12);
      if ( result )
        result = timer_is_past();
      if ( *v4 )
      {
        v7 = *v4 - 1;
        v8 = *v3;
        *v4 = v7;
        if ( !v7 )
        {
          if ( v8 )
            __enable_irq();
        }
      }
      v1 = *v0;
    }
    while ( *v0 );
  }
  return result;
}

