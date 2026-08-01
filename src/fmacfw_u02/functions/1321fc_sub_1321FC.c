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

extern uint32_t off_132240;

// ke_event_get @ 0x1321fc, size 66 bytes
char * ke_event_get(int a1, int a2)
{
  char *result; // r0
  char *v3; // r3
  char *v4; // r4
  int v5; // r2

  if ( a1 )
  {
    result = (char *)*((uint8_t *)off_132240 + 371);
    v3 = (char *)off_132240 + 202;
  }
  else
  {
    result = (char *)*((uint8_t *)off_132240 + 370);
    v3 = (char *)off_132240 + 118;
  }
  if ( result )
  {
    v4 = &v3[6 * (uint32_t)result];
    while ( 1 )
    {
      v5 = *(uint16_t *)v3;
      result = v3;
      v3 += 6;
      if ( v5 == a2 )
        break;
      if ( v3 == v4 )
        return 0;
    }
  }
  return result;
}

