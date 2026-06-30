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

extern uint32_t off_141D38;
extern uint32_t dword_141D48;
extern uint32_t dword_141D44;
extern uint32_t dword_141D40;
extern uint32_t off_141D3C;

// sub_141C80 @ 0x141c80, size 184 bytes
int  sub_141C80(uint16_t *a1, unsigned int a2, unsigned int a3, int16_t *a4)
{
  unsigned int v4; // r5
  int16_t v5; // r6
  int16_t **v6; // r4
  int v7; // r7
  int16_t v8; // r2
  int v9; // r5
  int16_t *v11; // r3
  int v12; // r5
  int result; // r0
  int v14; // r4
  int v15; // nf
  int v16; // r1
  int v17; // r4
  int v18; // r2
  int v19; // r5

  v4 = *a1;
  v5 = *a4;
  v6 = (int16_t **)off_141D38;
  *((uint8_t *)a4 + 4) = (v4 & 0x40) != 0;
  *((uint8_t *)a4 + 2) = (v4 >> 7) & 7;
  v7 = (v4 >> 10) & 0x1F;
  *((uint8_t *)a4 + 5) = v7;
  v8 = (a3 >> 3) & 6 | v5 | v4 & 0x10 | v4 & 0x20;
  v9 = *(uint32_t *)(a1 + 1);
  v11 = *v6;
  *((uint32_t *)a4 + 7) = *(uint32_t *)(a1 + 3);
  *a4 = v8;
  *((uint32_t *)a4 + 6) = v9;
  v12 = *((uint8_t *)a1 + 10);
  *((uint8_t *)a4 + 7) = v12;
  LOWORD(v14) = *(uint16_t *)((char *)a1 + 11);
  a4[4] = v14;
  *((uint8_t *)a4 + 41) = *((uint8_t *)a1 + 13);
  result = *v11;
  v14 = (uint16_t)v14;
  if ( result < 0 && a2 <= 0xD )
  {
    result = sub_12F46C(dword_141D48, dword_141D44, 213);
    v14 = (uint16_t)a4[4];
    LOBYTE(v7) = *((uint8_t *)a4 + 5);
    v8 = *a4;
    v12 = *((uint8_t *)a4 + 7);
  }
  v15 = (v8 & 4) != 0;
  v16 = dword_141D40;
  v17 = v14 << v7;
  v18 = *((uint16_t *)off_141D3C + 14) + 20;
  *((uint32_t *)a4 + 4) = v17;
  if ( v15 )
    v19 = v12 << 10;
  else
    v19 = v12 << 8;
  *((uint32_t *)a4 + 3) = v19;
  *((uint32_t *)a4 + 12) = (unsigned int)(((unsigned int)v16 * (unsigned uint64_t)(unsigned int)(v17 * v18)) >> 32) >> 18;
  return result;
}

