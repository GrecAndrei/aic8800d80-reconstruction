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

extern uint32_t dword_13BC14;
extern uint32_t dword_13BC18;
extern uint32_t dword_13BC1C;

// sub_13BBA8 @ 0x13bba8, size 108 bytes
int  sub_13BBA8(int result)
{
  int v1; // r4
  int v2; // r5
  int v3; // r10
  int v4; // r7
  int16_t v5; // r9
  int v6; // r6
  int v7; // t1

  v1 = dword_13BC14;
  v2 = dword_13BC18;
  v3 = dword_13BC1C;
  v4 = result;
  v5 = -128 * dword_13BC14;
  v6 = dword_13BC14 + 64;
  do
  {
    v7 = *(uint16_t *)(v1 + 2);
    v1 += 2;
    if ( v7 )
    {
      if ( *(uint8_t *)(v2 + 16) == v4 )
      {
        sub_12CBF4((uint16_t)(v5 + ((uint16_t)v1 << 7) - 256) | 8, 4);
        *(uint8_t *)(v2 + 25) = 0;
        result = sub_13B558(v4, v2, 2, 0, 0, 39, v3);
      }
    }
    v2 += 32;
  }
  while ( v1 != v6 );
  return result;
}

