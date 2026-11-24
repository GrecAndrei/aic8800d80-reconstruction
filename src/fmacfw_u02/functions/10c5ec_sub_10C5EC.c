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

// sub_10C5EC @ 0x10c5ec, size 74 bytes
int  sub_10C5EC(int a1, int a2, int a3, int a4, uint8_t a5, uint8_t a6)
{
  int result; // r0
  int v10; // r0

  sub_101F70(a1, a2, a2, 0, 0, 0);
  result = (int)sub_10C360((unsigned int *)a3, a4, a5, a6);
  if ( a5 )
  {
    if ( a1 == 1 )
      v10 = 28;
    else
      v10 = 3;
    return sub_102D7C(v10, (uint16_t *)a4);
  }
  return result;
}
