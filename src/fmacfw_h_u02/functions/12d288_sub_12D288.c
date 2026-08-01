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

// list_remove @ 0x12d288, size 60 bytes
uint32_t * list_remove(uint32_t *result, uint32_t **a2, uint32_t *a3)
{
  uint32_t *v3; // r3
  uint32_t *v4; // r4
  uint32_t **v5; // r3

  v3 = (uint32_t *)*result;
  if ( !a2 )
    return (uint32_t *)wlan_ioctl_handler_2((int)result, a3);
  if ( v3 )
  {
    v4 = result;
    if ( v3 == a2 )
    {
LABEL_8:
      v5 = (uint32_t **)result[1];
      result = *a2;
      *a3 = *a2;
      *a2 = a3;
      if ( v5 == a2 )
        v4[1] = a3;
    }
    else
    {
      while ( 1 )
      {
        v3 = (uint32_t *)*v3;
        if ( !v3 )
          break;
        if ( a2 == v3 )
          goto LABEL_8;
      }
    }
  }
  return result;
}

