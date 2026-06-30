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

extern uint32_t off_112080;
extern uint32_t dword_112090;
extern uint32_t dword_112084;
extern uint32_t dword_112088;
extern uint32_t dword_11208C;

// sub_111FDC @ 0x111fdc, size 162 bytes
int  sub_111FDC(int a1, int a2, unsigned int a3)
{
  int v3; // r4
  int v4; // r12
  int v5; // r3
  int v6; // r0
  int v7; // r0
  unsigned int v8; // r7
  int v9; // r4
  char v10; // r6

  if ( *(uint8_t *)off_112080 != 4 )
    return 1;
  v3 = a1 - 1;
  if ( (uint8_t)(a1 - 1) > 5u )
    return 2;
  if ( a2 << 30 )
  {
    sub_10DAE4(dword_112090);
    return 3;
  }
  else
  {
    v4 = dword_112084 + 16 * v3;
    if ( *(uint32_t *)v4 )
    {
      return 4;
    }
    else
    {
      v5 = 32 * a1 + 1075838976;
      if ( (*((uint32_t *)&REG_4020_0b00 + 8 * a1) & 0x8000) != 0 )
      {
        v6 = dword_112088;
        *(uint32_t *)(dword_112084 + 16 * v3) = a2;
        v7 = *(uint32_t *)(v6 + 4 * v3);
        v8 = dword_11208C;
        *(uint8_t *)(v4 + 8) = 1;
        v9 = 32 * v3 + 1075838976;
        v10 = *(uint8_t *)(v7 + 3) & 0x31;
        if ( a3 >= v8 )
          a3 = v8;
        *(uint32_t *)(v4 + 4) = a3;
        *(uint16_t *)v7 = a3;
        *(uint32_t *)(v7 + 4) = a2;
        *(uint8_t *)(v7 + 3) = v10 | 0xE;
        *(uint32_t *)(v9 + 2868) = v7;
        *(uint32_t *)(v5 + 2816) = *(uint32_t *)(v5 + 2816) & 0x7BFFFFFF | 0x80000000;
        return 0;
      }
      else
      {
        return 5;
      }
    }
  }
}

