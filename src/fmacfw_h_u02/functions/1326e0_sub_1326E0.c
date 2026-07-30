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

// sub_1326E0 @ 0x1326e0, size 64 bytes
int  sub_1326E0(int a1, int a2)
{
  int v2; // r4
  int v3; // r7
  unsigned int v4; // r3
  int v5; // r2
  unsigned int v6; // r5
  unsigned int v7; // r3

  v2 = 0;
  v3 = 0;
  do
  {
    v4 = (a1 >> v2) & 3;
    v5 = v3 & ~(3 << v2);
    v6 = (a2 >> v2) & 3;
    if ( v4 == 3 || v6 == 3 )
      break;
    if ( v4 >= v6 )
      v4 = (a2 >> v2) & 3;
    v7 = v4 << v2;
    v2 += 2;
    v3 = (uint16_t)(v5 | v7);
  }
  while ( v2 != 16 );
  return v3;
}

