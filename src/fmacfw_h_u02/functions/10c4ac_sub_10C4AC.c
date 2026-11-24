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

// sub_10C4AC @ 0x10c4ac, size 74 bytes
void  sub_10C4AC(int a1, int a2, int a3, int a4, uint8_t a5, uint8_t a6)
{
  int v9; // r0

  sub_101EC0(a1, a2, a2, 0, 0, 0);
  sub_10C220((unsigned int *)a3, a4, a5, a6);
  if ( a5 )
  {
    if ( a1 == 1 )
      v9 = 28;
    else
      v9 = 3;
    sub_102CCC(v9, (uint16_t *)a4);
  }
}
