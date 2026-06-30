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

extern uint32_t off_1196D8;
extern uint32_t dword_1196C4;
extern uint32_t dword_1196C0;
extern uint32_t dword_1196D4;
extern uint32_t dword_1196C8;
extern uint32_t dword_1196D0;
extern uint32_t dword_1196AC;
extern uint32_t dword_1196CC;
extern uint32_t dword_1196B0;
extern uint32_t dword_1196B4;
extern uint32_t dword_1196DC;
extern uint32_t off_1196B8;
extern uint32_t off_1196BC;

// sub_1194A8 @ 0x1194a8, size 514 bytes
unsigned int  sub_1194A8(int a1, int a2, int a3)
{
  int16_t **v3; // r10
  unsigned int v5; // r3
  int v8; // r4
  unsigned int v9; // r9
  int v10; // zf
  int v11; // r10
  unsigned int v12; // r8
  int v13; // s16
  int ( *v14)(int, uint32_t); // r3
  char v15; // r1
  int v16; // r4
  int v17; // r9
  int v18; // r6
  unsigned int *v19; // r11
  int i; // r0
  unsigned int v21; // r0
  unsigned int v22; // r3
  int v23; // r9
  unsigned int v24; // r8
  int v25; // r11
  unsigned int v26; // r1
  int v27; // r0
  uint8_t *v28; // r2
  unsigned int result; // r0
  char v30; // r3
  int v31; // r1
  unsigned int v32; // r2
  int v33; // r0
  int v34; // [sp+8h] [bp-1Ch]
  int v35; // [sp+8h] [bp-1Ch]
  int v36; // [sp+Ch] [bp-18h]
  unsigned int v37; // [sp+10h] [bp-14h] BYREF
  int v38; // [sp+14h] [bp-10h] BYREF
  int ( *v39)(int, uint32_t); // [sp+18h] [bp-Ch] BYREF
  int ( *v40[2])(int, int); // [sp+1Ch] [bp-8h] BYREF

  v3 = (int16_t **)off_1196D8;
  v5 = *(uint32_t *)(a1 + 4);
  v36 = *(uint8_t *)(a1 + 12);
  v8 = (v5 >> 7) & 3;
  v9 = (v5 >> 11) & 7;
  if ( **(int16_t **)off_1196D8 < 0 && ((v5 >> 11) & 6) == 0 )
    sub_12F46C(dword_1196C4, dword_1196C0, 397);
  v10 = v9 == 4;
  if ( v9 <= 4 )
  {
    v22 = *(uint32_t *)(a1 + 4);
    v23 = *(uint8_t *)(a1 + 12);
    v24 = v22 & 0x7F;
    v25 = (v22 >> 9) & 1;
    if ( v10 )
    {
      v31 = **v3;
      v32 = v24 >> 4;
      v33 = (v24 >> 4) + 1;
      v12 = v22 & 0xF;
      v38 = v33;
      if ( v31 < 0 )
      {
        if ( v32 <= 3 || (sub_12F46C(dword_1196D4, dword_1196C8, 340), **v3 < 0) )
        {
          if ( v12 > 9 )
            sub_12F46C(dword_1196D0, dword_1196C8, 341);
        }
      }
      v34 = dword_1196AC;
      v37 = *(uint32_t *)(dword_1196AC + 696 * v23 + 16);
    }
    else
    {
      if ( **v3 < 0 && (v22 & 0x60) != 0 )
      {
        v35 = *(uint32_t *)(a1 + 4);
        sub_12F46C(dword_1196CC, dword_1196C8, 349);
        LOBYTE(v22) = v35;
      }
      v34 = dword_1196AC;
      v26 = *(uint16_t *)(dword_1196AC + 696 * v23 + 20);
      v38 = ((v24 >> 3) & 3) + 1;
      v12 = v22 & 7;
      v37 = v26;
    }
    v14 = (int ( *)(int, uint32_t))dword_1196B0;
    v39 = (int ( *)(int, uint32_t))dword_1196B0;
    v11 = v25 | (8 * v12);
    v40[0] = (int ( *)(int, int))dword_1196B4;
    LOBYTE(v12) = 0;
    goto LABEL_14;
  }
  v11 = sub_11C394(a1, v9, &v39, v40, &v37, &v38);
  v12 = (*(uint8_t *)(a1 + 344) >> 5) & 1;
  if ( v9 != 7 )
  {
    v14 = v39;
    v34 = dword_1196AC;
LABEL_14:
    v15 = v8;
    v13 = (uint8_t)v8;
    goto LABEL_5;
  }
  v13 = (uint8_t)v8;
  v14 = v39;
  v34 = dword_1196AC;
  v15 = 0;
LABEL_5:
  v16 = 0;
  v17 = dword_1196DC;
  *(uint8_t *)(a3 + 34) = v15;
  v18 = a2 + 4;
  *(uint8_t *)(a3 + 35) = 0;
  v19 = (unsigned int *)(a3 + 12);
  for ( i = v14(v11, 0); ; i = v39(v11, (uint8_t)v16) )
  {
    v21 = (i * v38 * (unsigned int)*(uint16_t *)(v17 + 2 * v18)) >> v12;
    if ( v21 >= v37 )
      v21 = v37;
    *v19++ = v21;
    if ( *(uint8_t *)(a3 + 34) < ++v16 )
      break;
  }
  v27 = v40[0](v11, v13);
  v28 = off_1196B8;
  result = v27 * v38 * *(uint8_t *)(v34 + 696 * v36 + 28);
  *(uint16_t *)(a3 + 28) = result >> v12;
  v30 = v28[381];
  if ( !v30 || *(uint8_t *)off_1196BC )
    v30 = *(uint8_t *)(v34 + 696 * *(uint8_t *)(a1 + 12) + 6 * *(uint8_t *)(a1 + 13) + 354);
  *(uint8_t *)(a3 + 32) = v30;
  return result;
}

