// v23 annotated: sub_119204 @ 0x119204
// Original: 119204_sub_119204.c
// Primary struct: <unclustered>
//
// sub_119204 @ 0x119204, size 362 bytes
int __fastcall sub_119204(int a1, int a2, int a3)
{
  int v3; // r9
  int v4; // r5
  int v6; // r10
  int v8; // r3
  int v10; // r2
  int v11; // r4
  int v12; // r5
  int v13; // r3
  int v14; // r2
  int v15; // r0
  int v16; // t1
  __int16 v17; // r12
  __int16 v18; // lr
  int v19; // r5
  __int16 v20; // r5
  char v21; // r2
  int v23; // r1
  int v24; // r0
  int v25; // lr
  int v26; // r0
  __int16 v27; // r2

  v3 = dword_119384;
  v4 = dword_119370;
  v6 = *(unsigned __int8 *)(dword_119384 + 696 * a1 + 34);
  v8 = *(_DWORD *)(dword_119370 + 1320 * v6 + 72);
  if ( !v8 )
  {
    if ( **(__int16 **)off_119374 >= 0 )
    {
LABEL_9:
      v11 = sub_119084(1, 24);
      if ( !v11 )
        return 1;
      goto LABEL_4;
    }
LABEL_8:
    sub_12F694(dword_119380, dword_11937C, 520);
    goto LABEL_9;
  }
  v10 = *(unsigned __int8 *)(v8 + 4);
  if ( **(__int16 **)off_119374 < 0 && v10 == 2 )
    goto LABEL_8;
  v11 = sub_119084((*(unsigned __int8 *)(dword_119370 + 1320 * v6 + 1224) | v10) != 0, 24);
  if ( !v11 )
    return 1;
LABEL_4:
  v12 = v4 + 1320 * v6;
  sub_12C710(v12, v11);
  v13 = *(_DWORD *)(v11 + 72);
  if ( *(_BYTE *)(v12 + 106) == 2 )
  {
    v23 = v3 + 696 * a1;
    v24 = *(_DWORD *)(v12 + 100);
    v25 = *(_DWORD *)(v23 + 38);
    *(_BYTE *)(v13 + 109) = 2;
    *(_WORD *)(v13 + 116) = *(_WORD *)(v23 + 42);
    LOWORD(v23) = *(_WORD *)(v12 + 104);
    *(_DWORD *)(v13 + 118) = v24;
    v26 = *(_DWORD *)(v12 + 100);
    *(_BYTE *)(v13 + 110) = 0;
    *(_BYTE *)(v13 + 111) = 0;
    v27 = *(_WORD *)(v12 + 104);
    *(_DWORD *)(v13 + 112) = v25;
    *(_BYTE *)(v13 + 108) = 72;
    *(_WORD *)(v13 + 122) = v23;
    *(_DWORD *)(v13 + 124) = v26;
    *(_WORD *)(v13 + 128) = v27;
  }
  else
  {
    v14 = v3 + 696 * a1;
    v15 = *(_DWORD *)(v12 + 100);
    v16 = *(_DWORD *)(v14 + 38);
    v14 += 38;
    v17 = *(_WORD *)(v12 + 104);
    v18 = *(_WORD *)(v14 + 4);
    v19 = *(_DWORD *)v14;
    *(_DWORD *)(v13 + 112) = v16;
    *(_WORD *)(v13 + 128) = *(_WORD *)(v14 + 4);
    *(_DWORD *)(v13 + 124) = v19;
    *(_WORD *)(v13 + 116) = v18;
    *(_DWORD *)(v13 + 118) = v15;
    *(_WORD *)(v13 + 122) = v17;
    *(_BYTE *)(v13 + 110) = 0;
    *(_BYTE *)(v13 + 111) = 0;
    *(_BYTE *)(v13 + 108) = 72;
    *(_BYTE *)(v13 + 109) = 1;
  }
  v20 = *((_WORD *)off_119378 + 254) + 1;
  *((_WORD *)off_119378 + 254) = v20;
  v21 = *(_BYTE *)(v3 + 696 * a1 + 34);
  *(_WORD *)(v13 + 130) = 16 * v20;
  *(_DWORD *)(v11 + 88) = a2;
  *(_DWORD *)(v11 + 92) = a3;
  *(_BYTE *)(v11 + 28) = v21;
  *(_BYTE *)(v11 + 29) = a1;
  sub_1190B4(v11, 5);
  return 0;
}

