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

extern uint32_t off_11A6A0;
extern uint32_t dword_11A6A4;

// sub_11A580 @ 0x11a580, size 288 bytes
int  sub_11A580(int a1, int *a2, unsigned int a3, unsigned int a4, uint8_t a5)
{
  int v5; // r7
  int v6; // r6
  int result; // r0
  uint32_t *v12; // r3
  unsigned int v13; // r2
  unsigned int v14; // r1
  int16_t v15; // r12
  int16_t v16; // r2
  unsigned int v17; // r4
  int v18; // r4
  int v19; // r1
  int v20; // lr
  int v21; // r12
  uint32_t *v22; // [sp+Ch] [bp-8h]
  unsigned int v23; // [sp+Ch] [bp-8h]

  v5 = *a2;
  v6 = *(uint32_t *)(*a2 + 68);
  v22 = *(uint32_t **)(a1 + 76);
  result = sub_1195A0(a1, *a2, a5);
  if ( result )
  {
    v12 = v22;
    v13 = (uint16_t)(((v22[9] + 3) & 0xFFFC) + 4);
    if ( a4 > v13 )
    {
      v14 = ((unsigned int)(uint16_t)(a4 - v13) + 3) >> 2;
      v13 = (uint16_t)(v13 + 4 * v14);
    }
    else
    {
      v14 = 0;
    }
    v23 = v13 + *(uint32_t *)(v6 + 40);
    if ( v23 > a3 && (*(uint32_t *)off_11A6A0 & 0x3Fu) <= 0x11 )
    {
      return 0;
    }
    else
    {
      v15 = *(uint16_t *)(a1 + 80);
      v16 = *(uint16_t *)(v6 + 10);
      v17 = *(uint32_t *)(a1 + 36) & 0xFFE7FFFF;
      --*(uint8_t *)(dword_11A6A4 + 84 * a5 + 80);
      v12[5] = *(uint32_t *)(v6 + 24);
      v18 = v17 | (v14 << 9);
      *(uint16_t *)(v6 + 10) = v16 + v15;
      *(uint32_t *)(v6 + 24) = v12 + 3;
      *(uint32_t *)(v6 + 40) = v23;
      *(uint32_t *)(v6 + 268) = a1;
      *(uint32_t *)(a1 + 36) = v18 | 0x680000;
      v19 = *(uint32_t *)(v5 + 36);
      v20 = *(uint32_t *)(v5 + 76);
      v21 = *(uint32_t *)(*(uint32_t *)(v6 + 324) + 76);
      *(uint32_t *)(a1 + 68) = v6;
      v19 &= 0xFFE7FFFF;
      v12[17] = v18 | 0x680100;
      v12[12] = 0;
      *(uint32_t *)(v5 + 36) = v19 | 0x300000;
      *(uint32_t *)(v20 + 68) = v19 | 0x300100;
      ++*(uint8_t *)(v21 + 1);
      if ( v23 > a3 )
      {
        sub_11A31C(a1, a2, a3, a4, a5);
        return 0;
      }
      else
      {
        sub_119308((int16_t *)v5);
        *a2 = **(uint32_t **)(v6 + 324);
        return 1;
      }
    }
  }
  return result;
}

