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

extern uint32_t dword_1426AC;

// sub_14261C @ 0x14261c, size 142 bytes
uint64_t  sub_14261C(uint64_t a1)
{
  int v1; // r7
  int v2; // r4
  int v3; // r5
  uint64_t v4; // r2
  int v5; // r3
  unsigned int v6; // r7
  int v7; // r3
  int v8; // cf
  int v9; // r3

  v1 = (HIDWORD(a1) >> 20) & 0x7FF;
  v2 = v1 - 1023;
  v3 = HIDWORD(a1);
  v4 = a1;
  if ( v1 - 1023 > 19 )
  {
    if ( v2 <= 51 )
    {
      v6 = 0xFFFFFFFF >> ((HIDWORD(a1) >> 20) - 19);
      if ( ((unsigned int)a1 & v6) != 0 )
      {
        v7 = 1 << (51 - v2);
        v8 = __CFADD__((uint32_t)a1, v7);
        v9 = a1 + v7;
        if ( v8 )
          v3 = HIDWORD(a1) + 1;
        v5 = v9 & ~v6;
        return __PAIR64__(v3, v5);
      }
    }
    else if ( v1 == 2047 )
    {
      return sub_14273C(a1, HIDWORD(a1), a1, HIDWORD(a1));
    }
  }
  else
  {
    if ( v2 < 0 )
    {
      v3 = HIDWORD(a1) & 0x80000000;
      if ( v1 == 1022 )
        v3 |= 0x3FF00000u;
      v5 = 0;
      return __PAIR64__(v3, v5);
    }
    if ( HIDWORD(a1) & (dword_1426AC >> ((HIDWORD(a1) >> 20) + 1)) | (unsigned int)a1 )
    {
      v3 = (HIDWORD(a1) + (0x80000 >> ((HIDWORD(a1) >> 20) + 1))) & ~(dword_1426AC >> ((HIDWORD(a1) >> 20) + 1));
      v5 = 0;
      return __PAIR64__(v3, v5);
    }
  }
  return v4;
}

