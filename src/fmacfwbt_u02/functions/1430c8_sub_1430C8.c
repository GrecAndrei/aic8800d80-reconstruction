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

// __aeabi_d2ulz @ 0x1430c8, size 64 bytes
unsigned int  __aeabi_d2ulz(unsigned int a1, int a2)
{
  int v2; // r2
  int v3; // cf
  int v4; // r2
  int v5; // r2

  v2 = 2 * a2;
  if ( __CFSHL__(a2, 1) )
    return 0;
  v3 = __CFADD__(v2, 0x200000);
  v4 = v2 + 0x200000;
  if ( !v3 )
  {
    if ( v4 < 0 )
    {
      v5 = -993 - (v4 >> 21);
      if ( v5 >= 0 )
        return ((a2 << 11) | 0x80000000 | (a1 >> 21)) >> v5;
      return -1;
    }
    return 0;
  }
  if ( !(a1 | (a2 << 12)) )
    return -1;
  return 0;
}

