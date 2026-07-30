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

extern uint32_t dword_113C48;
extern uint32_t dword_113C68;
extern uint32_t off_113C54;
extern uint32_t dword_113C6C;
extern uint32_t off_113C4C;
extern uint32_t dword_113C64;
extern uint32_t dword_113C60;
extern uint32_t dword_113C5C;
extern uint32_t dword_113C50;
extern uint32_t dword_113C58;

// sub_113B08 @ 0x113b08, size 318 bytes
int  sub_113B08(int a1)
{
  unsigned int v1; // r3
  int v2; // r7
  int v4; // r8
  unsigned int v5; // r6
  int v6; // r4
  int v7; // r1
  int16_t v8; // r3
  int16_t v9; // r2
  int v10; // r3
  unsigned int v11; // r3
  unsigned int v12; // r2

  v1 = *(uint8_t *)(a1 + 25);
  v2 = *(uint8_t *)(a1 + 24);
  if ( v1 <= 0x1F && !*(uint8_t *)(dword_113C48 + 696 * v1 + 37) )
  {
    sub_12E948(dword_113C68, 696, dword_113C48);
    return sub_10FEC8((uint32_t *)(a1 - *(uint32_t *)off_113C54 - 4));
  }
  v4 = dword_113C6C;
  if ( (*(uint16_t *)(a1 + 26) & 8) == 0 )
  {
    if ( *(uint8_t *)(dword_113C6C + 1320 * v2 + 108) )
    {
      v5 = *(uint8_t *)(a1 + 22);
      if ( **(int16_t **)off_113C4C < 0 && v5 > 4 )
        sub_12F32C(dword_113C64, dword_113C60, 926);
      v6 = sub_115EC8();
      if ( v6 )
        goto LABEL_7;
LABEL_13:
      sub_10DAE4(dword_113C5C, *(uint8_t *)(dword_113C50 + v5));
      while ( 1 )
        ;
    }
    return sub_10FEC8((uint32_t *)(a1 - *(uint32_t *)off_113C54 - 4));
  }
  v5 = 3;
  v6 = sub_115EC8();
  if ( !v6 )
    goto LABEL_13;
LABEL_7:
  v7 = *(uint32_t *)(v6 + 76);
  v8 = *(uint16_t *)(v6 + 30) & 0xFFFE;
  ++*(uint8_t *)(dword_113C50 + v5);
  *(uint16_t *)(v6 + 30) = v8;
  *(uint32_t *)(v6 + 68) = 0;
  *(uint32_t *)(v7 + 4) = 0;
  *(uint32_t *)(v7 + 72) = 0;
  *(uint32_t *)(v6 + 44) = 0;
  sub_143630(v6 + 4, a1, 28);
  v9 = *(uint16_t *)(v6 + 30);
  v10 = *(uint32_t *)off_113C54;
  *(uint16_t *)(v6 + 6) = 0;
  *(uint32_t *)(v6 + 72) = a1 - v10 - 4;
  *(uint8_t *)(v6 + 66) = 0;
  *(uint32_t *)(v6 + 36) = 0;
  *(uint32_t *)(v6 + 84) = 0;
  *(uint16_t *)(v6 + 82) = 0;
  *(uint16_t *)(v6 + 30) = v9 & 0xFFFD;
  if ( (v9 & 8) != 0 )
    return sub_12D108(v4 + 1320 * v2 + 1312);
  v11 = *(uint8_t *)(v6 + 29);
  if ( v11 <= 0x1F )
  {
    v12 = *(uint8_t *)(v6 + 27);
    if ( v12 <= 8 )
      *(uint32_t *)(dword_113C58 + 4 * (9 * v11 + v12 + 2062)) += *(uint16_t *)(v6 + 4);
  }
  return sub_12D108(v4 + 8 * (v5 + 165 * v2 + 154));
}

