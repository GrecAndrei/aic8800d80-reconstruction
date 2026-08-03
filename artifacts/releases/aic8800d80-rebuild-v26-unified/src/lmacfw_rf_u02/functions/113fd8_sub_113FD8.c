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

extern uint32_t dword_114040;

// sub_113FD8 @ 0x113fd8, size 102 bytes
int  sub_113FD8(int a1, int a2, uint8_t *a3)
{
  int v5; // r1
  int v6; // r2
  unsigned int v7; // r0
  unsigned int v8; // r4
  unsigned int v9; // r3
  int result; // r0
  char v11; // r2
  uint32_t v12[3]; // [sp+4h] [bp-Ch]

  v5 = *(uint32_t *)(dword_114040 + 4);
  v6 = *(uint32_t *)(dword_114040 + 8);
  v12[0] = *(uint32_t *)dword_114040;
  v12[1] = v5;
  v12[2] = v6;
  v7 = v12[a1];
  if ( a2 > 3 )
  {
    ++v7;
    LOBYTE(a2) = a2 - 4;
  }
  v8 = (unsigned int)sub_113A44(v7) >> (8 * a2);
  v9 = (uint8_t)v8 >> 4;
  if ( (v8 & 0xF0) != 0 )
  {
    result = 0;
  }
  else
  {
    if ( !(uint8_t)v8 )
    {
      *a3 = 0;
      return 2;
    }
    v9 = (uint8_t)v8;
    result = 1;
  }
  if ( (v9 & 1) != 0 )
    v11 = -1;
  else
    v11 = 1;
  *a3 = (v9 >> 1) * v11;
  return result;
}

