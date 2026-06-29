// fwstruct annotate: 135580_sub_135580.c
// sub_135580 @ 0x135580, size 462 bytes
_DWORD *sub_135580()
{
  int v0; // r8
  int v1; // r9
  int v2; // r6
  unsigned __int8 *v3; // r4
  int v4; // r11
  int v5; // r0
  int v6; // r4
  _BYTE *v7; // r7
  int v8; // r10
  int v9; // r5
  __int16 v10; // r3
  _WORD *v11; // r2
  int v12; // r1
  int v13; // r11
  int v14; // t1
  int v15; // lr
  __int16 v16; // r3
  int v17; // r6
  __int16 v18; // r12
  _WORD *v19; // r7
  int v20; // r3
  int v21; // r0
  _DWORD *v22; // r1
  int v23; // r2
  bool v24; // cc
  int v25; // r2
  int v26; // r0
  int v27; // r3
  int v28; // r0
  _BYTE *v29; // r4
  int v31; // [sp+14h] [bp-10h]
  unsigned int v32; // [sp+14h] [bp-10h]
  unsigned __int16 v33; // [sp+1Ah] [bp-Ah] BYREF
  int v34; // [sp+1Ch] [bp-8h] BYREF

  v0 = dword_13577C;
  v1 = *((_DWORD *)off_135750 + 4);
  v2 = *(unsigned __int8 *)(v1 + 61);
  v3 = (unsigned __int8 *)(dword_13577C + 1320 * v2);
  v4 = v3[116];
  sub_12EEF8(256, dword_135758, dword_135754);
  if ( !v3[1224] )
  {
    v5 = v3[412];
    if ( v3[412] )
      v5 = 1;
    v6 = sub_119084(v5, 512);
    if ( v6 )
      goto LABEL_5;
    return (_DWORD *)sub_135020(1);
  }
  v6 = sub_119084(1, 512);
  if ( !v6 )
    return (_DWORD *)sub_135020(1);
LABEL_5:
  v7 = off_135750;
  v31 = 1320 * v2;
  v8 = *((_DWORD *)off_135750 + 5);
  sub_12C710(v0 + 1320 * v2, v6);
  v9 = *(_DWORD *)(v6 + 72);
  v10 = (unsigned __int8)v7[33];
  if ( v7[33] )
  {
    v11 = (_WORD *)dword_13576C;
    v10 = 32;
  }
  else
  {
    v11 = nullptr;
  }
  v12 = dword_13575C;
  *(_WORD *)(v9 + 108) = v10;
  v13 = v12 + 696 * v4;
  v14 = *(_DWORD *)(v13 + 38);
  v13 += 38;
  v15 = *(_DWORD *)v13;
  v16 = *((_WORD *)off_135760 + 254);
  *(_DWORD *)(v9 + 112) = v14;
  v17 = v0 + 1320 * v2;
  *(_WORD *)(v9 + 116) = *(_WORD *)(v13 + 4);
  v18 = *(_WORD *)(v13 + 4);
  *(_DWORD *)(v9 + 118) = *(_DWORD *)(v17 + 100);
  *(_WORD *)(v9 + 122) = *(_WORD *)(v17 + 104);
  ++v16;
  v19 = off_135760;
  *(_DWORD *)(v9 + 124) = v15;
  *(_WORD *)(v9 + 128) = v18;
  *(_BYTE *)(v9 + 110) = 0;
  *(_BYTE *)(v9 + 111) = 0;
  LOWORD(v15) = 16 * v16;
  v19[254] = v16;
  v20 = *(unsigned __int8 *)(v17 + 107);
  *(_WORD *)(v9 + 130) = v15;
  v21 = sub_130A5C(v9 + 132, v31 + 248 + v0, v11, v20, &v34, &v33, v1);
  *(_BYTE *)(v6 + 28) = *(_BYTE *)(v17 + 107);
  v22 = *(_DWORD **)(v6 + 76);
  *(_BYTE *)(v6 + 29) = *(_BYTE *)(v17 + 116);
  v23 = v33;
  v24 = v33 > 0x320u;
  v22[8] = v22[7] + 23 + v21;
  v22[9] = v21 + 28;
  if ( v24 )
  {
    if ( **(__int16 **)off_135770 < 0 )
      sub_12F6C4(dword_135778, dword_135774, 1115);
    *(_WORD *)(v8 + 14) = 0;
  }
  else
  {
    if ( v23 )
    {
      v25 = v23 + v8 + 19;
      v26 = v34 - 19 - v8;
      v27 = v8 + 19;
      do
      {
        *(_BYTE *)(v27 + 1) = *(_BYTE *)(v26 + v27);
        ++v27;
      }
      while ( v27 != v25 );
      LOWORD(v23) = v33;
    }
    *(_WORD *)(v8 + 14) = v23;
  }
  v28 = v6;
  v32 = *(_DWORD *)(*(_DWORD *)off_135764 + 8);
  *(_DWORD *)(v6 + 88) = dword_135768;
  *(_DWORD *)(v6 + 92) = v6;
  v29 = off_135750;
  sub_1190B4(v28, 5);
  v29[34] = 1;
  sub_12C80C(6154, 6, v32);
  return sub_12CF5C(6u, 8);
}

