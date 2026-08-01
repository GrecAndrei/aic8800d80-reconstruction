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

extern uint32_t off_1227EC;

// get_rx_pdu @ 0x1227a8, size 66 bytes
int get_rx_pdu()
{
  int *v0; // r2
  int result; // r0
  uint32_t *v2; // r3

  v0 = *((int **)off_1227EC + 2);
  if ( v0 )
  {
    result = 0;
    while ( !*((uint8_t *)v0 + 106) )
    {
      if ( *((uint8_t *)v0 + 108) && (v2 = (uint32_t *)v0[60]) != 0 )
      {
        do
        {
          v2 = (uint32_t *)*v2;
          if ( *((uint8_t *)v0 + 116) != 255 )
            result = (uint8_t)(result + 1);
        }
        while ( v2 );
        v0 = (int *)*v0;
        if ( !v0 )
          return result;
      }
      else
      {
        v0 = (int *)*v0;
        if ( !v0 )
          return result;
      }
    }
  }
  return 0;
}

