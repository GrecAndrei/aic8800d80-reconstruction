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

extern uint32_t off_118EA0;
extern uint32_t dword_118EA4;
extern uint32_t dword_118EA8;

// rf_tx_freq_set @ 0x118e38, size 102 bytes
// Doc: sub_1218E38 [util]: Initialize firmware subsystem state with constants
// sub_1218E38 [util]: Initialize firmware subsystem state with constants
int  rf_tx_freq_set(int a1, int a2)
{
  int16_t **v2; // r5
  int v3; // r7
  int v4; // r6
  int v6; // r0
  int v7; // r1
  int v8; // r3
  int v9; // r2
  int v10; // r0

  v2 = (int16_t **)off_118EA0;
  v3 = dword_118EA4;
  v4 = dword_118EA8;
LABEL_2:
  v6 = list_pop_front(a2);
  v7 = 2080374784;
  v8 = v6;
  if ( v6 )
  {
    while ( 1 )
    {
      v9 = *(uint32_t *)(v8 + 76);
      if ( *(uint32_t *)(v8 + 68) )
        goto LABEL_4;
      if ( *(int *)(v9 + 4) >= 0 )
        break;
LABEL_5:
      if ( !*(uint16_t *)(v8 + 4) )
      {
        btlp_enter_sleep(v8);
        goto LABEL_2;
      }
      if ( **v2 >= 0 )
        goto LABEL_2;
      mmio_irq_clear(v4, v3, 1147);
      v10 = list_pop_front(a2);
      v7 = 2080374784;
      v8 = v10;
      if ( !v10 )
        return system_init();
    }
    v7 = 0x40000000;
LABEL_4:
    *(uint32_t *)(v9 + 4) = v7;
    goto LABEL_5;
  }
  return system_init();
}

