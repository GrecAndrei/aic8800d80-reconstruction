// v23 annotated: sub_118F74 @ 0x118f74
// Original: 118f74_sub_118F74.c
// Primary struct: <unclustered>
//
// sub_118F74 @ 0x118f74, size 394 bytes
BOOL __fastcall sub_118F74(int a1, int a2, int a3, int a4, unsigned __int8 a5, unsigned __int8 a6, int a7, int a8)
{
  int v8; // r10
  int v9; // r8
  int v11; // r9
  int v12; // r0
  int v15; // r3
  int v16; // r1
  BOOL v17; // r0
  int v18; // r0
  int v19; // r8
  int v20; // r9
  unsigned __int8 *v21; // r2
  int v22; // r1
  __int16 v23; // lr
  int v24; // r0
  unsigned int v25; // r7
  _WORD *v26; // r8
  int v27; // lr
  int v28; // r2
  _DWORD *v31; // [sp+4h] [bp-8h]
  int v32; // [sp+4h] [bp-8h]

  v8 = dword_119118;
  v9 = dword_11911C;
  v11 = *(unsigned __int8 *)(dword_119118 + 696 * a1 + 34);
  v12 = *(_DWORD *)(dword_11911C + 1320 * v11 + 72);
  if ( a2 )
    v15 = 29;
  else
    v15 = 30;
  if ( v12 )
  {
    v16 = *(unsigned __int8 *)(v12 + 4);
    if ( **(__int16 **)off_119100 >= 0 || v16 != 2 )
    {
      v17 = (*(unsigned __int8 *)(dword_11911C + 1320 * v11 + 1224) | v16) != 0;
      goto LABEL_7;
    }
    goto LABEL_16;
  }
  if ( **(__int16 **)off_119100 < 0 )
  {
LABEL_16:
    v32 = v15;
    sub_12F32C(dword_119110, dword_119114, 520);
    v15 = v32;
    v17 = 1;
    goto LABEL_7;
  }
  v17 = 1;
LABEL_7:
  v18 = sub_118B04(v17, v15);
  if ( !v18 )
    return 1;
  v19 = v9 + 1320 * v11;
  v20 = *(_DWORD *)(v18 + 72);
  v31 = (_DWORD *)v18;
  sub_12C3A8(v19, v18);
  v21 = (unsigned __int8 *)off_119104;
  v22 = v31[18];
  v23 = *(_WORD *)(v19 + 104);
  *(_DWORD *)(v20 + 60) = HIWORD(*(_DWORD *)(v20 + 60)) << 16;
  v24 = *(_DWORD *)(v19 + 100);
  *(_DWORD *)(v22 + 124) = a2 | (16 * a3);
  *(_BYTE *)(v22 + 128) = 0;
  *(_BYTE *)(v22 + 129) = 0;
  *(_BYTE *)(v22 + 130) = 0;
  *(_BYTE *)(v22 + 131) = 0;
  v25 = v21[67];
  v26 = off_119120;
  *(_DWORD *)(v22 + 118) = v24;
  LOWORD(v21) = v26[2];
  *(_WORD *)(v22 + 122) = v23;
  *(_BYTE *)(v22 + 108) = 36;
  v27 = *(_DWORD *)v26;
  *(_WORD *)(v22 + 116) = (_WORD)v21;
  *(_DWORD *)(v22 + 112) = v27;
  *(_BYTE *)(v22 + 109) = 0;
  *(_BYTE *)(v22 + 110) = 0;
  *(_BYTE *)(v22 + 111) = 0;
  v28 = (v25 >> 5) & 1;
  if ( (v25 & 0x20) != 0 )
  {
    if ( (*(_BYTE *)(dword_119108 + 696 * a1 + 1) & 0x20) != 0 )
      v28 = 0x100000;
    else
      v28 = 0;
  }
  *(_DWORD *)(v22 + 132) = (a5 << 21) | (a4 << 13) | *(unsigned __int16 *)(v8 + 696 * a1 + 32) | v28;
  *(_BYTE *)(v22 + 136) = -40;
  if ( !a2 )
    *(_BYTE *)(v22 + 137) = *(_BYTE *)(dword_11910C + a6) << 6;
  v31[22] = a7;
  v31[23] = a8;
  return sub_118B34((int)v31, a6) == 0;
}

