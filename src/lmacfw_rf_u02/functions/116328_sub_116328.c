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

extern uint32_t off_116390;
extern uint32_t dword_116394;
extern uint32_t dword_116398;

// wlan_clk_init @ 0x116328, size 102 bytes
int  wlan_clk_init(int a1, int a2)
{
  int16_t **v2; // r5
  int v3; // r7
  int v4; // r6
  int v6; // r0
  int v7; // r1
  int v8; // r3
  int *v9; // r2
  int v10; // r0

  v2 = (int16_t **)off_116390;
  v3 = dword_116394;
  v4 = dword_116398;
LABEL_2:
  v6 = list_pop_front(a2);
  v7 = 2080374784;
  v8 = v6;
  if ( v6 )
  {
    while ( 1 )
    {
      v9 = *(int **)(v8 + 32);
      if ( *(uint32_t *)(v8 + 24) )
        goto LABEL_4;
      v7 = *v9;
      if ( *v9 >= 0 )
        break;
LABEL_5:
      if ( !*(uint16_t *)(v8 + 4) )
      {
        log_and_disable_irq(v8, v7, *(uint16_t *)(v8 + 4));
        goto LABEL_2;
      }
      if ( **v2 >= 0 )
        goto LABEL_2;
      flash_ctrl_init(v4, v3, 1147);
      v10 = list_pop_front(a2);
      v7 = 2080374784;
      v8 = v10;
      if ( !v10 )
        return pool_alloc_init();
    }
    v7 = 0x40000000;
LABEL_4:
    *v9 = v7;
    goto LABEL_5;
  }
  return pool_alloc_init();
}

