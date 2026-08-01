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

extern uint32_t off_116EB4;
extern uint32_t off_116EB8;
extern uint32_t off_116EBC;
extern uint32_t off_116EC0;

// task_queue_handler_c @ 0x116e24, size 144 bytes
int task_queue_handler_c()
{
  int *v0; // r6
  int v1; // r4
  int result; // r0
  uint16_t *v3; // r5
  int *v4; // r8
  int *v5; // r9
  char v6; // r2
  void ( *v7)(uint32_t); // r3
  int v8; // r3
  int v9; // r2

  v0 = (int *)off_116EB4;
  v1 = *(uint32_t *)off_116EB4;
  result = enter_critical_section(0x800000);
  if ( v1 )
  {
    v3 = off_116EB8;
    if ( *(uint16_t *)off_116EB8 )
    {
      v4 = (int *)off_116EBC;
      v5 = (int *)off_116EC0;
      do
      {
        if ( (*(uint8_t *)(v1 + 16) & 1) == 0 && !*v3 )
          break;
        list_pop_front(v0);
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *v4 = 1;
        }
        v6 = *(uint8_t *)(v1 + 16);
        ++*v5;
        if ( (v6 & 1) == 0 )
          --*v3;
        v7 = *(void ( **)(uint32_t))(v1 + 4);
        *(uint8_t *)(v1 + 16) = 0;
        if ( v7 )
          v7(*(uint32_t *)(v1 + 8));
        result = *(uint32_t *)(v1 + 12);
        if ( result )
          result = timer_is_past();
        if ( *v5 )
        {
          v8 = *v5 - 1;
          v9 = *v4;
          *v5 = v8;
          if ( !v8 )
          {
            if ( v9 )
              __enable_irq();
          }
        }
        v1 = *v0;
      }
      while ( *v0 );
    }
  }
  return result;
}

