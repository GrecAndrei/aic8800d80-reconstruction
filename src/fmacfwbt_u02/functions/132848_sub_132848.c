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

// util_find_first_set @ 0x132848, size 42 bytes
int  util_find_first_set(int a1)
{
  int v1; // r3
  int v2; // r2
  char v3; // r1

  if ( !a1 )
    return 12;
  v1 = 0;
  while ( 1 )
  {
    v2 = a1 >> (11 - v1) << 31;
    v3 = v1++;
    if ( v2 < 0 )
      break;
    if ( v1 == 12 )
      return 255;
  }
  return (uint8_t)(11 - v3);
}

