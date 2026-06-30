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

// sub_1247A4 @ 0x1247a4, size 50 bytes
int  sub_1247A4(uint8_t **a1, uint8_t *a2)
{
  uint8_t *v2; // r3
  uint8_t *v3; // t1

  v2 = *a1;
  if ( !*a1 )
    return 0;
  do
  {
    if ( *v2 == *a2 && v2[1] == a2[1] )
      return 1;
    v3 = a1[1];
    ++a1;
    v2 = v3;
  }
  while ( v3 );
  return 0;
}

