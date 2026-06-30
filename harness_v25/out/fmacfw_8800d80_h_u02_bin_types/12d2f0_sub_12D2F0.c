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

// sub_12D2F0 @ 0x12d2f0, size 48 bytes
uint32_t * sub_12D2F0(uint32_t *result, uint32_t *a2)
{
  uint32_t *v3; // r1
  uint32_t *v4; // r2
  int v5; // r1

  v3 = (uint32_t *)*a2;
  if ( v3 )
  {
    v4 = result;
    if ( *result )
    {
      result = (uint32_t *)a2[1];
      *(uint32_t *)v4[1] = v3;
      v4[1] = result;
    }
    else
    {
      result = (uint32_t *)*a2;
      v5 = a2[1];
      *v4 = *a2;
      v4[1] = v5;
    }
    *a2 = 0;
  }
  return result;
}

