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

// sub_1432D4 @ 0x1432d4, size 48 bytes
uint64_t  sub_1432D4(uint64_t a1, uint64_t a2)
{
  uint64_t v2; // [sp+8h] [bp-8h] BYREF

  if ( a2 )
    return sub_143304(a1, a2, &v2);
  if ( a1 )
    return -1;
  return a1;
}
