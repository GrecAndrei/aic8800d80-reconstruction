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


extern uint32_t off_118E2C;

// rf_calib_config @ 0x118d80, size 172 bytes
uint32_t * rf_calib_config(unsigned int a1, int a2, int a3)
{
  uint16_t **v3; // r8
  uint32_t *v7; // r4
  int v8; // r1

  v3 = (uint16_t **)off_118E2C;
  while ( 1 )
  {
    v7 = list_pop_front(a2);
    if ( !v7 )
      break;
    while ( 1 )
    {
      v8 = v7[19];
      if ( v7[17] )
      {
        *(uint32_t *)(v8 + 4) = 2080374784;
      }
      else if ( *(int *)(v8 + 4) >= 0 )
      {
        *(uint32_t *)(v8 + 4) = 0x40000000;
      }
      if ( *((uint16_t *)v7 + 2) )
        break;
      btlp_enter_sleep(v7);
      v7 = list_pop_front(a2);
      if ( !v7 )
        return system_init();
    }
    *(uint32_t *)(v8 + 4) |= 0x800000u;
    timer_check_state((int)v7, (uint32_t *)(v8 + 4));
    release_buffer((int)v7);
    if ( mac_tx_start_1((int)v7, 1) )
    {
      if ( **v3 < 0 && !a3 )
        mmio_irq_clear((int)aRepushList, (int)aTxlCfmFlush, 1105);
      check_abort_flag(a3, v7);
    }
    else
    {
      irq_lock_save_1(a1, (int)v7);
    }
  }
  return system_init();
}
