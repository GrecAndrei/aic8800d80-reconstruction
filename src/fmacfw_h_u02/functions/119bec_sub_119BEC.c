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

// sub_119BEC @ 0x119bec, size 30 bytes
unsigned int  sub_119BEC(int a1, unsigned int a2)
{
  unsigned int v2; // r3

  v2 = (uint16_t)(((*(uint16_t *)(a1 + 24) + 3) & 0xFFFC) + 4);
  if ( a2 <= v2 )
    return 0;
  else
    return ((unsigned int)(uint16_t)(a2 - v2) + 3) >> 2;
}

