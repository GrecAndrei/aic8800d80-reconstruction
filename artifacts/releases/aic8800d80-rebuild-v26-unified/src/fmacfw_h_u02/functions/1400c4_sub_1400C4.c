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

extern uint32_t dword_1401E4;
extern uint32_t off_1401E0;
extern uint32_t dword_1401F0;
extern uint32_t dword_1401EC;
extern uint32_t off_1401F4;
extern uint32_t dword_1401E8;

// sub_1400C4 @ 0x1400c4, size 284 bytes
int  sub_1400C4(int result)
{
  unsigned int v1; // r6
  int v2; // r4
  int v3; // r7
  int v4; // r5
  char v5; // r3
  char v6; // r3
  uint32_t *v7; // r8
  int v8; // r1
  int16_t v9; // r2
  int v10; // nf
  unsigned int v11; // r6
  char v12; // r3
  char v13; // r3
  int v14; // r0
  char v15; // r3

  v1 = *(uint8_t *)(result + 29);
  v2 = result;
  if ( v1 > 0x1F )
  {
    *(uint8_t *)(result + 54) = 0;
  }
  else
  {
    v3 = dword_1401E4;
    v4 = *(uint32_t *)(dword_1401E4 + 696 * v1 + 340);
    if ( **(int16_t **)off_1401E0 < 0 && !v4 )
      sub_12F32C(dword_1401F0, dword_1401EC, 2758);
    v5 = *(uint8_t *)(v4 + 166);
    if ( (*(uint32_t *)(v2 + 36) & 0x200000) != 0 && (*(uint8_t *)(v4 + 166) & 4) != 0 )
      v6 = v5 | 2;
    else
      v6 = v5 & 0xFD;
    v7 = off_1401F4;
    *(uint8_t *)(v4 + 166) = v6;
    if ( v7[4] - *(uint32_t *)v4 > (unsigned int)dword_1401E8 )
    {
      v14 = sub_13F490(v4, 0);
      v15 = (*(uint8_t *)(v4 + 167) + 1) & 3;
      *(uint8_t *)(v4 + 167) = v15;
      *(uint8_t *)(v4 + 154) = 0;
      *(uint8_t *)(v4 + 168) = 0;
      *(uint32_t *)v4 = v7[4];
      *(uint8_t *)(v2 + 54) = 4 * v15;
      if ( v14 )
      {
        if ( !sub_13D33C(v4) )
          *(uint32_t *)(v2 + 36) &= ~0x200000u;
        *(uint8_t *)(v3 + 696 * v1 + 350) |= 0x11u;
      }
    }
    else
    {
      *(uint8_t *)(v2 + 54) = *(uint8_t *)(v4 + 168) | (4 * *(uint8_t *)(v4 + 167));
    }
    result = sub_13EB30(v4);
    if ( result )
    {
      v8 = *(uint32_t *)(v2 + 36);
      v9 = *(uint16_t *)(v2 + 30);
      *(uint8_t *)(v2 + 54) &= 0xFCu;
      v10 = (v8 & 0x200000) != 0;
      v11 = v3 + 696 * v1;
      v12 = *(uint8_t *)(v11 + 350);
      *(uint16_t *)(v2 + 30) = v9 | 0x2000;
      if ( (v8 & 0x200000) != 0 )
        v8 |= 0x280000u;
      v13 = v12 | 0x20;
      if ( v10 )
        *(uint32_t *)(v2 + 36) = v8;
      *(uint8_t *)(v11 + 350) = v13;
    }
  }
  return result;
}

