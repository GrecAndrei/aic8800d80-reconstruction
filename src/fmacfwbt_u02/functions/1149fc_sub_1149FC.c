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

extern uint32_t off_114AD8;
extern uint32_t off_114ADC;
extern uint32_t off_114AE0;
extern uint32_t dword_114AEC;
extern uint32_t dword_114AE4;
extern uint32_t dword_114AE8;

// alloc_small_buffer @ 0x1149fc, size 218 bytes
uint8_t *alloc_small_buffer()
{
  int *v0; // r4
  uint8_t *result; // r0
  int v2; // r2
  int v3; // r1
  int v4; // r3
  uint8_t *v5; // r5
  int v6; // r0
  int v7; // r2
  int v8; // r0
  int v9; // r2
  int v10; // r0
  int v11; // r3
  int v12; // r2
  int v13; // r3
  int v14; // r2
  int *v15; // r3
  int v16; // r3

  set_system_flag_2(16);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_114AD8 = 1;
  }
  v0 = (int *)off_114ADC;
  result = (uint8_t *)off_114AE0;
  v2 = *(uint32_t *)off_114ADC;
  v3 = *((uint32_t *)off_114AE0 + 4);
  v4 = *(uint32_t *)off_114ADC + 1;
  *(uint32_t *)off_114ADC = v4;
  if ( v3 )
  {
    result = (uint8_t *)list_pop_front(result + 16);
    v5 = result;
    if ( *v0 )
    {
      v13 = *v0 - 1;
      v14 = *(uint32_t *)off_114AD8;
      *v0 = v13;
      if ( !v13 )
      {
        if ( v14 )
          __enable_irq();
      }
    }
    if ( result )
    {
      v6 = dispatch_by_cmd(result + 4);
      if ( v6 < 0 )
      {
        return (uint8_t *)ke_event_schedule(dword_114AEC, v5[4], v7);
      }
      else
      {
        *(uint32_t *)v5 = v6;
        v8 = find_object_by_key(17, 3090, v5);
        if ( v8 )
        {
          ke_event_schedule(dword_114AE4, v8, v9);
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(uint32_t *)off_114AD8 = 1;
          }
          v10 = dword_114AE8;
          ++*v0;
          check_abort_flag_2(v10, v5);
          if ( *v0 )
          {
            v11 = *v0 - 1;
            v12 = *(uint32_t *)off_114AD8;
            *v0 = v11;
            if ( !v11 )
            {
              if ( v12 )
                __enable_irq();
            }
          }
          return (uint8_t *)set_system_flag_1(16);
        }
        else
        {
          lock_release();
          return (uint8_t *)periph_write(0);
        }
      }
    }
  }
  else if ( v4 )
  {
    v15 = (int *)off_114AD8;
    *v0 = v2;
    v16 = *v15;
    if ( !v2 )
    {
      if ( v16 )
        __enable_irq();
    }
  }
  return result;
}

