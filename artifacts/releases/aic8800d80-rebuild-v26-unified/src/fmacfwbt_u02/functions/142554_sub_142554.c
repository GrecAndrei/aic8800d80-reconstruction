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

extern uint32_t dword_142664;
extern uint32_t off_142660;
extern uint32_t dword_142668;
extern uint32_t dword_14266C;

// sub_142554 @ 0x142554, size 266 bytes
int  sub_142554(int a1, uint8_t *a2, int16_t a3, int16_t a4)
{
  int v4; // r8
  int v5; // r9
  uint8_t *v6; // r5
  int v10; // r11
  int v11; // r10
  int v12; // r0
  char v13; // r5
  int16_t v14; // r3
  int v15; // r1
  int16_t v16; // r2
  int v17; // r3
  uint8_t v18; // r0
  int v19; // r4
  int *v20; // r0
  uint64_t v22; // r0
  char v23; // [sp+4h] [bp-50h]
  int v24[2]; // [sp+8h] [bp-4Ch] BYREF
  int16_t v25; // [sp+10h] [bp-44h]
  int v26; // [sp+18h] [bp-3Ch]
  uint64_t v27; // [sp+20h] [bp-34h]
  char v28; // [sp+31h] [bp-23h]
  char v29; // [sp+36h] [bp-1Eh]
  char v30; // [sp+37h] [bp-1Dh]

  v4 = dword_142664;
  v5 = *a2;
  v6 = (uint8_t *)(dword_142664 + 1320 * v5);
  if ( !v6[108] || v6[106] || *(uint8_t *)off_142660 > 7u )
  {
    v19 = 1;
  }
  else
  {
    v10 = (uint8_t)v6[116];
    v11 = dword_142668;
    v23 = v6[106];
    memset_thunk(v24, 0, 0x48u);
    v12 = a2[4];
    v13 = v6[107];
    BYTE2(v24[0]) = *(uint8_t *)off_142660;
    v30 = v13;
    v29 = *(uint8_t *)(v11 + 696 * v10 + 35);
    v28 = v23;
    v14 = v24[0];
    if ( v12 )
      v14 = LOWORD(v24[0]) | 4;
    v15 = *((uint16_t *)a2 + 3);
    v24[1] = *(uint32_t *)(a2 + 2);
    v25 = *((uint16_t *)a2 + 3);
    v16 = v14 | 0x30;
    v17 = a2[1];
    v18 = a2[3];
    LOWORD(v24[0]) = v16;
    v26 = v15 << v18;
    if ( (unsigned int)(v17 - 1) <= 1 )
    {
      LODWORD(v22) = sub_12C068();
      v17 = a2[1];
      v27 = *(uint64_t *)(v4 + 1320 * v5 + 40) + (unsigned int)dword_14266C + v22;
    }
    v19 = sub_141FDC(v4 + 1320 * v5, v11 + 696 * v10, (int)v24, v17) == 0;
  }
  v20 = (int *)rf_bus_setup_n3a8(12289, a4, a3, 1u);
  *v20 = v19;
  sub_12CBB4((int)v20);
  return 0;
}

