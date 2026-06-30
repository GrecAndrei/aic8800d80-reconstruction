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

// sub_1327E8 @ 0x1327e8, size 40 bytes
int  sub_1327E8(int a1)
{
  int v1; // r2
  int result; // r0
  int v4; // r3
  char v5; // r1

  v1 = 14;
  result = 7;
  do
  {
    v4 = (a1 >> v1) & 3;
    v5 = result - 1;
    v1 -= 2;
    if ( v4 != 3 )
      break;
    result = (uint8_t)(result - 1);
  }
  while ( v5 );
  return result;
}

