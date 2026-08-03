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

extern uint32_t off_124E5C;

// sub_124E3C @ 0x124e3c, size 30 bytes
int  sub_124E3C(uint32_t *a1)
{
  uint32_t *v1; // r3

  v1 = *(uint32_t **)off_124E5C;
  if ( !*(uint32_t *)off_124E5C )
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

