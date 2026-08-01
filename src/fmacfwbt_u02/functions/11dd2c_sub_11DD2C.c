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

extern uint32_t off_11DDD0;
extern uint32_t off_11DDDC;
extern uint32_t off_11DDE0;
extern uint32_t off_11DDD4;
extern uint32_t dword_11DDD8;

// tx_unlock @ 0x11dd2c, size 162 bytes
int tx_unlock()
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
  uint8_t *v9; // r4

  v0 = (int *)off_11DDD0;
  v1 = *(uint32_t *)off_11DDD0;
  result = set_system_flag_2(0x200000);
  if ( v1 )
  {
    v3 = (int *)off_11DDDC;
    v4 = (int *)off_11DDE0;
    v5 = 0;
    do
    {
      if ( (*(uint8_t *)(v1 + 16) & 1) == 0 )
      {
        if ( v5 )
          break;
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
        result = rf_tx_timestamp_check();
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
  v9 = off_11DDD4;
  if ( *((uint8_t *)off_11DDD4 + 69) )
  {
    set_system_flag_1(0x80000);
    result = state_check_feature(1024, dword_11DDD8);
    v9[69] = 0;
  }
  return result;
}

