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

extern uint32_t off_1120D8;
extern uint32_t off_1120DC;
extern uint32_t off_1120E4;
extern uint32_t off_1120E0;

// wlan_process_packet @ 0x112094, size 66 bytes
int wlan_process_packet()
{
  uint8_t *v0; // r4
  int v1; // r0
  int ( *v3)(uint32_t); // r3

  v0 = off_1120D8;
  v1 = *((uint16_t *)off_1120D8 + 7);
  *(uint16_t *)off_1120DC = v1;
  if ( v1 )
  {
    v3 = *((int ( **)(uint32_t))off_1120E4 + 5);
    if ( v3 && v3((uint8_t)v1) )
    {
      *(uint8_t *)off_1120E0 = 4;
      *v0 = 7;
      if ( !rf_calibration_done() )
        set_config_field(0);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    *(uint8_t *)off_1120E0 = 3;
    return 1;
  }
}

