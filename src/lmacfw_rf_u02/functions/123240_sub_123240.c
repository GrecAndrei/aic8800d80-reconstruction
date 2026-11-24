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


extern uint32_t dword_123338;
extern uint32_t dword_123348;
extern uint32_t off_123330;
extern uint32_t off_123334;
extern uint32_t off_12333C;

// exit_critical_section @ 0x123240, size 238 bytes
int exit_critical_section()
{
  int *v0; // r6
  int v1; // r0
  int result; // r0
  int v3; // r4
  int v4; // r3
  int v5; // r2
  uint8_t **v6; // r7
  int v7; // r5
  int v8; // r0
  int v9; // r3
  int v10; // r2
  uint8_t **v11; // r0
  int v12; // r0
  uint8_t *a1[18]; // [sp+4h] [bp-48h] BYREF

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_123330 = 1;
  }
  v0 = (int *)off_123334;
  v1 = dword_123338;
  ++*(uint32_t *)off_123334;
  result = (int)list_pop_front(v1);
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
    v6 = (uint8_t **)off_12333C;
    do
    {
      v7 = str_skip_spaces((uint8_t *)(v3 + 4), (int)a1);
      if ( v7 )
      {
        v11 = parse_dot_separated(a1[0], v6, 55);
        if ( v11 )
        {
          if ( *((uint16_t *)v11 + 5) < v7 || *((uint16_t *)v11 + 4) > v7 )
          {
            log_printf(aUsageSS, *v11, v11[1]);
          }
          else
          {
            v12 = ((int ( *)(int, uint8_t **))v11[3])(v7, a1);
            if ( v12 )
              log_printf("Command fail, ret=%d\r\n", v12);
          }
        }
        else
        {
          log_printf("Unknown command '%s'\r\n", (const char *)a1[0]);
        }
      }
      else
      {
        uart_tx_string(aNoCommand);
      }
      uart_tx_string(aAic);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_123330 = 1;
      }
      v8 = dword_123348;
      ++*v0;
      check_kernel_state(v8, (uint32_t *)v3);
      result = (int)list_pop_front(dword_123338);
      v3 = result;
      if ( *v0 )
      {
        v9 = *v0 - 1;
        v10 = *(uint32_t *)off_123330;
        *v0 = v9;
        if ( !v9 )
        {
          if ( v10 )
            __enable_irq();
        }
      }
    }
    while ( result );
  }
  return result;
}
