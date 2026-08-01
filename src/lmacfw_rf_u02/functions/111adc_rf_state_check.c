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

extern uint32_t off_111B20;

// ke_timeout_tick @ 0x111adc, size 66 bytes
// Doc: rf_bus_setup_n30e [rf]: RF bus register setup for N30E
// rf_bus_setup_n30e [rf]: RF bus register setup for N30E
int ke_timeout_tick()
{
  uint8_t *v0; // r4
  int v1; // r0
  int ( *v3)(uint32_t); // r3

  v0 = off_111B20;
  v1 = *((uint16_t *)off_111B20 + 7);
  *(uint16_t *)rf_bus_setup_n320 = v1;
  if ( v1 )
  {
    v3 = *((int ( **)(uint32_t))rf_bus_setup_n328 + 5);
    if ( v3 && v3((uint8_t)v1) )
    {
      *(uint8_t *)rf_bus_setup_n324 = 4;
      *v0 = 7;
      if ( !is_radio_powered() )
        prepare_and_dispatch(0);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    *(uint8_t *)rf_bus_setup_n324 = 3;
    return 1;
  }
}

