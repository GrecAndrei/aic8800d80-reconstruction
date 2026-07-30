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

extern uint32_t dword_13A640;
extern uint32_t dword_13A644;
extern uint32_t off_13A648;
extern uint32_t dword_13A64C;
extern uint32_t dword_13A650;

// sub_13A528 @ 0x13a528, size 280 bytes
// Doc: sub_123A528 [util]: Index into a table entry using byte fields 0x1c/0x1d with stride 0x2b8
// sub_123A528 [util]: Index into a table entry using byte fields 0x1c/0x1d with stride 0x2b8
int  sub_13A528(int a1, uint32_t *a2)
{
  int v3; // r7
  int v4; // r0
  int v5; // r3
  uint64_t v6; // kr00_8
  int v7; // r2
  int v8; // r6
  int v9; // lr
  int v10; // r5
  int v11; // r2
  int v12; // r0

  v3 = dword_13A640;
  v4 = *(uint8_t *)(a1 + 29);
  v5 = dword_13A640 + 696 * v4;
  v6 = *(uint64_t *)(v5 + 184);
  v7 = dword_13A644 + 1320 * *(uint8_t *)(a1 + 28);
  v8 = *(uint32_t *)HIDWORD(v6);
  v9 = *(uint32_t *)(v7 + 1200);
  v10 = 0;
  *a2 = 0;
  if ( !v8 || !v9 )
    return 0;
  if ( (*(uint32_t *)(v7 + 1208) & 2) != 0
    && *(uint16_t *)(v5 + 56) == (uint16_t)__rev16(*(uint16_t *)(a1 + 24)) )
  {
    return v10;
  }
  if ( !(uint32_t)v6
    || (unsigned int)*(uint8_t *)(v6 + 96) - 1 > 1
    || *(uint8_t *)(v3 + 696 * v4 + 669) > 1u )
  {
    switch ( *(uint8_t *)(v8 + 96) )
    {
      case 0:
      case 3:
        v10 = 4;
        *a2 = 4;
        v11 = 2;
        v12 = 1;
        break;
      case 1:
        *a2 = 12;
        v10 = 8;
        v11 = 3;
        v12 = 1;
        break;
      case 2:
        v10 = 8;
        *a2 = 8;
        v11 = 3;
        v12 = 1;
        break;
      case 4:
        *a2 = 16;
        if ( *(uint8_t *)(v8 + 98) >= 0x10u )
          v12 = 2;
        else
          v12 = 1;
        v10 = 18;
        v11 = 4;
        break;
      case 6:
      case 7:
      case 8:
        *a2 = 16;
        v10 = 8;
        v11 = 3;
        v12 = 1;
        break;
      default:
        if ( **(int16_t **)off_13A648 < 0 )
          sub_12F46C(dword_13A64C, dword_13A650, 181);
        v10 = 0;
        v11 = 3;
        v12 = 1;
        break;
    }
    if ( (*(uint16_t *)(a1 + 30) & 1) == 0 )
    {
      *(uint64_t *)(v8 + 72) += v12;
      sub_143770(a1 + 56, v8 + 72, 2 * v11);
    }
    return v10;
  }
  return 0;
}

