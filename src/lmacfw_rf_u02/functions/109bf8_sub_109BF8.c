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


extern uint32_t dword_109D2C;
extern uint32_t dword_109D30;
extern uint32_t dword_109D34;
extern uint32_t dword_109D3C;
extern uint32_t off_109D24;
extern uint32_t off_109D38;

// sub_109BF8 @ 0x109bf8, size 300 bytes
int  sub_109BF8(
        int a1,
        int *a2,
        int a3,
        int a4,
        int a5,
        uint8_t a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11)
{
  uint32_t *v11; // r4
  uint8_t v15; // r10
  int *v16; // r5
  int *v17; // r2
  int *v18; // r3
  int v19; // r0
  int *v20; // r4
  int v21; // t1
  int v22; // r6
  int v23; // t1
  int v24; // r1
  int v25; // t1
  int result; // r0
  uint32_t *v27; // r3
  int v28; // r1
  uint32_t *v29; // r2
  uint32_t *v30; // r0
  uint32_t *v31; // r1
  int v32; // r5
  int *v33; // r3
  int v34; // t1
  uint8_t v35[20]; // [sp+18h] [bp-14h] BYREF

  v11 = off_109D24;
  *(uint32_t *)off_109D24 |= 0x400u;
  *v11 &= ~0x400u;
  v15 = a4;
  sub_11F74C(1, "cal %x index\n", a1);
  if ( a5 )
  {
    sub_1043D8((int)a2, 1, 0x100000, 0x100000, 0, 1);
    return sub_1099BC(24, (float *)a2, 1, (int)v35);
  }
  else
  {
    if ( a8 == 1 )
    {
      sub_1043D8((int)a2, 1, 0x100000, 0x100000, 0, 0);
      sub_1099BC(24, (float *)a2, 0, (int)v35);
      v29 = (uint32_t *)dword_109D2C;
      v30 = (uint32_t *)dword_109D30;
      v31 = (uint32_t *)dword_109D34;
      v32 = dword_109D2C + 128;
      v33 = a2;
      do
      {
        v34 = *v33++;
        *v29++ = v34;
        *v30++ = v33[31];
        *v31++ = v33[95];
      }
      while ( v29 != (uint32_t *)v32 );
    }
    else
    {
      v16 = (int *)dword_109D2C;
      v17 = (int *)dword_109D30;
      v18 = (int *)dword_109D34;
      v19 = dword_109D2C + 128;
      v20 = a2;
      do
      {
        v21 = *v16++;
        *v20++ = v21;
        v23 = *v17++;
        v22 = v23;
        v20[31] = v23;
        v25 = *v18++;
        v24 = v25;
        v20[95] = v25;
        v20[63] = v22;
      }
      while ( v16 != (int *)v19 );
      sub_1047B8(a2, v24, a9, a10, (uint64_t *)a11);
    }
    sub_104D60(16, 32, (int)a2, a3, v15, 1, a6, a1, a7);
    result = (int)sub_10397C(a3);
    v27 = off_109D38;
    v28 = dword_109D3C;
    *(uint32_t *)off_109D38 &= ~0x200u;
    *v27 |= 0x200u;
    *v27 &= ~0x200u;
    a2[129] = v28;
    a2[131] = v28;
  }
  return result;
}
