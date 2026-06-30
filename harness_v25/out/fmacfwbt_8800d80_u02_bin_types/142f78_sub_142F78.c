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

// sub_142F78 @ 0x142f78, size 122 bytes
int  sub_142F78(unsigned int a1, unsigned int a2, unsigned int a3, int a4)
{
  int v4; // zf
  int v5; // zf
  int v7; // cf
  int v8; // zf
  int v9; // r0

  v4 = (int)(2 * a2) >> 21 == -1;
  if ( (int)(2 * a2) >> 21 != -1 )
    v4 = (2 * a4) >> 21 == -1;
  if ( v4 && ((int)(2 * a2) >> 21 == -1 && a1 | (a2 << 12) || (2 * a4) >> 21 == -1 && a3 | (a4 << 12)) )
    return 1;
  v5 = (a1 | (2 * a2)) == 0;
  if ( !(a1 | (2 * a2)) )
    v5 = (a3 | (2 * a4)) == 0;
  if ( !v5 )
    v5 = a2 == a4;
  if ( v5 && a1 == a3 )
    return 0;
  v7 = 0;
  v8 = a2 == a4;
  if ( ((a2 ^ a4) & 0x80000000) == 0 )
  {
    v7 = a2 >= a4;
    v8 = a2 == a4;
  }
  if ( v8 )
    v7 = a1 >= a3;
  if ( v7 )
    v9 = a4 >> 31;
  else
    v9 = ~(a4 >> 31);
  return v9 | 1;
}

