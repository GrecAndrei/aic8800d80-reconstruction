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

// scan_parse_adv_data @ 0x13c49c, size 34 bytes
int  scan_parse_adv_data(int a1)
{
  int v1; // r3
  int v2; // r1
  int result; // r0
  int v4; // t1

  if ( !*(uint8_t *)(a1 + 263) )
    return *(uint8_t *)(a1 + 263);
  v1 = a1 + 5;
  v2 = *(uint8_t *)(a1 + 263) + a1 + 5;
  result = 0;
  do
  {
    v4 = *(uint8_t *)++v1;
    if ( v4 == 2 )
      result = (char)(result + 1);
  }
  while ( v1 != v2 );
  return result;
}

