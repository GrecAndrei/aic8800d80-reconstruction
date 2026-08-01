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

extern uint32_t off_112224;
extern uint32_t off_112220;

// arg_store @ 0x1121d4, size 66 bytes
// Doc: rf_bus_setup_n30a [rf]: Setup RF bus and return status flag
// rf_bus_setup_n30a [rf]: Setup RF bus and return status flag
int arg_store()
{
  uint8_t *v0; // r4
  int v1; // r0
  int ( *v3)(uint32_t); // r3

  v0 = rf_bus_init_n460;
  v1 = *((uint16_t *)rf_bus_init_n460 + 7);
  *(uint16_t *)rf_bus_setup_n320_221c = v1;
  if ( v1 )
  {
    v3 = *((int ( **)(uint32_t))off_112224 + 5);
    if ( v3 && v3((uint8_t)v1) )
    {
      *(uint8_t *)off_112220 = 4;
      *v0 = 7;
      if ( !is_flag_one() )
        store_byte_field(0);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    *(uint8_t *)off_112220 = 3;
    return 1;
  }
}

