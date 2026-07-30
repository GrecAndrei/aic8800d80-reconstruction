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

extern uint32_t dword_125254;
extern uint32_t dword_12524C;
extern uint32_t dword_125258;
extern uint32_t off_12525C;
extern uint32_t dword_125250;

// sub_1251C4 @ 0x1251c4, size 134 bytes
int  sub_1251C4(uint8_t *a1, int a2, int a3)
{
  char v4; // r2
  int v5; // r1
  int v6; // r0
  int v7; // r2
  int result; // r0
  unsigned int v9; // r3
  uint8_t *v10; // r0
  uint8_t *v11; // r6

  if ( (a2 & 0x800000) != 0 )
  {
    result = sub_12ECB0(dword_125254, dword_12524C, a3);
    v9 = (uint8_t)a1[35];
    a1[668] = 0;
    if ( v9 <= 0x23 )
    {
      *(uint32_t *)(dword_125258 + 696 * v9 + 664) = *((uint32_t *)off_12525C + 4);
      return 696;
    }
  }
  else
  {
    v4 = a1[668];
    v5 = dword_12524C;
    v6 = dword_125250;
    v7 = (uint8_t)(v4 + 1);
    a1[668] = v7;
    result = sub_12ECB0(v6, v5, v7);
    if ( (uint8_t)a1[668] > 9u )
    {
      v10 = (uint8_t *)rf_bus_setup_n3a8(125, 13, 0, 8);
      *v10 = a1[35];
      v10[1] = a1[34];
      v11 = v10;
      a1[668] = 0;
      sub_14380C(v10 + 2, a1 + 38, 6);
      return sub_12CBB4(v11);
    }
  }
  return result;
}

