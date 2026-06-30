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

// sub_118324 @ 0x118324, size 26 bytes
int  sub_118324(int a1)
{
  int result; // r0

  result = sub_11AC10(a1 + 48);
  if ( *(uint32_t *)(a1 + 72) )
    return sub_11C158(a1);
  return result;
}

