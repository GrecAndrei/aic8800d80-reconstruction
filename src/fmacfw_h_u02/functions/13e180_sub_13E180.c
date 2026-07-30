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

// sub_13E180 @ 0x13e180, size 104 bytes
int  sub_13E180(uint8_t *a1)
{
  int result; // r0
  unsigned int v2; // r3
  int v3; // r3

  switch ( a1[169] )
  {
    case 0u:
    case 1u:
      v2 = a1[177];
      if ( !a1[177] )
        goto LABEL_15;
      if ( v2 > 3 )
        result = a1[177];
      else
        result = (uint16_t)(v2 | (a1[182] << 10));
      break;
    case 2u:
    case 3u:
      if ( !a1[177] )
        goto LABEL_15;
      result = (uint16_t)(a1[169] << 11);
      break;
    case 4u:
      result = 0x2000;
      break;
    case 5u:
      if ( a1[177] )
      {
        v3 = a1[194];
        if ( a1[183] )
          result = 14976;
        else
          result = 10752;
        if ( v3 )
          result |= 0x4000u;
      }
      else
      {
LABEL_15:
        result = 1024;
      }
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

