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


extern uint32_t off_1301AC;

// buf_array_clear_single @ 0x13013c, size 110 bytes
int  buf_array_clear_single(int a1, int a2)
{
  int v4; // r0
  int v5; // r7
  int v6; // r6
  int *v7; // r4
  unsigned int v9; // r0

  if ( a1 == 1 )
  {
    log_mac_state();
    return 0;
  }
  else
  {
    v4 = parse_integer(*(uint8_t **)(a2 + 4), nullptr, 0);
    v5 = v4;
    if ( v4 )
      v5 = 1;
    v6 = v4;
    if ( a1 > 2 )
    {
      v7 = (int *)off_1301AC;
      v9 = parse_integer(*(uint8_t **)(a2 + 8), nullptr, 0);
      if ( v9 > 0x7D0 )
        v7[91] = v9;
    }
    else
    {
      v7 = (int *)off_1301AC;
    }
    if ( *((uint8_t *)v7 + 363) != v5 )
    {
      *((uint8_t *)v7 + 363) = v5;
      if ( v6 )
      {
        mmio_init_check();
        rf_afe_enable();
      }
      else
      {
        rf_afe_disable();
      }
    }
    ke_event_schedule_1("temp_comp en=%d, peroid_ms=%d\n", v5, v7[91]);
    return 0;
  }
}
