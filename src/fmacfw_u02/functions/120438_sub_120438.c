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

extern uint32_t off_120488;

// clear_device_flag @ 0x120438, size 80 bytes
int  clear_device_flag(uint8_t *a1)
{
  uint32_t *v1; // r3
  int *v2; // r3
  int result; // r0

  v1 = off_120488;
  *a1 = 0;
  v2 = (int *)v1[2];
  if ( v2 )
  {
    result = 0;
    while ( 1 )
    {
      if ( *((uint8_t *)v2 + 106) )
      {
        if ( *((uint8_t *)v2 + 108) && *((uint8_t *)v2 + 1224) )
          goto LABEL_10;
LABEL_6:
        v2 = (int *)*v2;
        if ( !v2 )
          return result;
      }
      else
      {
        if ( !*((uint8_t *)v2 + 108) )
          goto LABEL_6;
        if ( !*((uint8_t *)v2 + 1224) )
        {
          ++result;
          goto LABEL_6;
        }
LABEL_10:
        *a1 = 1;
        v2 = (int *)*v2;
        if ( !v2 )
          return result;
      }
    }
  }
  return 0;
}

