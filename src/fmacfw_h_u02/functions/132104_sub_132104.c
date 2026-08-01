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

extern uint32_t off_132174;

// event_code_to_str @ 0x132104, size 112 bytes
char * event_code_to_str(char *result, int a2)
{
  int v2; // r1
  char *v3; // r3
  char *v4; // r4
  int v5; // r2

  if ( result )
  {
    if ( result != (char *)1 || (uint8_t)(a2 - 1) > 0xB0u )
      return 0;
    result = (char *)*((uint8_t *)off_132174 + 371);
    v2 = 5 * a2 + 5000;
    v3 = (char *)off_132174 + 202;
  }
  else
  {
    if ( (unsigned int)(a2 - 1) > 0xD )
      return result;
    if ( a2 == 14 )
      v2 = 2484;
    else
      v2 = 5 * a2 + 2407;
    result = (char *)*((uint8_t *)off_132174 + 370);
    v3 = (char *)off_132174 + 118;
  }
  if ( result )
  {
    v4 = &v3[6 * (uint32_t)result];
    while ( 1 )
    {
      v5 = *(uint16_t *)v3;
      result = v3;
      v3 += 6;
      if ( v5 == v2 )
        break;
      if ( v3 == v4 )
        return 0;
    }
  }
  return result;
}

