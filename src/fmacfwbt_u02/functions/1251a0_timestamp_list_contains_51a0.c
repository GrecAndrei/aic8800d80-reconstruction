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

extern uint32_t off_1251C0;

// ke_event_pending @ 0x1251a0, size 30 bytes
// Doc: ke_event_pending [util]: Check if a timestamp value exists in a list
// ke_event_pending [util]: Check if a timestamp value exists in a list
int  ke_event_pending(uint32_t *a1)
{
  uint32_t *v1; // r3

  v1 = *(uint32_t **)off_1251C0;
  if ( !*(uint32_t *)off_1251C0 )
    return (int)v1;
  if ( v1 != a1 )
  {
    while ( 1 )
    {
      v1 = (uint32_t *)*v1;
      if ( !v1 )
        break;
      if ( a1 == v1 )
        return 1;
    }
    return (int)v1;
  }
  return 1;
}

