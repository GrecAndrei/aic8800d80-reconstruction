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

// compare_uint16_field @ 0x117d10, size 30 bytes
BOOL  compare_uint16_field(int a1, int a2)
{
  unsigned int v2; // r3
  unsigned int v3; // r0

  v2 = *(uint16_t *)(a1 + 32);
  v3 = *(uint16_t *)(a2 + 32);
  if ( v2 > v3 )
    return 0;
  if ( v2 >= v3 )
    return 1;
  return (int)(v3 - v2) <= 63;
}

