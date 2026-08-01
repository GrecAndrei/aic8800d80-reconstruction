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

extern uint32_t off_11839C;

// reset_link_status @ 0x118374, size 38 bytes
int  reset_link_status(uint8_t *a1)
{
  uint32_t *v1; // r3
  int *v2; // r3
  int result; // r0

  v1 = off_11839C;
  *a1 = 0;
  v2 = (int *)v1[2];
  if ( !v2 )
    return 0;
  result = 0;
  do
  {
    if ( !*((uint8_t *)v2 + 94) )
    {
      if ( *((uint8_t *)v2 + 96) )
        ++result;
    }
    v2 = (int *)*v2;
  }
  while ( v2 );
  return result;
}

