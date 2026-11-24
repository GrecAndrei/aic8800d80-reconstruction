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


extern uint32_t off_12FE50;

// mode_dispatch @ 0x12fde0, size 110 bytes
int  mode_dispatch(int a1, int a2)
{
  unsigned int v4; // r0
  int v5; // r1
  int v6; // r7
  unsigned int v7; // r6
  int *v8; // r4

  if ( a1 == 1 )
  {
    rf_tx_power_lookup();
    return 0;
  }
  else
  {
    v4 = parse_uint_base(*(uint8_t **)(a2 + 4), nullptr, 0);
    v6 = v4;
    if ( v4 )
      v6 = 1;
    v7 = v4;
    if ( a1 > 2 )
    {
      v8 = (int *)off_12FE50;
      v4 = parse_uint_base(*(uint8_t **)(a2 + 8), nullptr, 0);
      if ( v4 > 0x7D0 )
        v8[91] = v4;
    }
    else
    {
      v8 = (int *)off_12FE50;
    }
    if ( *((uint8_t *)v8 + 363) != v6 )
    {
      *((uint8_t *)v8 + 363) = v6;
      if ( v7 )
      {
        read_global_signed_flag(v4, v5);
        set_flag_send_event_42e();
      }
      else
      {
        clear_flag_send_event_42e();
      }
    }
    alloc_tx_event("temp_comp en=%d, peroid_ms=%d\n", v6, v8[91]);
    return 0;
  }
}
