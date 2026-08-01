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

extern uint32_t dword_130354;
extern uint32_t dword_13035C;
extern uint32_t dword_130360;
extern uint32_t dword_130364;
extern uint32_t dword_130378;
extern uint32_t dword_130368;
extern uint32_t dword_130388;
extern uint32_t dword_130380;
extern uint32_t dword_13037C;
extern uint32_t dword_130384;
extern uint32_t dword_13036C;
extern uint32_t off_130370;
extern uint32_t off_130374;
extern uint32_t dword_130358;

// ke_malloc @ 0x130234, size 288 bytes
int  ke_malloc(unsigned int a1)
{
  int v1; // r0
  int v2; // r4
  uint32_t *v4; // r0
  uint32_t *v5; // r5
  unsigned int CPSR; // r1
  unsigned int v7; // r2
  unsigned int v8; // r4
  unsigned int v9; // r5
  unsigned int v10; // r3
  uint8_t *v11; // r2
  int v12; // r0
  int v13; // r8
  int v14; // r7
  unsigned int v15; // r5
  unsigned int v16; // r6
  int v17; // t1
  int v18; // r7
  int v19; // r6
  unsigned int v20; // r4
  unsigned int v21; // r5
  int v22; // t1
  unsigned int v23; // [sp+8h] [bp-8h]

  v1 = queue_operation(a1, (uint8_t *)dword_130354, 0);
  v2 = v1;
  if ( v1 >= 0 )
  {
    if ( v1 )
    {
      if ( memmove(dword_13035C) != v1 || strcmp(dword_13035C, dword_130354) )
      {
        v4 = list_pop_front(dword_130360);
        v5 = v4;
        if ( v4 )
        {
          memcpy(v4 + 1, dword_130354);
          check_abort_flag(dword_130364, v5);
        }
        else
        {
          uart_puts((uint8_t *)dword_130378);
        }
      }
      else
      {
        CPSR = __get_CPSR();
        v7 = __get_CPSR();
        v8 = __get_CPSR();
        v9 = __get_CPSR();
        v10 = __get_CPSR();
        v23 = __get_CPSR();
        printf_wrapper(dword_130368, CPSR, v7, v8, v9, v10, v23);
        if ( v9 )
        {
          v13 = dword_130388;
          v14 = dword_130380;
          v15 = v9 & 0xFFFFFFF0;
          uart_puts((uint8_t *)dword_13037C);
          v16 = v15 + 256;
          do
          {
            if ( !(v15 << 28) )
              printf_wrapper(v13, v15);
            v17 = *(uint32_t *)v15;
            v15 += 4;
            printf_wrapper(v14, v17);
          }
          while ( v16 != v15 );
        }
        if ( v8 )
        {
          v18 = dword_130388;
          v19 = dword_130380;
          v20 = v8 & 0xFFFFFFF0;
          uart_puts((uint8_t *)dword_130384);
          v21 = v20 + 256;
          do
          {
            if ( !(v20 << 28) )
              printf_wrapper(v18, v20);
            v22 = *(uint32_t *)v20;
            v20 += 4;
            printf_wrapper(v19, v22);
          }
          while ( v21 != v20 );
        }
        uart_puts((uint8_t *)dword_13036C);
        v11 = off_130370;
        v12 = *(uint8_t *)off_130370;
        if ( *(uint8_t *)off_130370 )
        {
          *((uint8_t *)off_130374 + 783) = -4;
          v2 = 0;
          *v11 = 0;
        }
        else
        {
          *((uint8_t *)off_130374 + 783) = -12;
          v2 = v12;
          *v11 = 1;
        }
      }
    }
    else
    {
      uart_puts((uint8_t *)dword_130358);
    }
    queue_operation(0x30u, (uint8_t *)dword_130354, dword_130358);
  }
  return v2;
}

