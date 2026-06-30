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

// sub_13715C @ 0x13715c, size 18 bytes
// Doc: sub_1237164 [util]: Trampoline wrapper around sub-helper
// sub_1237164 [util]: Trampoline wrapper around sub-helper
int  sub_13715C(int a1, uint8_t *a2)
{
  if ( *a2 )
    sub_1374C8((uint8_t)*a2);
  return 0;
}

