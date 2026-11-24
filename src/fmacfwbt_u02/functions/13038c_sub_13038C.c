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


extern uint32_t dword_130484;
extern uint32_t dword_130494;
extern uint32_t off_13047C;
extern uint32_t off_130480;
extern uint32_t off_130488;

// ke_event_send_1 @ 0x13038c, size 238 bytes
int  ke_event_send_1(int a1, int a2)
{
  int *v2; // r6
  int v3; // r0
  int result; // r0
  int v5; // r4
  int v6; // r3
  int v7; // r2
  uint8_t **v8; // r7
  int v9; // r5
  int v10; // r0
  int v11; // r3
  int v12; // r2
  uint8_t **v13; // r0
  int v14; // r0
  uint8_t *a1a[18]; // [sp+4h] [bp-48h] BYREF

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_13047C = 1;
  }
  v2 = (int *)off_130480;
  v3 = dword_130484;
  ++*(uint32_t *)off_130480;
  result = (int)list_pop_front(v3);
  v5 = result;
  if ( *v2 )
  {
    v6 = *v2 - 1;
    v7 = *(uint32_t *)off_13047C;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v8 = (uint8_t **)off_130488;
    do
    {
      v9 = parse_space_token((uint8_t *)(v5 + 4), (int)a1a);
      if ( v9 )
      {
        v13 = find_extension(a1a[0], v8, 7);
        if ( v13 )
        {
          if ( *((uint16_t *)v13 + 5) < v9 || *((uint16_t *)v13 + 4) > v9 )
          {
            printf_wrapper(aUsageSS, *v13, v13[1]);
          }
          else
          {
            v14 = ((int ( *)(int, uint8_t **))v13[3])(v9, a1a);
            if ( v14 )
              printf_wrapper("Command fail, ret=%d\r\n", v14);
          }
        }
        else
        {
          printf_wrapper("Unknown command '%s'\r\n", (const char *)a1a[0]);
        }
      }
      else
      {
        uart_puts(aNoCommand);
      }
      uart_puts(aAic);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_13047C = 1;
      }
      v10 = dword_130494;
      ++*v2;
      check_abort_flag(v10, (uint32_t *)v5);
      result = (int)list_pop_front(dword_130484);
      v5 = result;
      if ( *v2 )
      {
        v11 = *v2 - 1;
        v12 = *(uint32_t *)off_13047C;
        *v2 = v11;
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
