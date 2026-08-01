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

// util_find_first_zero @ 0x13282c, size 28 bytes
int  util_find_first_zero(int a1)
{
  int v1; // r3
  int v2; // zf
  int v3; // r1

  v1 = 0;
  while ( 1 )
  {
    v2 = ((a1 >> v1) & 1) == 0;
    v3 = (uint8_t)v1++;
    if ( !v2 )
      break;
    if ( v1 == 12 )
      return 12;
  }
  return v3;
}

