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

// sub_143338 @ 0x143338, size 94 bytes
int  sub_143338(int result, int a2)
{
  int v2; // r2
  unsigned int v3; // r3
  int v4; // zf
  int v5; // cf
  int v6; // zf
  int v7; // nf
  int v8; // cc

  v2 = 2 * result;
  v3 = 2 * a2;
  v4 = (2 * result) >> 24 == -1;
  if ( (2 * result) >> 24 != -1 )
    v4 = (int)v3 >> 24 == -1;
  if ( v4 && (v2 >> 24 == -1 && result << 9 || (int)v3 >> 24 == -1 && a2 << 9) )
    return 1;
  v5 = 0;
  v6 = (v2 | (v3 >> 1)) == 0;
  v8 = 0;
  v7 = ((v2 | (v3 >> 1)) & 0x80000000) != 0;
  if ( v2 | (v3 >> 1) )
  {
    v6 = result == a2;
    v8 = 0;
    v7 = (result ^ a2) < 0;
  }
  if ( !v7 )
  {
    v5 = v2 >= v3;
    result = v2 - v3;
    v6 = v2 == v3;
    v8 = v2 > v3;
  }
  if ( v8 )
    result = a2 >> 31;
  if ( !v5 )
    result = ~(a2 >> 31);
  if ( !v6 )
    return result | 1;
  return result;
}

