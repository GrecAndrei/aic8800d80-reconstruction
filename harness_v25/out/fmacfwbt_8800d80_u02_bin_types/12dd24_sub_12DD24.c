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

// sub_12DD24 @ 0x12dd24, size 100 bytes
uint8_t * sub_12DD24(uint8_t *result, int a2, int *a3)
{
  unsigned int v3; // r1
  int v4; // r4
  uint8_t *v5; // r3
  unsigned int v6; // r4
  int v7; // r3

  v3 = (unsigned int)&result[a2];
  if ( v3 <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    v4 = result[1];
    v5 = &result[v4 + 2];
    if ( *result == 196 )
      break;
    result += v4 + 2;
    if ( v3 <= (unsigned int)(v5 + 1) )
      return 0;
  }
  if ( v3 >= (unsigned int)v5 )
  {
    if ( !result )
      return result;
    result += 2;
    v6 = (unsigned int)&result[v4];
    while ( v6 > (unsigned int)(result + 1) )
    {
      v7 = result[1] + 2;
      if ( *result == 194 )
      {
        if ( v6 < (unsigned int)&result[v7] )
          return 0;
        if ( result )
          *a3 = result[1] == 3;
        return result;
      }
      result += v7;
    }
  }
  return 0;
}

