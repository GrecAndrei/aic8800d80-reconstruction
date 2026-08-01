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

extern uint32_t off_123330;
extern uint32_t off_123334;
extern uint32_t dword_123338;
extern uint32_t dword_12333C;
extern uint32_t dword_123350;
extern uint32_t dword_123354;
extern uint32_t dword_12334C;
extern uint32_t dword_123340;
extern uint32_t dword_123344;
extern uint32_t dword_123348;

// exit_critical_section @ 0x123240, size 238 bytes
// Doc: sub_1223240 [unknown]: Helper routine with large stack frame and shifted operand
// sub_1223240 [unknown]: Helper routine with large stack frame and shifted operand
uint8_t *exit_critical_section()
{
  int *v0; // r6
  int v1; // r0
  uint8_t *result; // r0
  uint8_t *v3; // r4
  int v4; // r3
  int v5; // r2
  uint32_t *v6; // r7
  int v7; // r8
  int v8; // r9
  int v9; // r5
  int v10; // r0
  int v11; // r3
  int v12; // r2
  uint32_t *v13; // r0
  int v14; // r0
  int v15[18]; // [sp+4h] [bp-48h] BYREF

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_123330 = 1;
  }
  v0 = (int *)off_123334;
  v1 = dword_123338;
  ++*(uint32_t *)off_123334;
  result = (uint8_t *)list_pop_front(v1);
  v3 = result;
  if ( *v0 )
  {
    v4 = *v0 - 1;
    v5 = *(uint32_t *)off_123330;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v6 = (uint32_t *)dword_12333C;
    v7 = dword_123350;
    v8 = dword_123354;
    do
    {
      v9 = str_skip_spaces(v3 + 4, (int)v15);
      if ( v9 )
      {
        v13 = parse_dot_separated(v15[0], v6, 55);
        if ( v13 )
        {
          if ( *((int16_t *)v13 + 5) < v9 || *((int16_t *)v13 + 4) > v9 )
          {
            log_printf(v7, *v13, v13[1]);
          }
          else
          {
            v14 = ((int ( *)(int, int *))v13[3])(v9, v15);
            if ( v14 )
              log_printf(v8, v14);
          }
        }
        else
        {
          log_printf(dword_12334C, v15[0]);
        }
      }
      else
      {
        uart_tx_string((uint8_t *)dword_123340);
      }
      uart_tx_string((uint8_t *)dword_123344);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_123330 = 1;
      }
      v10 = dword_123348;
      ++*v0;
      check_kernel_state(v10, v3);
      result = (uint8_t *)list_pop_front(dword_123338);
      v3 = result;
      if ( *v0 )
      {
        v11 = *v0 - 1;
        v12 = *(uint32_t *)off_123330;
        *v0 = v11;
        if ( !v11 )
        {
          if ( v12 )
            __enable_irq();
        }
      }
    }
    while ( result );
  }
  return result;
}

