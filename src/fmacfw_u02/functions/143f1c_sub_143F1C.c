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

extern uint32_t dword_143F6C;

// memset @ 0x143f1c, size 80 bytes
int  memset(uint8_t *a1, uint8_t *a2, int a3)
{
  uint8_t *v3; // r5
  uint8_t *v4; // r7
  int v5; // r3
  int v6; // r3
  int v7; // t1
  int v8; // r2
  int v9; // t1
  int v10; // r4
  int result; // r0
  int v12; // r2

  if ( a3 )
  {
    v3 = a1;
    v4 = &a1[a3];
    while ( 1 )
    {
      v7 = *v3++;
      v6 = v7;
      v9 = *a2++;
      v8 = v9;
      v10 = *(uint8_t *)(dword_143F6C + v9) & 3;
      if ( (*(uint8_t *)(dword_143F6C + v6) & 3) == 1 )
        v6 += 32;
      result = v8;
      if ( v10 == 1 )
      {
        v12 = v8 + 32;
        result = v6 - v12;
        if ( v6 != v12 )
          return result;
      }
      else
      {
        v5 = v6 - v8;
        if ( v5 )
          return v5;
        if ( !v8 )
          return result;
      }
      if ( v3 == v4 )
        return 0;
    }
  }
  return 0;
}

